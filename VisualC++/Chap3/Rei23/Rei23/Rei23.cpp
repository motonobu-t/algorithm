// Rei23.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------------------------
 *      ������̏ƍ��i�P���ȕ��@�j     *
 * -------------------------------------
 */

#include <stdio.h>
#include <string.h>

char *search(char *,char *);

void main(void)
{
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";

    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
	getchar();
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}

