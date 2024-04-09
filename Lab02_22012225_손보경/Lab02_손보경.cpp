// Lab02_손보경.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab02_손보경.h"
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
			_tsetlocale(LC_ALL, _T("")); //콘솔에서 한글 출력 위해
			_tprintf(_T("사칙연산 수식을 입력하시오:\n"));
			//str 키보드로 입력받기
			//_tscanf(_T("%s"), &str);  ///////////////
			string str_;
			//_tscanf(_T("%s", &str_));
			getline(cin, str_);  //getline()으로 문자열 받아오기
			str = str_.c_str();  //string형인 str_c를 CString으로 변환


			UINT cal_index = str.FindOneOf(_T("+-*/")); //연산자가 위치한 인덱스 찾아서 반환
			double result;	
			double x, y;
			//ttof : CString형을 배정도형으로 변환
			x = _ttof((LPCTSTR)str.Left(cal_index));  
			y = _ttof((LPCTSTR)str.Mid(cal_index+1));  //연산자 그 뒤에 부분부터 ~
			
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
				_tprintf(_T("올바르게 입력되지 않았습니다.\n"));
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
