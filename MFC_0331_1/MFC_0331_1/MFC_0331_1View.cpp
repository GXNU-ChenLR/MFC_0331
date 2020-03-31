
// MFC_0331_1View.cpp : CMFC_0331_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC_0331_1View 构造/析构

CMFC_0331_1View::CMFC_0331_1View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0331_1View::~CMFC_0331_1View()
{
}

BOOL CMFC_0331_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0331_1View 绘制

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
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0331_1View 诊断

#ifdef _DEBUG
void CMFC_0331_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0331_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0331_1Doc* CMFC_0331_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0331_1Doc)));
	return (CMFC_0331_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0331_1View 消息处理程序


void CMFC_0331_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p.x = point.x;
	p.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}
