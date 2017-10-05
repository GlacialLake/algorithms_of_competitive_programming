#include<cassert>
namespace cb {
	/*
		USAGE:
		mod maxn(factorial)
	*/
	const long long mod = (long long)1e9 + 7;
	long long ex_gcd(long long a, long long b, long long& x, long long& y)
	{
		if (!b) { x = 1, y = 0; return a; }
		long long ret = ex_gcd(b, a % b, y, x);
		y -=  a / b * x;
		return ret;
	}
	inline long long ad(long long a, long long b) { return (a + b) % mod; }
	inline long long sb(long long a, long long b) { return (a - b + mod) % mod; }
	inline long long mu(long long a, long long b) { return (a * b) % mod; }
	inline long long di(long long a, long long b)
	{
		long long x, y;
		assert(ex_gcd(b, mod, x, y) == 1);
		return mu(a, (x % mod + mod) % mod);
	}
	const int maxn = 200000;
	long long fact[maxn + 1];
	inline void init_fact()
	{
		fact[0] = 1;
		for(int i = 1; i < maxn + 1; ++i)
			fact[i] = mu(fact[i - 1], i);
	}
	inline long long co(long long n, long long k) { return di(fact[n], mu(fact[k], fact[n - k])); }
};
