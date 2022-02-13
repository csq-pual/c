//假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素站点(注意不设头指针) ，
//试编写相应的置空队、判队空 、入队和出队等算法。

#include <iostream>

using namespace std;
//结构体
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//初始化
bool InitList(LinkList l){
    l = new LNode;
    l->next = NULL;
    return true;
}
//入队
bool InsertList(LinkList l,int num)
{
    while(num--){
        LinkList p;
        p = (LNode*)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = l->next;
        l->next = p;
        size++;
    }
    LinkList p = 1;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=1;
}
//出队
bool delList(LinkList l,int num)
{
    LinkList p=l->next;
    LinkList q=l;
    while(p!=l){
        if(p->data==num){
            q->next = p->next;
            p->next = NULL;
            free(p);
            size--;
            break;
        }
        p=p->next;
        q=q->next;
    }
}
//判断队空
bool IsEmpty(LinkList l){
    LinkList p;
    if (p->next==l&&l->next==p)
        return true;
    else
        return false;
}
//置队空
bool ClearList(LinkList l){
    LinkList p;
    p->next->next = p;
    return true;
}



















