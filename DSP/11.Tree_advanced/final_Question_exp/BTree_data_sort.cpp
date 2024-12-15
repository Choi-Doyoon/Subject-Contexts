//B-트리를 활용한 데이터 정렬
#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool isLeaf;
    int degree;

    BTreeNode(int degree, bool isLeaf) : degree(degree), isLeaf(isLeaf) {}

    // 중위 순회를 통해 데이터를 수집
    void traverse(vector<int>& result) {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!isLeaf)
                children[i]->traverse(result);
            result.push_back(keys[i]);
        }
        if (!isLeaf)
            children[i]->traverse(result);
    }

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
};

class BTree {
private:
    BTreeNode* root;
    int degree;

public:
    BTree(int degree) : root(nullptr), degree(degree) {}

    void insert(int key);
    vector<int> getSortedData() {
        vector<int> result;
        if (root)
            root->traverse(result);
        return result;
    }
};

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;
        if (children[i + 1]->keys.size() == 2 * degree - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->degree, y->isLeaf);
    z->keys.resize(degree - 1);

    for (int j = 0; j < degree - 1; j++)
        z->keys[j] = y->keys[j + degree];

    if (!y->isLeaf) {
        z->children.resize(degree);
        for (int j = 0; j < degree; j++)
            z->children[j] = y->children[j + degree];
    }

    y->keys.resize(degree - 1);

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[degree - 1]);
}

void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(degree, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * degree - 1) {
            BTreeNode* s = new BTreeNode(degree, false);
            s->children.push_back(root);
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < key)
                i++;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

int main() {
    BTree tree(3); // Degree 3

    // 데이터 삽입
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    // 정렬된 데이터 가져오기
    vector<int> sortedData = tree.getSortedData();

    // 출력
    cout << "Sorted Data: [";
    for (size_t i = 0; i < sortedData.size(); ++i) {
        cout << sortedData[i];
        if (i != sortedData.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
