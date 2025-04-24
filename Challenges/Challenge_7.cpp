#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

struct point
{
	float x;
	float y;
};

struct line_segment
{
    point p1;
    point p2;
};

float calc_distance(line_segment line)
{
	float dist = sqrt(pow(line.p1.x - line.p2.x, 2) + pow(line.p1.y - line.p2.y, 2));
	return dist;
}

int main() 
{
	line_segment line;
	line.p1.x = 3.;
	line.p1.y = 4.;
	line.p2.x = 2.;
	line.p2.y = 2.;
	float dist = calc_distance(line);
	cout << dist << endl;

	return 0;
}
