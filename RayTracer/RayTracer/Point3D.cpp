#include "stdafx.h"
#include <math.h>
#include "Point3D.h"

// Default constructor
Point3D::Point3D(double x, double y, double z)
{
	m_Components[POINT3D_X_COMPONENT] = x;
	m_Components[POINT3D_Y_COMPONENT] = y;
	m_Components[POINT3D_Z_COMPONENT] = z;
}

// Copy Constructor
Point3D::Point3D(const Point3D& other)
{
	m_Components[POINT3D_X_COMPONENT] = other.GetX();
	m_Components[POINT3D_Y_COMPONENT] = other.GetY();
	m_Components[POINT3D_Z_COMPONENT] = other.GetZ();
}

// Assignment operator
Point3D& Point3D::operator=(const Point3D& other)
{
	if (this != &other)
	{
		m_Components[POINT3D_X_COMPONENT] = other.m_Components[POINT3D_X_COMPONENT];
		m_Components[POINT3D_Y_COMPONENT] = other.m_Components[POINT3D_Y_COMPONENT];
		m_Components[POINT3D_Z_COMPONENT] = other.m_Components[POINT3D_Z_COMPONENT];
	}
	return *this;
}

// Subscript operator
double& Point3D::operator[](int i)
{
	if (i >= 0 && i < POINT3D_MAX_COMPONENTS)
	{
		return m_Components[i];
	}
	else
	{
		// We should throw an exception or at least, handle the error...
		// By default, we return the first element
		return m_Components[0];
	}
}

Point3D Point3D::operator+(const Point3D& other)
{
	Point3D t;
	t.m_Components[POINT3D_X_COMPONENT] = m_Components[POINT3D_X_COMPONENT] + other.m_Components[POINT3D_X_COMPONENT];
	t.m_Components[POINT3D_Y_COMPONENT] = m_Components[POINT3D_Y_COMPONENT] + other.m_Components[POINT3D_Y_COMPONENT];
	t.m_Components[POINT3D_Z_COMPONENT] = m_Components[POINT3D_Z_COMPONENT] + other.m_Components[POINT3D_Z_COMPONENT];
	return t;
}

Point3D& Point3D::operator+=(const Point3D& other)
{
	*this = *this + other;
	return *this;
}

Point3D Point3D::operator-(const Point3D& other)
{
	Point3D t;
	t.m_Components[POINT3D_X_COMPONENT] = m_Components[POINT3D_X_COMPONENT] - other.m_Components[POINT3D_X_COMPONENT];
	t.m_Components[POINT3D_Y_COMPONENT] = m_Components[POINT3D_Y_COMPONENT] - other.m_Components[POINT3D_Y_COMPONENT];
	t.m_Components[POINT3D_Z_COMPONENT] = m_Components[POINT3D_Z_COMPONENT] - other.m_Components[POINT3D_Z_COMPONENT];
	return t;
}

Point3D& Point3D::operator-=(const Point3D& other)
{
	*this = *this - other;
	return *this;
}

Point3D Point3D::operator*(double a)
{
	Point3D t = *this;
	t.m_Components[POINT3D_X_COMPONENT] *= a;
	t.m_Components[POINT3D_Y_COMPONENT] *= a;
	t.m_Components[POINT3D_Z_COMPONENT] *= a;
	return t;
}

Point3D& Point3D::operator*=(double a)
{
	*this = *this * a;
	return *this;
}

Point3D Point3D::operator/(double a)
{
	Point3D t = *this;
	t.m_Components[POINT3D_X_COMPONENT] /= a;
	t.m_Components[POINT3D_Y_COMPONENT] /= a;
	t.m_Components[POINT3D_Z_COMPONENT] /= a;
	return t;
}

Point3D& Point3D::operator/=(double a)
{
	*this = *this / a;
	return *this;
}

double Point3D::distance(const Point3D &other) {
	return (sqrt(
		(m_Components[POINT3D_X_COMPONENT] - other.m_Components[POINT3D_X_COMPONENT]) * (m_Components[POINT3D_X_COMPONENT] - other.m_Components[POINT3D_X_COMPONENT]) +
		(m_Components[POINT3D_Y_COMPONENT] - other.m_Components[POINT3D_Y_COMPONENT]) * (m_Components[POINT3D_Y_COMPONENT] - other.m_Components[POINT3D_Y_COMPONENT]) +
		(m_Components[POINT3D_Z_COMPONENT] - other.m_Components[POINT3D_Z_COMPONENT]) * (m_Components[POINT3D_Z_COMPONENT] - other.m_Components[POINT3D_Z_COMPONENT])));
}
double Point3D::squaredDistance(const Point3D&other) {
	return (
		(m_Components[POINT3D_X_COMPONENT] - other.m_Components[POINT3D_X_COMPONENT]) * (m_Components[POINT3D_X_COMPONENT] - other.m_Components[POINT3D_X_COMPONENT]) +
		(m_Components[POINT3D_Y_COMPONENT] - other.m_Components[POINT3D_Y_COMPONENT]) * (m_Components[POINT3D_Y_COMPONENT] - other.m_Components[POINT3D_Y_COMPONENT]) +
		(m_Components[POINT3D_Z_COMPONENT] - other.m_Components[POINT3D_Z_COMPONENT]) * (m_Components[POINT3D_Z_COMPONENT] - other.m_Components[POINT3D_Z_COMPONENT]));
}

