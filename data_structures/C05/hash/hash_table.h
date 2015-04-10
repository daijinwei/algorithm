/*************************************************************************
	> File Name: hash_table.h
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Apr 2015 08:49:06 AM CST
 ************************************************************************/

#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <stdint.h>
#include <string>

class Node{
public:
    Node(int key, const std::stirng &str);
    int key;
    std::stirng value;
    Node *next;
};

class HashTable{
public:
    HashTable();

    bool insert(int key, const std::string &value);
    bool find(int key);
    std::string&
    operator[](int key);
private:
    bool insert(Node **node, int key, const std::string &value);
    Node *HashTable::find_node(int key);
    uint32_t hash_func(int key);
    enum{SIZE = 100};
    Node *nodes[SIZE];
};

#endif
