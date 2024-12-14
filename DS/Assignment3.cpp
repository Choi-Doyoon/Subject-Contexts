#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

template<typename T>
class Bag {
private:
    class Node {
    public:
        Node* parent;
        vector<Node*> children;
        vector<T> dataset;

        Node(Node* init_parent = nullptr) {
            parent = init_parent;
        }

        bool is_leaf() {
            return children.empty();
        }

        int count_data(const T& data) {
            return std::count(dataset.begin(), dataset.end(), data);
        }

        void loose_insert(T data) {
            dataset.push_back(data);
            sort(dataset.begin(), dataset.end());
        }

        void loose_erase(const T& data) {
            auto it = find(dataset.begin(), dataset.end(), data);
            if (it != dataset.end()) {
                dataset.erase(it);
            }
        }

        int find_data_index(const T& data) {
            auto it = find(dataset.begin(), dataset.end(), data);
            if (it != dataset.end()) {
                return distance(dataset.begin(), it);
            }
            return -1;
        }

        void merge_children(int index) {
            for (int i = 0; i < children[index + 1]->dataset.size(); i++) {
                children[index]->dataset.push_back(children[index + 1]->dataset[i]);
            }
            if (!children[index]->is_leaf()) {
                for (int i = 0; i < children[index + 1]->children.size(); i++) {
                    children[index]->children.push_back(children[index + 1]->children[i]);
                }
            }
            children.erase(children.begin() + index + 1);
        }

        Node* split_child(int index) {
            int mid = children[index]->dataset.size() / 2;
            loose_insert(children[index]->dataset[mid]);
            Node* left = new Node(children[index]->parent);
            Node* right = new Node(children[index]->parent);
            for (int i = 0; i < children[index]->dataset.size(); i++) {
                if (i < mid) {
                    left->dataset.push_back(children[index]->dataset[i]);
                }
                else if (i > mid) {
                    right->dataset.push_back(children[index]->dataset[i]);
                }
            }
            if (!children[index]->is_leaf()) {
                for (int i = 0; i < children[index]->children.size(); i++) {
                    if (i <= mid) {
                        left->children.push_back(children[index]->children[i]);
                        children[index]->children[i]->parent = left;
                    }
                    else if (i > mid) {
                        right->children.push_back(children[index]->children[i]);
                        children[index]->children[i]->parent = right;
                    }
                }
            }

            Node* temp = children[index];
            children[index] = right;
            children.insert(children.begin() + index, left);
            delete temp;
            return right->parent;
        }

        void print_data() {
            cout << "[ ";
            for (int i = 0; i < dataset.size(); i++) {
                cout << dataset[i] << " ";
            }
            cout << "]";
        }
    };

    const int M;
    Node* root_ptr;

    void fix_excess(Node* node) {
        if (node->dataset.size() < M) {
            return;
        }
        if (node == root_ptr) {
            Node* new_root = new Node(nullptr);
            new_root->children.push_back(root_ptr);
            root_ptr->parent = new_root;
            root_ptr = new_root->split_child(0);
        }
        else {
            auto it = find(node->parent->children.begin(), node->parent->children.end(), node);
            int split_index = distance(node->parent->children.begin(), it);
            fix_excess(node->parent->split_child(split_index));
        }
    }

    void fix_shortage(Node* node) {
        if (node == root_ptr && root_ptr->dataset.empty()) {
            // If root is empty and has children, make the first child the new root
            if (!root_ptr->is_leaf()) {
                Node* temp = root_ptr;
                root_ptr = root_ptr->children[0];
                root_ptr->parent = nullptr;
                delete temp;
            }
            return;
        }

        Node* parent = node->parent;
        auto it = find(parent->children.begin(), parent->children.end(), node);
        int index = distance(parent->children.begin(), it);
        if (index > 0 && parent->children[index - 1]->dataset.size() > ceil(M / 2.0f) - 1) {
            Node* left_sibling = parent->children[index - 1];
            node->dataset.insert(node->dataset.begin(), parent->dataset[index - 1]);
            parent->dataset[index - 1] = left_sibling->dataset.back();
            left_sibling->dataset.pop_back();
            if (!node->is_leaf()) {
                node->children.insert(node->children.begin(), left_sibling->children.back());
                left_sibling->children.pop_back();
            }
        }
        else if (index < parent->dataset.size() && parent->children[index + 1]->dataset.size() > ceil(M / 2.0f) - 1) {
            Node* right_sibling = parent->children[index + 1];
            node->dataset.push_back(parent->dataset[index]);
            parent->dataset[index] = right_sibling->dataset.front();
            right_sibling->dataset.erase(right_sibling->dataset.begin());
            if (!node->is_leaf()) {
                node->children.push_back(right_sibling->children.front());
                right_sibling->children.erase(right_sibling->children.begin());
            }
        }
        else if (index > 0) {
            Node* left_sibling = parent->children[index - 1];
            left_sibling->dataset.push_back(parent->dataset[index - 1]);
            left_sibling->dataset.insert(left_sibling->dataset.end(), node->dataset.begin(), node->dataset.end());
            parent->dataset.erase(parent->dataset.begin() + index - 1);
            parent->children.erase(parent->children.begin() + index);
            if (!node->is_leaf()) {
                left_sibling->children.insert(left_sibling->children.end(), node->children.begin(), node->children.end());
            }
            delete node;
        }
        else {
            Node* right_sibling = parent->children[index + 1];
            node->dataset.push_back(parent->dataset[index]);
            node->dataset.insert(node->dataset.end(), right_sibling->dataset.begin(), right_sibling->dataset.end());
            parent->dataset.erase(parent->dataset.begin() + index);
            parent->children.erase(parent->children.begin() + index + 1);
            if (!right_sibling->is_leaf()) {
                node->children.insert(node->children.end(), right_sibling->children.begin(), right_sibling->children.end());
            }
            delete right_sibling;
        }
        if (parent->dataset.size() < ceil(M / 2.0f) - 1) {
            fix_shortage(parent);
        }
    }
    Node* search_for_data(Node* node, const T& data) {
        if (!node) return nullptr;
        if (find(node->dataset.begin(), node->dataset.end(), data) != node->dataset.end()) {
            return node;
        }
        for (Node* child : node->children) {
            Node* found = search_for_data(child, data);
            if (found) return found;
        }
        return nullptr;
    }
    Node* search_recursion(Node* node, T data) {
        if (node->is_leaf()) {
            auto it = find(node->dataset.begin(), node->dataset.end(), data);
            return it != node->dataset.end() ? node : nullptr;
        }
        if (data < node->dataset[0]) {
            return search_recursion(node->children[0], data);
        }
        for (int i = 1; i < node->dataset.size(); ++i) {
            if (node->dataset[i - 1] < data && data < node->dataset[i]) {
                return search_recursion(node->children[i], data);
            }
        }
        return search_recursion(node->children.back(), data);
    }
    Node* find_insert_point(Node* node, T data) {
        if (node->is_leaf()) {
            return node;
        }
        if (data <= node->dataset[0]) {
            return find_insert_point(node->children[0], data);
        }
        for (int i = 1; i < node->dataset.size(); ++i) {
            if (node->dataset[i - 1] < data && data < node->dataset[i]) {
                return find_insert_point(node->children[i], data);
            }
        }
        return find_insert_point(node->children.back(), data);
    }

