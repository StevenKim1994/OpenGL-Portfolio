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

	loadLib(hDC);
	loadGame();
	
	
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

			
			drawLib(drawGame);
			SwapBuffers(hDC);
		}
	}

	freeLib();
	freeGame();
	

	DestroyWindow(hWnd);
	endGdiplus(gpToken);

	return (int)msg.wParam;
}

iPoint convertCoordinate(int x, int y)
{
    RECT rt;
    //GetWindowRect(hWnd, &rt);
    GetClientRect(hWnd, &rt);

    iPoint r;
    r.x = x - rt.left;
    r.y = y - rt.top;

    r.x = (r.x - viewport.origin.x) * devSize.width / viewport.size.width;
    r.y = (r.y - viewport.origin.y) * devSize.height / viewport.size.height;

    return r;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        RECT rt0, rt1;
        GetWindowRect(hWnd, &rt0);
        GetClientRect(hWnd, &rt1);
        win_border_width = (rt0.right - rt0.left) - (rt1.right - rt1.left);
        win_border_height = (rt0.bottom - rt0.top) - (rt1.bottom - rt1.top);
        break;
    }

    case WM_GETMINMAXINFO:
    {
        if (win_border_width == 0 || win_border_height == 0)
            break;

        float rate = devSize.width / devSize.height;
        float width = monitorSizeW * DEV_MIN_RATE;
        float height = width / rate;

        MINMAXINFO* mmi = (MINMAXINFO*)lParam;
        mmi->ptMinTrackSize.x = width + win_border_width;
        mmi->ptMinTrackSize.y = height + win_border_height;
        break;
    }

    case WM_SIZE:
        // client rect
        resizeLib(LOWORD(lParam), HIWORD(lParam));

        drawLib(drawGame);
        SwapBuffers(hDC);
        break;
    case WM_SIZING:
    {
        // window rect
        RECT& rect = *reinterpret_cast<LPRECT>(lParam);
        enforceResolution((int)wParam, rect, win_border_width, win_border_height);
        //RECT rect;
        //GetClientRect(hWnd, &rect);
        resizeLib(rect.right - rect.left, rect.bottom - rect.top);

        drawLib(drawGame);
        SwapBuffers(hDC);
        break;
    }
    case WM_MOVE:
    {
        // window rect
        RECT rect;
        GetClientRect(hWnd, &rect);
        resizeLib(rect.right - rect.left, rect.bottom - rect.top);

        drawLib(drawGame);
        SwapBuffers(hDC);
        break;
    }

    case WM_LBUTTONDOWN:
        cursor = convertCoordinate(LOWORD(lParam), HIWORD(lParam));
        keyGame(iKeyStateBegan, cursor);
        break;
    case WM_MOUSEMOVE:
        cursor = convertCoordinate(LOWORD(lParam), HIWORD(lParam));
        keyGame(iKeyStateMoved, cursor);
        break;
    case WM_LBUTTONUP:
        cursor = convertCoordinate(LOWORD(lParam), HIWORD(lParam));
        keyGame(iKeyStateEnded, cursor);
        break;
    case WM_SETCURSOR:
        if (updateCursor(LOWORD(lParam) == HTCLIENT))
            return true;
        break;

        //case WM_CHAR:
        //    break;
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
            goFullscreen();
        keyLib(iKeyStateBegan, wParam);
        break;
    case WM_KEYUP:
        keyLib(iKeyStateEnded, wParam);
        break;

    case WM_CLOSE:
        if (IDYES == MessageBoxW(NULL, TEXT("게임을 종료하시겠습니까?"), TEXT("알림"), MB_YESNO))
        {
            runWnd = false;
        }
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

// ------------------------------------
// Cursor
// ------------------------------------
static Texture* texCursor;
iPoint cursor;
static bool bCursor;

void loadCursor()
{
    
}

void freeCursor()
{
  
}

void drawCursor(float dt)
{
  
}

bool updateCursor(bool inClient)
{

    return NULL;
}

