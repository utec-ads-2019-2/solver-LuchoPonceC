#ifndef _INCL_GUARD
#define _INCL_GUARD

using namespace std;

class Node{

protected:
	
	Node *left;
	Node *right;
	string data;
	int prioridad;
public:

	Node() : left(nullptr), right(nullptr){}


	virtual float execute() = 0;

	friend class Solver; 

};

#endif


