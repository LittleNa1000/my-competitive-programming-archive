#include<bits/stdc++.h>
using namespace std;
int n,tc,w,x,wp;
string str;
int main(){
	cin>>tc;
	scanf("\n");
	while(tc--){
		w=1;
		wp=0;
		x=0;
		getline(cin,str);
    	cin>>n;
    	//cout<<tc<<str<<n<<endl;
    	//printf("\n\n");
    	//Count Words
    	for(int i=0;i<str.length();++i){
    		if(str[i]==' ') ++w;
		}
		printf("%d\n",w-n+1);
		for(int i=0;i<str.length();++i){
			if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
			cout<<str[i];
			if(str[i]==' '){
				++wp;
				if(wp==1) x=i;
				if(wp==n){
					printf("\n");
					i=x;
					wp=0;
				}
			}
		}
		if(tc>1) printf("\n");
		str.clear();
    	if(tc) scanf("\n");
	}
}
