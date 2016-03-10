#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include "iostream"
#include "iomanip"
#include "memory"
#include "cassert"
#include "string"
#include "array"
#define  def_VertexNum  4
#define  def_MAXCAST  INT_MAX
#define  def_notVertex -1
#define  vertex  signed int 

typedef  int  elemType;
using namespace  std;

typedef struct str_adjacentNode adjacentNode;	   //node
typedef adjacentNode*  pAdjacentNode;			   //pNode
typedef struct str_adjacentTable  adjacentTable;   //table
typedef adjacentTable*  pAdjacentTable;			   //PTABLE

struct str_adjacentNode
{
	int vertexNumber;
	int adjcentNodeCast;  //代价...
	pAdjacentNode next;

};
struct str_adjacentTable
{
	pAdjacentNode adjacentNode;
	int pathInde;  //path的扫描过程，各个点
	bool known;  //此vertex有无找到最短的路径
	int sumCast;
};
std::shared_ptr<array<int,def_VertexNum>>  ScreatAdjacentMetric(int vertexNum);

//void creatAdjacentMetric(int **array, int vertexNum);
void creatAdjacentMetric(int array[][def_VertexNum], int vertexNum);
//void creatAdjacentMetric(int (*array)[def_VertexNum], int vertexNum); //二维数组走参数问题

void createAdjacentTable(pAdjacentTable adjTable, int vertexNum);
void travelAdjacentTable(pAdjacentTable adjTable, int vertexNum);

void Djkstra(pAdjacentTable adjTable, int vertexNum, int i);

void printRoute(pAdjacentTable adjTable ,int end);

#endif

