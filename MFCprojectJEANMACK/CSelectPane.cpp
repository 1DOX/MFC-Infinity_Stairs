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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlSelect.Create(IDD_DIALOG_CHANGE, this)) {
		TRACE0("����\n");
		return -1;
	}
	m_ctrlSelect.ShowWindow(SW_SHOW);
	return 0;
}


void CSelectPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlSelect.GetSafeHwnd()) {
		m_ctrlSelect.MoveWindow(0, 0, cx, cy);
		m_ctrlSelect.SetFocus();
	}
}
