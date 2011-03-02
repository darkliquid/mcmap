#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define VERSION "2.0c"

#include <stdint.h>
#include <cstdlib>
#include <map>
#include <string>

#define UNDEFINED 0x7FFFFFFF

enum Orientation {
	North,
	East,
	South,
	West
};

struct coord {
	int x, y, z;
	
	bool operator()(const coord &a, const coord &b) {
		if (a.z < b.z) {
			return true;
		} else if (a.y < b.y) {
			return true;
		} else if (a.x < b.x) {
			return true;
		} 
		return false;
	}
	
	bool operator < (const coord &loc) {
		if (z < loc.z) {
			return true;
		} else if (y < loc.y) {
			return true;
		} else if (x < loc.x) {
			return true;
		} 
		return false;
	}
	
	bool operator == (const coord &loc) {
		return x == loc.x && y == loc.y && z == loc.z;
	}	
};

// Global area of world being rendered
extern int g_TotalFromChunkX, g_TotalFromChunkZ, g_TotalToChunkX, g_TotalToChunkZ;
// Current area of world being rendered
extern int g_FromChunkX, g_FromChunkZ, g_ToChunkX, g_ToChunkZ;
// size of that area in blocks (no offset)
extern size_t g_MapsizeY, g_MapminY, g_MapsizeZ, g_MapsizeX;

extern int g_OffsetY; // y pixel offset in the final image for one y step in 3d array (2 or 3)

extern bool g_RegionFormat;
extern Orientation g_Orientation; // North, West, South, East
extern bool g_Nightmode;
extern bool g_Underground;
extern bool g_BlendUnderground;
extern bool g_Skylight;
extern int g_Noise;
extern bool g_BlendAll; // If set, do not assume certain blocks (like grass) are always opaque
extern bool g_Hell, g_ServerHell; // rendering the nether
extern bool g_Signs;

// For rendering biome colors properly, external png files are used
extern bool g_UseBiomes;
extern uint64_t g_BiomeMapSize;
extern uint8_t *g_Grasscolor, *g_Leafcolor;
extern uint16_t *g_BiomeMap;
extern int g_GrasscolorDepth, g_FoliageDepth;

// 3D arrays holding terrain/lightmap
extern uint8_t *g_Terrain, *g_Light;
// 2D array to store min and max block height per X/Z - it's 2 bytes per index, upper for highest, lower for lowest (don't ask!)
extern uint16_t *g_HeightMap;
// maps for tile entities, since using an array for variable width data that wont have
// an allocation at every index seems dumb
extern std::map<coord, std::string, coord> TileEntities;

// If output is to be split up (for google maps etc) this contains the path to output to, NULL otherwise
extern char *g_TilePath;

#endif
