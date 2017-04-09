// Dr34_1.h : Dr34_1 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr34_1App:
// このクラスの実装については、Dr34_1.cpp を参照してください。
//

class CDr34_1App : public CWinApp
{
public:
	CDr34_1App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr34_1App theApp;