
// DialogBase2Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CDialogBase2Dlg ��ȭ ����
class CDialogBase2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CDialogBase2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBASE2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	CButton m_start;
	CComboBox m_combo;
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedClear();
};
