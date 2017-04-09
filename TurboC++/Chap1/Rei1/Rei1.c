/*
 * ------------------------------
 *      ‘Q‰»®in‚br‚ÌŒvZj    *
 * ------------------------------
 */

#include <stdio.h>

long combi(int,int);

void main(void)
{
    int n,r;

    for (n=0;n<=5;n++) {
        for (r=0;r<=n;r++)
            printf("%d‚b%d=%ld  ",n,r,combi(n,r));
        printf("\n");
    }
	getchar();
}
long combi(int n,int r)
{
    int i;
    long p=1;

    for (i=1;i<=r;i++)
        p=p*(n-i+1)/i;
    return p;
}



