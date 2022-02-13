/*
1.  �������Զ���������д洢����д�㷨����������������
*/
#include <stdio.h>
#include <malloc.h>
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild , *rchild;
} BiTNode , *BiTree;

/*����һ�ö�����*/
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

//��������������
int getDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;
	if (T != NULL)
	{
		leftHeight = getDepth(T->lchild);
		rightHeight = getDepth(T->rchild);
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//get������
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
		printf("��������һ��������:\n");
	CreatBiTree(&T);
		printf("\n�����������Ϊ%d\n",getDepth(T));
	getchar() ;
	getchar() ;
}





