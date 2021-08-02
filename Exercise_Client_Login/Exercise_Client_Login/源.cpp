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
    //���ø�ѡ��
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
        //��ѡ����
        ListView_SetExtendedListViewStyle(hList, LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

        InsertColumn(hList, 0);
        InsertColumn(hList, 1, 100,L"���");
        InsertColumn(hList, 2, 100, L"ʱ��");
        InsertColumn(hList, 3, 100, L"����");
        InsertColumn(hList, 4, 100, L"����");

        InsertItem(hList, 0, L"2011", L"9��5��", L"�廪��ѧ",L"600");
        InsertItem(hList, 1, L"2009", L"9��13��", L"�����¶���",L"800");
     //   InsertItem(hList, 1, L"2011", L"9��5��", L"�廪��ѧ",L"600");


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
