#include <iostream>
#include <random>
#include <vector>

using namespace std;

typedef struct tagNode
{
	tagNode* Next;
	int Value;
}NODE;

NODE* List;
NODE* End;
int Length = 0;


void Push(int _value);
void PushFront(int _value);
void insert(int count, int _value);
void remove(int count);
void removeBack();
void ShuffleList();
void PrintValueAt(int index);

int main(void)
{
	/*int i = 10;
	int* n = &i;

	cout << i << endl;
	cout << *n << endl;

	cout << &i << endl;
	cout << n << endl;

	*n = 20;

	cout << i << endl;
	cout << *n << endl;
	*/

	

	List = new NODE;

	List->Next = nullptr;
	List->Value = 0;

	End = List;

	Push(10);
	// Push(20);
	// Push(30);
	// Push(40);
	// Push(50);
	// Push(60);
	//insert(2, 25);
	//remove(2);
	removeBack();
	Push(100);
	
	// ShuffleList();

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
	//NODE* nextNode = List;

	//while (nextNode->Next != nullptr)
	//	nextNode = nextNode->Next;

	//nextNode->Next = new NODE;

	//nextNode->Next->Next = nullptr;
	//nextNode->Next->Value = _value;

	NODE* node = new NODE;

	node->Next = nullptr;
	node->Value = _value;

	End->Next = node;
	End = node;
	

	++Length;
}

void PushFront(int _value)
{
	NODE* newNode = new NODE;  // ���ο� ��� ����

	// initialize
	newNode->Next = List->Next;
	newNode->Value = _value;

	List->Next = newNode;  // ���ο� ��带 ����Ʈ�� �� �տ� ����

	++Length;
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

	++Length;
}

void remove(int count)
{
	// ** ����Ʈ�� ��� �� ������ �������� count�� ���� ũ�ٸ�
	// ** ���� �߰��� �� �����Ƿ� ����
	if (Length < count)
		return;

	// ** ����Ʈ�� ����
	NODE* nextNode = List;
	NODE* OldNode = nullptr;

	// ** ī��Ʈ�� ����ŭ ���� ���� �̵�
	while (0 < count)
	{
		--count;

		// ** ���� ���� �̵�
		nextNode = nextNode->Next;
	}

	// ** �� ���� ��带 �ӽ��� ����ҿ� ����
	NODE* tempNode = nextNode->Next->Next;

	// ** ���� ��带 ����
	delete nextNode->Next;
	nextNode->Next = nullptr;

	// ** ������ ������ �ӽ������ߴ� ��带 ����
	nextNode->Next = tempNode;
	
	--Length;
}

void removeBack()
{
	if (Length < 1)
		return;
	else if (Length < 2)
	{
		delete List->Next;
		List->Next = nullptr;
		End = List;
	}
	else
	{
		// ** ���� ���� ���� ��带 ����
		NODE* preNode = List;
		NODE* CurNode = List->Next;

		// ** ���κ��� ���� �� ������带 ã��
		while (CurNode->Next != nullptr)
		{
			preNode = preNode->Next;
			CurNode = CurNode->Next;
		}

		// ** ���κп� ������ ���� ��� ����
		delete CurNode;
		CurNode = nullptr;

		// ** ������ ���� ����� ���� ��忡 ����� ���� ��带 nullptr�� �ʱ�ȭ
		preNode->Next = nullptr;

		// ** ���� ��带 ����� ������ ����
		End = preNode;
	}

	--Length;
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