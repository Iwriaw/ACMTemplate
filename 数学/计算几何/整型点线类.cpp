#include <bits/stdc++.h>
using namespace std;
//本模板的坐标均为整数，尽可能的避开浮点运算，非必要不进行浮点运算以免产生精度问题
//函数只依赖重载的运算符，相互独立。
//具备浮点型点线类的大部分功能。
const double PI = acos(-1); //圆周率
const double eps = 1e-8;    //eps用来修正误差
struct Point                //二维点、向量类
{
    int x, y;
    friend bool operator<(const Point &a, const Point &b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend Point operator+(const Point &a, const Point &b) //加法
    {
        return Point{a.x + b.x, a.y + b.y};
    }
    friend Point operator-(const Point &a, const Point &b) //减法
    {
        return Point{a.x - b.x, a.y - b.y};
    }
    friend int operator*(const Point &a, const Point &b) //点积(dot product)，数量积a·b=|a||b|cos theta
    {
        return a.x * b.x + a.y * b.y;
    }
    friend int operator^(const Point &a, const Point &b) //叉积(cross product)，向量积|a^b|=|a||b|sin theta
    {
        return a.x * b.y - a.y * b.x; //向量a->b为逆时针值为正：(1,0)^(0,1)=1
    }
    friend int dist2(const Point &a, const Point &b) //两点距离的平方
    {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    int len2() const //向量长度的平方
    {
        return x * x + y * y;
    }
    friend double angle(const Point &a, const Point &b) //a->b的逆时针夹角[0, PI]，这里利用点积计算
    {
        return acos(a * b / sqrt(a.len2()) / sqrt(b.len2()));
    }
    friend Point rotate(const Point &a, const double &rad)
    {
        Point b = {sin(rad), cos(rad)};
        return {a ^ b, a * b};
    }
};
struct Line //二维直线、线段类 基于点类实现
{
    Point a, b;                        //确定直线、线段的两个端点。当a==b时，该直线可以表示为任何过a、b点直线，该线段退化为点a、b。
    friend int posP2L(Point a, Line b) //点和直线的位置关系，通过叉积判断。0：点在直线上，+：点在直线左边，-：点在直线右边
    {
        return (b.b - b.a) ^ (a - b.a);
    }
    friend int posP2S(Point a, Line b) //点和线段的位置关系， 1：点在线段内，-1：点在线段端点，0：点不在线段上
    {
    }
    friend double distP2L(Point a, Line b) //点a到直线b的距离(point to line)。
    {
    }
    friend double distP2S(Point a, Line b) //点a到线段b的距离(point to segment)
    {
    }
};