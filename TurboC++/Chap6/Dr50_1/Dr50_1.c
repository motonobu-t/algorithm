/*
 * ---------------------------------------
 *      ���^�����ƌ���؁i���I�\���j     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    struct tnode *left;        /* ���̎q�ւ̃|�C���^ */
    char node[30];
    struct tnode *right;       /* �E�̎q�ւ̃|�C���^ */
};
struct tnode *talloc(void);

int getch(void)
{
	rewind(stdin);
	return getchar();
}

void main(void)
{
    struct tnode *root,*p,*q1,*q2;
    int c;

    root=talloc();
    printf("�����m�[�h ? ");scanf("%s",root->node);
    root->left=root->right=NULL;
    do {
        p=root;                             /* �؂̃T�[�` */
        while (p->left!=NULL){
            printf("\n%s y/n ",p->node);c=getch();
            if (c=='Y' || c=='y')
                p=p->left;
            else
                p=p->right;
        }

        printf("\n������ %s �ł��B\n�������ł��� y/n ",p->node);
        c=getch();

        if (c=='n' || c=='N'){                         /* �w�K�@�\ */
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
}
struct tnode *talloc(void)            /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

