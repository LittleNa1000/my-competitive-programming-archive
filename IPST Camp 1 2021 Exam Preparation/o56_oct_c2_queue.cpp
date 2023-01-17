//                  11/1/2564 or pq
 #include<bits/stdc++.h>
 using namespace std;
 typedef pair<int,int> ii;
 ii p;
 int pr[200012];
 set<ii> s;
 set<ii>::iterator it;
 int cnt,n,c,tem;
 bool operator<(const ii &a,const ii &b){
     return a.first<b.first;
 }
 int main(){
     scanf("%d",&n);
     for(int i=0;i<n;++i){
         scanf("%d",&c);
         if(c==1){
             scanf("%d",&tem);
             s.insert({tem,cnt});
             pr[cnt]=tem;
             ++cnt;
         }
         else if(c==2){
             p=*s.begin();
             printf("%d\n",p.second+1);
             s.erase(s.begin());
         }
         else{ 
             scanf("%d",&tem);
             it=s.find({pr[tem-1],tem-1});
             printf("%d\n",distance(s.begin(),it));
         }
     }
 }