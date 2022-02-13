//如果希望循环队列中的元素都能得到利用，则需要设置一个标志域 tag，并以 tag 的值为 0 或 1 来区分，
//尾指针和头指针相同时的队列状态是“空”还是“满”。试编写与此结构相应的入队列和出队列的算法。
#include<stdio.h>
#define MAXSIZE 100
//结构体
typedef struct{
    int front;
    int rear;
    int tag;
    int data[MAXSIZE];
}Queue;
//初始化
int Initqueue(Queue &q){
    q.tag = 0;
    q.front = 0;
    q.rear = 0;
}
//判断栈空
bool Isempty(Queue q){
    if(q.front==q.rear&&q.tag==0){
        return true;}
    return false;
}
//判断栈满
bool Isfull(Queue q){
    if(q.front==q.rear&&q.tag==1){
        return true;
    }
    return false;
}
//入栈
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
//出栈
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

