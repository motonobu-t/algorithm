/*
 * ---------------------
 *      ‚S‚m–‚•ûw     *
 * ---------------------
 */

#include <stdio.h>

#define N 8     /* ‚S‚m•ûw(n=4,8,12,16,¥¥¥) */

void main(void)
{
    int hojin[N+1][N+1],i,j;

    for (j=1;j<=N;j++){
        for (i=1;i<=N;i++){
            if (j%4==i%4 || (j%4+i%4)%4==1)
                hojin[i][j]=(N+1-i)*N-j+1;
            else
                hojin[i][j]=(i-1)*N+j;
        }
    }

    printf("        ‚S‚m–‚•ûw (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }
}
