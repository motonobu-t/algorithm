/*
 * ------------------------------
 *      �n�m�C�̓��̍ċA��      *
 * ------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char,char);

int main(void)
{
    int n;
    printf("�~�Ղ̖��� ? ");
    scanf("%d",&n);

    hanoi(n,'a','b','c');
    return 0;
}
void hanoi(int n,char a,char b,char c)  /* �ċA�葱 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}
