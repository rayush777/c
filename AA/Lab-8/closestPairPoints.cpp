// WAP top find closest pair of points

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

int square(Point *p1, Point *p2)
{
    int d = ((p1->x - p2->x) * (p1->x - p2->x)) + ((p1->y - p2->y) * (p1->y - p2->y));
    return d;
}

vector<double> closestPairofPoints(vector<Point *> points, int n)
{
    int dmin = INT_MAX;
    double i1, i2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = square(points[i], points[j]);
            if (d < dmin)
            {
                dmin = d;
                i1 = i, i2 = j;
            }
        }
    }
    return {i1, i2, sqrt(dmin)};
}

int main()
{
    int n;
    cin >> n;
    vector<Point *> points(n);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points[i] = new Point(x, y);
    }
    vector<double> sol = closestPairofPoints(points, n);

    cout << "Closest pair are : (" << points[sol[0]]->x << "," << points[sol[0]]->y << ") | (" << points[sol[1]]->x << "," << points[sol[1]]->y << ")\n";

    cout << "Distance: " << sol[2] << endl;
    return 0;
}
