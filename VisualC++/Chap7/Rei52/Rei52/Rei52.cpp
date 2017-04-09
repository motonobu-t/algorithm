// Rei52.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ---------------------------------
 *      グラフの探索（幅優先）     *
 * ---------------------------------
 */

#include <stdio.h>

#define N 8                                 /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},       /* 隣接行列 */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,1,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,0,0,0,0},
                 {0,0,1,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                                 /* 訪問フラグ */

int queue[100];             /* キュー */
int head=0,                 /* 先頭データのインデックス */
    tail=0;                 /* 終端データのインデックス */


void main(void)
{
    int i,j;

    for (i=1;i<=N;i++)
        v[i]=0;

    queue[tail++]=1;v[1]=1;
    do {
        i=queue[head++];            /* キューから取り出す */
        for (j=1;j<=N;j++){
            if (a[i][j]==1 && v[j]==0){
                printf("%d->%d ",i,j);
                queue[tail++]=j;    /* キューに入れる */
                v[j]=1;
            }
        }
    } while (head!=tail);
	printf("\n");
	getchar();
}


