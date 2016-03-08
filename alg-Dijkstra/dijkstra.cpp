#include "dijkstra.h"

#if 01
std::shared_ptr<array<int,def_VertexNum>> ScreatAdjacentMetric(int vertexNum)
{
	//std::shared_ptr<std::shared_ptr<int>> adjacenMeric(new std::shared_ptr<int>);

#if 0
	std::shared_ptr<int> adjacentMetric(new int[vertexNum]);
	for (int i = 0; i < vertexNum; i++)
	{
			(adjacentMetric.get())[i] = i;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		std::cout << adjacentMetric.get()[i] << std::endl;
	}
#endif

	std::shared_ptr<std::array<int, def_VertexNum>> adjacentMetric(new std::array<int, def_VertexNum>[def_VertexNum]);
	for (int i = 0; i < def_VertexNum; i++)
	{
		for (int j = 0; j < def_VertexNum; j++)
		{
			adjacentMetric.get()[i][j] = i+j;
		}
	}
	return  adjacentMetric;
}
#endif

void creatAdjacentMetric(int array[][def_VertexNum], int vertexNum)
{
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			array[i][j] = i;
		}
	}

}


void createAdjacentTable(pAdjacentTable adjTable, int vertexNum)
{
	cout << "从vertex=0开始，请输入各个vertex信息：" << endl;
	pAdjacentNode adjNode = nullptr;
	pAdjacentNode adjNode2 = NULL;
	for (int i = 0; i < vertexNum; i++)
	{
		adjTable[i].pathInde = def_notVertex;
		adjTable[i].known = false;
		adjTable[i].sumCast = INT_MAX;

		for (int j = 0; j < vertexNum; j++)
		{
			unsigned int adjacent = -1;
			cout  << i << "->" << j << "如果相邻，请输入1,否则输入2为不可达" << endl;
			cin >> adjacent;
			int cast;
			switch (adjacent)
			{
			case 1:
				cout << "you input " << 1 << endl;
				cout<<  i << "->" << j << "相邻，请输入cast:" << endl;
				cin >> cast;
				adjNode = new adjacentNode;
				assert(NULL != adjNode);
				adjNode->vertexNumber = j;
				adjNode->adjcentNodeCast = cast;
				if (adjNode2 == NULL)
				{
					//cout << "......................" << adjNode2 << ",,," << adjNode << endl;
					adjNode2 = adjNode;		
					adjTable[i].adjacentNode = adjNode2;
				}
				else
				{
					adjNode2->next = adjNode;
					adjNode2 = adjNode2->next;
				}
				adjNode->next = NULL;
				break;
			case 2:
				cout << i << "->"  << j << "不相邻...:" << endl;
				adjTable[i].adjacentNode = NULL;
				break;
			default:
				cout << "input error" << i << "->" << j << " 默认不相邻...:" << endl;
				adjTable[i].adjacentNode = NULL;
				break;
			}
		}
		adjNode2->next = NULL;
		adjNode2 = NULL;

	}
}


void travelAdjacentTable(pAdjacentTable adjTable, int vertexNum)
{
	for (int i = 0; i < vertexNum; i++)
	{
		pAdjacentNode adjNode = adjTable[i].adjacentNode;
		while (adjNode != nullptr)
		{
			cout  << i << "->"  << adjNode->vertexNumber << "  cast:" << adjNode->adjcentNodeCast << "       ";
			adjNode = adjNode->next;
		}
		cout << endl;
		
	}
}

int findSmallestVertexToCurrentVertex(pAdjacentTable table, int i)
{
	int smallestIndex = def_notVertex;
	int smallCast = INT_MAX;
	pAdjacentNode adjNode = table[i].adjacentNode;
	while (adjNode != nullptr)
	{
		if (adjNode->adjcentNodeCast < smallCast)
		{
			smallestIndex = adjNode->vertexNumber;
			smallCast = adjNode->adjcentNodeCast;
		}
		adjNode = adjNode->next;
	}
	return smallestIndex;
}

void updateSumCostAllVertex(pAdjacentTable adjTable, int i,int j, int subCost)
{
	pAdjacentNode adjNode = adjTable[i].adjacentNode;
	adjTable[i].known = true;
	while (adjNode != nullptr)
	{
		if (adjTable[i].sumCast > adjTable[j].sumCast + subCost)
		{
			adjTable[i].sumCast = adjTable[j].sumCast + subCost;
			adjTable[i].pathInde = j;
		}
		adjNode = adjNode->next;
	}
}
void Djkstra(pAdjacentTable adjTable, int vertexNum, int i)
{
	pAdjacentNode adjNode = NULL;
	adjNode = adjTable[i].adjacentNode;
	adjTable[i].known = true;
	while (adjNode != nullptr)
	{
		adjTable[adjNode->vertexNumber].sumCast = adjNode->adjcentNodeCast; //更新各个点的代价
		adjNode = adjNode->next; 
	}

	vertex Vsmall = def_notVertex;
	vertex W_adjV = def_notVertex;
	for (int i = 0; i < vertexNum; i++)
	{
		Vsmall = findSmallestVertexToCurrentVertex(adjTable, i);
		if (def_notVertex == Vsmall)
			break;
		adjTable[Vsmall].known = true;
		adjNode = adjTable[Vsmall].adjacentNode;
		while (adjNode != nullptr)
		{
			W_adjV = adjNode->vertexNumber;
			updateSumCostAllVertex(adjTable, W_adjV, Vsmall, adjNode->adjcentNodeCast);
		}
	}
}
