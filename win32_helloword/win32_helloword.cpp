// Win32LevelRail1.5.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
//#include "Win32LevelRail1.5.h"
#include "win32_helloword.h"

#define MAX_LOADSTRING 100

//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define IDB_ONE     3301  
#define IDB_TWO     3302  
#define IDB_THREE   3303 
#define IDB_FOUR    3004
#define IDB_TANK    3010
#define IDB_ASSA	3011
#define IDB_SOLD    3012
#define IDB_EQP1    3020
#define IDB_EQP2    3021
#define IDB_EQP3    3022
#define IDB_STC1    3020
#define IDB_STC2    3021
#define IDB_STC3    3022
#define IDB_BKU1    3020
#define IDB_BKU2    3021
#define IDB_BKU3    3022

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
#define GET_ARRAY_LEN(array, len) {len = (sizeof(array) / sizeof(array[0]));}

// Global Variables:
//enum attribute_type { hp, att, def, coins, exper, NUM_ATTRI };
//enum character_type {soldier,assassin,tank};
int test;
HINSTANCE hInst;								// current instance
int nCS;								//nCmdShow
TCHAR szTitle[MAX_LOADSTRING] = { L"主窗口" };					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
TCHAR szTitle2[MAX_LOADSTRING] = { L"第二窗口" };
TCHAR szWindowClass2[MAX_LOADSTRING] = { L"Submarine" };    // 第二个窗口类的类名
HWND hWnd, hWnd2;
HWND hwnd;
WCHAR infor[10][64];
//Istrategy *strategy1 = new ConcreteStrategy1();
//Istrategy *strategy2 = new ConcreteStrategy2();
//Istrategy *strategy3 = new ConcreteStrategy3();

