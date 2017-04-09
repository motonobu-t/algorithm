// Dr44_2.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * -------------------------------------
 *      ２分探索木の作成（再帰版）     *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
};

struct tnode *talloc(void);
void gentree(struct tnode **,char *);

void main(void)
{
    char dat[12];
    struct tnode *root,*p;

    root=NULL;
    while (scanf_s("%s",dat,12)!=EOF){
        gentree(&root,dat);
    }
    p=root;
    while (p!=NULL){
        printf("%s\n",p->name);
        p=p->left;
    }
	getchar();
}
void gentree(struct tnode **p,char *w)  /* 木の作成の再帰手続き */
{                                       /* 参照による呼出し     */
    if ((*p)==NULL){
        (*p)=talloc();
        strcpy_s((*p)->name,12,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

