/*
 * ------------------------------------------
 *      ���[�N���b�h�̌ݏ��@�i�ċA�Łj      *
 * ------------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

int main(void)
{
    int a,b;

    printf("�Q�̐�������͂��Ă�������");
    scanf("%d %d",&a,&b);

    printf("�ő����=%d\n",gcd(a,b));
    return 0;
}
int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}
