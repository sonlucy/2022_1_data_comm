// WorkerThread2View.h : CWorkerThread2View 클래스의 인터페이스
//

#pragma once

struct CirTimerThread
{
	CWnd *pWnd;
	CPoint pos;

	CirTimerThread::CirTimerThread() {}  //기본생성자
	CirTimerThread::CirTimerThread(CWnd *pCWnd, CPoint Cpos) { pWnd = pCWnd; pos = Cpos; }

	void GenerateThread();  //스레드 생성 
	void EndThread();  //스레드 종료
};

class CWorkerThread2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CWorkerThread2View();
	DECLARE_DYNCREATE(CWorkerThread2View)

	// 특성입니다.
public:
	CWorkerThread2Doc* GetDocument() const;
	CirTimerThread arg, pArg;// *pThread1, *pThread2;
	CArray<CPoint, CPoint> cArray;

	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 구현입니다.
public:
	virtual ~CWorkerThread2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WorkerThread2View.cpp의 디버그 버전
inline CWorkerThread2Doc* CWorkerThread2View::GetDocument() const
{
	return reinterpret_cast<CWorkerThread2Doc*>(m_pDocument);
}
#endif