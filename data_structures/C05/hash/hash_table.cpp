/*************************************************************************
	> File Name: hash_table.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Apr 2015 08:54:46 AM CST
 ************************************************************************/

#include<iostream>
#include "hash_table.h"


Node::Node(int key, const std::string &str):
    key(key), value(str), next(NULL){}

HashTable::HashTable(){
    memset(nodes, 0, SIZE * sizeof(Node *));
}

uint32_t HashTable::hash_func(int key){
    return abs(key) % SIZE;   
}

bool HashTable::insert(int key, const std::string &value){
    uint32_t addr = hash_func(key);
    Node * node = nodes[addr];
    if(node == NULL){
        nodes[addr] = new Node(key, value);
    }else{
        return insert(&node->next, key, value);
    }
}

bool HashTable::insert(Node **next,int key, const std::string &value){
    Node *node = *next;
    if(node == 0){
        (*next) = new Node(key, value);
        return true;
    }else{
        return insert(&node->next, key, value);
    }
}

bool HashTable::find(int key){
    uint32_t addr = hash_func(key);
    Node *node = nodes[addr];
    if(node == NULL){
        return false;
    }else{
        do{
            if(node->key == key){
                return true;
            }else{
                node = node->next;
            }
        }while(node != NULL)
        return false
    }

}

Node* HashTable::find_node(int key){
    uint32_t addr = hash_func(key);
    Node *node = nodes[addr];
    if(node == NULL){
        return NULL;
    }else{
        do{
            if(node->key == key){
                return node;
            }else{
                node = node->next;
            }
        }while(node != NULL);
            return NULL;
    }
}

std::string&
HashTable::operator[](int key){
    Node *node = find_node(key);
    assert(node != NULL);
    return node->value;
}
