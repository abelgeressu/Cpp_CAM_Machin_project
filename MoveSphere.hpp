#pragma once

#include "mwTPoint3d.hpp"
#include <iostream>
#include <iomanip>


class MoveSphere
{
private:
    cadcam::mwTPoint3d<double> _centerPoint;
    cadcam::mwTPoint3d<double> _startPoint;
    cadcam::mwTPoint3d<double> _endPoint;
    double _delta;
    double _distance;
    cadcam::mwTPoint3d<double> _step;

    double temp=0., temp1=0., temp2=0.;

public:
    MoveSphere(cadcam::mwTPoint3d<double> start, cadcam::mwTPoint3d<double> end, double delta)
    :
    _startPoint(start),
    _endPoint(end),
    _delta(delta)
    {
        _distance = ~(_endPoint - _startPoint); // distance
        _step = _endPoint - _startPoint; // direction
        if (_distance > 0)
        {
            _step *= _delta  / _distance;
        }
        _centerPoint = _startPoint;

        temp1 = _distance / _delta;
    }
    ~MoveSphere() {}

    bool operator()()
    {

        _distance = ~(_endPoint - _centerPoint); 

        if (_centerPoint == _endPoint)
        {
            return false;
        }

        if (_distance < _delta)
        {
            _centerPoint = _endPoint;
        }
        else
        {
            _centerPoint += _step;
        }

        ++temp;
        temp2 = temp * 100 / temp1;
        std::cout << std::setw(10) << temp2 << " % complete;    " << temp << " out of " << temp1 << " spheres calculated" "\r";
        //	std::cout << " distance = " << _distance<< " delta = "<< _delta<<std::endl;

        return true;
    }


    cadcam::mwTPoint3d<double> GetCenter() { return _centerPoint; }


};