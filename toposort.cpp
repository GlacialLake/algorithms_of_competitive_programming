#include<vector>
#include<cstring>

namespace tp {
	/* the index starts from 1 */
	/*
		USAGE:
		maxn n G[1..n]
		toposort()
		res[1..n]
	*/
	const int maxn = 1000;
	std::vector<int> G[maxn + 1];
	int n;
	int vis[maxn + 1];
	int res[maxn + 1], top;
	bool dfs(int u)
	{
		vis[u] = -1;
		for (auto i : G[u])
			if (vis[i] == -1 || (vis[i] == 0 && (!dfs(i))))
			return 0;
		vis[u] = 1;
		res[--top] = u;
		return 1;
	}
	bool toposort()
	{
		top = n + 1;
		memset(vis, 0, sizeof vis);
		for (int u = 1; u <= n; ++u)
			if ((!vis[u]) && (!dfs(u)))
				return 0;
		return 1;
	}
};
