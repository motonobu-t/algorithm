// Input.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "Rei50.h"
#include "Input.h"


// CInput �_�C�A���O

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


// CInput ���b�Z�[�W �n���h��

void CInput::OnBnClickedOk()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	OnOK();
}
