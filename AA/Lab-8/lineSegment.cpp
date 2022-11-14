// LineSegment
/// W.A.P. to check if p1p2 intersect with p3p4 or not.

#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

int Direction(Point *pi, Point *pj, Point *pk)
{
    Point *ref = new Point(pj->x - pi->x, pj->y - pi->y);
    Point *tmp = new Point(pk->x - pi->x, pk->y - pi->y);

    // int d = (ref->x * tmp->y) - (tmp->x * ref->y);

    int d = (tmp->x * ref->y) - (tmp->y * ref->x);

    return d;
}

bool onSegment(Point *pi, Point *pj, Point *pk)
{

    if ((min(pi->x, pj->x) <= pk->x and max(pi->x, pj->x)) >= pk->x and (min(pi->y, pj->y) <= pk->y and max(pi->y, pj->y)))
        return true;
    return false;
}

bool LineSegment(Point *p1, Point *p2, Point *p3, Point *p4)
{

    int d1, d2, d3, d4;

    d1 = Direction(p3, p4, p1);
    d2 = Direction(p3, p4, p2);
    d3 = Direction(p1, p2, p3);
    d4 = Direction(p1, p2, p4);

    if (d1 * d2 < 0 and d3 * d4 < 0)
        return true;
    else if (d1 == 0 and onSegment(p3, p4, p1))
        return true;
    else if (d2 == 0 and onSegment(p3, p4, p2))
        return true;
    else if (d3 == 0 and onSegment(p1, p2, p3))
        return true;
    else if (d4 == 0 and onSegment(p1, p2, p4))
        return false;
    else
        return true;
}

int main()
{
    Point *p1, *p2, *p3, *p4;
    // p1 = new Point(1, 1);
    // p2 = new Point(4, 8);
    // p3 = new Point(2, 6);
    // p4 = new Point(6, 3);

    int x, y;
    cin >> x >> y;
    p1 = new Point(x, y);
    cin >> x >> y;
    p2 = new Point(x, y);
    cin >> x >> y;
    p3 = new Point(x, y);
    cin >> x >> y;
    p4 = new Point(x, y);

    if (LineSegment(p1, p2, p3, p4))
        cout << "Line segment p1p2  Intersecting with p3p4" << endl;
    else
        cout << "Line segment does not Intersect" << endl;

    return 0;
}
