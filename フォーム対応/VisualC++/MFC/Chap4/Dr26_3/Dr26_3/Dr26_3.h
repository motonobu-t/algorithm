// Dr26_3.h : Dr26_3 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr26_3App:
// このクラスの実装については、Dr26_3.cpp を参照してください。
//

class CDr26_3App : public CWinApp
{
public:
	CDr26_3App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr26_3App theApp;