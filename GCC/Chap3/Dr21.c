/*
 * --------------------
 *     �Q���T���@     *
 * --------------------
 */

#include <stdio.h>

#define N 10       /* �f�[�^���@*/

int main(void)
{
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;

    printf("��������data ? ");scanf("%d",&key);

    low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }
    if (low==high+2)
        printf("%d �� %d �Ԗڂɂ���܂���\n",a[mid],mid);
    else
        printf("������܂���ł���\n");
    return 0;
}
