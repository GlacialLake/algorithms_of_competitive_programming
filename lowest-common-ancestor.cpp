#include <vector>
#include <cmath>

struct lca {
	/* the index starts from 0 */
	/*
		USAGE:
		lca tree(n)
		tree.add(a, b)
		tree.preproc()
		tree.query(a, b)
	*/
	std::vector<std::vector<int> > tree, st;
	std::vector<int> depth, dfo, dfo_ly, fapr_pos;
	lca(int n)
	{
		tree.resize(n);
		depth.resize(n);
		fapr_pos.resize(n);
	}
	void add(int x, int y)
	{
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	void dfs(int cur, int fa = -1, int layer = 0)
	{
		depth[cur] = layer;
		dfo.push_back(cur);
		dfo_ly.push_back(layer);
		fapr_pos[cur] = dfo.size() - 1;
		for (auto& i : tree[cur])
			if (i != fa) {
				dfs(i, cur, layer + 1);
				dfo.push_back(cur);
				dfo_ly.push_back(layer);
			}
	}
	void preproc(int root)
	{
		dfs(root);
		int dfo_tot = dfo.size();
		st.resize(dfo_tot);
		int ysize = (int)log2(dfo_tot) + 1;
		for (int i = 0; i < dfo_tot; ++i) {
			st[i].resize(ysize);
			st[i][0] = i;
		}
		for (int j = 1; (1 << j) <= dfo_tot; ++j)
			for (int i = 0; i + (1 << j) - 1 < dfo_tot; ++i)
				if (dfo_ly[st[i][j - 1]] < dfo_ly[st[i + (1 << (j - 1))][j - 1]])
					st[i][j] = st[i][j - 1];
				else
					st[i][j] = st[i + (1 << (j - 1))][j - 1];
	}
	int query(int i, int j)
	{
		if ((i = fapr_pos[i]) > (j = fapr_pos[j])) {
			i = i ^ j;
			j = i ^ j;
			i = i ^ j;
		}
		int k = (int)log2(j - i + 1);
		if (dfo_ly[st[i][k]] < dfo_ly[st[j - (1 << k) + 1][k]])
			return dfo[st[i][k]];
		else
			return dfo[st[j - (1 << k) + 1][k]];
	}
};
