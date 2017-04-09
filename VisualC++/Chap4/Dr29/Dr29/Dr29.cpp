// Dr29.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ------------------------------------------
 *      ハノイの塔（引数を１つ減らす）      *
 * ------------------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char);
#define Total 'a'+'b'+'c'

void main(void)
{
    int n;
    printf("円盤の枚数 ? ");
    scanf_s("%d",&n);

    hanoi(n,'a','b');
	getchar();getchar();
}
void hanoi(int n,char a,char b)  /* 再帰手続 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d番の円盤を %c から %c に移動\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}


