
// MFCprojectJEANMACKView.cpp: CMFCprojectJEANMACKView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCprojectJEANMACK.h"
#endif

#include "MFCprojectJEANMACKDoc.h"
#include "MFCprojectJEANMACKView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCprojectJEANMACKView

IMPLEMENT_DYNCREATE(CMFCprojectJEANMACKView, CView)

BEGIN_MESSAGE_MAP(CMFCprojectJEANMACKView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCprojectJEANMACKView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCprojectJEANMACKView 생성/소멸

CMFCprojectJEANMACKView::CMFCprojectJEANMACKView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCprojectJEANMACKView::~CMFCprojectJEANMACKView()
{
}

BOOL CMFCprojectJEANMACKView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	return CView::PreCreateWindow(cs);
}

// CMFCprojectJEANMACKView 그리기

void CMFCprojectJEANMACKView::OnDraw(CDC* pDC)
{
	CMFCprojectJEANMACKDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
	pDC->TextOut(200, 200, Tscore);
	pDC->TextOut(200, 250, Tcoin);
	pDC->TextOut(200, 300, Tbackg);
	pDC->TextOut(200, 350, Tchar);
}


// CMFCprojectJEANMACKView 인쇄


void CMFCprojectJEANMACKView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCprojectJEANMACKView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCprojectJEANMACKView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCprojectJEANMACKView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCprojectJEANMACKView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCprojectJEANMACKView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCprojectJEANMACKView 진단

#ifdef _DEBUG
void CMFCprojectJEANMACKView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCprojectJEANMACKView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCprojectJEANMACKDoc* CMFCprojectJEANMACKView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCprojectJEANMACKDoc)));
	return (CMFCprojectJEANMACKDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCprojectJEANMACKView 메시지 처리기
