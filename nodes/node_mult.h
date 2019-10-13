#include "node.h"

class Node_mult : public Node{



public:

	//int prioridad;

	Node_mult() : Node(){
		this->data = "*"; 
		this->prioridad = 2;
	}


	float execute(){
		return (this->right)->execute() * (this->right)->left();
	}

};
