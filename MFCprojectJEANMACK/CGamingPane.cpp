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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlGaming.Create(IDD_DIALOG_GAMING, this)) {
		TRACE0("����\n");
		return -1;
	}
	m_ctrlGaming.ShowWindow(SW_SHOW);

	return 0;
}


void CGamingPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlGaming.GetSafeHwnd()) {
		m_ctrlGaming.MoveWindow(0, 0, cx, cy);
		m_ctrlGaming.SetFocus();
	}
}
