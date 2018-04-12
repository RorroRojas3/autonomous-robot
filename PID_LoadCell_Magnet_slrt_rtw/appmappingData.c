#include "slrtappmapping.h"
#include "./maps/PID_LoadCell_Magnet.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <PID_LoadCell_Magnet> */
		{ /* SignalMapInfo */
			PID_LoadCell_Magnet_BIOMAP,
			PID_LoadCell_Magnet_LBLMAP,
			PID_LoadCell_Magnet_SIDMAP,
			PID_LoadCell_Magnet_SBIO,
			PID_LoadCell_Magnet_SLBL,
			{0,23},
			21,
		},
		{ /* ParamMapInfo */
			PID_LoadCell_Magnet_PTIDSMAP,
			PID_LoadCell_Magnet_PTNAMESMAP,
			PID_LoadCell_Magnet_SPTMAP,
			{0,47},
			48,
		},
		"PID_LoadCell_Magnet",
		"",
		"PID_LoadCell_Magnet",
		1,
		PID_LoadCell_Magnet_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}