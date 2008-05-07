
//{{BLOCK(level2)

//======================================================================
//
//	level2, 256x1024@8, 
//	+ palette 256 entries, not compressed
//	+ 1996 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x128 
//	Total size: 512 + 127744 + 8192 = 136448
//
//	Time-stamp: 2008-04-24, 17:53:35
//	Exported by Cearn's GBA Image Transmogrifier
//	( http://www.coranac.com )
//
//======================================================================

#ifndef __LEVEL2__
#define __LEVEL2__

#define level2PalLen 512
extern const unsigned short level2Pal[256];

#define level2TilesLen 127744
extern const unsigned short level2Tiles[63872];

#define level2MapLen 8192
extern const unsigned short level2Map[4096];

#endif // __LEVEL2__

//}}BLOCK(level2)
