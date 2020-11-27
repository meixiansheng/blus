#include <stdio.h>
#include <stdlib.h>

//����Ľṹ
typedef struct  MyList
{
	int data;//ÿ�����洢��ֵ
	MyList * nextAdrr; //ÿ�������һ������ֵ
}Node,*pNode;

//��ʼ������
Node* InitList();
//���������һ��λ�����һ�����
Node* InsetLastPos(Node* p,int val);

//ɾ�������һ�����
Node* delFirsrNode(Node * pHead);
//������posλ�ò���ֵΪdata�Ľ��
Node * insertNodePos(Node* p, int val, int pos);

//ɾ��������λ��pos�Ľ��
Node * delPos(Node* pHeard,int pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL
Node * findNode(Node* pHeard, int data);

//�Ƴ������е�һ��ֵΪdata��Ԫ��
Node * delDataNode(Node* pHeard,int data,bool bSucced);

// ��ȡ��������Ч�ڵ�ĸ��� 
int GetVaildNode(Node* pHeard);

// �������� 
void destory(Node* pHeard);

//��ת����
Node * Reverse(Node* pHeard);

void Show(Node* pHeard);
//˫������


//��ʼ������
Node* InitList()
{
	//1.����һ��ͷ���
	Node * pHead = (Node *)malloc(sizeof(Node));
	if (!pHead)
	{
		printf("%s\n", "��ʼ��ͷ���ʧ��!");
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
			printf("%s\n", "����λ����Ч...");
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

	//�ҵ����һ�����λ��
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

//ɾ��������λ��pos�Ľ��
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

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL
Node * findNode(Node* pHeard, int data)
{
	//�ҵ����һ�����λ��
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

//�Ƴ������е�һ��ֵΪdata��Ԫ��
Node * delDataNode(Node* pHeard, int data, bool bSucced)
{   
	bSucced = false;
	//�ҵ����һ�����λ��
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

// ��ȡ��������Ч�ڵ�ĸ��� 
int GetVaildNode(Node* pHeard)
{
	int iLength = 0;

	//�ҵ����һ�����λ��
	Node * tmp = pHeard;
	while (tmp->nextAdrr != nullptr)
	{
		tmp = tmp->nextAdrr;
		++iLength;
	}

	return iLength;
}

// �������� 
void destory(Node* pHeard)
{   
	//�ҵ����һ�����λ��
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

//��ת����
Node * Reverse(Node* pHeard)
{
	//1.�������ع�������������Ľ����뵽��������
	Node * NewList = (Node*)malloc(sizeof(Node));
	//��ʼ���µ�ͷ�ڵ������
	NewList->data = pHeard->data;
	NewList->nextAdrr = nullptr;

	Node *  tmp = nullptr;
	while (pHeard->nextAdrr != NULL)
	{
		tmp = NewList->nextAdrr;
		NewList->nextAdrr = pHeard->nextAdrr;
		pHeard->nextAdrr = pHeard->nextAdrr->nextAdrr; //�Ͽ�֮ǰ�Ľ��
		NewList->nextAdrr->nextAdrr = tmp;
	}

	free(pHeard);
	pHeard = nullptr;
	return NewList;
	Node * newHead;

	///////////////////////////////////////////// �ݹ鷨
	//!!!���������ǵ���û�����һ�����
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

	///��ʼ������
	pHeard = InitList();
	/////////
	//���������һ��λ�����һ�����
	pHeard = InsetLastPos(pHeard,1);

	pHeard = InsetLastPos(pHeard, 2);

	pHeard = InsetLastPos(pHeard, 3);

	pHeard = InsetLastPos(pHeard, 4);

	pHeard = InsetLastPos(pHeard, 5);

	pHeard = InsetLastPos(pHeard, 6);

	Show(pHeard);

	printf("\n");

	////ɾ�������һ�����
	pHeard = delFirsrNode(pHeard);

	printf("ɾ�������һ������");
	printf("\n");

	Show(pHeard);

	//������posλ�ò���ֵΪdata�Ľ��
    pHeard = insertNodePos(pHeard, 1,1);

	printf("\n");

	Show(pHeard);

	//��ת����
	Node* newHeard = Reverse(pHeard);
	printf("\n");
	Show(newHeard);
	
	// ��ȡ��������Ч�ڵ�ĸ��� 
	int iNumber = GetVaildNode(newHeard);
	printf("\n");
	printf("%d", iNumber);


	// �������� 
	destory(newHeard);

	printf("\n");
	Show(newHeard);

	
	return 0;
}