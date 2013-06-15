#include "aghBranch.h"
#include "aghTree.h"


int main()
{
aghBranch<int> a,b,c;
aghTree<int> tr;
aghBranch<int> *root,*ptr;

a.set_data(100);
b.set_data(-10);
c.set_data(34);


tr.append(4); std::cout<<"4\n";
tr.append(5); std::cout<<"5\n";
tr.append(2); std::cout<<"2\n";
tr.append(3); std::cout<<"3\n";
tr.append(1); std::cout<<"1\n";
tr.append(6); std::cout<<"6\n";

std::cout<< tr.at(3) <<"\n";
std::cout<< tr.at(1) << std::endl;;
std::cout<< tr.at(2) << std::endl;

std::cout<<"\n"<<tr;

root = &a;
root->set_next('l',&b);
root->set_next('r',&c);


ptr = root->get_next('l');
std::cout<< root->get_next('r')->get_data();
ptr->set_data(-10000);
std::cout<<"\n"<<ptr->get_data()<<"\n";



}
