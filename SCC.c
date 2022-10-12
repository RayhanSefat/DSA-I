#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;
int graph[20][20];
int visited[20];
int stack[20], ptr=-1;

void push(int x){
    ptr++;
    stack[ptr] = x;
}

int top(){
    return stack[ptr];
}

void pop(){
    ptr--;
}

bool isEmpty(){
    return (ptr<0);
}

void DFS(int v){
    if(visited[v]) return;
    visited[v]=1;

    for(int i=1; i<=n; i++){
        if(graph[v][i]){
            DFS(i);
        }
    }

    push(v);
}

void DFSinverse(int v){
    if(visited[v]) return;
    visited[v]=1;

    printf("%d ", v);

    for(int i=1; i<=n; i++){
        if(graph[i][v]){
            DFSinverse(i);
        }
    }
}

int main(){
    scanf("%d", &n);

    memset(visited, 0, 20);
    memset(graph, 0, sizeof(graph));

    int e; scanf("%d", &e);

    for(int i=1; i<=e; i++){
        int u, v; scanf("%d%d", &u, &v);

        graph[u][v]=1;
    }

    for(int i=1; i<=n; i++){
        DFS(i);
    }

    for(int i=1; i<=n; i++) visited[i]=0;

    printf("Strongly connected components:\n");
    int cnt=0;

    while(!isEmpty()){
        int v=top();
        pop();

        if(visited[v]==0){
            DFSinverse(v);
            printf("\n");
            cnt++;
        }
    }

    printf("Number of strongly connected components: %d\n", cnt);

    return 0;
}
