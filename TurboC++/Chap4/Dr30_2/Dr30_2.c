/*
 * -------------------------------
 *      ���ׂĂ̖��H�����ǂ�     *
 * -------------------------------
 */

#include <stdio.h>

int m[9][9]={{2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* �ʉ߈ʒu������X�^�b�N */

int visit(int,int);

void main(void)
{
    sp=0;                       /* �X�^�b�N�E�|�C���^�̏����� */
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=7; Ej=7;     /* �����Əo���̈ʒu */

    printf("\n���H�̒T��");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
	printf("\n");
	getchar();
}
int visit(int i,int j)
{
    int k;
    static int path=1;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;   /* �K��ʒu���X�^�b�N�ɐς� */

    if (i==Ei && j==Ej){        /* �o���ɓ��B�����Ƃ� */
        printf("\npath=%d\n",path++);     /* �ʉߓ_�̕\�� */
        for (k=0;k<sp;k++)
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                                /* ���H�����܂悤 */
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);

    sp--;                       /* �X�^�b�N����̂Ă� */
    m[i][j]=0;                  /* �ʂȌo�H�̒T���̂��� */

    return success;
}

