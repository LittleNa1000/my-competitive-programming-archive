//              16/5/2564
#include"pandelib.h"
#include<bits/stdc++.h>
using namespace std;
int n,k,l,lgn,ans,qn,lgqn;
assignment_t a[100000],blank[100000];
bool results[100000],found;
void skiptime(int day){
  for(int i=0;i<day;++i) pandemic_assign(blank,results);
}
void display(){
  for(int i=0;i<k;++i){
    printf("%d: ",i);
    for(int j=0;j<a[i].size();++j) printf("%d ",a[i][j]); printf("\n");
  }
}
int main(){
  pandemic_init(n,k,l);
  lgn=ceil(log2(n));
  if((k==20&&l==20)){
    for(int i=0;i<n;++i){
      for(int j=0;j<lgn;++j){
        if(i&(1<<j)){
          a[j].push_back(i);
        }
      }
    }
    // display();
    pandemic_assign(a,results);
    skiptime(30);
    for(int i=0;i<k;++i){
      if(results[i]){
        ans+=1<<i;
      }
    }
    pandemic_answer(ans);
  }
  else if((k==15&&l==15)){
    qn=ceil((float)n/4);
    lgqn=ceil(log2(qn));
    for(int x=0;x<4;++x){
      for(int y=1;y<=qn;++y){
        for(int z=0;z<lgqn;++z){
          if(y&(1<<z)){
            if(y+(x*qn)<n) a[z].push_back(y+(x*qn));
          }
        }
      }
      //display();
      pandemic_assign(a,results);
      for(int i=0;i<k;++i) a[i].clear();
    }
    skiptime(26);
    for(int x=0;x<4;++x){
      found=0;
      skiptime(1);
      for(int y=0;y<k;++y){
        if(results[y]){
          found=1;
          ans+=1<<y;
        }
      }
      if(found) pandemic_answer(ans+(x*qn));
    }
    pandemic_answer(ans);
  }
  else{
    pandemic_answer(0);
  }
}
