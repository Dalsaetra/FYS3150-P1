# include "functions.hpp"


int main()
{

    std::vector<double> x = linspace(0, 1, 100);
    std::vector<double> u = u_eval(x);
    write_eval_to_file(x, u, "test_output.txt");
    return 0;
}