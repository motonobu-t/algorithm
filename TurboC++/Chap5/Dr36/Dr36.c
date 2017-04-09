/*
 * -----------------------------
 *      ���X�g�f�[�^�̍폜     *
 * -----------------------------
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
void del(char *);

void main(void)
{
    char key[20];

    genlist();
    displist();

    while (printf("Key Name "),scanf("%s",key)!=EOF){
        del(key);
    }

	displist();
	getchar();
}
void del(char *key)            /* ���X�g����폜 */
{
    struct tfield *p;

    p=head;
    while (p->pointer!=NULL){
        if (strcmp(key,p->pointer->name)==0){
            p->pointer=p->pointer->pointer;
            return;
        }
        p=p->pointer;
    }
    printf("�L�[�f�[�^��������܂���\n");
}
void genlist(void)      /* �_�~�[�E�m�[�h����ꂽ���X�g */
{
    struct tfield *p;

    head=NULL;
    do {
        p=talloc();
        p->pointer=head;
        head=p;
    }while (scanf("%s %s",p->name,p->tel)!=EOF);
}
void displist(void)           /* ���X�g�̕\�� */
{
    struct tfield *p;
    p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

