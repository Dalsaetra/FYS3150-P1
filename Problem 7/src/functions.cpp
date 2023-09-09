# include "functions.hpp"

std::vector<double> linspace(double start, double end, int n)
{
    std::vector<double> vec(n);
    double h = (end - start) / (n - 1);
    for (int i = 0; i < n; i++)
    {
        vec[i] = start + i * h;
    }
    return vec;
}

float f(float x)
{
    return 100 * std::exp(-10 * x);
}

std::vector<double> f_eval(std::vector<double> x)
{
    std::vector<double> vec(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        vec[i] = f(x[i]);
    }
    return vec;
}

void write_eval_to_file(std::vector<double> x, std::vector<double> u, std::string filename)
{
    std::ofstream file;
    file.open(filename);

    int width = 14;
    int prec = 5;
    for (int i = 0; i < x.size(); i++)
    {
        file << std::setw(width) << std::setprecision(prec) << std::scientific << x[i] << " " 
        << std::setw(width) << std::setprecision(prec) << std::scientific << u[i] << "\n";
    }
    file.close();
}
