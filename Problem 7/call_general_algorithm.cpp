# include "general_algorithm.hpp"
# include "functions.hpp"

int main()
{
    // Get number of steps from user:
    int m;
    std::cout << "Enter number of steps: ";
    std::cin >> m;
    // Make m intuitive to work with as number of grid points:
    m += 1;
    double h = 1.0 / (m - 1);
    double hh = h * h;

    int n = m - 2;
    
    // Create vectors:
    std::vector<double> a(n - 1, -1);
    std::vector<double> b(n, 2);
    std::vector<double> c(n - 1, -1);
    std::vector<double> g(n);

    // Create vector for the full solution:
    std::vector<double> v_mark(m);
    v_mark[0] = 0;
    v_mark[m - 1] = 0;

    // Fill g:
    std::vector<double> x = linspace(0, 1, m);
    std::vector<double> f = f_eval(x);
    g[0] = f[1] * hh + v_mark[0];
    g[n - 1] = f[n] * hh + v_mark[m - 1];
    for (int i = 1; i < n - 1; i++)
    {
        g[i] = f[i + 1] * hh;
    }

    // Solve equation:
    std::vector<double> v = general_algorithm(a, b, c, g);
    // Fill v_mark:
    for (int i = 1; i < m - 1; i++)
    {
        v_mark[i] = v[i - 1];
    }

    // Write to file:
    std::string filename = "general_algorithm_" + std::to_string(m-1) + "steps.txt";
    write_eval_to_file(x, v_mark, filename);
}