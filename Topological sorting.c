#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;
int graph[20][20];
int inDegree[20];
int visited[20];

void DFS(int v){
    if(visited[v]) return;
    visited[v]=1;

    printf("%d ", v);

    for(int i=1; i<=n; i++){
        if(graph[v][i]){
            inDegree[i]--;

            if(inDegree[i]==0) DFS(i);
        }
    }
}

int main(){
    scanf("%d", &n);

    memset(inDegree, 0, 20);
    memset(visited, 0, 20);
    memset(graph, 0, sizeof(graph));

    int e; scanf("%d", &e);

    for(int i=1; i<=e; i++){
        int u, v; scanf("%d%d", &u, &v);

        graph[u][v]=1;
        inDegree[v]++;
    }

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0) DFS(i);
    }

    return 0;
}
