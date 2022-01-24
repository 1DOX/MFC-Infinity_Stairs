#pragma once
#include <afxdockablepane.h>
#include "CSelectCtrl.h"
class CSelectPane :
    public CDockablePane
{
public:
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    CSelectCtrl m_ctrlSelect;
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

