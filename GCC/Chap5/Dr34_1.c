/*
 * ---------------------------------------
 *      ���X�g�f�[�^�̍쐬�i���͏��j     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();
    scanf("%s %s",head->name,head->tel);
    old=head;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;

    p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
    return 0;
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
