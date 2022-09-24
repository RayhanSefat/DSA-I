#include<stdio.h>
#include<string.h>

void Merge(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int L[n1+2], R[n2+2];

    for(int i=1; i<=n1; i++){
        L[i] = A[p+i-1];
    }

    for(int j=1; j<=n2; j++){
        R[j] = A[q+j];
    }

    L[n1+1]=11111;
    R[n2+1]=11111;

    int i=1;
    int j=1;

    for(int k=p; k<=r; k++){
        if(L[i] < R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }

    return;
}

void MS(int A[], int p, int r){
    int q=(p+r)/2;

    if(p<r){
        MS(A, p, q);
        MS(A, q+1, r);
        Merge(A, p, q, r);
    }

    return;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int p, r;
    printf("Enter p & r: ");
    scanf("%d%d", &p, &r);

    MS(a, p, r);

    printf("The sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
