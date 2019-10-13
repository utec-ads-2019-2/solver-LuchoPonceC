#include "node.h"
#include <cmath>

class Node_exp : public Node{


public:

	//int prioridad;

	Node_exp() : Node(){
		this->data = "^";
		this->prioridad = 3; 
	}


	float execute(){
		return pow((this->right)->execute(),(this->left)->execute());
	}

};
