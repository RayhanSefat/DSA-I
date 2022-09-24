#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int p, int r){
    int pidx = p + rand()%(r-p+1);
    int x=A[pidx]; //x is pivot
    int i=p-1;

    for(int j=p; j<r; j++){
        if(A[j]<=x){
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i+1], &A[pidx]);

    return i+1;
}


void QS(int A[], int p, int r){

    if(p<r){
        int q=Partition(A, p, r);
        QS(A, p, q-1);
        QS(A, q+1, r);
    }

    return;
}

int main(){
    int n, p, r, a[100];
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    a[i]=20000;

    printf("\nEnter p & r: ");
    scanf("%d%d", &p, &r);

    QS(a, p, r);

    printf("\nThe sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
