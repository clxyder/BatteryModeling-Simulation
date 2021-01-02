/*
Carlos A. Wong
EEE5452 - Modeling and Simulation
Dr. Petru Andrei
Project 4: Part A 2
Backward Euler Method
*/
#include "toolkit.hpp"

double func(double t, double c)
{
    return (-1*sqrt(t+1))-2*pow(c,2);
}
double dfunc(double t, double c)
{
    return -1*4*c;
}

int main()
{
    double t=0, x1, x0, f, tau = 1e-1, eps = 1e-6;
    const int epochs = 100, step = 1/tau;
    vector <double> x;
    
    cout << "Backward Euler Solver w/ tau " << tau << endl;
    cout << fixed << setprecision(6);
    
    // Initial value with k = 0
    x.push_back(20);
    
    for(int k = 1; k < step; ++k)
    // iterating throught time steps
    {
        t = k*tau;
        x0 = x[k-1];
        for(int i = 0; i < epochs; ++i)
        // Forward Euler Iterations
        {
            f = func(t, x0);
            x1 = x0 + tau * f;
            if(fabs(x1-x0) > eps)
                break;
            x0 = x1;
        }
        x.push_back(x0 + tau*func(t, x1));
    }
    
    printVec(x, 10);
    exportdata(x, "proj4_PartA_2c.csv");
    
    return 0;
}