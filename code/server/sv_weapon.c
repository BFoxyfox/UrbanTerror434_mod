/*
 * game_weapon.c
 *
 *  Created on: 19 feb. 2017
 *      Author: pedro
 */

#include "server.h"

void updateXOR(playerState_t *ps)
{
	ut_weapon_xor = ps->powerups[MAX_POWERUPS-1];
}
int SV_LastWeaponNum(playerState_t * ps)
{
	int i, last = 0;
	for(i = 0; i < MAX_POWERUPS; i++)
	{
		ut_weapon_xor = ps->powerups[(MAX_POWERUPS - 1)];
		if(UT_WEAPON_GETID(ps->powerups[i]) != UT_WP_NONE)
		{
			last++;
		}
	}
	if(last < 0) last = 1;
	return last-1;
}
weapon_t SV_Char2Weapon(char weapon[36])
{
	int i;
	for ( i = 0; i < (UT_WP_NUM_WEAPONS + 3); i++ ) {
		if ( Q_stricmp( weaponString[i], weapon ) == 0) {
			return i;
		}
	}
	return 0;
}
int  generateWeapon(playerState_t *ps, int clips, int mode, int bullet, int weapon)
{
	updateXOR(ps);
	int powerup;
	UT_WEAPON_SETBULLETS(powerup, bullet);
	UT_WEAPON_SETCLIPS(powerup, clips);
	UT_WEAPON_SETMODE(powerup, mode);
	UT_WEAPON_SETID(powerup, weapon);

	return powerup;
}
void SV_GiveBulletsAW(playerState_t *ps, int bulletsCount)
{
	int bullets = UT_WEAPON_GETBULLETS(ps->powerups[ps->weapon]);
	bullets += bulletsCount;
	UT_WEAPON_SETBULLETS(ps->powerups[ps->weapon], bullets);
}
void SV_GiveClipsAW(playerState_t *ps, int clipsCount)
{
	updateXOR(ps);
	int clips = UT_WEAPON_GETCLIPS(ps->powerups[ps->weapon]);
	clips += clipsCount;
	UT_WEAPON_SETCLIPS(ps->powerups[ps->weapon], clips);
}
void SV_SetBulletsAW(playerState_t *ps, int bulletsCount)
{
	updateXOR(ps);
	UT_WEAPON_SETBULLETS(ps->powerups[ps->weapon], bulletsCount);
}
void SV_SetClipsAW(playerState_t *ps, int clipsCount)
{
	updateXOR(ps);
	UT_WEAPON_SETCLIPS(ps->powerups[ps->weapon], clipsCount);
}
void SV_GiveWeapon(playerState_t *ps, weapon_t wp)
{
	int i;
	for(i = 0; i < (MAX_POWERUPS - 1); i++)
	{
		if(i == 15)
		{
			Com_Printf("No space\n");
			return;
		}
		if(ps->powerups[i] == ps->powerups[(MAX_POWERUPS - 1)])
		{
                    int mode;
                    mode = Info_ValueForKey(svs.clients[ps->clientNum].userinfo, "weapmodes")[wp] - '0';
                    if(mode > 2)
                        mode = 0;
                    ps->powerups[i] = generateWeapon(ps, *(int*)QVM_clips(wp), mode, *(int*)QVM_bullets(wp),wp);
                    break;
		}
	}
}
void SV_RemoveWeapon(playerState_t *ps, weapon_t wp)
{
	int i;

	updateXOR(ps);
	for(i = 0; i < MAX_POWERUPS; i++)
	{
		if(ps->powerups[i] != ps->powerups[(MAX_POWERUPS - 1)])
		{
			if(UT_WEAPON_GETID(ps->powerups[i]) == wp)
			{
				ps->powerups[i] = ps->powerups[(MAX_POWERUPS - 1)];
			}
		}
	}
	ps->weapon = SV_LastWeaponNum(ps);
}
void SV_AutoRemove(playerState_t *ps)
{
	int i;
	team_t team = *(int*)((byte*)ps+gclientOffsets[getVersion()][OFFSET_TEAM]);
	if(team == TEAM_SPECTATOR)
		return;

	if(strlen(Cvar_VariableString(va("%s_takeweapon", teamstring[team]))))
	{
		Cmd_TokenizeString(Cvar_VariableString(va("%s_takeweapon", teamstring[team])));
		for(i = 0; i < Cmd_Argc(); i++)
		{
			SV_RemoveWeapon(ps, SV_Char2Weapon(Cmd_Argv(i)));
		}
	}
}
void SV_AutoGive(playerState_t *ps)
{
	int i;
	team_t team = *(int*)((byte*)ps+gclientOffsets[getVersion()][OFFSET_TEAM]);

	if(team == TEAM_SPECTATOR)
		return;

	if(strlen(Cvar_VariableString(va("%s_giveweapon", teamstring[team]))))
	{
		Cmd_TokenizeString(Cvar_VariableString(va("%s_giveweapon", teamstring[team])));
		for(i = 0; i < Cmd_Argc(); i++)
		{
			SV_GiveWeapon(ps, SV_Char2Weapon(Cmd_Argv(i)));
		}
	}
}

void SV_WeaponMod(int cnum)
{
    playerState_t *ps;
    ps = SV_GameClientNum(cnum);
    if(*(int *)(((byte*)ps)+gclientOffsets[getVersion()][OFFSET_NOGEARCHANGE]))
    {
        return;
    }
    SV_AutoRemove(ps);
    SV_AutoGive(ps);
    ps->weapon = SV_LastWeaponNum(ps);
}
