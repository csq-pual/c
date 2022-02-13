//���ϣ��ѭ�������е�Ԫ�ض��ܵõ����ã�����Ҫ����һ����־�� tag������ tag ��ֵΪ 0 �� 1 �����֣�
//βָ���ͷָ����ͬʱ�Ķ���״̬�ǡ��ա����ǡ��������Ա�д��˽ṹ��Ӧ������кͳ����е��㷨��
#include<stdio.h>
#define MAXSIZE 100
//�ṹ��
typedef struct{
    int front;
    int rear;
    int tag;
    int data[MAXSIZE];
}Queue;
//��ʼ��
int Initqueue(Queue &q){
    q.tag = 0;
    q.front = 0;
    q.rear = 0;
}
//�ж�ջ��
bool Isempty(Queue q){
    if(q.front==q.rear&&q.tag==0){
        return true;}
    return false;
}
//�ж�ջ��
bool Isfull(Queue q){
    if(q.front==q.rear&&q.tag==1){
        return true;
    }
    return false;
}
//��ջ
bool enQueue(Queue q,int n){
    if(Isfull(q)){
        return false;
    }
    else
        q.data[q.rear] = n;
        q.rear = (q.rear+1)%MAXSIZE;
    if(q.front==q.rear){
        q.tag = 1;
    }
    return true;
}
//��ջ
bool deQueue(Queue q){
    int n;
    if(Isempty(q)){
        return false;
    }
    else
        n = q.data[q.front];
        q.front = (q.front+1)%MAXSIZE;
        if (Isempty(q)){
            q.tag = 0;
        }
        return true;
}
void print_Queue(Queue q){
    int i=0;
        for (i;i<=(q.rear-q.front+MAXSIZE)%MAXSIZE;i++)
        {
            printf("%d",q.data[i]);
        }
}
int main(){
    Queue q;
    Initqueue(q);
    enQueue(q,1);
    enQueue(q,5);
    deQueue(q);
    print_Queue(q);
}

