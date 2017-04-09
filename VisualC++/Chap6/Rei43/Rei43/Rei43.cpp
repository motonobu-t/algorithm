// Rei43.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ---------------------------
 *      ２分探索木の作成     *
 * ---------------------------
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

void main(void)
{
    char dat[12];
    struct tnode *root,*p,*old;

    root=talloc();                  /* ルート・ノード */
    scanf_s("%s",root->name,12);
    root->left=root->right=NULL;

    while (scanf_s("%s",dat,12)!=EOF){
        p=root;                     /* 木のサーチ */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* 新しいノードの接続 */
        strcpy_s(p->name,12,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
	getchar();
}
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}


