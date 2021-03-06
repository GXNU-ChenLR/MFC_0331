
// MFC_0331_2View.h : CMFC_0331_2View 类的接口
//

#pragma once


class CMFC_0331_2View : public CView
{
protected: // 仅从序列化创建
	CMFC_0331_2View();
	DECLARE_DYNCREATE(CMFC_0331_2View)

// 特性
public:
	CMFC_0331_2Doc* GetDocument() const;

// 操作
public:
	CRect cr;//矩形
	CString s;//保存输入的字符串
	CPoint insert;//记录鼠标点击的位置
	int min; //平均每个字符所占的像素宽度
	int num;//每一行输出的字符个数
	int row;//插入行的位置
	int column;//插入列的位置
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC_0331_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0331_2View.cpp 中的调试版本
inline CMFC_0331_2Doc* CMFC_0331_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0331_2Doc*>(m_pDocument); }
#endif

