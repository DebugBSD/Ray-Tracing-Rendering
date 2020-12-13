#include "stdafx.h"
#include <math.h>
#include "Vector3D.h"

// Default constructor
Vector3D::Vector3D(double x, double y, double z)
{
	m_Components[VECTOR3D_X_COMPONENT] = x;
	m_Components[VECTOR3D_Y_COMPONENT] = y;
	m_Components[VECTOR3D_Z_COMPONENT] = z;
}

// Copy Constructor
Vector3D::Vector3D(const Vector3D& other)
{
	m_Components[VECTOR3D_X_COMPONENT] = other.GetX();
	m_Components[VECTOR3D_Y_COMPONENT] = other.GetY();
	m_Components[VECTOR3D_Z_COMPONENT] = other.GetZ();
}

// Assignment operator
Vector3D& Vector3D::operator=(const Vector3D& other)
{
	if (this != &other)
	{
		m_Components[VECTOR3D_X_COMPONENT] = other.m_Components[VECTOR3D_X_COMPONENT];
		m_Components[VECTOR3D_Y_COMPONENT] = other.m_Components[VECTOR3D_Y_COMPONENT];
		m_Components[VECTOR3D_Z_COMPONENT] = other.m_Components[VECTOR3D_Z_COMPONENT];
	}
	return *this;
}

// Subscript operator
double& Vector3D::operator[](int i)
{
	if (i >= 0 && i < VECTOR3D_MAX_COMPONENTS)
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

Vector3D Vector3D::operator+(const Vector3D& other)
{
	Vector3D t;
	t.m_Components[VECTOR3D_X_COMPONENT] = m_Components[VECTOR3D_X_COMPONENT] + other.m_Components[VECTOR3D_X_COMPONENT];
	t.m_Components[VECTOR3D_Y_COMPONENT] = m_Components[VECTOR3D_Y_COMPONENT] + other.m_Components[VECTOR3D_Y_COMPONENT];
	t.m_Components[VECTOR3D_Z_COMPONENT] = m_Components[VECTOR3D_Z_COMPONENT] + other.m_Components[VECTOR3D_Z_COMPONENT];
	return t;
}

Vector3D& Vector3D::operator+=(const Vector3D& other)
{
	*this = *this + other;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	Vector3D t;
	t.m_Components[VECTOR3D_X_COMPONENT] = m_Components[VECTOR3D_X_COMPONENT] - other.m_Components[VECTOR3D_X_COMPONENT];
	t.m_Components[VECTOR3D_Y_COMPONENT] = m_Components[VECTOR3D_Y_COMPONENT] - other.m_Components[VECTOR3D_Y_COMPONENT];
	t.m_Components[VECTOR3D_Z_COMPONENT] = m_Components[VECTOR3D_Z_COMPONENT] - other.m_Components[VECTOR3D_Z_COMPONENT];
	return t;
}

Vector3D& Vector3D::operator-=(const Vector3D& other)
{
	*this = *this - other;
	return *this;
}

Vector3D Vector3D::operator*(double a)
{
	Vector3D t = *this;
	t.m_Components[VECTOR3D_X_COMPONENT] *= a;
	t.m_Components[VECTOR3D_Y_COMPONENT] *= a;
	t.m_Components[VECTOR3D_Z_COMPONENT] *= a;
	return t;
}

Vector3D& Vector3D::operator*=(double a)
{
	*this = *this * a;
	return *this;
}

Vector3D Vector3D::operator/(double a)
{
	Vector3D t = *this;
	t.m_Components[VECTOR3D_X_COMPONENT] /= a;
	t.m_Components[VECTOR3D_Y_COMPONENT] /= a;
	t.m_Components[VECTOR3D_Z_COMPONENT] /= a;
	return t;
}

Vector3D& Vector3D::operator/=(double a)
{
	*this = *this / a;
	return *this;
}

Vector3D Vector3D::operator^(const Vector3D& other)
{
	return (Vector3D(
		m_Components[VECTOR3D_Y_COMPONENT] * other.m_Components[VECTOR3D_Z_COMPONENT] - m_Components[VECTOR3D_Z_COMPONENT] * other.m_Components[VECTOR3D_Y_COMPONENT],
		m_Components[VECTOR3D_Z_COMPONENT] * other.m_Components[VECTOR3D_X_COMPONENT] - m_Components[VECTOR3D_X_COMPONENT] * other.m_Components[VECTOR3D_Z_COMPONENT],
		m_Components[VECTOR3D_X_COMPONENT] * other.m_Components[VECTOR3D_Y_COMPONENT] - m_Components[VECTOR3D_Y_COMPONENT] * other.m_Components[VECTOR3D_X_COMPONENT]));
}

double Vector3D::operator*(const Vector3D& other)
{
	return (
		m_Components[VECTOR3D_X_COMPONENT] * other.m_Components[VECTOR3D_X_COMPONENT] + 
		m_Components[VECTOR3D_Y_COMPONENT] * other.m_Components[VECTOR3D_Y_COMPONENT] + 
		m_Components[VECTOR3D_Z_COMPONENT] * other.m_Components[VECTOR3D_Z_COMPONENT]);
}

double Vector3D::length(void) {
	return (sqrt(
		m_Components[VECTOR3D_X_COMPONENT] * m_Components[VECTOR3D_X_COMPONENT] + 
		m_Components[VECTOR3D_Y_COMPONENT] * m_Components[VECTOR3D_Y_COMPONENT] + 
		m_Components[VECTOR3D_Z_COMPONENT] * m_Components[VECTOR3D_Z_COMPONENT]));
}
double Vector3D::squaredLength(void) {
	return (m_Components[VECTOR3D_X_COMPONENT] * m_Components[VECTOR3D_X_COMPONENT] +
			m_Components[VECTOR3D_Y_COMPONENT] * m_Components[VECTOR3D_Y_COMPONENT] +
			m_Components[VECTOR3D_Z_COMPONENT] * m_Components[VECTOR3D_Z_COMPONENT]);
}

void Vector3D::normalize(void)
{
	double l = length();
	m_Components[VECTOR3D_X_COMPONENT] /= l; 
	m_Components[VECTOR3D_Y_COMPONENT] /= l; 
	m_Components[VECTOR3D_Z_COMPONENT] /= l;
}

Vector3D& Vector3D::hat(void)
{
	double l = length();
	m_Components[VECTOR3D_X_COMPONENT] /= l;
	m_Components[VECTOR3D_Y_COMPONENT] /= l;
	m_Components[VECTOR3D_Z_COMPONENT] /= l;
	return (*this);
}
