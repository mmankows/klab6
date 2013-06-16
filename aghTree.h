#ifndef AGHTREE_H
	#define AGHTREE_H
	#include "aghContainer.h"
    #include "aghBranch.h"

template <typename TYPE>
class aghTree : public aghContainer<TYPE> {
/**
 * \class aghTree
 * \author Michal Mankowski 
 * \brief klasa reprezentujaca drzewo bst
 */  

	private:


int tree_size;   //< wielkosc drzewa
aghBranch<TYPE>* root; //< wskaznik na wezel - korzen


aghBranch<TYPE>* parent(aghBranch<TYPE>* son, int pos);
aghBranch<TYPE>* go2pos(int& _index,aghBranch<TYPE>* ) const; 
//< funkcja zwracajaca wezel na danej pozycjii
//niech bedzie lvr

/**
 * \brief metoda przeszukujaca drzewo az do znalezienia szukanego indexu
 * \param index kiedy ma sie zatrzymac, jesli -1 to przeszukuje do konca
 * \return wskaznik do szukanego wezla
*/
aghBranch<TYPE>* LVR(int index=-1); 


	public:

/**
 * \brief konstruktor domyslny
 */	
aghTree(void): tree_size(0), root(NULL) {}

/**
 * \brief konstruktor kopiujacy
 */
aghTree(const aghContainer<TYPE> &pattern);

/**
 * \brief destruktor
 */
//~aghTree() { this->clear(); root = NULL; }


/**
 * \brief op. przypisania
 * \param pattern - przyjmuje ref. do obiektu
 * \return zwraca referencje do obiektu ktoremu przypisywalismy
 */
aghTree<TYPE>& operator=(const aghTree<TYPE> &pattern);

/**
 * \brief wstawia element 
 *
 * pozycja jest ignorowana, specyfika drzewa
 * \param &_val - wartosc do wstawienia
 * \return true - udalo sie wstawic, false - porazka
 */
bool insert(int , TYPE const &_val);

/**
 * \brief zwraca referencje do obiektu na miejscu _index
 * \param _index - zadane miejsce w drzewie wedlug kolejnosci w LVR
 * \return referencja do obiektu na miejscu index
 */
TYPE& at(int _index) const;

/**
 * \brief zwraca liczbe elementow w pojemniku
 * \return wielkosc pojemnika
 */
int size(void) const { return this->tree_size; }

/**
 * \brief kasuje zadany element
 * \param _index - kasuje element na miejscu _index
 * \return czy udalo sie usunac
 */
bool remove(int _index);
///////


};



template <typename TYPE>
aghBranch<TYPE>* aghTree<TYPE>::parent(aghBranch<TYPE>* son,int pos)
{
aghBranch<TYPE>* ptr;


if(son == this->root) return NULL;
else
{
int temp = pos-1;
ptr=go2pos(temp,root);
temp=pos+1;
if(ptr->get_next('l') == son || ptr->get_next('r') ==son);
else if(temp+1<this->size()) ptr=go2pos(temp,root);
}
return ptr;


}

//---------------------------------------------------------


template <typename TYPE>
aghTree<TYPE>::aghTree(const aghContainer<TYPE> &pattern)
{
	*this = pattern;
}



template <typename TYPE>
aghBranch<TYPE>* aghTree<TYPE>::go2pos(int& _index, aghBranch<TYPE> *_ptr ) const
{//ptr w pierwszym uruchomieniu zawsze ma wartosc root!

	
	aghBranch<TYPE> *_tptr;
	
		if(_ptr->get_next('l') != NULL && _index > -1)
			_tptr = go2pos(_index, _ptr->get_next('l'));

			_index--;

		if(_index == -1 )
			return _ptr;
			
		if(_ptr->get_next('r') != NULL && _index > -1)
			_tptr = go2pos(_index, _ptr->get_next('r'));
	
		return _tptr;
}

//----------------------------------------

template<typename TYPE>
bool aghTree<TYPE>::remove(int _index)
{
    /*
char L = 'l', R='r';

aghBranch<TYPE> *pptr, *bptr;

bptr = go2pos(_index, root);

if(bptr->get_next(L) == NULL && bptr->get_next(R) == NULL)
{ //jesli nie ma synow, wczesniejszy ustaw na null(lewy bo LVR)
 

   go2pos(_index-1,root)->set_next(L,NULL);
   delete bptr;
}
else if(bptr->get_next(L) != NULL && bptr->get_next(R) != NULL)
{
    
    

}    

*/
std::cout<< "rodzic:"<<parent(go2pos(_index,root),_index)->get_data()<<'\n';

}

//-----------------------------------------------------------

template<typename TYPE>
bool aghTree<TYPE>::insert(int i, TYPE const &_val)
{
aghBranch<TYPE>* tptr=this->root;
char S;
this->tree_size++;

if(root!=NULL) 
    {
    if( _val >= root->get_data() ) S='r';
    else S='l';
    }
else
{
root=new aghBranch<TYPE>;
root->set_data(_val);
return true;
}

while(tptr->get_next(S) != NULL)
{

if(_val >= tptr->get_data()  )
    S='r';
else
    S='l';
tptr=tptr->get_next(S);
}


if(_val >= tptr->get_data() ) S='r';
else S='l';
std::cout<<"tworze " << S <<" Wezel!\n";
tptr->set_next(S, new aghBranch<TYPE>() );
tptr->get_next(S)->set_data(_val);

return true;
}




template<typename TYPE>
TYPE& aghTree<TYPE>::at(int i) const
{
	//i++;
//if(i>= this->size() || i<0) throw aghException("Wrong index for at()!");
if(i<0 || i >= this->size() ) throw -1; //tymczasowe

return go2pos(i,root)->get_data();
}



template <typename TYPE>
aghTree<TYPE>& aghTree<TYPE>::operator=(const aghTree<TYPE>& pattern)
{
*this=aghContainer<TYPE>::operator=(pattern);
return *this;
}



#endif
