// File: a4.hpp
// Liam
// Wong
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A4_HPP
#define A4_HPP

#include <ostream>
#include "symbol.hpp"
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using std::vector;
using std::priority_queue;
using std::stack;

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE

// IMPLEMENT YOUR FUNCTION huffman_tree

//bool operator<(symbol s1, symbol s2) {      // true if s1 has greater priority aka s1 has greater frequency/greater ASCII
//    if (s1.count == s2.count) {
//        return s1.value < s2.value;
//    } else return (s1.count < s2.count);
//}

template<typename Iter>
bnode<symbol> *huffman_tree(Iter first, Iter last) {
    priority_queue<bnode<symbol>*, vector<bnode<symbol> >, symbol> sortedQ;
//    stack<bnode<symbol>> minHeap;
    while (first != last) {
        auto tempNode = new bnode<symbol>;
        tempNode->value = *first;
        sortedQ.push(tempNode);
        first++;
    }
    while (sortedQ.size() > 1) {
        auto node1 = sortedQ.top();
        sortedQ.pop();
        auto node2 = sortedQ.top();
        sortedQ.pop();
        auto parent = new bnode<symbol>;
        if (node1.value.value < node2.value.value) {
            parent->value.value = node2.value.value;
        } else { parent->value.value = node1.value.value; }
        parent->value.count = node1.value.count + node2.value.count;
        parent->left = &node1;
        parent->right = &node2;
        sortedQ.push(parent);
//        goto empty;
    }
    return const_cast<bnode<symbol> *>(&sortedQ.top());
}


// IMPLEMENT YOUR FUNCTION print_dictionary
void print_dictionary(std::ostream &os, bnode<symbol> *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        os << root->value.value << " \n";
    }
    if (root->left != nullptr) {
        os << 0;
        return print_dictionary(os, root->left);
    }
    if (root->right != nullptr) {
        os << 1;
        return print_dictionary(os, root->right);
    }
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol> *root){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        delete root;
    }
    if(root->left != nullptr){
        release_tree(root->left);
    }
    if(root->right != nullptr){
        release_tree(root->right);
    }
}

#endif // A4_HPP
