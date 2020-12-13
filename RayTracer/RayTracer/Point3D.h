#pragma once

#include "Vector3D.h"

const int POINT3D_X_COMPONENT = 0;
const int POINT3D_Y_COMPONENT = 1;
const int POINT3D_Z_COMPONENT = 2;
const int POINT3D_MAX_COMPONENTS = 3;

// TODO: See 2.7 - Operations (Page 28)
class Point3D
{
public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0);		// Default constructor
	Point3D(const Point3D& other);			// Copy constructor

	Point3D& operator=(const Point3D& other);	// Copy assignment operator
	double& operator[](int i);					// Subscript operator
	Point3D operator+(const Point3D& other);	// + operator
	Point3D& operator+=(const Point3D& other);	// += operator
	Point3D operator-(const Point3D& other);	// - operator
	Point3D& operator-=(const Point3D& other);	// -= operator
	Point3D operator*(double a);				// * operator
	Point3D& operator*=(double a);				// *= operator
	Point3D operator/(double a);				// / operator
	Point3D& operator/=(double a);				// /= operator
	double distance(const Point3D& other);		// Length
	double squaredDistance(const Point3D& other);// Length Squared

	double GetX() const { return m_Components[POINT3D_X_COMPONENT]; }
	double GetY() const { return m_Components[POINT3D_Y_COMPONENT]; }
	double GetZ() const { return m_Components[POINT3D_Z_COMPONENT]; }

private:
	double m_Components[3]; // X, Y, Z
};

