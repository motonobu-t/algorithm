/*
 * -------------------------------------
 *      �����T���@�i�����������Łj     *
 * -------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define N 10       /* �f�[�^���@*/

void main(void)
{
    struct girl {
        char name[20];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i,flag=0;

    printf("��������data ? ");scanf("%s",key);
    for (i=0;i<N;i++){
        if (strcmp(key,a[i].name)==0){
            printf("%s %d\n",a[i].name,a[i].age);
            flag=1;
            break;
        }
    }
    if (flag!=1)
		printf("������܂���ł���\n");
	getchar();getchar();
}

