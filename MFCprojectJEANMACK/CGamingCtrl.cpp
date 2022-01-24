// CGamingCtrl.cpp: 구현 파일
//

#include "pch.h"
#include "MFCprojectJEANMACK.h"
#include "CGamingCtrl.h"
#include "afxdialogex.h"
#include "PlayGame.h"
#include "MFCprojectJEANMACKView.h"
#include "locale.h"
#include "MainFrm.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm")

#define CHAR_D 1
#define CHAR_U 2
#define CHAR_X 3


// CGamingCtrl 대화 상자

IMPLEMENT_DYNAMIC(CGamingCtrl, CDialogEx)

CGamingCtrl::CGamingCtrl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAMING, pParent)
{
	
}

CGamingCtrl::~CGamingCtrl()
{
}

void CGamingCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_CHAR_PIC, m_character);
}


BEGIN_MESSAGE_MAP(CGamingCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_PLAY, &CGamingCtrl::OnBnClickedPlay)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGamingCtrl 메시지 처리기


void CGamingCtrl::OnBnClickedPlay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	fileRead();
	viewdraw();
	if (GameCount == 0) {
		SetWindowTheme(m_progress.m_hWnd, _T(""), _T(""));
		m_progress.SendMessage(PBM_SETBARCOLOR, 0, RGB(255, 50, 50));
		m_progress.SendMessage(PBM_SETBKCOLOR, 0, RGB(70, 70, 70));
		m_progress.SetRange(0, 30);
		bmp_stair.Load(L"stair1.bmp");
		bmp_coin.Load(L"coin2.png");
		bmp_count3.Load(L"count3.png");
		bmp_count2.Load(L"count2.png");
		bmp_count1.Load(L"count1.png");
		if (game_char == 1) {
			bmp_d.LoadBitmapW(IDB_1D);
			bmp_u.LoadBitmapW(IDB_1U);
			bmp_dr.LoadBitmapW(IDB_1D_R);
			bmp_ur.LoadBitmapW(IDB_1U_R);
			bmp_x.LoadBitmapW(IDB_1X);
			bmp_xr.LoadBitmapW(IDB_1X_R);
		}
		else if (game_char == 2) {
			bmp_d.LoadBitmapW(IDB_2D);
			bmp_u.LoadBitmapW(IDB_2U);
			bmp_dr.LoadBitmapW(IDB_2D_R);
			bmp_ur.LoadBitmapW(IDB_2U_R);
			bmp_x.LoadBitmapW(IDB_2X);
			bmp_xr.LoadBitmapW(IDB_2X_R);
		}
		else {
			bmp_d.LoadBitmapW(IDB_3D);
			bmp_u.LoadBitmapW(IDB_3U);
			bmp_dr.LoadBitmapW(IDB_3D_R);
			bmp_ur.LoadBitmapW(IDB_3U_R);
			bmp_x.LoadBitmapW(IDB_3X);
			bmp_xr.LoadBitmapW(IDB_3X_R);
		}
	}
	m_progress.SetPos(30);
	count = 0;

	for (int i = 0; i < 30; i++) {
		changeDIR[i] = false; //초기화
		stairDIR_Left[i] = true; //초기화
		CoinSpawn[i] = false;
	}
	isleft = true;
	stair_index = 0;
	score = 0;
	coin = 0;

	GameCount += 1;
	GameInit();
}

void CGamingCtrl::GameInit()
{
	// TODO: 여기에 구현 코드 추가.
	is_game_ing = false;
	isDie = false;
	//GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	SetTimer(1, 50, NULL);
	CClientDC dc(this);
	// stair : x50 * y25 pixel
	CRect rc;
	GetClientRect(&rc);
	posX[0] = rc.right/2;
	posY[0] = 325;
	posX[1] = posX[0] - 50;
	posY[1] = 300;
	srand(time(NULL));
	for (int i = 2; i < 30; i++) {
		if ((rand() % 9) > 4) { //방향이 변경될 확률이라면
			changeDIR[i - 1] = true; //i 인덱스는 방향이 변경되는 계단
			if (stairDIR_Left[i - 1] == true) //이전 계단이 왼쪽 방향이라면
				stairDIR_Left[i] = false;
			//방향이 변경되었으므로 오른쪽을 가리킨다.
			else stairDIR_Left[i] = true;
		}
		else {
			changeDIR[i - 1] = false;
			stairDIR_Left[i] = stairDIR_Left[i - 1];
		}
		if (stairDIR_Left[i]) //현재 방향이 왼쪽이라면
			posX[i] = posX[i - 1] - dirLX;
		else //현재 방향이 오른쪽이라면
			posX[i] = posX[i - 1] - dirRX;
		posY[i] = posY[i - 1] - dirY;
	}
	//캐릭터 정보
	
	SpawnCoin();

	bmp_count3.Draw(dc, 0, 60);
	Sleep(1000);
	bmp_count2.Draw(dc, 0, 60);
	Sleep(1000);
	bmp_count1.Draw(dc, 0, 60);
	Sleep(1000);

	is_game_ing = true; //게임의 상태 = 진행중
	Invalidate();
}

