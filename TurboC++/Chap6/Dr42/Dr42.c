/*
 * -----------------------------------
 *      �Q���T���؂ւ̃f�[�^�ǉ�     *
 * -----------------------------------
 */

#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};

int sp=8;               /* �m�[�h�̊i�[���݈ʒu */
struct tnode a[MaxSize]={{  1,"Machilda",  2},
                         {  3,"Candy",  4},
                         {  5,"Rolla"   ,nil},
                         {nil,"Ann"  ,nil},
                         {  6,"Emy"     ,  7},
                         {nil,"Nancy",nil},
                         {nil,"Eluza"   ,nil},
						 {nil,"Lisa" ,nil}};
void main(void)
{
    char key[12];
    int p,old,i;

    printf("New name --> "); scanf("%s",key);
    p=0;                                /* �؂̃T�[�` */
    while (p!=nil){
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* �V�����m�[�h�̐ڑ� */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;

    for (i=0;i<sp;i++)                  /* �m�[�h�E�e�[�u���̕\�� */
		printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);
	getchar();getchar();

}

