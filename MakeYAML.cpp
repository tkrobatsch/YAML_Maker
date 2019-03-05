#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MakeYAML.h"

void MakeYAML(std::string file_name, std::string x_header, std::string y_header, std::vector<std::string>qualifiers, std::vector<double>x, std::vector<double>y, std::vector<double>ex, std::vector<double>ey, std::string xerr_label, std::string yerr_label) {
	std::ofstream fout;
	fout.open(file_name.c_str());
	if (fout.is_open()) {
		//print dependent values
		if (!y.empty()) {
			fout << "dependent_variables:" << std::endl;
			fout << "- header: {name: " << y_header << "}" << std::endl;
			//print qualifers
			if (!qualifiers.empty()) {
				fout << "  qualifiers:" << std::endl;
				for (int i = 0; i < qualifiers.size(); i++) {
					fout << "  - {name: " << qualifiers[i] << "}" << std::endl;
				}
			}
			fout << "  values:" << std::endl;
			for (int i = 0; i < y.size(); i++) {
				fout << "  - value: " << y[i] << std::endl;
				fout << "    errors:  " << std::endl;
				if (!ey.size()) { fout << "    - {" << xerr_label << ": " << ex[i] << ", label: 'stat'}"; }
				if (!ey.size()) { fout << "    - {" << yerr_label << ": " << ey[i] << ", label: 'sys'}" << std::endl; }
			}
		}

		//print independent values
		if (!x.empty()) {
			fout << "independent_variables:" << std::endl;
			fout << "- header: {name: " << x_header << "}" << std::endl;
			fout << "  values:" << std::endl;
			for (int i = 0; i < x.size(); i++) {
				fout << "  - {value: " << x[i] << "}" << std::endl;
			}
		}

		fout.close();
	}
	else std::cout << "Unable to open file";
}
