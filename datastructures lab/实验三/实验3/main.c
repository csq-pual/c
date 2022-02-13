#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
//��ʼ��opnd,optr
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
//���ò���
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


//���÷��Ŵ���
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


//��ȡtheta1��theta2֮������ȼ�
char getPriority(char theta1, char theta2)
	{
        //���������ȼ���ϵ
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


//���㺯��
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
//�жϷ���
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
    //��#ѹ��ջ��
    push_trstack(&optr,'#');
	ch=getchar();
	while(ch!='#'||gettop_trstack(&optr)!='#')
	{
        //ѹ������
		if(!isopter(ch))
		{
			push_ndstack(&opnd,ch-'0');
			ch=getchar();
		}
		else
		{
            //�Ƚ����ȼ�
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
