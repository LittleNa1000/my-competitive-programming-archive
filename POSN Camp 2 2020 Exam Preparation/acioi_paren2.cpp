#include<bits/stdc++.h>
using namespace std;
main(){
	stack<char> st;
	string in[100]; 
	int count,i,i2,max=0,y=0,x=0;
	scanf("%d",&count);
	for(i=0;i<count;i++){
	    cin>>in[i];
	}
	for(i2=0;i2<count;i2++){
	    max=0;
		y=0;
		x=0;
	for(i=0;i<in[i2].length();i++){
		if(in[i2][i]=='('||in[i2][i]=='{'||in[i2][i]=='['||in[i2][i]=='<'){
			st.push(in[i2][i]);
			if(max<st.size()) max=st.size();
		}
		else if(in[i2][i]==')'&&!st.empty()){
			if(st.top()=='('){
				st.pop();
			}
			else{
				//printf("NO\n");
				y++;
				//break;
			} 
		}
		else if(in[i2][i]=='}'&&!st.empty()){
			if(st.top()=='{'){
				st.pop();
			}
			else{
				//printf("NO\n");
				y++;
				//break;
			} 
		}
		else if(in[i2][i]==']'&&!st.empty()){
			if(st.top()=='['){
				st.pop();
			}
			else{
				//printf("NO\n");
				y++;
				//break;
			} 
		}
		else if(in[i2][i]=='>'&&!st.empty()){
			if(st.top()=='<'){
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
		while(!st.empty()) {
	  		st.pop();  
	  		x++;
	  	}
		if(x==0&&y==0){
			printf("YES %d\n",max);
		}
		else if(y>0||x>0){
			printf("NO %d\n",x+y);
		}	
	  
	}
}
