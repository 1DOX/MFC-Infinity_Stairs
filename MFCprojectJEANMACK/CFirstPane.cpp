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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlFirst.Create(IDD_DIALOG_FIRST, this)) {
		TRACE0("����\n");
		return -1;
	}
	m_ctrlFirst.ShowWindow(SW_SHOW);
	return 0;
}


void CFirstPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlFirst.GetSafeHwnd()) {
		m_ctrlFirst.MoveWindow(0, 0, cx, cy);
		m_ctrlFirst.SetFocus();
	}
}
