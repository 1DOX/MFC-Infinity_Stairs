#include "pch.h"
#include "CFirstPane.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CFirstPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CFirstPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlFirst.Create(IDD_DIALOG_FIRST, this)) {
		TRACE0("실패\n");
		return -1;
	}
	m_ctrlFirst.ShowWindow(SW_SHOW);
	return 0;
}


void CFirstPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlFirst.GetSafeHwnd()) {
		m_ctrlFirst.MoveWindow(0, 0, cx, cy);
		m_ctrlFirst.SetFocus();
	}
}
