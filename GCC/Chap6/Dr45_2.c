/*
 * -----------------------------------------------
 *      �Q���T���؂̃g���o�[�T���i��ċA�Łj     *
 * -----------------------------------------------
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
void treewalk(struct tnode *);

int main(void)
{
    char dat[12];
    struct tnode *root;

    root=NULL;
    while (scanf("%s",dat)!=EOF){
        root=gentree(root,dat);
    }
    treewalk(root);
    return 0;
}
void treewalk(struct tnode *p)   /* �؂̃g���o�[�T���i��ċA�Łj */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)){
        while (q!=NULL){         /* �s���邾�����ɐi�� */
            w[sp++]=q;           /* �e�̈ʒu���X�^�b�N�ɐς� */
            q=q->left;
        }
        sp--;                    /* �P�O�̐e�ɖ߂� */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* �E�֐i�� */
    }
}
struct tnode *gentree(struct tnode *p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(p->name,w)<0)
        p->right=gentree(p->right,w);
    else
        p->left=gentree(p->left,w);
    return p;
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
