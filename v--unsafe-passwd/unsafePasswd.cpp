#include "iostream"
#include "vector"
#include "string"
#include "memory"
#include "set"
#include "algorithm"
using namespace std;

int inputPasswd(std::string & passwd){
	//std::cout << "input passwd which just includes lower letter \"a ,b£¬c,d\":" << std::endl;
	std::cin >> passwd;

	int len = passwd.length();
	if (len == 0 || len > 3 )
	{
		//std::cerr << "input error!!"  << endl;
		std::cerr << endl;
		return 0;
	}
	return len;
}

vector<string> Permutation(string str);
vector<string>  dealPasswd2(string passwd);
vector<string>  dealPasswd2(string passwd, int i);

int main(){

	string *str111 = new string;
	vector<string> ans;
	string passwd;
	int len = inputPasswd(passwd);
	switch (len){
	case 1:
		cout << 'a' << endl << 'b' << endl;
		cout << 'c' << endl << 'd' << endl;
		break;
	case 2:
		dealPasswd2(passwd);
		break;
	case 3:
		dealPasswd2(passwd, 3);
		break;
	}
	return 0;
}

vector<string>  dealPasswd2(string passwd){
	vector<string> strvec;
	string indexch = "abcd";
	if (passwd[0] == passwd[1]){
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[0]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(),tmpvec.end());
		}
	}
	else{
		set<string> scount;
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[0]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[1]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
	}
	//vector<string> answer;
	sort(strvec.begin(), strvec.end());
	vector<string>::iterator it = strvec.begin();
	string  tstr = static_cast<string> (strvec[0]) ;
	for (int i = 0; i < strvec.size(); ++i, ++it){
		cout << tstr << endl;
		while ( *it == tstr && i < strvec.size() )
		{
			++i;
			++it;
			
		}
		tstr = *it;
		//cout << *it << endl;
	}
	return strvec;
}

vector<string>  dealPasswd2(string passwd, int ){
	vector<string> strvec;
	string indexch = "abcd";
	if (passwd[0] == passwd[1] && passwd[1] == passwd[2]){
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			//cout << "3333333333333333" << endl;
			tmpstr.insert(tmpstr.begin(), passwd[0]);
			tmpstr.insert(tmpstr.begin(), passwd[1]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
	}
	else{
		set<string> scount;
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[1]);
			tmpstr.insert(tmpstr.begin(), passwd[2]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[0]);
			tmpstr.insert(tmpstr.begin(), passwd[1]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
		for (int i = 0; i < 4; ++i)
		{
			string tmpstr;
			tmpstr.insert(tmpstr.begin(), passwd[2]);
			tmpstr.insert(tmpstr.begin(), passwd[1]);
			tmpstr.insert(tmpstr.begin(), indexch[i]);
			vector<string> tmpvec = Permutation(tmpstr);
			strvec.insert(strvec.end(), tmpvec.begin(), tmpvec.end());
		}
	}
	//vector<string> answer;
	sort(strvec.begin(), strvec.end());
	vector<string>::iterator it = strvec.begin();
	string  tstr = static_cast<string> (strvec[0]);
	for (int i = 0; i < strvec.size(); ++i, ++it){
		cout << tstr << endl;
		while (*it == tstr && i < strvec.size())
		{
			++i;
			++it;

		}
		tstr = *it;
		//cout << *it << endl;
	}
	return strvec;
}

vector<string> Permutation(string str) {
	vector<string> answer;
	if (str.empty())
		return answer;
	sort(str.begin(), str.end());
	do{
		answer.push_back(str);
	} while (next_permutation(str.begin(), str.end()));
	return answer;
}