#ifndef ZADANIE5_HPP
#define ZADANIE5_HPP

class Point{
private:
	float x;
	float y;
public:
	Point(float x, float y);
	float getX();
	float getY();
	void move(Point p);
};
#endif // ZADANIE5_HPP

