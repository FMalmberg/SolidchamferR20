/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2004 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

// Starts the plugin registration

#include "c4d.h"
#include <string.h>

// forward declarations
Bool RegisterSCModifier(void);
Bool RegisterSCTool(void);

Bool PluginStart(void)
{
	
	if (!RegisterSCTool()) return FALSE;
	if (!RegisterSCModifier()) return FALSE;
	
	ApplicationOutput("--SolidChamfer 2.2 for R20, Filip Malmberg 2020--");
	return TRUE;
}

void PluginEnd(void)
{

}

Bool PluginMessage(Int32 id, void *data)
{

	switch (id)
	{
		case C4DPL_INIT_SYS:
			if (!g_resource.Init()) return FALSE; // don't start plugin without resourc
			return TRUE;

	}

	return FALSE;
}
