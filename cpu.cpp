#include<iostream>

using namespace std;

int D;
int E;
int F;
int D_price;
int E_price;
int N;
int model[8][4];
int visited[8];
int ans;

void getMax(int curr_D, int curr_E, int curr_F, int p, int cost){
    int max_cost = curr_D*D_price + curr_E*E_price + cost;
    ans = (ans>max_cost?ans:max_cost);
    if(p==4 || curr_D ==0 || curr_E ==0) return;
    for(int i=0;i<N;i++){
        if(visited[i]==0){
            visited[i]=1;
            int j=0;
            while(1){
                if((j*model[i][0]<=curr_D)&&(j*model[i][1]<=curr_E)&&(j*model[i][2]<=curr_F)){
                    getMax(curr_D - j*model[i][0] ,curr_E - j*model[i][1],curr_F - j*model[i][2], p+1 , cost + j*model[i][3]);
                }
                else{
                    break;
                }
            j++;
            }
            visited[i]=0;
        }
    }
}

int main(){
    int T;
    cin>>T;
    for(int test = 1; test <= T; test++){
        ans = 0;
        cin>>D>>E>>F>>D_price>>E_price;
        cin>>N;
        for(int i=0;i<N;i++){
            visited[i]=0;
            cin>>model[i][0]>>model[i][1]>>model[i][2]>>model[i][3];
        }
        getMax(D,E,F,0,0);
        cout<<"#"<<test<<" "<<ans<<endl;
    }
}