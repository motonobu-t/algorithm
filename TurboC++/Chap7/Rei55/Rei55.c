/*
 * ---------------------------------------
 *      �ŒZ�H���i�_�C�N�X�g���@�j     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 8         /* �ߓ_�̐� */
#define M 9999

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0}, /* �אڍs�� */
                 {0,0,1,7,2,M,M,M,M},
                 {0,1,0,M,M,2,4,M,M},
                 {0,7,M,0,M,M,2,3,M},
                 {0,2,M,M,0,M,M,5,M},
                 {0,M,2,M,M,0,1,M,M},
                 {0,M,4,2,M,1,0,M,6},
                 {0,M,M,3,5,M,M,0,2},
                 {0,M,M,M,M,M,6,2,0}};
void main(void)
{
    int j,k,p,start,min,
        leng[N+1],              /* �ߓ_�܂ł̋��� */
        v[N+1];                 /* �m��t���O */

    printf("�n�_ ");scanf("%d",&start);
    for (k=1;k<=N;k++){
        leng[k]=M;v[k]=0;
    }
    leng[start]=0;

    for (j=1;j<=N;j++){
        min=M;          /* �ŏ��̐ߓ_��{�� */
        for (k=1;k<=N;k++){
            if (v[k]==0 && leng[k]<min){
                p=k; min=leng[k];
            }
        }
        v[p]=1;            /* �ŏ��̐ߓ_���m�肷�� */

        if (min==M){
			printf("�O���t�͘A���łȂ�\n");
			exit(1);
		}

		/* �����o�R���Ă��Ɏ��钷��������܂ł̍ŒZ�H��菬������΍X�V */
        for (k=1;k<=N;k++){
            if((leng[p]+a[p][k])<leng[k])
                leng[k]=leng[p]+a[p][k];
        }
    }
    for (j=1;j<=N;j++)
		printf("%d -> %d : %d\n",start,j,leng[j]);
	getchar();getchar();
}

