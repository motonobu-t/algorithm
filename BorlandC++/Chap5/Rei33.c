/*
 * -----------------------------
 *      �L���[�i�҂��s��j     *
 * -----------------------------
 */

#include <stdio.h>

#define MaxSize 100     /* �L���[�E�T�C�Y */
int queue[MaxSize];     /* �L���[ */
int head=0,             /* �擪�f�[�^�ւ̃|�C���^ */
    tail=0;             /* �I�[�f�[�^�ւ̃|�C���^ */
int queuein(int);
int queueout(int *);

void main(void)
{
    int c,n;

    while (printf("]"),(c=getchar())!=EOF){
        rewind(stdin);
        if (c=='i' || c=='I'){
            printf("data--> ");
            scanf("%d",&n);rewind(stdin);
            if (queuein(n)==-1){
                printf("�҂��s�񂪈�t�ł�\n");
            }
        }
        if (c=='o' || c=='O'){
            if (queueout(&n)==-1)
                printf("�҂��s��͋�ł�\n");
            else
                printf("queue data --> %d\n",n);
        }
    }
}
int queuein(int n)       /* �L���[�Ƀf�[�^������葱�� */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* �L���[����t�̂Ƃ� */
}
int queueout(int *n)     /* �L���[����f�[�^�����o���葱�� */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* �L���[����̂Ƃ� */
}
