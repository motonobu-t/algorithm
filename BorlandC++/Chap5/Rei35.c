/*
 * -------------------------------
 *      ���X�g�f�[�^�ւ̒ǉ�     *
 * -------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head;

struct tfield *talloc(void);
void genlist(void);
void displist(void);
void link(char *);

void main(void)
{
    char key[20];

    genlist();
    displist();

    while (printf("Key Name "),scanf("%s",key)!=EOF){
        link(key);
    }

    displist();
}
void link(char *key)    /* ���X�g�ւ̒ǉ� */
{
    struct tfield *p,*n;

    n=talloc();
    printf("�ǉ��f�[�^ ");
    scanf("%s %s",n->name,n->tel);

    p=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            n->pointer=p->pointer;
            p->pointer=n;
            return;
        }
        p=p->pointer;
    }
    printf("�L�[�f�[�^��������܂���\n");
}
void genlist(void)        /* ���X�g�̍쐬 */
{
    struct tfield *p;

    head=NULL;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        p->pointer=head;
        head=p;
    }
}
void displist(void)      /* ���X�g�̕\�� */
{
    struct tfield *p;
    p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
