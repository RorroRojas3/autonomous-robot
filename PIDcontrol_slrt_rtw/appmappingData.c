#include "slrtappmapping.h"
#include "./maps/PIDcontrol.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <PIDcontrol> */
		{ /* SignalMapInfo */
			PIDcontrol_BIOMAP,
			PIDcontrol_LBLMAP,
			PIDcontrol_SIDMAP,
			PIDcontrol_SBIO,
			PIDcontrol_SLBL,
			{0,25},
			24,
		},
		{ /* ParamMapInfo */
			PIDcontrol_PTIDSMAP,
			PIDcontrol_PTNAMESMAP,
			PIDcontrol_SPTMAP,
			{0,38},
			39,
		},
		"PIDcontrol",
		"",
		"PIDcontrol",
		1,
		PIDcontrol_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}