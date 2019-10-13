#include <iostream>
#include "solver.h"

int main(){

 	Solver solv;
 	solv.ingresar();
 	solv.print_ecuacion();
 	std::cout<<solv.Execute()<<std::endl;;

	return 0;
}