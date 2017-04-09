//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr19_2.h"
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
 * ----------------------------------------
 *      シェル・ソート（改良挿入法 ）     *
 * ----------------------------------------
 */

#include "turboform.h"

#define N 100   /* データ数 */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        /* Ｎ個の乱数 */
        a[i]=rand();
                            /* Ｎより小さい範囲で最大のｇａｐを決める */
    for (gap=1;gap<N/3;gap=3*gap+1)
        ;

    while (gap>0){
        for (i=gap;i<N;i++){
            for (j=i-gap;j>=0;j=j-gap){
                if (a[j]>a[j+gap]){
                    t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                }
                else
                    break;
            }
        }
        gap=gap/3;             /* ギャップを１／３にする */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");

}
//---------------------------------------------------------------------------
