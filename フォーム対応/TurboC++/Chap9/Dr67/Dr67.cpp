//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr67.h"
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
 * --------------------------------------------------------
 *   ダイナミック・プグラミング（釣銭の枚数を最小にする） *
 * --------------------------------------------------------
 */

#include "turboform.h"

#define limit 42    /* 釣銭金額 */
#define n 3         /* コインの種類 */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int size[]={1,10,25};
    int value[limit+1],     /* 枚数 */
        item[limit+1],      /* コインの番号 */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++){
        value[s]=s;          /* 初期値 */
    }
    for (i=0;i<n;i++){                    /* コインの番号 */
        for (s=size[i];s<=limit;s++){     /* ナップのサイズ */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]){
                value[s]=newvalue;item[s]=i;     /* 最適解の更新 */
            }
        }
    }
	tinit();cls();
    printf("コインの枚数 =%3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);
	printf("\n");
}
//---------------------------------------------------------------------------
