#include "myList.h"
#include <stdlib.h>


Node* nodePool=NULL;

List* listPool=NULL;

void initializeNodes(int nodeNum)
{
    int i;

    for(i=0; i<nodeNum; i++)
    {
        struct Node* node=(struct Node *)malloc(sizeof(struct Node));

        node->next=nodePool;

        nodePool=node;
    }
}

void initializeLists(int listNum)
{
    int i;

    for(i=0; i< listNum; i++)
    {
        struct List* ls=(struct List *)malloc(sizeof(struct List));

        ls->next=listPool;

        listPool=ls;
    }
}

List * ListCreate()
{
   if(listPool!=NULL)
   {
        List* newList=listPool;

        listPool=listPool->next;

        // initialize the list

        newList->head=NULL;
        newList->tail=NULL;
        newList->current=NULL;
        newList->count=0;
        newList->StateOfCurrent=0;
        newList->next=NULL;

        return newList;
   }
   else
   {
        return NULL;
   }

}

int ListCount(List* ls)
{
    return ls->count;
}

void * ListFirst(List* ls)
{
    ls->current=ls->head;

    return ls->head->data;
}

void * ListLast(List* ls)
{
    ls->current=ls->tail;

    return ls->tail->data;
}

void * ListNext(List* ls)
{
    if(ls->current==ls->tail)
    {
        ls->current=NULL;
        ls->StateOfCurrent=1;

        return NULL;
    }
    else
    {
        ls->current=ls->current->next;

        return ls->current->data;
    }
}

void * ListPrev(List * ls)
{
    if(ls->current==ls->head)
    {
        ls->current=NULL;
        ls->StateOfCurrent=-1;

        return NULL;
    }
    else
    {
        ls->current=ls->current->prev;


        return ls->current->data;
    }
}


void * ListCurr(List* ls)
{
    if(ls->current!=NULL)
        return ls->current->data;
    else
        return NULL;
}

int ListAdd(List* ls, void* item)
{
    Node* node;

    if(nodePool==NULL)
    {
        return -1;
    }
    else
    {
        // extract the first node from nodePool and use it to hold the item

        node=nodePool;

        nodePool=nodePool->next;

        node->data=item;

        node->next=NULL;

        node->prev=NULL;

        if(ls->StateOfCurrent==-1)
        {
            // before the start, add at the head

            node->next=ls->head;

            if(ls->head!=NULL)
                ls->head->prev=node;
            else
                ls->tail=node;


            ls->head=node;
            ls->StateOfCurrent=0;


        }
        else if(ls->StateOfCurrent==0)
        {
            if(ls->count==0)
            {
                ls->head=node;
                ls->tail=node;

                node->prev=NULL;
                node->next=NULL;
            }
            else
            {
                node->next=ls->current->next;

                if(ls->current->next!=NULL)
                    ls->current->next->prev=node;
                else
                    ls->tail=node;

                node->prev=ls->current;
                ls->current->next=node;

            }
        }
        else if(ls->StateOfCurrent==1)
        {
            // after the end

            node->prev=ls->tail;

            if(ls->tail!=NULL)
                ls->tail->next=node;
            else
                ls->head=node;

            ls->tail=node;
            ls->StateOfCurrent=0;
        }

        ls->current=node;
        ls->count++;

        return 0;

    }
}


int ListInsert(List* ls, void* item)
{
    Node* node;

    if(nodePool==NULL)
    {
        return -1;
    }
    else
    {
        // extract the first node from nodePool and use it to hold the item

        node=nodePool;

        nodePool=nodePool->next;

        node->data=item;

        node->next=NULL;

        node->prev=NULL;

        if(ls->StateOfCurrent==-1)
        {
            // before the start, add at the head

            node->next=ls->head;

            if(ls->head!=NULL)
                ls->head->prev=node;
            else
                ls->tail=node;

            ls->head=node;
            ls->StateOfCurrent=0;


        }
        else if(ls->StateOfCurrent==0)
        {
            if(ls->count==0)
            {
                ls->head=node;
                ls->tail=node;

                node->prev=NULL;
                node->next=NULL;
            }
            else
            {
                node->prev=ls->current->prev;

                if(ls->current->prev!=NULL)
                    ls->current->prev->next=node;
                else
                    ls->head=node;

                node->next=ls->current;
                ls->current->prev=node;
            }
        }
        else if(ls->StateOfCurrent==1)
        {
            // after the end

            node->prev=ls->tail;

            if(ls->tail!=NULL)
                ls->tail->next=node;
            else
                ls->head=node;

            ls->tail=node;
            ls->StateOfCurrent=0;
        }

        ls->current=node;
        ls->count++;

        return 0;

    }
}


