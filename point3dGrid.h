#pragma once

#include <fstream>
#include <vector>


class point3dGrid
	
{
public:
	void 	static printFile(const std::string& skinFileName,
		const unsigned long& nx,
		const unsigned long& ny,
		const unsigned long& nz,
		const double& delta,
		const std::vector<std::vector <unsigned long> >& skin);
};


