#ifndef _TOP_H
#define _TOP_H

#include "iostream"
#include "iomanip"
#include "memory"
#include "cassert"
#include "string"

#define  def_VertexNum  10
#define  def_NoAdjacent  INT_MAX
typedef  int  elemType;

void** creatAdjacentMetric(int vertexNum);

void createAdjacentTable(int vertexNum);


#endif