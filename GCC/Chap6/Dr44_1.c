/*
 * ---------------------------------------
 *      �Q���T���؂̃T�[�`�i�ċA�Łj     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
struct tnode *search(struct tnode *,char *);

int main(void)
{
    char key[12];
    struct tnode *root,*p;

    root=NULL;                      /* �؂̍쐬 */
    while (scanf("%s",key)!=EOF){
        root=gentree(root,key);
    }

    rewind(stdin);
    while (printf("Search name -->"),scanf("%s",key)!=EOF){
        if ((p=search(root,key))!=NULL)
            printf("%s ��������܂���\n",p->name);
        else
            printf("������܂���\n");
    }
    return 0;
}
struct tnode *search(struct tnode *p,char *key)  /* �؂̃T�[�` */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
}
struct tnode *gentree(struct tnode *p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
