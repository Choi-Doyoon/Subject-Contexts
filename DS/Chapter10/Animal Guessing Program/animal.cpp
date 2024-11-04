#include<cstdlib>
#include<iostream>
#include<string>
#include "bintree.h"
#include "useful.h"
using namespace std;
using namespace bintreenode;
using namespace useful;

void ask_and_move(binary_tree_node<string>*& current_ptr){
    cout<<current_ptr->data();
    if(inquire("Please answer")){current_ptr=current_ptr->left();}
    else{current_ptr=current_ptr->right();}
}

binary_tree_node<string>* beginning_tree(){
    binary_tree_node<string> *root_ptr;
    binary_tree_node<string> *child_ptr;

    const string root_question("Are you a mammal?");
    const string left_question("Are you bigger than a cat?");
    const string right_question("Do you live underwater?");
    const string animal1("Kangaroo");
    const string animal2("Mouse");
    const string animal3("Trout");
    const string animal4("Robin");

    root_ptr = new binary_tree_node<string> (root_question);
 
    child_ptr = new binary_tree_node<string> (left_question);
    child_ptr->set_left( new binary_tree_node<string> (animal1) );
    child_ptr->set_right( new binary_tree_node<string> (animal2) );
    root_ptr->set_left(child_ptr);
 
    child_ptr = new binary_tree_node<string> (right_question);
    child_ptr->set_left( new binary_tree_node<string> (animal3) );
    child_ptr->set_right( new binary_tree_node<string> (animal4) );
    root_ptr->set_right(child_ptr);
    return root_ptr;
}

void instruct() {
    cout << "Welcome to the animal guessing game!" << endl;
    cout << "Think of an animal, and I'll try to guess what it is by asking questions." << endl;
    cout << "If I can't guess, you can teach me by adding a new question and answer!" << endl;
    cout << "Let's start!" << endl;
}


void learn(binary_tree_node<string>* leaf_ptr){
    string guess_animal; 
    string correct_animal; 
    string new_question; 
    guess_animal = leaf_ptr->data( );
    cout << "I give up. What are you? " << endl;
    getline(cin, correct_animal);
    cout << "Please type a yes/no question that will distinguish a" << endl;
    cout << correct_animal << " from a " << guess_animal << "." << endl;
    cout << "Your question: " << endl;
    getline(cin, new_question);
 
    leaf_ptr->set_data(new_question);
    cout << "As a " << correct_animal << ", " << new_question << endl;
    if (inquire("Please answer"))
    {
        leaf_ptr->set_left( new binary_tree_node<string> (correct_animal) );
        leaf_ptr->set_right( new binary_tree_node<string> (guess_animal) );
    }
    else
    {
        leaf_ptr->set_left( new binary_tree_node<string> (guess_animal) );
        leaf_ptr->set_right( new binary_tree_node<string> (correct_animal) );
    }
}

void play(binary_tree_node<string>* current_ptr){
    cout << "Think of an animal, then press the return key.";
    eat_line( );
    while (!current_ptr->is_leaf( )){
        ask_and_move(current_ptr);
    }
    cout << ("My guess is " + current_ptr->data);
    if (!inquire(". Am I right?")){learn(current_ptr);}
    else{cout << "I knew it all along!" << endl;}
}

int main(){
    binary_tree_node<string> *taxonomy_root_ptr;
    instruct( );
    taxonomy_root_ptr = beginning_tree( );
    do{
        play(taxonomy_root_ptr);
    } while (inquire("Shall we play again?"));
    cout << "Thank you for teaching me a thing or two." << endl;
    return EXIT_SUCCESS;
}