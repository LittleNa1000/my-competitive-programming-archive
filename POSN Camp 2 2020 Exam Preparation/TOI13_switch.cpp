//				15/5/2563
#include<bits/stdc++.h>
using namespace std;
int n;
queue<bool> q,q2;
char temp;
main(){
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		scanf("%c",&temp);
		q.push(temp-'0');
	}
	q2=q;
	for(int i=1;i<=n;i++){
		q.push(q.front());
		q.pop();
		if(q==q2){
			printf("%d",i);
			break;
		}
	}
}
