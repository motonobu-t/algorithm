//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei67.h"
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
 * -------------------------------------------------------
 *   ダイナミック・プログラミング（ナップ・サック問題）  *
 * -------------------------------------------------------
 */

#include "turboform.h"

#define limit 8         /* ナップサックの重量制限値 */
#define n 5             /* 品物の種類 */
#define min    1        /* 重さの最小値 */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct body {
        char name[20];         /* 品名 */
        int size;           /* 重さ */
        long price;         /* 価格 */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++){
        value[s]=0;         /* 初期値 */
    }
    for (i=0;i<n;i++){                      /* 品物の番号 */
        for (s=a[i].size;s<=limit;s++){     /* ナップのサイズ */
            p=s-a[i].size;                  /* 空きサイズ */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s]){
                value[s]=newvalue;item[s]=i;    /* 最適解の更新 */
            }
        }
    }
	tinit();cls();
    printf("    品  目　価格\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %5ld\n",a[item[s]].name,a[item[s]].price);
	printf("    合  計 %5ld\n",value[limit]);
}
//---------------------------------------------------------------------------
