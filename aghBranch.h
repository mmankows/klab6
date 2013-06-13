#ifndef AGHBRANCH_H
	#define AGHBRANCH_H

	//!!!!!!
	#include <iostream>
	#include <stdlib.h>
	//!!!!!!

template<typename TYPE>
class aghBranch {

	protected:
TYPE data;
aghBranch<TYPE> *right, *left;	


	public:
aghBranch<TYPE>() :  right(NULL), left(NULL) {}
~aghBranch<TYPE>() { right = NULL; left = NULL; }


TYPE& get_data(void) {return data;}
void set_data(TYPE _newdata) { this->data = _newdata; }


aghBranch<TYPE>* get_next(char c) { 
if(c=='l') return left;
else if(c=='r') return right;
else return NULL;
}
void set_next(char c, aghBranch<TYPE>* _node) {
if(c=='l') left = _node;
else right = _node;
}


};
	
#endif
