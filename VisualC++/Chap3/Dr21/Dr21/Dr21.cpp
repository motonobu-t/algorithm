// Dr21.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * --------------------
 *     ２分探索法     *
 * --------------------
 */

#include <stdio.h>

#define N 10       /* データ数　*/

void main(void)
{
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;

    printf("検索するdata ? ");scanf_s("%d",&key);

    low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }
    if (low==high+2)
        printf("%d は %d 番目にありました\n",a[mid],mid);
    else
        printf("見つかりませんでした\n");
	getchar();getchar();
}


