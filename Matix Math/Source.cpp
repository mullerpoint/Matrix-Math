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
#endif

//Global variables and defines
#define TEXT_WIDTH 20
bool done = false;
using namespace boost::numeric;
std::vector<ublas::matrix<double>*>Matricies;
//

//Function Prototypes
void process_menu_in(char);
void print_menu();
void print_matricies(); 
void push_answer(ublas::matrix<double>*);
bool check_matrcies(ublas::matrix<double>*);
//


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	//Initialize variables
	std::string menu_in;
	print_menu();

	//while loop for main functionality 
	while (!done)
	{
		std::getline(std::cin, menu_in);
		process_menu_in(menu_in[0]);
	}

}

void process_menu_in(char inchar)
{
	switch (toupper(inchar))
	{

		//add a matrix
	case 'A':
	{
		//create local variables 
		int rows, columns;
		ublas::matrix<double>* temp_ptr;

		//query user for input
		std::cout << "What size matrix do you want to add:" << std::endl << "Rows: ";
		std::cin >> rows;
		std::cout << std::endl << "Columns: ";
		std::cin >> columns;

		//create matrix
		temp_ptr = new ublas::matrix<double>(rows, columns);

		bool check = check_matrcies(temp_ptr);

		if (check)
		{
			Matricies.push_back(temp_ptr);
		}
		else
		{
			std::cout << "the first matix entered has " << (*(Matricies[0])).size1() << " rows, the second matrix entered has " << (*temp_ptr).size2()
				<< " columns, making them incompatible please re-add a compatible matrix";
		}

	}
	break;

	//fill in the matrix
	case 'F':
	{
		//code to fill the matrix
		std::cout << "matrix filler called" << std::endl;
	}

	//add matricies
	case '+':
	{
		if (Matricies.size() >= 1)
		{
			ublas::matrix<double> temp_matrix;

			temp_matrix = *(Matricies[0]) + *(Matricies[1]);

			push_answer(&temp_matrix);

		}
		else
		{
			std::cout << "ERR: Not Enough matricies entered" << std::endl;
		}
	}
	break;

	//subtract matricies
	case '-':
	{
		if (Matricies.size() >= 1)
		{
			ublas::matrix<double> temp_matrix;

			temp_matrix = *(Matricies[0]) - *(Matricies[1]);

			push_answer(&temp_matrix);

		}
		else
		{
			std::cout << "ERR: Not Enough matricies entered" << std::endl;
		}
	}
	break;

	//multiply matricies
	case '*':
	{
		if (Matricies.size() >= 1)
		{
			ublas::matrix<double> temp_matrix;

			//temp_matrix = (*(Matricies[0])) * (*(Matricies[1]));

			push_answer(&temp_matrix);

		}
		else
		{
			std::cout << "ERR: Not Enough matricies entered" << std::endl;
		}
	}
	break;

	//divide matricies
	case '/':
	{
		if (Matricies.size() >= 1)
		{
			ublas::matrix<double> temp_matrix;

			temp_matrix = *(Matricies[0]) / *(Matricies[1]);

			push_answer(&temp_matrix);

		}
		else
		{
			std::cout << "ERR: Not Enough matricies entered" << std::endl;
		}
	}
	break;

	//print the menu again
	case 'M':
	{
		print_menu();
	}
	break;

	//quit program
	case 'Q':
		done = true;
		break;

	default:
		break;
	}

	return;
}



void print_menu()
{
	std::cout << std::endl
		<< "A -> Add a matrix object" << std::endl
		<< "F -> Fill a Matrix" << std::endl
		<< "M -> Print this menu again" << std::endl
		<< "+ -> Add the two entered matricies" << std::endl
		<< "- -> Subtract the two entered matricies" << std::endl
		<< "* -> Multiply the two entered matricies" << std::endl
		<< "/ -> Divide the two entered matricies" << std::endl
		<< "Q -> Quit the program" << std::endl << std::endl;
	return;
}

void push_answer(ublas::matrix<double>* ans_matrix)
{
	if (Matricies.size() == 1)
	{
		Matricies.push_back(ans_matrix);
	}
	else
	{
		Matricies[2] = ans_matrix;
	}
	return;
}

bool check_matricies(ublas::matrix<double>* temp_matrix)
{
	if ((*(Matricies[0])).size1() == (*temp_matrix).size2())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void print_matricies()
{
	std::cout << "Matrix 1: " << std::endl << (*(Matricies[0])) << std::endl
		<< "Matrix 2: " << std::endl << (*(Matricies[1])) << std::endl
		<< "Answer Matrix" << std::endl << (*(Matricies[2])) << std::endl << std::endl;

	return;
}