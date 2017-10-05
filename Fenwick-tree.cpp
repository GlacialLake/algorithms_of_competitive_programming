namespace ft {
	/* the index starts from 1 */
	/*
		USAGE:
		maxn n
		add(x, inc) / init(a[])
		sum(x)[1, x]
	*/
	const int maxn = 1000;
	long long tree[maxn + 1];
	int n;
	void add(int x, long long inc)
	{
		while (x <= n) {
			tree[x] += inc;
			x += ((x)&(-x));
		}
	}
	void init(long long a[])
	{
		for (int i = 1; i <= n; ++i)
			add(i, a[i]);
	}
	long long sum(int x)
	{
		long long ret = 0;
		while (x >= 1) {
			ret += tree[x];
			x -= ((x)&(-x));
		}
		return ret;
	}
};
