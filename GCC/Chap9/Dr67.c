/*
 * --------------------------------------------------------
 *   �_�C�i�~�b�N�E�v�O���~���O�i�ޑK�̖������ŏ��ɂ���j *
 * --------------------------------------------------------
 */

#include <stdio.h>

#define limit 42    /* �ޑK���z */
#define n 3         /* �R�C���̎�� */

int main(void)
{
    int size[]={1,10,25};
    int value[limit+1],     /* ���� */
        item[limit+1],      /* �R�C���̔ԍ� */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++){
        value[s]=s;          /* �����l */
    }
    for (i=0;i<n;i++){                    /* �R�C���̔ԍ� */
        for (s=size[i];s<=limit;s++){     /* �i�b�v�̃T�C�Y */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]){
                value[s]=newvalue;item[s]=i;     /* �œK���̍X�V */
            }
        }
    }

    printf("�R�C���̖��� =%3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);
    printf("\n");
    return 0;
}
