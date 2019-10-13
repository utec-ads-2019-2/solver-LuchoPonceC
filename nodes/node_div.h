#include "node.h"

class Node_div : public Node{


public:

	//int prioridad;

	Node_div() : Node(){
		this->data = "/";
		this->prioridad = 2; 
	}


	float execute(){
		return (this->right)->execute() / (this->left)->execute();
	}

};
