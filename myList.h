#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <stddef.h>

typedef struct Node{
    void * data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List{
    Node * head;
    Node * tail;
    Node * current;
    int count;
    int StateOfCurrent; //-1 is before the head, 0 is in the between the head and end, 1 is after the end
    struct List * next;
} List;



extern Node* nodePool;

extern List* listPool;


void initializeNodes(int nodeNum);

void initializeLists(int listNum);

List * ListCreate();

int ListCount(List* ls);

void * ListFirst(List* ls);

void * ListLast(List* ls);

void * ListNext(List* ls);

void * ListPrev(List * ls);

void * ListCurr(List* ls);

int ListAdd(List* ls, void* item);

int ListInsert(List* ls, void* item);

int ListAppend(List* ls, void* item);

int ListPrepend(List* ls, void* item);

void * ListRemove(List* ls);

void  ListConcat(List* ls1, List * ls2);

void itemFree(Node * node);

void ListFree(List* ls,  void (* itemFree)(Node *));

void *ListTrim(List* ls);

int isGreater(int * a, int * b);    // server as comparator, if a>b return 1; else return 0

void *ListSearch(List* ls, int (* Comparator)(void *, void *), void * comparisonArg);



#endif // LIST_H_INCLUDED
