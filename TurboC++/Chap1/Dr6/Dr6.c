/*
 * ---------------------------------
 *      ���[�N���b�h�̌ݏ��@       *
 * ---------------------------------
 */

#include <stdio.h>

void main(void)
{
    int a,b,m,n,k;

    printf("��̐�������͂��Ă������� ");
    scanf("%d %d",&a,&b);

    m=a; n=b;
    do{
        k=m % n;
        m=n; n=k;
    } while(k!=0);
	printf("�ő����=%d\n",m);
	getchar();getchar();
}

