#include "cards.h"
#include<bits/stdc++.h>
using namespace std;
const vector< vector<int> > st2={{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},
                                 {1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
const vector< vector<int> > rt2={{1,2},{1,4},{2,5},{1,3},{1,5},
                                 {4,5},{2,3},{5,2},{2,4},{3,4}};
const vector<int> ans2={3,2,1,4,3,
                        1,4,3,5,5};
int val;
void init_magician(int N, int K) {
}

void init_assistant(int N, int K) {
}
int count(vector<int> v){
  int x=0;
  for(int i=v.size()-1,j=0;i>0;--i,++j){
    if(v[i]>v[i-1]) x+=(1<<j);
  }
  return x;
}
vector<int> choose_cards(vector<int> cards) {
  if(cards.size()==2){
    if(cards[0]==1&&cards[1]==2) return {2};
    else if(cards[0]==1&&cards[1]==3) return {1};
    else return {3};
  }
  else if(cards.size()==3){
    for(int i=0;i<10;++i){
      if(cards==st2[i]){
        return rt2[i];
      }
    }
  }
  else if(cards.size()==6){
    val=cards[5];
    cards.pop_back();
    do{
      if(count(cards)==val){
        return cards;
      }
    }while(next_permutation(cards.begin(),cards.end()));
  }
  return {};
}

int find_discarded_card(vector<int> cards) {
  if(cards.size()==1){
    if(cards[0]==1) return 3;
    else if(cards[0]==2) return 1;
    else return 2;
  }
  else if(cards.size()==2){
    for(int i=0;i<10;++i){
      if(cards==rt2[i]) return ans2[i];
    }
  }
  else if(cards.size()==5){
    return count(cards);
  }
  return 1;
}
