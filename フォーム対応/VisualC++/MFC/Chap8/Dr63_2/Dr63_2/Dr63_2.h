// Dr63_2.h : Dr63_2 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr63_2App:
// このクラスの実装については、Dr63_2.cpp を参照してください。
//

class CDr63_2App : public CWinApp
{
public:
	CDr63_2App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr63_2App theApp;