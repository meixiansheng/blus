#include <stdio.h>
#include <stdlib.h>

//链表的结构
typedef struct  MyList
{
	int data;//每个结点存储的值
	MyList * nextAdrr; //每个结点下一个结点的值
}Node,*pNode;

//初始化链表
Node* InitList();
//在链表最后一个位置添加一个结点
Node* InsetLastPos(Node* p,int val);

//删除链表第一个结点
Node* delFirsrNode(Node * pHead);
//在链表pos位置插入值为data的结点
Node * insertNodePos(Node* p, int val, int pos);

//删除链表中位置pos的结点
Node * delPos(Node* pHeard,int pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL
Node * findNode(Node* pHeard, int data);

//移除链表中第一个值为data的元素
Node * delDataNode(Node* pHeard,int data,bool bSucced);

// 获取链表中有效节点的个数 
int GetVaildNode(Node* pHeard);

// 销毁链表 
void destory(Node* pHeard);

//反转链表
Node * Reverse(Node* pHeard);

void Show(Node* pHeard);
//双向链表


//初始化链表
Node* InitList()
{
	//1.创建一个头结点
	Node * pHead = (Node *)malloc(sizeof(Node));
	if (!pHead)
	{
		printf("%s\n", "初始化头结点失败!");
		return nullptr;
	}

	pHead->nextAdrr = nullptr;

	return pHead;
}

Node * insertNodePos(Node* p,int val,int pos)
{
	Node * pNew = (Node*)malloc(sizeof(Node));
	if (!pNew)
	{
		printf("%s\n", " malloc new node failed.");
		return p;
	}

	Node * tmp = p;
	for (int i = 1;i<pos;++i)
	{
		if (tmp == nullptr)
		{
			printf("%s\n", "插入位置无效...");
			return p;
		}

		tmp = tmp->nextAdrr;
	}

	Node * tmpNext = tmp->nextAdrr;
	tmp->nextAdrr = pNew;
	pNew->nextAdrr = tmpNext;

	pNew->data = val;

	return p;
}

Node* InsetLastPos(Node* p,int val)
{
	Node * pNew = (Node*)malloc(sizeof(Node));
	if (!pNew)
	{
		printf("%s\n", " malloc new node failed.");
		return p;
	}

	//找到最后一个结点位置
	Node * tmp = p;
	while (tmp->nextAdrr != nullptr)
	{
		tmp = tmp->nextAdrr;
	}

	tmp->nextAdrr = pNew;
	pNew->nextAdrr = nullptr;
	pNew->data = val;

	return p;
}

Node* delFirsrNode(Node * pHead)
{
	Node * pFirst = pHead->nextAdrr;
	pHead->nextAdrr = pFirst->nextAdrr;

	free(pFirst);
	pFirst = nullptr;

	return pHead;
}

//删除链表中位置pos的结点
Node * delPos(Node* pHeard, int pos)
{   
	Node* pCurrent = nullptr;
	Node * tmp = pHeard;
	for (int i = 0;i<pos-1;++i)
	{
		tmp = tmp->nextAdrr;
	}

	pCurrent = tmp->nextAdrr;
	tmp->nextAdrr = pCurrent->nextAdrr;
	free(pCurrent);
	pCurrent = nullptr;

	return pHeard;
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL
Node * findNode(Node* pHeard, int data)
{
	//找到最后一个结点位置
	Node * tmp = pHeard;
	while (tmp->nextAdrr != nullptr)
	{
		tmp = tmp->nextAdrr;

		if (tmp->data == data)
		{
			return tmp;
		}
	}
    
	Node * Last = tmp->nextAdrr;
	if (Last->data == data)
	{
		return Last;
	}

	return nullptr;
}

//移除链表中第一个值为data的元素
Node * delDataNode(Node* pHeard, int data, bool bSucced)
{   
	bSucced = false;
	//找到最后一个结点位置
	Node * tmp = pHeard;
	while (tmp->nextAdrr != nullptr)
	{
		tmp = tmp->nextAdrr;
		if (tmp->nextAdrr->data == data)
		{ 
			Node * pCurrent = tmp->nextAdrr;
			tmp->nextAdrr = pCurrent->nextAdrr->nextAdrr;
			free(pCurrent);
			pCurrent = NULL;
			bSucced = true;
			return pHeard;
		}
	}

	Node * Last = tmp->nextAdrr;
	if (Last->data == data)
	{
		Node * pCurrent = tmp->nextAdrr;
		tmp->nextAdrr = nullptr;
		free(pCurrent);
		pCurrent = NULL;
		bSucced = true;
	}
	
	return pHeard;
}

// 获取链表中有效节点的个数 
int GetVaildNode(Node* pHeard)
{
	int iLength = 0;

	//找到最后一个结点位置
	Node * tmp = pHeard;
	while (tmp->nextAdrr != nullptr)
	{
		tmp = tmp->nextAdrr;
		++iLength;
	}

	return iLength;
}

// 销毁链表 
void destory(Node* pHeard)
{   
	//找到最后一个结点位置
	Node * pCurrent;
	while (pHeard->nextAdrr != nullptr)
	{   
		pCurrent = pHeard->nextAdrr;
		pHeard = pCurrent->nextAdrr;
		free(pCurrent);
		pCurrent = nullptr;
	}

	pHeard = nullptr;
}

//反转链表
Node * Reverse(Node* pHeard)
{
	//1.迭代法重构链表，将旧链表的结点插入到新链表中
	Node * NewList = (Node*)malloc(sizeof(Node));
	//初始化新的头节点的数据
	NewList->data = pHeard->data;
	NewList->nextAdrr = nullptr;

	Node *  tmp = nullptr;
	while (pHeard->nextAdrr != NULL)
	{
		tmp = NewList->nextAdrr;
		NewList->nextAdrr = pHeard->nextAdrr;
		pHeard->nextAdrr = pHeard->nextAdrr->nextAdrr; //断开之前的结点
		NewList->nextAdrr->nextAdrr = tmp;
	}

	free(pHeard);
	pHeard = nullptr;
	return NewList;
	Node * newHead;

	///////////////////////////////////////////// 递归法
	//!!!存在问题是倒序没有最好一个结点
	//if (!pHeard || pHeard->nextAdrr == nullptr)
	//{   
	//	return pHeard;
	//}
	//
	//newHead = Reverse(pHeard->nextAdrr);

	//pHeard->nextAdrr->nextAdrr = pHeard;
	//pHeard->nextAdrr = nullptr;

	//return newHead;
}

void Show(Node* pHeard)
{   
	if (pHeard->nextAdrr == nullptr || !pHeard)
	{
		return;
	}

	Node*tmp = pHeard;
	while (tmp->nextAdrr != nullptr)
	{
		printf("%d ", tmp->nextAdrr->data);
		tmp = tmp->nextAdrr;
	}
}

int main()
{   
	Node* pHeard = nullptr;
	Node* pData = nullptr;

	///初始化链表
	pHeard = InitList();
	/////////
	//在链表最后一个位置添加一个结点
	pHeard = InsetLastPos(pHeard,1);

	pHeard = InsetLastPos(pHeard, 2);

	pHeard = InsetLastPos(pHeard, 3);

	pHeard = InsetLastPos(pHeard, 4);

	pHeard = InsetLastPos(pHeard, 5);

	pHeard = InsetLastPos(pHeard, 6);

	Show(pHeard);

	printf("\n");

	////删除链表第一个结点
	pHeard = delFirsrNode(pHeard);

	printf("删除链表第一个结点后");
	printf("\n");

	Show(pHeard);

	//在链表pos位置插入值为data的结点
    pHeard = insertNodePos(pHeard, 1,1);

	printf("\n");

	Show(pHeard);

	//反转链表
	Node* newHeard = Reverse(pHeard);
	printf("\n");
	Show(newHeard);
	
	// 获取链表中有效节点的个数 
	int iNumber = GetVaildNode(newHeard);
	printf("\n");
	printf("%d", iNumber);


	// 销毁链表 
	destory(newHeard);

	printf("\n");
	Show(newHeard);

	
	return 0;
}