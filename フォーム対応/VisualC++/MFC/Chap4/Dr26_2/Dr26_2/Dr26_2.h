// Dr26_2.h : Dr26_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr26_2App:
// このクラスの実装については、Dr26_2.cpp を参照してください。
//

class CDr26_2App : public CWinApp
{
public:
	CDr26_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr26_2App theApp;