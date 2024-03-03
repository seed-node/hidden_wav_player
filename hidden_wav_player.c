#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void displayError(const char *message) {
    char errorMessage[256];
    sprintf(errorMessage, "%s. Error code: %d", message, GetLastError());
    MessageBox(NULL, errorMessage, "Error", MB_OK | MB_ICONERROR);
}

int main(int argc, char *argv[]) {
    char processDirectory[MAX_PATH];
    if (!GetModuleFileName(NULL, processDirectory, MAX_PATH)) {
        displayError("Failed to get module file name");
        return 1;
    }

    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    if (_splitpath_s(processDirectory, drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0) != 0) {
        displayError("Failed to split path");
        return 1;
    }

    strcat(drive, dir);
    if (!SetCurrentDirectory(drive)) {
        displayError("Failed to set current directory");
        return 1;
    }

    char *executablePath = "playwav.exe";
    char commandLine[MAX_PATH];
    sprintf(commandLine, "\"%s\" %s %s", executablePath, argv[1], argv[2]);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(executablePath, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        displayError("Failed to create process");
        return 1;
    }

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return 0;
}
