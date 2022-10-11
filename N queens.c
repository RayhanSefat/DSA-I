#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;
int graph[100][100];
int x=0;

void printIt(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j]==-1) printf("%d ", j);
        }
    }

    printf("\n");
    x++;
    //exit(0);
}

void subProb(int r, int c){
    if(graph[r][c]!=0 || c>n || r>n) return;
    //printf("In: %d %d\n", r, c);

    graph[r][c]=-1;

    if(r==n) printIt();

    int cnt=1;
    for(int i=r+1; i<=n; i++){
        graph[i][c]++;
        if(c-cnt>0) graph[i][c-cnt]++;
        if(c+cnt<=n) graph[i][c+cnt]++;
        cnt++;
    }

    for(int i=1; i<=n; i++){
        subProb(r+1, i);
    }

    graph[r][c]=0;

    cnt=1;
    for(int i=r+1; i<=n; i++){
        graph[i][c]--;
        if(c-cnt>0) graph[i][c-cnt]--;
        if(c+cnt<=n) graph[i][c+cnt]--;
        cnt++;
    }
    //printf("Out: %d %d\n", r, c);
}

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            graph[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++) subProb(1, i);
    printf("%d\n", x);

    return 0;
}
