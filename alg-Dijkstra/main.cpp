#include "dijkstra.h"

int main()
{
#if 0

//用智能指针返回一个二维数组方法，避免局部指针返回错误，但error
std::shared_ptr<array<int, def_VertexNum>> spArray = ScreatAdjacentMetric(def_VertexNum);
for (int i = 0; i < def_VertexNum; i++)
{
	for (int j = 0; j < def_VertexNum; j++)
	{
		std::cout << std::setw(5) << spArray.get()[i][j];
	}
	cout << std::endl;
}

	std::cout << "use count = " << spArray.use_count() << std::endl;
	auto xx = spArray;
	std::cout << "use count = " << spArray.use_count() << std::endl;
#endif
#if 0
	//int **array = new int *;
	int array[def_VertexNum][def_VertexNum] = { 0 };
	creatAdjacentMetric(array, def_VertexNum);
	for (int i = 0; i < def_VertexNum; i++)
	{
		for (int j = 0; j < def_VertexNum; j++)
		{
			 std::cout << std::setw(3) << array[i][j];
		}
		cout << endl;
	}
#endif

	pAdjacentTable adjTable = new adjacentTable[def_VertexNum];
	createAdjacentTable(adjTable, def_VertexNum);
	std::cout << "\n....................原始..........................\n";
	travelAdjacentTable(adjTable, def_VertexNum);
	Djkstra(adjTable, def_VertexNum, 0);

	std::cout << "\n....................处理后........................\n";
	travelAdjacentTable(adjTable, def_VertexNum);


	cout << "打印路径：" ;
	printRoute(adjTable, 3);
	return 0;
}