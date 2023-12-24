---
title: Single Linked List
date: 2023-12-23 17:43:00 +0700
categories: [Blogging, DSA]
tags: [typography]
pin: true
math: true
mermaid: true
---

# Single linked list :

- Each node link to the next node in the list
- Each node is a struct that contains two parts :
1. The data part : Save node's data
2. The linking part : Save the address of the next node in the list or NULL if it's the last node.

## Data structure of a node 

```cpp
typedef struct tagNode{
    int data;
    struct tagNode *pNext;
}Node;

```
## Data structure of a list

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

## Create a NULL list
```cpp
void createList(LIST &l){
    l.pHead = l.pTail = NULL;
}
```

## Create a node which contains data equal `x`

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

## Review List
```cpp
Node *p;
p = l.pHead;
while(p != NULL){
    // do stuff with p -> data
    p = p-> pNext;
}
```

- print list: 

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
## Search a node contains data equal `x`

```cpp
Node *search(LIST l, int x){
    Node *p ;
    p = l.pHead;
    while( (p!= NULL) && (p->data != x))
        p = p-> pNext;
    return p;
}
```

## Insert a node `x` into the list

- Insert into List's head node:
```cpp
void addHead(LIST &l, Node *p){
    if (l.pHead == NULL){
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
```
- Insert into List's tail node:
```cpp
void addTail(LIST &l, Node *p){
    if(l.pTail == NULL){
        l.pTail = p;
        l.pHead = l.pTail;
    }
    else{
        l.pTail -> pNext = p;
        l.pTail = p;
    }
}
```

- Insert after Node `q`:
```cpp
void insertAfterQ(LIST &l, Node *p, Node *q){
    if (q != NULL){
        p -> pNext = q->pNext;
        q -> pNext = p;
        if (l.pTail == q) l.pTail = p;
    }
    else{
        addHead(l, q);
    }
}
```
## Delete a node in the list

> return 1 if delete successfully, if not then return 0

- Delete List's head node :
```cpp
int deleteHead(LIST &l, int& data){
    Node *p;
    if (l.pHead != NULL){
        p = l.pHead;
        l.pHead = l.pHead -> pNext;
        data = p -> data;
        delete(p);
        if (l.pHead == NULL){
            l -> pTail = NULL;
        }
        return 1;
    }
    return 0;
}
```
- Delete the node after node `q`
```cpp
int removeAfterQ(LIST &l , Node *q, int &data){
    Node *p;
    if (q != NULL){
        p = q-> pNext;
        if (p!= NULL){
            if (p == l.pTail)
                l.pTail = q;
            q -> pNext = p -> pNext;
            data = p -> data;
            delete p;
        }
        return 1;
    }
    else 
        return 0;
}
```
- Delete a node with data equal `x`

```cpp
int deleteX(LIST &l, int x){
    Node *p, *q;
    p = search(l, x);
    q = l.pHead ;
    while (q != l.pTail){
        if ( q -> pNext == p){
            break;
        }
    }
    int temp;
    return removeAfterQ(l, q, temp);
}
```

## Sort a list

- Selection sort
```cpp
void selectionSort(LIST &l){
    Node *p, *q, *min;
    p = l.pHead;
    while (p != l.pTail)
    {
        min = p;
        q = p-> pNext;
        while(q!= NULL){
            if (q->data < p->data){
                min = q;
            }
            q = q-> pNext;
        }
        swap(min->data, p->data);
        p = p-> pNext;
    }
}
```

- Quick sort

```cpp
void quickSort(LIST &l){
    Node *x, *p;
    LIST l1, l2;
    if (l.pHead == l.pTail){
        return ;
    }
    createList(l1);
    createList(l2);
    x = l.pHead;
    l.pHead = x -> pNext;
    while (l.pHead != NULL){
        p = l.pHead;
        l.pHead = p-> pNext;
        p->pNext = NULL;
        if (p->data <= x->data){
            addHead(l1, p);
        }
        else{
            addHead(l2, p);
        }
    }
    quickSort(l1);
    quickSort(l2);
    if (l1.pHead != NULL){
        l.pHead = l1.pHead;
        l1.pTail -> pNext = x;
    }
    else{
        l.pHead = x;
        
    }
    x-> pNext = l2.pHead;
    if (l2.pHead != NULL){
        l.pTail = l2.pTail;
    }
    else 
        l.pTail = x;

}
```