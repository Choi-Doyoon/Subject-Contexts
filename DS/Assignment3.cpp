#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MINIMUM = 1;
const int MAXIMUM = 2 * MINIMUM;

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
};

class BTree {
private:
    BTreeNode* root;

    // 노드에 키 삽입 (재귀적 호출)
    void loose_insert(BTreeNode* node, int key) {
        // 현재 노드의 적절한 삽입 위치를 찾기
        size_t i = 0;
        while (i < node->keys.size() && node->keys[i] < key) {
            ++i;
        }

        // 중복된 키는 삽입하지 않음
        if (i < node->keys.size() && node->keys[i] == key) {
            return; // 이미 존재하는 키
        }

        // 리프 노드인 경우, 키를 바로 삽입
        if (node->isLeaf) {
            node->keys.insert(node->keys.begin() + i, key);
        }
        else {
            // 내부 노드인 경우, 자식 노드로 재귀 호출
            loose_insert(node->children[i], key);

            // 자식 노드가 초과된 경우, 노드 분할 처리
            if (node->children[i]->keys.size() > MAXIMUM) {
                fix_excess(node, i);
            }
        }
    }

    // 초과된 노드 분할
    void fix_excess(BTreeNode* parent, size_t index) {
        BTreeNode* child = parent->children[index];
        BTreeNode* sibling = new BTreeNode(child->isLeaf);

        // 중간 값을 부모로 올리고, 나머지는 새로운 형제 노드로 이동
        sibling->keys.assign(child->keys.begin() + MINIMUM + 1, child->keys.end());
        int middleKey = child->keys[MINIMUM];
        child->keys.resize(MINIMUM);

        // 리프가 아니면, 자식 포인터도 이동
        if (!child->isLeaf) {
            sibling->children.assign(child->children.begin() + MINIMUM + 1, child->children.end());
            child->children.resize(MINIMUM + 1);
        }

        // 부모 노드에 중간 값을 삽입하고, 형제 노드를 연결
        parent->keys.insert(parent->keys.begin() + index, middleKey);
        parent->children.insert(parent->children.begin() + index + 1, sibling);
    }

    bool loose_erase(BTreeNode* node, int key) {
        size_t i = 0;
        while (i < node->keys.size() && node->keys[i] < key) {
            ++i;
        }

        if (i < node->keys.size() && node->keys[i] == key) {
            if (node->isLeaf) {
                node->keys.erase(node->keys.begin() + i);
                return true;
            }
            else {
                node->keys[i] = remove_biggest(node->children[i]);
                if (node->children[i]->keys.size() < MINIMUM) {
                    fix_shortage(node, i);
                }
                return true;
            }
        }

        if (node->isLeaf) {
            return false; // Key not found
        }

        bool result = loose_erase(node->children[i], key);
        if (node->children[i]->keys.size() < MINIMUM) {
            fix_shortage(node, i);
        }

        return result;
    }

    int remove_biggest(BTreeNode* node) {
        if (node->isLeaf) {
            int biggest = node->keys.back();
            node->keys.pop_back();
            return biggest;
        }

        int result = remove_biggest(node->children.back());
        if (node->children.back()->keys.size() < MINIMUM) {
            fix_shortage(node, node->children.size() - 1);
        }

        return result;
    }

    void fix_shortage(BTreeNode* parent, size_t index) {
        if (index > 0 && parent->children[index - 1]->keys.size() > MINIMUM) {
            BTreeNode* leftSibling = parent->children[index - 1];
            BTreeNode* child = parent->children[index];

            child->keys.insert(child->keys.begin(), parent->keys[index - 1]);
            parent->keys[index - 1] = leftSibling->keys.back();
            leftSibling->keys.pop_back();

            if (!leftSibling->isLeaf) {
                child->children.insert(child->children.begin(), leftSibling->children.back());
                leftSibling->children.pop_back();
            }
        }
        else if (index + 1 < parent->children.size() && parent->children[index + 1]->keys.size() > MINIMUM) {
            BTreeNode* rightSibling = parent->children[index + 1];
            BTreeNode* child = parent->children[index];

            child->keys.push_back(parent->keys[index]);
            parent->keys[index] = rightSibling->keys.front();
            rightSibling->keys.erase(rightSibling->keys.begin());

            if (!rightSibling->isLeaf) {
                child->children.push_back(rightSibling->children.front());
                rightSibling->children.erase(rightSibling->children.begin());
            }
        }
        else {
            if (index > 0) {
                index--;
            }

            BTreeNode* leftChild = parent->children[index];
            BTreeNode* rightChild = parent->children[index + 1];

            leftChild->keys.push_back(parent->keys[index]);
            leftChild->keys.insert(leftChild->keys.end(), rightChild->keys.begin(), rightChild->keys.end());

            if (!rightChild->isLeaf) {
                leftChild->children.insert(leftChild->children.end(), rightChild->children.begin(), rightChild->children.end());
            }

            parent->keys.erase(parent->keys.begin() + index);
            parent->children.erase(parent->children.begin() + index + 1);
            delete rightChild;
        }
    }

public:
    BTree() : root(nullptr) {}

    // 키 삽입
    void insert(int key) {
        if (!root) {
            root = new BTreeNode(true); // 루트가 없으면 새로 생성
        }

        loose_insert(root, key);

        // 루트 노드가 초과된 경우, 분할 처리
        if (root->keys.size() > MAXIMUM) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children.push_back(root);
            fix_excess(newRoot, 0);
            root = newRoot; // 새로운 루트를 설정
        }
    }

    bool erase(int key) {
        if (!root) {
            return false;
        }

        bool result = loose_erase(root, key);

        if (root->keys.empty() && !root->isLeaf) {
            BTreeNode* oldRoot = root;
            root = root->children[0];
            delete oldRoot;
        }

        return result;
    }

    int count(int key) {
        int totalCount = 0;
        std::queue<BTreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            BTreeNode* node = nodes.front();
            nodes.pop();

            totalCount += std::count(node->keys.begin(), node->keys.end(), key);

            for (BTreeNode* child : node->children) {
                nodes.push(child);
            }
        }

        return totalCount;
    }

    void show_contents() {
        show_recursive(root, 0);
    }

    void show_recursive(BTreeNode* node, int depth) {
        if (!node) {
            return;
        }

        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }

        for (int key : node->keys) {
            std::cout << key << " ";
        }

        std::cout << "\n";

        for (BTreeNode* child : node->children) {
            show_recursive(child, depth + 1);
        }
    }
};

int main() {
    BTree btree;
    std::string command;
    int x;

    while (true) {
        std::cout << "Enter command (insert x / count x / erase x / show / quit): ";
        std::cin >> command;
        if (command == "insert") {
            std::cin >> x;
            btree.insert(x);
        }
        else if (command == "count") {
            std::cin >> x;
            std::cout << "Count of " << x << ": " << btree.count(x) << "\n";
        }
        else if (command == "erase") {
            std::cin >> x;
            if (btree.erase(x)) {
                std::cout << x << " erased.\n";
            }
            else {
                std::cout << x << " not found.\n";
            }
        }
        else if (command == "show") {
            btree.show_contents();
        }
        else if (command == "quit") {
            break;
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }

    return 0;
}

