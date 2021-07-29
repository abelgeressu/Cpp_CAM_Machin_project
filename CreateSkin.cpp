#include "CreateSkin.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include "Sphere.hpp"
#include "PointCloud.hpp"
#include "MoveSphere.hpp"


void CreateSkin(const cadcam::mwTPoint3d<double> refPoint,
    const unsigned long nx, const unsigned long ny,
    const unsigned long nz, const double sphereRad,
    mwDiscreteFunction& func, const double deltaT,
    const double delta, const std::string& skinFileName)
{

    //Your source code here...

    PointCloud _pointCloud(refPoint, nx, ny, nz, delta);

    Sphere _sphere(point3d(9.5, 19.5, 0.), sphereRad);

    MoveSphere _moveSphere(_sphere.GetCenter(), point3d(9.5, 19.5, 19.5), deltaT);

    do
    {
        _pointCloud.RemovePoints(_moveSphere.GetCenter(), _sphere.GetRadius());
    }
    while ( _moveSphere() );

    _pointCloud.Draw(skinFileName);
}