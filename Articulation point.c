#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 100
int n, e;
int time=0;
int graph[N][N];
char color[N];
int parent[N], discoveryTime[N], finishTime[N], low[N];
bool isArticulationPoint[N];

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

void DFS(int v){
    color[v]='g';
    time++;
    discoveryTime[v]=time;
    low[v]=discoveryTime[v];
    int numberOfChildren=0;

    for(int i=1; i<=n; i++){
        if(graph[v][i]==1 && color[i]=='w'){
            numberOfChildren++;
            parent[i]=v;
            DFS(i);
            low[v]=min(low[v], low[i]);
            if(parent[v]!=-1 && discoveryTime[v]<=low[i]) isArticulationPoint[v]=true;
            if(parent[v]==-1 && numberOfChildren>1) isArticulationPoint[v]=true;
        }
        else if(graph[v][i]==1 && i!=parent[v]){
            low[v]=min(low[v], discoveryTime[i]);
        }
    }

    color[v]='b';
    time++;
    finishTime[v]=time;
}

void initialize(){
    for(int i=1; i<=n; i++){
        color[i]='w';
        parent[i]=-1;
        discoveryTime[i]=0;
        finishTime[i]=0;
        low[i]=INT_MAX;
        isArticulationPoint[i]=false;

        for(int j=1; j<=n; j++){
            graph[i][j]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    initialize();

    scanf("%d ", &e);
    for(int i=1; i<=e; i++){
        int u, v; scanf("%d%d", &u, &v);
        graph[u][v]=graph[v][u]=1;
    }

    for(int i=1; i<=n; i++){
        if(color[i]=='w') DFS(i);
    }

    for(int i=1; i<=n; i++){
        if(isArticulationPoint[i]==true) printf("%d is an articulation point.\n", i);
    }

    return 0;
}
