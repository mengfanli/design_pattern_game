// win32_helloword.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "win32_helloword.h"
#include "concrete_character.h"
#include "concrete_decorator.h"
#define MAX_LOADSTRING 100

//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define IDB_ONE     3301  
#define IDB_TWO     3302  
#define IDB_THREE   3303 

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif


// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
int r = 125;
int g = 125;
int b = 125;
COLORREF color = RGB(r, g, b);
//定义一个颜色索引color
WCHAR infor[64];
WCHAR str[64];
int x = 200, y = 150;

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	Iwarrior *pSoldier = new Soldier();
	EquipmentDedcorator *pArmour = new Armour(pSoldier);
	//count << pArmour->Name()<<endl;
	int mystringSize = (int)(pArmour->Name().length() + 1);
	
	//WCHAR* mywstring = new WCHAR[mystringSize];
	printf("len of string is %d", mystringSize);
	MultiByteToWideChar(CP_ACP, 0, pArmour->Name().c_str(), -1, infor, mystringSize);
	//int att = ;

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32_HELLOWORD, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32_HELLOWORD));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32_HELLOWORD));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32_HELLOWORD);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

			case IDB_ONE:
				//MessageBox(hWnd, L"您点击了第一个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
				SendMessage((HWND)lParam, WM_SETTEXT, (WPARAM)NULL, (LPARAM)L"第一个按鈕已点击");
				break;
			case IDB_TWO:
				MessageBox(hWnd, L"您点击了第二个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
				break;
			case IDB_THREE:
				MessageBox(hWnd, L"您点击了第三个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

	case WM_CREATE:
		{
			//创建三个按钮  
			CreateWindow(L"Button", L"按钮一", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 10, 120, 60, hWnd, (HMENU)IDB_ONE, hInst, NULL);
			CreateWindow(L"Button", L"按钮二", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 80, 120, 60, hWnd, (HMENU)IDB_TWO, hInst, NULL);
			CreateWindow(L"Button", L"按钮三", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 150, 120, 60, hWnd, (HMENU)IDB_THREE, hInst, NULL);
		}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SetTextColor(hdc, color);//设置文本的颜色
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
			TextOut(hdc, x, y, L"Hello World!", 12);/* 参数解释: hdc 待输出的设备 0 坐标x 0 坐标y L"Hello World!"  
													L表示将ANSI字符转换为unicode 以便支持中文,Hello World!表示要打印的字符串 12 表示要输出的字符数*/
			//swprintf_s(infor, L"r:%d,g:%d,b:%d\nx=%d,y=%d", r, g, b, x, y);//格式化字符串
			TextOut(hdc, x, y - 100, infor, wcslen(infor));
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_LBUTTONDOWN://鼠标左击消息
		color = RGB(255, 0, 0);
		InvalidateRect(hWnd, NULL, TRUE);/* InvalidateRect参数 hWnd 窗口句柄 NULL 设置矩形 TRUE 设置重画*/
		break;
	case WM_RBUTTONDOWN://鼠标右击消息
		color = RGB(0, 0, 255);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);//得到x坐标
		y = HIWORD(lParam);//得到y坐标
		InvalidateRect(hWnd, NULL, TRUE);//发出重绘消息
		break;
	case WM_MOUSEWHEEL:
	{
		//得到鼠标滚轮的参数
		int zDelta = (short)HIWORD(wParam);
		if (zDelta > 0) //正值向前
		{
			if (g < 255)
				g += 1;

		}
		else //负值向后
		{
			if (g > 0)
				g--;
		}
		color = RGB(0, g, 122);
		InvalidateRect(hWnd, NULL, TRUE);
	}
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
