//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr13.h"
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
 * -------------------
 *      多桁計算     *
 * -------------------
 */

#include "turboform.h"

#define KETA 20             /* 桁数 */
#define N ((KETA-1)/4+1)    /* 配列サイズ */

void lmul(short a[],short b,short c[])    /* ロング数×ショート数 */
{
    short i;long d,cy=0;
    for (i=N-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}
void ldiv(short a[],short b,short c[])    /* ロング数÷ショート数 */
{
    short i;long d,rem=0;
    for (i=0;i<N;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}
void print(short c[])            /* ロング数の表示 */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    short a[N+2]={   0,3050,2508,8080,1233},
          c[N+2];
	tinit();cls();
    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);

}
//---------------------------------------------------------------------------
