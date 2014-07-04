FR-Overworld
===============
![Overworld Viewer](http://i.imgur.com/NLirerI.png)


This is a small module + demo for overworld initiation and camera manipulation in Fire Red. The example in this instance is used as a small overworld viewer with music, and inserts the same as a normal intro. To use this within an intro, call initMap once with the arguments as follows: Bank, Map, Camera_X, Camera_Y. To release the allocated memory from the overworld, call function 080563F0. The overworld code is slightly tweaked to remove entry signs as well as maintain the existing music prior to calling the overworld loader.

To compile, adjust the compile.bat or compile.sh for your .gba's location and insertion location. Next run the appropriate file and the routine will be compiled and automatically inserted at the given address.

Finally, place the pointer to the compiled and inserted binary (+1) at 0x080EC5D0 to complete the hooks.
