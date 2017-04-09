// Dr34_2.h : Dr34_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr34_2App:
// このクラスの実装については、Dr34_2.cpp を参照してください。
//

class CDr34_2App : public CWinApp
{
public:
	CDr34_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr34_2App theApp;