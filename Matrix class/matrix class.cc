#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template<class T> class matrix{
    vector < vector <T> > data;
    int rows, cols;
    string majorType;
public:
    matrix (int cols, int rows, string majorType);
    int getrows(){return rows;}
    int getcols(){return cols;}
    //set all the elements in matrix to the same number
    void data_value (double value);
    //add a row or column
    void addrow ();
    void addcol ();
    //matrix transpose
    matrix<T> transpose ();
    //dot products
    T dot (matrix<T>);
    //additional functionality
    T sumofmatrix ();
    //operators +=, -=, /=, *=
    void operator += (T);
    void operator -= (T);
    void operator /= (T);
    void operator *= (T);
    //operator[] and ():assessing elements from Matrix
    vector<T>& operator[](size_t i){return data[i];}
    T& operator()(size_t i, size_t j){return data[j][i];}
    //operator adds or subtracts matrix
    matrix<T> operator + (matrix<T>&);
    matrix<T> operator - (matrix<T>&);
    //operator print the matrix dimensions, format, and the contents of the matrix
    friend ostream& operator << (ostream& out, matrix<T>& mat){
        ostringstream output;
        output << "dimension: " << endl;
        output << "rows: " << mat.getrows() << "\ncolumns: " << mat.getcols() << endl;
        output << "format: column major" << endl;
        for (int i = 0; i < mat.getrows(); i++){
            for (int j = 0; j < mat.getcols(); j++)
            output << mat.data[j][i] << "\t";
	    output << "\r" << endl;
        }
        out << output.str();
        return out;
    }
};
//constructor
template<class T> matrix<T>::matrix (int cols, int rows, string majorType):rows(rows),cols(cols){
    if (majorType == "rows"){
        int temp = cols;
        cols = rows;
        rows = temp;
    }
    data.resize( cols );
    for( auto &q : data ) q.resize( rows );
}
//set all the elements in matrix to the same number
template<class T> void matrix<T>::data_value (double value){
    for (int i = 0; i < (*this).getrows(); i++)
    {
        for ( int j = 0; j < (*this).getcols(); j++ )
            (*this)[j][i] = value;
    }
}
//add a row or column
template<class T> void matrix<T>::addrow(){
    for (unsigned i = 0; i < this->data.size(); i++){
        this->data[i].resize(this->rows + 1);
    }
    this->rows += 1;
}
template<class T> void matrix<T>::addcol(){
    this->data.resize(this->cols + 1);
    this->data[this->cols].resize(this->rows);
    this->cols += 1;
}
//operators +=, -=, /=, *=
template<class T> void matrix<T>::operator += (T addend){
    for (int i = 0; i < (*this).getrows(); i++)
    {
        for ( int j = 0; j < (*this).getcols(); j++ )
            (*this)[j][i] += addend;
    }
}
template<class T> void matrix<T>::operator -= (T addend){
    for (int i = 0; i < (*this).getrows(); i++)
    {
        for ( int j = 0; j < (*this).getcols(); j++ )
            (*this)[j][i] -= addend;
    }
}
template<class T> void matrix<T>::operator /= (T addend){
    for (int i = 0; i < (*this).getrows(); i++)
    {
        for ( int j = 0; j < (*this).getcols(); j++ )
            (*this)[j][i] /= addend;
    }
}
template<class T> void matrix<T>::operator *= (T addend){
    for (int i = 0; i < (*this).getrows(); i++)
    {
        for ( int j = 0; j < (*this).getcols(); j++ )
            (*this)[j][i] *= addend;
    }
}
//operator adds or subtracts matrix
template<class T> matrix<T> matrix<T>::operator + (matrix<T> &M){
    matrix<T> new_matrix(getcols(),getrows(),"cols");
    for (int i = 0; i < new_matrix.getrows(); i++)
    {
        for ( int j = 0; j < new_matrix.getcols(); j++ )
            new_matrix[j][i] = (*this)[j][i] + M[j][i];
    }
    return new_matrix;
}
template<class T> matrix<T> matrix<T>::operator - (matrix<T> &M){
    matrix<T> new_matrix(getcols(),getrows(),"cols");
    for (int i = 0; i < new_matrix.getrows(); i++)
    {
        for ( int j = 0; j < new_matrix.getcols(); j++ )
            new_matrix[j][i] = (*this)[j][i] - M[j][i];
    }
    return new_matrix;
}
//matrix transpose
template<class T> matrix<T> matrix<T>::transpose (){
    matrix<T> matrix_trp((*this).getrows(),(*this).getcols(),"cols");
    for (int i = 0; i < matrix_trp.getrows(); i++)
    {
        for ( int j = 0; j < matrix_trp.getcols(); j++ )
            matrix_trp[j][i] = (*this)[i][j];
    }
    return matrix_trp;
}
//dot products
template<class T> T matrix<T>::dot (matrix<T> M){
    vector<T> M_line, data_line;
    double dproduct;
    for (int i = 0; i < M.getrows(); i++){
        for (int j = 0; j < M.getcols(); j++)
            M_line.push_back(M[j][i]);
    }
    for (int i = 0; i < (*this).getrows(); i++){
        for (int j = 0; j < (*this).getcols(); j++)
            data_line.push_back((*this)[j][i]);
    }
    for (int i = 0; i < data_line.size(); i++)
        dproduct += data_line[i] * M_line[i];
    return dproduct;
}
//additional functionality: summation of a matrix's elements
template<class T> T matrix<T>::sumofmatrix (){
    T s;
    for (int i = 0; i < (*this).getrows(); i++){
        for (int j = 0; j < (*this).getcols(); j++)
            s += (*this)[j][i];
    }
    return s;
}
int main(){
    //initiate matrix by calling constructor
    matrix<double> data(2,3,"cols"), matrix_empty(2,3,"cols"),matrix_empty1(2,3,"cols"),matrix_empty2(2,3,"cols"),new_matrix1(2,3,"cols"),new_matrix2(2,3,"cols"),dot_matrix(2,3,"cols");
    //output data matrix
    cout << "Data matrix: " << endl;
    for (int i = 0; i < data.getrows(); i++)
    {
        for ( int j = 0; j < data.getcols(); j++ )
            cout << data[j][i] << "\t";
            cout << "\r" << endl;
    } cout << endl;
    cout << "Data rows: " << data.getrows() << endl;
    cout << "Data columns: " << data.getcols() << endl;
    //set all the elements to the same number
    data.data_value(10);
    cout << "Set all the elements in data matrix to 10: " << endl;
    for (int i = 0; i < data.getrows(); i++)
    {
        for ( int j = 0; j < data.getcols(); j++)
            cout << data[j][i] << "\t";
            cout << "\r" << endl;
    } cout << endl;
    //add a row
    matrix_empty2.data_value(3);
    matrix_empty2.addrow();
    cout << "Add a row to the matrix_empty2 matrix: " << endl;
    for (int i = 0; i < matrix_empty2.getrows(); i++)
    {
        for ( int j = 0; j < matrix_empty2.getcols(); j++ )
            cout << matrix_empty2[j][i] << "\t" ;
            cout << "\r" << endl;
    } cout << endl;
    matrix_empty1.data_value(3);
    matrix_empty1.addcol();
    cout << "Add a column to the matrix_empty1 matrix: " << endl;
    for (int i = 0; i < matrix_empty1.getrows(); i++)
    {
        for ( int j = 0; j < matrix_empty1.getcols(); j++ )
            cout << matrix_empty1[j][i] << "\t" ;
            cout << "\r" << endl;
    } cout << endl;
    //test operator adds or subtracts matrix
    matrix_empty.data_value(5);
    cout << "New matrix for adding or subtracting: " << endl;
    for (int i = 0; i < matrix_empty.getrows(); i++)
    {
        for ( int j = 0; j < matrix_empty.getcols(); j++ )
            cout << matrix_empty[j][i] << "\t" ;
            cout << "\r" << endl;
    } cout << endl;
    new_matrix1 = data + matrix_empty;
    cout << "Add the two matrices: " << endl;
    for (int i = 0; i < new_matrix1.getrows(); i++)
    {
        for ( int j = 0; j < new_matrix1.getcols(); j++ )
            cout << new_matrix1[j][i] << "\t";
            cout << "\r" << endl;
    } cout << endl;
    new_matrix2 = data - matrix_empty;
    cout << "Subtract the two matrices: " << endl;
    for (int i = 0; i < new_matrix2.getrows(); i++)
    {
        for ( int j = 0; j < new_matrix2.getcols(); j++ )
            cout << new_matrix2[j][i] << "\t";
            cout << "\r" << endl;
    } cout << endl;
    //output data into txt
    ofstream myfile( "result.txt" );
    if( myfile.is_open() )
    {
        myfile << data;
        myfile.close();
    }
    else
        cout << "Can't open the file." << endl;
    //matrix transpose
    double temp = data[1][0];
    data[1][0] = 3;
    cout << "Original matrix: " << endl;
    for (int i = 0; i < data.getrows(); i++)
    {
        for ( int j = 0; j < data.getcols(); j++ )
            cout << data[j][i] << "\t" ;
            cout << "\r" << endl;
    }
    cout << endl;
    matrix<double> matrix_trp = data.transpose();
    cout << "Transposed matrix: " << endl;
    for (int i = 0; i < matrix_trp.getrows(); i++)
    {
        for ( int j = 0; j < matrix_trp.getcols(); j++ )
            cout << matrix_trp[j][i] << "\t" ;
            cout << "\r" << endl;
    }
    cout << endl;
    data[1][0] = temp;
    //dot product
    dot_matrix.data_value(5);
    double dproduct;
    dproduct = data.dot(dot_matrix);
    cout << "Dot product of two matrices: \t" << dproduct << endl;
    //additional functionality
    double sumofmatrix;
    sumofmatrix = data.sumofmatrix();
    cout << "Sum of the two matrices: \t" << sumofmatrix << endl;
}
