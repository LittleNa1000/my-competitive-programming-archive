#include<bits/stdc++.h>
using namespace std;
stack<char> st;
string in; 
int count,i,i2,mx,y,x;
int main(){
	cin>>in;
	for(i=0;i<in.length();i++){
		if(in[i]=='('){
			st.push(in[i]);
			if(mx<st.size()) mx=st.size();
		}
		else if(in[i]==')'&&!st.empty()){
			if(st.top()=='('){
				st.pop();
			}
			else{
				//printf("NO\n");
				y++;
				//break;
			} 
		}
		else{
		  //printf("WHAT\n");
		  y++;
		  //break;
		}
		
	}
		while(!st.empty()){
	  		st.pop();  
	  		x++;
	  	}
		// if(x==0&&y==0){
		// 	printf("YES %d\n",mx);
		// }
		// else if(y>0||x>0){
		// 	printf("NO %d\n",x+y);
		// }	
	    printf("%d",x+y);
	
}