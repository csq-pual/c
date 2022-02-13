//已知f为单链表的表头指针, 链表中存储的都是整型数据，
//试写出实现下列运算的递归算法：
//1.求链表的结点个数；
//2.求所有整数的平均值。
#include<stdio.h>
#include <stdlib.h>

//结构体
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//初始化
bool InitList(LinkList l){
    l = new LNode;
    l->next=NULL;
    return true;
}
//创建链表
LinkList CreateList(int n,int a[]){
    LNode *p,*r=0,*t=0;
    int i=0;
    for(i;i<n;i++){
            //动态分布储存空间
        p = (LNode*)malloc(sizeof(LNode));
        p->data = a[i];
        p->next = NULL;
        if(!r)
            r=t=p;
        else
            t=t->next=p;
    }
    return r;
}
//递归求链表结点数
int CountNode(LNode *r){
    if(!r)
        return 0;
    else
        return CountNode(h->next)+1;
}
//求平均值
int AverageList(LNode r){
    int sum=0;
    int Average=0;
    int count1=0;
    LNode *p;
    //遍历链表
    for(p=r;p;p=p->next){
        sum=sum+p->data;
        count1++;
    }
    Average = sum/conut1;
    return Average;
}











