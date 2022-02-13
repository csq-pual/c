/*
2.��֪ĳ�ö���������������ABCDEFG����������CBEDAFG��
�Ի�����Ӧ�Ķ����������������ĺ������С�

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiNode	//��ʽ�������ṹ
{
	char data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

void BuildTree(BiTree &T, char *Pre_str, char *In_str, int L1, int R1, int L2, int R2)	//����������
{
	//Ϊ���ڵ����ռ䲢��ֵ��ֵ
	T = (BiNode*)malloc(sizeof(BiNode));
	T->data = Pre_str[L1];

	//Ѱ�����������еĸ�ֵλ��
	int In_root;
	for(int i = L2; i <= R2; i++)
	{
		if(Pre_str[L1] == In_str[i])
		{
			In_root = i;
			break;
		}
	}
	//�ж�������������Ƿ����������
	if(In_root - L2 != 0)
	{
		//�ݹ鹹���������������������䣬�ֱ�Ϊǰ���������е�����������
		BuildTree(T->Lchild, Pre_str, In_str, L1 + 1, L1 + In_root - L2, L2, In_root - 1);
	}
	else
		T->Lchild = NULL;

	//�ж����������ұ��Ƿ����������
	if(R2 - In_root != 0)
	{
		//�ݹ鹹���������������������䣬�ֱ�Ϊǰ���������е�����������
		BuildTree(T->Rchild, Pre_str, In_str, R1 - (R2 - In_root) + 1 , R1, In_root + 1, R2);
	}
	else
		T->Rchild = NULL;
}

void PostOrder(BiTree T) //�������������
{
	if(T)
	{
		PostOrder(T->Lchild);
		PostOrder(T->Rchild);
		printf("%c ", T->data);
	}
}

int main()
{
	char Pre_str[30], In_str[30];
	printf("��������������:");
	scanf("%s", Pre_str);
	printf("��������������:");
	scanf("%s", In_str);

	int len1 = strlen(Pre_str);
	int len2 = strlen(In_str);


	BiTree T = NULL;
	BuildTree(T, Pre_str, In_str, 0, len1 - 1, 0, len2 - 1);

	printf("����������ɶ�����:");
	PostOrder(T);
	printf("\n");

	return 0;
}































