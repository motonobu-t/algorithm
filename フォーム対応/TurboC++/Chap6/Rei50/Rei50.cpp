//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei50.h"
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
 *      ���^�����ƌ���؁i�z��\���j     *
 * ---------------------------------------
 */
#include <stdio.h>
#define Max 100
#define nil -1
struct tnode {
    int left;      /* ���ւ̃|�C���^ */
	AnsiString node;  /* CString�^�œ��� */
    int right;     /* �E�ւ̃|�C���^ */
};
struct tnode a[Max]={{1  ,"�|�\�l�ł���"  ,2},
					 {3  ,"�̎�ł���"    ,4},
					 {nil,"�g�c�@��"      ,nil},
					 {nil,"���@�z��"    ,nil},
					 {5  ,"���D�ł���"    ,6},
					 {nil,"���R�@����"    ,nil},
                     {nil,"�v�� �G"       ,nil}};
int lp=6;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString ret;
	int p,c;
	do {
        p=0;
		while (a[p].left!=nil){          /* �؂̃T�[�` */
			c=MessageDlg(a[p].node,mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES)
				p=a[p].left;
            else
                p=a[p].right;
		}
		c=MessageDlg("������"+a[p].node+"�ł�",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

        if (c==IDNO){               /* �w�K�@�\ */
			a[lp+1]=a[p];                    /* �m�[�h�̈ړ� */
										   /* �V�����m�[�h�̍쐬 */
			ret=InputBox("","���Ȃ��̍l����","");
			a[lp+2].node=ret;
			a[lp+2].left=a[lp+2].right=nil;
							/* ����m�[�h�̍쐬 */
			ret=InputBox("",a[lp+1].node+"��"+a[lp+2].node+"����ʂ��鎿���","");
			a[p].node=ret;
			c=MessageDlg("�������̍��ڂ�"+a[lp+1].node+"�ŗǂ��ł���",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES){          /* �q�̐ڑ� */
				a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
				a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
	} while (c=MessageDlg("�����܂���",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0),c==IDYES);

}
//---------------------------------------------------------------------------
