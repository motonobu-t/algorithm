/*
 * ------------------------------------------
 *      ���[�N���b�h�̌ݏ��@�i�ċA�Łj      *
 * ------------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

void main(void)
{
    int a,b;

    printf("�Q�̐�������͂��Ă�������");
    scanf("%d %d",&a,&b);

    printf("�ő����=%d\n",gcd(a,b));
}
int gcd(int m,int n)
{
    if (m==n)
        return m;
    if (m>n)
        return gcd(m-n,n);
    else
        return gcd(m,n-m);
}
