#include<cmath>
#include<algorithm>
namespace st {
	/* the index starts from 1 */
	/* maxc = upper(log2(maxn)) */
	/* 
		USAGE:
		maxn maxc n seq
		init()
		rmxq(l, r)[l, r]{pos}
	*/
	const int maxn = 100000, maxc = 17;
	int seq[maxn + 1], n;
	int st[maxn + 1][maxc + 1];
	void init()
	{
	    for (int i = 1; i <= n; ++i)
	        st[i][0] = i;
	    for (int j = 1; j < maxc + 1; ++j)
	        for (int i = 1; i + (1 << (j - 1)) - 1 <= n; ++i)
	            if (seq[st[i][j - 1]] > seq[st[i + (1 << (j - 1))][j - 1]])
	                st[i][j] = st[i][j - 1];
	            else
	                st[i][j] = st[i + (1 << (j - 1))][j - 1];
	}
	int rmxq(int l, int r)
	{
	    int k = (int)log2(r - l + 1);
	    if (seq[st[l][k]] > seq[st[r - (1 << k) + 1][k]])
	        return st[l][k];
	    else
	        return st[r - (1 << k) + 1][k];
	}
};
