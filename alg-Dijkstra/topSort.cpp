#include "dijkstra.h"

#if 0
#include<iostream>
#include<fstream>
using namespace std;

class line{
public:
	int start;
	int end;
	int length;
	int id;
};
int pNum;
int lNum;
bool *ifVisited;
bool ifVisitedLine[4801];
int startP;
int endP;
int mustNum;
int mustP[51];
				line l[4801];
int path[4801];
int successPath[51];
int plength = 999999;
bool success;
int pathPNum;

void dfs(int cur){
	if (cur == pNum){
		return;
	}
	for (int i = 1; i <= lNum; i++){
		if (l[i].start == l[path[cur]].end&&ifVisited[l[i].end] == false){
			if (l[i].end == endP){
				if (cur >= mustNum){
					for (int j = 1; j <= mustNum; j++){
						if (ifVisited[j] == false){
							goto fall;
						}
					}
					int nowLength = 0;
					for (int j = 1; j <= cur; j++){
						nowLength = l[path[j]].length + nowLength;
					}
					if (nowLength < plength){
						plength = nowLength;
						pathPNum = cur;
						for (int j = 1; j < cur; j++){
							successPath[j] = path[j];
						}
						goto success;
					}
				}
				else{
				fall:
					continue;
				}
			}
			else{
				path[cur] == l[i].id;
				ifVisited[i] = true;
				dfs(cur + 1);
				ifVisited[i] = false;
			}
		}
	success:
		continue;
	}
}

int main(){
	ifstream file("1.csv");
	char temp;
	file >> startP >> temp >> endP >> temp;
	temp = '|';
	mustNum = 0;
	while (temp == '|'){
		mustNum++;
		file >> mustP[mustNum];
		temp = '\n';
		file >> temp;
	}
	file.close();
	file.open("2.csv");
	lNum = pNum = 0;
	int temp2;
	while (file >> temp2){
		lNum++;
		l[lNum].id = temp2;
		file >> temp >> l[lNum].start >> temp >> l[lNum].end >> temp >> l[lNum].length;
		if (pNum < l[lNum].start){
			pNum = l[lNum].start;
		}
		if (pNum < l[lNum].end){
			pNum = l[lNum].end;
		}
		temp2 = -1001;
	}
	for (int i = 1; i <= lNum; i++){
		ifVisitedLine[i] = false;
	}
	ifVisited = new bool[pNum + 1];
	for (int i = 1; i <= pNum; i++){
		ifVisited[i] = false;
	}
	ifVisited[startP] = true;
	plength = 0;
	pathPNum = 0;
	success = false;
	dfs(1);
	ofstream file2("3.csv");
	if (success == true){
		for (int i = pathPNum - 1; i >= 1; i--){
			file2 << l[successPath[i]].end;
			if (i != 1){
				file2 << "|";
			}
		}
	}
	else{
		file2 << "NA";
	}
	return 0;
}

# endif 