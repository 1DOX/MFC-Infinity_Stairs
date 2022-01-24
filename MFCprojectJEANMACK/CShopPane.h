#pragma once
#include <afxdockablepane.h>
#include "CShopCtrl.h"
class CShopPane :
    public CDockablePane
{
public:
    CShopCtrl m_ctrlShop;
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);

};

