#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class BaseClass{
protected:
	int FirstAttribute;
	int SecondAttribute;
public:
	BaseClass(const int& first, const int& second): FirstAttribute(first), SecondAttribute(second){};

	virtual void display() const{
		cout<<FirstAttribute<<" "<<SecondAttribute<<endl;
	};

	void setFirstAttribute(const int& d){
		FirstAttribute = d;
	};
	void setSecondAttribute(const int& d){
		SecondAttribute = d;
	};

	virtual ~BaseClass(){};
};


class FirstDerived : public BaseClass{
protected:
	int DerivedAttribute;
public:
	FirstDerived(const int& f, const int& s, const int& d): BaseClass(f, s), DerivedAttribute(d){};

	void display() const override{
		cout<<FirstAttribute<<" "<<SecondAttribute<<" "<<DerivedAttribute<<endl;
	}

	~FirstDerived(){};
};

class SecondDerived : public BaseClass{
protected:
	int AnotherDerived;
public:
	SecondDerived(const int& f, const int& s, const int& d): BaseClass(f,s), AnotherDerived(d){};

	void display() const override{
		cout<<FirstAttribute<<" "<<SecondAttribute<<" "<<AnotherDerived<<endl;
	}
	~SecondDerived(){};
};

void modifyObj(BaseClass* ptr){
	ptr->setFirstAttribute(2);
	ptr->setSecondAttribute(2);
}

int main() {
	vector<BaseClass*> vec;
	vec.resize(3);
	vec[0] = new BaseClass(0,0);
	vec[1] = new FirstDerived(0,0,0);
	vec[2] = new SecondDerived(0,0,0);
	for(const auto i: vec){
		i->display();
	}
	for(const auto i: vec){
		modifyObj(i);
		i->display();
		delete i;
	}
	return 0;
}