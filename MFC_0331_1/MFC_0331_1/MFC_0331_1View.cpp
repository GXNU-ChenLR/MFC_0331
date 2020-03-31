
// MFC_0331_1View.cpp : CMFC_0331_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_0331_1.h"
#endif

#include "MFC_0331_1Doc.h"
#include "MFC_0331_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0331_1View

IMPLEMENT_DYNCREATE(CMFC_0331_1View, CView)

BEGIN_MESSAGE_MAP(CMFC_0331_1View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_0331_1View ����/����

CMFC_0331_1View::CMFC_0331_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_0331_1View::~CMFC_0331_1View()
{
}

BOOL CMFC_0331_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0331_1View ����

void CMFC_0331_1View::OnDraw(CDC* pDC)
{
	CMFC_0331_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr = pDoc->cr;
	CRect ct;
	GetClientRect(&ct);
	pDoc->x = ct.Width() / 2;
	pDoc->y = ct.Height() / 2;
	CClientDC dc(this);
	pDoc->cr.left = pDoc->x - 100;
	pDoc->cr.top = pDoc->y - 10;
	pDoc->cr.right = pDoc->x + 100;
	pDoc->cr.bottom = pDoc->y + 10;
	dc.Rectangle(pDoc->cr.left, pDoc->cr.top, pDoc->cr.right, pDoc->cr.bottom);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0331_1View ���

#ifdef _DEBUG
void CMFC_0331_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0331_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0331_1Doc* CMFC_0331_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0331_1Doc)));
	return (CMFC_0331_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0331_1View ��Ϣ�������


void CMFC_0331_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0331_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CString s,c;
	c.Format(_T("%c"), nChar);
	
	if ( p.x >= pDoc->cr.left && p.y >= pDoc->cr.top)
		s.Insert(p.x / 10 + p.y / 20 * 30, nChar);
	else
		s.Append(c);

		pDoc->cr.left = pDoc->x - 99;
		pDoc->cr.top = pDoc->y - 9;
		dc.DrawText(s, pDoc->cr, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC_0331_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p.x = point.x;
	p.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}
