//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr55.h"
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
 *      �ŒZ�H�̃��[�g�̕\��     *
 * -------------------------------
 */

#include "turboform.h"

#define N 8         /* �ߓ_�̐� */
#define M 9999

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0}, /* �אڍs�� */
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
        leng[N+1],              /* �ߓ_�܂ł̋��� */
        v[N+1],                 /* �m��t���O */
        index[N+1];             /* �O�̐ߓ_�ւ̃|�C���^ */
	tinit();cls();
	start=stoi(Edit1->Text);

    for (k=1;k<=N;k++){
        leng[k]=M;v[k]=0;
    }
    leng[start]=0;
    index[start]=0;        /* �n�_�͂ǂ��������Ȃ� */

    for (j=1;j<=N;j++){
        min=M;             /* �ŏ��̐ߓ_��{�� */
        for (k=1;k<=N;k++){
            if (v[k]==0 && leng[k]<min){
                p=k; min=leng[k];
            }
        }
        v[p]=1;            /* �ŏ��̐ߓ_���m�肷�� */

        if (min==M){
            printf("�O���t�͘A���łȂ�\n");
            exit(1);
        }

        /* �����o�R���Ă��Ɏ��钷��������܂ł̍ŒZ�H��菬������΍X�V */
        for (k=1;k<=N;k++){
            if((leng[p]+a[p][k])<leng[k]){
                leng[k]=leng[p]+a[p][k];
                index[k]=p;
            }
        }
    }
    for (j=1;j<=N;j++){                  /* �ŒZ�H�̃��[�g�̕\�� */
        printf("%3d : %d",leng[j],j);    /* �I�[ */
        p=j;
        while (index[p]!=0){
            printf(" <-- %d",index[p]);
            p=index[p];
        }
        printf("\n");
	}
}
//---------------------------------------------------------------------------
