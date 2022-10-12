#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *left, *right;
    struct Node *parent;
};

struct Node *root = NULL;

void createNode(int data){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    if(root==NULL){
        root = temp;
        return;
    }

    struct Node *current=root, *previous=NULL;


    while(current != NULL){
        previous = current;

        if(data < current->data) current = current->left;
        else current = current->right;
    }

    temp->parent = previous;

    if(data<previous->data) previous->left = temp;
    else previous->right = temp;
}

void createTree(int a[], int size){
    for(int i=0; i<size; i++) createNode(a[i]);
}

struct Node* searchNode(int key, struct Node *node){
    if(node == NULL) return NULL;
    if(node->data == key) return node;

    if(key < node->data) return searchNode(key, node->left);
    else return searchNode(key, node->right);
}

void searchElement(int key){
    struct Node *node = searchNode(key, root);
    if(node != NULL){
        printf("%d is found!", key);
        if(node != root) printf(" It is a child of %d.", node->parent->data);
        printf("\n");
    }
    else printf("%d is not found!\n", key);
}

struct Node* findTreeMinimum(struct Node *node){
    struct Node *temp = node;

    while(temp->left != NULL) temp = temp->left;

    return temp;
}

struct Node* findSuccessor(int val){
    struct Node* x=searchNode(val, root);
    if (x->right!=NULL){
        return findTreeMinimum(x->right);
    }

    struct Node* y=x->parent;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->parent;
    }

    return y;
}

void deletion(struct Node * z){
    struct Node* y;
    struct Node* x;

    if (z->left==NULL||z->right==NULL){
        y=z;
    }else y=findSuccessor(z->data);

    if(y->left!=NULL){
        x=y->left;
    }else x=y->right;

    if(x!=NULL){
        x->parent=y->parent;
    }

    if(y->parent==NULL)
    {
        root=x;
    }else if(y==y->parent->left){
        y->parent->left=x;
    }else y->parent->right=x;

    if(y!=z){
        z->data=y->data;
    }
};

void pritTree(struct Node *node){
    if(node == NULL) return;

    pritTree(node->left);
    printf("%d ", node->data);
    pritTree(node->right);
}

int main(){
    int a[] = {12, 5, 7, 11, 13, 9, 4, 21, 19, 17};
    createTree(a, 10);

    pritTree(root);
    printf("\n");

    deletion(searchNode(21, root));
    pritTree(root);

    return 0;
}
