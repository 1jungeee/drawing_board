
// MFCProject3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCProject3.h"
#include "MFCProject3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCProject3Dlg ��ȭ ����



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


// CMFCProject3Dlg �޽��� ó����

BOOL CMFCProject3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);		// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	draw_type = 1; // �޴� ����
	draw_type2 = 1; // �޴��ȿ� ���� �޴� ����

	color_type = 1; 

	m_iPenSize = 1;
	m_iEditSize = 1;
	xy_idx = 0;

	UpdateData(FALSE);

	m_iR = m_iG = m_iB = 0; // RGB
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCProject3Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.



		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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



	// ȭ�鿡 �����Ϸ��� ������ �� ���� ������ ���������� �Ҷ� �������� ���ܼ� ������ �ϼ����� ���� 
	/*
	if (draw_type == 1) { // ��
		for (int i = 0; i < xy_idx; i++)
		{
			dc.MoveTo(xy[i][0], xy[i][1]);
			dc.LineTo(xy[i][2], xy[i][3]);
		}
	}

	else if (draw_type == 2) { // �簢��
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
	else if (draw_type == 3) { //����
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

	else if (draw_type = 5) { // �ʱ�ȭ
		for (int i = 0; i < xy_idx; i++)
		{
			xy[i][0] = 0;
			xy[i][1] = 0;
			xy[i][2] = 0;
			xy[i][3] = 0;

			xy2[i][0] = 0; //�����簢���� x��
			xy2[i][1] = 0; //�����簢���� y��
			xy2[i][2] = 0; //�߰��簢���� x��
			xy2[i][3] = 0; //�߰��簢���� y��
			xy2[i][4] = 0; //ū�簢���� x��
			xy2[i][5] = 0; //ū�簢���� y��

			xy3[i][0] = 0; //���������� x��
			xy3[i][1] = 0; //���������� y��
			xy3[i][2] = 0; //�߰������� x��
			xy3[i][3] = 0; //�߰������� y��
			xy3[i][4] = 0; //ū������ x��
			xy3[i][5] = 0; //ū������ y��

			draw_type = 1;
		}
		//InvalidateRect(NULL, TRUE);
		//UpdateWindow();
	}*/
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCProject3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCProject3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (draw_type == 1) { // ��

		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {
			CClientDC dc(this); 

			CPen ColorPen(PS_SOLID, m_iPenSize, RGB(m_iR, m_iG, m_iB)); //�� ����
			dc.SelectObject(&ColorPen); // ���� ����
			dc.MoveTo(m_PreX, m_PreY);
			dc.LineTo(point.x, point.y); // ���� �׸���.

			m_PreX = point.x; m_PreY = point.y; //��ǥ�� m_PreX�� m_PreY�� ����.
		}

	}
	else if (draw_type == 2) { // �簢��

		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {
			CClientDC dc(this);

			CBrush Colorbrush(RGB(m_iR, m_iG, m_iB)); //���� ����
			CBrush *p_old_brush = dc.SelectObject(&Colorbrush);

			if (draw_type2 == 1) { // ���� �簢��

				dc.Rectangle(m_PreX - 5, m_PreY - 5, m_PreX + 5, m_PreY + 5);
				
			}
			else if (draw_type2 == 2) { // �߰� �簢��
				dc.Rectangle(m_PreX - 50, m_PreY - 50, m_PreX + 50, m_PreY + 50);
			
			}
			else if (draw_type2 == 3) { // ū �簢��
				dc.Rectangle(m_PreX - 100, m_PreY - 100, m_PreX + 100, m_PreY + 100);
				
			}
			else if (draw_type2 == 4) { // ���� �簢��
				int x1, y1, xsiz, ysiz;
				for (int i = 0; i < 1; i++) {
					x1 = rand() % 1000; // x��ǥ
					y1 = rand() % 1000; // y��ǥ
					xsiz = rand() % 100 + 50; // ���� ����
					ysiz = rand() % 100 + 50; // ���� ����
					dc.Rectangle(x1, y1, x1 + xsiz, y1 + ysiz);
				}
			}
		}
	}

	else if (draw_type == 3) { // ����
		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) { // ���콺 ���� ��ư Ŭ��
			CClientDC dc(this);
			CBrush Colorbrush(RGB(m_iR, m_iG, m_iB)); // ä��� �÷� 
			CBrush *p_old_brush = dc.SelectObject(&Colorbrush); 


			if (draw_type2 == 1) { // ���� ����
				dc.Ellipse(m_PreX - 5, m_PreY - 5, m_PreX + 5, m_PreY + 5);
			
			}
			else if (draw_type2 == 2) { // �߰� ����
				dc.Ellipse(m_PreX - 50, m_PreY - 50, m_PreX + 50, m_PreY + 50);
			
			}
			else if (draw_type2 == 3) { // ū ����
				dc.Ellipse(m_PreX - 100, m_PreY - 100, m_PreX + 100, m_PreY + 100);
			
			}
			else if (draw_type2 == 4) { // ���� ����
				int x1, y1, xsiz, ysiz;
				for (int i = 0; i < 1; i++) {
					x1 = rand() % 1000; //x��ǥ
					y1 = rand() % 1000; //y��ǥ
					xsiz = rand() % 100 + 50; // ���� ����
					ysiz = rand() % 100 + 50; // ���� ����
					dc.Ellipse(x1, y1, x1 + xsiz, y1 + ysiz);
				}
			}
		}
	}
	else if (draw_type = 4) { // ���߼�
		if ((nFlags && MK_LBUTTON) == MK_LBUTTON) {  // ���콺 ���� ��ư Ŭ��
			CClientDC dc(this); 

			CPen ColorPen(PS_SOLID, m_iPenSize, RGB(m_iR, m_iG, m_iB)); //���߼� �� ����
			dc.SelectObject(&ColorPen);
			dc.MoveTo(m_PreX, m_PreY);
			dc.LineTo(point.x, point.y); // ���� �׸���.

		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCProject3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_PreX = point.x;
	m_PreY = point.y;
	CDialogEx::OnLButtonDown(nFlags, point);


}


void CMFCProject3Dlg::OnColorBlack() //������ ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_iR = 0;
	m_iG = 0;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorRed() //������ ����
{

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	m_iR = 255;
	m_iG = 0;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorGreen() //�ʷϻ� ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_iR = 0;
	m_iG = 255;
	m_iB = 0;
}


void CMFCProject3Dlg::OnColorBlue() // �Ķ��� ����
{
	m_iR = 0;
	m_iG = 0;
	m_iB = 255;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnColorOrange() // ��Ȳ�� ����
{

	m_iR = 255;
	m_iG = 148;
	m_iB = 54;

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnColorYellow() // ����� ����
{
	m_iR = 255;
	m_iG = 255;
	m_iB = 36;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnColorNavy() // ���� ����
{
	m_iR = 0;
	m_iG = 0;
	m_iB = 128;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnColorPurple() // ����� ����
{
	m_iR = 95;
	m_iG = 0;
	m_iB = 255;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}



void CMFCProject3Dlg::OnThin() // ���� ��
{
	m_iPenSize = 1;
	m_iEditSize = 1;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnMiddle() // ���� ��
{
	m_iPenSize = 10;
	m_iEditSize = 10;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnThick() // �β��� ��
{
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onreset() //�ʱ�ȭ
{


	InvalidateRect(NULL, TRUE);
	UpdateWindow();

	draw_type = 1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onexit() // ����
{

	OnOK();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnLine() //��
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_iR = 0;
	m_iG = 0;
	m_iB = 0;
	draw_type = 1;
	m_iPenSize = 1;
	m_iEditSize = 1;

}


void CMFCProject3Dlg::OnAttationLine() // ���߼�
{
	draw_type = 4;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}



void CMFCProject3Dlg::OnSElli() // ���� ����
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::OnMElli() // �߰� ����
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 2;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.


}

void CMFCProject3Dlg::OnBElli() // ū ����
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 3;

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

void CMFCProject3Dlg::OnRElli() // ���� ����
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 3;
	draw_type2 = 4;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}



void CMFCProject3Dlg::Onserase() // ���� ���찳
{

	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 1;
	m_iEditSize = 1;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onmerase() // �߰� ���찳
{
	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 10;
	m_iEditSize = 10;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onberase() // ū ���찳
{
	draw_type = 1;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onaerase() // ���߼� ���찳
{
	draw_type = 4;
	m_iR = m_iG = m_iB = 240;
	m_iPenSize = 20;
	m_iEditSize = 20;
	UpdateData(FALSE);
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}



void CMFCProject3Dlg::Onsrect() //���� �簢��
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onmrect() // �߰� �簢��
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 2;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onbrect() // ū �簢��
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 3;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCProject3Dlg::Onrrect() // ���� �簢��
{
	m_iR = 255; m_iG = 255; m_iB = 255;
	draw_type = 2;
	draw_type2 = 4;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}







