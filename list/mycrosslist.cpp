#include "crosslist.h"

pCrossListHead creatCrossList(int edgenum)
{
	//def_MyAssert(edgenum);
	pCrossListHead crossList = new crossListHead{nullptr, nullptr, 0, edgenum };
	crossList->head_row = new struct str_crosslistHeadRow[600];
	crossList->head_colunm = new struct str_crosslistHeadColumn[600];
	return crossList;
}
void initCrossListHeadNode(pCrossListHead crossList, signed short nodeNum)
{
	crossList->head_row[nodeNum].is_key = false;
	crossList->head_row[nodeNum].known = false;
	crossList->head_row[nodeNum].layer = 0;
	crossList->head_row[nodeNum].outDgree = 0;
	crossList->head_row[nodeNum].next = nullptr;

	crossList->head_colunm[nodeNum].is_key = false;
	crossList->head_colunm[nodeNum].known = false;
	crossList->head_colunm[nodeNum].layer = 0;
	crossList->head_colunm[nodeNum].inDgree = 0;
	crossList->head_colunm[nodeNum].next = nullptr;
}
u_short insertCrossList(pCrossListHead crossList, signed short nodeNum, const u_short startNode, \
	const u_short endNode, u_short cost, const int edgenum)
{
	if (startNode > nodeNum  && endNode > nodeNum)  //increase tow node
	{
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
	}
	else if (startNode > nodeNum  || endNode > nodeNum)  //find just increase one node
	{
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
	}
	pcrossListArc cListArc = new crossListArc{ startNode, endNode, cost, edgenum, nullptr, nullptr };
	//def_MyAssert(cListArc);
	pcrossListArc tmpArc = crossList->head_row[startNode].next;
	crossList->head_row[startNode].next = cListArc;
	cListArc->right = tmpArc;
	++crossList->head_row[startNode].outDgree;

	tmpArc = crossList->head_colunm[endNode].next;
	crossList->head_colunm[endNode].next = cListArc;
	cListArc->down = tmpArc;
	++crossList->head_colunm[endNode].inDgree;
	return nodeNum;
}
void printCrossList(pCrossListHead crosslist, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "headrow " << i << " iskey=" << crosslist->head_row[i].is_key << " outdgree=" << crosslist->head_row[i].outDgree << endl;
	}
	for (int i = 0; i < num; ++i){
		pcrossListArc arc = crosslist->head_row[i].next;
		while (arc){
			cout << "start =" << arc->startNode << " end =" << arc->endNode << " cost =" << arc->Cost \
				<< " edge=" << arc->edgeNumber << endl;
			arc = arc->right;
		}
	}
	cout << "..............................\n";
	for (int i = 0; i < num; i++)
	{
		cout << "headrow " << i << " iskey=" << crosslist->head_colunm[i].is_key << " outdgree=" << crosslist->head_colunm[i].inDgree << endl;
	}
	for (int i = 0; i < num; ++i){
		pcrossListArc arc = crosslist->head_colunm[i].next;
		while (arc){
			cout << "start =" << arc->startNode << " end =" << arc->endNode << " cost =" << arc->Cost \
				<< " edge=" << arc->edgeNumber << endl;
			arc = arc->down;
		}
	}
}


int main()
{
	pCrossListHead crossList = creatCrossList(600);
	signed short nodeNum = -1;
	/*nodeNum = insertCrossList(crossList, nodeNum, 0, 1, 1, 1);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 3, 10, 2);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 2, 18, 3);
	nodeNum = insertCrossList(crossList, nodeNum, 1, 3, 5, 60);
	nodeNum = insertCrossList(crossList, nodeNum, 2, 3, 2, 4);*/
	nodeNum = insertCrossList(crossList, nodeNum, 0, 1, 1, 1);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 2, 18, 3);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 3, 10, 2);
	nodeNum = insertCrossList(crossList, nodeNum, 1, 3, 5, 60);
	nodeNum = insertCrossList(crossList, nodeNum, 2, 3, 2, 4);
	cout << nodeNum << endl;
	printCrossList(crossList, nodeNum+1);
	
	return 0;

}