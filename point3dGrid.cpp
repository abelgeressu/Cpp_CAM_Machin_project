#include "point3dGrid.h"
#include "mwTPoint3d.hpp"

void point3dGrid::printFile(
	const std::string& skinFileName,
	const unsigned long& nx,
	const unsigned long& ny,
	const unsigned long& nz,
	const double& delta,
	const std::vector<std::vector <unsigned long> >& skin)
{
	std::ofstream	ofs;
	ofs.open(skinFileName);
	for (unsigned long i = 0; i < nx; i++)
		for (unsigned long j = 0; j < ny; j++)
			for (unsigned long k = 0; j < nz; k++)
					ofs << i * delta << ' ' << j * delta << ' ' << k * delta << std::endl;
	ofs.close();
}

