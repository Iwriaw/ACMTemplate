#include <bits/stdc++.h>
using namespace std;
struct Point //二维点、向量类
{
    int x, y;
    friend Point operator-(const Point &a, const Point &b) //减法
    {
        return Point{a.x - b.x, a.y - b.y};
    }
    friend int operator^(const Point &a, const Point &b) //叉积(cross product)，向量积|a^b|=|a||b|sin theta
    {
        return a.x * b.y - a.y * b.x; //向量a->b为逆时针值为正：(1,0)^(0,1)=1
    }
    friend bool operator<(const Point &a, const Point &b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    int len2() const //向量长度的平方
    {
        return x * x + y * y;
    }
};
struct Polar //极角排序
{
    struct cmpo
    {
        Point p;
        bool operator()(Point a, Point b)
        {
            Point pa = a - p;
            Point pb = b - p;
            return (pa ^ pb) > 0 || ((pa ^ pb) == 0 && pa.len2() < pb.len2()); //角相同短的排前面
        }
    } cmp;
    vector<Point> getorder(vector<Point> v)
    {
        for (int i = 1; i < v.size(); i++) //v[0]换为(x,y)最小的点
            if (v[i] < v[0])
                swap(v[0], v[i]);
        cmp.p = v[0];
        sort(v.begin() + 1, v.end(), cmp);
        return v;
    }
} po;
int main()
{
    int n;
    cin >> n;
    vector<Point> v;
    while (n--)
    {
        Point p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }
    v = po.getorder(v);
    for (auto i : v)
        cout << i.x << ',' << i.y << ' ';
    cout << endl;
    return 0;
}