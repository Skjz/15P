#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<windowsx.h>
#include <CommCtrl.h>
#include"resource.h"

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
VOID InsertColumn(HWND hList, int nIndex, int nWidth = 0, LPCWSTR lpText = L"", int nFormat = LVCFMT_CENTER)
{
    LV_COLUMN lvColumn = { LVCF_FMT | LVCF_TEXT | LVCF_WIDTH };
    lvColumn.fmt = nFormat;
    lvColumn.cx = nWidth;
    lvColumn.pszText = (LPWSTR)lpText;

    ListView_InsertColumn(hList, nIndex, &lvColumn);
}

VOID InsertItem(HWND hList, int nRow, LPCWSTR lpText1, LPCWSTR lpText2, LPCWSTR lpText3, LPCWSTR lpText4)
{
    LVITEM lvItem = { LVIF_TEXT };

    lvItem.iItem = nRow;
    lvItem.iSubItem = 0;
    lvItem.pszText = (LPWSTR)L"";

    ListView_InsertItem(hList, &lvItem);
    //设置复选框
    ListView_SetCheckState(hList, nRow, TRUE);
    ListView_SetItemText(hList, nRow, 1, (LPWSTR)lpText1);
    ListView_SetItemText(hList, nRow, 2, (LPWSTR)lpText2);
    ListView_SetItemText(hList, nRow, 3, (LPWSTR)lpText3);
    ListView_SetItemText(hList, nRow, 4, (LPWSTR)lpText4);


}

INT_PTR CALLBACK DlgProc2(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    static auto hInstance = GetModuleHandle(NULL);

    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        HWND hList = GetDlgItem(hDlg, IDC_LIST3);
        //复选框风格
        ListView_SetExtendedListViewStyle(hList, LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

        InsertColumn(hList, 0);
        InsertColumn(hList, 1, 100,L"年份");
        InsertColumn(hList, 2, 100, L"时间");
        InsertColumn(hList, 3, 100, L"经历");
        InsertColumn(hList, 4, 100, L"分数");

        InsertItem(hList, 0, L"2011", L"9月5号", L"清华大学",L"600");
        InsertItem(hList, 1, L"2009", L"9月13号", L"蓝翔新东方",L"800");
     //   InsertItem(hList, 1, L"2011", L"9月5号", L"清华大学",L"600");


        break;
    }
    case WM_CLOSE:
    {
        EndDialog(hDlg, 0);
    }
    default:
    {
        return FALSE;
    }

    }


    return TRUE;
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static auto hInstance = GetModuleHandle(NULL);

    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        break;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == IDOK &&HIWORD(wParam)==BN_CLICKED)
        {
            DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, DlgProc2);

        }
        break;
    }
    case WM_CLOSE:
    {
        EndDialog(hDlg, 0);
    }



    default:
    {
        return FALSE;
    }


    }

    return TRUE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int nShowCmd)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
    

    return 0;
}
