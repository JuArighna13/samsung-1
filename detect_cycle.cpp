#include<iostream>

using namespace std;

int N;
int M;
int cycle;
int answerN;
int adj[101][101];
int visited[101];       //0 = not visited; 2 = visited previously; 1 = visited in current stack
int arr[101];
int answer[101];


void dfs_visit(int v){
    int i;
    visited[v]=1;
    for(i=1;i<=N;i++){
        if(cycle==0){
            if(adj[v][i]==1){
                if(visited[i]==0){
                    dfs_visit(i);
                }
                else if(visited[i]==1){
                    cycle = i;
                    break;
                }
            }
        }
    }
    answer[answerN++] = v;
    visited[v] = 2;
}

void dfs(){
    int i;
    answerN = 0;
    cycle = 0;
    for(int i=1;i<=N;i++){
        if(cycle>0) return;
        if(visited[i]==0){
            dfs_visit(i);
        }
    }
}

void reset(){
    for(int i=0;i<101;i++) arr[i]=0;
    for(int i=0;i<101;i++) visited[i]=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            adj[i][j]=0;
        }
    }
    for(int i=0;i<101;i++) answer[i]=0;
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
            adj[x][y]=1;
        }
        dfs();
        if(cycle==0){
            cout<<"#"<<test<<" "<<0<<endl;
        }
        else{
            for(int i=0;i<answerN;i++){
                arr[answer[i]] = 1;
                if(answer[i]==cycle){
                    answerN = i+1;
                }
            }
            cout<<"#"<<test;
            for(int i=1;i<=N;i++){
                if(arr[i]==1){
                    cout<<" "<<i;
                }
            }
            cout<<endl;
        }
    }
}