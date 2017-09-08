# Matrix class
1. Create a class “Matrix”
  a. Enable the constructor to allocate memory for an m by n matrix in row major or column major format. 
Store these parameters (m,n,format).
  b. Use C++ templates to allow float or double types to be used
  c. Write functions that report the number of rows and the number of columns in the matrix.
  d. Write a function that sets all the matrix elements to the same number
  e. Create functions to add a row and add a column
2. Add the following operators to your “Matrix” class
  a. Add a += operator that adds a number of type T to each element of the matrix
  b. Add similar -=, *= and /= operators.
  c. Enable access to individual matrix elements with the () operator
  d. Implement the + and - operators to return a matrix that adds or subtracts two different matrices.
  e. Make the << operator print the matrix dimensions, format, as well as the contents of the matrix. 
Show that this works by outputting to an output file stream. 
3. Implement the following functions
  a. Create a function that returns the matrix transpose into a new matrix
  b. Create a function to return the dot product of this matrix and a 2nd matrix. 
Check to make sure the operation is possible (ie correct rows and columns for each matrix). 
Make sure that it works for dot products of matrices with different dimensions.

#ADP90
to calculate the APD of the AP’s simulated by the hRD model.
1. Create a function that will open a file and read a specified column of data
2. Write a function that uses the data read in above to compute the start-to-start time between action 
potentials in milliseconds. This is known as the cycle length and is measured by the time between the 
first peak of each action potential and the next. Output the cycle lengths between action potentials and 
the magnitude of each of the first peaks. Verify that the program is outputting reasonable values.
3. Create a function to find the maximum upstroke velocity dVdtmax and the time at which it occurs for 
each action potential. 
4. Find APD90, or the time between dVdtmax and when the membrane potential has returned to 10% of the 
initial peak that was used to determine cycle length minus the resting potential immediately before 
excitation. 

#Simple math
1. Create a program that prints t vs a*exp(-t/b). The program should ask the user to input how
long t should be and the time increment in addition to the parameters a and b. 
2. Modify your program so that it can print however many exponential functions to a file in
sequential columns as specified by the user. 

#Drug release model
This a model for PLGA drug release based on the paper, Mathematical modeling of PLGA microparticles: 
from polymer degradation to drug release[J]. Molecular pharmaceutics, 2014, 11(11): 4036-4048.
