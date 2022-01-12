#include <iostream>

using namespace std;

template <typename T>
class myUnique {
private:
	T* ptr;

public:
	//konstruktor kopiujacy
	
	myUnique(const myUnique &) = delete;
	myUnique operator=(const myUnique &)= delete;
};

template <typename T>
class myShared {
private:
	static int counter;
	static T* ptr;
public:
	//konstruktor kopiujacy
	myShared(T* ptr){
		this->ptr=ptr;
		counter++;
	}
	
	myShared(const myShared &) = delete;

	myShared operator=(const myShared &){
		counter++;
		return this;
	}

	~myShared(){
		if(counter==1)
			delete ptr;
		counter--;
	}
};

template <typename T>
int myShared<T>::counter = 0;


int main()
{

	return 0;
}
