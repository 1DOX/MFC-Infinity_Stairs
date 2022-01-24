// CFirstCtrl.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectJEANMACK.h"
#include "CFirstCtrl.h"
#include "afxdialogex.h"
#include "MainFrm.h"



// CFirstCtrl 대화 상자

IMPLEMENT_DYNAMIC(CFirstCtrl, CDialogEx)

CFirstCtrl::CFirstCtrl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FIRST, pParent)
{

}

CFirstCtrl::~CFirstCtrl()
{
}

void CFirstCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_Btn_start);
	DDX_Control(pDX, IDC_BUTTON3, m_Btn_change);
	DDX_Control(pDX, IDC_BUTTON1, m_Btn_shop);
}


BEGIN_MESSAGE_MAP(CFirstCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFirstCtrl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFirstCtrl::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFirstCtrl::OnBnClickedButton3)
	ON_WM_PAINT()
	//ON_BN_CLICKED(IDC_BUTTON4, &CFirstCtrl::OnBnClickedButton4)
END_MESSAGE_MAP()


// CFirstCtrl 메시지 처리기


void CFirstCtrl::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->OnBnClickedButton1();
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->fileRead();
	pGamingCtrl->viewdraw();
}


BOOL CFirstCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFirstCtrl::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->OnBnClickedButton2();
}


void CFirstCtrl::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->OnBnClickedButton3();

}


void CFirstCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;

	CBitmap bmp1;

	CRect rct;
	this->GetClientRect(&rct);


	// Then load the bitmap to the memory.
	//DC에 대해 메모리 DC를 만들어 줌
	MemDC.CreateCompatibleDC(&dc);

	//비트맵 로드
	bmp1.LoadBitmap(IDB_BACKG);


	//메모리 DC에 저장
	MemDC.SelectObject(&bmp1);
	//메모리 DC 비트맵을 화면 DC로 복사 및 출력
	dc.BitBlt(0, 0, rct.Width(), rct.Height(), &MemDC, 0, 0, SRCCOPY);
}


/*void CFirstCtrl::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->OnBnClickedButton4();
}*/