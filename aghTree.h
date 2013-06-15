#ifndef AGHTREE_H
	#define AGHTREE_H
	#include "aghContainer.h"


template <typename TYPE>
class aghTree : public aghContainer<TYPE> {
/**
 * \class aghTree
 * \author Michal Mankowski 
 * \brief klasa reprezentujaca drzewo bst
 */  

	private:

aghBranch<TYPE>* go2pos(int i,aghBranch<TYPE>* branch) const; 
//< funkcja zwracajaca wezel na danej pozycjii
//niech bedzie lvr

int tree_size;   //< wielkosc drzewa
aghBranch<TYPE>* root; //< wskaznik na wezel - korzen


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
~aghTree() { this->clear(); root = NULL; }


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
aghBranch<TYPE>* aghTree<TYPE>::go2pos(int _index, aghBranch<TYPE> *_ptr ) const
{//ptr w pierwszym uruchomieniu zawsze ma wartosc root!

std::cout<<"g2p "<< _index<< " \n";

if(0 == _index) return _ptr;
else
{   
    std::cout<<"left:"<<_ptr->get_next('l')<<"  right:"<<_ptr->get_next('r')<<"\n";
    if(_ptr->get_next('l') != NULL) 
    { //elsify popsuly by!
        
        _ptr=go2pos(--_index, _ptr->get_next('l'));
    }
    std::cout<<"gonna check...\n";
    
    if(_ptr->get_next('r') != NULL)
    {
        std::cout<<"R!";
       _ptr=go2pos(--_index, _ptr->get_next('r'));
    }
    if(_ptr->get_next('r') == NULL && _ptr->get_next('l') == NULL) 
        return _ptr;
}

return _ptr;
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
//if(i>= this->size() || i<0) throw aghException("Wrong index for at()!");
if(i<0 || i>= this->size() ) throw -1; //tymczasowe

return go2pos(i,root)->get_data();
}



template <typename TYPE>
aghTree<TYPE>& aghTree<TYPE>::operator=(const aghTree<TYPE>& pattern)
{
*this=aghContainer<TYPE>::operator=(pattern);
return *this;
}



#endif
