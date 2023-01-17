//				14/8/2563
//              Kruskal
#include <bits/stdc++.h>
using namespace std;
int par[200005], rnk[100005];
struct t
{
	int u, v, w, i;
};
bool operator<(const t &a, const t &b)
{
	return a.w > b.w;
}
int find_par(int x)
{
	if (par[x] == x)
		return x;
	return par[x] = find_par(par[x]);
}
priority_queue<t> pq;
int V, E, u, v, w, idx;
vector<int> mst;
long long int ans;
main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0; i < V; ++i)
		par[i] = i;
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		pq.push({u, v, w, i});
	}
	while (mst.size() < V - 1)
	{
		u = pq.top().u;
		v = pq.top().v;
		w = pq.top().w;
		idx = pq.top().i;
		pq.pop();
		u = find_par(u);
		v = find_par(v);
		if (u != v)
		{
			ans += w;
			mst.push_back(idx);
			if (rnk[u] > rnk[v])
			{
				par[v] = u;
			}
			else
				par[u] = v;
			if (rnk[u] == rnk[v])
				++rnk[v];
		}
	}
	sort(mst.begin(), mst.end());
	printf("%lld\n", ans);
	for (int i = 0; i < mst.size(); ++i)
	{
		printf("%d\n", mst[i]);
	}
}
