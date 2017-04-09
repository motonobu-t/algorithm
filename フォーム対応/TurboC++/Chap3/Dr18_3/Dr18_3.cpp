//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr18_3.h"
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
 * -------------------------------
 *      ポインタをソートする     *
 * -------------------------------
 */

#include "turboform.h"

#define N 10
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct girl {
        char *name;
        int age;
    } *t,*p[N],a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
                    "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char *min;
    int s,i,j;

    for (i=0;i<N;i++)     /* データをポインタで指し示す */
        p[i]=&a[i];

    for (i=0;i<N-1;i++){
        min=p[i]->name;
        s=i;
        for (j=i+1;j<N;j++){
            if (strcmp(p[j]->name,min)<0){
                min=p[j]->name;
                s=j;
            }
        }
        t=p[i]; p[i]=p[s]; p[s]=t;    /* ポインタの交換 */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%10s%4d\n",p[i]->name,p[i]->age);

}
//---------------------------------------------------------------------------
