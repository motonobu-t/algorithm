// Rei41.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------------------------
 *      ���X�g��p�����n�b�V���i�擪�ɒǉ��j     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tfield{
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];               /* �|�C���^�E�e�[�u�� */

struct tfield *talloc(void);

void main(void)
{
    int n;
    char key[12];
    struct tfield *p;

    for (n=0;n<TableSize;n++)    /* �|�C���^�E�e�[�u���̏����� */
        dat[n]=NULL;

    printf("���O �d�b�ԍ�\n");
    while (p=talloc(),scanf_s("%s %s",p->name,12,p->tel,12)!=EOF){
        n=hash(p->name);         /* �n�b�V���O */
        p->pointer=dat[n];       /* �擪�ɒǉ� */
        dat[n]=p;
    }

    rewind(stdin);                                  /* �T�� */
    printf("\n�T������f�[�^����͂��Ă�������\n");
    while (scanf_s("%s",key,12)!=EOF){
        n=hash(key);
        p=dat[n];
        while (p!=NULL){
            if (strcmp(key,p->name)==0)
                printf("%15s%15s\n",p->name,p->tel);
            p=p->pointer;
        }
    }
}
int hash(char *s)    /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


