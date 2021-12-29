#include "AVLTree.h"

int height(node* tree)
    {
    return tree ? tree->height_ : 0;
    }

int balance_factor(node* tree)
    {
    return height(tree->right_) - height(tree->left_);
    }

void fix_height(node* p)
    {
    int h_left = height(p->left_);
    int h_right = height(p->right_);
    p->height_ = (h_left > h_right ? h_left : h_right) + 1;
    }

node* rotate_right(node* tree)
    {
    node* tmp = tree->left_;
    tree->left_ = tmp->right_;
    tmp->right_ = tree;
    fix_height(tree);
    fix_height(tmp);
    return tmp;
    }

node* rotate_left(node* tree)
    {
    node* tmp = tree->right_;
    tree->right_ = tmp->left_;
    tmp->left_ = tree;
    fix_height(tree);
    fix_height(tmp);
    return tmp;
    }

node* balance(node* tree)
    {
    fix_height(tree);
    if (balance_factor(tree) == 2)
        {   
        if (balance_factor(tree->right_) < 0)
            tree->right_ = rotate_right(tree->right_);
        return rotate_left(tree);
        }
    if (balance_factor(tree) == -2)
        {
        if (balance_factor(tree->left_) > 0)
            tree->left_ = rotate_left(tree->left_);
        return rotate_right(tree);
        }
    return tree;
    }


node* insert(node* tree, int item)
    {
    if (!tree) return new node(item);
    if (item < tree->item_)
        tree->left_ = insert(tree->left_, item);
    else
        tree->right_ = insert(tree->right_, item);
    return balance(tree);
    }

node* find(node* tree, int item)
    {
    if (tree->item_ == item) return tree;
    if (tree->item_ < item) return find(tree->left_, item);
    else return find(tree->right_, item);
    }

node* find_min(node* tree)
    {
    return tree->left_ ? find_min(tree->left_) : tree;
    }

node* remove_min(node* tree)
    {
    if (tree->left_ == 0)
        return tree->right_;
    tree->left_ = remove_min(tree->left_);
    return balance(tree);
    }

node* remove(node* tree, int item)
    {
    if (!tree) return 0;
    if (item < tree->item_)
        tree->left_ = remove(tree->left_, item);
    else if (item > tree->item_)
        tree->right_ = remove(tree->right_, item);
    else
        {
        node* a = tree->left_;
        node* b = tree->right_;
        delete tree;
        if (!b) return a;
        node* min = find_min(b);
        min->right_ = remove_min(b);
        min->left_ = a;
        return balance(min);
        }
    return balance(tree);
    }

void print(node* tree, int level)
    {
    if (tree)
        {
        print(tree->left_, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << tree->item_ << '\n';
        print(tree->right_, level + 1);
        }
    }