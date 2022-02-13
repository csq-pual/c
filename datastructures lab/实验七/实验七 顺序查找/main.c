//实验七 顺序查找
#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int R[],int n,int k)
{
    int i=0;
    while(i<n && R[i]!=k)
    {
        printf("%d",R[i]);
        i++;
    }
    if(i>=n)
        return -1;
    else
    {
        printf("%d",R[i]);
        return i;
    }

}

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k, loc;
  printf("Please input your number: \n");
  scanf("%d", &k);
  loc=SeqSearch(a, 10, k);
  printf("\n");
  printf("通过顺序查找数字的位置为 %d\n ", loc);
  return 0;
}

