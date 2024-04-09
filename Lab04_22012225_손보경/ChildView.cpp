
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "CDLab.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

POSITION pos;

CList<CPoint, CPoint&>list;  //list  ���������� ����

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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	pos = list.GetHeadPosition(); //list�� �� �� ��ġ �� pos�� ����
	while (pos != NULL)
	{
		CPoint position = list.GetNext(pos);//�����Ͱ� ����Ű�� ���� ��ȯ�ϰ�, �����ʹ� ���� ��带 ����Ű�����Ѵ�.
		dc.Rectangle(position.x - 20, position.y - 20, position.x + 20, position.y + 20);  //������ ũ�Ⱑ �ٲ𶧸��� �ٽ� �׸��Ե�
	}

	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	
	//���� ���� ��ġ�� ����Ʈ�� ���
	list.AddTail(point);
	
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnRButtonDown(nFlags, point);

	pos = list.GetHeadPosition(); //list�� ù ����� �����͸� ��ȯ
	
	CPoint p;
	p = list.GetAt(pos);  //pos�� ����Ű�� ��ġ ��ȯ


	while (pos != NULL)
	{
		if ((point.x - 20 < p.x) && (point.y - 20 < p.y) && (point.x + 20 > p.x) && (point.y + 20 > p.y))
		{//�簢�� �ȿ� ���콺 Ŭ���� ���

			list.RemoveAt(pos); //�ش� �簢�� ����
			break;
		}
		list.GetNext(pos);  //pos�� ����Ű�� �� ���� ��带 ����Ű�����Ѵ�.
		p = list.GetAt(pos);  //���� pos��  ����Ű�� ��ġ�� p�� �ʱ�ȭ

	}


	Invalidate();  //ȭ��ٽñ׸���
}
