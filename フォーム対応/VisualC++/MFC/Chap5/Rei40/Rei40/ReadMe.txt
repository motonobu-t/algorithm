================================================================================
MICROSOFT FOUNDATION CLASS ライブラリ: Rei40 プロジェクトの概要
===============================================================================

アプリケーション ウィザードが作成した Rei40 には Microsoft 
Foundation Class の基本的な使い方が示されています。アプリケーション作成のひな型
としてお使いください。

このファイルには Rei40 アプリケーションを構成している各ファイ
ルの概要説明が含まれます。

Rei40.vcproj
   これはアプリケーション ウィザードで生成された VC++ プロジェクトのメイン プ
   ロジェクト ファイルです。ファイルが生成された Visual C++ のバージョン情報が
   含まれています。また、アプリケーション ウィザードで選択したプラットフォー
   ム、構成およびプロジェクト機能に関する情報も含まれています。

Rei40.h
   これはアプリケーションのメイン ヘッダー ファイルです。このファイルには、
   Resource.h を含む、その他のプロジェクト固有のヘッダーが含まれていて、
   CRei40App アプリケーション クラスを宣言します。

Rei40.cpp
   これは、アプリケーション クラス CRei40App を含むメイン アプリケー
   ション ソース ファイルです。

Rei40.rc
   これは、プログラムが使用する Microsoft Windows のリソースの一覧ファイルで
   す。このファイルには RES サブディレクトリに保存されているアイコン、ビットマ
   ップ、カーソルが含まれています。このファイルは、Microsoft Visual C++ で直接
   編集することができます。プロジェクト リソースは 1041 にあります。

res\Rei40.ico
   これは、アプリケーションのアイコンとして使用されるアイコンファイルです。この
   アイコンはメイン リソース ファイル Rei40.rc に含まれていま
   す。

res\Rei40.rc2
   このファイルは Microsoft Visual C++ を使用しないで編集されたリソースを含んで
   います。リソース エディタで編集できないリソースはすべてこのファイルに入れて
   ください。

/////////////////////////////////////////////////////////////////////////////

メイン フレーム ウィンドウ:
    プロジェクトは標準の MFC インターフェイスを含みます。

MainFrm.h, MainFrm.cpp
   これらのファイルは、フレーム クラス CMainFrame を含みます。
   フレーム クラスは CFrameWnd から派生し、すべての SDI フレーム機能を制御しま
   す。

res\Toolbar.bmp
   このビットマップ ファイルはツール バーのタイル イメージとして使用されます。
   初期ツール バーおよびステータス バーは、CMainFrame クラスで
   作成されます。ツール バーのボタンを追加するには、このツール バーのビットマッ
   プをリソース エディタを使用して編集し、Rei40.rc ファイル内
   の IDR_MAINFRAME TOOLBAR 配列を更新してください。
/////////////////////////////////////////////////////////////////////////////

アプリケーション ウィザードは 1 つのドキュメントの種類と 1 つのビューを作成し
ます:

Rei40Doc.h, Rei40Doc.cpp - ドキュメント
   これらのファイルは CRei40Doc クラスを含みます。特別なドキュメント 
   データを追加したり、ファイルを保存したり、
   (via CRei40Doc::Serialize) を読み込んだりするには、これらのファイ
   ルを編集してください。

Rei40View.h, Rei40View.cpp - ドキュメントのビュー
   これらのファイルは CRei40View クラスを含みます。
   CRei40View オブジェクトは CRei40Doc オブジェクトを表示す
   るのに使用されます。



/////////////////////////////////////////////////////////////////////////////

その他の機能:

ActiveX コントロール
   アプリケーションは ActiveX コントロールの使用に関するサポートを含みます。

/////////////////////////////////////////////////////////////////////////////

その他の標準ファイル:

StdAfx.h, StdAfx.cpp
   これらのファイルは、既にコンパイルされたヘッダー ファイル (PCH) 
   Rei40.pch や既にコンパイルされた型のファイル StdAfx.obj を
   ビルドするために使用されます。

Resource.h
   これは新規リソース ID を定義する標準ヘッダー ファイルです。Microsoft 
   Visual C++ はこのファイルの読み取りと更新を行います。

Rei40.manifest
   アプリケーション マニフェスト ファイルは Windows XP で、Side-by-Side アセン
   ブリの特定のバージョンに関するアプリケーションの依存関係を説明するために使用
   されます。ローダーはこの情報を使用して、アセンブリ キャッシュから適切なアセ
   ンブリを、またはアプリケーションからプライベート アセンブリを読み込みます。
   アプリケーション マニフェストは再頒布用に、実行可能アプリケーションと同じフ
   ォルダにインストールされる外部 .manifest ファイルとして含まれているか、また
   はリソースのフォーム内の実行可能ファイルに含まれています。
/////////////////////////////////////////////////////////////////////////////

その他の注意:

アプリケーション ウィザードは "TODO:" で始まるコメントを使用して、追加したりカ
スタマイズする必要があるソース コードの部分を示します。

アプリケーションが共有 DLL 内で MFC を使用する場合は、MFC DLL を再頒布する必要
があります。また、アプリケーションがオペレーティング システムのロケール以外の言
語を使用している場合も、対応するローカライズされたリソース MFC90XXX.DLL を再頒
布する必要があります。これらのトピックの詳細については、MSDN ドキュメントの 
Visual C++ アプリケーションの再頒布に関するセクションを参照してください。

/////////////////////////////////////////////////////////////////////////////
