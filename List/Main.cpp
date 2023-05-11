#include <iostream>
#include <random>
#include <vector>

using namespace std;

typedef struct tagNode
{
	tagNode* Next;
	int Value;
}NODE;

NODE* List = new NODE;
int Length = 0;


void Push(int _value);
void PushFront(int _value);
void insert(int count, int _value);
void ShuffleList();
void PrintValueAt(int index);

int main(void)
{
	List = new NODE;

	List->Next = nullptr;
	List->Value = 0;

	Push(10);
	Push(20);
	Push(30);
	Push(40);
	Push(50);
	insert(2, 25);
	//PushFront(60);
	//ShuffleList();

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

	//PrintValueAt(0);


	return 0;
}

void Push(int _value)
{
	NODE* nextNode = List;

	while (nextNode->Next != nullptr)
		nextNode = nextNode->Next;

	nextNode->Next = new NODE;

	nextNode->Next->Next = nullptr;
	nextNode->Next->Value = _value;

	++Length;
}

void PushFront(int _value)
{
	NODE* newNode = new NODE;  // 새로운 노드 생성

	// initialize
	newNode->Next = List->Next;
	newNode->Value = _value;

	List->Next = newNode;  // 새로운 노드를 리스트의 맨 앞에 연결
}

void insert(int count, int _value)
{
	// ** 리스트에 담긴 총 원소의 개수보다 count의 값이 크다면
	// ** 값을 추가할 수 없으므로 리턴
	if (Length < count)
		return;

	// ** 리스트를 들고옴
	NODE* nextNode = List;
	
	// ** 카운트의 값만큼 다음 노드로 이동
	while (0 < count)
	{
		--count;

		// ** 다음 노드로 이동
		nextNode = nextNode->Next;
	}
	// ** 이동이 끝났다면 새로운 노드를 추가

	// ** 새로운 노드 생성
	NODE* newNode = new NODE;
	newNode->Next = nullptr;
	newNode->Value = _value;

	// ** 다음 노드를 임시의 저장소에 저장
	NODE* tempNode = nextNode->Next;

	// ** 다음노드를 저장하는 장소에 새로운 노드를 배치
	nextNode->Next = newNode;

	// ** 새로운 노드가 가르키는 다음노드를 임시공간에 있던 노드로 배치
	newNode->Next = tempNode;
}

void ShuffleList()
{
	// 리스트의 노드를 벡터에 저장
	vector<NODE*> nodes;
	NODE* currentNode = List->Next;
	while (currentNode != nullptr)
	{
		nodes.push_back(currentNode);
		currentNode = currentNode->Next;
	}

	// 노드를 무작위로 섞음
	random_device rd;
	mt19937 rng(rd());
	shuffle(nodes.begin(), nodes.end(), rng);

	// 노드의 순서를 변경
	for (size_t i = 0; i < nodes.size() - 1; i++)
	{
		nodes[i]->Next = nodes[i + 1];
	}
	nodes[nodes.size() - 1]->Next = nullptr;

	// 리스트의 첫 번째 노드를 업데이트
	List->Next = nodes[0];
}

void PrintValueAt(int index)
{
	NODE* currentNode = List->Next;
	int count = 0;

	while (currentNode != nullptr)
	{
		if (count == index)
		{
			cout << "Value at index " << index << ": " << currentNode->Value << endl;
			return;
		}

		currentNode = currentNode->Next;
		count++;
	}

	cout << "찾을 수 없는 범위: " << index << endl;
}