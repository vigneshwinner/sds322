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

		float getX()
		{
			return px;
		}

		float getY()
		{
			return py;
		}

		void setX(float px)
		{
			this->px = px;
		}

		void setY(float py)
		{
			this->py = py;
		}

                float distance_to_origin()
                {
                        float dist = sqrt(pow(px, 2) + pow(py, 2));
                        return dist;
                }

                void display()
                {
                        cout << "(" << getX() << ", " << getY() << ")" << endl;
                }

                float distance(Point p2)
                {
                        float dist = sqrt(pow(px - p2.getX(), 2) + pow(py - p2.getY(), 2));
                        return dist;
                }
};

class Line
{
	private:
		Point p1, p2;

	public:
		Line(Point p1, Point p2)
		{
			this->p1 = p1;
			this->p2 = p2;
		}

		void display()
		{
			p1.display();
			p2.display();
		}

		Point midpoint()
		{
			Point mid;
			mid.setX((p1.getX()+ p2.getX()) / 2);
			mid.setY((p1.getY() + p2.getY()) / 2);
			return mid;
		}
};

int main()
{
	Point p1;
	Point p2(10, 10);

	Line line(p1, p2);

	line.display();
	cout << "\nMidpoint: " << endl;
	line.midpoint().display();
}
