#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

namespace binarytreenode{
    template<class Item>
    class binary_tree_node{
        public:
            //Constructor
            binary_tree_node(const Item& init_data = Item(),binary_tree_node* init_left=NULL,binary_tree_node* init_right=NULL){
                data_field=init_data;
                left_field=init_left;
                right_field=init_right;
            }
            //data
            Item& data(){return data_field;}
            const Item& data() const{return data_field;}

            //left
            binary_tree_node*& left(){return left_field;}
            const binary_tree_node* left() const{return left_field;}

            //right
            binary_tree_node*& right(){return right_field;}
            const binary_tree_node* right() const{return right_field;}

            void set_data(const Item& new_data){data_field=new_data;}
            void set_left(binary_tree_node* new_left){left_field=new_left;}
            void set_right(binary_tree_node* new_right){right_field=new_right;}
            bool is_leaf() const{return (left_field==NULL&&right_field==NULL);}

            //tree clear
            void tree_clear(binary_tree_node<Item>*& root_ptr){
                if(toor_ptr!=NULL){
                    tree_clear(root_ptr->left());
                    tree_clear(root_ptr->right());
                    delete root_ptr;
                    root_ptr=NULL;
                }
            }

            //tree copy
            binary_tree_node<Item>* tree_copy(binary_tree_node<Item>* root_ptr){
                binary_tree_node<Item> *l_ptr;
                binary_tree_node<Item> *r_ptr;

                if(root_ptr==NULL){return NULL;}
                else{
                    l_ptr=tree_copy(root_ptr->left());
                    r_ptr=tree_copy(root_ptr->right());
                    return new binary_tree_node<Item>(root_ptr->data(),l_ptr,r_ptr);
                }
            }

            //Pre-Order Traversal
            void preorder_print(const binary_tree_node<Item>* root_ptr){
                if(root_ptr!=NULL){
                    cout<<root_ptr->data()<<endl;
                    preorder_print(root_ptr->left());
                    preorder_print(root_ptr->right());
                }
            }

            //In-Order Traversal
            void inorder_print(const binary_tree_node<Item>* root_ptr){
                if(root_ptr != NULL){
                    inorder_print(root_ptr->left());
                    cout<<root_ptr->data()<<endl;
                    inorder_print(root_ptr->right());
                }
            }

            //Post-Order Traversal
            void postorder_print(const binary_tree_node<Item>* root_ptr){
                if(root_ptr!=NULL){
                    postorder_print(root_ptr->left());
                    postorder_print(root_ptr->right());
                    cout<<root_ptr->data()<<endl;
                }
            }
        private:
            Item data_field; //for storing data
            binary_tree_node* left_field; //a pointer to the left child node
            binary_tree_node* right_field; //a pointer to the right chile node
    };
}
#endif