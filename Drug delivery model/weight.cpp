#include "matrix.h"
#include<cmath>
#include<functional>
#include<vector>
using namespace std;

#define MW0_fs 29310
#define MW0_ds 31830
#define kdeg_fs 1.386e-6
#define kdeg_ds 2.125e-6
#define MW0_fl 29050
#define MW0_dl 32440
#define kdeg_fl 1.673e-6
#define kdeg_dl 3.287e-6

void weight( double radius)
{
	vector<double> t;
	for (int i = 0; i < 80; i++) t.push_back(i);

	vector<double> wFO_f, wFO_d;
    if( (radius < 30) & (radius > 7) ){
        for (size_t i = 0; i < t.size(); i++){
        wFO_f.push_back(MW0_fs * exp(-kdeg_fs * t[i]));
        cout << wFO_f[i] << " ";
        } cout << endl;
        for (size_t i = 0; i < t.size(); i++){
        wFO_d.push_back(MW0_ds * exp(-kdeg_ds * t[i]));
        cout << wFO_d[i] << " ";
        } cout << endl;
    }
    else if ( (radius > 30) & (radius < 55) ){
        for (size_t i = 0; i < t.size(); i++){
        wFO_f.push_back(MW0_fl * exp(-kdeg_fl * t[i]));
        cout << wFO_f[i] << " ";
        } cout << endl;
        for (size_t i = 0; i < t.size(); i++){
        wFO_d.push_back(MW0_dl * exp(-kdeg_dl * t[i]));
        cout << wFO_d[i] << " ";
        } cout << endl;
    }

    //write to file
    cout << "Column1 is weight of drug-loaded particles, column2 is weight of drug-free particles." << endl;
    ofstream file;
    	file.open("weight.txt");
    	for( size_t i = 0; i < wFO_d.size(); ++i ){
        	file << wFO_d[i] << "\t" << wFO_f[i] << endl;
    	}
    	file.close();
}
