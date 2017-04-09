//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei50_1.h"
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
 * ---------------------------------------
 *      ���^�����ƌ���؁i���I�\���j     *
 * ---------------------------------------
 */
struct tnode {
	struct tnode *left;  /* ���ւ̃|�C���^ */
	wchar_t node[30];      /* ���I���������蓖�Ă��s�����ߌŒ蒷�z�� */
	struct tnode *right; /* �E�ւ̃|�C���^ */
};
struct tnode *root;

struct tnode *talloc(void)            /* �L���̈�̎擾 */
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tnode *p,*q1,*q2;
    int c;
	AnsiString ret;

    root=talloc();
	ret=InputBox("","�����m�[�h�H","");
	ret.WideChar(root->node,30 );
	root->left=root->right=NULL;
    do {
        p=root;                             /* �؂̃T�[�` */
        while (p->left!=NULL){
			c=MessageDlg(AnsiString(p->node),mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=MessageDlg("������"+AnsiString(p->node)+"�ł�",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

		if (c==IDNO){                         /* �w�K�@�\ */
			q1=talloc(); *q1=*p;        /* �m�[�h�̈ړ� */

            q2=talloc();                /* �V�����m�[�h�̍쐬 */
			ret=InputBox("","���Ȃ��̍l����","");
			ret.WideChar(q2->node,30);
            q2->left=q2->right=NULL;
                                        /* ����m�[�h�̍쐬 */
			ret=InputBox("",AnsiString(q1->node)+"��"+AnsiString(q2->node)+"����ʂ��鎿���","");
			ret.WideChar(p->node,30);
			c=MessageDlg("�������̍��ڂ�"+AnsiString(q1->node)+"�ŗǂ��ł���",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

            if (c==IDYES){      /* �q�̐ڑ� */
				p->left=q1; p->right=q2;
            }
            else {
				p->left=q2; p->right=q1;
            }
        }
	} while (c=MessageDlg("�����܂���",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0),c==IDYES);

}
//---------------------------------------------------------------------------
