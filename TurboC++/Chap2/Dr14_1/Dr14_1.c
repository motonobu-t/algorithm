/*
 * -----------------------
 *      ���̑����v�Z     *
 * -----------------------
 */

#include <stdio.h>

void ladd(short *,short *,short *);
void lsub(short *,short *,short *);
void ldiv(short *,short,short *);
void printresult(short *);

#define L 1000          /* ���߂錅��      */
#define L1 ((L/4)+1)    /* �z��̃T�C�Y    */
#define L2 (L1+1)       /* ��]���Ɏ��  */
#define N 451           /* �v�Z���鍀��    */

void main(void)
{
    short s[L2+2],w[L2+2];
    short k;
    for (k=0;k<=L2;k++)
        s[k]=w[k]=0;

    s[0]=w[0]=1;
    for (k=1;k<=N;k++){
        ldiv(w,k,w);
        ladd(s,w,s);
    }
	printresult(s);
	getchar();
}
void printresult(short c[])       /* ���ʂ̕\�� */
{
    short i;
    printf("%3d. ",c[0]);         /* �ŏ�ʌ��̕\�� */
    for (i=1;i<L1;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])
{
    short i,brrw=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void ldiv(short a[],short b,short c[])    /* �����O�����V���[�g�� */
{
    short i;long d,rem=0;
    for (i=0;i<=L2;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}