void setCurrentMonitor(RECT& rt)
{
    GetWindowRect(hWnd, &rt);
    HMONITOR hMonitor = MonitorFromRect(&rt, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi;
    mi.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(hMonitor, &mi);
    if (mi.dwFlags == MONITORINFOF_PRIMARY)
    {
        rt.left = 0;
        rt.top = 0;
        rt.right = GetSystemMetrics(SM_CXSCREEN);
        rt.bottom = GetSystemMetrics(SM_CYSCREEN);
    }
    else
    {
        memcpy(&rt, &mi.rcWork, sizeof(RECT));
    }
}

bool isFullscreen;
RECT rtPrev;
void goFullscreen()
{
    isFullscreen = !isFullscreen;
    if (isFullscreen)
    {
        GetWindowRect(hWnd, &rtPrev);

        RECT rt;
        setCurrentMonitor(rt);
        int x = rt.left, y = rt.top;
        int w = rt.right - rt.left, h = rt.bottom - rt.top;
        //SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW);
        SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);
        SetWindowPos(hWnd, HWND_TOP, x, y, w, h, SWP_SHOWWINDOW);
    }
    else
    {
        int x = rtPrev.left, y = rtPrev.top;
        int w = rtPrev.right - rtPrev.left, h = rtPrev.bottom - rtPrev.top;
        //SetWindowLong(hWnd, GWL_STYLE, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
        SetWindowLong(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
        SetWindowPos(hWnd, HWND_TOP, x, y, w, h, SWP_SHOWWINDOW);
    }
}

int win_border_width = 0, win_border_height = 0;
void enforceResolution(int edge, RECT& rect, int win_border_width, int win_border_height)
{
    switch (edge) {

    case WMSZ_BOTTOM:
    case WMSZ_TOP:
    {
        int h = (rect.bottom - rect.top) - win_border_height;
        int w = h * devSize.width / devSize.height + win_border_width;
        rect.left = (rect.left + rect.right) / 2 - w / 2;
        rect.right = rect.left + w;
        break;
    }

    case WMSZ_LEFT:
    case WMSZ_RIGHT:
    {
        int w = (rect.right - rect.left) - win_border_width;
        int h = w * devSize.height / devSize.width + win_border_height;
        rect.top = (rect.top + rect.bottom) / 2 - h / 2;
        rect.bottom = rect.top = h;
        break;
    }

    case WMSZ_BOTTOMLEFT:
    {
        int w = (rect.right - rect.left) - win_border_width;
        int h = (rect.bottom - rect.top) - win_border_height;
        // if( w/h > devSize.width/devSize.height )
        if (w * devSize.height > devSize.width * h)
        {
            w = h * devSize.width / devSize.height + win_border_width;
            rect.left = rect.right - w;
        }
        else
        {
            h = w * devSize.height / devSize.width + win_border_height;
            rect.bottom = rect.top + h;
        }
        break;
    }

    case WMSZ_BOTTOMRIGHT:
    {
        int w = (rect.right - rect.left) - win_border_width;
        int h = (rect.bottom - rect.top) - win_border_height;
        // if( w/h > devSize.width/devSize.height )
        if (w * devSize.height > devSize.width * h)
        {
            w = h * devSize.width / devSize.height + win_border_width;
            rect.right = rect.left + w;
        }
        else
        {
            h = w * devSize.height / devSize.width + win_border_height;
            rect.bottom = rect.top + h;
        }
        break;
    }

    case WMSZ_TOPLEFT:
    {
        int w = (rect.right - rect.left) - win_border_width;
        int h = (rect.bottom - rect.top) - win_border_height;
        // if( w/h > devSize.width/devSize.height )
        if (w * devSize.height > devSize.width * h)
        {
            w = h * devSize.width / devSize.height + win_border_width;
            rect.left = rect.right - w;
        }
        else
        {
            h = w * devSize.height / devSize.width + win_border_height;
            rect.top = rect.bottom - h;
        }
        break;
    }

    case WMSZ_TOPRIGHT:
    {
        int w = (rect.right - rect.left) - win_border_width;
        int h = (rect.bottom - rect.top) - win_border_height;
        // if( w/h > devSize.width/devSize.height )
        if (w * devSize.height > devSize.width * h)
        {
            w = h * devSize.width / devSize.height + win_border_width;
            rect.right = rect.left + w;
        }
        else
        {
            h = w * devSize.height / devSize.width + win_border_height;
            rect.top = rect.bottom - h;
        }
        break;
    }
    }
}