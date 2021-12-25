// test.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include "Source/gtx_0x106C.hpp"
#include "Source/registry.hpp"
#include "Source/file.hpp"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

static Class1 class1;
static Class2 class2;
static Class3 class3;
static Class4 class4;

static void DoCrtFuncs()
{
	struct _stat buf;
	_stat( "meh", &buf );
}

float floatVal = 12.0f;
int test = 7;

extern "C" void __cdecl clear();

void __declspec(naked) test3()
{

}

int __stdcall SkipWhiteSpace_4DA390(char *pStr)
{
	return 0;
}

char *__stdcall sub_4DA3F0(char *pStr)
{
	return 0;
}

char bPlay_replay_67D4F4 = 0;
char bConstant_replay_save_67D5C4 = 0;
int bStartNetworkGame_7081F0 = 0;

// MATCH
void __stdcall ParseCommandLine_4DA320(char *pCommandLine)
{
  char* pIter = pCommandLine;
  int len = SkipWhiteSpace_4DA390(pCommandLine);
  _strupr(pCommandLine);
  while ( len > 0 )
  {
      if ( *pIter == '-' || *pIter == '/' )
      {
        const char cmd_char = *(++pIter);
		switch(cmd_char)
		{
		case 'R':
			bPlay_replay_67D4F4 = 1;
			break;

		case 'Q':
			bConstant_replay_save_67D5C4 = 1; 
			break;

		case 'N':
			bStartNetworkGame_7081F0 = 1; 
			break;

		default:
			break;
		}
      }
      
      pIter = sub_4DA3F0(pIter);
	  --len;
  }
}

void test_file()
{
    File::GetFileSize_4A6B10(0);
    File::IsCdRomDrive_4A6BB0(0);
    File::ReadFileToBuffer_4A6C80(0, 0);
    File::Read_4A6D90(0, 0, 0, 0);
    File::WriteBufferToFile_4A6E80(0, 0, 0);
    File::Write_4A6F30(0, 0, 0, 0);
    File::AppendBufferToFile_4A6F50(0, 0, 0);
    File::CreateFile_4A7000(0);
    File::Global_Open_4A7060("lol.txt");
    File::Global_Close_4A70C0();
    File::Global_Close_UnChecked_4A7110();
    File::Global_Seek_4A7140(0);
    File::File_Error_4A7190(0, 0, 0);
    File::Global_Read_4A71C0(0, 0);
    File::GetRemainderSize_4A7250(0, 0);
    File::SkipWhitespace_4A7340(0);
}

void test_gtx_0x106C()
{
    gtx_0x106C c;
    c.sub_5AA3B0(0);
    c.LoadSty_5AB750("blah.sty");
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	gRegistry_6FF968.Open_Sound_Root_586A00(NULL);
	gRegistry_6FF968.Get_Sound_Settting_586A70("lol");
	gRegistry_6FF968.Set_Sound_Setting_586AE0("lol", 5);

    test_file();
    test_gtx_0x106C();

	ParseCommandLine_4DA320("");


	//clear();
	test3();

	sharp_bose_0x54* p54 = new sharp_bose_0x54();
	p54->sub_5BECF0(1,2);

	p54->field_18.sub_5BEBF0();
	delete p54;

	DoCrtFuncs();

	class1.InlineFunc();

	floatVal = floatVal / 3.45f;

	printf("Float v = %f\n", floatVal);

	test = test >> 7;
	test = test << 3;
	test = test / 3;
	test = test % 4;
	printf("test %d\n", test);

	const int total = class1.DoTheCalc() + class2.DoTheCalc() + class3.DoTheCalc() + class4.DoTheCalc();
	printf("Total = %d\n", total);

	return 7;
/*
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_TEST);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
*/
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
/*
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_TEST);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_TEST;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
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
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
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

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
*/
