/*
 * -------------------------
 *      ‹Rm„—ğ‚Ì–â‘è     *
 * -------------------------
 */

#include <stdio.h>

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    /* ”Õ–Ê */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* ‹Rm‚ÌˆÚ“®‚˜¬•ª */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* ‹Rm‚ÌˆÚ“®‚™¬•ª */

void main(void)
{
    int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* ”Õ–Ê */
            else
                m[i][j]=1;      /* •Ç */

    backtrack(2,2);
}
void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;  /* staticw’è•K—v */

    if (m[x][y]==0){
        m[x][y]=++count;         /* –K–â‡”Ô‚Ì‹L˜^ */
        if (count==N*N){
            printf("\n‰ğ%d\n",++num);    /* ‰ğ‚Ì•\¦ */
            for (i=2;i<=N+1;i++){
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
        }
        else
            for (k=0;k<8;k++)           /* i‚ŞˆÊ’u‚ğ‘I‚Ô */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* ‚P‚Â‘O‚É–ß‚é */
        count--;
    }
}