//享元池初始化
std::map<std::string, Strange*> StrangeFactory::m_map = std::map<std::string, Strange*>();

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance2(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProc4(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProc5(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	hInst = hInstance; // 将实例句柄存储在全局变量中
	nCS = nCmdShow;

	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32_HELLOWORD, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance2(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32_HELLOWORD));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex, wcex2,wcex3,wcex4,wcex5;
	//第一个窗口类
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32_HELLOWORD));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32_HELLOWORD);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	// 第二个窗口类的定义
	wcex2.cbSize = sizeof(WNDCLASSEX);
	wcex2.style = CS_HREDRAW | CS_VREDRAW;
	wcex2.lpfnWndProc = (WNDPROC)WndProc2;
	wcex2.cbClsExtra = 0;
	wcex2.cbWndExtra = 0;
	wcex2.hInstance = hInstance;
	wcex2.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_WIN32_HELLOWORD);
	wcex2.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex2.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex2.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32_HELLOWORD);
	wcex2.lpszClassName = szWindowClass2;//L"windows3"
	wcex2.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	// 第三个窗口类的定义
	wcex3.cbSize = sizeof(WNDCLASSEX);
	wcex3.style = CS_HREDRAW | CS_VREDRAW;
	wcex3.lpfnWndProc = (WNDPROC)WndProc3;
	wcex3.cbClsExtra = 0;
	wcex3.cbWndExtra = 0;
	wcex3.hInstance = hInstance;
	wcex3.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_WIN32_HELLOWORD);
	wcex3.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex3.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex3.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32_HELLOWORD);
	wcex3.lpszClassName = L"windows3";
	wcex3.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	// 第四个窗口类的定义
	wcex4.cbSize = sizeof(WNDCLASSEX);
	wcex4.style = CS_HREDRAW | CS_VREDRAW;
	wcex4.lpfnWndProc = (WNDPROC)WndProc4;
	wcex4.cbClsExtra = 0;
	wcex4.cbWndExtra = 0;
	wcex4.hInstance = hInstance;
	wcex4.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_WIN32_HELLOWORD);
	wcex4.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex4.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex4.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32_HELLOWORD);
	wcex4.lpszClassName = L"windows4";
	wcex4.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	// 第五个窗口类的定义
	wcex5.cbSize = sizeof(WNDCLASSEX);
	wcex5.style = CS_HREDRAW | CS_VREDRAW;
	wcex5.lpfnWndProc = (WNDPROC)WndProc5;
	wcex5.cbClsExtra = 0;
	wcex5.cbWndExtra = 0;
	wcex5.hInstance = hInstance;
	wcex5.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_WIN32_HELLOWORD);
	wcex5.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex5.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex5.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32_HELLOWORD);
	wcex5.lpszClassName = L"windows5";
	wcex5.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	return (RegisterClassEx(&wcex) && RegisterClassEx(&wcex2) && RegisterClassEx(&wcex3)&&RegisterClassEx(&wcex4)&&RegisterClassEx(&wcex5));
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance5(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // Store instance handle in our global variable
	//创建存档窗口
	hWnd = CreateWindow(L"windows5", L"存档窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
BOOL InitInstance4(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // Store instance handle in our global variable
	//创建第一个窗口
	hWnd = CreateWindow(L"windows4", L"技能窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
BOOL InitInstance3(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // Store instance handle in our global variable
	//创建第一个窗口
	hWnd = CreateWindow(L"windows3", L"装备窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
BOOL InitInstance2(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable
	//创建第一个窗口
	hWnd = CreateWindow(szWindowClass2, L"角色窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

BOOL InitInstance1(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // Store instance handle in our global variable
	//创建第一个窗口
	hWnd = CreateWindow(szWindowClass, /*szTitle*/L"主窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}
	hwnd = hWnd;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int h ,a ,d,c,e;
	int size;
	TCHAR s[5][6] = { L"HP ：", L"ATT:",L"DEF:",L"COIN:",L"EP:" };
	TCHAR szText[256];
	//找怪可能找的怪或者老头，以及可能的掉血加血值
	static std::string s_strangeType[4] = { "M","M","M","H" };
	//static Context *context = new Context();
	int strangeLen; 

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"确认离开程序", L"警告", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDB_ONE:
			//MessageBox(hWnd, L"您点击了第一个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
		{
			srand((unsigned)time(NULL));
			GET_ARRAY_LEN(s_strangeType, strangeLen);
			int typeIndex = rand() % strangeLen;
			std::string type = s_strangeType[typeIndex];
			Strange *p = StrangeFactory::getStrange(type);
			//Iequipment *p = new GetinfoAdapter(type);
			p->assignAttDef(rand() % 10+1);
			p->mission();
			//Singleton_player::GetInstance().doSomething(p);
			h = Singleton_player::GetInstance().get_info(hp);
			if (h <= 0) {
				MessageBox(hWnd, L"您挂了，游戏结束。", L"提示", MB_OK | MB_ICONINFORMATION);
				PostQuitMessage(0);
			}
		}
			break;
		case IDB_TWO:
			//MessageBox(hWnd, L"您点击了技能窗口按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
			if (!InitInstance4(hInst, nCS))
			{
				return FALSE;
			}

			break;
		case IDB_THREE:
			//MessageBox(hWnd, L"您点击了装备窗口按钮。", L"提示", MB_OK | MB_ICONINFORMATION);

			if (!InitInstance3(hInst, nCS))
			{
				return FALSE;
			}
			break;
		case IDB_FOUR:
			//MessageBox(hWnd, L"您点击了存档窗口按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
			if (!InitInstance5(hInst, nCS))
			{
				return FALSE;
			}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
	{
		//创建四个按钮  
		CreateWindow(L"Button", L"找怪", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 10, 120, 60, hWnd, (HMENU)IDB_ONE, hInst, NULL);
		CreateWindow(L"Button", L"技能", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 80, 120, 60, hWnd, (HMENU)IDB_TWO, hInst, NULL);
		CreateWindow(L"Button", L"背包", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 150, 120, 60, hWnd, (HMENU)IDB_THREE, hInst, NULL);
		CreateWindow(L"Button", L"存档", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 220, 120, 60, hWnd, (HMENU)IDB_FOUR, hInst, NULL);
		
	}
	break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		h = Singleton_player::GetInstance().get_info(hp);
		size = wsprintf(szText, TEXT("%s%d"), s[0], h);
		TextOut(hdc, 300, 50, szText, size);

		a = Singleton_player::GetInstance().get_info(att);
		size = wsprintf(szText, TEXT("%s%d"), s[1], a);
		TextOut(hdc, 300, 150, szText, size);

		d = Singleton_player::GetInstance().get_info(def);
		size = wsprintf(szText, TEXT("%s%d"), s[2], d);
		TextOut(hdc, 300, 250, szText, size);

		c = Singleton_player::GetInstance().get_info(coins);
		size = wsprintf(szText, TEXT("%s%d"), s[3], c);
		TextOut(hdc, 500, 50, szText, size);
		e = Singleton_player::GetInstance().get_info(exper);
		size = wsprintf(szText, TEXT("%s%d"), s[4], e);
		TextOut(hdc, 500, 150, szText, size);
		//END TODO
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"确认离开窗口", L"警告", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDB_TANK:
			MessageBox(hWnd, L"您选择了坦克角色。", L"提示", MB_OK | MB_ICONINFORMATION);
			Singleton_player::GetInstance().init_character(tank);
			DestroyWindow(hWnd);
			break;
		case IDB_ASSA:
			MessageBox(hWnd, L"您选择了刺客角色。", L"提示", MB_OK | MB_ICONINFORMATION);
			Singleton_player::GetInstance().init_character(assassin);
			DestroyWindow(hWnd);//
			break;
		case IDB_SOLD:
			MessageBox(hWnd, L"您选择了战士角色。", L"提示", MB_OK | MB_ICONINFORMATION);
			Singleton_player::GetInstance().init_character(soldier);
			DestroyWindow(hWnd);//IDB_SOLD
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
	{
		//创建两个按钮  
		CreateWindow(L"Button", L"坦克", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 10, 120, 60, hWnd, (HMENU)IDB_TANK, hInst, NULL);
		CreateWindow(L"Button", L"刺客", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 80, 120, 60, hWnd, (HMENU)IDB_ASSA, hInst, NULL);
		CreateWindow(L"Button", L"战士", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 150, 120, 60, hWnd, (HMENU)IDB_SOLD, hInst, NULL);
		//CreateWindow(L"Button", L"商店", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		//	35, 220, 120, 60, hWnd, (HMENU)IDB_FOUR, hInst, NULL);
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//InvalidateRect(hWnd, NULL, TRUE);//发出重绘消息
		//PostQuitMessage(0);
		if (!InitInstance1(hInst, nCS))
		{
			return FALSE;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK WndProc3(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static Afactory *pequipfatcory1 = new Equipfactory1;
	static Afactory *pequipfatcory2 = new Equipfactory2;
	static Afactory *pequipfatcory3 = new Equipfactory3;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"确认离开窗口", L"警告", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDB_EQP1:
		{
			Iequipment *peq1 = pequipfatcory1->Createequip();
			if (peq1 != NULL) {
				MessageBox(hWnd, L"您购买了装备1", L"提示", MB_OK | MB_ICONINFORMATION);
				Singleton_player::GetInstance().doSomething(peq1);
			}
			else
			MessageBox(hWnd, L"买不起，sorry", L"提示", MB_OK | MB_ICONINFORMATION);
			SAFE_DELETE(peq1);
		}
			break;
		case IDB_EQP2:
		{
			Iequipment *peq2 = pequipfatcory2->Createequip();
			if (peq2 != NULL) {
				MessageBox(hWnd, L"您购买了装备3", L"提示", MB_OK | MB_ICONINFORMATION);
				Singleton_player::GetInstance().doSomething(peq2);
			}
			else
			MessageBox(hWnd, L"买不起，sorry", L"提示", MB_OK | MB_ICONINFORMATION);
			SAFE_DELETE(peq2);
		}
			break;
		case IDB_EQP3:
		{
			Iequipment *peq3 = pequipfatcory3->Createequip();
			if (peq3 != NULL) {
				MessageBox(hWnd, L"您购买了装备3", L"提示", MB_OK | MB_ICONINFORMATION);
				Singleton_player::GetInstance().doSomething(peq3);
			}
			else
			MessageBox(hWnd, L"买不起，sorry", L"提示", MB_OK | MB_ICONINFORMATION);
			SAFE_DELETE(peq3);
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
	{
		//创建两个按钮  
		CreateWindow(L"Button", L"购买铁剑", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 10, 120, 60, hWnd, (HMENU)IDB_EQP1, hInst, NULL);
		CreateWindow(L"Button", L"购买布甲", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 80, 120, 60, hWnd, (HMENU)IDB_EQP2, hInst, NULL);
		CreateWindow(L"Button", L"购买红宝石", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 150, 120, 60, hWnd, (HMENU)IDB_EQP3, hInst, NULL);
		//CreateWindow(L"Button", L"商店", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		//	35, 220, 120, 60, hWnd, (HMENU)IDB_FOUR, hInst, NULL);
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//InvalidateRect(hWnd, NULL, TRUE);//发出重绘消息
		//PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK WndProc4(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"确认离开窗口", L"警告", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDB_STC1:
		{
			Singleton_player::GetInstance().set_context(1);
				MessageBox(hWnd, L"您选择了技能 双倍金币", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		case IDB_STC2:
		{
			Singleton_player::GetInstance().set_context(2);
			MessageBox(hWnd, L"您选择了技能 双倍经验", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		case IDB_STC3:
		{
			Singleton_player::GetInstance().set_context(3);
			MessageBox(hWnd, L"您选择了技能 双倍伤害", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
	{
		//创建两个按钮  
		CreateWindow(L"Button", L"双倍金币", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 10, 120, 60, hWnd, (HMENU)IDB_STC1, hInst, NULL);
		CreateWindow(L"Button", L"双倍经验", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 80, 120, 60, hWnd, (HMENU)IDB_STC2, hInst, NULL);
		CreateWindow(L"Button", L"双倍伤害", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 150, 120, 60, hWnd, (HMENU)IDB_STC3, hInst, NULL);
		//CreateWindow(L"Button", L"商店", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		//	35, 220, 120, 60, hWnd, (HMENU)IDB_FOUR, hInst, NULL);
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//InvalidateRect(hWnd, NULL, TRUE);//发出重绘消息
		//PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK WndProc5(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static Memento_Manager *memento_manager;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"确认离开窗口", L"警告", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDB_BKU1:
		{
			Singleton_player::GetInstance().set_context(1);
				MessageBox(hWnd, L"您选择了备份1", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		case IDB_BKU2:
		{
			Singleton_player::GetInstance().set_context(2);
			MessageBox(hWnd, L"您选择了备份2", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		case IDB_BKU3:
		{
			Singleton_player::GetInstance().set_context(3);
			MessageBox(hWnd, L"您选择了备份3", L"提示", MB_OK | MB_ICONINFORMATION);
				DestroyWindow(hWnd);
		}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
	{
		//创建两个按钮  
		CreateWindow(L"Button", L"还原点一", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 10, 120, 60, hWnd, (HMENU)IDB_STC1, hInst, NULL);
		CreateWindow(L"Button", L"还原点二", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 80, 120, 60, hWnd, (HMENU)IDB_STC2, hInst, NULL);
		CreateWindow(L"Button", L"还原点三", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			35, 150, 120, 60, hWnd, (HMENU)IDB_STC3, hInst, NULL);
		//CreateWindow(L"Button", L"商店", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		//	35, 220, 120, 60, hWnd, (HMENU)IDB_FOUR, hInst, NULL);
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//InvalidateRect(hWnd, NULL, TRUE);//发出重绘消息
		//PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
// Message handler for about box.
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
