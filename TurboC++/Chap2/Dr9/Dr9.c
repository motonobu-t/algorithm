/*
 * -----------------------------
 *      �V���v�\���̒�ϕ�     *
 * -----------------------------
 */

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))   /* ��ϕ��֐� */

void main(void)
{
    int k;
    double a,b,n,h,fo,fe,sum;

    printf("�ϕ���� A,B ? ");
    scanf("%lf %lf",&a,&b);

    n=50;              /* ���`���Ԃ̕����� */
    h=(b-a)/(2*n);     /* ��ԕ� */
    fo=0; fe=0;
    for (k=1;k<=2*n-3;k=k+2){
        fo=fo+f(a+h*k);         /* ����̘a */
        fe=fe+f(a+h*(k+1));     /* �������̘a */
    }
    sum=(f(a)+f(b)+4*(fo+f(b-h))+2*fe)*h/3;
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
	printf("   /%f\n",a);
	getchar();getchar();
}


