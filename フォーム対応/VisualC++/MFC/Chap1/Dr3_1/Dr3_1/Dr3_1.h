// Dr3_1.h : Dr3_1 アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr3_1App:
// このクラスの実装については、Dr3_1.cpp を参照してください。
//

class CDr3_1App : public CWinApp
{
public:
	CDr3_1App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr3_1App theApp;