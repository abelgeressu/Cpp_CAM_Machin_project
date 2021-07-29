#include "PointCloud.hpp"



PointCloud::PointCloud()
:
_refPoint(0.0, 0.0, 0.0),
_endPoint(0.0, 0.0, 0.0),
_nx(0),
_ny(0),
_nz(0),
_delta(0.0)
{
}

PointCloud::PointCloud(const point3d refPoint, const unsigned long& nx, const unsigned long& ny, const unsigned long& nz, const double& delta)
:
_refPoint(refPoint),
_nx(nx),
_ny(ny),
_nz (nz),
_delta(delta)
{
	_endPoint.x(_refPoint.x() + (_nx - 1) * _delta);
	_endPoint.y(_refPoint.y() + (_ny - 1) * _delta);
	_endPoint.z(_refPoint.y() + (_nz - 1) * _delta);
	SetRectangle(_refPoint, _nx, _ny, _nz, _delta);
}


void PointCloud::RemovePoints(point3d center, const double& radius)
{
	for (_rectIt it = _rect.begin(); it != _rect.end(); )
	{
		auto inside = [&]()->bool
		{
			return ((pow((*it)->point.x() - center.x(), 2) + pow((*it)->point.y() - center.y(), 2) + pow((*it)->point.z() - center.z(), 2)) < pow(radius, 2));
		};

		if (inside())
		{
			if ((*it)->visible)
			{
				ChangeUpperLayer(**it);
			}
			it = _rect.erase(it);
		}
		else
		{
			++it;
		}
	
	}

	//_rect.remove_if([](std::shared_ptr<PointCloud::pointRect>& sptr) {return !sptr->visible; });
/*
	for (unsigned long x = 0; x < _nx; ++x)
		for (unsigned long y = 0; y < _ny; ++y)
			for (unsigned long z = 0; z < _nz; ++z)
			{
				if (
					(pow(_rectNEW[x][y][z]->point.x() - center.x(), 2) + pow(_rectNEW[x][y][z]->point.y() - center.y(), 2) + pow(_rectNEW[x][y][z]->point.z() - center.z(), 2)) < pow(radius, 2)
					)
					if (_rectNEW[x][y][z]->visible && y >= 1)
					{
						_rectNEW[x][y][z]->visible = false;
						_rectNEW[x][y-1][z]->visible = true;
					}
			}
*/

}


void PointCloud::Draw(const std::string& skinFileName)
{
	std::ofstream testFile(skinFileName, std::ios_base::trunc);
	if (!testFile.is_open())
	{
		std::cout << "Error while opening file " << skinFileName;
		return;
	}
	else
	{
		for (auto& ptr : _rect)
		{
			if (ptr->visible)
				testFile << ptr->point.x() << " " << ptr->point.y() << " " << ptr->point.z() << std::endl;
		}
		testFile.close();
	}

}

void PointCloud::SetRectangle(const point3d refPoint, const unsigned long& nx, const unsigned long& ny, const unsigned long& nz, const double& delta)
{
	 _refPoint = refPoint;
	 _nx = nx;
	 _ny = ny;
	 _nz = nz;
	 _delta = delta; 

	 _endPoint.x(_refPoint.x() + (_nx - 1) * _delta);
	 _endPoint.y(_refPoint.y() + (_ny - 1) * _delta);
	 _endPoint.z(_refPoint.y() + (_nz - 1) * _delta);


	 if (!_rect.empty())
	 {
		 _rect.clear();
	 }

	 for (double x = _refPoint.x(); x <= _endPoint.x(); x += _delta)
		 for (double y = _refPoint.y(); y <= _endPoint.y(); y += _delta)
			 for (double z = _refPoint.z(); z <= _endPoint.z(); z += _delta)
			 {
				if (y == _endPoint.y())
					dot.visible = true;
				else
					dot.visible = false;

				dot.point = point3d(x, y, z);

				 _rect.push_back(std::make_shared<pointRect>(dot));
			 }


/*
	 if (!_rectNEW.empty())
	 {
		 _rectNEW.clear();
	 }

	 dot.point = _refPoint;
	 _rectNEW.reserve(_nx);
	 for (unsigned long x = 0; x < _nx; ++x, dot.point.x(dot.point.x() + _delta))
	 {
		 std::vector<std::vector<std::shared_ptr<pointRect>>> vectorX;
		 vectorX.reserve(_ny);
		 for (unsigned long y = 0; y < _ny; ++y, dot.point.y(dot.point.y() + _delta))
		 {
			 std::vector<std::shared_ptr<pointRect>> vectorY;
			 vectorY.reserve(_nz);
			 for (unsigned long z = 0; z < _nz; ++z, dot.point.z(dot.point.z() + _delta))
			 {
				 dot.visible = (dot.point.y() == _endPoint.y());

				 vectorY.push_back(std::make_shared<pointRect>(dot));
			 }
			 vectorX.push_back(vectorY);
		 }
		 _rectNEW.push_back(vectorX);
	 }
*/

}


void PointCloud::ChangeUpperLayer(pointRect deletedPoint)
{

	_rectIt it = _rect.begin();
	double max = (*it)->point.y();

	for (_rectIt ptr = _rect.begin(); ptr != _rect.end(); ptr++)
	{
		if ((*ptr)->point.x() == deletedPoint.point.x() && (*ptr)->point.z() == deletedPoint.point.z())
		{
			if ((*ptr)->point.y() > max && (*ptr)->point.y() < deletedPoint.point.y())
			{
				max = (*ptr)->point.y();
				it = ptr;
			}
		}

	}

	(*it)->visible = true;

}