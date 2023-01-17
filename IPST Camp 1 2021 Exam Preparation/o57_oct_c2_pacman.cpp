//                  11/1/2564
 #include<bits/stdc++.h>
 using namespace std;
 typedef pair<int,int> ii;
 typedef pair<ii,ii> N;
//  struct N{
//      int d,i,j,q;
//  };
//  bool operator<(const N &a,const N &b){
//      return a.d<b.d;
//  }
 //bool visited[1005][1005][3];
 int dp[1005][1005][3],a[1005][1005];
 int n,m,d,i,j,quota,ans;
 //priority_queue<N,vector<N>,greater<N> > pq;
 //priority_queue<N> pq;
 queue<N> pq;
 int main(){
     scanf("%d%d",&n,&m);
     for(int i=0;i<n;++i){
         for(int j=0;j<m;++j){
             scanf("%d",&a[i][j]);
             dp[i][j][2]=-1;
             dp[i][j][1]=-1;
             dp[i][j][0]=-1;
         }
     }
     dp[0][0][2]=0;
     pq.push({{0,0},{0,2}}); //or {{},{}}
     while(!pq.empty()){
         d=pq.front().first.first;
         i=pq.front().first.second;
         j=pq.front().second.first;
         quota=pq.front().second.second;
         pq.pop();
         //if(visited[i][j][quota]) continue;
         //visited[i][j][quota]=1;
         //printf("%d (%d,%d) %d\n",d,i,j,quota);
         if(i==n-1&&j==m-1){
            if(quota){
                //dp[i][j][quota-1]+=a[i][j];
            }
            //printf("%d",d);
            continue;
         }
         if(i+1<n&&quota&&dp[i+1][j][quota-1]<d+a[i][j]/*&&!visited[i+1][j][quota-1]*/){
             dp[i+1][j][quota-1]=d+a[i][j];
             pq.push({{d+a[i][j],i+1},{j,quota-1}});
         }
         if(j+1<m&&quota&&dp[i][j+1][quota-1]<d+a[i][j]){
             dp[i][j+1][quota-1]=d+a[i][j];
             pq.push({{d+a[i][j],i},{j+1,quota-1}});
         }
         if(i+1<n&&dp[i+1][j][2]<d/*&&!visited[i+1][j][2]*/){
             dp[i+1][j][2]=d;
             pq.push({{d,i+1},{j,2}});
         }
         if(j+1<m&&dp[i][j+1][2]<d){
             dp[i][j+1][2]=d;
             pq.push({{d,i},{j+1,2}});
         }
     }
     ans=max(dp[n-1][m-1][2]+a[n-1][m-1],max(dp[n-1][m-1][1]+a[n-1][m-1],dp[n-1][m-1][0]));
     printf("%d",ans);
 }