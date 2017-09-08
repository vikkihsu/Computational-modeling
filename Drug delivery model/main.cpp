#include "matrix.h"
#include "final.h"
#include<iostream>
#include<fstream>
#include<cmath>
#include<functional>
#include<vector>
using namespace std;

int main()
{
	cout << "Type the number to get corresponding outputs:" << endl;
	cout << "1 for degradation (generator 1);" << endl;
	cout << "2 for degradation (generator 2);" << endl;
	cout << "3 for weight changes;" << endl;
	cout << "4 for drug release;" << endl;
	cout << "> ";
	int ans;
	cin >> ans;
	cout << "Type the maximum length for a chain: " << endl << "> ";
	int length;
	cin >> length;
	cout << "Type the size of a particle: " << endl << ">";
	double radius;
	cin >> radius;
	cout << "Type the pH for the environment: " << endl << ">";
	double pH;
	cin >> pH;


	switch(ans){
		case 1:
			degradation1( length );
			break;
		case 2:
		    degradation2( length );
			break;
        case 3:
			weight( radius);
			break;
        case 4:
            drugrelease( radius );
	}

	return 0;
}
