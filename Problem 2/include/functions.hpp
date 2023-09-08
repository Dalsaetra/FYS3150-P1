// Include guard:
# ifndef __utils_hpp__  
# define __utils_hpp__

# include <vector>
# include <iostream>
# include <cmath>
# include <fstream>
# include <string>
# include <iomanip>

// Function declarations:

// linspace: returns a vector of n evenly spaced numbers between start and end.
std::vector<double> linspace(double start, double end, int n);

// u: analytical solution to our specific problem.
float u(float x);

// u_eval: returns a vector of the analytical solution evaluated at points x.
std::vector<double> u_eval(std::vector<double> x);

// write_eval_to_file: writes the vectors x and u to a file of name filename.
void write_eval_to_file(std::vector<double> x, std::vector<double> u, std::string filename);

// End of include guard:
# endif // __utils_hpp__