// Lab02_�պ���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab02_�պ���.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: change error code to suit your needs
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
			CString str;
			_tsetlocale(LC_ALL, _T("")); //�ֿܼ��� �ѱ� ��� ����
			_tprintf(_T("��Ģ���� ������ �Է��Ͻÿ�:\n"));
			//str Ű����� �Է¹ޱ�
			//_tscanf(_T("%s"), &str);  ///////////////
			string str_;
			//_tscanf(_T("%s", &str_));
			getline(cin, str_);  //getline()���� ���ڿ� �޾ƿ���
			str = str_.c_str();  //string���� str_c�� CString���� ��ȯ


			UINT cal_index = str.FindOneOf(_T("+-*/")); //�����ڰ� ��ġ�� �ε��� ã�Ƽ� ��ȯ
			double result;	
			double x, y;
			//ttof : CString���� ������������ ��ȯ
			x = _ttof((LPCTSTR)str.Left(cal_index));  
			y = _ttof((LPCTSTR)str.Mid(cal_index+1));  //������ �� �ڿ� �κк��� ~
			
			if (str[cal_index] == '+')
			{
				result =( x + y);
			}
			else if (str[cal_index] == '-')
			{
				result = (x - y);
			}
			else if (str[cal_index] == '*')
			{
				result = (x*y);
			}
			else if (str[cal_index] == '/')
			{
				result = (x / y);
			}
			else
			{
				_tprintf(_T("�ùٸ��� �Էµ��� �ʾҽ��ϴ�.\n"));
				return 0;
			}

			_tprintf(_T("%lf\n"), result);
		}
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
