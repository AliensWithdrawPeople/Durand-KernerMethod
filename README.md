# Durand-KernerMethod
C++ implementation of Durand-Kerner root-finding algorithm

Example:
// m -- multipliers
std::vector<double> m = {1., 5, -7.};
// d -- degrees of x
std::vector<double> d = {2., 1., 0.};
Solver s(m, d);
// eps = 0.01 -- precision 
std::vector<double> roots = s.solve(0.01);
