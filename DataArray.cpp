#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Array
{
	int *pBase;
	int leng;
	int valid;
};

//��ʼ������ 
void InitArray(struct Array*pArray, int ileng);
//�������
void ShowArray(struct Array*pArray, int ileng);
//�ж������Ƿ�Ϊ��
bool IsEmpty(struct Array *pArray);
//�ж������Ƿ�����
bool IsFull(struct Array *pArray);
//������ĺ���׷��һ��Ԫ��
bool Append(struct Array *pArray, int val);
//��ָ��λ�ò���
bool Insert(struct Array *pArray, int val,int pos);
//ɾ��������ָ��λ�õ�Ԫ�ز�������ɾ��Ԫ�ص�ֵ
bool Delete(struct Array * pArr, int pos, int *pVal);
//��ת����
void Reverse(struct Array * pArr);

//��������
void Sort(struct Array * pArr);

//��ʼ������ 
void InitArray(struct Array*pArray, int ileng)
{
	pArray->pBase = (int *)malloc(sizeof(int) * ileng);
	if (pArray->pBase == NULL) //��ʼ������ 
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else
	{
		pArray->leng = ileng;
		pArray->valid = 0;
	}
}

//�������
void ShowArray(struct Array*pArray, int ileng)
{
	if (IsEmpty(pArray))
		return;

	for (int i = 0; i < pArray->valid; ++i)
	{
		printf("%d  ", pArray->pBase[i]);
	}
}

//�ж������Ƿ�Ϊ��
bool IsEmpty(struct Array *pArray)
{
	if (pArray->valid == 0)
		return true;
	return false;
}

//�ж������Ƿ�����
bool IsFull(struct Array *pArray)
{
	if (pArray->valid == pArray->leng)
		return true;
	return false;
}

//������ĺ���׷��һ��Ԫ��
bool Append(struct Array *pArray, int val)
{
	if (IsFull(pArray))
	{
		printf("%s\n", "�����Ѿ�����");
		return false;
	}

	pArray->pBase[pArray->valid] = val;

	++pArray->valid;

	return true;
}

//��ָ��λ�ò���
bool Insert(struct Array *pArray, int val,int pos)
{
	//�����ж�λ���Ƿ�Ϸ�,����������Ѿ����ˣ���ô��û��������
	if (IsFull(pArray))
	{
		return false;
	}
    
	//pos��1��ʼ���������±��0��ʼ
	if (pos<1 || pos > pArray->valid + 1)
	{
		return false;
	}

	//ע��˴���ѭ���ǴӺ�ǰ��������ɾ��ʱ�����Ǵ�ǰ��󣬷������������
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
	//ע��˴���ѭ���Ǵ�ǰ���������������ʱ�����ǴӺ�ǰ���������������
	for (int index = pos - 1;index <= pArr->valid -1 ;++index)
	{
		pArr->pBase[index - 1] = pArr->pBase[index];
	}

	--pArr->valid;
}

//��ת����
void Reverse(struct Array * pArr)
{
   //����1��a,�ѵ�һ��Ԫ�غ����һ��Ԫ�ص���
	//b.�ѵڶ�����Ԫ�غ͵����ڶ���Ԫ�ص���
	//ֱ�� first < lastΪֹ
	for (int first = 0,last = pArr->valid-1; first < last; ++first,--last)
	{
		int temp = pArr->pBase[first];
		pArr->pBase[first] = pArr->pBase[last];
		pArr->pBase[last] = temp;
	}

	//����2.
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
	//1.��ʼ������
	InitArray(&pArray, 8);

	//������ĺ���׷��һ��Ԫ��
	Append(&pArray, 5);

	Append(&pArray, 3);

	Insert(&pArray,1,1);

	Insert(&pArray, 6, 1);

	Insert(&pArray, 7, 2);

	printf("%s\n", "ɾ��֮ǰ");

	//�������
	ShowArray(&pArray, 8);

	printf("\n");

	/*int pva = 1;
	Delete(&pArray, 2, &pva);*/
	Reverse(&pArray);
	//�������
	ShowArray(&pArray, 8);
	
	printf("\n");

	Sort(&pArray);

	//�������
	ShowArray(&pArray, 8);

	return 0;
}
