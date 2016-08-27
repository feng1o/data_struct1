/*给点一个nm矩阵点，.表示你可走，X表示不能进入的点，，求从某一个点开始，到走出去（边界）最长的路径是多少步*/
//怎么改用非递归的呢？可以套用非递归的最快走出迷宫算法吗？？？
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct dirent{
	int row;
	int col;
} dirent;

void  goOutMax(vector<vector<char>>  vec, int row, int col, int dx, int dy, vector<dirent> dvec, int ii, int step, int& max);
//void  goOutMax(vector<vector<char>>  vec, int row, int col, int dx, int dy, vector<dirent> dvec, int i, int& max);

int main(){
	int col = 10;
	int row = 7;
	cout << "输入行列数，，，，" << endl;
	cin >> row;
	cin >> col;

	vector<vector<char>>  vec;
	
	for (int i = 0; i < row; ++i){
		vector<char>  jvec;
		for (int j = 0; j < col; ++j){
			char ch='.';
			//cin >> ch;
			jvec.push_back(ch);
		}
		vec.push_back(jvec);
		jvec.clear();
	}
	cout << "vec...ii>>" << vec[2][2] << endl;

	int dx = 0; 
	int dy = 1;
	//cin >> dx;
	//cin >> dy;
	int n = 4;
	//cin >> n;  //输入可走的方向，，，默认给了4个，，，
	vector<dirent> dvec;
	/*while (n--){
		dirent dr;
		cin >> dr.row;
		cin >> dr.col;
		dvec.push_back(dr);
	}*/
	dirent dr;
	dr.row = 1;
	dr.col = 0;
	dvec.push_back(dr);

	dirent dr2;
	dr2.row = 0;
	dr2.col = 1;
	dvec.push_back(dr2);

	dirent dr3;
	dr3.row = -1;
	dr3.col = 0;
	dvec.push_back(dr3);


	dirent dr4;
	dr3.row = 0;
	dr3.col = -1;
	dvec.push_back(dr4);


	int max = 0;
	int i = 0;
	goOutMax(vec, row, col, dx, dy, dvec,0, i, max);
	cout << max << endl;
	return 0;
}

//void  goOutMax(vector<vector<char>>  vec, int row, int col, int dx, int dy, vector<dirent> dvec, int step, int& max){
void  goOutMax(vector<vector<char>>  vec, int row, int col, int dx, int dy, vector<dirent> dvec, int ii, int step, int& max){
	/*static int step2 = 0;
	if (step2 > max)
		max = step2;*/
	if (step > max){ //补数变多了，，更新
		max = step;
		cout << "step....:" << step << endl;
		cout << "max.....:" << max << endl;
	}
	//cout << "----------------------dx =" << dx << "  dy=" << dy << endl;
	if (dx < 0 || dx > row - 1 || dy < 0 || dy > col - 1){
		step = 0;
		return;
	}
	//到边界或者遇到 X不能走的点
	if (step != 0 && (dx == 0 || dx == row - 1 || dy == 0 || dy == col - 1 || vec[dx][dy] == 'X')){
	//if (dx < 0 || dx >= row - 1 || dy < 0 || dy > col - 1 || vec[dx][dy] == 'X'){
		//step = 0;
		cout << "----------------------dx =" << dx << "  dy=" << dy << endl;
		return;
	}
	int tdx = dx;
	int tdy = dy;
	int size = static_cast<int>(dvec.size());
	int istep = step;
	//++step;
	int i = ii;
	//for (int i = 0; i < size; ++i){
	for (; i < size; ++i){  //4个方向各个常识
		int k = i;
		cout << "in for....:" << i << "\n";
		cout << "tdx...:" << tdx << endl << endl;
		cout << ".............." << dvec[k].row << " || " << dvec[k].col << endl;
		//if (step != 0 && (dx == 0 || dx == row - 1 || dy == 0 || dy == col - 1 || vec[dx][dy] == 'X'))
		//	break;
		//goOutMax(vec, row, col, dx + dvec[i].row, dy + dvec[i].col, dvec, ++step, max);
		cout << "----------------------tdx =" << dx << "  tdy=" << dy << endl;
		//goOutMax(vec, row, col, tdx + dvec[i].row, tdy + dvec[i].col, dvec, step, max); //也不行 
		goOutMax(vec, row, col, tdx + dvec[k].row, tdy + dvec[k].col, dvec, i, istep+1, max); 
		//dx -= dvec[i].row;
		//dy -= dvec[i].col;
		//++step;
		  //++step2; //STAITC 会一直加
		if (!(i % 3))
			cout << endl;
	}
	return;
}