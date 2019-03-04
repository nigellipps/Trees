/*
 Nigel Lipps
 WordTree.cpp
 */
#include <iostream>
#include <string>
#include "WordTree.h"
using namespace std;

typedef string ItemType;

// copy constructor
WordTree::WordTree(const WordTree& rhs) {
    *this = rhs;
}

// assignment operator
const WordTree& WordTree::operator=(const WordTree& rhs) {
    if(rhs.root == nullptr)
        root = nullptr;
    else
        root = new WordNode(*rhs.root);
    return *this;
}

//the helper function
//void addHelp(ItemType x, WordNode *ptr){
//    //if the node is the same as x, increase the count
//    if(ptr -> m_data == x){
//        ptr -> m_count++;
//        return;
//    }
//    //if x is less than the current node, move to the left
//    else if(x < ptr -> m_data) {
//        if(ptr -> m_left == nullptr) {
//            ptr -> m_left = new WordNode(x);
//            return;
//        }
//        addHelp(x, ptr->m_left);
//        //ptr = ptr -> m_left;
//    }
//    //if x is greater than the current node, move to the right
//    else {
//        if(ptr -> m_right == nullptr) {
//            ptr -> m_right = new WordNode(x);
//            return;
//        }
//        addHelp(x, ptr->m_right);
//        //ptr = ptr -> m_right;
//    }
//}

// Adds the given word to the tree if it is not
// already in the tree OR increments the appropriate
// counter if it is already there
void WordTree::add(ItemType x) {
    //checks to see if a new tree is necessary
    if(root == nullptr)
        root = new WordNode(x);
    else {
        WordNode *ptr = root;
        while(ptr != nullptr){
//            addHelp(x, root);
            //if the node is the same as x, increase the count
            if(ptr -> m_data == x){
                ptr -> m_count++;
                return;
            }
            //if x is less than the current node, move to the left
            else if(x < ptr -> m_data) {
                if(ptr -> m_left == nullptr) {
                    ptr -> m_left = new WordNode(x);
                    return;
                }
                ptr = ptr -> m_left;
            }
            //if x is greater than the current node, move to the right
            else {
                if(ptr -> m_right == nullptr) {
                    ptr -> m_right = new WordNode(x);
                    return;
                }
                ptr = ptr -> m_right;
            }
        }
    }
}

// Returns the number of distince words / nodes
int WordTree::distinctWords() const{
    if(root == nullptr)
        return 0;
    return root->distinctWords();
}

// Returns the total number of words inserted,
// including duplicate values
int WordTree::totalWords() const {
    if(root == nullptr)
        return 0;
    return root->totalWords();
}

// Prints the LinkedList
ostream& operator<<(ostream &out, const WordTree& rhs){
    if(rhs.root != nullptr)
        out << *rhs.root;
    return out;
}

// Destroys all the dynamically allocated memory
// in the tree.
WordTree::~WordTree(){
    deleteTree(root);
}

//the delete tree helper function
void WordTree::deleteTree(WordNode *temp){
    if(temp == nullptr) return;
    deleteTree(temp -> m_left);
    deleteTree(temp -> m_right);
    delete temp;
}

// Prints the words of the tree in alphabetical order,
// and next to each word, the number of times each
// word occurs in the text
ostream& operator << (ostream &out, const WordNode &rhs){
    if(rhs.m_left != nullptr)
        out << *rhs.m_left;
    out << rhs.m_data << " " << rhs.m_count << endl;
    if(rhs.m_right != nullptr)
        out << *rhs.m_right;
    return out;
}
