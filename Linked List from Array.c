#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL, *current=NULL;
int numberOfElements=0;

struct Node* createNode(int data){
    struct Node *temp=NULL;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    //printf("%p\n", temp);

    return temp;
}

void addNodeBack(int key){
    struct Node *temp=NULL;
    temp = createNode(key);

    if(head == NULL){
        head = temp;
        current = temp;
    }else{
        current->next = temp;
        current = current->next;
    }

    numberOfElements++;

    return;
}

void addNodeFront(int key){
    struct Node *temp=NULL;
    temp = createNode(key);

    if(head == NULL){
        head = temp;
        current = temp;
    }else{
        temp->next = head;
        head = temp;
    }

    numberOfElements++;

    return;
}

void insertNodePositionwise(int key, int pos){
    if(pos>numberOfElements){
        printf("Invalid index given!\n");
        return;
    }

    if(pos==numberOfElements){
        addNodeBack(key);
        return;
    }

    struct Node *temp=NULL;
    temp = head;

    while(pos--){
        temp = temp->next;
    }

    struct Node *temp1 = createNode(temp->data);
    temp1->next = temp->next;

    temp->next = temp1;
    temp->data = key;

    numberOfElements++;
}

struct Node* createLinkList(int a[], int size){
    for(int i=0; i<size; i++){
        addNodeBack(a[i]);
    }

    return head;
}

int search(int key){
    struct Node *temp;
    temp = head;

    int i=1;
    while(temp!=NULL){
        if(temp->data==key){
            return i;
        }

        temp = temp->next;
        i++;
    }

    return -1;
}

void insertAfterElement(int key, int element){
    int pos = search(element);

    if(pos==-1){
        printf("Element not found!");
        return;
    }

    insertNodePositionwise(key, pos);
}

void deleteByPosition(int pos){
    if(pos>numberOfElements){
        printf("Invalid index given!\n");
        return;
    }

    if(pos==1){
        head = head->next;
        return;
    }

    struct Node *temp=NULL;
    temp = head;

    while(pos>2){
        pos--;
        temp = temp->next;
    }

    temp->next = temp->next->next;
    numberOfElements--;
}

void deleteElement(int element, bool flag){
    int pos = search(element);

    if(pos==-1){
        if(flag) printf("Element was not found!\n");
        return;
    }

    deleteByPosition(pos);

    deleteElement(element, false);
}

void reverse(){
    struct Node *previous = NULL;
    while(head->next != NULL){
        struct Node *nextNode = head->next;
        head->next = previous;
        previous = head;
        head = nextNode;
    }

    head->next = previous;
}

void printList(){
    struct Node *temp;
    temp = head;

    printf("%d elements:\n", numberOfElements);
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    struct Node *head;
    head = createLinkList(a, n);

    printList();

    printf("Searching:\n");
    int key;
    do{
        scanf("%d", &key);
        if(!key) break;

        int index = search(key);
        if(index==-1){
            printf("Element not found!\n");
        }else{
            printf("Element found at %dth position.\n", index);
        }
    }while(1);


    printf("Adding back:\n");
    do{
        scanf("%d", &key);
        if(!key) break;

        addNodeBack(key);
        printList();
    }while(1);


    printf("Adding front:\n");
    do{
        scanf("%d", &key);
        if(!key) break;

        addNodeFront(key);
        printList();
    }while(1);


    printf("Inserting to a position:\n");
    do{
        int pos;
        scanf("%d", &key);
        if(!key) break;

        scanf("%d", &pos);

        insertNodePositionwise(key, pos);
        printList();
    }while(1);

    printf("Inserting after an element:\n");
    do{
        int element;
        scanf("%d", &key);
        if(!key) break;

        scanf("%d", &element);

        insertAfterElement(key, element);
        printList();
    }while(1);


    printf("Delete by position:\n");
    do{
        int pos;
        scanf("%d", &pos);

        if(!pos) break;

        deleteByPosition(pos);
        printList();
    }while(1);


    printf("Delete an element:\n");
    do{
        int element;
        scanf("%d", &element);

        if(!element) break;

        deleteElement(element, true);
        printList();
    }while(1);

    reverse();
    printList();

    return 0;
}
