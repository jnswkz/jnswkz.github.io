---
title: Single Linked List
date: 2023-12-23 17:43:00 +0700
categories: [Blogging, dsa]
tags: [typography]
pin: true
math: true
mermaid: true
---

# Single Linked List

- Each node link to the next node in the list
- Each node is a struct that contains two parts :
1. The data part : Save node's data
2. The linking part : Save the address of the next node in the list or NULL if it's the last node.

# Data structure of a node 

```cpp
typedef struct tagNode{
    int data;
    struct tagNode *pNext;
}Node;

```
# Data structure of a list

```cpp
typedef struct tagList{
    Node *pHead;
    Node *pTail;

}LIST;
```
# Basic stuff to do with single linked list
1. Create a NULL list
2. Create a node which contains data equal `x`
3. Review list
4. Search a node contain data equal `x`
5. Insert a node `x` into the list
6. Delete a node in the list
7. Sort a single linked list

> with `x` is a integer in all examples below

# Create a NULL list
```cpp
void createList(LIST &l){
    l.pHead = l.pTail = NULL;
}
```

# Create a node which contains data equal `x`

```cpp
Node* createNode(int x){
    Node* p;
    p = new Node;
    if ( p == NULL) exit(1);
    p-> data = x;
    p->pNext = NULL;
    return p;
}
```

# Review List
```cpp
Node *p;
p = l.pHead;
while(p != NULL){
    // do stuff with p -> data
    p = p-> pNext;
}
```

## print list
```cpp 
void printList(LIST l){
    Node *p;
    p = l.pHead;
    while(p != NULL){
        cout << p->data;
        p = p-> pNext;
    }
}
```
# Search a node contains data equal `x`

```cpp
Node *search(LIST l, int x){
    Node *p ;
    p = l.pHead;
    while( (p!= NULL) && (p->data != x))
        p = p-> pNext;
    return p;
}
```

# Insert a node `x` into the list
