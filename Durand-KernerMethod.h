#include <complex>
#include <vector>
#include <algorithm>

class Solver
{
private:
    std::vector<std::complex<double>> roots;
    std::vector<std::complex<double>> deltaRoots;
    std::vector<double> multipliers;
    std::vector<double> degrees;
    std::complex<double> p0;

    std::complex<double> eval(std::complex<double> x);
    void step();
    double norm(std::vector<std::complex<double>> v);

public:
    Solver(std::vector<double> m, std::vector<double> d);
    std::vector<std::complex<double>> solve(double eps);
};