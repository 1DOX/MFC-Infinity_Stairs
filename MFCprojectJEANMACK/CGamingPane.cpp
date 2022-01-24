#include "pch.h"
#include "CGamingPane.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CGamingPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CGamingPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlGaming.Create(IDD_DIALOG_GAMING, this)) {
		TRACE0("실패\n");
		return -1;
	}
	m_ctrlGaming.ShowWindow(SW_SHOW);

	return 0;
}


void CGamingPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlGaming.GetSafeHwnd()) {
		m_ctrlGaming.MoveWindow(0, 0, cx, cy);
		m_ctrlGaming.SetFocus();
	}
}
