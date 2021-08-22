/*map*/
#define map_x 30
#define map_y 25

/*debug*/

//#define debug 1

/*東南西北*/

#define N 1 //北
#define S 3 //南
#define W 4 //西
#define E 2 //東

/*speed*/
#define level1 220
#define level2 100
#define level3 50
#define final 25

struct point
{
	int x;
	int y;
	int direct;
};
