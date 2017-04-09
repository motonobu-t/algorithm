// Rei66ListBox.h : Rei66ListBox アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CRei66ListBoxApp:
// このクラスの実装については、Rei66ListBox.cpp を参照してください。
//

class CRei66ListBoxApp : public CWinApp
{
public:
	CRei66ListBoxApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRei66ListBoxApp theApp;