/*
 * ----------------------------------------
 *     ������̒u�������i���v���C�X�j     *
 * ----------------------------------------
 */

#include <stdio.h>
#include <string.h>

void replace(char *,char *,char *);
char *search(char *,char *);

void main(void)
{
    int k;
    static char text[][128]={"     --- �T���r�A�̉� ---",
                             "���������v���Ă�",
                             "�T���r�A�̉Ԃ����Ȃ��̕����̒���",
                             "�������ꂽ����",
                             "�����ČN�̃x�b�h��",
                             "�T���r�A�̍g���Ԃ����߂�",
                             "�l�͌N�����ʂ܂ŕ������߂Ă��悤��",
                             ""};
    k=0;
    while (text[k][0]!='\0'){
        replace(text[k],"�T���r�A","�� �� �� ��");
        replace(text[k],"�g","��");
        printf("%s\n",text[k]);
        k++;
	}
	getchar();
}
void replace(char *text,char *key,char *rep)
{
    char *p,buf[128];

    p=search(text,key);
    while (p!=NULL){
        *p='\0';
        strcpy(buf,p+strlen(key));
        strcat(text,rep);
        strcat(text,buf);
        p=search(p+strlen(rep),key);
    }
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}

