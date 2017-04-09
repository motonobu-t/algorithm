// Rei37.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * -----------------------------------
 *      双方向リストデータの作成     *
 * -----------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    struct tfield *left;    /* 逆ポインタ */
    char name[20];          /* 名前       */
    char tel[20];           /* 電話番号   */
    struct tfield *right;   /* 順ポインタ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*tail,*p;

    tail=NULL;              /* 逆リストの作成 */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->left=tail;
        tail=p;
    }

    p=tail;                 /* 順リストの作成 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

    printf("\n順方向リスト\n");
    p=head;                 /* リストの順表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("\n逆方向リスト\n");
    p=tail;                 /* リストの逆表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	getchar();
}
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


