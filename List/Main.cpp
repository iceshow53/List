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
	NODE* newNode = new NODE;  // ���ο� ��� ����

	// initialize
	newNode->Next = List->Next;
	newNode->Value = _value;

	List->Next = newNode;  // ���ο� ��带 ����Ʈ�� �� �տ� ����
}

void insert(int count, int _value)
{
	// ** ����Ʈ�� ��� �� ������ �������� count�� ���� ũ�ٸ�
	// ** ���� �߰��� �� �����Ƿ� ����
	if (Length < count)
		return;

	// ** ����Ʈ�� ����
	NODE* nextNode = List;
	
	// ** ī��Ʈ�� ����ŭ ���� ���� �̵�
	while (0 < count)
	{
		--count;

		// ** ���� ���� �̵�
		nextNode = nextNode->Next;
	}
	// ** �̵��� �����ٸ� ���ο� ��带 �߰�

	// ** ���ο� ��� ����
	NODE* newNode = new NODE;
	newNode->Next = nullptr;
	newNode->Value = _value;

	// ** ���� ��带 �ӽ��� ����ҿ� ����
	NODE* tempNode = nextNode->Next;

	// ** ������带 �����ϴ� ��ҿ� ���ο� ��带 ��ġ
	nextNode->Next = newNode;

	// ** ���ο� ��尡 ����Ű�� ������带 �ӽð����� �ִ� ���� ��ġ
	newNode->Next = tempNode;
}

void ShuffleList()
{
	// ����Ʈ�� ��带 ���Ϳ� ����
	vector<NODE*> nodes;
	NODE* currentNode = List->Next;
	while (currentNode != nullptr)
	{
		nodes.push_back(currentNode);
		currentNode = currentNode->Next;
	}

	// ��带 �������� ����
	random_device rd;
	mt19937 rng(rd());
	shuffle(nodes.begin(), nodes.end(), rng);

	// ����� ������ ����
	for (size_t i = 0; i < nodes.size() - 1; i++)
	{
		nodes[i]->Next = nodes[i + 1];
	}
	nodes[nodes.size() - 1]->Next = nullptr;

	// ����Ʈ�� ù ��° ��带 ������Ʈ
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

	cout << "ã�� �� ���� ����: " << index << endl;
}