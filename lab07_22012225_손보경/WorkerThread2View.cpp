// WorkerThread2View.cpp : CWorkerThread2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WorkerThread2.h"
#endif

#include "WorkerThread2Doc.h"
#include "WorkerThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkerThread2View

IMPLEMENT_DYNCREATE(CWorkerThread2View, CView)

BEGIN_MESSAGE_MAP(CWorkerThread2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWorkerThread2View 생성/소멸

CWorkerThread2View::CWorkerThread2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWorkerThread2View::~CWorkerThread2View()
{
}

BOOL CWorkerThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWorkerThread2View 그리기

void CWorkerThread2View::OnDraw(CDC* /*pDC*/)
{
	CWorkerThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWorkerThread2View 인쇄

BOOL CWorkerThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWorkerThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWorkerThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWorkerThread2View 진단

#ifdef _DEBUG
void CWorkerThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkerThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkerThread2Doc* CWorkerThread2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkerThread2Doc)));
	return (CWorkerThread2Doc*)m_pDocument;
}
#endif //_DEBUG


#define LOOPCNT (200000)
#define DIVCNT (LOOPCNT/500)


UINT MyDraw(LPVOID arg)
{
	CirTimerThread *pArg = (CirTimerThread*)arg;
	CClientDC dc(pArg->pWnd);
	CPen WHITEpen(PS_SOLID, 2, RGB(255, 255, 255));   //흰색
	
	for (int i = 0; i < LOOPCNT; i++) //윈도우 크기가 바뀔때마다 다시 그릴 수 있도록 for-loop으로 
	{
		dc.Ellipse(pArg->pos.x - 20, pArg->pos.y - 20, pArg->pos.x + 20, pArg->pos.y + 20 );  //반지름 2인 원
	}
	
	Sleep(3000);  //3000ms => 3sec 기다리도록

	dc.SelectObject(&WHITEpen);
	dc.Ellipse(pArg->pos.x - 20, pArg->pos.y - 20, pArg->pos.x + 20, pArg->pos.y + 20);  //그렸던 원 위치에 흰색 원 그려서 원 지우기

	pArg->EndThread();  /////스레드 종료

	return 0;
	

}  //그렸던 원이 지워지고난 후 스레드 종료E



// CWorkerThread2View 메시지 처리기


void CWorkerThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CView::OnLButtonDown(nFlags, point);

	//화면지우기
	CClientDC dc(this);                  
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);

	//왼쪽마우스버튼 누르면 스레드 생성
	CirTimerThread *arg = new CirTimerThread(this, point);  //동적 스레드 생성
	arg->GenerateThread();

}


void CirTimerThread::GenerateThread()
{
	AfxBeginThread(MyDraw, this); //스레드 동적 생성. CWinThread타입 스레드 객체 주소값 반환
}

void CirTimerThread::EndThread()
{
	AfxEndThread(0, TRUE);  //스레드 강제 종료 함수
}