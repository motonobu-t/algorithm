/*
 * -------------------------------
 *      �Q���T���؂̔z��\��     *
 * -------------------------------
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

int main(void)
{
    struct tnode a[MaxSize]={{  1,"Machilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[12];
    int p;

    printf("Search name --> "); scanf("%s",key);
    p=0;
    while (p!=nil){
        if (strcmp(key,a[p].name)==0){
            printf("������܂���\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* �������؂ֈړ� */
        else
            p=a[p].right;                   /* �E�����؂ֈړ� */
    }
    return 0;
}
