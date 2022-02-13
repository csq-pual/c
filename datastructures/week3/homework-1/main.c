/*
1.  二叉树以二叉链表进行存储，编写算法，计算二叉树的深度
*/
#include <stdio.h>
#include <malloc.h>
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild , *rchild;
} BiTNode , *BiTree;

/*创建一棵二叉树*/
void CreatBiTree(BiTree *T)
{

	char ch;
	scanf("%c",&ch);
	if(ch == "#")
		*T = NULL;
	else
	{
		*T = (BiTNode * )malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
}

//计算二叉树的深度
int getDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;
	if (T != NULL)
	{
		leftHeight = getDepth(T->lchild);
		rightHeight = getDepth(T->rchild);
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//get最大深度
		return maxHeight+1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	BiTree T = NULL;
		printf("请您输入一个二叉树:\n");
	CreatBiTree(&T);
		printf("\n二叉树的深度为%d\n",getDepth(T));
	getchar() ;
	getchar() ;
}





