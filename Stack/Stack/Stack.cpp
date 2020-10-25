#include <stdio.h>

#define MaxSize 100
//1.数组表示栈
//note1.数组表示的栈push时候需要判断栈是否已经满了，pop的时候需要判断是栈否空着
struct DataStack
{
	int data[MaxSize]; //数据
	int topPoint;  //栈的栈顶指针 topPoint is 0 to say the stack is empty

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

//1.链表表示的栈
//note1.使用头插法插入节点,不像数组栈push，链表的push没有限制，也就是说栈不会满
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

//使用头插法来push新节点
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
	int q;//商
	int r;//余数

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





