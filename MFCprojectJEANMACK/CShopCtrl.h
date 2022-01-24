#pragma once


// CShopCtrl 대화 상자

class CShopCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CShopCtrl)

public:
	CShopCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CShopCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButtonTh1();
	afx_msg void OnBnClickedButtonTh2();
	afx_msg void OnBnClickedButtonTh3();
};
