#pragma once

#include "mwTPoint3d.hpp"

class Sphere
{
public:
    Sphere(cadcam::mwTPoint3d<double> center, const double& radius);
    ~Sphere() {}

    //bool isPointInside(cadcam::mwTPoint3d<double>& point);

    double GetRadius() { return _radius; }
    cadcam::mwTPoint3d<double> GetCenter() { return _center; }
    void SetCenter(cadcam::mwTPoint3d<double> center) { _center = center; }

private:
    cadcam::mwTPoint3d<double> _center;
    double _radius;
};