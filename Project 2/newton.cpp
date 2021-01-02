/*
Title:      Newton-Raphson Root Calculator
Name:       Carlos A. Wong
Course:     EEE5452
Due Date:   09/07/17

*/
#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
	//return 2x - e^(-x) + 2;
	return 3*exp(3*x)-exp(-1*pow(x,3)*log(3))+(1/3.0);
}
double dfunc(double x)
{
	//return 2 + e^(-x);
	return 9*(exp(3*x)+pow(x, 2)*exp(-pow(x,3)));
}
int main()
{
    const int max = 30;
    bool zflag = false;
	double f, df, t, x0, eps = 1e-6;
	int count = 0;
	
	cout << "Welcome to the Newton-Raphson Root Calculator!\nPlease insert an initial guess:\nx0: ";
	cin >> x0;
	do
	{
	    f = func(x0);
	    df = dfunc(x0);
		if(df == 0)
		{
		    zflag = true;
		    break;
		}
		t = f/df;
		x0 -= t;
		count++;
	}while(fabs(t) > eps && count < max); // |f(x0)| > eps
	
	if(zflag == true)
	    cout << "Calculation was aborted! Cannot divide by zero.\n";
	if(count == max)
		cout << "Maximum iteration reached, could not converge.\n";
	
	cout << "The root value: " << x0 << " +- " << eps << endl
	<< "Number of iterations: " << count << endl;
}
