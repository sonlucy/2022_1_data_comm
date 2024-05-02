
// DialogBase2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DialogBase2.h"
#include "DialogBase2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDialogBase2Dlg 대화 상자



CDialogBase2Dlg::CDialogBase2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGBASE2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogBase2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_START, m_start);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}

BEGIN_MESSAGE_MAP(CDialogBase2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CDialogBase2Dlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_CLEAR, &CDialogBase2Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CDialogBase2Dlg 메시지 처리기

BOOL CDialogBase2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_combo.AddString(_T("+"));
	m_combo.AddString(_T("-"));
	m_combo.AddString(_T("*"));
	m_combo.AddString(_T("/"));


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDialogBase2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDialogBase2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDialogBase2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogBase2Dlg::OnBnClickedStart()  //사용자가"계산"버튼 눌렀을때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString  CStr_x1, CStr_x2, Cstr, print_y;
	double x1, x2, y;

	GetDlgItem(IDC_EDIT1)->GetWindowText(CStr_x1);	//IDC_EDIT1에 입력된 값 읽어와서 CStr_x1에 저장
	x1 = _ttof(CStr_x1);	//CString을 배정도형으로 변환하여 x1에 저장

	GetDlgItem(IDC_EDIT2)->GetWindowText(CStr_x2); //IDC_EDIT2의 입력된 값 읽어와서 CStr_x2에 저장
	x2 = _ttof(CStr_x2); //CString을 배정도형으로 변환하여 x2에 저장

	m_combo.GetLBText(m_combo.GetCurSel(), Cstr);		//콤보박스에서 값읽어 와서 Cstr에 저장


	if (Cstr == '+') //덧셈
	{
		y = x1 + x2;
		print_y.Format(_T("%.2lf"), y);		//자료형변경
		m_edit3.SetWindowTextW(print_y);		//3번째 edit창에 출력

	}
	else if (Cstr == '-')   //뺄셈
	{
		y = x1 - x2;
		print_y.Format(_T("%.2lf"), y);   
		m_edit3.SetWindowTextW(print_y); 	//3번째 edit창에 출력

	}
	else if (Cstr == '*')   //곱셈
	{

		y = x1 * x2;
		print_y.Format(_T("%.2lf"), y);
		m_edit3.SetWindowTextW(print_y);	//3번째 edit창에 출력

	}
	else if (Cstr == '/') //나눗셈
	{

		y = x1 / x2;
		if (x2 == 0)		//0으로 나누려고하면
		{
			MessageBox(_T("잘못된 입력입니다"), _T("ERROR"), MB_ICONERROR);   //오류 메시지 띄우기
			return;   
		}
		print_y.Format(_T("%.2lf"), y);	 //자료형변경
		m_edit3.SetWindowTextW(print_y);	//3번째 edit창에 출력

	}


}




void CDialogBase2Dlg::OnBnClickedClear()  //"CLEAR"버튼 눌렀을때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//클리어버튼 눌리면 edit창의 text를 모두 0으로 
	m_edit1.SetWindowTextW(_T("0"));
	m_edit2.SetWindowTextW(_T("0"));
	m_edit3.SetWindowTextW(_T("0"));

}