void CGamingCtrl::OnPaint()
{

	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.


	   //배경 설정
	CDC MemDC;

	CBitmap bmp1, bmp2, bmp3, bmp4, bmp5; //bmp6, bmp7, bmp8, bmp9, bmp10, bmp11, bmp12, bmp13, bmp14, bmp15;

	CRect rct;
	this->GetClientRect(&rct);


	// Then load the bitmap to the memory.
	//DC에 대해 메모리 DC를 만들어 줌
	MemDC.CreateCompatibleDC(&dc);

	//비트맵 로드

	//Theme1
	bmp1.LoadBitmap(IDB_BG1_1);
	bmp2.LoadBitmap(IDB_BG1_2);
	bmp3.LoadBitmap(IDB_BG1_3);
	bmp4.LoadBitmap(IDB_BG1_4);
	bmp5.LoadBitmap(IDB_BG1_5);

	////theme2
	//bmp6.LoadBitmap(IDB_BITMAP15);
	//bmp7.LoadBitmap(IDB_BITMAP16);
	//bmp8.LoadBitmap(IDB_BITMAP17);
	//bmp9.LoadBitmap(IDB_BITMAP18);
	//bmp10.LoadBitmap(IDB_BITMAP19);

	////theme3
	//bmp11.LoadBitmap(IDB_BITMAP20);
	//bmp12.LoadBitmap(IDB_BITMAP21);
	//bmp13.LoadBitmap(IDB_BITMAP22);
	//bmp14.LoadBitmap(IDB_BITMAP23);
	//bmp15.LoadBitmap(IDB_BITMAP24);


		//메모리 DC에 저장
		MemDC.SelectObject(&bmp1);

		//메모리 DC 비트맵을 화면 DC로 복사 및 출력
		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);

		ScoreInit(score); //테마 변경 되기 전 Y값 초기화

		if (score >= 100 && score < 200) {
			MemDC.SelectObject(&bmp2);
			dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
		}

		else if (score >= 200 && score < 300) {
			MemDC.SelectObject(&bmp3);
			dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
		}

		else if (score >= 300 && score < 400) {
			MemDC.SelectObject(&bmp4);
			dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
		}

		else if (score >= 400) {
			MemDC.SelectObject(&bmp5);
			dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
		}


	//else if (CChoice == 2) {
	//	//메모리 DC에 저장
	//	MemDC.SelectObject(&bmp6);

	//	//메모리 DC 비트맵을 화면 DC로 복사 및 출력
	//	dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);

	//	ScoreInit(score); //테마 변경 되기 전 Y값 초기화

	//	if (score >= 100 && score < 200) {
	//		MemDC.SelectObject(&bmp7);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 200 && score < 300) {
	//		MemDC.SelectObject(&bmp8);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 300 && score < 400) {
	//		MemDC.SelectObject(&bmp9);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 400) {
	//		MemDC.SelectObject(&bmp10);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}
	//}

	//else if (CChoice == 3) {
	//	//메모리 DC에 저장
	//	MemDC.SelectObject(&bmp11);

	//	//메모리 DC 비트맵을 화면 DC로 복사 및 출력
	//	dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);

	//	ScoreInit(score); //테마 변경 되기 전 Y값 초기화

	//	if (score >= 100 && score < 200) {
	//		MemDC.SelectObject(&bmp12);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 200 && score < 300) {
	//		MemDC.SelectObject(&bmp13);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 300 && score < 400) {
	//		MemDC.SelectObject(&bmp14);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}

	//	else if (score >= 400) {
	//		MemDC.SelectObject(&bmp15);
	//		dc.BitBlt(0, -500, rct.Width(), rct.Height() + 500, &MemDC, 0, BgVerticalCtrl, SRCCOPY);
	//	}
	// }


	if (is_game_ing) { //게임이 진행중인 경우
		for (int i = 0; i < 30; i++) {
			if (CoinSpawn[i])
				bmp_coin.Draw(dc, coinposX[i], coinposY[i]);
			bmp_stair.Draw(dc, posX[i], posY[i]);
		}

		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		CRect rc;
		GetClientRect(&rc);

		CString scoreS;
		scoreS.Format(_T("[ %d ]"), score);
		dc.TextOut(rc.right/2, 60, scoreS);

		if (isDie) {
			SelectChar(CHAR_X);
			is_game_ing = false;
		}
		else if (!isCharChange)
			SelectChar(CHAR_D);
		else
			SelectChar(CHAR_U);
		memDC.SelectObject(pOldBmp);
	}
}


void CGamingCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (score > 0) gauge = 1.0f;
	else if (score > 30) gauge = 1.3f;
	else if (score > 50) gauge = 1.5f;
	else if (score > 80) gauge = 1.8f;
	else if (score > 100) gauge = 2.0f;
	else if (score > 150) gauge = 2.5f;
	else if (score > 200) gauge = 3.0f;
	else if (score > 300) gauge = 5.0f;

	if ((m_progress.GetPos()) < 1 && is_game_ing == true) {
		GameOver();
	}
	else m_progress.OffsetPos(-gauge);
}


void CGamingCtrl::SpawnStair(int index)
//매개변수 index = 새로 스폰할 계단(y가 일정 범위를 벗어난 계단)의 index
{
	//계단이 움직인 후 y가 일정 범위를 벗어나면 계단을 새로 생성해주는 함수
	// TODO: 여기에 구현 코드 추가.
	int beforePosX = posX[index == 0 ? 29 : index - 1];
	int beforePosY = posY[index == 0 ? 29 : index - 1];

	if ((rand() % 9) > 4) { //방향이 변경될 확률이라면
		changeDIR[index == 0 ? 29 : index - 1] = true;
		stairDIR_Left[index] = !stairDIR_Left[index == 0 ? 29 : index - 1];
	}
	else {
		changeDIR[index == 0 ? 29 : index - 1] = false;
		stairDIR_Left[index] = stairDIR_Left[index == 0 ? 29 : index - 1];
	}
	if (stairDIR_Left[index]) posX[index] = beforePosX - dirLX;
	else posX[index] = beforePosX - dirRX;
	posY[index] = beforePosY - dirY;

	coinposX[index] = posX[index] + 12;
	coinposY[index] = posY[index] - 25;
	if ((rand() % 12) < 4)
		CoinSpawn[index] = true;

}

void CGamingCtrl::MoveStairs(int index, bool p_isChange, bool s_isLeft)
//매개변수 index = 현재 플레이어가 밟고 있는 계단의 시스템적 실제 인덱스
{
	BgVerticalCtrl = BgVerticalCtrl - 4; //배경 Y축으로 -4씩 이동
	//플레이어가 올라가는 경우 계단의 위치를 아래로 내려주는 함수
	// TODO: 여기에 구현 코드 추가.
	for (int i = 0; i < 30; i++) {
		if (s_isLeft) { //왼쪽 방향으로 올라갔다면
			posX[i] += dirLX;
			coinposX[i] += dirLX;
		}
		else {
			posX[i] += dirRX;
			coinposX[i] += dirRX;
		}
		posY[i] += dirY;
		coinposY[i] += dirY;
	}

	CRect rc;
	GetClientRect(&rc);
	for (int i = 0; i < 30; i++) {
		if ((rc.bottom) < posY[i]) {
			SpawnStair(i);
		}
		//해당 계단의 y좌표가 창 크기를 벗어났다면
		if (coinposY[i] == 300) {
			if (CoinSpawn[i] == true) {
				coin++;
				PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_COINSOUND),
					NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC);
			}
			CoinSpawn[i] = false;
		}
	}
	if (changeDIR[index] != p_isChange) { //방향전환을 할 계단인데, 플레이어가 '오르기'한 경우
		GameOver();
		return;
	}
	else {
		m_progress.OffsetPos(10.0);
		score++;
	}
	Invalidate(); //창 초기화
	//배경(background) 바꾸는 거 넣기
}

