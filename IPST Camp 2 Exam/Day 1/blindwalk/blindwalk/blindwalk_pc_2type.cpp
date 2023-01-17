#include "blindwalk.h"
#include<stdio.h>
#include<vector>
static const long long T1 = 2596418101;
static const long long T2 = 840634349;
static const long long T3 = 590846489;
using namespace std;
long long D,D2;
vector<int> hop[525];
int deg[525];
int h,con,NN;
int find_hop(long long D){
    int x=0;
    if(D%T1==0) return D/T1;
    if(D%T2==0) return D/T2;
    if(D%T3==0) return D/T3;
    for(int i=0;i<NN;++i){
        for(int j=0;j<NN;++j){
            D2=D-(i*T1);
            D2-=(j*T2);
            if(D2%T3==0){
                return (D2/T3)+i+j;
            }
        }
    }
    return 0;
}
long long is_connect(int i,int j){
    D=ask(i,j);
    h=find_hop(D);
    if(h==1){
        if(D==T1){
            return 1;
        }
        else if(D==T2){
            return 2;
        }
        else if(D==T3){
            return 3;
        }
    }
    return 0;
}
vector<vector<int>> build_graph(int N){
    NN=N;
    vector<vector<int>> out;
    int i=0;
    for(int j=i+1;j<N;++j){
        D=ask(i,j);
        h=find_hop(D);
        if(h==1){
            if(D==T1){
                out.push_back({i,j,1});
                ++deg[i];
            }
            else if(D==T2){
                out.push_back({i,j,2});
            }
            else if(D==T3){
                out.push_back({i,j,3});
            }
            ++deg[i];
            ++deg[j];
        }
        hop[h].push_back(j);
    }
    //Can reduce ask amount
    for(int i=1;i<N-1;++i){
        if(hop[i].empty()&&hop[i+1].empty()) continue;
        if(hop[i].size()==2&&hop[i+1].size()==2){
            con=is_connect(hop[i][0],hop[i+1][0]);
            if(con){
                out.push_back({hop[i][0],hop[i+1][0],con});
                ++deg[hop[i][0]];
                ++deg[hop[i+1][0]];
                con=is_connect(hop[i][1],hop[i+1][1]);
                out.push_back({hop[i][1],hop[i+1][1],con});
                ++deg[hop[i][1]];
                ++deg[hop[i+1][1]];
            }
            else{
                con=is_connect(hop[i][0],hop[i+1][1]);
                out.push_back({hop[i][0],hop[i+1][1],con});
                ++deg[hop[i][0]];
                ++deg[hop[i+1][1]];
                con=is_connect(hop[i][1],hop[i+1][0]);
                out.push_back({hop[i][1],hop[i+1][0],con});
                ++deg[hop[i][1]];
                ++deg[hop[i+1][0]];
            }
        }
        else if(hop[i].size()==2&&hop[i+1].size()==1){
            con=is_connect(hop[i][0],hop[i+1][0]);
            if(con){
                out.push_back({hop[i][0],hop[i+1][0],con});
                ++deg[hop[i][0]];
                ++deg[hop[i+1][0]];
            }
            else{
                con=is_connect(hop[i][1],hop[i+1][0]);
                out.push_back({hop[i][1],hop[i+1][0],con});
                ++deg[hop[i][1]];
                ++deg[hop[i+1][0]];
            }
        }
        else if(hop[i].size()==1&&hop[i+1].size()==1){
            con=is_connect(hop[i][0],hop[i+1][0]);
            out.push_back({hop[i][0],hop[i+1][0],con});
            ++deg[hop[i][0]];
            ++deg[hop[i+1][0]];
        }
    }
    int dx1,dx2;
    for(int i=0;i<N;++i){
        if(deg[i]==1){
            dx1=i;
            break;
        }
    }
    deg[dx1]++;
    for(int i=0;i<N;++i){
        if(deg[i]==1){
            dx2=i;
            break;
        }
    }
    //printf("%d %d\n",dx1,dx2);
    con=is_connect(dx1,dx2);
    if(con){
        out.push_back({dx1,dx2,con});
    }
    return out;
}
/*
4 4
0 1 2
0 3 1
2 3 1
1 3 3

6 5
3 4 1
4 5 1
5 0 1
0 1 1
1 2 1

6 5
3 4 1
4 5 2
5 0 3
0 1 1
1 2 2

6 6
3 4 1
4 5 1
5 0 1
0 1 1
1 2 1
2 3 1
*/