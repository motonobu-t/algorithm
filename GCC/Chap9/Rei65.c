/*
 * -------------------------------
 *      �헪��������񂯂�     *
 * -------------------------------
 */

#include <stdio.h>

int main(void)
{
    int man,computer,M,judge;
    int table[3][3]={{0,0,0},    /* �헪�e�[�u�� */
                     {0,0,0},
                     {0,0,0}},
        hist[3]={0,0,0};    /* ���s�̓x�� */
    char *hand[3]={"�O�[","�`���L","�p�["};

    M=0;
    while (1) {
        if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
            computer=2;
        else if (table[M][1]>table[M][2])
            computer=0;
        else
            computer=1;

        printf("0:�O�[�@1:�`���L  2:�p�[\n");
        printf("���Ȃ��̎� ");scanf("%d",&man);

        printf("�R���s���[�^�̎� %s\n",hand[computer]);

        judge=(computer-man+3)%3;
        switch (judge){
            case 0: printf("�Ђ��킯\n");break;
            case 1: printf("���Ȃ��̏���\n");break;
            case 2: printf("�R���s���[�^�̏���\n");break;
        }
        hist[judge]++;
        table[M][man]++;        /* �w�K */
        M=man;
        printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);
    }
    return 0;
}
