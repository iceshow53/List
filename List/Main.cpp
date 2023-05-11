#include <iostream>

using namespace std;

typedef struct tagNode
{
	tagNode* Next;
	int Value;
}NODE;

NODE* List = new NODE;

void Push(int _value);

int main(void)
{
	// ** ù��° ���
	// create
	List = new NODE;

	// initialize
	List->Next = nullptr;
	List->Value = 0;

	// ==================================
	// ** �ι�° ���
	Push(10);
	// create
	List->Next = new NODE;

	// initialize
	List->Next->Next = nullptr;
	List->Next->Value = 10;

	// ==================================
	// create
	List->Next->Next = new NODE;

	// initialize
	List->Next->Next->Next = nullptr;
	List->Next->Next->Value = 20;

	// ==================================
	// create
	List->Next->Next->Next = new NODE;
	
	// initialize
	List->Next->Next->Next->Next = nullptr;
	List->Next->Next->Next->Value = 30;

	
	// ** �ι�° ��带 nextNode �� �Ѱ��ش�.
	NODE* Node = List->Next;

	// ** nextNode �� nullptr�� �ƴ϶�� �ݺ�
	while (Node != nullptr)
	{
		// ** ���
		cout << Node->Value << endl;

		// ** ���� ���� �̵�
		Node = Node->Next;
	}

	return 0;
}

void Push(int _value)
{
	NODE* nextNode = List;

	while (nextNode != nullptr)
		nextNode = nextNode->Next;

	nextNode = new NODE;
	nextNode->Next = nullptr;
	nextNode->Value = _value;


}

