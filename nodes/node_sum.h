
#include "node.h"

class Node_sum : public Node{


public:

	

	Node_sum() : Node(){
		this->data = "+";
		this->prioridad = 1; 
	}


	float execute(){
		return (this->right)->execute() + (this->left)->execute();
	}

};
