//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr65.h"
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
 *      戦略を持つじゃんけん     *
 * -------------------------------
 */

#include "turboform.h"

int man,computer,C=0,M=0,judge;
int table[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},    /* 戦略テーブル */
                    {{0,0,0},{0,0,0},{0,0,0}},
                    {{0,0,0},{0,0,0},{0,0,0}}},
    hist[3]={0,0,0};                       /* 勝敗の度数 */
char *hand[3]={"グー","チョキ","パー"};

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tinit();cls();
	if (table[C][M][0]>table[C][M][1] && table[C][M][0]>table[C][M][2])
        computer=0;
    else if (table[C][M][1]>table[C][M][2])
        computer=1;
    else
        computer=2;
	man=stoi(Edit1->Text);

    printf("コンピュータの手 %s\n",hand[computer]);
    judge=(computer-man+3)%3;         /* 判定 */
    switch (judge){
        case 0: printf("ひきわけ\n");
                table[C][M][(computer+2)%3]++;break;
        case 1: printf("あなたの勝ち\n");
                table[C][M][computer]--;break;
        case 2: printf("コンピュータの勝ち\n");
                table[C][M][computer]++;break;
    }
    M=man;               /* １つ前の状態を保存 */
    C=computer;

    hist[judge]++;
    printf("--- %d勝%d敗%d分 ---\n\n",hist[1],hist[2],hist[0]);

}
//---------------------------------------------------------------------------
