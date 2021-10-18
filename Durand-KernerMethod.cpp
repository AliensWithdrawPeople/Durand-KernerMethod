#include "Durand-KernerMethod.h"

std::complex<double> Solver::eval(std::complex<double> x)
{
    using namespace std::literals::complex_literals;
    std::complex<double> res = 0;
    for (int i = 0; i < multipliers.size() && i < degrees.size(); i++)
    { res += multipliers[i] * pow(x, degrees[i]); }
    return res;
}

void Solver::step()
{
    using namespace std::literals::complex_literals;
    std::complex<double> polyEval = 0;
    for(int i = 0; i < roots.size(); i++)
    {
        polyEval = eval(roots[i]);
        for(int j = 0; j < roots.size(); j++)
        { 
            if(j != i) 
            { polyEval = polyEval / (roots[i] - roots[j]); }
        }
        deltaRoots[i] = polyEval;  
        roots[i] -= polyEval;
    }
}

double Solver::norm(std::vector<std::complex<double>> v)
{
    using namespace std::literals::complex_literals;
    double norm2 = 0;
    for (auto a : v)
    { norm2 += std::norm(a); }
    return norm2;
}

Solver::Solver(std::vector<double> m, std::vector<double> d)
{
    using namespace std::literals::complex_literals;
    p0 = 0.4 + 0.9i;
    multipliers = m;
    degrees = d;
    double maxMult = multipliers[std::distance(degrees.begin(), std::max_element(degrees.begin(), degrees.end()))];
    for (int i = 0; i < multipliers.size(); i++)
    { multipliers[i] /= maxMult; }

    for (int i = 0; i < *std::max_element(degrees.begin(), degrees.end()); i++)
    {
        roots.push_back(pow(p0, i));
        deltaRoots.push_back(0);
    }
}

std::vector<std::complex<double>> Solver::solve(double eps)
{
    using namespace std::literals::complex_literals;
    do
    { step(); } 
    while (norm(deltaRoots) > eps);
    return roots;
}