    void loose_insert(Node* node, T data) {
        node->dataset.push_back(data);
        sort(node->dataset.begin(), node->dataset.end());
    }

    void loose_erase(Node* node, T data) {
        auto it = find(node->dataset.begin(), node->dataset.end(), data);
        if (it != node->dataset.end()) {
            node->dataset.erase(it);
        }
    }

    void remove_biggest(Node* node, T& data) {
        if (node->is_leaf()) {
            data = node->dataset.back();
            node->dataset.pop_back();
        }
        else {
            remove_biggest(node->children.back(), data);
        }
    }

    void print_tree(Node* node, int space) {
        if (!node) return;
        int count = 5;
        space += count;
        for (int i = node->children.size() - 1; i >= (int)node->dataset.size(); --i) {
            print_tree(node->children[i], space);
        }
        cout << endl;
        for (int i = space; i > count; --i) {
            cout << " ";
        }
        for (int i = node->dataset.size() - 1; i >= 0; --i) {
            cout << node->dataset[i] << " "<<endl;
        }
        for (int i = (int)node->dataset.size() - 1; i >= 0; --i) {
            if (i < (int)node->children.size()) {
                print_tree(node->children[i], space);
            }
        }
    }
public:
    Bag(int maximum = 3) : M(maximum) {
        root_ptr = nullptr;
    }

    int count(T data) {
        int total_count = 0;
        queue<Node*> q;
        if (root_ptr) {
            q.push(root_ptr);
        }
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            total_count += current->count_data(data);

            for (Node* child : current->children) {
                q.push(child);
            }
        }
        return total_count;
    }

    void insert(T data) {
        if (root_ptr == nullptr) {
            root_ptr = new Node();
            loose_insert(root_ptr, data);
        }
        else {
            Node* insert_point = find_insert_point(root_ptr, data);
            loose_insert(insert_point, data);
            fix_excess(insert_point);
        }
    }

    void erase_one(const T& data) {
        Node* target_node = search_for_data(root_ptr, data);
        if (!target_node) {
            return; 
        }
        target_node->loose_erase(data);
    }

    void show_contents() {
        if (!root_ptr) {
            cout << "[ ]" << endl;
            return;
        }
        print_tree(root_ptr, 0);
    }
};

int main() {
    Bag<int> bag(3);
    string command;

    cout << "Welcome to the Bag program. Available commands:" << endl;
    cout << "  insert x - Inserts x into the bag" << endl;
    cout << "  erase x - Erases one occurrence of x from the bag" << endl;
    cout << "  count x - Counts the occurrences of x in the bag" << endl;
    cout << "  quit - Exits the program" << endl;

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;

        if (command == "insert") {
            int x;
            cin >> x;
            cout << "Before insert:" << endl;
            bag.show_contents();
            bag.insert(x);
            cout << "After insert:" << endl;
            bag.show_contents();
        }
        else if (command == "erase") {
            int x;
            cin >> x;
            cout << "Before erase:" << endl;
            bag.show_contents();
            bag.erase_one(x);
            cout << "After erase:" << endl;
            bag.show_contents();
        }
        else if (command == "count") {
            int x;
            cin >> x;
            cout << "Count of " << x << ": " << bag.count(x) << endl;
        }
        else if (command == "quit") {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid command! Please try again." << endl;
        }
    }
    return 0;
}
