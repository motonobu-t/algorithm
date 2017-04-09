// Dr14_2ListBox.h : Dr14_2ListBox アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr14_2ListBoxApp:
// このクラスの実装については、Dr14_2ListBox.cpp を参照してください。
//

class CDr14_2ListBoxApp : public CWinApp
{
public:
	CDr14_2ListBoxApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr14_2ListBoxApp theApp;