#include "matrix.h"
#include<cmath>
#include<functional>
#include<vector>
using namespace std;

#define k_cds 5.635e-5
#define C_lims 2.791e-5
#define D0s 3.972e-14
#define C_initials 3.77e-5
#define k_cdl 4.682e-5
#define C_liml 2.791e-5
#define D0l 1.324e-12
#define C_initiall 3.7e-5

void drugrelease( double radius )
{
	double r2 = radius * radius, r3 = radius * radius * radius;
	double n;
	vector<double> t, C_load, C_solv, drug_release;
	for (int i = 0; i < 80; i++) t.push_back(i);

	if ( (radius < 30) & (radius > 7) ){
        for (int i = 0; i < 80; i++){
            n = (k_cds * C_lims * r2)/(r2 + k_cds - t[i]*D0s);
            C_solv.push_back(n);
        }
        for (int i = 0; i < 80; i++){
            n = k_cds * t[i] * (C_lims - C_solv[i]);
            C_load.push_back(n);
        }
        for (int i = 0; i < 80; i++){
            n = (C_load[i] * r3 + C_solv[i] * r3) / (C_initials * r3);
            drug_release.push_back(100 - n * 100);
        }
	}
	else if ( (radius > 30) & (radius < 55) ){
        for (int i = 0; i < 80; i++){
            C_solv.push_back((k_cdl * C_liml * r2)/(r2 + k_cdl - t[i]*D0l));
        }
        for (int i = 0; i < 80; i++){
            n = k_cdl * t[i] * (C_liml - C_solv[i]);
            C_load.push_back(n);
        }
        for (int i = 0; i < 80; i++){
            n = (C_load[i] * r3 + C_solv[i] * r3) / (C_initiall * r3);
            drug_release.push_back(100 - n * 100);
        }
	}

	cout << "C_load: " << endl;
	for (int i = 0; i < 80; i++){
        cout << C_load[i] << endl;
	}cout << endl;

	cout << "C_solv: " << endl;
	for (int i = 0; i < 80; i++){
        cout << C_solv[i] << endl;
	}cout << endl;

	cout << "Drug release: " << endl;
	for (int i = 0; i < 80; i++){
        cout << drug_release[i] << endl;
	}cout << endl;

	//write to file
	cout << "Column1 is drug release, column2 is concentration of dissolving, column3 is concentration of drug-loaded particles." << endl;
    ofstream file;
    	file.open("drug_release.txt");
    	for( size_t i = 0; i < C_load.size(); ++i ){
        	file << drug_release[i] << "\t" << C_solv[i] << "\t" << C_load[i] << endl;
    	}
    	file.close();
}
