#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

template<typename T>
class BTreeNode {
public:
    BTreeNode* parent;
    vector<BTreeNode*> children;
    vector<T> dataset;

    BTreeNode(BTreeNode* init_parent = nullptr)
        : parent(init_parent), children(), dataset() {
    }

    bool is_leaf() const {
        return children.empty();
    }
};

template<typename T>
class Bag {
private:
    const int MINIMUM;
    BTreeNode<T>* root_ptr;

    void fix_shortage(BTreeNode<T>* node) {
        if (!node || node->dataset.size() >= MINIMUM) return;

        if (node == root_ptr && root_ptr->dataset.empty()) {
            if (!root_ptr->is_leaf()) {
                BTreeNode<T>* new_root = root_ptr->children[0];
                new_root->parent = nullptr;
                delete root_ptr;
                root_ptr = new_root;
            }
            return;
        }

        BTreeNode<T>* parent = node->parent;
        if (!parent) return;

        auto it = find(parent->children.begin(), parent->children.end(), node);
        int index = distance(parent->children.begin(), it);

        if (index > 0 && parent->children[index - 1]->dataset.size() > MINIMUM) {
            BTreeNode<T>* left_sibling = parent->children[index - 1];
            node->dataset.insert(node->dataset.begin(), parent->dataset[index - 1]);
            parent->dataset[index - 1] = left_sibling->dataset.back();
            left_sibling->dataset.pop_back();

            if (!left_sibling->is_leaf()) {
                node->children.insert(node->children.begin(), left_sibling->children.back());
                left_sibling->children.back()->parent = node;
                left_sibling->children.pop_back();
            }
        }
        else if (index < parent->children.size() - 1 && parent->children[index + 1]->dataset.size() > MINIMUM) {
            BTreeNode<T>* right_sibling = parent->children[index + 1];
            node->dataset.push_back(parent->dataset[index]);
            parent->dataset[index] = right_sibling->dataset.front();
            right_sibling->dataset.erase(right_sibling->dataset.begin());

            if (!right_sibling->is_leaf()) {
                node->children.push_back(right_sibling->children.front());
                right_sibling->children.front()->parent = node;
                right_sibling->children.erase(right_sibling->children.begin());
            }
        }
        else if (index > 0) {
            BTreeNode<T>* left_sibling = parent->children[index - 1];
            left_sibling->dataset.push_back(parent->dataset[index - 1]);
            left_sibling->dataset.insert(left_sibling->dataset.end(), node->dataset.begin(), node->dataset.end());

            if (!node->is_leaf()) {
                left_sibling->children.insert(left_sibling->children.end(), node->children.begin(), node->children.end());
                for (auto child : node->children) {
                    child->parent = left_sibling;
                }
            }

            parent->dataset.erase(parent->dataset.begin() + index - 1);
            parent->children.erase(parent->children.begin() + index);
            delete node;
        }
        else {
            BTreeNode<T>* right_sibling = parent->children[index + 1];
            node->dataset.push_back(parent->dataset[index]);
            node->dataset.insert(node->dataset.end(), right_sibling->dataset.begin(), right_sibling->dataset.end());

            if (!right_sibling->is_leaf()) {
                node->children.insert(node->children.end(), right_sibling->children.begin(), right_sibling->children.end());
                for (auto child : right_sibling->children) {
                    child->parent = node;
                }
            }

            parent->dataset.erase(parent->dataset.begin() + index);
            parent->children.erase(parent->children.begin() + index + 1);
            delete right_sibling;
        }

        fix_shortage(parent);
    }

