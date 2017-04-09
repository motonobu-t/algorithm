// Dr25.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------
 *      �n�b�V��     *
 * -------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize      1000

int hash(char *);

struct tel{             /* �f�[�^�E�e�[�u�� */
    char name[12];
    char telnum[12];
    int empty;
} dat[TableSize];

void main(void)
{
    int n;
    char a[12],b[12];

    printf("���O �d�b�ԍ�\n");
    while (scanf_s("%s %s",a,12,b,12)!=EOF){
        n=hash(a);
        while (dat[n].empty==1 && n<TableSize)
            n++;
        if (n<TableSize){
            strcpy_s(dat[n].name,12,a);
            strcpy_s(dat[n].telnum,12,b);
            dat[n].empty=1;
        }
        else
            printf("�\����t�ł�\n");
    }

    rewind(stdin);
    printf("��������f�[�^����͂��Ă�������\n");
    while (scanf_s("%s",a,12)!=EOF){
        n=hash(a);
        while (strcmp(a,dat[n].name)!=0 && n<TableSize)
            n++;
        if (n<TableSize)
            printf("%15s%15s\n",dat[n].name,dat[n].telnum);
        else
            printf("�f�|�^�͌�����܂���ł���\n");
    }
}
int hash(char *s)        /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}


