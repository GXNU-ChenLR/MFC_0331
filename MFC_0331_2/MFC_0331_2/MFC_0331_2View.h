
// MFC_0331_2View.h : CMFC_0331_2View ��Ľӿ�
//

#pragma once


class CMFC_0331_2View : public CView
{
protected: // �������л�����
	CMFC_0331_2View();
	DECLARE_DYNCREATE(CMFC_0331_2View)

// ����
public:
	CMFC_0331_2Doc* GetDocument() const;

// ����
public:
	CRect cr;//����
	CString s;//����������ַ���
	CPoint insert;//��¼�������λ��
	int min; //ƽ��ÿ���ַ���ռ�����ؿ��
	int num;//ÿһ��������ַ�����
	int row;//�����е�λ��
	int column;//�����е�λ��
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC_0331_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0331_2View.cpp �еĵ��԰汾
inline CMFC_0331_2Doc* CMFC_0331_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0331_2Doc*>(m_pDocument); }
#endif

