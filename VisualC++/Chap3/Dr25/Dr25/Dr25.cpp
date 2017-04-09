// Dr25.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * -------------------
 *      ハッシュ     *
 * -------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize      1000

int hash(char *);

struct tel{             /* データ・テーブル */
    char name[12];
    char telnum[12];
    int empty;
} dat[TableSize];

void main(void)
{
    int n;
    char a[12],b[12];

    printf("名前 電話番号\n");
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
            printf("表が一杯です\n");
    }

    rewind(stdin);
    printf("検索するデータを入力してください\n");
    while (scanf_s("%s",a,12)!=EOF){
        n=hash(a);
        while (strcmp(a,dat[n].name)!=0 && n<TableSize)
            n++;
        if (n<TableSize)
            printf("%15s%15s\n",dat[n].name,dat[n].telnum);
        else
            printf("デ－タは見つかりませんでした\n");
    }
}
int hash(char *s)        /* ハッシュ関数 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}


