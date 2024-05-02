
// DialogBase2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DialogBase2.h"
#include "DialogBase2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CDialogBase2Dlg ��ȭ ����



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


// CDialogBase2Dlg �޽��� ó����

BOOL CDialogBase2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_combo.AddString(_T("+"));
	m_combo.AddString(_T("-"));
	m_combo.AddString(_T("*"));
	m_combo.AddString(_T("/"));


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDialogBase2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CDialogBase2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogBase2Dlg::OnBnClickedStart()  //����ڰ�"���"��ư ��������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CString  CStr_x1, CStr_x2, Cstr, print_y;
	double x1, x2, y;

	GetDlgItem(IDC_EDIT1)->GetWindowText(CStr_x1);	//IDC_EDIT1�� �Էµ� �� �о�ͼ� CStr_x1�� ����
	x1 = _ttof(CStr_x1);	//CString�� ������������ ��ȯ�Ͽ� x1�� ����

	GetDlgItem(IDC_EDIT2)->GetWindowText(CStr_x2); //IDC_EDIT2�� �Էµ� �� �о�ͼ� CStr_x2�� ����
	x2 = _ttof(CStr_x2); //CString�� ������������ ��ȯ�Ͽ� x2�� ����

	m_combo.GetLBText(m_combo.GetCurSel(), Cstr);		//�޺��ڽ����� ���о� �ͼ� Cstr�� ����


	if (Cstr == '+') //����
	{
		y = x1 + x2;
		print_y.Format(_T("%.2lf"), y);		//�ڷ�������
		m_edit3.SetWindowTextW(print_y);		//3��° editâ�� ���

	}
	else if (Cstr == '-')   //����
	{
		y = x1 - x2;
		print_y.Format(_T("%.2lf"), y);   
		m_edit3.SetWindowTextW(print_y); 	//3��° editâ�� ���

	}
	else if (Cstr == '*')   //����
	{

		y = x1 * x2;
		print_y.Format(_T("%.2lf"), y);
		m_edit3.SetWindowTextW(print_y);	//3��° editâ�� ���

	}
	else if (Cstr == '/') //������
	{

		y = x1 / x2;
		if (x2 == 0)		//0���� ���������ϸ�
		{
			MessageBox(_T("�߸��� �Է��Դϴ�"), _T("ERROR"), MB_ICONERROR);   //���� �޽��� ����
			return;   
		}
		print_y.Format(_T("%.2lf"), y);	 //�ڷ�������
		m_edit3.SetWindowTextW(print_y);	//3��° editâ�� ���

	}


}




void CDialogBase2Dlg::OnBnClickedClear()  //"CLEAR"��ư ��������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//Ŭ�����ư ������ editâ�� text�� ��� 0���� 
	m_edit1.SetWindowTextW(_T("0"));
	m_edit2.SetWindowTextW(_T("0"));
	m_edit3.SetWindowTextW(_T("0"));

}


