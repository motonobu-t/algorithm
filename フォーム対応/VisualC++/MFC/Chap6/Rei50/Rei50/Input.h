#pragma once


// CInput �_�C�A���O

class CInput : public CDialog
{
	DECLARE_DYNAMIC(CInput)

public:
	CInput(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CInput();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	CString m_msg;
	CString m_text;
	afx_msg void OnBnClickedOk();
};
