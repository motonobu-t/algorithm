/*
 * ---------------------------------------------
 *      �n�m�C�̓��i�V�~�����|�V�����t���j     *
 * ---------------------------------------------
 */

#include <stdio.h>
#include <conio.h>

void hanoi(int,int,int,int);
void move(int,int,int);

int pie[20][3];        /* 20:�~�Ղ̍ő喇��, 3:�_�̐� */
int sp[3],N;           /* �X�^�b�N�E�|�C���^ */

void main(void)
{
    int i;
    printf("�~�Ղ̖��� ? ");
    scanf("%d",&N);

    for (i=0;i<N;i++)               /* �_���ɉ~�Ղ�ς� */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* �X�^�b�N�E�|�C���^�̏����ݒ� */

    hanoi(N,0,1,2);
}
void hanoi(int n,int a,int b,int c)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void move(int n,int s,int d)        /* �~�Ղ̈ړ��V�~�����[�V���� */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ���|�����։~�Ղ̈ړ� */
    sp[d]++;                        /* �X�^�b�N�E�|�C���^�̍X�V */
    sp[s]--;

    printf("\n%d �Ԃ̉~�Ղ� %c-->%c �Ɉڂ�\n\n",n,'a'+s,'a'+d);
    for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
    printf("\n       a       b       c\n");
    rewind(stdin);getchar();
}
