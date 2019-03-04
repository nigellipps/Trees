/*
 Nigel Lipps
 WordTree.h
 */

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>

typedef std::string ItemType;

struct WordNode {
    ItemType m_data;
    WordNode *m_left;
    WordNode *m_right;
    //counter variable for number of words
    int m_count;
    // You may add additional data members and member functions in WordNode

    WordNode(ItemType data) {
        m_data = data;
        m_left = m_right = nullptr;
        m_count = 1;
    }

    WordNode(const WordNode &n) {
        m_data = n.m_data;
        m_count = n.m_count;
        if(n.m_left != nullptr)
            m_left = new WordNode(*n.m_left);
        else
            m_left = nullptr;
        if(n.m_right != nullptr)
            m_right = new WordNode(*n.m_right);
        else
            m_right = nullptr;
    }

    int distinctWords() {
        int count = 1;
        if(m_left != nullptr)
            count += m_left->distinctWords();
        if(m_right != nullptr)
            count += m_right->distinctWords();
        return count;
    }

    int totalWords() {
        int count = m_count;
        if(m_left != nullptr)
            count += m_left->totalWords();
        if(m_right != nullptr)
            count += m_right->totalWords();
        return count;
    }

    friend std::ostream& operator << (std::ostream &out, const WordNode &n);

};

class WordTree {
private:
    WordNode *root;
    void deleteTree(WordNode *w);
    //not impemented helper function for the add function
    void addHelp(ItemType v,WordNode *ptr);
public:    
    // default constructor
    WordTree() : root(nullptr) { };
    
    // copy constructor
    WordTree(const WordTree& rhs);
    
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    
    // Adds the given word to the tree if it is not
    // already in the tree OR increments the appropriate
    // counter if it is already there
    void add(ItemType v);
    
    // Returns the number of distince words / nodes
    int distinctWords() const;
    
    // Returns the total number of words inserted,
    // including duplicate values
    int totalWords() const;
    
    // Prints the words of the tree in alphabetical order,
    // and next to each word, the number of times each
    // word occurs in the text
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);
    
    // Destroys all the dynamically allocated memory
    // in the tree
    ~WordTree();
};
#endif /* WordTree_h */
