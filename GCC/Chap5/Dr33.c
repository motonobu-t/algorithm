/*
 * -----------------------------
 *      �L���[�i�҂��s��j     *
 * -----------------------------
 */

#include <stdio.h>

int queuein(int);
int queueout(int *);
void disp(void);

#define MaxSize 100     /* �L���[�E�T�C�Y */
int queue[MaxSize];     /* �L���[ */
int head=0,             /* �擪�f�[�^�ւ̃|�C���^ */
    tail=0;             /* �I�[�f�[�^�ւ̃|�C���^ */

int main(void)
{
    int c,n;

    while (printf("]"),(c=getchar())!=EOF){
        rewind(stdin);
        switch (c){
            case 'i':
            case 'I': printf("data--> ");
                      scanf("%d",&n);rewind(stdin);
                      if (queuein(n)==-1)
                            printf("�҂��s�񂪈�t�ł�\n");
                      break;
            case 'o':
            case 'O': if (queueout(&n)==-1)
                          printf("�҂��s��͋�ł�\n");
                      else
                          printf("queue data --> %d\n",n);
                      break;
            case 'l':
            case 'L': disp();
                      break;
        }
    }
    return 0;
}
int queuein(int n)     /* �L���[�Ƀf�[�^������葱�� */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* �L���[����t�̂Ƃ� */
}
int queueout(int *n)    /* �L���[����f�[�^�����o���葱�� */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* �L���[����̂Ƃ� */
}
void disp(void)        /* �҂��s��̓��e��\������葱�� */
{
    int i;

    i=head;
    while (i!=tail){
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}