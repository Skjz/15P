#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<tchar.h>
#include"resource.h"
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wparam, LPARAM lparam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        MessageBox(hDlg, _T("对话框创建了"), _T("模态对话框"), MB_OK | MB_ICONWARNING);
        break;
    }
    case WM_CLOSE:
    {
        EndDialog(hDlg, 0);
    }
    default:
    {
        return false;
    }
    return true;
    }
}


int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

    return 0;
}