void CGamingCtrl::GameOver()
{
	// TODO: 여기에 구현 코드 추가.
	KillTimer(1);
	isDie = true;
	Invalidate();
	PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_DIESOUND),
		NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC);
	CString cr;
	cr.Format(_T("GAME OVER!\n현재 점수는 [ %d ] 점 입니다.\n획득 코인: %d"), score, coin);

	Wait(2000);
	AfxMessageBox(cr);

	changeValue();
	viewdraw();
}

BOOL CGamingCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if ((pMsg->message == WM_KEYDOWN) && (is_game_ing == true)) {
		CClientDC dc(this);
		// stair : x50 * y25 pixel
		bool p_isChange;
		if (pMsg->wParam == VK_SHIFT) { //방향전환
			p_isChange = true;
			isleft = !isleft;
			MoveStairs(stair_index, p_isChange, isleft);
			if ((++stair_index) == 30) stair_index = 0;
			isCharChange = true;
			return TRUE;
		}
		else if (pMsg->wParam == VK_UP) { //오르기
			p_isChange = false;
			MoveStairs(stair_index, p_isChange, isleft);
			if ((++stair_index) == 30) stair_index = 0;
			isCharChange = true;
			return TRUE;
		}
		Invalidate();
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

int CGamingCtrl::SelectChar(int type)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	BITMAP bitInfo;
	CRect rc;
	GetClientRect(&rc);
	pOldBmp = (CBitmap*)memDC.SelectObject(&bitInfo);
	COLORREF colorkey = RGB(36, 0, 159); // 투명색 지정 (컬러키 지정)

	switch (type) {
	case CHAR_D:
		if (isleft) {
			bmp_d.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_d);
		}
		else {
			bmp_dr.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_dr);
		}
		break;
	case CHAR_U:
		if (isleft) {
			bmp_u.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_u);
		}
		else {
			bmp_ur.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_ur);
		}
		isCharChange = false;
		break;
	case CHAR_X:
		if (isleft) {
			bmp_x.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_x);
		}
		else {
			bmp_xr.GetBitmap(&bitInfo);
			pOldBmp = memDC.SelectObject(&bmp_xr);
		}
		isCharChange = false;
		break;
	}
	::TransparentBlt(dc.m_hDC, rc.right/2, 260, bitInfo.bmWidth, bitInfo.bmHeight,
		memDC.m_hDC, 0, 0, bitInfo.bmWidth, bitInfo.bmHeight, colorkey);
	if (type == CHAR_U) {
		Wait(50);
		Invalidate();
	}
	return 0;
}

void CGamingCtrl::SpawnCoin()
{
	// TODO: 여기에 구현 코드 추가.
	for (int i = 10; i < 30; i++) {
		//코인이 생성될 확률 - 계단보다 일정간격 y위에 배치
		coinposX[i] = posX[i] + 12;
		coinposY[i] = posY[i] - 25;
		if ((rand() % 16) < 4)
			CoinSpawn[i] = true;
	}
	Invalidate();
}

void CGamingCtrl::Wait(DWORD dwMillisecond)
{
	MSG msg;
	DWORD dwStart;
	dwStart = GetTickCount();

	while (GetTickCount() - dwStart < dwMillisecond)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}


int CGamingCtrl::ScoreInit(int CScore)
{
	// TODO: 여기에 구현 코드 추가.
	switch (CScore) {
	case 0:
		BgVerticalCtrl = 0;

	case 100:
		BgVerticalCtrl = 0;

	case 200:
		BgVerticalCtrl = 0;

	case 300:
		BgVerticalCtrl = 0;

	case 400:
		BgVerticalCtrl = 0;

	case 500:
		BgVerticalCtrl = 0;
	}

	return 0;
}


void CGamingCtrl::viewdraw()
{
	// TODO: 여기에 구현 코드 추가.

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCprojectJEANMACKView* pView = (CMFCprojectJEANMACKView*)pMainFrame->GetActiveView();

	CString Tprint;
	for (int i = 0; i < 4; i++) {
		AfxExtractSubString(Tprint, changeSTR, i, '#');
		switch (i) {
		case 0:
			pView->Tscore.Format(_T("최고 점수: ") + Tprint);
			break;
		case 1:
			pView->Tcoin.Format(_T("보유 골드: ") + Tprint);
			break;
		case 2:
			pView->Tbackg.Format(_T("보유 테마: ") + Tprint);
			break;
		case 3:
			pView->Tchar.Format(_T("보유 캐릭터: ") + Tprint);
			break;
		}
	}
	pView->Invalidate();
}

