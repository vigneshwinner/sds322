#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Point
{
	private:
		float px, py;
	public:
		Point()
		{
			px = 1.;
			py = 1.;
		}

		Point(float xcoordinate, float ycoordinate)
		{
			px = xcoordinate;
			py = ycoordinate;
		}

		float distance_to_origin()
		{
			float dist = sqrt(pow(px, 2) + pow(py, 2));
			return dist;
		}	

		void display()
		{
			cout << "Point: (" << px << ", " << py << ")" << endl;
		}

		float distance(Point p2)
		{
			float dist = sqrt(pow(px - p2.px, 2) + pow(py - p2.py, 2));
			return dist;
		}
};

int main()
{
	Point p1;
	Point p2(10., 10.);

	cout << "Distance from origin: " << p2.distance_to_origin() << endl;
	p1.display();
	cout << "Distance from Point 2: " << p1.distance(p2) << endl;

}
