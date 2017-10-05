#include<cmath>
#include<vector>
namespace cg {
	struct P { double x, y; P(double _x = 0, double _y = 0) :x(_x), y(_y) {} };
	inline double sq(double x) { return x*x; }
	inline double dis2(P A, P B) { return sq(A.x - B.x) + sq(A.y - B.y); }
	inline double len2(P A) { return sq(A.x) + sq(A.y); }
	inline double dot(P A, P B) { return A.x*B.x + A.y*B.y; }
	inline double det(P A, P B) { return A.x*B.y - A.y*B.x; }
	inline double ang(P A, P B) { return acos(dot(A, B) / sqrt(len2(A)) / sqrt(len2(B))); }
	inline P operator + (P A, P B) { return P(A.x + B.x, A.y + B.y); }
	inline P operator - (P A, P B) { return P(A.x - B.x, A.y - B.y); }
	inline P operator * (P A, double a) { return P(A.x * a, A.y * a); }
	inline P operator / (P A, double a) { return P(A.x / a, A.y / a); }
	inline P rot(P A, double rad) { return P(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad)); }
	inline bool zero(double x) { return x < 0 ? (-x) < 1e-10 : x < 1e-10; }
	inline bool operator < (const P& A, const P& B) { return A.x < B.x || (zero(A.x - B.x) && A.y < B.y); }
	inline bool colin(P A, P B, P C) { return zero(det(B - A, C - A)); }
	inline P cross(P A, P v1, P B, P v2) { return A + v1 * (det(v2, A - B) / det(v1, v2)); }
	inline double dtolin(P A, P X, P Y)
	{
		P v = Y - X;
		return fabs(det(v, A - X)) / sqrt(len2(v));
	}
	/*
		vector v's valid index starts from 0
	*/
	double polya(std::vector<P> v)
	{
		double tot = 0;
		int sz = v.size();
		for (int i = 1; i < sz - 1; ++i)
			tot += det(v[i] - v[0], v[i + 1] - v[0]);
		return fabs(tot / 2);
	}
};
