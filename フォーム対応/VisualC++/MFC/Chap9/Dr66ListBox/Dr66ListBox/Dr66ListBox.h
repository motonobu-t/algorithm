// Dr66ListBox.h : Dr66ListBox アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr66ListBoxApp:
// このクラスの実装については、Dr66ListBox.cpp を参照してください。
//

class CDr66ListBoxApp : public CWinApp
{
public:
	CDr66ListBoxApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr66ListBoxApp theApp;