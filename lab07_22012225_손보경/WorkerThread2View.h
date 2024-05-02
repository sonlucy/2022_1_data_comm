// WorkerThread2View.h : CWorkerThread2View Ŭ������ �������̽�
//

#pragma once

struct CirTimerThread
{
	CWnd *pWnd;
	CPoint pos;

	CirTimerThread::CirTimerThread() {}  //�⺻������
	CirTimerThread::CirTimerThread(CWnd *pCWnd, CPoint Cpos) { pWnd = pCWnd; pos = Cpos; }

	void GenerateThread();  //������ ���� 
	void EndThread();  //������ ����
};

class CWorkerThread2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CWorkerThread2View();
	DECLARE_DYNCREATE(CWorkerThread2View)

	// Ư���Դϴ�.
public:
	CWorkerThread2Doc* GetDocument() const;
	CirTimerThread arg, pArg;// *pThread1, *pThread2;
	CArray<CPoint, CPoint> cArray;

	// �۾��Դϴ�.
public:

	// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// �����Դϴ�.
public:
	virtual ~CWorkerThread2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WorkerThread2View.cpp�� ����� ����
inline CWorkerThread2Doc* CWorkerThread2View::GetDocument() const
{
	return reinterpret_cast<CWorkerThread2Doc*>(m_pDocument);
}
#endif