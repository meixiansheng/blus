#include <stdio.h>
#include <stdlib.h>

//简单二叉树的遍历，主要锻炼先序遍历，中序遍历，后序遍历
//二叉树的图形详见简单二叉树.png
struct BinaryTree
{
	BinaryTree * leftChild;
	BinaryTree * rightChild;
	char data;
};

void Preorde(BinaryTree * topNode);
void Ldrorde(BinaryTree * topNode);
void Lrdorde(BinaryTree * topNode);

BinaryTree *  CreateBinaryTree()
{
	BinaryTree * A = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * B = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * C = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * D = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * E = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * F = (BinaryTree *)malloc(sizeof(BinaryTree));
	BinaryTree * G = (BinaryTree *)malloc(sizeof(BinaryTree));

	A->data = 'a';
	A->leftChild = B;
	A->rightChild = E;

	B->data = 'b';
	B->leftChild = nullptr;
	B->rightChild = C;

	C->data = 'c';
	C->leftChild = D;
	C->rightChild = nullptr;

    D->data = 'd';
	D->leftChild = nullptr;
	D->rightChild = nullptr;

	E->data = 'e';
	E->leftChild = nullptr;
	E->rightChild = F;

	F->data = 'f';
	F->leftChild = nullptr;
	F->rightChild = G;

	G->data = 'g';
	G->leftChild = nullptr;
	G->rightChild = nullptr;

	return  A;
}

//先序遍历
void Preorde(BinaryTree * topNode)
{  
	if (topNode != nullptr)
	{
		printf("%c\n", topNode->data);

		if (topNode->leftChild)
		{
			Preorde(topNode->leftChild);
		}

		if (topNode->rightChild)
		{
			Preorde(topNode->rightChild);
		}
	}
}

//中序遍历
void Ldrorde(BinaryTree * topNode)
{
	if (topNode != nullptr)
	{  
		if (topNode->leftChild)
		{
			Preorde(topNode->leftChild);
		}

		printf("%c\n", topNode->data);

		if (topNode->rightChild)
		{
			Preorde(topNode->rightChild);
		}
	}
}
//后序遍历
void Lrdorde(BinaryTree * topNode)
{
	if (topNode != nullptr)
	{
		if (topNode->leftChild)
		{
			Preorde(topNode->leftChild);
		}

		if (topNode->rightChild)
		{
			Preorde(topNode->rightChild);
		}

		printf("%c\n", topNode->data);
	}
}

int main()
{  
	BinaryTree * topNode = CreateBinaryTree();

	//Preorde(topNode);
	//Ldrorde(topNode);
	Lrdorde(topNode);
     
    return 0;
}
