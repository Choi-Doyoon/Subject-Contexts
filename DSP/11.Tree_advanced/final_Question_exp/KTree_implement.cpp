//KTree 구현
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class KTreeNode {
public:
    int data;
    vector<KTreeNode*> children;

    KTreeNode(int value) : data(value) {}
};

class KTree {
private:
    KTreeNode* root;
    int k; // K-트리의 최대 자식 수

public:
    KTree(int k) : root(nullptr), k(k) {}

    void insert(int parentValue, int value) {
        if (!root) {
            root = new KTreeNode(value); // 루트를 생성
            return;
        }

        queue<KTreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            KTreeNode* current = q.front();
            q.pop();

            if (current->data == parentValue) {
                if (current->children.size() < k) {
                    current->children.push_back(new KTreeNode(value));
                    return;
                }
            }

            for (KTreeNode* child : current->children) {
                q.push(child);
            }
        }

        cout << "Parent " << parentValue << " not found or already has " << k << " children.\n";
    }

    void printIndented(KTreeNode* node, int depth = 0) {
        if (!node) return;

        // 들여쓰기 후 노드 출력
        cout << string(depth * 4, ' ') << node->data << "\n";

        // 모든 자식 노드 재귀 호출
        for (KTreeNode* child : node->children) {
            printIndented(child, depth + 1);
        }
    }

    void printTree() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        printIndented(root);
    }
};

int main() {
    KTree tree(3); // 각 노드가 최대 3개의 자식을 가질 수 있음

    tree.insert(0, 1); // 루트 삽입
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(1, 4);

    tree.insert(2, 5);
    tree.insert(2, 6);

    tree.insert(3, 7);

    tree.insert(4, 8);

    cout << "K-ary Tree Structure:\n";
    tree.printTree();

    return 0;
}
