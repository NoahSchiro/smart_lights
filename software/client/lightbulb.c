#include "lightbulb.h"

/*
Lightbulb will be a LED that has RGB enabled.
Commands simply consist of giving each color a 
value from 0 to 255. 

Off   = [0  , 0  , 0  ]
White = [255, 255, 255]
Red   = [255, 0  , 0  ]
Green = [0  , 255, 0  ]
Blue  = [0  , 0  , 255]
and so on...

!!NOTE!! because we do not yet have access 
to the ESP32, this module will just print 
debug statements
*/
void lbCommand(uint8_t red, uint8_t green, uint8_t blue){
	
	//Edge cases
	if(red == 0 && green == 0 && blue == 0) {
		printf("Lightbulb: off\n");
	}
	else if(red == 255 && green == 255 && blue == 255) {
		printf("Lightbulb: max brightness\n");
	}

	//Main case
	else {
		printf("Lightbulb: RGB[%d, %d, %d]\n", red, green, blue);
	}
}