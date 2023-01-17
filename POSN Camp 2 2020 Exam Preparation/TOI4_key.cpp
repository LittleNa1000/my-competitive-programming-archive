//				29/3/2563
#include<bits/stdc++.h>
using namespace std;
string par1,par2,key;
int parent,child;
void compare(int idxpar,int idxchild){
	char a=par1[idxpar], b=par2[idxpar], c=key[idxchild];
	if(c>a&&c>b) key[idxchild]=max(a,b);
	else if(c<a&&c<b) key[idxchild]=min(a,b);
}
main(){
	scanf("%d %d",&parent,&child);
	cin>>par1>>par2>>key;
	for(int i=0;i<parent;i++){
		for(int j=0;j<child;j++){
			compare(i,j);
		}
	}
	cout<<key;
}
