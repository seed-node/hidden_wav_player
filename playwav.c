#include <stdbool.h>
#include <string.h>
#include <windows.h>


bool isAnotherInstanceRunning(const char *filename) {
    const char *lastBackslash = strrchr(filename, '\\');
    const char *fileName =
        (lastBackslash != NULL) ? lastBackslash + 1 : filename;

    char mutexName[MAX_PATH + sizeof("Mutex")];
    strcpy(mutexName, fileName);
    strcat(mutexName, "Mutex");

    HANDLE hMutex = CreateMutex(NULL, FALSE, mutexName);
    if (hMutex == NULL) {
        return true;
    }
    DWORD dwLastError = GetLastError();
    if (dwLastError == ERROR_ALREADY_EXISTS) {
        CloseHandle(hMutex);
        return true;
    }

    return false;
}

void playWav(const char *filename) {
    PlaySound(filename, NULL, SND_FILENAME | SND_SYNC);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    if (__argc < 2 || __argc > 3) {
        MessageBox(NULL, "Usage: <wav_file> [wait_time_in_seconds]", "Error",
                   MB_OK | MB_ICONERROR);
        return -1;
    }

    const char *wav_file = __argv[1];

    if (isAnotherInstanceRunning(wav_file)) {
        return 1;
    }

    if (__argc == 3) {
        int wait_time = atoi(__argv[2]);
        Sleep(wait_time * 1000);
    }

    playWav(wav_file);

    return 0;
}
