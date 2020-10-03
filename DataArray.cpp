#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Array
{
	int *pBase;
	int leng;
	int valid;
};

//初始化数组 
void InitArray(struct Array*pArray, int ileng);
//输出数组
void ShowArray(struct Array*pArray, int ileng);
//判断数组是否为空
bool IsEmpty(struct Array *pArray);
//判断数组是否填满
bool IsFull(struct Array *pArray);
//在数组的后面追加一个元素
bool Append(struct Array *pArray, int val);
//向指定位置插入
bool Insert(struct Array *pArray, int val,int pos);
//删除数组中指定位置的元素并返回所删除元素的值
bool Delete(struct Array * pArr, int pos, int *pVal);
//反转数组
void Reverse(struct Array * pArr);

//数组排序
void Sort(struct Array * pArr);

//初始化数组 
void InitArray(struct Array*pArray, int ileng)
{
	pArray->pBase = (int *)malloc(sizeof(int) * ileng);
	if (pArray->pBase == NULL) //初始化数组 
	{
		printf("动态内存分配失败！");
		exit(-1);
	}
	else
	{
		pArray->leng = ileng;
		pArray->valid = 0;
	}
}

//输出数组
void ShowArray(struct Array*pArray, int ileng)
{
	if (IsEmpty(pArray))
		return;

	for (int i = 0; i < pArray->valid; ++i)
	{
		printf("%d  ", pArray->pBase[i]);
	}
}

//判断数组是否为空
bool IsEmpty(struct Array *pArray)
{
	if (pArray->valid == 0)
		return true;
	return false;
}

//判断数组是否填满
bool IsFull(struct Array *pArray)
{
	if (pArray->valid == pArray->leng)
		return true;
	return false;
}

//在数组的后面追加一个元素
bool Append(struct Array *pArray, int val)
{
	if (IsFull(pArray))
	{
		printf("%s\n", "数组已经满了");
		return false;
	}

	pArray->pBase[pArray->valid] = val;

	++pArray->valid;

	return true;
}

//向指定位置插入
bool Insert(struct Array *pArray, int val,int pos)
{
	//首先判断位置是否合法,如果是数组已经满了，那么就没法插入了
	if (IsFull(pArray))
	{
		return false;
	}
    
	//pos从1开始但是数组下标从0开始
	if (pos<1 || pos > pArray->valid + 1)
	{
		return false;
	}

	//注意此处的循环是从后到前遍历，而删除时遍历是从前向后，否则程序会出错误
	for (int index = pArray->valid-1; index >= pos - 1; --index)
	{
		pArray->pBase[index+1] = pArray->pBase[index];
	}

	pArray->pBase[pos - 1] = val;


	++pArray->valid;
}

bool Delete(struct Array * pArr, int pos, int *pVal)
{
	if (IsEmpty(pArr))
		return false;
	if (pos > pArr->valid-1 || pos < 1)
	{
		return false;
	}

	*pVal = pArr->pBase[pos - 1];
	//注意此处的循环是从前到后遍历，而插入时遍历是从后到前，否则程序会出错误
	for (int index = pos - 1;index <= pArr->valid -1 ;++index)
	{
		pArr->pBase[index - 1] = pArr->pBase[index];
	}

	--pArr->valid;
}

//反转数组
void Reverse(struct Array * pArr)
{
   //方法1，a,把第一个元素和最后一个元素调换
	//b.把第二个人元素和倒数第二个元素调换
	//直道 first < last为止
	for (int first = 0,last = pArr->valid-1; first < last; ++first,--last)
	{
		int temp = pArr->pBase[first];
		pArr->pBase[first] = pArr->pBase[last];
		pArr->pBase[last] = temp;
	}

	//方法2.
	/*for (int i = 0;i<pArr->valid/2;++i)
	{
		int temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[pArr->valid -i-1];
		pArr->pBase[pArr->valid - i - 1] = temp;
	}*/
}

void Sort(struct Array * pArr)
{   
	int i, j ,t;
	for (i = 0 ;i< pArr->valid;++i)
	{
		for (j = i+1;j<pArr->valid;++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

int main()
{

	struct Array pArray;
	//1.初始化数组
	InitArray(&pArray, 8);

	//在数组的后面追加一个元素
	Append(&pArray, 5);

	Append(&pArray, 3);

	Insert(&pArray,1,1);

	Insert(&pArray, 6, 1);

	Insert(&pArray, 7, 2);

	printf("%s\n", "删除之前");

	//输出数组
	ShowArray(&pArray, 8);

	printf("\n");

	/*int pva = 1;
	Delete(&pArray, 2, &pva);*/
	Reverse(&pArray);
	//输出数组
	ShowArray(&pArray, 8);
	
	printf("\n");

	Sort(&pArray);

	//输出数组
	ShowArray(&pArray, 8);

	return 0;
}
