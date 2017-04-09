// Dr35_1.h : Dr35_1 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr35_1App:
// このクラスの実装については、Dr35_1.cpp を参照してください。
//

class CDr35_1App : public CWinApp
{
public:
	CDr35_1App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr35_1App theApp;