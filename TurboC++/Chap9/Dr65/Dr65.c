/*
 * -------------------------------
 *      �헪��������񂯂�     *
 * -------------------------------
 */

#include <stdio.h>

void main(void)
{
    int man,computer,C,M,judge;
    int table[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},    /* �헪�e�[�u�� */
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}}},
        hist[3]={0,0,0};                       /* ���s�̓x�� */
    char *hand[3]={"�O�[","�`���L","�p�["};

    C=M=0;
    while (1) {
        if (table[C][M][0]>table[C][M][1] && table[C][M][0]>table[C][M][2])
            computer=0;
        else if (table[C][M][1]>table[C][M][2])
            computer=1;
        else
            computer=2;

        printf("0:�O�[�@1:�`���L  2:�p�[\n");
        printf("���Ȃ��̎� ");scanf("%d",&man);

        printf("�R���s���[�^�̎� %s\n",hand[computer]);

        judge=(computer-man+3)%3;         /* ���� */
        switch (judge){
            case 0: printf("�Ђ��킯\n");
                    table[C][M][(computer+2)%3]++;break;
            case 1: printf("���Ȃ��̏���\n");
                    table[C][M][computer]--;break;
            case 2: printf("�R���s���[�^�̏���\n");
                    table[C][M][computer]++;break;
        }
        M=man;               /* �P�O�̏�Ԃ�ۑ� */
        C=computer;

        hist[judge]++;
        printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);
    }
}

