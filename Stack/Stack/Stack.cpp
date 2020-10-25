#include <stdio.h>

#define MaxSize 100
//1.�����ʾջ
//note1.�����ʾ��ջpushʱ����Ҫ�ж�ջ�Ƿ��Ѿ����ˣ�pop��ʱ����Ҫ�ж���ջ�����
struct DataStack
{
	int data[MaxSize]; //����
	int topPoint;  //ջ��ջ��ָ�� topPoint is 0 to say the stack is empty

	DataStack()
	{
		topPoint = 0;
	}
};

bool isFull(DataStack & dataStack)
{
	if (dataStack.topPoint == MaxSize - 1)
		return true;

	return false;
}

bool isEmpty(DataStack & dataStack)
{
	if (dataStack.topPoint == 0)
		return true;
	return false;
}

int push(DataStack & dataStack, int val)
{
	if (isFull(dataStack))
		return 0;

	dataStack.data[dataStack.topPoint] = val;
	++dataStack.topPoint;

	return val;
}

int pop(DataStack & dataStack)
{
	--dataStack.topPoint;

	return dataStack.data[dataStack.topPoint];
}

//1.�����ʾ��ջ
//note1.ʹ��ͷ�巨����ڵ�,��������ջpush�������pushû�����ƣ�Ҳ����˵ջ������
struct nodeStack
{
	int val;
	nodeStack * next;
	nodeStack()
	{
		next = nullptr;
		val = 0;
	}

};

//ʹ��ͷ�巨��push�½ڵ�
int push(nodeStack * lnodeStack, int val)
{
	nodeStack * newNode = new nodeStack;
	if (!newNode)
	{
		return 0;
	}

	newNode->val = val;

	newNode->next = lnodeStack->next;
	lnodeStack->next = newNode;

	return val;
}

int pop(nodeStack * lnodeStack)
{
	if (lnodeStack->next == nullptr)
		return 0;

	nodeStack * topNode = lnodeStack->next;
	lnodeStack->next = topNode->next;
	int ret = topNode->val;

	delete topNode;
	topNode = nullptr;

	return ret;
}

void systemCovert(int number,int _system,nodeStack *& lnodeStack)
{
	int q;//��
	int r;//����

	q = number % _system;
	r = number / _system;

	push(lnodeStack, q);

	while (r!=0)
	{   
		q = r % _system;
		r = r / _system;
		printf("%d\n", q);
		push(lnodeStack, q);
	}
}

int main()
{
	nodeStack * lnodeStack = new nodeStack;
	lnodeStack->next = nullptr;
	
	systemCovert(77,2,lnodeStack);

	while (lnodeStack->next!= nullptr)
	{
		int a = pop(lnodeStack);
		printf("%d", a);
	}

	return 0;
}





