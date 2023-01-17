//      19/2/2564 or dfs? sort??
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct N{
    int d,i;
    bool h;
};
vector<int> verti;
vector<ii> hori;
queue<N> q;
bool visited[100005][2]; //or bitset?
int L,m,n,x1,x2,y,ub,dist[100005][2],d,idx,H;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d %d",&L,&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x1,&x2);
        hori.push_back({x1,x2});
        dist[i][1]=INT_MAX;
        if(!x1){
            q.push({1,i,1});
            dist[i][1]=1;
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d",&y);
        dist[i][0]=INT_MAX;
        verti.push_back(y);
    }
    sort(verti.begin(),verti.end());
    verti.push_back(L);
    while(!q.empty()){
        d=q.front().d;
        idx=q.front().i;
        H=q.front().h;
        q.pop();
        if(visited[idx][H]) continue;
        visited[idx][H]=1;
        if(H){
            if(hori[idx].second==L){
                printf("%d",d); return 0;
            }
            ub=upper_bound(verti.begin(),verti.end(),hori[idx].second)-verti.begin();
            for(int i=0;i<ub;++i){
                if(!visited[i][0]&&dist[i][0]>d+1){
                    dist[i][0]=d+1;
                    q.push({d+1,i,0});
                }
            }
        }
        else{
            if(idx==m){
                printf("%d",d);
                return 0;
            }
            for(int i=0;i<n;++i){
                if(hori[i].first<=verti[idx]&&hori[i].second>=verti[idx]&&!visited[i][1]&&dist[i][1]>d+1){
                    if(hori[i].second==L){
                        printf("%d",d+1); return 0;
                    }
                    dist[i][1]=d+1;
                    q.push({d+1,i,1});
                }
            }
        }
    }
}
/*
12 3 3
0 9
8 10
6 12
5 
7
9
*/