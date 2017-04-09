// Rei7.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * -----------------------
 *       素数の判定      *
 * -----------------------
 */

#include <stdio.h>
#include <math.h>

void main(void)
{
    int i,n,Limit;

    while (printf("data? "),scanf_s("%d",&n)!=EOF){
        if (n>=2){
            Limit=(int)sqrt((double)n);
            for (i=Limit;i>1;i--){
                if (n%i == 0)
                    break;
            }
            if (i==1)
                printf("素数\n");
            else
                printf("素数でない\n");
        }
    }
}

