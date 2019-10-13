#include "node.h"

class Node_dif : public Node{



public:

	//int prioridad;

	Node_dif() : Node(){
		this->data = "-";
		this->prioridad = 1; 
	}


	float execute(){
		return (this->right)->execute() - (this->left)->execute();
	}

};
