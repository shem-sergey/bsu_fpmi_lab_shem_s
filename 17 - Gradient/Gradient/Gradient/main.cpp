#undef UNICODE

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";

COLORREF begin, end;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{	
HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;

	// Заполняем структуру класса окна 
	wcApp.lpszClassName = szClassName;
	wcApp.hInstance		= hInstance;   
	wcApp.lpfnWndProc	= WndProc;
	wcApp.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wcApp.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName	= 0;
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style			= CS_HREDRAW | CS_VREDRAW;
	wcApp.cbClsExtra	= 0;
	wcApp.cbWndExtra	= 0;
	
// Регистрируем класс окна
	if (!RegisterClass(&wcApp)){
		MessageBox(NULL, "Class hasn't been registered", "RegisterClass", MB_OK);
		return 0;
	}

	hWnd=CreateWindow(szClassName, "Simple Windows Program", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg,0,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
	static HDC hdc;
	static PAINTSTRUCT ps;
	static RECT R;
	switch (uMsg) {
	case WM_CREATE:
		begin = RGB(255, 255, 255);
		end = RGB(0, 0, 0);
		break;
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		GetClientRect(hWnd, &R);
		HBRUSH MyBrush;
		MyBrush = CreateSolidBrush(RGB(255,255,255));
		SelectObject(hdc, MyBrush);
		Rectangle(hdc,R.left,R.top,R.right,R.bottom);
		for(int i = 0; i < 30; ++i)
		{
			int r_step, g_step, b_step;
			r_step = (GetRValue(begin) - GetRValue(end))/30;
			g_step = (GetGValue(begin) - GetGValue(end))/30;
			b_step = (GetBValue(begin) - GetBValue(end))/30;
			int r, g, b;
			r = GetRValue(begin) + r_step * i;
			g = GetGValue(begin) + g_step * i;
			b = GetBValue(begin) + b_step * i;
			MyBrush = CreateSolidBrush(RGB(r, g, b));
			SelectObject(hdc, MyBrush);
			HPEN MyPen = CreatePen(PS_NULL, 0, RGB(0,0,0));
			SelectObject(hdc, MyPen);
			int w = R.right/60, h = R.bottom/60;
			Rectangle(hdc, w*i, h*i, R.right - w*i, R.bottom - h*i);
		}
		EndPaint(hWnd,&ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		begin = RGB(rand()%256,rand()%256,rand()%256);
		end = RGB(rand()%256,rand()%256,rand()%256);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	default:
		return (DefWindowProc(hWnd,uMsg,wParam,lParam));
	}
	return (0);
}
