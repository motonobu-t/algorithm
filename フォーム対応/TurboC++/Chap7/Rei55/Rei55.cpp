//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei55.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
 * ---------------------------------------
 *      最短路問題（ダイクストラ法）     *
 * ---------------------------------------
 */

#include "turboform.h"

#define N 8         /* 節点の数 */
#define M 9999

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0}, /* 隣接行列 */
                 {0,0,1,7,2,M,M,M,M},
                 {0,1,0,M,M,2,4,M,M},
                 {0,7,M,0,M,M,2,3,M},
                 {0,2,M,M,0,M,M,5,M},
                 {0,M,2,M,M,0,1,M,M},
                 {0,M,4,2,M,1,0,M,6},
                 {0,M,M,3,5,M,M,0,2},
				 {0,M,M,M,M,M,6,2,0}};
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int j,k,p,start,min,
        leng[N+1],              /* 節点までの距離 */
        v[N+1];                 /* 確定フラグ */
	tinit();cls();
	start=stoi(Edit1->Text);

    for (k=1;k<=N;k++){
        leng[k]=M;v[k]=0;
    }
    leng[start]=0;

    for (j=1;j<=N;j++){
        min=M;          /* 最小の節点を捜す */
        for (k=1;k<=N;k++){
            if (v[k]==0 && leng[k]<min){
                p=k; min=leng[k];
            }
        }
        v[p]=1;            /* 最小の節点を確定する */

        if (min==M){
            printf("グラフは連結でない\n");
            exit(1);
        }

        /* ｐを経由してｋに至る長さがそれまでの最短路より小さければ更新 */
        for (k=1;k<=N;k++){
            if((leng[p]+a[p][k])<leng[k])
                leng[k]=leng[p]+a[p][k];
        }
    }
    for (j=1;j<=N;j++)
        printf("%d -> %d : %d\n",start,j,leng[j]);

}
//---------------------------------------------------------------------------
