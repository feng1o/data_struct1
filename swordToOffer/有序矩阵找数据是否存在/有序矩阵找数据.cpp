#include "iostream"
#include "string"

using namespace std;
class FindSortMatrixElement{
public:
	FindSortMatrixElement() = default;

	bool operator()(int(&array)[4][4],int key){//s数组的引用必须知道界限
		int rows = m_irow;
		int columns = m_icolumn;
		int row = 0;
		int column = columns-1;
		for (; column >= 0;column--)
		{
			if (array[row][column] == key)
				return true;
			if (array[row][column] > key)
				continue;
			else 
			for (; row < rows;++row)
			{
				if (array[row][column] == key)
					return true;
				if (array[row][column]<key)
					continue;
				else break;
			}
			return false;

		}
	}
	~FindSortMatrixElement(){};
private:
	int m_irow = 4;
	int m_icolumn = 4;
};

int main()
{
	int array[][4] = {
		{ 1, 2, 3, 4 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 }
	};
	int a[] = { 1, 2, 3, 5 };
	for (auto &it :array)
	{
		for (auto &it2:it)
		cout << it2 << endl;
	}
	FindSortMatrixElement fsort;
	std::cout<<boolalpha<<"find "<<fsort(array,152);
}