// Input.cpp : 実装ファイル
//

#include "stdafx.h"
#include "Rei50.h"
#include "Input.h"


// CInput ダイアログ

IMPLEMENT_DYNAMIC(CInput, CDialog)

CInput::CInput(CWnd* pParent /*=NULL*/)
	: CDialog(CInput::IDD, pParent)
	, m_msg(_T(""))
	, m_text(_T(""))
{

}

CInput::~CInput()
{
}

void CInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LABEL, m_msg);
	DDX_Text(pDX, IDC_EDIT1, m_text);
}


BEGIN_MESSAGE_MAP(CInput, CDialog)
	ON_BN_CLICKED(IDOK, &CInput::OnBnClickedOk)
END_MESSAGE_MAP()


// CInput メッセージ ハンドラ

void CInput::OnBnClickedOk()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	OnOK();
}
