#include "SC_ToolDialog.h"
#include "SolidChamfer.h"
#include "lib_ngon.h"

Float Radius=5;
Int32 Subdivision=0;
Bool CloseCorners=true;

Bool SC_ToolDialog::CreateLayout(void)
{
	GroupBegin(0,BFH_SCALEFIT,1,0,String(""),0);
	GroupBegin(0,BFH_SCALEFIT,2,0,String(""),0);
	GroupSpace(6,1);

	AddStaticText(0,BFH_LEFT,0,0,String("Subdivision"),0);
	C4DGadget* g1= AddEditNumberArrows(1000,BFH_LEFT);
	AddStaticText(0,BFH_LEFT,0,0,String("Offset"),0);
	C4DGadget* g2= AddEditNumberArrows(1001,BFH_LEFT);
	
	AddStaticText(0,0,0,0,String(""),0);
	AddButton(1003, 0,80, 12, String("Apply"));


	GroupEnd();

	GroupEnd();

	return TRUE;
}

Bool SC_ToolDialog::InitValues(void)
{
	SetInt32(1000,Subdivision,0);
	SetMeter(1001,Radius);
	return TRUE;
}

Int32 SC_ToolDialog::GetSubdivision(){
	return Subdivision;
}

CORNER_STYLE SC_ToolDialog::GetCornerstyle(){
	if(CloseCorners){return CORNER_CLOSED;}
	return CORNER_OPEN;
}

Bool SC_ToolDialog::Command(Int32 id,const BaseContainer &msg)
{
	if(id==1000){
		GetInt32(1000,Subdivision);
		if(Subdivision>6){
			Subdivision=6;
			SetInt32(1000,Subdivision,0);
		}

	}
	if(id==1001){
		GetFloat(1001,Radius);
	}
	if(id==1003){ //Apply


		GetFloat(1001,Radius);
		GetInt32(1000,Subdivision);
		BaseDocument* doc=GetActiveDocument();

		BaseObject* obj=doc->GetActiveObject();
		if(obj==NULL){return TRUE;}
		if (!obj->IsInstanceOf(Opolygon)) return TRUE;

		doc->StartUndo();
		doc->AddUndo(UNDOTYPE::CHANGE,obj);
	
		PolygonObject* mesh = (PolygonObject*)obj;
		BaseSelect* edgeSelection =mesh->GetEdgeS();

		SC_Offsetdata o;
		SC_SubdivisionData sd(mesh);

		SolidChamfer(mesh, edgeSelection, o,sd, GetCornerstyle());

		for(int i=0; i<Subdivision; i++){
			sd.Subdivide(o);
		}

		AutoAlloc<Modeling> mod;
		mod->InitObject(mesh); //Do checks here!

		o.CalculateOffset(mesh, mod, Radius);
		obj->SetDirty(DIRTYFLAGS::DATA);

		mod->Commit();

		doc->EndUndo();	
		EventAdd();
	}
	return TRUE;
}
