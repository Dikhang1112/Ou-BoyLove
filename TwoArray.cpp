#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};

Node* createNode(const vector<int>& vals)
{
	Node* head = nullptr;
	Node* tail = nullptr;
	for (int val : vals)
	{
		Node* node = new Node(val);
		if (!head)
		{
			head = tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	return head;
} 
void printNode(Node* list)
{
	while (list)
	{
		cout << list->val;
		if (list->next) cout << " -> ";
		list = list->next;
	}
	cout << endl;
}

Node* reverseList(Node* head) {
	Node* prev = nullptr;
	while (head) {
		Node* next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}
Node* addTwoLists(Node* num1, Node* num2) {
	Node* res = nullptr, * curr = nullptr;
	int carry = 0;
	num1 = reverseList(num1);
	num2 = reverseList(num2);
	while (num1 != nullptr || num2 != nullptr || carry != 0) {
		int sum = carry;

		if (num1 != nullptr) {
			sum += num1->val;
			num1 = num1->next;
		}

		if (num2 != nullptr) {
			sum += num2->val;
			num2 = num2->next;
		}

		Node* newNode = new Node(sum % 10);

		carry = sum / 10;
		if (res == nullptr) {
			res = newNode;
			curr = newNode;
		}
		else {

			curr->next = newNode;
			curr = curr->next;
		}
	}

	return reverseList(res);
}
int main()
{
	Node* l1 = createNode(vector<int> {2,4,3});
	Node* l2 = createNode(vector<int> {5,6,4});
	Node* sum = addTwoLists(l1, l2);
	printNode(sum);
	return 0;
}	