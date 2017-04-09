// Dr18_1.h : Dr18_1 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr18_1App:
// このクラスの実装については、Dr18_1.cpp を参照してください。
//

class CDr18_1App : public CWinApp
{
public:
	CDr18_1App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr18_1App theApp;