// Dr17MFC.h : Dr17MFC アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDr17MFCApp:
// このクラスの実装については、Dr17MFC.cpp を参照してください。
//

class CDr17MFCApp : public CWinApp
{
public:
	CDr17MFCApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr17MFCApp theApp;