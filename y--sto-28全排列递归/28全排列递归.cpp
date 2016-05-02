#include "iostream"
#include "unordered_set"
#include "string"
#include "vector"
#include "algorithm"

class cPermutatio{

public:
	explicit cPermutatio(std::string str1) : str(str1){};
	cPermutatio(const cPermutatio &permu)
	{
		str = permu.str;
	}
	cPermutatio& operator=(const cPermutatio &permu)
	{
		if (this != &permu)
			std::cout << "not self" << std::endl;
		str = permu.str;
		return *this;
	}
	~cPermutatio(){};
	//std::vector<std::string> permutation();
	void permutation();

	void print();
private:	
	//void recurpermu(std::vector<std::string>  vector, int begin);
	void recurpermu(int begin);
	std::string str;
	int i = 0;
	std::vector<std::string>  vector;
	std::unordered_set<char>  uniqset;
};

void cPermutatio::permutation(){
	if (str.length() == 0)
	{
		return ;
	}
	recurpermu(0);
}

void cPermutatio::recurpermu(int begin){
	int len = str.length();
	std::sort(str.begin() + begin, str.end()); //電會。。。
	if (begin == len )
	{
		std::cout << "............." << ++i << std::endl;
		vector.push_back(str);
	}
	for (int i = begin; i < len; ++i)
	{
		if (uniqset.find(str[i]) == uniqset.end()){
			uniqset.insert(str[i]);
			std::swap(str[i], str[begin]);
			recurpermu(begin + 1);
			std::swap(str[i], str[begin]);
		}
	}
}

void cPermutatio::print(){
	//auto it = vector.cbegin();
	for (auto it : vector)
		std::cout << it << std::endl;
}

int main(){
	cPermutatio strpermu("cbb");
	strpermu.permutation();
	strpermu.print();
	return 0;
}