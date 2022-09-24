#include<stdio.h>
#include<string.h>

int Partition(int A[], int p, int r){
    int x=A[r]; //x is pivot
    int i=p-1;

    for(int j=p; j<r; j++){
        if(A[j]<=x){
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }

    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;

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
    freopen("Input.txt", "r", stdin);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    a[i]=20000;

    printf("Enter p & r: ");
    scanf("%d%d", &p, &r);

    QS(a, p, r);

    printf("The sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
