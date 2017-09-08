#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

// calculate the result for all t
vector<double> createexp( double a, double b, double t, double dt )
{
    vector<double> result;
    for( double i = 0; i <= t; i += dt)
        result.push_back( a*exp(-i/b) );

    return result;
}

// write to a file
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

int main()
{
    //double t = 1, dt = 0.5;
    //vector<double> a(3); a[0] = 1; a[1] = 2; a[2] = 3;
    //vector<double> b(a);
    double t, dt, cols;
    cout << "Length of t: ";
    cin >> t;
    cout << "Increment of t: ";
    cin >> dt;
    cout << "Number of columns(pairs of a and b): ";
    cin >> cols;
    vector<double> a(cols), b(cols);
    cout << "Enter all of the a:" << endl;
    for( int i = 0; i < cols; ++i )
        cin >> a[i];
    cin.clear();
    cout << "Enter all of the b:" << endl;
    for( int i = 0; i < cols; ++i )
        cin >> b[i];

    // calculate the function results
    vector< vector<double> > result( a.size(), vector<double>(t/dt + 1, 0) );
    for( int i = 0; i < a.size(); ++i )
        result[i] = createexp(a[i], b[i], t, dt);

    // write to the file
    string context;
    double t1;
    for( int i = 0; i < t/dt + 1; ++i )
    {
        context += to_string(t1).substr(0,3);
        for( int cols = 0; cols < a.size(); ++cols )
            context += "\t" + to_string(result[cols][i]).substr(0,5);
        context += "\n";
        t1 += dt;
    }
    writetofile( context );
    return 0;
}

