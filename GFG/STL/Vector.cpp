#include <iostream>
#include <vector>
using namespace std;

// Printing Vector
void printVector(vector<int> v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
}
int main() {
	vector<int> vec;
	for(int i=0;i<17;++i){
	    // Inserting at the end
	    vec.push_back(i*10);
	}
	printVector(vec);
	cout<<"\nForward Iterators"<<endl;
	//Using iterators
	for(auto itr = vec.begin();itr != vec.end(); ++itr){
	    cout<<*itr<<" ";
	}
	cout<<"\nBackward Iterators"<<endl;
	for(auto itr=vec.rbegin();itr != vec.rend();++itr){
	    cout<<*itr<< " ";
	}
	cout<<"\nSize of vector: "<<vec.size()<<endl;
	cout<<"Max_Size of Vector "<<vec.max_size()<<endl;
	cout<<"Capacity of vector "<<vec.capacity()<<endl;
	cout<<"Front "<<(vec.front())<<endl;
	cout<<"Back "<<(vec.back())<<endl;

	vector<int> g1;
	vector<int> g2;
	vector<int> g3;


	g1.assign(5,10);
	cout<<"Vector g1: ";
	printVector(g1);

	g2.assign(g1.begin()+1, g1.end()-1);
	cout<<"\nVector g2: ";
	printVector(g2);

	int arr[] = {1,2,3,4,5};
	g3.assign(arr,arr+5);
	cout<<"\nVector g3: ";
	printVector(g3);

	g1.pop_back();
	cout<<"\nVector g1 after removing from back: ";
	printVector(g1);


	vec.insert(vec.begin()+3,90);
	cout<<"\nVector vec after inserting: ";
	printVector(vec);

	auto it = vec.insert(vec.begin()+10, 5, 100);
	cout<<"\nVector vec after inserting: ";
	printVector(vec);
	cout<<endl<<*(it+6);










}
