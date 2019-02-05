#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>
#include "MakeYAML.h"


int main() {
	std::vector<double> x, y, ex, ey;
	std::vector<std::string> q;

	srand(time(NULL));

	q.push_back("Well this is a thing");
	q.push_back("Science!");

	for (int i = 0; i < 5; i++) {
		x.push_back(rand());
		y.push_back(x[i] * i);
		ex.push_back(rand());
		ey.push_back(rand());
	}

	MakeYAML("junk.yaml", "X title", "Y title", q, x, y, ex, ey, "x err label", "y err label");
}