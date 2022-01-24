// PlayGame.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectJEANMACK.h"
#include "PlayGame.h"
#include "afxdialogex.h"


// PlayGame 대화 상자

IMPLEMENT_DYNAMIC(PlayGame, CDialogEx)

PlayGame::PlayGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAMING, pParent)
{
}

PlayGame::~PlayGame()
{
}

void PlayGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PlayGame, CDialogEx)
END_MESSAGE_MAP()


// PlayGame 메시지 처리기