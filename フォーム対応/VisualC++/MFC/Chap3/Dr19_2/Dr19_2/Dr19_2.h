// Dr19_2.h : Dr19_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr19_2App:
// このクラスの実装については、Dr19_2.cpp を参照してください。
//

class CDr19_2App : public CWinApp
{
public:
	CDr19_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr19_2App theApp;