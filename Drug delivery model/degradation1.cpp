#include<iostream>
#include<cmath>
#include<functional>
#include<vector>
#include"matrix.h"
using namespace std;

void degradation1(int l){
    //set the number for original long chains
    //int l = 70;
    cout << "Length of chains: " << l << endl;
    matrix<double> mat(5,5,"");
    matrix<double> mat1(mat.getRows(), mat.getCols(), "");
    for (int i = 0; i < mat.getRows(); i++){
        for (int j = 0; j < mat.getCols(); j++){
            unsigned seed = static_cast<int> (chrono::system_clock::now().time_since_epoch().count());
            mt19937 generator(seed);
            uniform_int_distribution<int> dist( 20, l );
            auto r = bind( dist, generator );
            mat[i][j] = r();
            //mat[i][j] = 20 + rand()%(l-20);
        }
    }
    cout << "mat: " << endl;
    mat.out_matrix();

    //set the random number of polymer chains
    matrix<double> poly(mat.getRows(), mat.getCols(), ""), poly_num(mat.getRows(), mat.getCols(), "");
    int n, m, mm;
    for(int i = 0; i < mat.getRows(); i++){
        for (int j = 0; j < mat.getCols(); j++){
            //poly[i][j] = 1 + rand()%(n-1);
            for(int t = 0; t < poly[i][j]; t++){
                m = floor((mat[i][j] - 1)/poly[i][j]);
                unsigned seed = static_cast<int> (chrono::system_clock::now().time_since_epoch().count());
                mt19937 generator(seed);
                uniform_int_distribution<int> dist( 10, m);
                auto r = bind( dist, generator );
                mm = r();
                poly_num[i][j] += mm;
                //poly_num[i][j] += 10 + rand()%(m-10);
            }
        }
    }
    cout << "poly: " << endl;
    poly.out_matrix();
    cout << "poly_num: " << endl;
    poly_num.out_matrix();

    //set the random number of diffusing oligomer
    matrix<double> dif(mat.getRows(), mat.getCols(), ""), dif_num(mat.getRows(), mat.getCols(), "");
    dif = mat - poly_num;
    for (int i = 0; i < dif.getRows(); i++){
        for (int j = 0; j < dif.getCols(); j++){
            if (dif[i][j] == 1)
                dif[i][j] = 0;
            else if (dif[i][j] > 1){
                unsigned seed = static_cast<int> (chrono::system_clock::now().time_since_epoch().count());
                mt19937 generator(seed);
                uniform_int_distribution<int> dist( 1, floor(dif[i][j]/2));
                auto r = bind( dist, generator );
                n = r();
                //nn = floor(dif[i][j]/2);
                //n = 1 + rand()%(nn-1);
                for (int t = 0; t < n; t++){
                    unsigned seed = static_cast<int> (chrono::system_clock::now().time_since_epoch().count());
                    mt19937 generator(seed);
                    uniform_int_distribution<int> dist( 2, floor(dif[i][j]-1/m));
                    auto r = bind( dist, generator );
                    m = r();
                    dif_num[i][j] += m;
                    //mm = floor(dif[i][j]-1/m);
                    //dif_num[i][j] += 2 +rand()%(mm-2);
                }
                dif[i][j] = n;
            }
        }
    }
    cout << "dif: " << endl;
    dif.out_matrix();
    cout << "dif_num: " << endl;
    dif_num.out_matrix();

    //set the number of monomer
    matrix<double> mono(mat.getRows(), mat.getCols(), "");
    mono = mat - poly_num - dif_num;
    cout << "mono: " << endl;
    mono.out_matrix();

    //write to file
    cout << "Column1 is poly_num, column2 is dif_num, column3 is mono, column4 is mat, column5 is poly, column6 is dif" << endl;
    ofstream file;
    	file.open("degradation1.txt");
    	for( int i = 0; i < mat.getRows(); ++i ){
            for (int j = 0; j < mat.getCols(); j++){
                file << poly_num[i][j] << "\t" << dif_num[i][j] << "\t" << mono[i][j] << "\t" << mat[i][j] << "\t" << poly[i][j] << "\t" << dif[i][j] << endl;
            }
    	}
    	file.close();
}

/*set the longest chain to be 70, and the original matrix's size is 5x5. then use then random function to set the number
in original matrix randomly, so each element in the matrix should be different. Then set a limit of [1,floor(mat[i][j]/10)]
for generating random number of polymer chains, and for each chain, generate a random length with a limit
[10,floor((mat[i][j]-1)/nn)]. Adding all the chain together output as poly_num, minus it with mat, and in the rest length,
generate random number of diffusing oligomers, with a limit for number of chain as [1,floor(dif[i][j]/2)], and for each chain,
generate random length in the limit of [2,floor(dif[i][j]-1/m)], adding all the chain together and output as dif_num.
Using mat to minus dif_num and poly_num, the rest are monomers, which have 1 length in each chain only.*/

/*try two methods of random function. mt19337will generate different number each time, but all the elements in the matrix are
the same, and when it comes to the random number generating in the for-loop in another for-loop, it will stop generate new number.
the rand() one will generate different number of elements, but it generates the same number each time running the program.
another problem for it is the same as the mt19337 one.*/

/*to be solved:
random generation in the for-loop in for-loop;
equation.cpp for diffusing and drug delivery;(equations and parameters are known already)
make this as a degradation.cpp;
add pH limit for the degradation and maybe diffusing and drug delivery.*/
