#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void writetofile( string context )
{
    ofstream myfile( "result.txt" );
    if( myfile.is_open() )
    {
        myfile << context;
        myfile.close();
    }
    else
        cout << "Can't open the file." << endl;
}

int main(){
    //output column a or b
    ifstream file ("HRdOutput2.txt");
    vector<double> A, B;//A is time, B is potential
    if (file.is_open())
    {
        cout << "Potential: " << endl;//cout << "Time: " << endl;
        while(!file.eof()){
                double a, b;
            file >> a >> b;
            A.push_back(a);
            B.push_back(b);
            //cout << b << endl; //a can be switched to b to output column b
            //cout << a << endl;
        }
    }
    string context;
    double t;
        for (int i = 0; i < A.size(); i++){
            context += to_string(A[i]);
            context += "\n";
        }
    writetofile(context);
}



