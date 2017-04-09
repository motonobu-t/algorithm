// Dr1_2Label.h : Dr1_2Label アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr1_2LabelApp:
// このクラスの実装については、Dr1_2Label.cpp を参照してください。
//

class CDr1_2LabelApp : public CWinApp
{
public:
	CDr1_2LabelApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr1_2LabelApp theApp;