// Dr30_2.h : Dr30_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr30_2App:
// このクラスの実装については、Dr30_2.cpp を参照してください。
//

class CDr30_2App : public CWinApp
{
public:
	CDr30_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr30_2App theApp;