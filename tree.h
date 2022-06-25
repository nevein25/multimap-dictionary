#include "global.h"


typedef struct node{
    struct node *left;
    struct node *right;
    EntryType entry;
}Node;

typedef Node *TreeType;


//Pre: None.
//Post: The tree is initialized to be empty.

void createTree(TreeType *t);

//Pre: The tree is initialized.
//Post: If the tree is empty (1) is returned. Else (0) is returned.

int isEmptyTree(TreeType *t);

//Pre: The tree is initialized.
//Post: If the tree is full (1) is returned. Else (0) is returned.

int isFullTree(TreeType *t);


//Pre: The tree is created & initialized
/*Post: the subtree rooted at the left child is comprised of elements less than the value at the current item,
 and the subtree rooted at the right child is comprised of elements greater than the value at the current item.*/
int insert (TreeType *t,EntryType *item);

//pre-condition: tree not empty
//post:return 1 if the key is found return 0 if not
int search(TreeType *t,EntryType *item);

//pre-condition: tree not empty
//post-condition: values of specific key is modified
void modifyValue(TreeType *t,EntryType *item,EntryType *newValue);

//pre: tree is created and initialized
//post:return 1 if deleted return 0 if not
int deleteKey(TreeType *t,EntryType *item);

