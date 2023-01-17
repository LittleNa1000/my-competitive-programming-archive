#include<bits/stdc++.h>
using namespace std;
set<int> s;
bool less_than_1;
void operate(int a,int b){
	s.erase(*s.rbegin());
	s.erase(*s.rbegin());
	s.insert(((a|b)+(a&b)+(a^b))/3);
	if(s.size()==1) less_than_1=1;
}
main(){
	int n,temp;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&temp);
			s.insert(temp);
		}
	while(!less_than_1){
		operate(*s.rbegin(),*--s.rbegin());
	}
	printf("%d",*s.begin());
}
