//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr66ListBox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
 * -------------------------
 *      ãRémèÑóÇÃñ‚ëË     *
 * -------------------------
 */

#include <stdio.h>
#define N 5

int m[N+4][N+4],                    /* î’ñ  */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* ãRémÇÃà⁄ìÆÇòê¨ï™ */
	dy[8]={1,2,2,1,-1,-2,-2,-1};    /* ãRémÇÃà⁄ìÆÇôê¨ï™ */

AnsiString outstr;		//Å@ÇPçsèoóÕóp
char cbuf[100];		//	èëéÆïœä∑óp

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* ñKñ‚èáî‘ÇÃãLò^ */
		if (count==N*N){
			sprintf(cbuf,"â%3d",++num); /* âÇÃï\é¶ */
			Form1->ListBox1->AddItem(AnsiString(cbuf),NULL);
			for (i=2;i<=N+1;i++){
				outstr="";
				for (j=2;j<=N+1;j++){
					sprintf(cbuf,"%4d",m[i][j]); /* âÇÃï\é¶ */
					outstr+=AnsiString(cbuf);
				}
				Form1->ListBox1->AddItem(outstr,NULL);
			}
        }
        else
            for (k=0;k<8;k++)           /* êiÇﬁà íuÇëIÇ‘ */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* ÇPÇ¬ëOÇ…ñﬂÇÈ */
        count--;
    }
}

	void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* î’ñ  */
            else
                m[i][j]=1;      /* ï« */

    backtrack(2,2);

}
//---------------------------------------------------------------------------
