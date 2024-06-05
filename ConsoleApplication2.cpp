// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

void display(vector<vector<double>> V1, int Nx)
{ 
	for (int i = 0; i < Nx; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			cout << V1[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{   
	int Nx;
	cout << "enter the number of nodes Nx=";
	//Nx = 5;
	cin >> Nx;
	vector<vector <double>> Grid_XY;
	vector<vector<double>> A;
	vector<double> b;
	vector<double> sol_new, sol_old;
	// solution Grid
	for (int i = 0; i <= Nx; i++)
	{   
		Grid_XY.push_back({});
		for (int j = 0; j <= Nx; j++)
		{
			Grid_XY[i].push_back({0});
		}
	}
	// Let's put the boundary conditions

	for (int j = 1; j < Nx-1; j++)
	{
		Grid_XY[0][j] = 1;
		Grid_XY[Nx-1][j] = 1;
	}

	for (int i = 0; i < pow(Nx - 2,2); i++)
	{
		A.push_back({});
		for (int j = 0; j < pow(Nx - 2, 2); j++)
		{
			A[i].push_back({ 0 });
		}
	}

	for (int i = 0; i < pow(Nx - 2, 2); i++)
	{
		if (i < Nx - 2 || i > pow(Nx - 2, 2) - Nx+1)
			b.push_back(1);
		else
			b.push_back(0);
		cout << b[i] << " ";
	}

	cout << endl;
	for(int i = 0 ;  i < pow(Nx - 2, 2); i++)
	{
		for (int j = 0;  j < pow(Nx - 2, 2); j++)
		{
			if (i == j)
				A[i][j] = -4;
			
		}
	}
	int col = Nx-1;
	for (int i = 0; i < pow(Nx - 2, 2)-(Nx-2); i++)
	{
			A[i][col-1] = 1;
			A[col - 1][i] = 1;
			col++;	
	}
	 col = 1;
	for (int i = 0; i < pow(Nx - 2, 2) - 1; i++)
	{  
		if ((i + 1) % (Nx - 2) != 0)
		{
			A[i][col] = 1;
			A[col][i] = 1;
		}
		  col++;
	}
	

	cout << "Solution Domain of the Laplace Equation : "<<endl;
	display(Grid_XY, Nx);
	cout << endl;

	cout << " the mastrix needed for computing the solution: "<<endl;
	display(A, pow(Nx - 2, 2));


	//now use gauss jacobi method to solve the matrix and allot the values 



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
