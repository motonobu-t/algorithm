/*
 * ---------------------------------------
 *      �D�揇�ʃp�[�W���O�i���ږ@�j     *
 * ---------------------------------------
 */

#include <stdio.h>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

double v[50];        /* �v�Z�p�X�^�b�N */
char ope[50];        /* ���Z�q�p�X�^�b�N */
int pri[256];        /* �D�揇�ʕ\ */
int sp1,sp2;         /* �X�^�b�N�E�|�C���^ */

void calc(void);

int main(void)
{
    char *expression="(1>2|2<8|3<4)|(9<2)",*p=expression;

    pri['|']=1; pri['<']=pri['>']=2;
    pri['(']=3; pri[')']=0;

    ope[0]=0; pri[0]=-1;        /* �ԕ� */
    sp1=sp2=0;
    while  (*p!='\0'){
        if ('0'<=*p && *p<='9')
            v[++sp2]=*p-'0';
        else {
            while (pri[*p]<=pri[ope[sp1]] && ope[sp1]!='(')
                calc();
            if (*p!=')')
                ope[++sp1]=*p;
            else
                sp1--;      /* �i����菜�� */
        }
        p++;
    }
    while (sp1>0)           /* ���Z�q�X�^�b�N����ɂȂ�܂� */
        calc();
    printf("%s=%f\n",expression,v[1]);
    return 0;
}
void calc(void)             /* ���Z���� */
{
    switch (ope[sp1]) {
        case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2;break;
        case '>' : v[sp2-1]=Max(v[sp2-1],v[sp2]);break;
        case '<' : v[sp2-1]=Min(v[sp2-1],v[sp2]);break;
    }
    sp2--; sp1--;
}
