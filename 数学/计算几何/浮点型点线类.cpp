#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);//圆周率
const double eps = 1e-8;//eps用来修正误差
int sgn(const double& x)
{
    return x < -eps ? -1 : x > eps;
}
struct Point
{
    double x, y;
    friend Point operator+(const Point &a, const Point &b) //加法
    {
        return Point{a.x + b.x, a.y + b.y};
    }
    friend Point operator-(const Point &a, const Point &b) //减法
    {
        return Point{a.x - b.x, a.y - b.y};
    }
    friend double operator*(const Point &a, const Point &b) //点积(dot product)，数量积a·b=|a||b|cos theta
    {
        return a.x * b.x + a.y * b.y;
    }
    friend double operator^(const Point &a, const Point &b) //叉积(cross product)，向量积|a^b|=|a||b|sin theta
    {
        return a.x * b.y - a.y * b.x; //向量a->b为逆时针值为正：(1,0)^(0,1)=1
    }
    friend double dist(const Point &a, const Point &b) //两点距离
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    double len() const //向量长度
    {
        return sqrt(x * x + y * y);
    }
    Point normal() const //单位法向量，逆时针旋转PI/2。(1,0)->(0,1)
    {
        return Point{-y / len(), x / len()};
    }
    friend double angle(const Point &a, const Point &b) //a,b的夹角[0, PI]，这里利用点积计算
    {
        return acos(a * b / a.len() / b.len());
    }
};
struct Line
{
    Point a, b;

};
int main()
{

    return 0;
}