#pragma once
#include <afxdockablepane.h>
#include "CGamingCtrl.h"
class CGamingPane :
    public CDockablePane
{
public:
    CGamingCtrl m_ctrlGaming;
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

