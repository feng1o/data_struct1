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
	cout << "��vertex=0��ʼ�����������vertex��Ϣ��" << endl;
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
			if (i == j) continue;     //�Լ����Լ�������
			cout  << i << "->" << j << "������ڣ�������1,��������2Ϊ���ɴ�" << endl;
			cin >> adjacent;
			int cast;
			switch (adjacent)
			{
			case 1:
				cout << "you input " << 1 << endl;
				cout<<  i << "->" << j << "���ڣ�������cast:" << endl;
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
				cout << i << "->"  << j << "������...:" << endl;
				adjTable[i].adjacentNode = NULL;
				break;
			default:
				cout << "input error" << i << "->" << j << " Ĭ�ϲ�����...:" << endl;
				adjTable[i].adjacentNode = NULL;
				break;
			}
		}
		if (NULL != adjNode2){
			adjNode2->next = NULL;
			adjNode2 = NULL;
		}
	}
}


void travelAdjacentTable(pAdjacentTable adjTable, int vertexNum)
{
	cout << "\n";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << "���:" << i << "���·���ҵ���:" << std::boolalpha << left <<setw(6) << adjTable[i].known << " path:" << setw(2) << adjTable[i].pathInde << " sumcast:" << setw(4) << adjTable[i].sumCast << endl;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		//cout <<"known: " << std::boolalpha << adjTable[i].known << " path:" << adjTable[i].pathInde << " sumcast:"  << adjTable[i].sumCast << endl;
		pAdjacentNode adjNode = adjTable[i].adjacentNode;
		while (adjNode != nullptr)
		{
			cout  << i << "->"  << adjNode->vertexNumber << " cast:" << setw(2) << adjNode->adjcentNodeCast << "  ";
			adjNode = adjNode->next;
		}
		cout << endl;
		
	}
}

int findSmallestVertexToCurrentVertex(pAdjacentTable table, int num)
{
	int smallestIndex = def_notVertex;
	int smallCast = INT_MAX;
	int n = 0;
	while (n < num )
	{
		if (table[n].known == false && table[n].sumCast < smallCast)
		{
			smallestIndex = n;
			smallCast = table[n].sumCast;
		}
		n++;
	}
	return smallestIndex;
}

void Djkstra(pAdjacentTable adjTable, int vertexNum, int i)
{
	adjTable[i].known = true;
	adjTable[i].sumCast = 0;  
	//adjTable[i].pathInde = i;  //�ݹ��˳����������ɸ�ֵ
	pAdjacentNode adjNode = NULL;
	adjNode = adjTable[i].adjacentNode;  //update node i ;;
	while (adjNode != nullptr)
	{
		adjTable[adjNode->vertexNumber].sumCast = adjNode->adjcentNodeCast; //���¸�����Ĵ���
		adjTable[adjNode->vertexNumber].pathInde = i;
		adjNode = adjNode->next;
	}

	vertex Vsmall = def_notVertex;
	vertex W_adjV = def_notVertex;
	for (int n = 1; n < vertexNum; n++)
	{
		Vsmall = findSmallestVertexToCurrentVertex(adjTable, vertexNum); //��ǰһ����������ҵ�������С��node
		if (def_notVertex == Vsmall)
			break;
		i = Vsmall;
		adjTable[Vsmall].known = true;
		adjNode = adjTable[Vsmall].adjacentNode;
		while (adjNode != nullptr)
		{
			W_adjV = adjNode->vertexNumber;
			//updateSumCostAllVertex(adjTable, W_adjV, Vsmall, adjNode->adjcentNodeCast);
			if (adjTable[W_adjV].known == false && adjTable[W_adjV].sumCast > adjTable[Vsmall].sumCast + adjNode->adjcentNodeCast)
			{
				adjTable[W_adjV].sumCast = adjTable[Vsmall].sumCast + adjNode->adjcentNodeCast;
				adjTable[W_adjV].pathInde = Vsmall;
			}
			adjNode = adjNode->next;
		}
	}
}


void printRoute(pAdjacentTable adjTable,  int end)
{
	if (adjTable[end].pathInde != def_notVertex)
	{
		printRoute(adjTable, adjTable[end].pathInde);
		cout << " to ";
	}
	cout << end;
}