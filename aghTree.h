#ifndef AGHTREE_H
	#define AGHTREE_H

template <typename TYPE>
class aghTree : public aghContainer<TYPE> {
/**
 * \class aghTree
 * \author Michal Mankowski 
 * \brief klasa reprezentujaca drzewo bst
 */  





int tree_size;   //< wielkosc drzewa
aghBranch<TYPE>* root; //< wskaznik na wezel - korzen

aghBranch<TYPE>* find_successor(aghBranch<TYPE>* node);
aghBranch<TYPE>* parent(aghBranch<TYPE>*);
aghBranch<TYPE>* go2pos(int& _index,aghBranch<TYPE>* ) const; 
aghBranch<TYPE>* vlr(int& _index, aghBranch<TYPE> *_ptr ) const;

public:


/**
 * \brief konstruktor domyslny
 */	
aghTree(void): tree_size(0), root(NULL) {}

/**
 * \brief konstruktor kopiujacy
 */
aghTree(const aghTree<TYPE> &pattern);

/**
 * \brief destruktor
 */
~aghTree() { this->clear(); }


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

//----------------------------------------------------------------------
template <typename TYPE>
aghTree<TYPE>::aghTree(const aghTree<TYPE> &pattern)
{
	this->root=NULL;
	for (int i=0; i < pattern.size(); i++)
			this->append( pattern.at(i) );
}
//----------------------------------------------------------------------

template <typename TYPE>
aghBranch<TYPE>* aghTree<TYPE>::parent(aghBranch<TYPE>* son)
{//szukanie parenta podobnie do metody insert
 //przy uzyciu klucz syna, podazamy sciazka jakbysmy go wstawiali
if(son==NULL) throw aghException(-1,"paernt() : son==NULL!");

std::cout<<"!!\n";


aghBranch<TYPE> *tptr = this->root;
TYPE _val = son->get_data();
char S;
if(son==root) return NULL;
else
{
if(_val >= tptr->get_data()) S='r';
else S='l';
}


while(tptr->get_next(S) != NULL)
    {
    if(_val >= tptr->get_data()  )
        {
        S='r';
        }
    else
        S='l';
    if(tptr->get_next(S) == son) return tptr;    
    tptr=tptr->get_next(S);
    }

}

//---------------------------------------------------------

template <typename TYPE>
aghBranch<TYPE>* aghTree<TYPE>::go2pos(int& _index, aghBranch<TYPE> *_ptr ) const
{//ptr w pierwszym uruchomieniu zawsze ma wartosc root!
if(_index <0 || _index>=this->size() ) throw aghException(-1,"go2pos(): wrong index!");
if(_ptr == NULL) throw aghException(2,"go2pos(): can't start from NULL!");
	
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
aghBranch<TYPE>* aghTree<TYPE>::find_successor(aghBranch<TYPE>* node)
{

if(node==NULL || node->get_next('l') == node->get_next('r') )  throw aghException(20,"find_successor(): wrong node!");
//niepprawy wezel, lub wezel bez obu nastepnikow
TYPE ndatal = node->get_next('l')->get_data(); 
TYPE ndatar = node->get_next('r')->get_data();
char S;

for(int i=0; ; i++)
{
int k=i;    
aghBranch<TYPE> *tptr = vlr(k,node);
TYPE temp = tptr->get_data();

if(tptr->get_next('r')==tptr->get_next('l'))
    {
        if(temp> ndatal && temp<= ndatar )
            return tptr;
    }

}


}

//----------------------------------------------------------------------


template<typename TYPE>
bool aghTree<TYPE>::remove(int _index)
{
if(_index == 0 && this->size() == 1) { delete root; this->root=NULL; }
else
{
if( _index < 0 || _index >= this->size() ) return false;


aghBranch<TYPE> *y,*x,*delnode = go2pos(_index,root), *px, *py;

if(delnode->get_next('l') == NULL || delnode->get_next('r')==NULL)
    y=delnode;
else
    y=find_successor(delnode);



if(y->get_next('l') != NULL)
    x=y->get_next('l');
else
    x=y->get_next('r');

if(x!=NULL)
    px = parent(y);

if(parent(y)==NULL)
    this->root =x;
else
    if(y==parent(y)->get_next('l') )
        parent(y)->set_next('l',x);
    else
        parent(y)->set_next('r',x);
if( y != delnode)
    delnode->set_data(y->get_data());

delete delnode;
}
tree_size--;



return true;




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
tptr->set_next(S, new aghBranch<TYPE>() );
tptr->get_next(S)->set_data(_val);

return true;
}




template<typename TYPE>
TYPE& aghTree<TYPE>::at(int i) const
{

if(i>= this->size() || i<0) throw aghException(-1,"at(): wrong index!");
//if(i<0 || i >= this->size() ) throw -1; //tymczasowe

return vlr(i,root)->get_data();
}



template <typename TYPE>
aghTree<TYPE>& aghTree<TYPE>::operator=(const aghTree<TYPE>& pattern)
{
*this=aghContainer<TYPE>::operator=(pattern);
return *this;
}

//--------------------------------------------------------
template <typename TYPE>
aghBranch<TYPE>* aghTree<TYPE>::vlr(int& _index, aghBranch<TYPE> *_ptr ) const
{//ptr w pierwszym uruchomieniu zawsze ma wartosc root!
 //funkcja przechodzi wiercholki, gdy przejdzie odpowidnia ilosc
 //zwroci _ptr != NULL co bedzie sygnalem do opuszczania
 //kolejnych poziomow rekurencji
 //wartosc przyjmowana przez ref, by uniknac zmiennej static


if(0 == _index) return _ptr;
else
{   
     // std::cout<<"^^"<<_ptr->get_data()<<"\n";
   
    if( _ptr->get_next('l')!=NULL) 
    { //elsify popsuly by!
        aghBranch<TYPE> *tptr = vlr(--_index, _ptr->get_next('l'));
        if(tptr!=NULL) _ptr = tptr;
    }

    if(_index==0) return _ptr; //musi byc

    if( _ptr->get_next('r')!=NULL)
    {
        aghBranch<TYPE> *tptr = vlr(--_index, _ptr->get_next('r'));
        if(tptr!=NULL) _ptr= tptr;
    }
   
}

if(_index==0) return _ptr;
else return NULL;

}



#endif
