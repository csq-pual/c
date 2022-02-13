#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
//初始化opnd,optr
typedef struct
{
	int top;
	int OPND[50];
}opnd_stack;

typedef struct
{
	int top;
	char OPTR[50];
}optr_stack;

void init_ndstack(opnd_stack *s)
{
	s->top=-1;
}
void init_trstack(optr_stack *s)
{
	s->top=-1;
}
//设置操作
void push_ndstack(opnd_stack *s,int n)
{
	s->OPND[++s->top]=n;
}
void push_trstack(optr_stack *s,char n)
{
	s->OPTR[++s->top]=n;
}

int pop_ndstack(opnd_stack *s)
{
	if(s->top<=-1) return -1;
	else return  s->OPND[s->top--];
}
char pop_trstack(optr_stack *s)
{
	if(s->top<=-1) return -1;
	else return s->OPTR[s->top--];
}
int gettop_ndstack(opnd_stack *s)
{
	return s->OPND[s->top];
}
char gettop_trstack(optr_stack *s)
{
	return s->OPTR[s->top];
}


//设置符号代号
int getIndex(char theta)
{
    int index = 0;
    switch (theta)
    {
    case'+':
        index=0;
        break;
    case'-':
        index=1;
        break;
    case'*':
        index=2;
        break;
    case'/':
        index=3;
        break;
    case'(':
        index=4;
        break;
    case')':
        index=5;
        break;
    case'#':
        index=6;
        break;

    default:
        break;
    }
    return index;
}


//获取theta1与theta2之间的优先级
char getPriority(char theta1, char theta2)
	{
        //算符间的优先级关系
	    const char priority[][7] =
	    {
	        { '>','>','<','<','<','>','>' },
	        { '>','>','<','<','<','>','>' },
	        { '>','>','>','>','<','>','>' },
	        { '>','>','>','>','<','>','>' },
	        { '<','<','<','<','<','=','0' },
	        { '>','>','>','>','0','>','>' },
            { '<','<','<','<','<','0','=' },
	    };

	    int index1 = getIndex(theta1);
	    int index2 = getIndex(theta2);
	    return priority[index1][index2];
	}


//计算函数
int calculate(int num1,char x,int num2){
    switch (x)
    {
    case '+':
        return num1+num2;
        break;
    case '-':
        return num1-num2;
        break;
    case '*':
        return num1*num2;
        break;
    case '/':
        return num1/num2;
        break;
    default:
        break;
    }
    return -1;
}
//判断符号
int isopter(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='#') return 1;
	else {return 0;}
}
int main(){
    char c,ch;
	int x1,x2;
	int i=0;
	opnd_stack opnd;
	optr_stack optr;
	init_ndstack(&opnd);
	init_trstack(&optr);
    //将#压入栈底
    push_trstack(&optr,'#');
	ch=getchar();
	while(ch!='#'||gettop_trstack(&optr)!='#')
	{
        //压入数字
		if(!isopter(ch))
		{
			push_ndstack(&opnd,ch-'0');
			ch=getchar();
		}
		else
		{
            //比较优先级
			switch(getPriority(optr.OPTR[optr.top],ch))
			{
			case'<':
				push_trstack(&optr,ch);
				ch=getchar();
				break;
			case'=':
				pop_trstack(&optr);
				ch=getchar();
				break;
			case'>':
				x1=pop_ndstack(&opnd);
				x2=pop_ndstack(&opnd);
				c=pop_trstack(&optr);
				push_ndstack(&opnd,calculate(x1,c,x2));
				break;
			}

		}
		++i;
	}
	printf("%d",-gettop_ndstack(&opnd));
	return 1;
}
