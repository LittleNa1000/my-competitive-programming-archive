#include "guess.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> ic;
char res;
int find_answer(int N, int K) {
  vector<ic> base(N);
  for(int i=0;i<N;++i){
    base[i].first=i;
  }
  if(K==1){
    while(N>3){
      for(int i=0;i<base.size();++i){
        base[i].second='X';
      }
      for(int i=0;;){
        base[i].second='R';
        i+=6;
        if(i>=base.size()) break;
        base[i].second='R';
        i+=2;
        if(i>=base.size()) break;
        base[i].second='R';
        i+=1;
        if(i>=base.size()) break;
      }
      for(int i=0;i<base.size();++i){
        if(base[i].second=='R') continue;
        if(base[i-1].second=='R'||(i+1!=base.size()&&base[i+1].second=='R')) base[i].second='C';
        else base[i].second='X';
      }

      for(int i=0;i<base.size();++i){
        printf("before base %d %c\n",base[i].first,base[i].second);
      }
      vector<ic> send,nxt;
      for(int i=0;i<base.size();++i){
        if(base[i].second=='R') send.push_back({base[i].first,base[i].second});
      }
      // for(int i=0;i<send.size();++i){
      //   printf("send %d %c\n",send[i].first,send[i].second);
      // }
      //res='R';
       res=ask(send);
       printf("res%c\n",res);
      for(int i=0;i<base.size();++i){
        if(base[i].second==res){ 
          nxt.push_back({base[i].first,base[i].second});
        }
      }
      
      base=nxt;
      for(int i=0;i<base.size();++i){
        printf("after base %d %c\n",base[i].first,base[i].second);
      }
      N=base.size();
      //break; 
    }
    vector<ic> send2;
    for(int i=0;i<base.size();++i){
        if(i==0) base[i].second='R';
        if(i==1) base[i].second='C';
        else base[i].second='X';
    }
    send2.push_back({base[0].first,'R'});
    res=ask(send2);
    printf("res2%c\n",res);
    //res='X';
    if(res=='R') return base[0].first;
    if(res=='C') return base[1].first;
    else return base[2].first;
    //return 1;
  }
  else{
    return 1;
  }
}
// int main(){
//    cout<<find_answer(729,1);
// }