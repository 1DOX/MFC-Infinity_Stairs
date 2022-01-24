#pragma once


// CGamingCtrl 대화 상자

class CGamingCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CGamingCtrl)

public:
	CGamingCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGamingCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAMING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPlay();
private:
	int count = 0;
public:
	CProgressCtrl m_progress;
	CImage bmp_stair;
	//int stairs[30];
	bool changeDIR[30] = { false };
	int posX[30] = { 0 };
	int posY[30] = { 0 };
	int dirLX = 50; //계단 비트맵 가로사이즈(픽셀)
	int dirRX = -50;
	int dirY = 25;
	//afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CImage bmp_char;
	bool isleft;
	int stair_index;
	bool stairDIR_Left[30];
	CImage p_black;
	int score;
	CListBox m_listBox;
	bool is_game_ing = false;
	float gauge = 1.0f;
	int backg_x = 600;
	int backg_y = 600;
	CImage background;
	void GameInit();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void SpawnStair(int index);
	void MoveStairs(int index, bool p_isChange, bool s_isLeft);
	void GameOver();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_character;
	CBitmap* pOldBmp;
	CBitmap bmp_d, bmp_u, bmp_dr, bmp_ur, bmp_x, bmp_xr; // 비트맵 클래스의 객체를 선언
	int SelectChar(int type);
	bool isCharChange = false;
	CImage bmp_coin;
	int coinposX[30] = { 0 };
	int coinposY[30] = { 0 };
	bool CoinSpawn[30];
	int coin = 0;
	void SpawnCoin();
	int GameCount = 0;
	CImage bmp_count3;
	CImage bmp_count2;
	CImage bmp_count1;
	bool isDie;
	void Wait(DWORD dwMillisecond);
	int ScoreInit(int CScore);
	int BgVerticalCtrl = 0;
	void viewdraw();
	int playerC = 1;
	int backG = 1;
	void fileRead();
	CString fscore;
	CString fcoin;
	CString fbackg;
	CString fchar;
	void changeValue();
	CString changeSTR;
	int game_char = 1;
	int game_thema = 1;
	void thema(int t);
	void gamechar(int c, int coin);
};