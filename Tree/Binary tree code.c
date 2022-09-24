#include<stdio.h>

struct node{
    int value;
    struct node *left, *right;
};

struct node *root;

void display(struct node *top){
    if(top!=NULL){
        printf("%d ", top->value);
        display(top->right);
        display(top->left);
    }
}

void insert(int data, struct node **pointingNode){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->value=data;
    temp->left=NULL;
    temp->right=NULL;

    if(*pointingNode==NULL){
        *pointingNode=temp;
    }else{
        if(data<=((temp)->value)){
            insert(data, &(*pointingNode)->left);
        }else{
            insert(data, &(*pointingNode)->right);
        }
    }
}

int main(){
    insert(21, &root);
    insert(12, &root);
    insert(7, &root);
    insert(32, &root);
    insert(17, &root);
    insert(13, &root);
    insert(9, &root);
    insert(22, &root);

    display(root);

    return 0;
}
