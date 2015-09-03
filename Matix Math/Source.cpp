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
//

//Function Prototypes
void process_menu_in(char);
void print_menu();
int print_matricies();
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

	}
	break;

	//add matricies
	case '+':
	{

	}
	break;

	//subtract matricies
	case '-':
	{

	}
	break;

	//multiply matricies
	case '*':
	{

	}
	break;

	//divide matricies
	case '/':
	{

	}
	break;

	//quit program
	case 'Q':
		done = true;
		break;

	default:
		break;
	}


}