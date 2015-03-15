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
typedef TNode SearchTree;
typedef int ItemType;

struct TreeNode{
    ItemType item;
    TNode   left;
    TNode   right;
};

/* Make the search tree empty */
SearchTree bstree_make_empty(SearchTree tree);

/* Create a binary search tree */
SearchTree bstree_insert(SearchTree tree, ItemType item);

/* Find the element in the tree */
Position bstree_find(SearchTree tree, ItemType item);

/* Fint the min Item in the tree */
Position bstree_find_min(SearchTree tree);

/* Fint the max Item in the tree */
Position bstree_find_max(SearchTree tree);

/* Delete the item in the tree */
Position bstree_delete(SearchTree tree);

/* Delete the min item in the tree */
void bstree_delete_min(SearchTree tree);

/* tree inoder traversal */
Position bstree_inoder_traversal(SearchTree tree);

#endif
