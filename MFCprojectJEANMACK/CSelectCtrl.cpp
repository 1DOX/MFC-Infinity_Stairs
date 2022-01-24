// CSelectCtrl.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectJEANMACK.h"
#include "CSelectCtrl.h"
#include "afxdialogex.h"
#include "CGamingCtrl.h"


// CSelectCtrl 대화 상자

IMPLEMENT_DYNAMIC(CSelectCtrl, CDialogEx)

CSelectCtrl::CSelectCtrl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CHANGE, pParent)
{

}

CSelectCtrl::~CSelectCtrl()
{
}

void CSelectCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CSelectCtrl::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CSelectCtrl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSelectCtrl::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSelectCtrl 메시지 처리기


void CSelectCtrl::OnBnClickedButton3()//삼각김밥
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("선택 - 예술가 쿠키"));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->gamechar(3, 1);
}


void CSelectCtrl::OnBnClickedButton1()//기본 캐릭터 -
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("선택 - 쿠키 "));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();

	CFile file;
	CString str, coin;
	file.Open(_T("Coin.txt"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	while (ar.ReadString(str)) {
		AfxExtractSubString(coin, str, 1, '#');
	}
	int coins = _ttoi(coin);

	pGamingCtrl->gamechar(1, coins);
}


void CSelectCtrl::OnBnClickedButton2()//다스베이더 - 오윤석
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("선택 - 다스베이더 쿠키"));
	CGamingCtrl* pGamingCtrl = (CGamingCtrl*)AfxGetMainWnd();
	pGamingCtrl->gamechar(2, 1);
}
