//				6/5/2563 Last Edited: 22/6/2563 MAYBE ITRATIVE???
#include<bits/stdc++.h>
using namespace std;
short int t,m,n,key_length,a,b,ak,bk;
char str1[1005],str2[1005],key[2005];
bool is_true;
void f(short int idx_str1,short int idx_str2,short int idx_key){
	if(idx_key==key_length&&!is_true){
		printf("Yes\n");
		is_true=1;
		return ;
	}
	if(key[idx_key]==str1[idx_str1]&&idx_str1<m){
		f(idx_str1+1,idx_str2,idx_key+1);
	}
	if(is_true) return ;
	if(key[idx_key]==str2[idx_str2]&&idx_str2<n){
		f(idx_str1,idx_str2+1,idx_key+1);
	}
}
main(){
	scanf("%s\n%s",&str1,&str2);
	m=strlen(str1);
	n=strlen(str2);
	for(int i=0;i<m;i++){
		if(str1[i]=='A') a++;
		else b++;
	}
	for(int i=0;i<n;i++){
		if(str2[i]=='A') a++;
		else b++;
	}
	key_length=m+n;
	scanf("%hd",&t);
	while(t--){
		is_true=0;   ak=0;   bk=0;
		scanf("%s",&key);
		for(int i=0;i<key_length;i++){
			if(key[i]=='A') ak++;
			else bk++;
		}
		if(ak==a&&bk==b) f(0,0,0);
		if(!is_true) printf("No\n");
	}
}
