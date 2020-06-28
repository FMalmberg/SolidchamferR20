#ifndef ADDEDGEPOINT
#define ADDEDGEPOINT

#include "c4d.h"
#include "lib_modeling.h"
#include "lib_ngon.h"

//Insert vertex c on the edge defined by vertices a and b
void AddEdgePoint(C4DAtom* op, Int32 a, Int32 b, Int32 c, Modeling* mod);

#endif