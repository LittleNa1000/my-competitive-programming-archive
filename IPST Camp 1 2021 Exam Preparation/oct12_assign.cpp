//      11/2/2564 don't have to remove () or remove?
#include<bits/stdc++.h>
using namespace std;
string str1,str2;
vector<string> ans;
bool no;
void f(int l1,int r1,int l2,int r2){
    if(str1[l1]=='('&&str1[r1]==')'){
        if(str2[l2]!='('||str2[r2]!=')'){
            no=1;
            return ;
        }
        ++l1;
        --r1;
        ++l2;
        --r2;
        //could do better (packbot)
    }
    //printf("%d %d %d %d\n",l1,r1,l2,r2);
    if(l1==r1&&(str1[l1]>='A'&&str1[l1]<='Z')){
        ans.push_back(str2.substr(l2,r2-l2+1));
        //cout<<str2.substr(l2,r2-l2+1)<<'\n';
        return ;
    }
    vector<int> c1,c2;
    for(int i=l1,lvl=0;i<=r1;++i){
        if(str1[i]=='(') ++lvl;
        else if(str1[i]==')') --lvl;
        else if(str1[i]==','&&!lvl) c1.push_back(i);
    }
    for(int i=l2,lvl=0;i<=r2;++i){
        if(str2[i]=='(') ++lvl;
        else if(str2[i]==')') --lvl;
        else if(str2[i]==','&&!lvl) c2.push_back(i);
    }
    //printf("%d %d %d %d %d %d\n",l1,r1,l2,r2,c1.size(),c2.size());
    if(c1.size()!=c2.size()){
        no=1;
        return ;
    }
    if(c1.empty()){
        if(str1.substr(l1,r1-l1+1)!=str2.substr(l2,r2-l2+1)){
            no=1;
        }
        return ;
    }
    for(int i=0;i<c1.size();++i){
        if(i==0) f(l1,c1[i]-1,l2,c2[i]-1);
        else f(c1[i-1]+1,c1[i]-1,c2[i-1]+1,c2[i]-1);
    }
    f(c1[c1.size()-1]+1,r1,c2[c2.size()-1]+1,r2);
}
int main(){
    cin>>str1>>str2;
    f(0,str1.length()-1,0,str2.length()-1);
    if(no) printf("no");
    else for(int i=0;i<ans.size();++i) cout<<ans[i]<<'\n';
}