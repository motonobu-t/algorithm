//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr19_1.h"
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
 *      �V�F���E�\�[�g�i���Ǒ}���@ �j     *
 * ----------------------------------------
 */

#include "turboform.h"

#define N 100   /* �f�[�^�� */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* �m�̗��� */
        a[i]=rand();

    gap=N/2;                /* �M���b�v�̏����l */
    while (gap>0){
        for (k=0;k<gap;k++){    /* �M���v�Ƃт̕�������̃\�[�g */
            for (i=k+gap;i<N;i=i+gap){
                for (j=i-gap;j>=k;j=j-gap){
                    if (a[j]>a[j+gap]){
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             /* �M���b�v�𔼕��ɂ��� */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");

}
//---------------------------------------------------------------------------
