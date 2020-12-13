#pragma once

const int VECTOR3D_X_COMPONENT = 0;
const int VECTOR3D_Y_COMPONENT = 1;
const int VECTOR3D_Z_COMPONENT = 2;
const int VECTOR3D_MAX_COMPONENTS = 3;
// TODO: See 2.6.2 - Operations (Page 26)
class Vector3D
{
public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);		// Default constructor
	Vector3D(const Vector3D& other);			// Copy constructor

	Vector3D& operator=(const Vector3D& other); // Copy assignment operator
	double& operator[](int i);					// Subscript operator
	Vector3D operator+(const Vector3D& other);	// + operator
	Vector3D& operator+=(const Vector3D& other);// += operator
	Vector3D operator-(const Vector3D& other);	// - operator
	Vector3D& operator-=(const Vector3D& other);// -= operator
	Vector3D operator*(double a);				// * operator
	Vector3D& operator*=(double a);				// *= operator
	Vector3D operator/(double a);				// / operator
	Vector3D& operator/=(double a);				// /= operator
	Vector3D operator^(const Vector3D& other);  // Cross product
	double operator*(const Vector3D& other);	// Dot product
	double length();
	double squaredLength(); 
	void normalize(void); 						// convert vector to a unit vector
	Vector3D& hat(void); 						// return a unit vector, and normalize the vector

	double GetX() const { return m_Components[VECTOR3D_X_COMPONENT]; }
	double GetY() const { return m_Components[VECTOR3D_Y_COMPONENT]; }
	double GetZ() const { return m_Components[VECTOR3D_Z_COMPONENT]; }

private:
	double m_Components[VECTOR3D_MAX_COMPONENTS]; // X, Y, Z
};

