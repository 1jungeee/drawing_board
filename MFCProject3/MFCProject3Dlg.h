
// MFCProject3Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMFCProject3Dlg 대화 상자
class CMFCProject3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCProject3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
