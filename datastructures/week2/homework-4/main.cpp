//��֪fΪ������ı�ͷָ��, �����д洢�Ķ����������ݣ�
//��д��ʵ����������ĵݹ��㷨��
//1.������Ľ�������
//2.������������ƽ��ֵ��
#include<stdio.h>
#include <stdlib.h>

//�ṹ��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//��ʼ��
bool InitList(LinkList l){
    l = new LNode;
    l->next=NULL;
    return true;
}
//��������
LinkList CreateList(int n,int a[]){
    LNode *p,*r=0,*t=0;
    int i=0;
    for(i;i<n;i++){
            //��̬�ֲ�����ռ�
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
//�ݹ�����������
int CountNode(LNode *r){
    if(!r)
        return 0;
    else
        return CountNode(h->next)+1;
}
//��ƽ��ֵ
int AverageList(LNode r){
    int sum=0;
    int Average=0;
    int count1=0;
    LNode *p;
    //��������
    for(p=r;p;p=p->next){
        sum=sum+p->data;
        count1++;
    }
    Average = sum/conut1;
    return Average;
}











