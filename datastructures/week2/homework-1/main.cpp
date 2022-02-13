//假设称正读和反读都相同的字符序列为“回文”，例如，‘abba’和‘abcba’是回文，‘bcde’和‘abaca’则不是回文，试利用栈作为数据结构，
//编写一个算法判别读入的一个以‘@’为结束符的字符序列是否是“回文” 。
#include<stdio.h>
#define MAXSIZE 100
//定义栈结构体
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
//初始化栈空间
void InitStack(SqStack &s){
    s.base = new SElemType[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
}
//入栈
int push(SqStack s,SElemType e){
    if(s.top-s.base==s.stacksize) return -1;
    *s.top=e;
    *s.top++;
    return 1;
}
//判断回文
int check_huiwen(char c[]){
        SqStack s;
        int i=0;
        int j=1;
        InitStack(s);
        //存入数据
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
        printf("%s是回文！\n",a);
    if(check_huiwen(a)==-1)
        printf("%s不是回文！\n",a);
    printf("\n");
    if(check_huiwen(b)==1)
        printf("%s是回文！\n",b);
    if(check_huiwen(b)==-1)
        printf("%s不是回文！\n",b);
    printf("\n");
    return 0;
}
