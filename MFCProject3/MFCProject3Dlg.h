
// MFCProject3Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMFCProject3Dlg ��ȭ ����
class CMFCProject3Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCProject3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	int m_PreX;
	int m_PreY;
	int m_iR;
	int m_iG;
	int m_iB;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int m_iPenSize;
	int m_iEditSize;
	int m_nDrawMode;
	CPoint m_ptStart;
	CPoint m_ptPrev;



	bool m_bFirst;
	bool m_bLButtonDown;
	bool m_bContextMenu;
	bool m_bHatch;

	int m_nCount;
	int draw_type;
	int draw_type2;
	int color_type;

	int xy[4000][16];
	int xy_idx;

	

	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnThin();
	afx_msg void OnMiddle();
	afx_msg void OnThick();
	afx_msg void Onreset();
	afx_msg void Onexit();
	afx_msg void OnLine();

	afx_msg void OnSElli();
	afx_msg void OnMElli();
	afx_msg void OnBElli();
	afx_msg void Onserase();
	afx_msg void Onmerase();
	afx_msg void Onberase();
	afx_msg void Onsrect();
	afx_msg void Onmrect();
	afx_msg void Onbrect();
	afx_msg void OnRElli();
	afx_msg void Onrrect();


	afx_msg void OnColorOrange();
	afx_msg void OnColorYellow();
	afx_msg void OnColorNavy();
	afx_msg void OnColorPurple();


	afx_msg void OnAttationLine();
	afx_msg void Onaerase();
};
