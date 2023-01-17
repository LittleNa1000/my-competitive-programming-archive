//				10/4/2563
#include<bits/stdc++.h>
using namespace std;
int n,idx,temp,j,k;
char action;
string word,str=" ";
vector<int> cursor(1,0);
/*void print_vec(vector<int> v){
    for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    printf("\n");
}*/
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>action;
		if(action=='i'){
			cin>>word;
			str.insert(cursor[idx]+1,word+' ');
			temp=cursor[idx]+word.size()+1;
			idx++;
			cursor.insert(cursor.begin()+idx,temp);
			for(int m=idx+1;m<cursor.size();m++){
				cursor[m]+=word.size()+1;
			}
		}
		else if(action=='l'){
			if(idx) idx--;
		}
		else if(action=='r'){
			if(idx<cursor.size()-1) idx++;
		}
		else if(action=='b'){
			if(cursor.size()>1&&idx>0){
				j=cursor[idx-1];
				k=cursor[idx]-j;
				str.erase(j,k);
				cursor.erase(cursor.begin()+idx);
				idx--;
				for(int m=idx+1;m<cursor.size();m++){
					cursor[m]-=k;
				}
			}
		}
		else if(action=='d'){
			if(cursor.size()>1&&idx<cursor.size()-1){
				j=cursor[idx];
				k=cursor[idx+1]-j;
				str.erase(j,k);
				cursor.erase(cursor.begin()+idx+1);
				for(int m=idx+1;m<cursor.size();m++){
					cursor[m]-=k;
				}
			}
		}
		//cout<<str<<'\n';
		//print_vec(cursor);
		//printf("%d\n",cursor[idx]);
	}
	str.erase(str.begin());
	cout<<str<<'\n';
	//print_vec(cursor);
	//printf("%d\n",cursor[idx]);
}
