// Rei50.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------------------------
 *      ���^�����ƌ���؁i�z��\���j     *
 * ---------------------------------------
 */

#include <stdio.h>

#define Max 100
#define nil -1

int getch(void)
{
	rewind(stdin);
	return getchar();
}

void main(void)
{
    struct tnode {
        int left;           /* ���ւ̃|�C���^ */
        char node[30];
        int right;          /* �E�ւ̃|�C���^ */
    };
    static struct tnode a[Max]={{1  ,"�|�\�l�ł���"  ,2},
                                {3  ,"�̎�ł���"    ,4},
                                {nil,"�g�c�@��"      ,nil},
                                {nil,"���@�z��"    ,nil},
                                {5  ,"���D�ł���"    ,6},
                                {nil,"���R�@����",nil},
                                {nil,"�v�� �G"       ,nil}};
    int p,lp=6,c;

    do {
        p=0;
        while (a[p].left!=nil){          /* �؂̃T�[�` */
            printf("\n%s y/n ",a[p].node);c=getch();
            if (c=='y' || c=='Y')
                p=a[p].left;
            else
                p=a[p].right;
        }

        printf("\n������ %s �ł��B\n�������ł��� y/n ",a[p].node);
        c=getch();

        if (c=='n' || c=='N'){               /* �w�K�@�\ */
            a[lp+1]=a[p];                    /* �m�[�h�̈ړ� */
                                           /* �V�����m�[�h�̍쐬 */
            printf("\n���Ȃ��̍l���� ? ");scanf_s("%s",a[lp+2].node,30);
            a[lp+2].left=a[lp+2].right=nil;
                                            /* ����m�[�h�̍쐬 */
            printf("%s �� %s ����ʂ��鎿��� ? ",a[lp+1].node,a[lp+2].node);
            scanf_s("%s",a[p].node,30);
            printf("�������̍��ڂ� %s �ŗǂ��ł��� y/n ",a[lp+1].node);
            c=getch();

            if (c=='Y' || c=='y'){          /* �q�̐ڑ� */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
    } while (printf("\n�����܂��� y/n "), c=getch(),c=='y' || c=='Y');
	printf("\n");
}

