/*
 * -----------------------------
 *      ���X�g�f�[�^�̒T��     *
 * -----------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
};

struct tfield *talloc(void);

int main(void)
{
    struct tfield *head,*p,
                  sentinel;        /* �ԕ� */
    char key[20];

    head=&sentinel;                /* �ԕ��ւ̃|�C���^�[ */
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        p->pointer=head;
        head=p;
    }

    rewind(stdin);                      /* �T�� */
    while (printf("key name "),scanf("%s",key)!=EOF){
        strcpy(sentinel.name,key);      /* �ԕ��ɃL�[������ */
        p=head;
        while (strcmp(p->name,key)!=0)
            p=p->pointer;
        if (p!=&sentinel)
            printf("%s %s\n",p->name,p->tel);
        else
            printf("������܂���\n");
    }
    return 0;
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

