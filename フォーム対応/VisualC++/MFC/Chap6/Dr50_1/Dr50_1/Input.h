#pragma once


// CInput ダイアログ

class CInput : public CDialog
{
	DECLARE_DYNAMIC(CInput)

public:
	CInput(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CInput();

// ダイアログ データ
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	CString m_msg;
	CString m_text;
	afx_msg void OnBnClickedOk();
};
