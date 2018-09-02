#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

#include "list.h"

using namespace std;
int main()
{
	int actual;
	List<int> test;
	cout<<"test"<<endl;

	if(test.empty()){
		cout<<"vacia"<<endl;
	}else{
		cout<<"con algo de dentro"<<endl;
	}

	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.print_list();
	cout<<"-------------"<<endl;
	test.pop_back();
	test.print_list();
	cout<<"-------------"<<endl;
	test.pop_back();
	test.print_list();
	cout<<"-------------"<<endl;
	test.get(4);
	test.size();
	return 0;
}