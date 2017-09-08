#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    //output column a or b
    ifstream file ("HRdOutput2.txt");
    vector<double> A, B;//A is time, B is potential
    if (file.is_open())
    {
        while(!file.eof()){
                double a, b;
            file >> a >> b;
            A.push_back(a);
            B.push_back(b);
        }
    }
    int row = A.size();
    //find the peak potentials and calculate the cycle length
    vector<double>apeak, clength, app, bpeak;
    //apeak: time peak; bpeak: potential peak; clength: cycle length; app: apeak's position
    for (double i = 1; i <= row; i++){
        if (B[i+1] < B[i] && B[i] > B[i-1]){
            apeak.push_back(A[i]);
            bpeak.push_back(B[i]);
            app.push_back(i);
        }
    }
    cout << "Cycle length: " << endl;
    for (int i = 0; i < bpeak.size(); i++){
        clength.push_back(apeak[i] - apeak[i+1]);
        cout << clength[i] << endl;
    }
    cout << "First peak's magnitude: " << endl;
    for (int i = 0; i < bpeak.size(); i+=2)
        cout << bpeak[i] << endl;
}
