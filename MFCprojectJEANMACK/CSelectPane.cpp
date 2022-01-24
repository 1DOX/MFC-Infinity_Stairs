#include "pch.h"
#include "CSelectPane.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CSelectPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CSelectPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlSelect.Create(IDD_DIALOG_CHANGE, this)) {
		TRACE0("실패\n");
		return -1;
	}
	m_ctrlSelect.ShowWindow(SW_SHOW);
	return 0;
}


void CSelectPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlSelect.GetSafeHwnd()) {
		m_ctrlSelect.MoveWindow(0, 0, cx, cy);
		m_ctrlSelect.SetFocus();
	}
}
