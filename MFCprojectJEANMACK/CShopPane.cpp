#include "pch.h"
#include "CShopPane.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CShopPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CShopPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlShop.Create(IDD_DIALOG_SHOP, this)) {
		TRACE0("����\n");
		return -1;
	}
	m_ctrlShop.ShowWindow(SW_SHOW);
	return 0;
}


void CShopPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlShop.GetSafeHwnd()) {
		m_ctrlShop.MoveWindow(0, 0, cx, cy);
		m_ctrlShop.SetFocus();
	}
}
