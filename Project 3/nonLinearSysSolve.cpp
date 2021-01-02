/*
Carlos A. Wong
EEE5452 - Modeling and Simulation
Project 3 - Non Linear System Solver
Dr. Petru Andrei
September 28, 2017
*/
#include "toolkit.hpp"

// GLOBAL VARIABLES
const int n = 101;
double eps = 1e-6, Vt = 0.026, ni = 1e10, Na = 1e17, Nd = 2*Na,
    q = 1.6e-19, e = 1e-12, h = 3e-7;

vector <double> x(n,0), x_old(n,0), y(n,0);

// FUNCTION LIST
// J y = F
// A -> J[r, c] | F[r, c+1]
void ComputeF(vector < vector <double>> &F);
void ComputeJ(vector < vector <double>> &J);

int main()
{
    const int epochs = 100;
    double error;
    vector <double> line(n+1, 0);
	vector < vector <double>> AugMatrix(n, line);
	
	// allocate memory x, y, J, F
	
	// Initial Guess vector x[n] set to all zeros.
	
	cout << "Non-Linear System of Equation Solver\n\nProcessing data...\n\n";
	
	for(int i = 0; i < epochs; ++i)
	// Newton Iterations
	{
		ComputeJ(AugMatrix);
		ComputeF(AugMatrix);
		y = solveGauss(AugMatrix);
		
		for(int j = 0; j < n; ++j)
			x[j] -= y[j];
			
		error = norm(y);
		if(error < eps)
		{
			cout << "Processing complete!\nEpoch number: " << i << "\nError: " << error << endl;
			break;
		}
	}
	
	exportdata(x, "proj3out.csv");
	printVec(x, 8);
	return 0;
}
void ComputeF(vector < vector <double>> &F)
{
    double a, b, c;
	F[0][n] = x[0] + Vt*log(Na/ni);
	
	for(int i = 1; i < 100; ++i)
	{
	    a = ((x[i+1] + x[i-1] - 2*x[i])/pow(h,2));
	    b = (q/e)*ni*(exp(x[i]/Vt)-exp(-1*x[i]/Vt));
	    c = (q/e)*(i <= 50 ? -Na : Nd);
		F[i][n] = a - b + c;
	}
	
	F[100][n] = x[100] - Vt*log(Nd/ni);
}
void ComputeJ(vector < vector <double>> &J)
{
	J[0][0] = 1.0;
	
	for(int i = 1; i < 100; ++i)
	{
		// dF[i]/dx[i-1] =
		J[i][i+1] = 1/pow(h,2);
		// dF[i]/dx[i-1] = 
		J[i][i-1] = 1/pow(h,2);
		// dF[i]/dx[i] =
		J[i][i] = -2/pow(h,2) - ((q*ni)/(e*Vt))*(exp(x[i]/Vt)+exp(-1*x[i]/Vt));
	}
	
	J[100][100] = 1.0;
}