
// MFCProject3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCProject3.h"
#include "MFCProject3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCProject3Dlg 대화 상자



CMFCProject3Dlg::CMFCProject3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCPROJECT3_DIALOG, pParent)
	, m_iEditSize(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProject3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CMFCProject3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_HSCROLL()


	ON_COMMAND(ID_COLOR_BLACK, &CMFCProject3Dlg::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CMFCProject3Dlg::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMFCProject3Dlg::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMFCProject3Dlg::OnColorBlue)
	ON_COMMAND(ID_COLOR_ORANGE, &CMFCProject3Dlg::OnColorOrange)
	ON_COMMAND(ID_COLOR_YELLOW, &CMFCProject3Dlg::OnColorYellow)
	ON_COMMAND(ID_COLOR_NAVY, &CMFCProject3Dlg::OnColorNavy)
	ON_COMMAND(ID_COLOR_PURPLE, &CMFCProject3Dlg::OnColorPurple)

	ON_COMMAND(ID_THIN, &CMFCProject3Dlg::OnThin)
	ON_COMMAND(ID_MIDDLE, &CMFCProject3Dlg::OnMiddle)
	ON_COMMAND(ID_THICK, &CMFCProject3Dlg::OnThick)

	ON_COMMAND(ID_reset, &CMFCProject3Dlg::Onreset)
	ON_COMMAND(ID_exit, &CMFCProject3Dlg::Onexit)

	ON_COMMAND(ID_LINE, &CMFCProject3Dlg::OnLine)
	ON_COMMAND(ID_ATTATION_LINE, &CMFCProject3Dlg::OnAttationLine)
	ON_COMMAND(ID_S_ELLI, &CMFCProject3Dlg::OnSElli)
	ON_COMMAND(ID_M_ELLI, &CMFCProject3Dlg::OnMElli)
	ON_COMMAND(ID_B_ELLI, &CMFCProject3Dlg::OnBElli)
	ON_COMMAND(ID_s_erase, &CMFCProject3Dlg::Onserase)
	ON_COMMAND(ID_m_erase, &CMFCProject3Dlg::Onmerase)
	ON_COMMAND(ID_b_erase, &CMFCProject3Dlg::Onberase)
	ON_COMMAND(ID_a_erase, &CMFCProject3Dlg::Onaerase)
	ON_COMMAND(ID_s_rect, &CMFCProject3Dlg::Onsrect)
	ON_COMMAND(ID_m_rect, &CMFCProject3Dlg::Onmrect)
	ON_COMMAND(ID_b_rect, &CMFCProject3Dlg::Onbrect)
	ON_COMMAND(ID_R_ELLI, &CMFCProject3Dlg::OnRElli)
	ON_COMMAND(ID_r_rect, &CMFCProject3Dlg::Onrrect)


END_MESSAGE_MAP()


// CMFCProject3Dlg 메시지 처리기

BOOL CMFCProject3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);		// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	draw_type = 1; // 메뉴 지정
	draw_type2 = 1; // 메뉴안에 작은 메뉴 지정

	color_type = 1; 

	m_iPenSize = 1;
	m_iEditSize = 1;
	xy_idx = 0;

	UpdateData(FALSE);

	m_iR = m_iG = m_iB = 0; // RGB
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCProject3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCProject3Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.



		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		dc.SelectStockObject(WHITE_BRUSH);
		CRect rect;
		//GetClientRect(&rect);
		dc.Rectangle(&rect);

		CDialogEx::OnPaint();
	}
	CClientDC dc(this);



	// 화면에 저장하려고 했으나 펜 색깔 도형등 복합적으로 할때 오류들이 생겨서 저장은 완성하지 못함 
	/*
	if (draw_type == 1) { // 펜
		for (int i = 0; i < xy_idx; i++)
		{
			dc.MoveTo(xy[i][0], xy[i][1]);
			dc.LineTo(xy[i][2], xy[i][3]);
		}
	}

	else if (draw_type == 2) { // 사각형
		if (draw_type2 == 1) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Rectangle(xy2[i][0] - 5, xy2[i][1] - 5, xy2[i][0] + 5, xy2[i][1] + 5);
			}
		}
		else if (draw_type2 == 2) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Rectangle(xy2[i][2] - 50, xy2[i][3] - 50, xy2[i][2] + 50, xy2[i][3] + 50);
			}
		}
		else if (draw_type2 == 3) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Rectangle(xy2[i][4] - 100, xy2[i][5] - 100, xy2[i][4] + 100, xy2[i][5] + 100);
			}
		}
	}
	else if (draw_type == 3) { //원형
		if (draw_type2 == 1) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Ellipse(xy3[i][0] - 5, xy3[i][1] - 5, xy3[i][0] + 5, xy3[i][1] + 5);
			}
		}
		else if (draw_type2 == 2) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Ellipse(xy3[i][2] - 50, xy3[i][3] - 50, xy3[i][2] + 50, xy3[i][3] + 50);
			}
		}
		else if (draw_type2 == 3) {
			for (int i = 0; i < xy_idx; i++)
			{
				dc.Ellipse(xy3[i][4] - 100, xy3[i][5] - 100, xy3[i][4] + 100, xy3[i][5] + 100);
			}
		}
	}

	else if (draw_type = 5) { // 초기화
		for (int i = 0; i < xy_idx; i++)
		{
			xy[i][0] = 0;
			xy[i][1] = 0;
			xy[i][2] = 0;
			xy[i][3] = 0;

			xy2[i][0] = 0; //작은사각형의 x값
			xy2[i][1] = 0; //작은사각형의 y값
			xy2[i][2] = 0; //중간사각형의 x값
			xy2[i][3] = 0; //중간사각형의 y값
			xy2[i][4] = 0; //큰사각형의 x값
			xy2[i][5] = 0; //큰사각형의 y값

			xy3[i][0] = 0; //작은원형의 x값
			xy3[i][1] = 0; //작은원형의 y값
			xy3[i][2] = 0; //중간원형의 x값
			xy3[i][3] = 0; //중간원형의 y값
			xy3[i][4] = 0; //큰원형의 x값
			xy3[i][5] = 0; //큰원형의 y값

			draw_type = 1;
		}
		//InvalidateRect(NULL, TRUE);
		//UpdateWindow();
	}*/
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCProject3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCProject3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{


	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (draw_type == 1) { // 펜

		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {
			CClientDC dc(this); 

			CPen ColorPen(PS_SOLID, m_iPenSize, RGB(m_iR, m_iG, m_iB)); //펜 생성
			dc.SelectObject(&ColorPen); // 펜을 선택
			dc.MoveTo(m_PreX, m_PreY);
			dc.LineTo(point.x, point.y); // 선을 그린다.

			m_PreX = point.x; m_PreY = point.y; //좌표를 m_PreX와 m_PreY에 저장.
		}

	}
	else if (draw_type == 2) { // 사각형

		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {
			CClientDC dc(this);

			CBrush Colorbrush(RGB(m_iR, m_iG, m_iB)); //색깔 지정
			CBrush *p_old_brush = dc.SelectObject(&Colorbrush);

			if (draw_type2 == 1) { // 작은 사각형

				dc.Rectangle(m_PreX - 5, m_PreY - 5, m_PreX + 5, m_PreY + 5);
				
			}
			else if (draw_type2 == 2) { // 중간 사각형
				dc.Rectangle(m_PreX - 50, m_PreY - 50, m_PreX + 50, m_PreY + 50);
			
			}
			else if (draw_type2 == 3) { // 큰 사각형
				dc.Rectangle(m_PreX - 100, m_PreY - 100, m_PreX + 100, m_PreY + 100);
				
			}
			else if (draw_type2 == 4) { // 랜덤 사각형
				int x1, y1, xsiz, ysiz;
				for (int i = 0; i < 1; i++) {
					x1 = rand() % 1000; // x좌표
					y1 = rand() % 1000; // y좌표
					xsiz = rand() % 100 + 50; // 가로 길이
					ysiz = rand() % 100 + 50; // 세로 길이
					dc.Rectangle(x1, y1, x1 + xsiz, y1 + ysiz);
				}
			}
		}
	}

	else if (draw_type == 3) { // 원형
		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) { // 마우스 왼쪽 버튼 클릭
			CClientDC dc(this);
			CBrush Colorbrush(RGB(m_iR, m_iG, m_iB)); // 채우기 컬러 
			CBrush *p_old_brush = dc.SelectObject(&Colorbrush); 


			if (draw_type2 == 1) { // 작은 원형
				dc.Ellipse(m_PreX - 5, m_PreY - 5, m_PreX + 5, m_PreY + 5);
			
			}
			else if (draw_type2 == 2) { // 중간 원형
				dc.Ellipse(m_PreX - 50, m_PreY - 50, m_PreX + 50, m_PreY + 50);
			
			}
			else if (draw_type2 == 3) { // 큰 원형
				dc.Ellipse(m_PreX - 100, m_PreY - 100, m_PreX + 100, m_PreY + 100);
			
			}
			else if (draw_type2 == 4) { // 랜덤 원형
				int x1, y1, xsiz, ysiz;
				for (int i = 0; i < 1; i++) {
					x1 = rand() % 1000; //x좌표
					y1 = rand() % 1000; //y좌표
					xsiz = rand() % 100 + 50; // 가로 길이
					ysiz = rand() % 100 + 50; // 세로 길이
					dc.Ellipse(x1, y1, x1 + xsiz, y1 + ysiz);
				}
			}
		}
	}
	else if (draw_type = 4) { // 집중선
		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {  // 마우스 왼쪽 버튼 클릭
			CClientDC dc(this); 

			CPen ColorPen(PS_SOLID, m_iPenSize, RGB(m_iR, m_iG, m_iB)); //집중선 펜 생성
			dc.SelectObject(&ColorPen);
			dc.MoveTo(m_PreX, m_PreY);
			dc.LineTo(point.x, point.y); // 선을 그린다.

		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCProject3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_PreX = point.x;
	m_PreY = point.y;
	CDialogEx::OnLButtonDown(nFlags, point);


}


void CMFCProject3Dlg::OnColorBlack() //검은색 설정
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iR = 0;
	m_iG = 0;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorRed() //빨간색 설정
{

	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_iR = 255;
	m_iG = 0;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorGreen() //초록색 설정
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iR = 0;
	m_iG = 255;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorBlue() // 파란색 설정
{
	m_iR = 0;
	m_iG = 0;
	m_iB = 255;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnColorOrange() // 주황색 설정
{

	m_iR = 255;
	m_iG = 148;
	m_iB = 54;

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnColorYellow() // 노란색 설정
{
	m_iR = 255;
	m_iG = 255;
	m_iB = 36;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnColorNavy() // 남색 설정
{
	m_iR = 0;
	m_iG = 0;
	m_iB = 128;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnColorPurple() // 보라색 설정
{
	m_iR = 95;
	m_iG = 0;
	m_iB = 255;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CMFCProject3Dlg::OnThin() // 얇은 선
{
	m_iPenSize = 1;
	m_iEditSize = 1;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnMiddle() // 보통 선
{
	m_iPenSize = 10;
	m_iEditSize = 10;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnThick() // 두꺼운 선
{
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onreset() //초기화
{


	InvalidateRect(NULL, TRUE);
	UpdateWindow();

	draw_type = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onexit() // 종료
{

	OnOK();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnLine() //펜
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iR = 0;
	m_iG = 0;
	m_iB = 0;
	draw_type = 1;
	m_iPenSize = 1;
	m_iEditSize = 1;

}


void CMFCProject3Dlg::OnAttationLine() // 집중선
{
	draw_type = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CMFCProject3Dlg::OnSElli() // 작은 원형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::OnMElli() // 중간 원형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 2;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


}

void CMFCProject3Dlg::OnBElli() // 큰 원형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 3;

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CMFCProject3Dlg::OnRElli() // 랜덤 원형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CMFCProject3Dlg::Onserase() // 작은 지우개
{

	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 1;
	m_iEditSize = 1;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onmerase() // 중간 지우개
{
	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 10;
	m_iEditSize = 10;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onberase() // 큰 지우개
{
	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onaerase() // 집중선 지우개
{
	draw_type = 4;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CMFCProject3Dlg::Onsrect() //작은 사각형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onmrect() // 중간 사각형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 2;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onbrect() // 큰 사각형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 3;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCProject3Dlg::Onrrect() // 랜덤 사각형
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 4;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}







