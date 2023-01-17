// CLOSET PAIR OF POINTS BY LNW TUM
#include<bits/stdc++.h>
using namespace std;
int N,x,y;
typedef pair<int,int> ii;
vector<ii> point;
ii temp[50005];
bool operator<(const ii& a,const ii& b){
    return a.first<b.first;
}
bool sby(const ii &a,const ii &b){
	return a.second<b.second;
}
int dis(ii a,ii b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int closest(int lb,int ub){
	//Base case
    if(lb>=ub){
        return INT_MAX;
    }
    if(lb == ub-1){
        if(point[lb].second>point[ub].second){
            swap(point[lb],point[ub]);
        }
        //cout<<dis(point[lb],point[ub])<<endl;
        return dis(point[lb],point[ub]);
    }
    int mid = (lb+ub)/2;
    int cl = closest(lb,mid);
    int cr = closest(mid+1,ub);
    int minn = cl>cr?cr:cl;
    int xmid = point[mid].first;
    //Sorting points in [lb,ub] (Y-axis)
    /*int tl=lb,tm=mid+1,co=lb;
    while(tl<=mid&&tm<=ub){
        if(point[tl].second<point[tm].second){
            temp[co++] = point[tl++];
        }
        else{
            temp[co++] = point[tm++];
        }
    }
    while(tl<=mid)temp[co++] = point[tl++];
    while(tm<=ub)temp[co++] = point[tm++];
    for(int i=lb;i<=ub;i++){
        point[i] = temp[i];
    }*/
    sort(point.begin()+lb,point.begin()+ub+1,sby);
    for(int i=lb;i<=ub;i++){
        if(abs(xmid-point[i].first)<minn){
            for(int j=i+1;j<=ub&&point[j].second-point[i].second<minn;j++){
                //cout<<i<<" "<<j<<" "<<dis(point[i],point[j])<<endl;
                minn = min(minn,dis(point[i],point[j]));
            }
        }
    }
    return minn;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        point.push_back({x,y});
    }
    sort(point.begin(),point.end()); //Sort (X-axis)
    cout<<closest(0,N-1);
}
