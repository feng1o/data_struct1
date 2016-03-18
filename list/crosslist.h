#include "iostream"

typedef unsigned short u_short;
typedef struct str_crossListNode   crossListNode;
typedef struct str_crossListNode*  pCrossListNode;
struct str_crossListNode
{
	int 		   row;
	int			   column;
	u_short		   adjacentCost;
	int            edgeNumber;
	pCrossListNode down;
	pCrossListNode right;
	bool		   known;
};

typedef struct
{
	pCrossListNode  head_row;
	pCrossListNode  head_colunm;
	u_short 		rowCount;
	u_short 		columnCount;
	int				edgeCount;
}CrossListHead;