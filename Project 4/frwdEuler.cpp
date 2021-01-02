/*
Carlos A. Wong
EEE5452 - Modeling and Simulation
Dr. Petru Andrei
Project 4: Part A 1
Forward Euler Method
*/
#include "toolkit.hpp"

double f(double t, double c)
{
    return (-1*sqrt(t+1))-2*pow(c,2);
}

int main()
{
    double tau = 1e-3;
    int step = 1/tau;
    vector <double> x;
    
    cout << "Forward Euler Solver w/ tau " << tau << endl;
    
    // Initial value with k = 0
    x.push_back(20.0);
    for(int k = 1; k < step; ++k)
    {
        x.push_back(x[k-1] + (tau*f(k*tau, x[k-1])));
    }
    
    printVec(x);
    exportdata(x, "proj4_PartA_1a.csv");
    
    return 0;
}