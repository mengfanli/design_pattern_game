// win32_helloword.cpp : ����Ӧ�ó������ڵ㡣
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


// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������
int r = 125;
int g = 125;
int b = 125;
COLORREF color = RGB(r, g, b);
//����һ����ɫ����color
WCHAR infor[64];
WCHAR str[64];
int x = 200, y = 150;

// �˴���ģ���а����ĺ�����ǰ������: 
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

    // TODO: �ڴ˷��ô��롣
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

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32_HELLOWORD, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32_HELLOWORD));

    MSG msg;

    // ����Ϣѭ��: 
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
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
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
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

			case IDB_ONE:
				//MessageBox(hWnd, L"������˵�һ����ť��", L"��ʾ", MB_OK | MB_ICONINFORMATION);
				SendMessage((HWND)lParam, WM_SETTEXT, (WPARAM)NULL, (LPARAM)L"��һ�����o�ѵ��");
				break;
			case IDB_TWO:
				MessageBox(hWnd, L"������˵ڶ�����ť��", L"��ʾ", MB_OK | MB_ICONINFORMATION);
				break;
			case IDB_THREE:
				MessageBox(hWnd, L"������˵�������ť��", L"��ʾ", MB_OK | MB_ICONINFORMATION);
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

	case WM_CREATE:
		{
			//����������ť  
			CreateWindow(L"Button", L"��ťһ", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 10, 120, 60, hWnd, (HMENU)IDB_ONE, hInst, NULL);
			CreateWindow(L"Button", L"��ť��", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 80, 120, 60, hWnd, (HMENU)IDB_TWO, hInst, NULL);
			CreateWindow(L"Button", L"��ť��", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				35, 150, 120, 60, hWnd, (HMENU)IDB_THREE, hInst, NULL);
		}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SetTextColor(hdc, color);//�����ı�����ɫ
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
			TextOut(hdc, x, y, L"Hello World!", 12);/* ��������: hdc ��������豸 0 ����x 0 ����y L"Hello World!"  
													L��ʾ��ANSI�ַ�ת��Ϊunicode �Ա�֧������,Hello World!��ʾҪ��ӡ���ַ��� 12 ��ʾҪ������ַ���*/
			//swprintf_s(infor, L"r:%d,g:%d,b:%d\nx=%d,y=%d", r, g, b, x, y);//��ʽ���ַ���
			TextOut(hdc, x, y - 100, infor, wcslen(infor));
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_LBUTTONDOWN://��������Ϣ
		color = RGB(255, 0, 0);
		InvalidateRect(hWnd, NULL, TRUE);/* InvalidateRect���� hWnd ���ھ�� NULL ���þ��� TRUE �����ػ�*/
		break;
	case WM_RBUTTONDOWN://����һ���Ϣ
		color = RGB(0, 0, 255);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);//�õ�x����
		y = HIWORD(lParam);//�õ�y����
		InvalidateRect(hWnd, NULL, TRUE);//�����ػ���Ϣ
		break;
	case WM_MOUSEWHEEL:
	{
		//�õ������ֵĲ���
		int zDelta = (short)HIWORD(wParam);
		if (zDelta > 0) //��ֵ��ǰ
		{
			if (g < 255)
				g += 1;

		}
		else //��ֵ���
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

// �����ڡ������Ϣ�������
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
