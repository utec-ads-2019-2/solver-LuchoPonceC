#include "node.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<string,float> variables ;

class Node_varia : public Node{

private:
	bool numero;
	
public:
	
	

	Node_varia(string data, bool numero) : Node(){
		this->data = data;
		this->numero = numero;

	}


	float execute(){
		if(numero){
			return stof(this->data);
		}
		if(variables.find(this->data) == variables.end()){
			float usar;
			std::cout<<"Digite el valor de la variable "<<this->data<<" ";std::cin>>usar;
			variables[this->data] = usar;
		}
		return variables[this->data];
	}

};
