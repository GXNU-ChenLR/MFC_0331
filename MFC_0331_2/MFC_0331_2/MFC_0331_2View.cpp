
// MFC_0331_2View.cpp : CMFC_0331_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC_0331_2View 构造/析构

CMFC_0331_2View::CMFC_0331_2View()
{
	// TODO: 在此处添加构造代码
	s.Empty();//初始化字符串
	insert.x = 0;
	insert.y = 0;
}

CMFC_0331_2View::~CMFC_0331_2View()
{
}

BOOL CMFC_0331_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0331_2View 绘制

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
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0331_2View 诊断

#ifdef _DEBUG
void CMFC_0331_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0331_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0331_2Doc* CMFC_0331_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0331_2Doc)));
	return (CMFC_0331_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0331_2View 消息处理程序


void CMFC_0331_2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char c;
	c = (char)nChar;
	CClientDC dc(this);
	CSize ss = dc.GetTextExtent(s); 
	if (!s.IsEmpty())
	{
		min = ss.cx / s.GetLength();  //字符串的宽/字符串的长度=平均每个字符所占的像素宽度
									  //int line = ss.cx / s.GetLength();//表示一共要输出多少行
		int num = 200 / min;//每一行输出的字符个数
		row = (insert.y - cr.top)/ss.cy;
		column = (insert.y - cr.top)/min;
		//插入字符的位置=(insert.x - cr.left) / 每个字符所占像素+(insert.y - cr.top) / 行数*每行字符数

		if ( insert.x >= cr.left && insert.y >= cr.top && insert.x <= cr.right && insert.y <= cr.bottom)
		{
			//int m = (insert.x - cr.left) / min + (insert.y - cr.top) / line * 24;//在鼠标点击位置插入字符
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	insert.x = point.x;
	insert.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}
