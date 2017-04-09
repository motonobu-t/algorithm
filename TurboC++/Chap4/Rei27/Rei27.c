/*
 * ---------------------------
 *     ŠKæŒvZ‚Ì”ñÄ‹A‰ğ    *
 * ---------------------------
 */

#include <stdio.h>

long kaijo(int);

void main(void)
{
    int n;
    for (n=0;n<13;n++)
		printf("%2d!= %10ld\n",n,kaijo(n));
	getchar();
}
long kaijo(int n)   /* ŠKæ */
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}

