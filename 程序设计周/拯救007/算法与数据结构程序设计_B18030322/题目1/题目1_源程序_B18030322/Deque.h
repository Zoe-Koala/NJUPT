#ifndef _DEQUE_H_
#define _DEQUE_H_
typedef unsigned int ElemType;

//������ʽ
typedef struct NodeRecord {
	ElemType Element;
	struct NodeRecord *Next;   //ָ����һ��node
}*Node;

typedef struct DequeRecord {
	Node Front, Rear;          //�ֱ�ָ��Deque��ǰ��������
}*Deque;

Deque DequeNew();                  //�����µ�Deque
void DequeDelete(Deque D);         //ɾ��Deque
void DequeClear(Deque D);          //ɾ�����еĽڵ����ͷ�ڵ�
int IsEmpty(Deque D);              //�ж�Deque�Ƿ�Ϊ��
void Push(ElemType X, Deque D);    //��XԪ��ѹջ��D��
ElemType Pop(Deque D);             //����һ��Ԫ�س�ջ
void Inject(ElemType X, Deque D);  //����Ԫ��X��Dĩβ

#endif // !_DEQUE_H_
