// Dr8_2.h : Dr8_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr8_2App:
// このクラスの実装については、Dr8_2.cpp を参照してください。
//

class CDr8_2App : public CWinApp
{
public:
	CDr8_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr8_2App theApp;