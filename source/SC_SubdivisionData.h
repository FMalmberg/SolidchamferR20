#ifndef SC_SUBDIVISIONDATA_H
#define	SC_SUBDIVISIONDATA_H

#include <vector>
#include "SC_Offsetdata.h"
#include "SC_Edge.h"
#include "SC_EditMesh.h"
#include <map>
#include <set>
using namespace std;

class SC_SubdivisionData{
private:
	vector<int> strips;	 
	vector<int> faces;
	set<Int32> StripBoundary;
	set<Int32> FaceBoundary;
	set<SC_Edge,SC_Edge> OpenEdges;


	PolygonObject* mesh;
	Int32 GetNewEdgeVertex(Int32 a, Int32 b,map<SC_Edge,Int32, SC_Edge> & edgemap, SC_Offsetdata& offset, SC_EditMesh & m);

	bool IsStripBoundary(Int32 vertex_id);
	bool IsFaceBoundary(Int32 vertex_id);

public:
	SC_SubdivisionData(PolygonObject* obj){mesh=obj;}
	void AddStrip(int poly_id);
	void AddFace(int poly_id);
	void Subdivide(SC_Offsetdata& offset);
	void AddStripBoundary(Int32 vertex_id);
	void AddFaceBoundary(Int32 vertex_id);
	void AddOpenEdge(SC_Edge e);
};

#endif