#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
}SeqList;

void ListInitiate(SeqList *L)/*初始化顺序表L*/
{
    L->size = 0;/*定义初始数据元素个数*/
}

int ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if(L->size >= MaxSize)
{
        printf("顺序表已满无法插入! \n");
        return 0;
}
    else if(i < 0||i>L->size)
{
        printf("参数i不合法! \n");
        return 0;
}
else
{
    for(j = L->size; j > i; j--) L->list[j+1] = L->list[j-1];/*为插入做准备*/
    L->list[i] = x;/*插入*/
    L->size ++;/*元素个数加1*/
    return 1;
}
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
    int j;
    if(L->size <= 0)
{
        printf("顺序表已空无数据元素可删! \n");
        return 0;
}
    else if(i < 0 || i > L->size-1)
{
        printf("参数i不合法");
        return 0;
}
else
{//此段程序有一处错误

    *x = L->list[i];/*保存删除的元素到参数x中*/
    for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*依次前移*/
    L->size--;/*数据元素个数减1*/
    return 1;
}
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if(i < 0 || i > L.size-1)
{
        printf("参数i不合法! \n");
        return 0;
}
    else
{
        *x = L.list[i];
        return 1;
}
}
void ComBination(SeqList L1,SeqList L2,SeqList *L3){
    int i=0,j=0,k=0;
    while((i!=L1.size)&&(j!=L2.size)){
        if(L1.list[i]<L2.list[j]){
            L3->list[k++] = L1.list[i++];
        }
        else{
            L3->list[k++] = L2.list[j++];
        }
        L3->size++;
    }
    while(i<L1.size){
        L3->list[k++] = L1.list[i++];
        L3->size++;2
        5

    }
    while(j<L2.size){
        L3->list[k++] = L2.list[j++];
        L3->size++;
    }
}
void main(void){
    SeqList myList,L1,L2,L3;
    int i,x,a,b,c;
    ListInitiate(&myList);
    for(i = 0; i < 10; i++)
        ListInsert(&myList, i, i+1);
        ListDelete(&myList, 4, &x);
    for(i = 0; i < ListLength(myList); i++){
        ListGet(myList,i,&x); //此段程序有一处错误
        printf("%d", x);
    }
    ListInitiate(&L1);
    ListInitiate(&L2);
    ListInitiate(&L3);
    for(i = 0; i < 5; i++)
        {printf("请输入L1数据：");
        scanf("%d",&a);
        ListInsert(&L1,i,a);}
    for(i = 0; i < 7; i++)
        {printf("请输入L2数据：");
        scanf("%d",&b);
        ListInsert(&L2,i,b);}
    ComBination(L1,L2,&L3);
    for(i = 0; i < ListLength(L3); i++){
        ListGet(L3,i,&c);
        printf("%d",c);
    }
}
/*
四、实验任务
1.改正上述程序中的错误。
2.编写合并函数，将两个有序线性表合并为一个有序表并在主函数中加以测试。
合并前：
L1: 1 3 5 7 9
L2:2 4 6 8 10 11 13
合并后：
L3:1 2 3 4 5 6 7 8 9 10 11 13
*/
