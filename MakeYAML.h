#pragma once

void MakeYAML(std::string file_name, 
	std::string x_header, std::string y_header, std::vector<std::string>qualifiers,
	std::vector<double>x, std::vector<double>y, std::vector<double>ex, std::vector<double>ey, 
	std::string xerr_label, std::string yerr_label);