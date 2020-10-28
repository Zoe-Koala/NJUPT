#ifndef _DEQUE_H_
#define _DEQUE_H_
typedef unsigned int ElemType;

//链表形式
typedef struct NodeRecord {
	ElemType Element;
	struct NodeRecord *Next;   //指向下一个node
}*Node;

typedef struct DequeRecord {
	Node Front, Rear;          //分别指向Deque的前后两个点
}*Deque;

Deque DequeNew();                  //创建新的Deque
void DequeDelete(Deque D);         //删除Deque
void DequeClear(Deque D);          //删除所有的节点除了头节点
int IsEmpty(Deque D);              //判断Deque是否为空
void Push(ElemType X, Deque D);    //将X元素压栈到D中
ElemType Pop(Deque D);             //将第一个元素出栈
void Inject(ElemType X, Deque D);  //插入元素X至D末尾

#endif // !_DEQUE_H_
