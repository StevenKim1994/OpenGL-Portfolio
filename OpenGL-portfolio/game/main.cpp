#include "main.h"

#include "game.h"
HINSTANCE hInstance;
HWND hWnd;
HDC hDC;
bool runWnd;

WCHAR szTitle[100] = TEXT("Kim SiYun OpenGL portfolio");
WCHAR szWindowClass[100] = TEXT("main");

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInst,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR		lpCmdLine,
	_In_ int		nCmdShow)
{
	ULONG_PTR gpToken = startGdiplus();
	hInstance = hInst;
	
	WNDCLASSEXW wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;	
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPENGLPORTFOLIO));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szWindowClass;
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wc);

	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	hDC = GetDC(hWnd);

	RECT rect;
	GetClientRect(hWnd, &rect); // 스크롤바 타이틀바 제외한 윈도우창 Rect 크기 받아옴

	monitorSizeW = rect.right - rect.left;
	monitorSizeH = rect.bottom - rect.top;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	runWnd = true;

	MSG msg;
	while(runWnd)
	{
		if(PeekMessage(&msg, NULL, 0,0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SwapBuffers(hDC);
		}
	}

	DestroyWindow(hWnd);
	endGdiplus(gpToken);

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
		break;
	case WM_SIZING:
		break;
	case WM_MOVE:

		break;

	case WM_CLOSE:
		if (IDYES == MessageBoxW(NULL, TEXT("Exit?"), TEXT("Alert"), MB_YESNO))
		{
			runWnd = false;
		}
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}