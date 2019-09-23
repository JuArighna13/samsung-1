#include<iostream>

using namespace std;
int det[5][5];
int mat[13][5];

void detonate(int r){
    for(int i=r;i>r-5 && i>=0;i--){
        for(int j=0;j<5;j++){
            det[r-i][j]=0;
            if(mat[i][j]==2){
                det[r-i][j]=2;
                mat[i][j]=0;
            }
        }
    }
}

void undetonate(int r){
    for(int i=r;i>r-5 && i>=0;i--){
        for(int j=0;j<5;j++){
            if(det[r-i][j]==2){
                det[r-i][j]=0;
                mat[i][j]=2;
            }
        }
    }
}

void solve(int n, int pos, int c, int &max){
    if(pos>4||pos<0||c<0) return;
    if(mat[n][pos]==2)
        c-=1;
    else if(mat[n][pos]==1)
        c+=1;
    if(n==0)
    {
        if(c>max)
            max=c;
        return;
    }
    else
    {
        solve(n-1,pos+1,c,max);
        solve(n-1,pos-1,c,max);
        solve(n-1,pos,c,max);
    }
}

int main(){
    int T;
    cin>>T;
    for(int t0=1; t0<=T; t0++){
        int N;
        int ans = -1;
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<5;j++){
                cin>>mat[i][j];
            }
        }
        for(int j=0;j<5;j++) mat[N][j]=0;
        mat[N][2]=3;
        for(int j=N-1;j>=4;j--){
            int c = -1;
            detonate(j);
            solve(N,2,0,c);
            if(c>ans) ans = c;
            undetonate(j);
        }
        cout<<"#"<<t0<<" "<<ans<<endl;
    }
}