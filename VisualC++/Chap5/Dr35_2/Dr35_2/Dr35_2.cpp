// Dr35_2.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * -----------------------------
 *      リストデータの探索     *
 * -----------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p,
                  sentinel;        /* 番兵 */
    char key[20];

    head=&sentinel;                /* 番兵へのポインター */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->pointer=head;
        head=p;
    }

    rewind(stdin);                      /* 探索 */
    while (printf("\nkey name "),scanf_s("%s",key,20)!=EOF){
        strcpy_s(sentinel.name,20,key);      /* 番兵にキーを入れる */
        p=head;
        while (strcmp(p->name,key)!=0)
            p=p->pointer;
        if (p!=&sentinel)
            printf("%s %s\n",p->name,p->tel);
        else
            printf("見つかりません\n");
    }
}
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}



