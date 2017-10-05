namespace uf {
	/* the index starts from 1 */
	/*
		USAGE:
		maxn
		init(n)
		find(x) join(x, y)
	*/
	const int maxn = 1000;
	int fa[maxn + 1];
	void init(int n) 
	{ 
		for (int i = 1; i <= n; ++i)
			fa[i] = i; 
	}
	int find(int x)
	{
		int r = x;
		while (fa[r] != r)
			r = fa[r];
		int i = x, j;
		while (fa[i] != r) { 
			j = fa[i]; 
			fa[i] = r; 
			i = j; 
		}
		return r;
	}
	void join(int x, int y) 
	{ 
		fa[find(x)] = find(y); 
	}
};
