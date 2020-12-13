#include "stdafx.h"
#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
	m_Components[0] = x;
	m_Components[1] = y;
	m_Components[2] = z;
}
