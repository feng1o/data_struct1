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
#define  vertex  unsigned short 
typedef  int  elemType;
using namespace  std;

typedef struct str_adjacentNode adjacentNode;	   //node
typedef adjacentNode*  pAdjacentNode;			   //pNode
typedef struct str_adjacentTable  adjacentTable;   //table
typedef adjacentTable*  pAdjacentTable;			   //PTABLE

struct str_adjacentNode
{
	int vertexNumber;
	int adjcentNodeCast;  //����...
	pAdjacentNode next;

};
struct str_adjacentTable
{
	pAdjacentNode adjacentNode;
	int pathInde;  //path��ɨ����̣�������
	bool known;  //��vertex�����ҵ���̵�·��
	int sumCast;
};
std::shared_ptr<array<int,def_VertexNum>>  ScreatAdjacentMetric(int vertexNum);

//void creatAdjacentMetric(int **array, int vertexNum);
void creatAdjacentMetric(int array[][def_VertexNum], int vertexNum);
//void creatAdjacentMetric(int (*array)[def_VertexNum], int vertexNum); //��ά�����߲�������

void createAdjacentTable(pAdjacentTable adjTable, int vertexNum);
void travelAdjacentTable(pAdjacentTable adjTable, int vertexNum);

void Djkstra(pAdjacentTable adjTable, int vertexNum, int i);

#endif

