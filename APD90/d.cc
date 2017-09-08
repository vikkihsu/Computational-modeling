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
    for (double i = 1; i <= row; i++){
        if (B[i+1] < B[i] && B[i] > B[i-1]){
            apeak.push_back(A[i]);
            bpeak.push_back(B[i]);
            app.push_back(i);
        }
    }
    for (int i = 0; i < bpeak.size(); i++)
        clength.push_back(apeak[i] - apeak[i+1]);

    //find the dvdt max and its corresponding time
    vector<double>dv, dvdt, dvdt_max, Avt, Avt_max;
    for (int i = 1; i <= row; i++)
        dv.push_back((B[i]-B[i-1])/(A[i]-A[i-1]));
    for (int i = 0; i < dv.size(); i++){
        if (dv[i] > dv[i+1] && dv[i] > dv[i-1]){
            dvdt.push_back(dv[i]);
            Avt.push_back(A[i]);
            }
        }
    for (int i = 0; i < dvdt.size(); i++){
        if (dvdt[i-1] < dvdt[i] && dvdt[i] > dvdt[i+1] && dvdt[i] > 0){
            dvdt_max.push_back(dvdt[i]);
            Avt_max.push_back(Avt[i]);
        }
    }

    //find ADP90
    vector<double>ip_ten, A_ten;
    //ip_ten: 10% of initial peak; A_ten: time of ip_ten
    for (int i = 0; i < bpeak.size(); i+=2){
        for (int j = app[i]+1; j < B.size(); j++){
            if (0.1*bpeak[i] > (B[j-1]+B[j+1])/2){
            ip_ten.push_back(B[j]);
            A_ten.push_back(A[j]);
            j = B.size();
            }
        }
    }
    cout << "ADP90: " << endl;
    for (int i = 0; i < ip_ten.size(); i++){
        //cout << ip_ten[i] << endl;
        cout << Avt_max[i] - A_ten[i] << endl;
    }
}
