//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr25.h"
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
 *      �n�b�V��     *
 * -------------------
 */

#include "turboform.h"

#define TableSize 1050
#define ModSize      1000
struct tel{             /* �f�[�^�E�e�[�u�� */
    char name[12];
    char telnum[12];
    int empty;
} dat[TableSize];
int hash(char *s)        /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
    char a[12],b[12];
	tinit();cls();
	stoc(Edit1->Text,a);
	stoc(Edit2->Text,b);

    n=hash(a);
    while (dat[n].empty==1 && n<TableSize)
        n++;
    if (n<TableSize){
        strcpy(dat[n].name,a);   // �x���G���[�̏ꍇ��strcpy�̑����strcpy_s���g��
        strcpy(dat[n].telnum,b);
        dat[n].empty=1;
    }
    else
        printf("�\����t�ł�\n");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	char a[12];
	stoc(Edit3->Text,a);
	tinit();cls();
	n=hash(a);
    while (strcmp(a,dat[n].name)!=0 && n<TableSize)
        n++;
    if (n<TableSize)
        printf("%15s%15s\n",dat[n].name,dat[n].telnum);
    else
		printf("�f�|�^�͌�����܂���ł���\n");
}
//---------------------------------------------------------------------------
