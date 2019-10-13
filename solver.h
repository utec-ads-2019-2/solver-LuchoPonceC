#include "nodes/node_div.h"
#include "nodes/node_dif.h"
#include "nodes/node_exp.h"
#include "nodes/node_mult.h"
#include "nodes/node_paren.h"
#include "nodes/node_sum.h"
#include "nodes/node_varia.h"
#include "nodes/node_apoyo.h"
#include <queue>
#include <stack>


class Solver{
	Node *root;
	stack<Node *> Operadores;
	queue<Node *> Postfijo;
	stack<Node *> stackTree;
	string ecuacion;


	void validar_prioridad(Node *actual){
		
		if(actual->prioridad > Operadores.top()->prioridad){
			Operadores.push(actual);
		}
		else{
			while((Operadores.top())->data != "#" and actual->prioridad <= Operadores.top()->prioridad){
				Postfijo.push(Operadores.top());
				Operadores.pop();
			}
			Operadores.push(actual);
		}
				
	}

	void insertar_op(char temporal){
		switch(temporal){
			case '+':
				validar_prioridad(new Node_sum());
				break;
			case '-':
				validar_prioridad(new Node_dif());
				break;
			case '*':
				validar_prioridad(new Node_mult());					
				break;
			case '/':
				validar_prioridad(new Node_div());				
				break;
			case '^':
				Operadores.push(new Node_exp());
				break;
			case ')':
				
				while((Operadores.top())->data != "#" and (Operadores.top())->data != "("){
					Postfijo.push(Operadores.top());
					Operadores.pop();
				}
				Operadores.pop();
				
				break;
			case '(':
				
				Operadores.push(new Node_paren("("));
				
				break;
		}
	}

	bool isOperator(Node *actual){
		if(actual->data == "+" or actual->data == "-" or actual->data == "*" or actual->data == "/" or actual->data == "^"){
			return true;
		}
		return false;
	}


	void makeTree (){
		while(Postfijo.size()>0){
			stackTree.push(Postfijo.front());
			Postfijo.pop();
			if(stackTree.size()>=3){
				createNodeTree();
			}
		}
		root = stackTree.top();

	}

	void createNodeTree(){
		Node *actual = stackTree.top();
		if(isOperator(actual)){
			stackTree.pop();
			actual->left = stackTree.top();
			stackTree.pop();
			actual->right = stackTree.top();
			stackTree.pop();
			stackTree.push(actual);
		}
		return;



	}

	void delete_all(Node *current){
		if(!current->right and current->left) {
            delete_all(current->left);
        }
        if(!current->left and current->right) {
            delete_all(current->right);
        }
        if(current->right and current->left) {
            delete_all(current->left);
            delete_all(current->right);
        }
        delete current;
        current = nullptr;
	}



public:

	float Execute(){
		return root->execute();
	}

	void print_ecuacion(){
		std::cout<<"La ecuacion es la siguiente: "<<this->ecuacion<<std::endl;
	}

	Solver() : root(nullptr) {
		Operadores.push(new Node_apoyo());
	}

	~Solver(){
		delete_all(root);
	}
	


	void ingresar (){
		string texto;
		std::cin>>texto;
		this->ecuacion = texto;
		string temporal = "";
		int pos_fin=0;
		for(int i=0; i<=texto.size();i++){
			if(temporal.size()==0){
				temporal = temporal + texto[i];
			}
			else{
				
				pos_fin = (temporal.size()-1);

				if((65<=temporal[pos_fin] and temporal[pos_fin]<=90) or (97<=temporal[pos_fin] and temporal[pos_fin]<=122)){

					while((65<=texto[i] and texto[i]<=90) or (97<=texto[i] and texto[i]<=122)){
						temporal = temporal + texto[i];
						i++;
					}
					Postfijo.push(new Node_varia(temporal,false));
					
					temporal = "";
				}


				else if(48<=temporal[pos_fin] and temporal[pos_fin]<=57){
					
					while(48<=texto[i] and texto[i]<=57){
						temporal = temporal + texto[i];
						i++;

					}

					Postfijo.push(new Node_varia(temporal,true));
					
					temporal = "";
				}

				else{
					insertar_op(temporal[pos_fin]);
					
					
					temporal = "";
				}

				i--;
		
			}
			
		}

		while(Operadores.top()->data != "#"){
			Postfijo.push(Operadores.top());
			Operadores.pop();
		}

		makeTree();

	}	



};

