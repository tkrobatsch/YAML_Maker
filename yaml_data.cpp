#include <iostream>
#include <vector>
#include "MakeYAML.h"


int main(int argc, char** argv) {
	std::vector<double> x, y, ex, ey;
	std::vector<std::string> q;
	double myx, myy, ystat, ysys;

	if (argc != 4) {
		std::cerr << "usage: yaml_data < data_filename yaml_filename x_axis y_axis" << std::endl;
		return 1;
	}

	while (std::cin) {
		std::cin >> myx >> myy >> ystat >> ysys;
		x.push_back(myx);
		y.push_back(myy);
		ex.push_back(ystat);
		ey.push_back(ysys);
	}

	MakeYAML(argv[1], argv[2], argv[3], q, x, y, ex, ey, "symerror", "symerror");

	return 0;
}
