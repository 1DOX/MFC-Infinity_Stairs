#pragma once
#include <afxdockablepane.h>
#include "CFirstCtrl.h"

class CFirstPane :
    public CDockablePane
{
public:
    CFirstCtrl m_ctrlFirst;
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

