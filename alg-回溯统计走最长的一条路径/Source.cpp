/*����һ��nm����㣬.��ʾ����ߣ�X��ʾ���ܽ���ĵ㣬�����ĳһ���㿪ʼ�����߳�ȥ���߽磩���·���Ƕ��ٲ�*/
//��ô���÷ǵݹ���أ��������÷ǵݹ������߳��Թ��㷨�𣿣���
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
	cout << "������������������" << endl;
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
	//cin >> n;  //������ߵķ��򣬣���Ĭ�ϸ���4��������
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
	if (step > max){ //��������ˣ�������
		max = step;
		cout << "step....:" << step << endl;
		cout << "max.....:" << max << endl;
	}
	//cout << "----------------------dx =" << dx << "  dy=" << dy << endl;
	if (dx < 0 || dx > row - 1 || dy < 0 || dy > col - 1){
		step = 0;
		return;
	}
	//���߽�������� X�����ߵĵ�
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
	for (; i < size; ++i){  //4�����������ʶ
		int k = i;
		cout << "in for....:" << i << "\n";
		cout << "tdx...:" << tdx << endl << endl;
		cout << ".............." << dvec[k].row << " || " << dvec[k].col << endl;
		//if (step != 0 && (dx == 0 || dx == row - 1 || dy == 0 || dy == col - 1 || vec[dx][dy] == 'X'))
		//	break;
		//goOutMax(vec, row, col, dx + dvec[i].row, dy + dvec[i].col, dvec, ++step, max);
		cout << "----------------------tdx =" << dx << "  tdy=" << dy << endl;
		//goOutMax(vec, row, col, tdx + dvec[i].row, tdy + dvec[i].col, dvec, step, max); //Ҳ���� 
		goOutMax(vec, row, col, tdx + dvec[k].row, tdy + dvec[k].col, dvec, i, istep+1, max); 
		//dx -= dvec[i].row;
		//dy -= dvec[i].col;
		//++step;
		  //++step2; //STAITC ��һֱ��
		if (!(i % 3))
			cout << endl;
	}
	return;
}