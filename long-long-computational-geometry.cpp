namespace cg {
	struct P { long long x, y; P(long long _x = 0, long long _y = 0) :x(_x), y(_y) {} };
	inline long long sq(long long x) { return x*x; }
	inline long long dis2(P A, P B) { return sq(A.x - B.x) + sq(A.y - B.y); }
	inline long long dot(P A, P B) { return A.x*B.x + A.y*B.y; }
	inline long long det(P A, P B) { return A.x*B.y - A.y*B.x; }
	inline long long len2(P A) { return sq(A.x) + sq(A.y); }
	inline P operator + (P A, P B) { return P(A.x + B.x, A.y + B.y); }
	inline P operator - (P A, P B) { return P(A.x - B.x, A.y - B.y); }
	inline P operator * (P A, long long a) { return P(A.x * a, A.y * a); }
	inline P operator / (P A, long long a) { return P(A.x / a, A.y / a); }
	inline bool operator < (const P& A, const P& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }
	inline bool colin(P A, P B, P C) { return det(B - A, C - A) == 0; }
};
