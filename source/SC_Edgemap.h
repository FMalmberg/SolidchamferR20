// A wrapper around std:map, for easier syntax when handling edges

#ifndef SC_EDGEMAP
#define SC_EDGEMAP

#include "c4d.h"
#include "SC_Edge.h"
#include "SC_Edgedata.h"
#include <map>
using namespace std;

class SC_Edgemap{
private:
	map<SC_Edge, SC_Edgedata, SC_Edge> m;
public:
	void insert(Int32 v1, Int32 v2);
	int size();
	SC_Edgedata& operator()(Int32 v1, Int32 v2);
	bool find(Int32 v1, Int32 v2);
};

#endif