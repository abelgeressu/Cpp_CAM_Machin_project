#include "Sphere.hpp"

Sphere::Sphere(cadcam::mwTPoint3d<double> center, const double& radius)
: _center(center),
  _radius(radius)
{
}

/*
bool Sphere::isPointInside(cadcam::mwTPoint3d<double>& point)
{
    return ( (pow(*point-*_center, 2) + pow(*(point + 1) - *(_center + 1), 2) + pow(*(point + 2) - *(_center + 2), 2)) < pow(_radius, 2) );	
}
*/