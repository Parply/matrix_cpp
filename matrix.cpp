#include "matrix.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<double>> foo;
	foo = {{5.0,5.0},{3.0,2.0}};
	matrix<double> m(foo);
	//m.transpose();
	cout << m[0][1] << endl;

	

	return 0;
}
