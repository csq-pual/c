//�����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���βԪ��վ��(ע�ⲻ��ͷָ��) ��
//�Ա�д��Ӧ���ÿնӡ��жӿ� ����Ӻͳ��ӵ��㷨��

#include <iostream>

using namespace std;
//�ṹ��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//��ʼ��
bool InitList(LinkList l){
    l = new LNode;
    l->next = NULL;
    return true;
}
//���
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
//����
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
//�ж϶ӿ�
bool IsEmpty(LinkList l){
    LinkList p;
    if (p->next==l&&l->next==p)
        return true;
    else
        return false;
}
//�öӿ�
bool ClearList(LinkList l){
    LinkList p;
    p->next->next = p;
    return true;
}



















