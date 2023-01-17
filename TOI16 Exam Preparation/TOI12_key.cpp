//                  22/11/2563
#include<bits/stdc++.h>
using namespace std;
bool vst[1001][1001],ss;
string a,b,c;
int al,bl,i,j;
int main(){
    int n;
    cin>>a>>b;
    al=a.length();
    bl=b.length();
    scanf("%d",&n);
    while(n--){
        queue<pair<int,int> > q;
        for(int i=0;i<=al;++i){
            for(int j=0;j<=bl;++j) vst[i][j]=0;
        }
        cin>>c;
        ss=0;
        q.push({0,0});
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            if(vst[i][j]) continue ;
            vst[i][j]=1;
            //printf("(%d,%d)\n",i,j);
            if(i==al&&j==bl){
                ss=1;
                break;
            }
            if(i<al&&a[i]==c[i+j]&&!vst[i+1][j]) q.push({i+1,j});
            if(j<bl&&b[j]==c[i+j]&&!vst[i][j+1]) q.push({i,j+1});
        }
        if(ss) printf("Yes\n");
        else printf("No\n");
    }
}