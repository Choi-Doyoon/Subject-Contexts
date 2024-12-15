#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

const int K = 2;

struct Node {
	int points[K];
	Node* left;
	Node* right;
};

Node* createNode(int points[])
{
	// 2-1�� ���� ����, 4�� (Problem 2-1, 4pts)
}

Node* insertNode(Node* root, int points[], int depth)
{
	// 2-2�� ���� ����, 4�� (Problem 2-2, 4pts)
}

void printKDTree(Node* root, int space, int depth)
{
	// 2-3�� ���� ����, 4�� (Problem 2-3, 4pts
    if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

    cout << string(depth * 4, ' ') << root->data << "\n";

        // 모든 자식 노드 재귀 호출
        for (createNode* child : node->children) {
            printKDTree(child, depth + space);
        }
}

void deleteKDTree(Node* root)
{
	if (root == nullptr)
		return;
	if (root->left != nullptr)
		deleteKDTree(root->left);
	if (root->right != nullptr)
		deleteKDTree(root->right);

	delete root;
	return;
}

void printFormat()
{
	cout << "   ^\n";
	cout << "   |\n";
	cout << "right\n";
	cout << "   |\n";
	cout << "root\n";
	cout << "   |\n";
	cout << "left\n";
	cout << "   |\n";
	cout << "   v\n";
	return;
}

int main()
{
	printFormat();

	Node* root = nullptr;

	int depth = 0;
	int points[8][2] = {
	{5,3},{5,4},{3,9},{4,6},{6,2},{1,1},{4,1},{6,7}
	};

	for (int i = 0; i < 8; i++) {
		root = insertNode(root, points[i], depth);
	}

	int space = 0;
	printKDTree(root, space, depth);

	deleteKDTree(root);
}