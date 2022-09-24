#include<stdio.h>
#include<string.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n+1], b[n+1];
    printf("Enter the elements of the array: ");
    int m=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]>m) m=a[i];
    }

    int Count[m+1];
    for(int i=1; i<=m; i++) Count[i]=0;
    for(int i=1; i<=n; i++){
        Count[a[i]]++;
    }
    for(int i=2; i<=m; i++) Count[i]+=Count[i-1];
    for(int i=n; i>=1; i--){
        b[Count[a[i]]]=a[i];
        Count[a[i]]--;
    }

    printf("The sorted elements: ");
    for(int i=1; i<=n; i++){
        printf("%d ", b[i]);
    }

    return 0;
}