int ListAppend(List* ls, void* item)
{
    Node* node;

    if(nodePool==NULL)
    {
        return -1;
    }
    else
    {
        // extract the first node from nodePool and use it to hold the item

        node=nodePool;

        nodePool=nodePool->next;

        node->data=item;

        node->next=NULL;

        node->prev=NULL;


        // append the node at the end

        if(ls->count==0)
        {
            ls->head=node;
            ls->tail=node;

            node->prev=NULL;
            node->next=NULL;
        }
        else
        {

            ls->tail->next=node;
            node->prev=ls->tail;

            ls->tail=node;
        }


        ls->current=node;
        ls->count++;

        return 0;

    }
}

int ListPrepend(List* ls, void* item)
{
    Node* node;

    if(nodePool==NULL)
    {
        return -1;
    }
    else
    {
        // extract the first node from nodePool and use it to hold the item

        node=nodePool;

        nodePool=nodePool->next;

        node->data=item;

        node->next=NULL;

        node->prev=NULL;


        // append the node at the head

        if(ls->count==0)
        {
            ls->head=node;
            ls->tail=node;

            node->prev=NULL;
            node->next=NULL;
        }
        else
        {
            node->next=ls->head;
            ls->head->prev=node;

            ls->head=node;

        }

        ls->current=node;
        ls->count++;

        return 0;

    }
}

void * ListRemove(List* ls)
{
    Node* node=ls->current;

    if(ls->current!=NULL)
    {
        if(ls->current->prev!=NULL)
        {
            // current is not the head

            ls->current->prev->next=ls->current->next;
        }
        else
        {
            ls->head=ls->current->next;
        }

        if(ls->current->next!=NULL)
        {
            // current is not the tail

            ls->current->next->prev=ls->current->prev;

            ls->current=ls->current->next;
        }
        else
        {
            ls->tail=ls->current->prev;

            ls->current=NULL;

            ls->StateOfCurrent=1;
        }

        // free the data and add the node to the head of node pool

        void *item=node->data;

        node->data=NULL;
        node->prev=NULL;
        node->next=nodePool;
        nodePool=node;

        ls->count--;

        return item;

    }
    else
    {
        return NULL;
    }

}

void  ListConcat(List* ls1, List * ls2)
{
    if(ls1->tail!=NULL)
    {
        // ls1 is not empty

        ls1->tail->next=ls2->head;
    }
    else
    {
        ls1->head=ls2->head;
        ls1->tail=ls2->tail;
    }

    if(ls2->head!=NULL)
    {
        // ls2 is not empty

        ls2->head->prev=ls1->tail;
        ls1->tail=ls2->tail;
    }

    ls1->count=ls1->count+ls2->count;

    // reset ls2 to initia state and add it to the head of listPool

    ls2->head=NULL;
    ls2->tail=NULL;
    ls2->current=NULL;
    ls2->StateOfCurrent=0;
    ls2->count=0;
    ls2->next=listPool;
    listPool=ls2;

}

void itemFree(Node * node)
{
    if(node!=NULL)
    {
        node->data=NULL;
        node->prev=NULL;
        node->next=nodePool;
        nodePool=node;

    }
}

void ListFree(List* ls,  void (* itemFree)(Node *))
{
    Node * node;

    while(ls->head!=NULL)
    {
        node=ls->head;

        ls->head=ls->head->next;

        (*itemFree)(node);

        ls->count--;
    }

    ls->head=NULL;
    ls->tail=NULL;
    ls->current=NULL;
    ls->StateOfCurrent=0;
    ls->next=listPool;
    listPool=ls;
}

void *ListTrim(List* ls)
{
    void * item;

    Node * node;

    if(ls->count==0)
        return NULL;
    else if(ls->count==1)
    {
        node=ls->tail;
        item=node->data;

        ls->head=NULL;
        ls->tail=NULL;
        ls->count--;
        ls->current=NULL;

        node->data=NULL;
        node->prev=NULL;
        node->next=nodePool;
        nodePool=node;

        return item;
    }
    else
    {
        node=ls->tail;
        item=node->data;

        node->prev->next=NULL;
        ls->tail=node->prev;
        ls->count--;
        ls->current=ls->tail;

        node->data=NULL;
        node->prev=NULL;
        node->next=nodePool;
        nodePool=node;

        return item;
    }
}


int isGreater(int * a, int * b)
{
    if(*(int *)a > *(int *)b )
        return 1;
    else
        return 0;
}

void *ListSearch(List* ls, int (* Comparator)(void *, void *), void * comparisonArg)
{
    if(ls->tail==NULL || ls->current==NULL)
        return NULL;

    Node * node=ls->head;

    while(node!=NULL)
    {
        int isMatch=(* Comparator)(node->data, comparisonArg);

        if(isMatch==1)
        {
            ls->current=node->prev;
            return node->data;
        }

        node=node->next;
    }

    ls->current=ls->tail->prev;
    return NULL;
}

