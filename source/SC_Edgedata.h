#ifndef SC_EDGEDATA_H
#define	SC_EDGEDATA_H

#include "c4d.h"

class SC_Edgedata{
private:
	Int32 a;
	Int32 b;
	Int32 new_a;
	Int32 new_b;
	bool a_open;
	bool b_open;

public:
	SC_Edgedata();
	SC_Edgedata(Int32 a, Int32 b);

	Int32 GetNew(Int32 v);
	void SetNew(Int32 v, Int32 new_v);
	bool IsOpen(Int32 v);
	void SetIsOpen(Int32 v, bool IsOpen);
};

#endif