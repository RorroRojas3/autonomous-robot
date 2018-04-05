#include "slrtappmapping.h"
#include "./maps/electromagnetAndLoadCell.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <electromagnetAndLoadCell> */
		{ /* SignalMapInfo */
			electromagnetAndLoadCell_BIOMAP,
			electromagnetAndLoadCell_LBLMAP,
			electromagnetAndLoadCell_SIDMAP,
			electromagnetAndLoadCell_SBIO,
			electromagnetAndLoadCell_SLBL,
			{0,1},
			2,
		},
		{ /* ParamMapInfo */
			electromagnetAndLoadCell_PTIDSMAP,
			electromagnetAndLoadCell_PTNAMESMAP,
			electromagnetAndLoadCell_SPTMAP,
			{0,15},
			16,
		},
		"electromagnetAndLoadCell",
		"",
		"electromagnetAndLoadCell",
		1,
		electromagnetAndLoadCell_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}