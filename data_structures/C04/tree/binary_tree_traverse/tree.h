/*************************************************************************
	> File Name: tree.h
	> Author: David 
	> Mail:   daijinwei41@gmail.com
	> Created Time: Fri 13 Mar 2015 10:15:21 AM CST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H

struct BTreeNode;
typedef struct BTreeNode* TNode;
typedef TNode Position;
typedef int ItemType;

struct BTreeNode{
    ItemType item;
    TNode   parent;
    TNode   left;
    TNode   right;
};

#endif
