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
};
struct Graham
{
    Polar po;
    vector<Point> getCH(vector<Point> v)//get convex hull
    {
        vector<Point> ans;
        v = po.getorder(v);//极角排序后还需要一点修改，最后一个点和起始点连接线段上可能有多个点
        //这里要加一段，没写完
        for (auto i : v)
        {
            while (ans.size() >= 2 && ((ans[ans.size() - 1] - ans[ans.size() - 2]) ^ (i - ans[ans.size() - 1])) < 0)
                ans.pop_back();
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    return 0;
}