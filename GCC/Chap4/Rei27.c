/*
 * ---------------------------
 *     �K��v�Z�̔�ċA��    *
 * ---------------------------
 */

#include <stdio.h>

long kaijo(int);

int main(void)
{
    int n;
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));
    return 0;
}
long kaijo(int n)   /* �K�� */
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}
