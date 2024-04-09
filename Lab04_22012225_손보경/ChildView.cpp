
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "CDLab.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

POSITION pos;

CList<CPoint, CPoint&>list;  //list  전역변수로 설정

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	pos = list.GetHeadPosition(); //list의 맨 앞 위치 값 pos에 저장
	while (pos != NULL)
	{
		CPoint position = list.GetNext(pos);//포인터가 가리키는 값을 반환하고, 포인터는 다음 노드를 가리키도록한다.
		dc.Rectangle(position.x - 20, position.y - 20, position.x + 20, position.y + 20);  //윈도우 크기가 바뀔때마다 다시 그리게됨
	}

	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	
	//내가 찍은 위치값 리스트에 담기
	list.AddTail(point);
	
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnRButtonDown(nFlags, point);

	pos = list.GetHeadPosition(); //list의 첫 노드의 포인터를 반환
	
	CPoint p;
	p = list.GetAt(pos);  //pos가 가리키는 위치 반환


	while (pos != NULL)
	{
		if ((point.x - 20 < p.x) && (point.y - 20 < p.y) && (point.x + 20 > p.x) && (point.y + 20 > p.y))
		{//사각형 안에 마우스 클릭한 경우

			list.RemoveAt(pos); //해당 사각형 제거
			break;
		}
		list.GetNext(pos);  //pos가 가리키는 값 다음 노드를 가리키도록한다.
		p = list.GetAt(pos);  //현재 pos가  가리키는 위치로 p값 초기화

	}


	Invalidate();  //화면다시그리기
}
