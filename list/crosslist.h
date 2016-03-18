#include "iostream"
using namespace  std;
//#define def_minTwoNum(x, y) (x)>(y)? y:x
typedef unsigned short u_short;
typedef struct str_crossListArc   crossListArc;
typedef struct str_crossListArc*  pcrossListArc;
typedef struct str_crossList      crossListHead;
typedef struct str_crossList*      pCrossListHead;
struct str_crossListArc
{
	const u_short 		   startNode;
	const u_short		   endNode;
	u_short			       Cost;
	const int              edgeNumber;
	pcrossListArc	       down;
	pcrossListArc          right;
	//bool		           known;
};
struct str_crosslistHeadRow {
	bool          is_key;	//是否关键点
	bool	      known;		//是否走过
	u_short       layer;		//层数
	u_short       outDgree;	//出度
	pcrossListArc next;
};
struct str_crosslistHeadColumn {
	bool		   is_key;	//是否关键点
	bool		   known;		//是否走过
	u_short		   layer;		//层数
	u_short		   inDgree;	//ru度
	pcrossListArc  next;
};

struct str_crossList
{
	struct str_crosslistHeadRow*	head_row;
	struct str_crosslistHeadColumn* head_colunm;
	u_short 						nodeCount;
	int								edgeCount;
};

pCrossListHead creatCrossList(int edgenum);
u_short insertCrossList(pCrossListHead crossList, signed short nodeNum, const u_short startNode, \
	const u_short endNode, u_short cost, const int edgenum);
void printCrossList(pCrossListHead crosslist, int num);