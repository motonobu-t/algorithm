//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei21.h"
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
 * ---------------------
 *      ２分探索法     *
 * ---------------------
 */

#include "turboform.h"

#define N 10       /* データ数　*/
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid,flag=0;

	tinit();cls();
	key=stoi(Edit1->Text);

	low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]==key){
            printf("%d は %d 番目にありました\n",a[mid],mid);
            flag=1;
            break;
        }
        if (a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    if (flag!=1)
        printf("見つかりませんでした\n");

}
//---------------------------------------------------------------------------
