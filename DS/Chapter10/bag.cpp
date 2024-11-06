#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

template<class Item>
class binary_tree_node {
public:
    // Constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL) {
        data_field = init_data;
        left_field = init_left;
        right_field = init_right;
    }

    Item& data() { return data_field; }
    const Item& data() const { return data_field; }

    binary_tree_node*& left() { return left_field; }
    const binary_tree_node* left() const { return left_field; }

    binary_tree_node*& right() { return right_field; }
    const binary_tree_node* right() const { return right_field; }

    void set_data(const Item& new_data) { data_field = new_data; }
    void set_left(binary_tree_node* new_left) { left_field = new_left; }
    void set_right(binary_tree_node* new_right) { right_field = new_right; }
    bool is_leaf() const { return (left_field == NULL && right_field == NULL); }

private:
    Item data_field;
    binary_tree_node* left_field;
    binary_tree_node* right_field;
};

template<class Item>
class bag {
public:
    typedef size_t size_type;
    typedef Item value_type;

    // Constructors and Destructor
    bag() : root_ptr(nullptr) {}
    bag(const bag& source) { root_ptr = tree_copy(source.root_ptr); }
    ~bag() { tree_clear(root_ptr); }

    size_type erase(const Item& target) {
        size_type count = 0;
        while (erase_one(target)) { ++count; }
        return count;
    }

    bool erase_one(const Item& target) {
        return erase_one_node(root_ptr, target);
    }

    void insert(const Item& entry) {
        insert_node(root_ptr, entry);
    }

    void operator +=(const bag& addend) {
        insert_all(addend.root_ptr);
    }

    void operator =(const bag& source) {
        if (this == &source) return;
        tree_clear(root_ptr);
        root_ptr = tree_copy(source.root_ptr);
    }

    size_type size() const { return tree_size(root_ptr); }
    size_type count(const Item& target) const { return tree_count(root_ptr, target); }

    void insert_all(binary_tree_node<Item>* addroot_ptr) {
        if (addroot_ptr != nullptr) {
            insert(addroot_ptr->data());
            insert_all(addroot_ptr->left());
            insert_all(addroot_ptr->right());
        }
    }

private:
    binary_tree_node<Item>* root_ptr;

    // Helper functions
    void insert_node(binary_tree_node<Item>*& node_ptr, const Item& entry) {
        if (node_ptr == nullptr) {
            node_ptr = new binary_tree_node<Item>(entry);
        }
        else if (entry < node_ptr->data()) {
            insert_node(node_ptr->left(), entry);
        }
        else {
            insert_node(node_ptr->right(), entry);
        }
    }

    bool erase_one_node(binary_tree_node<Item>*& node_ptr, const Item& target) {
        if (node_ptr == nullptr) return false;

        if (target < node_ptr->data()) {
            return erase_one_node(node_ptr->left(), target);
        }
        else if (target > node_ptr->data()) {
            return erase_one_node(node_ptr->right(), target);
        }
        else {
            binary_tree_node<Item>* old_node = node_ptr;
            if (node_ptr->left() == nullptr) {
                node_ptr = node_ptr->right();
            }
            else if (node_ptr->right() == nullptr) {
                node_ptr = node_ptr->left();
            }
            else {
                replace_parent(old_node, old_node->left());
            }
            delete old_node;
            return true;
        }
    }

    void replace_parent(binary_tree_node<Item>*& old_root, binary_tree_node<Item>*& node_ptr) {
        if (node_ptr->right() != nullptr) {
            replace_parent(old_root, node_ptr->right());
        }
        else {
            old_root->set_data(node_ptr->data());
            old_root = node_ptr;
            node_ptr = node_ptr->left();
        }
    }

    size_type tree_size(binary_tree_node<Item>* node_ptr) const {
        if (node_ptr == nullptr) return 0;
        return 1 + tree_size(node_ptr->left()) + tree_size(node_ptr->right());
    }

    size_type tree_count(binary_tree_node<Item>* node_ptr, const Item& target) const {
        if (node_ptr == nullptr) return 0;
        size_type count = (node_ptr->data() == target) ? 1 : 0;
        return count + tree_count(node_ptr->left(), target) + tree_count(node_ptr->right(), target);
    }

    binary_tree_node<Item>* tree_copy(binary_tree_node<Item>* node_ptr) {
        if (node_ptr == nullptr) return nullptr;
        return new binary_tree_node<Item>(node_ptr->data(), tree_copy(node_ptr->left()), tree_copy(node_ptr->right()));
    }

    void tree_clear(binary_tree_node<Item>*& node_ptr) {
        if (node_ptr != nullptr) {
            tree_clear(node_ptr->left());
            tree_clear(node_ptr->right());
            delete node_ptr;
            node_ptr = nullptr;
        }
    }
};

template<class Item>
bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2) {
    bag<Item> result = b1;  // Copy of b1
    result += b2;           // Add contents of b2
    return result;
}

int main() {
    // bag<int> 객체 생성
    bag<int> bag1;

    // 값 삽입
    bag1.insert(10);
    bag1.insert(20);
    bag1.insert(10);
    bag1.insert(30);

    // 각 값의 개수 출력
    cout << "10의 개수: " << bag1.count(10) << endl;
    cout << "20의 개수: " << bag1.count(20) << endl;
    cout << "30의 개수: " << bag1.count(30) << endl;

    // 전체 요소의 수 출력
    cout << "bag1의 전체 크기: " << bag1.size() << endl;

    // 하나의 10을 제거
    if (bag1.erase_one(10)) {
        cout << "10을 하나 제거했습니다." << endl;
    }

    // 제거 후 10의 개수와 전체 크기 확인
    cout << "10의 개수 (제거 후): " << bag1.count(10) << endl;
    cout << "bag1의 전체 크기 (제거 후): " << bag1.size() << endl;

    // 모든 20 제거
    size_t removed_count = bag1.erase(20);
    cout << "20을 " << removed_count << "개 제거했습니다." << endl;

    // 20의 개수와 전체 크기 확인
    cout << "20의 개수 (제거 후): " << bag1.count(20) << endl;
    cout << "bag1의 전체 크기 (제거 후): " << bag1.size() << endl;

    // bag 복사 및 덧셈 연산 테스트
    bag<int> bag2(bag1);  // 복사 생성자 사용
    bag2.insert(40);

    bag<int> bag3 = bag1 + bag2;  // + 연산자 사용

    // bag3의 내용 확인
    cout << "bag3의 전체 크기: " << bag3.size() << endl;
    cout << "10의 개수 (bag3): " << bag3.count(10) << endl;
    cout << "30의 개수 (bag3): " << bag3.count(30) << endl;
    cout << "40의 개수 (bag3): " << bag3.count(40) << endl;

    return 0;
}
