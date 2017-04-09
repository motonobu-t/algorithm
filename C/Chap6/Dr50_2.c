/*
 * -------------------------------------------
 *      �؁i���I�\���j�̃f�B�X�N�ւ̕ۑ�     *
 * -------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define Rec 34L         /* ���R�[�h�E�T�C�Y */
#define Leaf -1         /* �t */
FILE *fp;

struct tnode {
    struct tnode *left;     /* ���̎q�ւ̃|�C���^ */
    char node[30];
    struct tnode *right;    /* �E�̎q�ւ̃|�C���^ */
};

struct tnode *talloc(void);
struct tnode *readtree(struct tnode *);
void writetree(struct tnode *);

int getch(void)
{
    rewind(stdin);
    return getchar();
}

void main(void)
{
    struct tnode *root=NULL,*p,*q1,*q2;
    int c;

    if ((fp=fopen("dbase.dat","r"))==NULL){
        root=talloc();
        printf("�����m�[�h ? ");scanf("%s",root->node);
        root->left=root->right=NULL;
    }
    else {
        root=readtree(root);
        fclose(fp);
    }
    do {
        p=root;                   /* �؂̃T�[�` */
        while (p->left!=NULL){
            printf("\n%s y/n ",p->node);c=getch();
            if (c=='Y' || c=='y')
                p=p->left;
            else
                p=p->right;
        }

        printf("\n������ %s �ł��B\n�������ł��� y/n ",p->node);
        c=getch();

        if (c=='n' || c=='N'){          /* �w�K�@�\ */
            q1=talloc(); *q1=*p;        /* �m�[�h�̈ړ� */

            q2=talloc();                /* �V�����m�[�h�̍쐬 */
            printf("\n���Ȃ��̍l���� ? ");scanf("%s",q2->node);
            q2->left=q2->right=NULL;
                                        /* ����m�[�h�̍쐬 */
            printf("%s �� %s ����ʂ��鎿��� ? ",q1->node,q2->node);
            scanf("%s",p->node);
            printf("�������̍��ڂ� %s �ŗǂ��ł��� y/n ",q1->node);
            c=getch();
            if (c=='Y' || c=='y'){      /* �q�̐ڑ� */
                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (printf("\n�����܂��� y/n "), c=getch(),c=='Y' || c=='y');
    printf("\n");
    if ((fp=fopen("dbase.dat","w"))!=NULL){
        writetree(root);
        fclose(fp);
    }
}
struct tnode *readtree(struct tnode *p)    /* �t�@�C������؂����[�h */
{
    int flag;

    p=talloc();
    fscanf(fp,"%30s%4d",p->node,&flag);
    if (flag==Leaf)
        p->left=p->right=NULL;
    else{
        p->left=readtree(p->left);
        p->right=readtree(p->right);
    }
    return p;
}
void writetree(struct tnode *p)      /* �t�@�C���ɖ؂����C�g */
{
    if (p!=NULL){
        if (p->left==NULL)
            fprintf(fp,"%30s%4d",p->node,Leaf);
        else
            fprintf(fp,"%30s%4d",p->node,!Leaf);
        writetree(p->left);
        writetree(p->right);
    }
}
struct tnode *talloc(void)           /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
