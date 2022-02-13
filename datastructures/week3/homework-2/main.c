/*
2.已知某棵二叉树的先序序列ABCDEFG，中序序列CBEDAFG，
试画出对应的二叉树，并给出它的后序序列。

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiNode	//链式二叉树结构
{
	char data;
	struct BiNode *Lchild, *Rchild;
}BiNode, *BiTree;

void BuildTree(BiTree &T, char *Pre_str, char *In_str, int L1, int R1, int L2, int R2)	//构建二叉树
{
	//为根节点分配空间并赋值根值
	T = (BiNode*)malloc(sizeof(BiNode));
	T->data = Pre_str[L1];

	//寻找中序序列中的根值位置
	int In_root;
	for(int i = L2; i <= R2; i++)
	{
		if(Pre_str[L1] == In_str[i])
		{
			In_root = i;
			break;
		}
	}
	//判断中序序列左边是否存在子序列
	if(In_root - L2 != 0)
	{
		//递归构建左子树，包含两个区间，分别为前序、中序序列的左子树区间
		BuildTree(T->Lchild, Pre_str, In_str, L1 + 1, L1 + In_root - L2, L2, In_root - 1);
	}
	else
		T->Lchild = NULL;

	//判断中序序列右边是否存在子序列
	if(R2 - In_root != 0)
	{
		//递归构建右子树，包含两个区间，分别为前序、中序序列的右子树区间
		BuildTree(T->Rchild, Pre_str, In_str, R1 - (R2 - In_root) + 1 , R1, In_root + 1, R2);
	}
	else
		T->Rchild = NULL;
}

void PostOrder(BiTree T) //后序遍历二叉树
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
	printf("请输入先序序列:");
	scanf("%s", Pre_str);
	printf("请输入中序序列:");
	scanf("%s", In_str);

	int len1 = strlen(Pre_str);
	int len2 = strlen(In_str);


	BiTree T = NULL;
	BuildTree(T, Pre_str, In_str, 0, len1 - 1, 0, len2 - 1);

	printf("后序遍历生成二叉树:");
	PostOrder(T);
	printf("\n");

	return 0;
}































