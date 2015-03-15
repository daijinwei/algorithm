/*************************************************************************
	> File Name: tree.h
	> Author: David 
	> Mail:   daijinwei41@gmail.com
	> Created Time: Fri 13 Mar 2015 10:15:21 AM CST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H

struct TreeNode;
typedef struct TreeNode* TNode;
typedef TNode Position;
typedef TNode AvlTree;
typedef int ItemType;

struct TreeNode{
    ItemType item;
    TNode   left;
    TNode   right;
    int     height;     // the tree's heigh
};

int max(int x, int y);
/* Return the heigth of tree node */
int avl_tree_height(Position pnode);

Position avl_tree_single_rotate_with_left(Position node);
Position avl_tree_single_rotate_with_right(Position node);

/* double retoate */
Position avl_tree_double_rotate_with_left(Position node);
Position avl_tree_double_rotate_with_right(Position node);

/* Avl tree insert a node */
AvlTree avl_tree_insert(AvlTree tree, ItemType item);

Position avl_tree_inoder_traversal(AvlTree tree);
#endif
