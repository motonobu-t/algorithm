//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr15_1.h"
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
 * ---------------------------------------------
 *      連立方程式の解法（ピボット選択法）     *
 * ---------------------------------------------
 */

#include "turboform.h"

#define N 3     /* 元の数 */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d,max,dumy;
    int i,j,k,s;
	tinit();cls();
    for (k=0;k<N;k++){
        max=0;s=k;
        for(j=k;j<N;j++){
            if (fabs(a[j][k])>max){
                max=fabs(a[j][k]);s=j;
            }
        }
        if (max==0){
            printf("解けない");
            exit(1);
        }
        for (j=0;j<=N;j++){
            dumy=a[k][j];
            a[k][j]=a[s][j];
            a[s][j]=dumy;
        }

        p=a[k][k];              /* ピボット係数 */
        for (j=k;j<N+1;j++)        /* ピボット行をｐで割る */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){      /* ピボット列の掃き出し */
            if (i!=k){
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);

}
//---------------------------------------------------------------------------
