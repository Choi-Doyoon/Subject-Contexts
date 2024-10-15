#ifndef NODE_H
#include<iostream>
using namespace std;

namespace node{
    class node{
        public:
        typedef double value_type;
        node(const value_type& init_data=value_type(),const node* init_link=NULL){
            data_field=init_data;
            link_field=init_link;
        }
        void set_data(const value_type& new_data);
        void set_link(node* new_link);
        value_type data() const;
        const node* link() const{return link_field;}
        node* link(){return link_field;}
        private:
        value_type data_field;
        node *link_field;
    };
}
#endif