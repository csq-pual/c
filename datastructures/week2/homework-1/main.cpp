//����������ͷ�������ͬ���ַ�����Ϊ�����ġ������磬��abba���͡�abcba���ǻ��ģ���bcde���͡�abaca�����ǻ��ģ�������ջ��Ϊ���ݽṹ��
//��дһ���㷨�б�����һ���ԡ�@��Ϊ���������ַ������Ƿ��ǡ����ġ� ��
#include<stdio.h>
#define MAXSIZE 100
//����ջ�ṹ��
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
//��ʼ��ջ�ռ�
void InitStack(SqStack &s){
    s.base = new SElemType[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}
//��ջ
int push(SqStack s,SElemType e){
    if(s.top-s.base==s.stacksize) return -1;
    *s.top=e;
    *s.top++;
    return 1;
}
//�жϻ���
int check_huiwen(char c[]){
        SqStack s;
        int i=0;
        int j=1;
        InitStack(s);
        //��������
        for (i;c[i]!='@';i++){
            push(s,c[i]);
        }
        if (s.top!=s.base)
            j=-1;
        while(s.base==s.top){
                *s.top--;
                *s.base++;
                if (s.base == s.top){
                    continue;
                }
                if(s.base != s.top){
                    j=-1;
                    break;
                }
            }
        return j;
}
int main(int argc, char *argv[]){
    char *a = "abcdcba@";
    char *b = "sadbfsdsoefyw@";
    if (check_huiwen(a)==1)
        printf("%s�ǻ��ģ�\n",a);
    if(check_huiwen(a)==-1)
        printf("%s���ǻ��ģ�\n",a);
    printf("\n");
    if(check_huiwen(b)==1)
        printf("%s�ǻ��ģ�\n",b);
    if(check_huiwen(b)==-1)
        printf("%s���ǻ��ģ�\n",b);
    printf("\n");
    return 0;
}
