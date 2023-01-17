//	peak
#include<bits/stdc++.h>
using namespace std;
int h[6000000];
main(){
	set<int> s;
	set<int>::iterator itr;
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
		if(i==1){// first h[i]
			if(h[0]>h[1]){
				s.insert(h[0]);
				//printf("A");
			}
		}
		else if(i+1==n){// last h[i]
			if(h[i]>h[i-1]){
				s.insert(h[i]);
				//printf("B");
			}
		}
		else{
			if(h[i-1]>h[i-2]&&h[i-1]>h[i]){
				s.insert(h[i-1]);
				//printf("C");
			}
		}
	}
	/*while(s.size()>k) {
		s.erase(s.begin());
	}*/
	//s.erase(s.begin(),s.end()-
	if(s.size()==0) printf("-1");
	else{
		if(s.size()==k){
			for(itr=--s.end();itr!=s.begin();itr--) 
    		{ 
        		printf("%d\n",*itr);
    		} 
    		printf("%d\n",*itr);
		}
		else if(s.size()<k){
			for(itr=s.begin()+k;itr!=s.end();itr++) 
    		{ 
        		printf("%d\n",*itr);
    		} 
		}
		else printf("F**K %d",s.size());
	}
}
