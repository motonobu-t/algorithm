//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei54.h"
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
 * -------------------------------
 *      Ｅｕｌｅｒの一筆書き     *
 * -------------------------------
 */

#include "turboform.h"

#define Node 4        /* 節点の数 */
#define Root 6        /* 辺の数 */
#define Start 1       /* 開始点 */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,1},
                       {0,1,0,1,2},
                       {0,0,1,0,1},
                       {0,1,2,1,0}};
int success,
    v[Root+1],      /* 経路を入れるスタック */
    n;              /* 通過した道の数 */
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){    /* 辺の数だけ通過し元に戻ったら */
        printf("解 %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--; a[j][i]--;    /* 通つた道を切り離す */
                n--;
                visit(j);
                a[i][j]++; a[j][i]++;    /* 道を復旧する */
                n++;
            }
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tinit();cls();
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("解なし\n");

}
//---------------------------------------------------------------------------
