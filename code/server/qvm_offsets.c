/*
 *
 *	Ultimate modding by pedrxd
 *
 */

#include "server.h"

int   gclientOffsets[vMAX][OFFSET_GL_MAX] =
{
		[v42023] = 	{ 3820, 2828},
		[v43] = 	{ 4328, 3352},
		[v431] = 	{ 4328, 3352},
		[v432] = 	{ 4328, 3352}
};
int   weaponOffsets[vMAX][OFFSET_WP_MAX] =
{
		//version    0     1   2   3   4   5    6   7    8    9   10
		[v42023] = {8256, 28, 32, 48, 52, 172, 36, 232, 228,  8, 432},
		[v43] =    {8649, 31, 35, 51, 55, 175, 39, 235, 228, 11, 432},
		[v431] =   {4365, 31, 35, 51, 55, 175, 39, 235, 228, 11, 432},
		[v432] =   {4393, 31, 35, 51, 55, 175, 39, 235, 228, 11, 432}
};


void *QVM_baseWeapon(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
	                  weapon*weaponOffsets[getVersion()][SIZE]));
}
void *QVM_clips(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_CLIPS] +
			          weapon*weaponOffsets[getVersion()][SIZE]));
}
void *QVM_bullets(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_BULLETS] +
			          weapon*weaponOffsets[getVersion()][SIZE]));
}
void *QVM_damages(weapon_t weapon , ariesHitLocation_t location)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_DAMAGES] +
			          weapon*weaponOffsets[getVersion()][SIZE]+
			          location*8));
}
void *QVM_bleed(weapon_t weapon,  ariesHitLocation_t location)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_BLEED] +
			          weapon*weaponOffsets[getVersion()][SIZE]+
			          location*8));
}
void *QVM_knockback(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_KNOCKBACK] +
			          weapon*weaponOffsets[getVersion()][SIZE]));
}
void *QVM_reloadSpeed(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_RELOADSPEED] +
			          weapon*weaponOffsets[getVersion()][SIZE]));
}
void *QVM_fireTime(weapon_t weapon, int mode)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_FIRETIME] +
			          weapon*weaponOffsets[getVersion()][SIZE]+
			          mode*52));
}
void *QVM_noRecoil(weapon_t weapon, int mode)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_NORECOIL] +
			          weapon*weaponOffsets[getVersion()][SIZE] +
			          mode*52));
}
void *QVM_WPflags(weapon_t weapon)
{
	weapon-=1;
	if(getVersion() == vunk || ( weapon < 0 || UT_WP_NUM_WEAPONS+3 < weapon ))
		return NULL;
	return VM_ArgPtr((weaponOffsets[getVersion()][OFFSET_BASE] +
			          weaponOffsets[getVersion()][OFFSET_WPFLAG] +
			          weapon*weaponOffsets[getVersion()][SIZE]));
}

int overrideQVMData(void)
{
	weapon_t weapon;
	int i;

	if(getVersion()==vunk)
		return 0;
	for(weapon = UT_WP_KNIFE; weapon < (UT_WP_NUM_WEAPONS + 3); weapon++)
	{
		//Check one by one all cvar that can contains some data for changes weapons
		if(Q_stricmp(Cvar_VariableString(va("%s_clips", weaponString[weapon])), ""))
		{
			*(int*)QVM_clips(weapon) = Cvar_VariableIntegerValue(va("%s_clips", weaponString[weapon]));
		}
		if(Q_stricmp(Cvar_VariableString(va("%s_bullets", weaponString[weapon])), ""))
		{
			*(int*)QVM_bullets(weapon) = Cvar_VariableIntegerValue(va("%s_bullets", weaponString[weapon]));
		}
		if(Q_stricmp(Cvar_VariableString(va("%s_knockback", weaponString[weapon])), ""))
		{
			*(float*)QVM_knockback(weapon) = Cvar_VariableValue(va("%s_knockback", weaponString[weapon]));
		}
		if(Q_stricmp(Cvar_VariableString(va("%s_reloadspeed", weaponString[weapon])), ""))
		{
			*(float*)QVM_reloadSpeed(weapon) = Cvar_VariableValue(va("%s_reloadspeed", weaponString[weapon]));
		}
		if(Q_stricmp(Cvar_VariableString(va("%s_damagesfactor", weaponString[weapon])), ""))
		{
			for(i=0;i<HL_MAX;i++)
			{
				*(float*)QVM_damages(weapon,i)*=Cvar_VariableValue(va("%s_damagesfactor", weaponString[weapon]));
			}
		}

		//Now check strings that have more values than only the name
		for(i=0; i<HL_MAX; i++)
		{
			if(Q_stricmp(Cvar_VariableString(va("%s_damages_%s", weaponString[weapon], hitlocationstring[i])), ""))
			{
				*(float*)QVM_damages(weapon,i) = Cvar_VariableValue(va("%s_damages_%s", weaponString[weapon], hitlocationstring[i]));
			}
			if(Q_stricmp(Cvar_VariableString(va("%s_bleed_%s", weaponString[weapon], hitlocationstring[i])), ""))
			{
				*(float*)QVM_bleed(weapon,i) = 1;
			}

		}
		for(i=0; i<3; i++)
		{
			if(Q_stricmp(Cvar_VariableString(va("%s_%i_firetime", weaponString[weapon], i)), ""))
			{
				*(int*)QVM_fireTime(weapon,i) = Cvar_VariableIntegerValue(va("%s_%i_firetime", weaponString[weapon], i));
			}
			if(Q_stricmp(Cvar_VariableString(va("%s_%i_norecoil", weaponString[weapon], i)), ""))
			{
				*(int*)QVM_noRecoil(weapon,i) |= UT_WPMODEFLAG_NORECOIL;
			}
		}
	}
	return 1;
}
