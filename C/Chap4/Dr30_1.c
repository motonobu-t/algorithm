/*
 * ---------------------------------------------------
 *      ���H�����ǂ�i�o�H���X�^�b�N�ɋL�^����j     *
 * ---------------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* �ʉ߈ʒu������X�^�b�N */

int visit(int,int);

void main(void)
{
    sp=0;                       /* �X�^�b�N�E�|�C���^�̏����� */
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=5; Ej=5;     /* �����Əo���̈ʒu */

    printf("\n���H�̒T��\n");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
    printf("\n");
}
int visit(int i,int j)
{
    int k;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;       /* �K��ʒu���X�^�b�N�ɐς� */

    if (i==Ei && j==Ej){            /* �o���ɓ��B�����Ƃ� */
        for (k=0;k<sp;k++)          /* �ʉߓ_�̕\�� */
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                            /* �o���ɓ��B���Ȃ��Ԗ��H�����܂悤 */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    sp--;                            /* �X�^�b�N����̂Ă� */
    return success;
}
