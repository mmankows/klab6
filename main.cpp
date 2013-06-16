#include "aghInclude.h"

int main()
{
aghBranch<int> a,b,c;
aghTree<int> tr;
aghBranch<int> *root,*ptr;



a.set_data(100);
b.set_data(-10);
c.set_data(34);

tr.append(8); std::cout <<"wrzucam 8\n";

tr.append(4); std::cout<<"wrzucam 4\n";
tr.append(2); std::cout<<"wrzucam 2\n";

tr.append(3); std::cout<<"wrzucam 3\n";

tr.append(6); std::cout<<"wrzucam 6\n";
tr.append(14); std::cout<<"41\n";
tr.append(1); std::cout<<"1\n";
tr.append(9); std::cout<<"9\n";


std::cout<< tr.at(2) <<"\n";
std::cout<< tr.at(0) << std::endl;;
std::cout<< tr.at(1) << std::endl;

std::cout<<"\n"<<tr;

root = &a;
root->set_next('l',&b);
root->set_next('r',&c);

 tr.remove(0);
 tr.remove(3);

std::cout<<"\n\n"<<tr;


ptr = root->get_next('l');
std::cout<< root->get_next('r')->get_data();
ptr->set_data(-10000);
std::cout<<"\n"<<ptr->get_data()<<"\n";
cout << "KONIEC\n\n\n\n";
cout <<tr<<endl;
aghTree<int> tr2=tr;
//cout<<"[1]   "<<tr<<endl<<"size "<<tr.size()<<endl<<endl<<endl;
//tr.clear();
//tr2.insert(0,100);
//tr2.remove(1);
//tr2=tr;
//cout<<"[2]   "<<tr2<<endl<<tr2.size()<<endl;
//cout<<" 2  "<<tr2<<endl<<endl;
//int i=0;
//cout << tr2.root <<endl;
//cout << tr.root <<endl;
}
