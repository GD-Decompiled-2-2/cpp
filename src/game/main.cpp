#ifdef WIN32
#include <windows.h>
#include "3rdparty/cocos/wrapper.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // 1. Register window class
    WNDCLASSW wc = {};
    wc.lpfnWndProc = DefWindowProc; // placeholder, real GD hooks input elsewhere
    wc.hInstance   = (HINSTANCE)hInstance;
    wc.lpszClassName = L"GDWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClassW(&wc);

    // 2. Create the window
    HWND hwnd = CreateWindowExW(
        0,
        wc.lpszClassName,
        L"Geometry Dash",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        nullptr,
        nullptr,
        (HINSTANCE)hInstance,
        nullptr
    );

    if (!hwnd)
        return -1;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 3. Initialize game engine / Cocos stuff
    CocosWrapper::AppDelegate app;
    app.applicationDidFinishLaunching();

    // 4. Run main message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
#endif
