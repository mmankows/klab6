#include "aghBranch.h"
#include "aghTree.h"


int main()
{
aghBranch<int> a,b,c;

aghBranch<int> *root,*ptr;

a.set_data(100);
b.set_data(-10);
c.set_data(34);

root = &a;
root->set_next('l',&b);
root->set_next('r',&c);


ptr = root->get_next('l');
std::cout<< root->get_next('r')->get_data();
ptr->set_data(-10000);
std::cout<<"\n"<<ptr->get_data()<<"\n";



}
