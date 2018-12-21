#include <bits/stdc++.h>
using namespace std;
#define N 233
#define inf 0x3fffffff

int n;
int mat[N][N],dp[N][N],path[N][N];
int vis[N];

map <int,string> dict;

void floyd(){
        for(int k=0; k<n; k++) {
                for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                                if(dp[i][j]>dp[i][k]+dp[k][j]) {
                                        dp[i][j]=dp[i][k]+dp[k][j];
                                        path[i][j]=k;
                                }
                        }
                }
        }
}

void print_path(int i,int j){
        if(i==j) return;
        if(path[i][j]==0) cout<<dict[j]<<",";
        else{
                print_path(i, path[i][j]);
                print_path(path[i][j], j);
        }
}

void dfs(int cur){
        vis[cur]=1;
        cout<<dict[cur]<<" ";
        for(int i=0; i<n; i++) {
                if(mat[cur][i]!=-1&&!vis[i]) {
                        dfs(i);
                        vis[i]=0;
                }
        }
}

void init(){
        memset(path,0,sizeof(path));
        memset(mat,0,sizeof(mat));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));

        scanf("nodeNum:%d",&n);
        string node;
        cin>>node;

        for(int i=0; i<n; i++) {
                cin>>node;
                dict[i]=node;
        }

        for(int i=0; i<n; i++) {
                for(int j=0; j<=n; j++) {
                        if(!j) cin>>node;
                        else cin>>mat[i][j-1];
                        if(i==j-1) mat[i][j-1]=0;
                        if(mat[i][j-1]==-1) dp[i][j-1]=inf;
                        else dp[i][j-1]=mat[i][j-1];
                }
        }
}

int main() {
        freopen("./ex3_Graph1.txt","r",stdin);

        cout<<"Graph1:"<<endl;
        init();
        floyd();
        for(int i=1; i<n; i++) {
                cout<<"\ts0->"<<dict[i]<<" path: s0,";
                print_path(0,i);
                cout<<"\b"<<"\t"<<"value="<<dp[0][i]<<endl;
        }
        dfs(0);
        cout<<"\n"<<endl;


        freopen("./ex3_Graph2.txt","r",stdin);

        cout<<"Graph2:"<<endl;
        init();
        floyd();
        cout<<"\ta->"<<dict[7]<<" path: a,";
        print_path(0,7);
        cout<<"\b"<<"\t"<<"value="<<dp[0][7]<<endl;
        dfs(0);
        cout<<endl;
        return 0;
}
