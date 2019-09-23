#include<iostream>

using namespace std;

int N;
int M;
int adj[101][101];
int visited[101];
int color[101];

bool isBipartite(int v){
    for(int i=1;i<=N;i++){
        if(adj[v][i]==1){
            if(visited[i]==0){
                visited[i]=1;
                color[i] = 1-color[v];
                if(!isBipartite(int v)) return false;
            }
            else return (color[v]!=color[i]);
        }
    }
    return true;
}

void reset(){
    for(int i=0;i<101;i++) color[i]=-1;
    for(int i=0;i<101;i++) visited[i]=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            adj[i][j]=0;
        }
    }
}

int main(){
    int T;
    cin>>T;
    for(int test = 1; test <= T; test++){
        reset();
        cin>>N>>M;
        for(int i=1;i<=M;i++){
            int x,y;
            cin>>x>>y;
            adj[x][y]=1;        //graph is bipartite
            adj[y][x]=1;
        }
        visited[1] = 1;
        color[1] = 0;
        bool ans = isBipartite(1);
        cout<<"#"<<test;
        if(ans){
            for(int i=1;i<=N;i++){
                if(color[i]==0) cout<<" "<<i;
            }
            cout<<endl;
        }
        else{
            cout<<" "<<-1<<endl;
        }
    }
}