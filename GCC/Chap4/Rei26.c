/*
 * -------------------------
 *     �K��v�Z�̍ċA��    *
 * -------------------------
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
long kaijo(int n)   /* �ċA�葱 */
{
    if (n==0)
        return 1L;
    else
        return n*kaijo(n-1);
}
