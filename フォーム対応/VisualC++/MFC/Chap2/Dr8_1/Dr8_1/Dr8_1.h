// Dr8_1.h : Dr8_1 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr8_1App:
// このクラスの実装については、Dr8_1.cpp を参照してください。
//

class CDr8_1App : public CWinApp
{
public:
	CDr8_1App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr8_1App theApp;