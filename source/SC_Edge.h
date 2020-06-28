#ifndef SC_EDGE_H
#define	SC_EDGE_H

#include "c4d.h"

class SC_Edge{
private:
	Int32 a;
	Int32 b;


public:
	SC_Edge(Int32 v1, Int32 v2);
	SC_Edge();

	Int32 GetFirst();
	Int32 GetSecond();

	bool operator()(const SC_Edge& e1, const SC_Edge& e2) const; //Compare two edges
};


#endif