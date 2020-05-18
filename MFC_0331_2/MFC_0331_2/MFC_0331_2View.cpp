
// MFC_0331_2View.cpp : CMFC_0331_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_0331_2.h"
#endif

#include "MFC_0331_2Doc.h"
#include "MFC_0331_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0331_2View

IMPLEMENT_DYNCREATE(CMFC_0331_2View, CView)

BEGIN_MESSAGE_MAP(CMFC_0331_2View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_0331_2View ����/����

CMFC_0331_2View::CMFC_0331_2View()
{
	// TODO: �ڴ˴���ӹ������
	s.Empty();//��ʼ���ַ���
	insert.x = 0;
	insert.y = 0;
}

CMFC_0331_2View::~CMFC_0331_2View()
{
}

BOOL CMFC_0331_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0331_2View ����

void CMFC_0331_2View::OnDraw(CDC* pDC)
{
	CMFC_0331_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect ct;
	this->GetClientRect(&ct);
	int r = 100;
	cr.left = ct.Width() / 2 - r;
	cr.right = ct.Width() / 2 + r;
	cr.top = ct.Height() / 2 - r;
	cr.bottom = ct.Height() / 2 + r;
	CClientDC dc(this);
	dc.Rectangle(cr.left, cr.top, cr.right, cr.bottom);
	cr.left = ct.Width() / 2 - r + 1;
	cr.right = ct.Width() / 2 + r - 1;
	cr.top = ct.Height() / 2 - r + 1;
	cr.bottom = ct.Height() / 2 + r - 1;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0331_2View ���

#ifdef _DEBUG
void CMFC_0331_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0331_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0331_2Doc* CMFC_0331_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0331_2Doc)));
	return (CMFC_0331_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0331_2View ��Ϣ�������


void CMFC_0331_2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	char c;
	c = (char)nChar;
	CClientDC dc(this);
	CSize ss = dc.GetTextExtent(s); 
	if (!s.IsEmpty())
	{
		min = ss.cx / s.GetLength();  //�ַ����Ŀ�/�ַ����ĳ���=ƽ��ÿ���ַ���ռ�����ؿ��
									  //int line = ss.cx / s.GetLength();//��ʾһ��Ҫ���������
		int num = 200 / min;//ÿһ��������ַ�����
		row = (insert.y - cr.top)/ss.cy;
		column = (insert.y - cr.top)/min;
		//�����ַ���λ��=(insert.x - cr.left) / ÿ���ַ���ռ����+(insert.y - cr.top) / ����*ÿ���ַ���

		if ( insert.x >= cr.left && insert.y >= cr.top && insert.x <= cr.right && insert.y <= cr.bottom)
		{
			//int m = (insert.x - cr.left) / min + (insert.y - cr.top) / line * 24;//�������λ�ò����ַ�
			s.Insert(row*num + column, c);
		}
		
	}
	else
		s.AppendChar(c);
	
	dc.DrawText(s,cr, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC_0331_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	insert.x = point.x;
	insert.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}
