# include "general_algorithm.hpp"

// General algorithm:

// General algorithm for solving a tridiagonal matrix equation:
std::vector<double> general_algorithm(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> g)
{
    int n = b.size();
    std::vector<double> b_t(n);
    std::vector<double> g_t(n);
    std::vector<double> v(n);

    // Forward substitution:
    b_t[0] = b[0];
    g_t[0] = g[0];
    for (int i = 1; i < n; i++)
    {
        double ab = a[i] / b_t[i - 1];
        b_t[i] = b[i] - ab * c[i - 1];
        g_t[i] = g[i] - ab * g_t[i - 1];
    }

    // Backward substitution:
    v[n - 1] = g_t[n - 1] / b_t[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        v[i] = (g_t[i] - c[i] * v[i + 1]) / b_t[i];
    }

    return v;
}