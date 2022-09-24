#include<stdio.h>
#include<string.h>

int BS(int a[], int first, int last, int x)
{
    if(last>=first){
        int mid= first + (last-first)/2;

        if(a[mid]==x)
            return mid;

        else if(a[mid]<x)
            return BS(a, mid+1, last, x);

        else
            return BS(a, first, mid-1, x);
    }

    return -1;
}

int main()
{
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    int inx = BS(a, 0, n-1, x);

    if(inx != -1) printf("The index od the number: %d\n", inx);
    else printf("Number does not exist in the array!\n");

    return 0;
}
