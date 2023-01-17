//                      15/11/2563
#include<bits/stdc++.h>
using namespace std;
int arr[100001][31];
void build(string str,int idx){
    int j=0,i=1;
    for(;i<str.length();++i){
        if(str[i]==str[j]){
            arr[idx][i]=j+1;
            ++j;
            continue;
        }
        if(j==0) continue;
        j=arr[idx][j-1];
        --i;
    }
}
bool kmp(string str,string cat,int idx){
    int i=0,j=0;
    for(;i<str.length();++i){
    	if(str[i]==cat[j]){
    		if(j==cat.length()-1) return 1;
			++j;
			continue;
		}
		if(j==0) continue;
		j=arr[idx][j-1];
		--i;
	}
	return 0;
}
int main(){
    int m,ms,n,ns;
    string cat[100001],str;
    scanf("%d %d",&m,&ms);
    for(int i=0;i<m;++i){
        cin>>cat[i];
    }
    for(int i=0;i<m;++i){
        build(cat[i],i);
        //for(int j=0;j<ms;++j) printf("%d ",arr[i][j]); printf("\n");
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&ns);
        cin>>str;
        vector<int> ans;
        for(int j=0;j<m;++j){
            if(kmp(str,cat[j],j)){
                ans.push_back(j+1);
            }
        }
        if(ans.empty()) printf("OK\n");
        else{
            for(int j=0;j<ans.size();++j) printf("%d ",ans[j]);
            printf("\n");
        }
    }
}
