#include <stdio.h>
#include <stdlib.h>

int BinSearch(int R[], int n, int k)
{
    int low=0,high=n-1,mid,count=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        printf("第%d次查找：在[ %d ,%d]中找到元素R[%d]:%d\n ",++count,low,high,mid,R[mid]);
        if(R[mid]==k)
            return mid;
        if(R[mid]>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k, loc;
    printf("Please input your number: \n");
    scanf("%d", &k);
    loc=BinSearch(a, 10, k);
    if(loc == -1)
        printf("not find!");
    return 0;
}
