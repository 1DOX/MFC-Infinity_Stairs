#pragma once


// CFirstCtrl 대화 상자

class CFirstCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstCtrl)

public:
	CFirstCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFirstCtrl();
	CBitmap m_bitFirst;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIRST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnPaint();
	CButton m_Btn_start;
	CButton m_Btn_change;
	CButton m_Btn_shop;
	//afx_msg void OnBnClickedButton4();
};
