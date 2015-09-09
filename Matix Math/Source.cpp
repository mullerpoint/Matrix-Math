//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gary Muller
// Fall 2015
// MA 225 Assignment 2
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//A program to allow a user to input matricies and perform math functions on them
//utilizes a menu commandline interface to allow the user to input the matricies
//and choose a function to perform on them before outputting the result
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files - Standard libraries and classes
#ifndef CORE_DEPENDENCIES_H_
#include <iostream> //default include for functionality
#include <string> //get working string functionality
#include <iomanip> //included to make pretty output
#include <vector> //use vector functionality
#include <boost/numeric/ublas/matrix.hpp> //boost matrix library
#include <boost/numeric/ublas/io.hpp> //boost matrix I/O library
#include <fstream> //testing
#include <sstream> //testing
#include <algorithm> //testing
#include <boost/numeric/ublas/operation.hpp> //testing
#endif


//Global variables and defines
using namespace boost::numeric;
//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	//introduce program to user
		std::cout << std::endl <<
			"///////////////////////////////////////////" << std::endl <<
			"// Matrix Multiplication Program         //" << std::endl <<
			"// Written By Gary Muller                //" << std::endl <<
			"// Written For MA225 Fall 2015           //" << std::endl <<
			"///////////////////////////////////////////" << std::endl << std::endl;

	//query user for input
		int rows1, rows2, columns1, columns2; //rows and columns for the matricies 1 and 2

		//matrix 1
			std::cout << "Please enter the first Matrix Dimensions: " << std::endl << "Rows: ";
			std::cin >> rows1;
			std::cout << "Columns: ";
			std::cin >> columns1;

		//matrix 2
			std::cout << std::endl << "Please enter the second Matrix Dimensions: " << std::endl << "Rows: ";
			std::cin >> rows2;
			std::cout << "Columns: ";
			std::cin >> columns2;

		//create matricies if sizes are compatible otherwise end program
			if (columns1 != rows2)
			{
				std::cout << "These dimesions cannot be multiplied please start program again and enter compatible dimesions" << std::endl;
			}
			else
			{
				ublas::matrix<double> matrix1(rows1, columns1);
				ublas::matrix<double> matrix2(rows2, columns2);

				//provide context for matrix entry
				std::cout << std::endl << "Enter the number located at each row,column combination:" << std::endl;
				int row;
				int column;

				//matrix1 data entry
				std::cout << "Matrix 1: " << std::endl;
				for (row = 0; row < rows1; row++)
				{
					for (column = 0; column < columns1; column++){
						std::cout << '(' << row + 1 << ',' << column + 1 << ") ";
						std::cin >> matrix1(row, column);
					}
				}

				//matrix2 data entry
				std::cout << std::endl << "Matrix 2: " << std::endl;
				for (row = 0; row < rows2; row++)
				{
					for (column = 0; column < columns2; column++){
						std::cout << '(' << row + 1 << ',' << column + 1 << ") ";
						std::cin >> matrix2(row, column);
					}
				}



				//perform calculation
					ublas::matrix<double> ans_matrix(columns1, rows2); //create appropriatly sized answer matrix

					ans_matrix = ublas::prod(matrix1, matrix2);


				//output results	
					std::cout << std::endl << std::endl << "The answer matrix is a " << rows1 << 'x' << columns2 << " matrix with the contents: " << std::endl <<
						ans_matrix << std::endl << std::endl;

			}//else
}//main