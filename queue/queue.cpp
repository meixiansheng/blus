#include <stdio.h>
#define Max_ORDER 8

//顺序线性队列
struct OrderLinerQueue
{
   int * data;
   int front;
   int rear;
};

bool InitOrderQueue(OrderLinerQueue * pOrderLinerQueue)
{
    pOrderLinerQueue->data = (int*)malloc(sizeof(int)*Max_ORDER);
    if(!pOrderLinerQueue->data)
    {
        return false;
    }

    pOrderLinerQueue->front = 0;
    pOrderLinerQueue->rear = 0;

    return true;
}

bool EnOrderQueue(OrderLinerQueue * pOrderLinerQueue,int data)
{
    //队满
    if(pOrderLinerQueue->rear >= Max_ORDER)
    {
        return false;
    }


    pOrderLinerQueue->data[pOrderLinerQueue->rear] = data;
    qDebug() << "进队列: " << data;

    ++pOrderLinerQueue->rear;

    return true;
}

bool DeOrderQueue(OrderLinerQueue * pOrderLinerQueue)
{
    //队已经空
    if(pOrderLinerQueue->front == pOrderLinerQueue->rear)
    {
        return false;
    }

    qDebug() << "出队列: " << pOrderLinerQueue->data[pOrderLinerQueue->front];
    pOrderLinerQueue->data[pOrderLinerQueue->front] = -1;

    ++pOrderLinerQueue->front;

    return true;
}

int GetlenghOrder(OrderLinerQueue * pOrderLinerQueue)
{
    return pOrderLinerQueue->rear - pOrderLinerQueue->front;
}

//链式顺序队列的节点
struct  Node
{
    int data;
    Node * next;
    Node() {}
};

//链式顺序队列的管理节点指针
struct  ChainOrderQueue
{
     Node* front;
     Node * rear;
     ChainOrderQueue() {}
};

bool InitChainOrderQueue(ChainOrderQueue * pMangerPoint)
{
     Node *pNode = (Node *)malloc(sizeof(Node));
     if(pNode == nullptr)
     {
         return false;
     }

     pMangerPoint->front = pNode;
     pMangerPoint->rear = pNode;

     pNode->next = nullptr;
}

bool EnChainOrderQueue(ChainOrderQueue * pMangerPoint,int data)
{
    Node *pNode = (Node *)malloc(sizeof(Node));
    if(pNode == nullptr)
    {
        return false;
    }

    pNode->data = data;
    pNode->next = nullptr;
    pMangerPoint->rear->next = pNode;
    pMangerPoint->rear = pNode;

    return true;
}

bool DeChainOrderQueue(ChainOrderQueue * pMangerPoint)
{
   //队满
   if(pMangerPoint->front == pMangerPoint->rear)
   {
       return false;
   }

   Node *pNode = pMangerPoint->front->next;
   pMangerPoint->front->next = pNode->next;

   free(pNode);

   pNode = pMangerPoint->front->next;

   //如果头指针指向尾指针 那么队列已经清空，此时为了便于判断将尾指针赋值给头指针
   if(pNode == pMangerPoint->rear)
   {
       pMangerPoint->rear = pMangerPoint->front;
   }

   return true;
}

//获得链表长度
int GetlenghChainOrderQueue(ChainOrderQueue * pMangerPoint)
{
   int ilength;
   Node * p = pMangerPoint->front->next;
   while(p!=nullptr)
   {
       ++ilength;
       p = p->next;
   }

   return ilength;
}

//清空队列
bool ClearChainOrderQueue(ChainOrderQueue * pMangerPoint)
{
   if(pMangerPoint->front == pMangerPoint->rear)
   {
       return false;
   }

   Node * p = pMangerPoint->front->next;
   while (p!=nullptr)
   {
        pMangerPoint->front->next = p->next;
        free(p);
        p = pMangerPoint->front->next;
   }

   p = nullptr;

   pMangerPoint->rear = pMangerPoint->front;

   return true;
}

//销毁队列也就是在清空队列数据元素的基础上销毁New出来的节点元素front，把头指针销毁
bool DestroyChainOrderQueue(ChainOrderQueue * pMangerPoint)
{
    ClearChainOrderQueue(pMangerPoint);
    free(pMangerPoint->front);
    pMangerPoint->front = nullptr;
    pMangerPoint->rear = nullptr;

    return true;
}

int main(int argc, char *argv[])
{
    

    return 0;
}
