#ifndef _COLORS_
#define _COLORS_

#include "helper.h"
#include <cmath>

// Byte order see below. Colors aligned to word boundaries for some speedup
// Brightness is precalculated to speed up calculations later
// Colors are stored twice since BMP and PNG need them in different order
// Noise is supposed to look normal when -noise 10 is given
extern uint8_t colors[256][8];
#define PRED 0
#define PGREEN 1
#define PBLUE 2
#define PALPHA 3
#define NOISE 4
#define BRIGHTNESS 5

#define GETBRIGHTNESS(c) (uint8_t)sqrt( \
                                        double(PRED[c]) *  double(PRED[c]) * .236 + \
                                        double(PGREEN[c]) *  double(PGREEN[c]) * .601 + \
                                        double(PBLUE[c]) *  double(PBLUE[c]) * .163)

void loadColors();
bool loadColorsFromFile(const char *file);
bool dumpColorsToFile(const char *file);
bool extractColors(const char *file);
bool loadBiomeColors(const char* path);

#define AIR 0
#define STONE 1
#define GRASS 2
#define DIRT 3
#define COBBLESTONE 4
#define WOOD 5
#define WATER 8
#define STAT_WATER 9
#define LAVA 10
#define STAT_LAVA 11
#define SAND 12
#define GRAVEL 13
#define LOG 17
#define LEAVES 18
#define SANDSTONE 24
#define BED 26
#define WOOL 35
#define FLOWERY 37
#define FLOWERR 38
#define MUSHROOMB 39
#define MUSHROOMR 40
#define DOUBLESTEP 43
#define STEP 44
#define TORCH 50
#define FIRE 51
#define REDWIRE 55
#define RAILROAD 66
#define REDTORCH_OFF 75
#define REDTORCH_ON 76
#define SNOW 78
#define FENCE 85
#define CAKE 92
#define SANDSTEP 233
#define WOODSTEP 234
#define COBBLESTEP 235
#define PINELEAVES 236
#define BIRCHLEAVES 237
#define SIGN 63
#define WALLSIGN 68
//#define VOIDBLOCK 255 // This will hopefully never be a valid block id in the near future :-)

#endif
