// Dr34_1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ---------------------------------------
 *      リストデータの作成（入力順）     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();
    scanf_s("%s %s",head->name,20,head->tel,20);
    old=head;
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;

    p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	getchar();
}
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


