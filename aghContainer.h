#ifndef AGHCONTAINER_H
  #define AGHCONTAINER_H

#include <iostream>
using namespace std;

template <typename TYPE>
class aghContainer {

public:
	virtual ~aghContainer(){};
	
	void append(TYPE const&);
	bool replace(int, TYPE const&);
	void clear();
	bool isEmpty();
	int indexOf(TYPE const& _value, int _from = 0) const;
	bool contains(TYPE const& _value, int _from = 0) const;

	virtual bool insert(int, TYPE const&)=0;
	virtual TYPE& at(int) const=0;
	virtual int size() const=0;
	virtual bool remove(int)=0;

	bool operator==(aghContainer<TYPE> const&) const;
	bool operator!=(aghContainer<TYPE> const&) const;
	aghContainer<TYPE>& operator=(const aghContainer<TYPE>  &right);
	TYPE& operator[](int) const;
	aghContainer<TYPE>& operator+=(aghContainer<TYPE> const&);
	aghContainer<TYPE>& operator+=(TYPE const&);
	aghContainer<TYPE>& operator<<(TYPE const&);
	aghContainer<TYPE>& operator<<(aghContainer<TYPE> const&);
};

//----------------------------------------------------------------------

template <typename TYPE>
void aghContainer<TYPE>::append(TYPE const& _value)		//wstawianie wartosci na koniec
{
	insert( size(), _value);
}

//----------------------------------------------------------------------

template <typename TYPE>
bool aghContainer<TYPE>::replace(int pos, TYPE const& pattern)
{
	if ( pos >= this->size() || pos < 0 ) return false;
	aghContainer<TYPE> *ptr = & ( at(pos) );	//wskaznik na wartosc do usuniecia
	delete ptr;
	ptr = NULL;
	return  insert(pos, pattern);	//wstawienie nowej wartosci
}
	
//----------------------------------------------------------------------

template <typename TYPE>
void aghContainer<TYPE>::clear()
{
	while ( this->remove(0) );
}

//----------------------------------------------------------------------

template <typename TYPE>
bool aghContainer<TYPE>::isEmpty()
{
	if ( this->size() ) return false;
		else return true;
}

//----------------------------------------------------------------------


template <typename TYPE>
int aghContainer<TYPE>::indexOf(TYPE const& _value, int _from) const
{
	for(int i=_from; i < this->size(); i++)
		if ( this->at(i) == _value ) return i;
	
	return -1;
}

//----------------------------------------------------------------------

template <typename TYPE>
bool aghContainer<TYPE>::contains(TYPE const& _value, int _from) const
{
	for(int i=_from; i < this->size(); i++)
		if ( this->at(i) == _value ) return true;	//przeszukiwanie, przy pierwszym znalezionym konczy

	return false;
}

//----------------------------------------------------------------------

template <typename TYPE>
bool aghContainer<TYPE>::operator==(aghContainer<TYPE> const& right) const
{
	if ( this->size() != right.size() ) return false;
	
	for (int i=0; i < this->size(); i++)
		if ( this->at(i) != right.at(i) ) return false;		//zwraca falsz gdy ktoras wartosc sie rozni
	
	return true;
}

//----------------------------------------------------------------------

template <typename TYPE>
bool aghContainer<TYPE>::operator!=(aghContainer<TYPE> const& right) const
{
	return !(*this == right);
}

//----------------------------------------------------------------------

template <typename TYPE>
TYPE& aghContainer<TYPE>::operator[](int n) const
{
	return this->at(n);
}

//----------------------------------------------------------------------

template <typename TYPE>
aghContainer<TYPE>& aghContainer<TYPE>::operator+=(aghContainer<TYPE> const& right)
{
	for (int i=0; i < right.size(); i++)
		this->append( right.at(i) );	//dodawanie kolejnych wartosci do kontenera wynikowego
		
	return *this;
}

//----------------------------------------------------------------------

template <typename TYPE>
aghContainer<TYPE>& aghContainer<TYPE>::operator+=(TYPE const& element)
{
	this->append( element );
	return *this;
}

//----------------------------------------------------------------------

template <typename TYPE>
aghContainer<TYPE>& aghContainer<TYPE>::operator<<(TYPE const& element)
{
	*this += element;	//uzywanie operatora += zeby nie dublowac kodu
	return *this;
}

//----------------------------------------------------------------------

template <typename TYPE>
aghContainer<TYPE>& aghContainer<TYPE>::operator<<(aghContainer<TYPE> const& right)
{
	*this += right;		//uzywanie operatora += zeby nie dublowac kodu
	return *this;
}

//----------------------------------------------------------------------

template <typename TYPE>
ostream& operator<<(ostream& out, aghContainer<TYPE> const& right)
{
	for (int i=0; i < right.size(); i++)
		out << i << " element pojemnika: " << right.at(i) << endl;
	return out;
}

//----------------------------------------------------------------------


template <typename TYPE>
aghContainer<TYPE>& aghContainer<TYPE>::operator=(const aghContainer<TYPE>  &right)
{
	
	if( this == &right );
	else
		{
		if (!( this->isEmpty() ) ) this->clear();	//wyczyszczednie kontenera
		for(int i=0; this->size() < right.size(); i++)
			this->append(right[i]);		//dodawanie kolejno wartosci
		}
	return *this;
}

#endif
