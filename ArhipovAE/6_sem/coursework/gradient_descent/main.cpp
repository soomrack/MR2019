#include <iostream>
#include <cmath>

#define pi 3.141592653589793

using namespace std;

typedef double D;

class Model
{
public:
    D *variable;

    Model();
    D Function();
};

Model :: Model()
{
    variable = new D[2];
    // initial guess
    variable[0]= 1.3;
    variable[1]= 1.;
    variable[2]=2.;
}

//Enter a function
D Model :: Function()
{
    return variable[0] * variable[1] + variable[0] * variable[0] + variable[1] * variable[1];
    //return 100 * (sqrt(abs(variable[1] - 0.01 * variable[0] * variable[0]))) +  0.01 * abs(variable[0] + 10);
    //return  -cos(variable[0]) * cos(variable[1]) * exp(variable[0] + variable[1]);
    //return pow(variable[0], 3) + pow(variable[1], 2) - 6*variable[0]*variable[1] - 39*variable[0] +18*variable[1] +20;
    //return 100*(variable[1]-variable[0]*variable[0]) * (variable[1]-variable[0]*variable[0]) + (1-variable[0])*(1-variable[0]);
}

class Optimization : public Model
{
public:
    void implementation_descent();
    void calculate_gradient(const int number_variables, D *gradient, D delta);
};


void Optimization :: calculate_gradient(const int number_variables, D *gradient, D delta)
{
    int variable_counter;
    D function_value_right, function_value_left, module_gradient = 0;

    for(variable_counter = 0; variable_counter < number_variables; variable_counter++)
    {
        variable[variable_counter] += delta;
        function_value_right = Function();
        variable[variable_counter] -= delta;

        variable[variable_counter] -= delta;
        function_value_left = Function();
        variable[variable_counter] += delta;

        gradient[variable_counter] = (function_value_right - function_value_left) / (2 * delta);
        module_gradient += gradient[variable_counter] * gradient[variable_counter];
    }
    module_gradient = sqrt(module_gradient);

    for(variable_counter = 0; variable_counter < number_variables; variable_counter++)
        gradient[variable_counter] /= module_gradient;

    gradient[number_variables] = Function();
}

void Optimization :: implementation_descent()
{
    int variable_counter, number_iterations= 0;
    D function_value, step, eps;
    const int number_variables = 2;
    D *gradient = new D[number_variables + 1];

    step = 0.1;
    eps = 0.0001;

    while(step > eps)
    {
        calculate_gradient(number_variables, gradient, 0.0001);
        for(variable_counter = 0; variable_counter < number_variables; variable_counter++)
            variable[variable_counter] -= step * gradient[variable_counter];

        function_value = Function();
        if(function_value >= gradient[number_variables])
        {
            step /= 2.;
            for(variable_counter = 0; variable_counter < number_variables; variable_counter++)
                variable[variable_counter] += step * gradient[variable_counter];
        }
        number_iterations++;
        cout << number_iterations << " " << variable[0] << "  " << variable[1] << "  " << function_value<< endl;
    }
}


int main()
{
    Optimization fun;
    fun.implementation_descent();
}
