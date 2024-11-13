#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template <typename T>
class dnode {
public:
    T data;          
    dnode<T>* next;
    dnode<T>* prev;  

    dnode(const T& item){
        data = item;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    dnode<T>* head;
    dnode<T>* tail;

public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        list_clear(); 
    }

    int list_length() const {
        int length = 0;
        dnode<T>* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        return length;
    }

    bool list_search(const T& item) const {
        dnode<T>* current = head;
        while (current) {
            if (current->data == item) {return true;}
            current = current->next;
        }
        return false;
    }

    dnode<T>* list_locate(const T& item) const {
        dnode<T>* current = head;
        while (current) {
            if (current->data == item) {return current;}
            current = current->next;
        }
        return nullptr;
    }

    void list_copy(const DoublyLinkedList<T>& other) {
        list_clear(); 
        dnode<T>* current = other.head;
        while (current) {
            list_tail_insert(current->data);
            current = current->next;
        }
    }

    bool list_head_insert(const T& item) {
        if (list_search(item)) {return false;} 
        dnode<T>* newNode = new dnode<T>(item);
        if (!head){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }

    bool list_tail_insert(const T& item) {
        if (list_search(item)) {return false;} 
        dnode<T>* newNode = new dnode<T>(item);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        return true;
    }

    bool list_insert(dnode<T>* node, const T& item) {
        if (list_search(item) || !node) {return false;}
        dnode<T>* newNode = new dnode<T>(item);
        newNode->next = node->next;
        newNode->prev = node;

        if (node->next) {
            node->next->prev = newNode;
        } 
        else {
            tail = newNode; 
        }
        node->next = newNode;
        return true;
    }

    bool list_head_remove() {
        if (!head) {return false;}
        dnode<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return true;
    }

    bool list_tail_remove() {
        if (!tail) {return false;}
        dnode<T>* temp = tail;
        tail = tail->prev;
        if (tail) {tail->next = nullptr;}
        else {head = nullptr;}
        delete temp;
        return true;
    }

    bool list_remove(dnode<T>* node) {
        if (!node) {return false;}
        if (node == head) {
            return list_head_remove();
        }
        if (node == tail) {
            return list_tail_remove();
        }
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        delete node;
        return true;
    }

    void list_clear() {
        while (head) {
            list_head_remove();
        }
    }
    
    void show_contents() const {
        dnode<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    dnode<T>* get_head() const { return head; }
    dnode<T>* get_tail() const { return tail; }
};

template <typename T>
class OurSet {
private:
    DoublyLinkedList<T> list;

public:
    OurSet() = default;

    OurSet(const OurSet<T>& other) {
        dnode<T>* current = other.list.get_head();
        while (current) {
            list.list_tail_insert(current->data);
            current = current->next;
        }
    }

    ~OurSet() {}

    bool insert(const T& item) {
        cout << "Before insert: "<<endl;
        show_contents();
        bool result = list.list_tail_insert(item);
        cout << "After insert " << item << endl;
        show_contents();
        return result;
    }

    bool erase(const T& item) {
        cout << "Before erase: ";
        show_contents();
        dnode<T>* nodeToRemove = list.list_locate(item);
        if (nodeToRemove) {
            list.list_remove(nodeToRemove);
            cout << "After erase " << item << ": ";
            show_contents();
            return true;
        }
        cout << "Item " << item << " not found for erase." << endl;
        return false; 
    }

    int count(const T& item) const {
        return list.list_search(item) ? 1 : 0; 
    }

    OurSet<T>& operator=(const OurSet<T>& other) {
        if (this != &other) {
            list.list_clear(); 
            dnode<T>* current = other.list.get_head();
            while (current) {
                list.list_tail_insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    OurSet<T>& operator+=(const OurSet<T>& other) {
        dnode<T>* current = other.list.get_head();
        while (current) {
            this->insert(current->data); 
            current = current->next;
        }
        return *this;
    }

    OurSet<T> operator+(const OurSet<T>& other) const {
        OurSet<T> result = *this; 
        result += other; 
        return result;
    }

    bool operator==(const OurSet<T>& other) const {
        dnode<T>* current = list.get_head();
        while (current) {
            if (!other.list.list_search(current->data)) {
                return false;
            }
            current = current->next;
        }
        current = other.list.get_head();
        while (current) {
            if (!list.list_search(current->data)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool operator!=(const OurSet<T>& other) const {
        return !(*this == other);
    }
};