    void loose_erase(BTreeNode<T>* node, T data) {
        auto it = find(node->dataset.begin(), node->dataset.end(), data);

        if (it != node->dataset.end()) {
            if (node->is_leaf()) {
                node->dataset.erase(it);
            }
            else {
                int index = distance(node->dataset.begin(), it);
                BTreeNode<T>* pred = node->children[index];
                while (!pred->is_leaf()) {
                    pred = pred->children.back();
                }
                swap(*it, pred->dataset.back());
                loose_erase(pred, pred->dataset.back());
            }
        }
        else if (!node->is_leaf()) {
            if (data <= node->dataset.front()) {
                loose_erase(node->children.front(), data);
            }
            else if (data > node->dataset.back()) {
                loose_erase(node->children.back(), data);
            }
            else {
                for (size_t i = 0; i < node->dataset.size(); ++i) {
                    if (data <= node->dataset[i]) {
                        loose_erase(node->children[i], data);
                        break;
                    }
                }
            }
        }

        fix_shortage(node);
    }

    T remove_biggest(BTreeNode<T>* node) {
        if (node->is_leaf()) {
            T biggest = node->dataset.back();
            node->dataset.pop_back();
            return biggest;
        }
        else {
            return remove_biggest(node->children.back());
        }
    }

    void loose_insert(BTreeNode<T>* node, T data) {
        if (node->is_leaf()) {
            node->dataset.push_back(data);
            sort(node->dataset.begin(), node->dataset.end());
            return;
        }

        if (data <= node->dataset.front()) {
            loose_insert(node->children.front(), data);
        }
        else if (data > node->dataset.back()) {
            loose_insert(node->children.back(), data);
        }
        else {
            for (size_t i = 0; i < node->dataset.size(); ++i) {
                if (data <= node->dataset[i]) {
                    loose_insert(node->children[i], data);
                    break;
                }
            }
        }

        fix_excess(node);
    }

    void fix_excess(BTreeNode<T>* node) {
        if (node->dataset.size() <= 2 * MINIMUM) return;

        if (node == root_ptr) {
            BTreeNode<T>* new_root = new BTreeNode<T>();
            new_root->children.push_back(root_ptr);
            root_ptr->parent = new_root;
            root_ptr = new_root;
        }

        BTreeNode<T>* parent = node->parent;
        if (!parent) return;

        int mid_index = node->dataset.size() / 2;
        T middle_value = node->dataset[mid_index];

        BTreeNode<T>* right_child = new BTreeNode<T>(parent);
        right_child->dataset.assign(node->dataset.begin() + mid_index + 1, node->dataset.end());
        node->dataset.erase(node->dataset.begin() + mid_index, node->dataset.end());

        if (!node->is_leaf()) {
            right_child->children.assign(node->children.begin() + mid_index + 1, node->children.end());
            for (auto child : right_child->children) {
                child->parent = right_child;
            }
            node->children.erase(node->children.begin() + mid_index + 1, node->children.end());
        }

        parent->dataset.push_back(middle_value);
        sort(parent->dataset.begin(), parent->dataset.end());
        parent->children.push_back(right_child);

        fix_excess(parent);
    }

public:
    Bag(int minimum = 1) : MINIMUM(minimum), root_ptr(nullptr) {}

    void insert(T data) {
        if (!root_ptr) root_ptr = new BTreeNode<T>();
        loose_insert(root_ptr, data);
        fix_excess(root_ptr);
    }

    void erase_one(T data) {
        if (!root_ptr) return;
        loose_erase(root_ptr, data);
        fix_shortage(root_ptr);
    }

    void show_contents() const {
        if (!root_ptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<BTreeNode<T>*> q;
        q.push(root_ptr);

        while (!q.empty()) {
            BTreeNode<T>* node = q.front();
            q.pop();

            cout << "[ ";
            for (const auto& value : node->dataset) {
                cout << value << " ";
            }
            cout << "] ";

            for (auto child : node->children) {
                q.push(child);
            }
        }

        cout << endl;
    }
};

int main() {
    Bag<int> bag;

    bag.insert(10);
    bag.insert(20);
    bag.insert(5);
    bag.show_contents();

    bag.erase_one(20);
    bag.show_contents();

    bag.insert(30);
    bag.insert(40);
    bag.erase_one(10);
    bag.show_contents();

    return 0;
}
