// WorkerThread2View.cpp : CWorkerThread2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWorkerThread2View ����/�Ҹ�

CWorkerThread2View::CWorkerThread2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWorkerThread2View::~CWorkerThread2View()
{
}

BOOL CWorkerThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWorkerThread2View �׸���

void CWorkerThread2View::OnDraw(CDC* /*pDC*/)
{
	CWorkerThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWorkerThread2View �μ�

BOOL CWorkerThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWorkerThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWorkerThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CWorkerThread2View ����

#ifdef _DEBUG
void CWorkerThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkerThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkerThread2Doc* CWorkerThread2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
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
	CPen WHITEpen(PS_SOLID, 2, RGB(255, 255, 255));   //���
	
	for (int i = 0; i < LOOPCNT; i++) //������ ũ�Ⱑ �ٲ𶧸��� �ٽ� �׸� �� �ֵ��� for-loop���� 
	{
		dc.Ellipse(pArg->pos.x - 20, pArg->pos.y - 20, pArg->pos.x + 20, pArg->pos.y + 20 );  //������ 2�� ��
	}
	
	Sleep(3000);  //3000ms => 3sec ��ٸ�����

	dc.SelectObject(&WHITEpen);
	dc.Ellipse(pArg->pos.x - 20, pArg->pos.y - 20, pArg->pos.x + 20, pArg->pos.y + 20);  //�׷ȴ� �� ��ġ�� ��� �� �׷��� �� �����

	pArg->EndThread();  /////������ ����

	return 0;
	

}  //�׷ȴ� ���� �������� �� ������ ����E



// CWorkerThread2View �޽��� ó����


void CWorkerThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CView::OnLButtonDown(nFlags, point);

	//ȭ�������
	CClientDC dc(this);                  
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);

	//���ʸ��콺��ư ������ ������ ����
	CirTimerThread *arg = new CirTimerThread(this, point);  //���� ������ ����
	arg->GenerateThread();

}


void CirTimerThread::GenerateThread()
{
	AfxBeginThread(MyDraw, this); //������ ���� ����. CWinThreadŸ�� ������ ��ü �ּҰ� ��ȯ
}

void CirTimerThread::EndThread()
{
	AfxEndThread(0, TRUE);  //������ ���� ���� �Լ�
}