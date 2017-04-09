//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr41.h"
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
 * -----------------------------------------------
 *      ���X�g��p�����n�b�V���i�I�[�ɒǉ��j     *
 * -----------------------------------------------
 */

#include "turboform.h"

#define TableSize 1000
#define ModSize   1000

struct tfield {
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];             /* �|�C���^�E�e�[�u�� */
int hash(char *s)         /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	struct tfield *p,*q;
	p=talloc();
	stoc(Edit1->Text,p->name);
	stoc(Edit2->Text,p->tel);

	n=hash(p->name);
    if (dat[n]==NULL){            /* ��̂Ƃ� */
        dat[n]=p;
        p->pointer=NULL;
    }
    else {                        /* �����������Ƃ� */
        q=dat[n];
        while (q->pointer!=NULL)  /* �I�[�֒ǉ� */
            q=q->pointer;
        q->pointer=p;
        p->pointer=NULL;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	char key[32];
	struct tfield *p;
	stoc(Edit3->Text,key);

	n=hash(key);
    p=dat[n];
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0)
            printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	int n;
	for (n=0;n<TableSize;n++)    /* �|�C���^�E�e�[�u���̏����� */
        dat[n]=NULL;
}
