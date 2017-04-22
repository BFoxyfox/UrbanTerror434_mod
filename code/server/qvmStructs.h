/*
 * qvmStructs.h
 *
 *  Created on: 28 feb. 2017
 *      Author: pedro
 */

#ifndef CODE_SERVER_QVMSTRUCTS_H_
#define CODE_SERVER_QVMSTRUCTS_H_

typedef enum {
	UT_ITEM_NONE,

	UT_ITEM_REDFLAG,
	UT_ITEM_BLUEFLAG,
	UT_ITEM_NEUTRALFLAG,

	UT_ITEM_KNIFE,		   // E
	UT_ITEM_BERETTA,	   // F
	UT_ITEM_DEAGLE, 	   // G
	UT_ITEM_SPAS12, 	   // H
	UT_ITEM_MP5K,		   // I
	UT_ITEM_UMP45,		   // J
	UT_ITEM_HK69,		   // K
	UT_ITEM_LR, 		   // L
	UT_ITEM_G36,		   // M
	UT_ITEM_PSG1,		   // N

	UT_ITEM_GRENADE_HE,    // O
	UT_ITEM_GRENADE_FLASH,
	UT_ITEM_GRENADE_SMOKE, // Q

	UT_ITEM_VEST,		   // R
	UT_ITEM_NVG,		   // S
	UT_ITEM_MEDKIT, 	   // T
	UT_ITEM_SILENCER,	   // U
	UT_ITEM_LASER,		   // V
	UT_ITEM_HELMET, 	   // W
	UT_ITEM_AMMO,		   // X
	UT_ITEM_APR,		   // Y

	UT_ITEM_SR8,		   // Z

	UT_ITEM_AK103,		   // a
	UT_ITEM_BOMB,		   // b
	UT_ITEM_NEGEV,		   // c
	UT_ITEM_GRENADE_FRAG,  // d
	UT_ITEM_M4, 		   // e
	UT_ITEM_GLOCK,		   // f
	UT_ITEM_COLT1911,      // g
	UT_ITEM_MAC11,         // h
	UT_ITEM_FRF1,
	UT_ITEM_BENELLI,
	UT_ITEM_P90,
	UT_ITEM_MAGNUM,
	UT_ITEM_FSTOD,

	UT_ITEM_MAX,

	UT_ITEM_C4,
} utItemID_t;

enum weaponOffsetStructure
{
	OFFSET_BASE,
	OFFSET_CLIPS,
	OFFSET_BULLETS,
	OFFSET_DAMAGES,
	OFFSET_BLEED,
	OFFSET_KNOCKBACK,
	OFFSET_RELOADSPEED,
	OFFSET_FIRETIME,
	OFFSET_NORECOIL,
	OFFSET_WPFLAG,
	SIZE,
	OFFSET_WP_MAX
};
enum gclientOffsetStructure
{
	OFFSET_NOGEARCHANGE,
	OFFSET_TEAM,
	OFFSET_GL_MAX
};

typedef enum
{
	vunk,
	v42023,
	v43,
	v431,
	v432,
	vMAX,
}urtVersion;

extern const char versionString[vMAX][10];
extern char (*weaponString)[15];
extern char itemString[UT_ITEM_MAX][10];
extern char teamstring[4][5];
extern char hitlocationstring[HL_MAX][15];

extern int ut_weapon_xor;
extern int gclientOffsets[vMAX][OFFSET_GL_MAX];



#define MAX_NETNAME 36
typedef struct
{
	int	connected;
	usercmd_t	cmd;
	qboolean unknow1;
	qboolean unknow2;
	char		netname[MAX_NETNAME];
}clientPersistant_t;

typedef struct gentity_s
{
	int unknow[171];
	int health;
}gentity_t;

typedef struct gclient_s
{
	playerState_t ps;
	clientPersistant_t pers;
}gclient_t;


#endif /* CODE_SERVER_QVMSTRUCTS_H_ */
