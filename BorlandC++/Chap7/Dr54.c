/*
 * -----------------------------------------------
 *      �d���������̈�M�����i�L���O���t�Łj     *
 * -----------------------------------------------
 */

#include <stdio.h>

#define Node 4        /* �ߓ_�̐� */
#define Root 6        /* �ӂ̐� */
#define Start 1       /* �J�n�_ */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,0},
                       {0,0,0,1,1},
                       {0,0,0,0,1},
                       {0,1,1,0,0}};
int success,
    v[Root+1],      /* �o�H������X�^�b�N */
    n;              /* �ʉ߂������̐� */

void visit(int);

void main(void)
{
    success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("���Ȃ�\n");
}
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){     /* �ӂ̐������ʉ߂����ɖ߂����� */
        printf("�� %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--;     /* �ʂ�����؂藣�� */
                n--;
                visit(j);
                a[i][j]++;     /* ���𕜋����� */
                n++;
            }
    }
}
