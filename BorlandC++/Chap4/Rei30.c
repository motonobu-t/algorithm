/*
 * -------------------------------------------
 *      ���H�����ǂ�i�P����������j     *
 * -------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;

int visit(int,int);

void main(void)
{
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=5; Ej=5;     /* �����Əo���̈ʒu */

    printf("\n���H�̒T��\n");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
    printf("\n");
}
int visit(int i,int j)
{
    m[i][j]=1;                /* �K�ꂽ�ʒu�Ɉ������ */

    if (i==Ei && j==Ej)       /* �o���ɓ��B�����Ƃ� */
        success=1;
                               /* �o���ɓ��B���Ȃ��Ԗ��H�����܂悤 */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          /* �ʉߓ_�̕\�� */
        printf("(%d,%d) ",i,j);
    return success;
}
