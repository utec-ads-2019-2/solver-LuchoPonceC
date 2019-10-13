#include "node.h"

class Node_paren : public Node{


public:

	//int prioridad;

	Node_paren(string parentesis) : Node(){
		this->data = parentesis;
		this->prioridad = 0;
	}



	float execute(){
		
	}

};
