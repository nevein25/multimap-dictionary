#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void createTree(TreeType *t)
{
    *t=NULL;
}


int isEmptyTree(TreeType *t)
{
    return (!t);
}

int isFullTree(TreeType *t)
{
    return 0;
}



int insert (TreeType *t,EntryType *item)
{
    Node *q = *t, *r=NULL;
    int found=0;

        while(q){
            r=q;
            if(item->key < q->entry.key){
            q=q->left;
            }
            else if(item->key == q->entry.key){
                found=1;
                break;
            }
            else {
             q=q->right;
            }
        }

    if(found ==0){
    Node *p =(Node *)malloc(sizeof(Node));

    p->entry=*item;
    p->left=NULL;
    p->right=NULL;

    if (!(*t))  //if empty
    {
        *t= p;
    }
    else  //if not empty
    {
        Node *cur,*pre;
        cur=*t;

        while(cur)
        {
            pre=cur;
            if(item->key < cur->entry.key)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }

        if(item->key < pre->entry.key)
        {
            pre->left=p;
        }
        else
        {
            pre->right=p;
        }
    }
    }
    return found;
}


int search(TreeType *t,EntryType *item)
{

    Node *cur;
    cur=*t;
    int found=0;

    while(cur)
    {
        if(item->key < cur->entry.key)
        {
            cur=cur->left;
        }
        else if(item->key > cur->entry.key)
        {
            cur=cur->right;
        }
        else if(item->key == cur->entry.key)
        {
            found=1;
            break;
        }

    }
    if (found==1)
    {
        *item=cur->entry;
    }
    return found;
}


void modifyValue(TreeType *t,EntryType *item,EntryType *newValue)
{
    Node *p;
    p=*t;
    int found=0;

    while(p)
    {
        if(item->key < p->entry.key)
        {
            p=p->left;
        }
        else if(item->key > p->entry.key)
        {
            p=p->right;
        }
        else if(item->key == p->entry.key )
        {
            found=1;
            p->entry.sizeValue=newValue->sizeValue;
            for(int i=0; i < newValue->sizeValue; i++)
            {

                p->entry.value[i]=newValue->value[i];
            }

            break;
        }
    }
    if (found==0)
    {
        printf("The key does not exist\n");
    }

}

int deleteKey(TreeType *t,EntryType *item){
    Node *p = *t, *r =NULL;
    int found=0;
    while(p && !(found=(p->entry.key == item->key))){
        r=p;
        if(item->key < p->entry.key){
            p=p->left;
        }
        else {
             p=p->right;
        }
    }
    if (found){
        *item = p->entry;
        if(!r){ //if it is the root
            deleteNode(t);
        }else if(item->key< r->entry.key){
            deleteNode(&r->left);
        }else{
            deleteNode(&r->right);
        }
    }
    return found;
}
void deleteNode(TreeType *t){
    Node *p = *t, *r;
    if(!((*t)->left)){ //if it dosent have a left node   //also can be done at the leaf node
        *t = (*t)->right; //but the right one on the deleted node
    }else if(!((*t)->right)){
        *t = (*t)->left;
    }else{//it has 2 nodes
        p=(*t)->left;
        if(!p->right){ //if left dosent have right pransh
            (*t)->entry=p->entry;
            (*t)->left=p->left;
        }else{
            do{
                r=p;
                p=p->right;
            }while(p->right);
            (*t)->entry=p->entry;
            r->right=p->left;
        }
    }
    free(p);
}

