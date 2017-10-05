#include<algorithm>
namespace st {
	/* the index starts from 1 */
	/*
		USAGE:
		maxn a[] n
		build()
		add(pos, inc) qmi(L, R)[L, R]{val} seek(pos)
	*/
	const int maxn = 100000;
	long long tree[maxn << 2], a[maxn + 1];
	int n;
	void update(int l = 1, int r = n, int x = 1)
	{
		tree[x] = std::min(tree[x << 1], tree[x << 1 | 1]);
	}
	void build(int l = 1, int r = n, int x = 1)
	{
		if (l == r)tree[x] = a[l];
		else {
			int m = (l + r) >> 1;
			build(l, m, x << 1);
			build(m + 1, r, x << 1 | 1);
			update(l, r, x);
		}
	}
	void add(int pos, int inc, int l = 1, int r = n, int x = 1)
	{
		if (l == r)tree[x] += inc;
		else {
			int m = (l + r) >> 1;
			if (pos <= m)add(pos, inc, l, m, x << 1);
			else add(pos, inc, m + 1, r, x << 1 | 1);
			update(l, r, x);
		}
	}
	long long qmi(int L, int R, int l = 1, int r = n, int x = 1)
	{
		if (l >= L && r <= R)return tree[x];
		else {
			int m = (l + r) >> 1;
			bool lok = 0, rok = 0;
			long long la, ra;
			if (L <= m)lok = 1, la = qmi(L, R, l, m, x << 1);
			if (R > m)rok = 1, ra = qmi(L, R, m + 1, r, x << 1 | 1);
			if (lok && rok)return std::min(la, ra);
			else if (lok)return la;
			else return ra;
		}
	}
	long long seek(int pos, int l = 1, int r = n, int x = 1)
	{
		if (l == r)return tree[x];
		else {
			int m = (l + r) >> 1;
			if (pos <= m)return seek(pos, l, m, x << 1);
			else return seek(pos, m + 1, r, x << 1 | 1);
		}
	}
};
