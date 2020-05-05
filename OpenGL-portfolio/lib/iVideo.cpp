#include "iVideo.h"

// https://docs.microsoft.com/en-us/windows/win32/medfound/mfplay-tutorial--video-playback

#define WINVER _WIN32_WINNT_WIN7

#include <new>
#include <windows.h>
#include <windowsx.h>
#include <mfplay.h>
#include <mferror.h>
#include <shobjidl.h>   // defines IFileOpenDialog
#include <strsafe.h>
#include <Shlwapi.h>

#pragma comment(lib, "mfplay.lib")
#pragma comment(lib, "shlwapi.lib")

// Global variables
IMFPMediaPlayer* g_pPlayer = NULL;

HRESULT PlayVideo(HWND hwnd, const WCHAR* sURL)
{
    // Create the player object and play a video file.

    return MFPCreateMediaPlayer(
        sURL,
        TRUE,   // Start playback automatically?
        0,      // Flags.
        NULL,   // Callback pointer.
        hwnd,
        &g_pPlayer
    );
}

#include "iStd.h"

extern HWND hWnd;

void playVideo(const char* path)
{
    wchar_t* wPath = utf8_to_utf16(path);
    PlayVideo(hWnd, wPath);
    free(wPath);
}
