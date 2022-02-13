#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
}SeqList;

void ListInitiate(SeqList *L)/*��ʼ��˳���L*/
{
    L->size = 0;/*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
    int j;
    if(L->size >= MaxSize)
{
        printf("˳��������޷�����! \n");
        return 0;
}
    else if(i < 0||i>L->size)
{
        printf("����i���Ϸ�! \n");
        return 0;
}
else
{
    for(j = L->size; j > i; j--) L->list[j+1] = L->list[j-1];/*Ϊ������׼��*/
    L->list[i] = x;/*����*/
    L->size ++;/*Ԫ�ظ�����1*/
    return 1;
}
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
    int j;
    if(L->size <= 0)
{
        printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
        return 0;
}
    else if(i < 0 || i > L->size-1)
{
        printf("����i���Ϸ�");
        return 0;
}
else
{//�˶γ�����һ������

    *x = L->list[i];/*����ɾ����Ԫ�ص�����x��*/
    for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*����ǰ��*/
    L->size--;/*����Ԫ�ظ�����1*/
    return 1;
}
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
    if(i < 0 || i > L.size-1)
{
        printf("����i���Ϸ�! \n");
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
        ListGet(myList,i,&x); //�˶γ�����һ������
        printf("%d", x);
    }
    ListInitiate(&L1);
    ListInitiate(&L2);
    ListInitiate(&L3);
    for(i = 0; i < 5; i++)
        {printf("������L1���ݣ�");
        scanf("%d",&a);
        ListInsert(&L1,i,a);}
    for(i = 0; i < 7; i++)
        {printf("������L2���ݣ�");
        scanf("%d",&b);
        ListInsert(&L2,i,b);}
    ComBination(L1,L2,&L3);
    for(i = 0; i < ListLength(L3); i++){
        ListGet(L3,i,&c);
        printf("%d",c);
    }
}
/*
�ġ�ʵ������
1.�������������еĴ���
2.��д�ϲ��������������������Ա�ϲ�Ϊһ����������������м��Բ��ԡ�
�ϲ�ǰ��
L1: 1 3 5 7 9
L2:2 4 6 8 10 11 13
�ϲ���
L3:1 2 3 4 5 6 7 8 9 10 11 13
*/
