#pragma once

#include "mwTPoint3d.hpp"
#include <list>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm> 

class PointCloud
{
private:
    typedef cadcam::mwTPoint3d<double> point3d;

    struct pointRect
    {
        point3d point = point3d(0.,0.,0.);
        bool visible = false;
    } dot;
	
    std::list < std::shared_ptr<pointRect> >  _rect;
    typedef std::list < std::shared_ptr<pointRect> >::const_iterator _rectIt;

    point3d _refPoint;
    point3d _endPoint;
    unsigned long _nx;
    unsigned long _ny;
    unsigned long _nz;
    double _delta;

    void ChangeUpperLayer(pointRect deletedPoint);

    std::vector<std::vector<std::vector<std::shared_ptr<pointRect>>>> _rectNEW;

public:
    PointCloud();
    PointCloud(const point3d refPoint, const unsigned long& nx, const unsigned long& ny, const unsigned long& nz, const double& delta);
    ~PointCloud() {}

    void RemovePoints(point3d center, const double& radius);

    void Draw(const std::string& skinFileName);

    void SetRectangle(const point3d refPoint, const unsigned long& nx, const unsigned long& ny, const unsigned long& nz, const double& delta);
};