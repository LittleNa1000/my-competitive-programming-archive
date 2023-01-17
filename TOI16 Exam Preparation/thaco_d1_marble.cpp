//                  7/11/2563 or pq
#include<bits/stdc++.h>
using namespace std;
int n,m,cR,cG;
string str[500001];
vector<pair<bool,bool> > path;// or bitset
bool isR;
int main(){
    scanf("%d %d",&n,&m);
    int qsumR[n+1][m+1],qsumG[n+1][m+1];// or global var
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            qsumR[i][j]=0;
            qsumG[i][j]=0;
        }
    }
    for(int i=0;i<n;++i){
        cin>>str[i];
    }
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            qsumR[i][j]=qsumR[i+1][j]+qsumR[i][j+1]-qsumR[i+1][j+1];
            qsumG[i][j]=qsumG[i+1][j]+qsumG[i][j+1]-qsumG[i+1][j+1];
            if(str[i][j]=='R') qsumR[i][j]++;
            else qsumG[i][j]++;
        }
    }
    //for(int i=0;i<n;++i){
    //    for(int j=0;j<m;++j) printf("(%d,%d) ",qsumR[i][j],qsumG[i][j]); printf("\n");}
    int i=0,j=0;
    for(int mo=1;mo<=n+m-1;++mo){
        if(i==n-1&&j==m-1){
            cR=min(cR,cG);
            cG=cR;
            printf("%d\n",cG*2);
            for(int x=0;x<path.size();++x){
                if((path[x].second&&cR>0)||(!path[x].second&&cG>0)){
                    printf("Y ");
                    if(path[x].second) --cR;
                    else --cG;
                }
                else printf("N ");
                if(path[x].first) printf("R\n");
                else printf("D\n");
            }
            if((str[n-1][m-1]=='R'&&cR>0)||(str[n-1][m-1]=='G'&&cG>0)){
                    printf("Y ");
                }
            else printf("N ");
        }
        //printf("{%d,%d}\n",i,j);
        isR=0;
        if(str[i][j]=='R'){
            isR=1;
            cR++;
        }
        else cG++;
        if(cR>cG){
            if((qsumG[i+1][j]>qsumG[i][j+1]&&i<n-1)||j==m-1){
                ++i;
                path.push_back({0,isR});
            }
            else{
                ++j;
                path.push_back({1,isR});
            }
        }
        else{
            if((qsumR[i+1][j]>qsumR[i][j+1]&&i<n-1)||j==m-1){
                ++i;
                path.push_back({0,isR});
            }
            else{
                ++j;
                path.push_back({1,isR});
            }
        }
    }
}