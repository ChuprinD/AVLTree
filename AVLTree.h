#pragma once

#include <iostream>

using namespace std;

class node
    {
    public:
        int item_;
        int height_;
        node* left_;
        node* right_;

    node(int x)
        {
        left_ = nullptr;
        right_ = nullptr;
        item_ = x;
        height_ = 1;
        }
    };

node* insert(node* tree, int item);
node* find_min(node* tree);
node* remove_min(node* tree);
node* remove(node* tree, int item);
node* find(node* tree, int item);
void print(node* tree, int level);