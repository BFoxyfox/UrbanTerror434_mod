# Titan Mod for UrT
Th3K1ll3r and Pedrxd are proud to announce the new TitanMod completly rewritted. This software aspires to be the BEST UrbanTerror Server Mod never written before, adding a lot of new features in order to give better experiences to players and admins.

The usage of this software is *UNDER YOUR OWN RISK*.

--> Server Mod version: **Titan[MOD]/v3**

--> Supported UrT version: **4.3.2**

## Features
All features of this Mod will be described below:

### Cvars
Cvar |  Value  | Description
--- | --- | ---
mod&#95;infiniteStamina | On / Off | Disable stamina on the server
mod&#95;infiniteWallJumps | On / Off | Allow infinite jums cross walls
mod&#95;noFallDamage | On / Off | Dont get damage when fall from high distance
mod&#95;colourNames | On / Off | Enable colour names on the scoreboard
mod&#95;playerCount | number | If the int is positive, will be added to the real count of player, if is negative a random number beetween value to 1 will be added
mod&#95;mapName | string | The specified name will be set to the mapname for UrT searcher, if nothing set will be the real one.
mod_mapColour | &#60;value&#62; | The color set to mapname is no longer visible on the client's UrT server list, but it makes the server appears at the top. Values: 0-9
mod&#95;hidecmds | value | Used for mute commands on chat starting with !, /, @, &. Where value 0 = off, 1 = pm player, 2 = full mute.
mod&#95;infiniteAmmo | On / Off | When a player shot, no bullet will be spend .
mod_forceGear | &#60;value&#62; | Force a certain /gear to all clients
mod_checkClientGuid | On / Off | Validate client's guids when they join the server
mod_disconnectMsg | &#60;string&#62; | Set a custom 'disconnect' message, displayed when a player leaves the server
mod_badRconMessage | &#60;string&#62; | Set a custom 'bad rconpassword' message, dispayed to a client who introduces a wrong rconpassword
mod_allowTell | On / Off | Allow /tell command on the server
mod_allowRadio | On / Off | Allow radio chat on the server
mod_allowWeapDrop | On / Off | Allow dropping weapons on the server
mod_allowItemDrop | On / Off | Allow dropping items on the server
mod_allowFlagDrop | On / Off | Allow dropping the flag on the server
mod_allowSuicide | On / Off | Allow /kill command on the server
mod_allowVote | On / Off | Allow /callvote command on the server
mod_allowTeamSelection | Mode | 1: Allow normal team selection; 2:Only work spec and autojoin; 3:Like 2 + only specs can do autojoin 0:Nothing work;
&#60;team&#62;&#95;giveweapon | &#60;"string of weapons"&#62; | When a player spawn, the weapons specified will be gived to the player
&#60;team&#62;&#95;takeweapon | &#60;"string of weapons"&#62; | When a player spawn, the weapons specified will be removed to the player
&#60;weapon&#62;&#95;clips | number | Modificate the number of clips that a weapon should have
&#60;weapon&#62;&#95;bullets | number | Modificate the number of bullets that a weapon should have
&#60;weapon&#62;&#95;knockback | number | Change the power of knockback
&#60;weapon&#62;&#95;reloadspeed | number | Change the speed of reloadspeed. Can handle to bug weapons! We recommend not to use it yet
&#60;weapon&#62;&#95;damagesfactor | factor | Change all the damages that a weapon produced. Using this expresion realDamage * factor = modificatedDamage
&#60;weapon&#62;&#95;damages&#95;&#60;hitlocation&#62; | damage | Should be a decimal number. 0.X where X is the damage that give the weapon
&#60;weapon&#62;&#95;bleed&#95;&#60;hitlocation&#62; | On / Off | Activate or desactivate the bleed produced by a weapon.

#### Variables
##### Team
> free | red | blue | spec

##### Hit location
> unknown | head | helmet | torso | vest | arml | armr | groin | butt | legul | legur | legll | leglr | footl | footr

##### Mode
The mode where should affect the modification.

##### Weapons
###### 4.2
>  knife | beretta | deagle | spas12 | mp5k | ump45 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | neveg | m4 | glock | colt | mac11 | boot | knifefly

###### 4.3
>  knife | beretta | deagle | spas12 | mp5k | ump45 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | neveg | m4 | glock | colt | mac11 | frf1 | benelli | p90 | magnum | fstod | boot | knifefly

### Commands (Rcon)
Command | Syntax | Description
--- | --- | ---
setscore | &#60;player&#62; &#60;score&#62; | Set a certain score to a player on the scoreboard of the game
setdeaths | &#60;player&#62; &#60;deaths&#62; | Set a certain deaths to a player on the scoreboard of the game
invisible | &#60;player&#62; | Turn invisible mode (On/Off) of a player
playsound | &#60;player&#62; &#60;index&#62; | Play a sound that is on the index of client's configstrings
playsoundfile | &#60;player&#62; &#60;file&#62; | Play a sound that is on the pk3 files of client's game folder. Must specify the path to the file (sound(s)/... file.wav)
giveweapon / gw | &#60;player&#62; &#60;weapon&#62; | Give a weapon to a player
removeweapon / rw | &#60;player&#62; &#60;weapon&#62; | Remove a weapon to a player
giveclips | &#60;player&#62; &#60;clips&#62; | Add clips to the current weapon of player
givebullets | &#60;player&#62; &#60;bullets&#62; | Add bullets to the current weapon of player
setclips | &#60;player&#62; &#60;clips&#62; | Set clips to the current weapon of player
setbullets | &#60;player&#62; &#60;bullets&#62; | Set bullets to the current weapon of player
teleport | &#60;player&#62; &#60;playerto&#62; *OR* &#60;x&#62; &#60;y&#62; &#60;z&#62; | This command allow two type of teleport, to a player or to a coordinates.
qvmreload | nothing | This command will apply the modifications on the weapons using the cvar, a map change or restart will do the same action.

## INFO
