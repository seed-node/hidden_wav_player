# hidden_wav_player
## Overview:

hidden_wav_player is a minimalistic command-line utility designed for playing WAV audio files without displaying any visible user interface. It provides a discreet way to play audio files without distracting the user with a console window or graphical interface.

## Features:

- Plays WAV audio files silently.
- No visible user interface during playback.
- Easy to integrate into scripts or workflows requiring hidden audio playback.
- Optionally includes a wait time before audio playback.

## Setup:

Before using hidden_wav_player, make sure to place the `playwav.exe` file in the same directory as `hidden_wav_player.exe`. This is necessary for the utility to function correctly.

## Usage:

`hidden_wav_player.exe <wav_file> [wait_time_in_seconds]`

- `<wav_file>`: Path to the WAV audio file.
- `[wait_time_in_seconds]` (Optional): Wait time in seconds before playing the audio file.

## Requirements:

- Windows operating system.
- No additional dependencies.

## Usage Example:

`hidden_wav_player.exe sound.wav`
`hidden_wav_player.exe sound.wav 5`

The first example plays the audio file without any wait time, while the second example waits for 5 seconds before playing the audio.

## Compile:
To compile the source code, use the following commands:

`x86_64-w64-mingw32-gcc -o hidden_wav_player.exe hidden_wav_player.c -mwindows -lwinmm`  
`x86_64-w64-mingw32-gcc -o playwav.exe playwav.c -mwindows -lwinmm`

## License:
This software is released under the MIT License.
