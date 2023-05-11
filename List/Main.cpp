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
	// ** 첫번째 노드
	// create
	List = new NODE;

	// initialize
	List->Next = nullptr;
	List->Value = 0;

	// ==================================
	// ** 두번째 노드
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

	
	// ** 두번째 노드를 nextNode 에 넘겨준다.
	NODE* Node = List->Next;

	// ** nextNode 가 nullptr이 아니라면 반복
	while (Node != nullptr)
	{
		// ** 출력
		cout << Node->Value << endl;

		// ** 다음 노드로 이동
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

