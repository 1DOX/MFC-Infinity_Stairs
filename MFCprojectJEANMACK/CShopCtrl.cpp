// CShopCtrl.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectJEANMACK.h"
#include "CShopCtrl.h"
#include "afxdialogex.h"
#include "MainFrm.h"


// CShopCtrl 대화 상자

IMPLEMENT_DYNAMIC(CShopCtrl, CDialogEx)

CShopCtrl::CShopCtrl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SHOP, pParent)
{

}

CShopCtrl::~CShopCtrl()
{
}

void CShopCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShopCtrl, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_TH1, &CShopCtrl::OnBnClickedButtonTh1)
	ON_BN_CLICKED(IDC_BUTTON_TH2, &CShopCtrl::OnBnClickedButtonTh2)
	ON_BN_CLICKED(IDC_BUTTON_TH3, &CShopCtrl::OnBnClickedButtonTh3)
END_MESSAGE_MAP()


// CShopCtrl 메시지 처리기





void CShopCtrl::OnBnClickedButtonTh1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("테마 선택 - 히말라야"));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->thema(1);
}


void CShopCtrl::OnBnClickedButtonTh2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("테마 선택 - 오로라"));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->thema(2);
}


void CShopCtrl::OnBnClickedButtonTh3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("테마 선택 - 스페이스"));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->thema(3);
}