void CGamingCtrl::fileRead()
{
	// TODO: 여기에 구현 코드 추가.
	//파일을 읽어와서 점수,코인,테마,캐릭터 변수에 저장
	CStdioFile file;
	CString str;

	file.Open(_T("Coin.txt"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	while (ar.ReadString(str)) {
		AfxExtractSubString(fscore, str, 0, '#');
		AfxExtractSubString(fcoin, str, 1, '#');
		AfxExtractSubString(fbackg, str, 2, '#');
		AfxExtractSubString(fchar, str, 3, '#');
	}
	file.Close();
	changeSTR = fscore + '#' + fcoin + '#' + fbackg + '#' + fchar + '#';
}


void CGamingCtrl::changeValue()
{
	// TODO: 여기에 구현 코드 추가.
	//파일에 저장된 값 변경
	CStdioFile informationfile; // CStdioFile은 텍스트 파일을 줄 단위로 읽고 씀

	int holdcoin = 0;
	int holdscore = 0;
	int whilecount = 0;

	setlocale(LC_ALL, "Korean");

	holdscore = _ttoi(fscore);
	holdcoin = _ttoi(fcoin);

	fbackg = "1"; fchar = "1";
	//
	informationfile.Open(_T("Coin.txt"), CFile::modeWrite | CFile::typeText);

	if (holdscore < score) //현재점수가 최고점수보다 높으면
		fscore.Format(_T("%d"), score); //fscore에 현재점수 포맷

	holdcoin += coin;
	fcoin.Format(_T("%d"), holdcoin); //코인 파일에 더해줌

	changeSTR = fscore + '#' + fcoin + '#' + fbackg + '#' + fchar + '#';

	informationfile.Write(changeSTR, sizeof(changeSTR) * 5);
	informationfile.Close();
}


void CGamingCtrl::thema(int t)
{
	// TODO: 여기에 구현 코드 추가.
	int coins = _ttoi(fcoin);
	switch (t) {
	case 1:
		game_thema = 1;
		AfxMessageBox(_T("테마 선택 완료"));
		break;
	case 2:
		if (fbackg == "1" || fbackg == "3") game_thema = 2;
		else if (coins >= 300) {
			coins -= 300;
			fcoin.Format(_T("%d"), coins);
			if (fbackg == "2") fbackg = "3";
			else fbackg = "1";
			AfxMessageBox(_T("테마 구매 완료"));
		}
		else AfxMessageBox(_T("돈 부족"));
		break;
	case 3:
		if (fbackg == "2" || fbackg == "3") game_thema = 3;
		else if (coins >= 500) {
			coins -= 500;
			fcoin.Format(_T("%d"), coins);
			if (fbackg == "1") fbackg = "3";
			else fbackg = "2";
			AfxMessageBox(_T("테마 구매 완료"));
		}
		else AfxMessageBox(_T("돈 부족"));
		break;
	}
}


void CGamingCtrl::gamechar(int c, int coin)
{
	// TODO: 여기에 구현 코드 추가.
	int coins = _ttoi(fcoin);
	switch (c) {
	case 1:
		game_thema = 1;
		AfxMessageBox(_T("캐릭터 선택 완료"));
		break;
	case 2:
		if (fbackg == "1" || fbackg == "3") game_thema = 2;
		else if (coin >= 800) {
			coins -= 800;
			fcoin.Format(_T("%d"), coins);
			if (fbackg == "2") fbackg = "3";
			else fbackg = "1";
			AfxMessageBox(_T("캐릭터 구매 완료"));
		}
		else AfxMessageBox(_T("돈 부족"));
		break;
	case 3:
		if (fbackg == "2" || fbackg == "3") game_thema = 3;
		else if (coin >= 1200) {
			coins -= 1200;
			fcoin.Format(_T("%d"), coins);
			if (fbackg == "1") fbackg = "3";
			else fbackg = "2";
			AfxMessageBox(_T("캐릭터 구매 완료"));
		}
		else AfxMessageBox(_T("돈 부족"));
		break;
	}
}
