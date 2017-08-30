# Titan Mod for Urban Terror
Pedrxd and Th3K1ll3r are proud to announce the new Titan Mod completely rewritted. This software aspires to be the best Urban Terror Server Mod never written before, adding a lot of new features in order to give better experiences to players and admins.

The usage of this software is *UNDER YOUR OWN RISK*.

--> Server Mod version: **Titan[MOD]/v3.0**

--> Supported UrT version: **4.2.023** to **4.3.2**

## Features
All features of this Mod will be described below:

### Cvars
Cvar |  Value type  | Description
--- | --- | ---
mod_infiniteStamina | &#60;boolean&#62; | Enable or disable infinite stamina on the server
mod_infiniteWallJumps | &#60;boolean&#62; | Enable or disable infinite walljumps on the server
mod_nofallDamage | &#60;boolean&#62; | Enable or disable damage when falling from a high distance
mod_colourNames | &#60;boolean&#62; | Enable or disable colour names on the scoreboard and chat
mod_playerCount | &#60;integer&#62; | If the integer is positive it will be added to the real count of players. If it is negative, a random number between that value and 1 will be added
mod_mapName | &#60;string&#62; | The specified name will be set to the mapname for UrT searcher. If nothing is set, mapname will be the real one
mod_mapColour | &#60;value&#62; | The color set to mapname is no longer visible on the client's UrT server list, but it makes the server appears at the top (ordering by mapname). Values: 0 -> 9
mod_hideCmds | &#60;value&#62; | Hide commands on chat starting with !, /, @, &. Values: 0 = off, 1 = pm player, 2 = full mute
mod_infiniteAmmo | &#60;boolean&#62; | Enable or disable infinite ammo in any weapon
mod_forceGear | &#60;string&#62; | Force a certain /gear to all clients
mod_checkClientGuid | &#60;boolean&#62; | Validate client's guid when he joins the server
mod_disconnectMsg | &#60;string&#62; | Set a custom 'disconnect' message, displayed when a player leaves the server
mod_badRconMessage | &#60;string&#62; | Set a custom 'bad rconpassword' message, dispayed to a client who introduces a wrong rconpassword
mod_allowTell | &#60;boolean&#62; | Allow /tell command on the server
mod_allowRadio | &#60;boolean&#62; | Allow radio chat on the server
mod_allowWeapDrop | &#60;boolean&#62; | Allow dropping weapons on the server
mod_allowItemDrop | &#60;boolean&#62; | Allow dropping items on the server
mod_allowFlagDrop | &#60;boolean&#62; | Allow dropping the flag on the server
mod_allowSuicide | &#60;boolean&#62; | Allow /kill command on the server
mod_allowVote | &#60;boolean&#62; | Allow /callvote command on the server
mod_allowTeamSelection | &#60;value&#62; | Values: 0 = disable full team selection system, 1 = allow normal team selection, 2 = only allow spec and autojoin, 3 = like 2 + only specs can do autojoin
mod_minKillHealth | &#60;integer&#62; | Set the minimum percent of health necessary to execute /kill command (Range: 0 -> 100)
mod_minTeamChangeHealth | &#60;integer&#62; | Set the minimum percent of health necessary to execute /team command (Range: 0 -> 100)
mod_enableHealth | &#60;boolean&#62; | Enable or disable auto health features
mod_timeoutHealth | &#60;integer&#62; | Delay between each 'addAmountOfHealth' (in milliseconds)
mod_limitHealth | &#60;integer&#62; | Maximum percent of health that can be reached with auto health function (Range: 0 -> 100)
mod_addAmountOfHealth | &#60;integer&#62; | Percentatge of health that auto health function will add to the player (Range: 0 -> 100)
mod_whenMoveHealth | &#60;boolean&#62; | Enable or disable auto health when the player is moving
&#60;team&#62;_giveweapon | &#60;weapon1&#62; &#60;weapon2&#62; ... | When a player spawns, the weapons specified will be given to him
&#60;team&#62;_takeweapon | &#60;weapon1&#62; &#60;weapon2&#62; ... | When a player spawns, the weapons specified will be removed from him
&#60;team&#62;_giveitem | &#60;item1&#62; &#60;item2&#62; ... | When a player spawns, the items specified will be given to him
&#60;team&#62;_takeitem | &#60;item1&#62; &#60;item2&#62; ... | When a player spawns, the items specified will be removed from him
&#60;weapon&#62;_clips | &#60;integer&#62; | Change the number of clips of a weapon (Range: 0 -> 255)
&#60;weapon&#62;_bullets | &#60;integer&#62; | Change the number of bullets of a weapon (Range: 0 -> 255)
&#60;weapon&#62;_knockback | &#60;integer&#62; | Change the knockback power of a weapon (Range: 0 -> 200)
&#60;weapon&#62;_reloadspeed | &#60;integer&#62; | Change the reload speed of a weapon (WARNING: it can lead to bug the weapon)
&#60;weapon&#62;_damagesfactor | &#60;factor&#62; | Change all the damages that a weapon produces (NOTE: realDamage * factor = modificatedDamage)
&#60;weapon&#62;&#95;damages&#95;&#60;hitlocation&#62; | &#60;decimal&#62; | Change a weapon damage on a specified hitlocation (Format: 0.X where X is the damage the weapon produces)
&#60;weapon&#62;&#95;bleed&#95;&#60;hitlocation&#62; | &#60;boolean&#62; | Enable or disable the bleed produced by a weapon on a specified hitlocation
&#60;weapon&#62;&#95;&#60;modeID&#62;&#95;firetime | &#60;integer&#62; | Change the firetime of a weapon mode
&#60;weapon&#62;&#95;&#60;modeID&#62;&#95;norecoil | &#60;boolean&#62; | Enable or disable the recoil of a weapon mode

#### Variables
##### Teams
> free | red | blue | spec

##### Hit locations
> unknown | head | helmet | torso | vest | arml | armr | groin | butt | legul | legur | legll | leglr | footl | footr

##### ModeID
> 1 = first mode | 2 = second mode | 3 = third mode

##### Weapons
###### 4.2
> knife | beretta | deagle | spas12 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | bomb | negev | m4 | glock | colt | mac11 | boot | knifefly

###### 4.3
> knife | beretta | deagle | spas12 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | bomb | negev | m4 | glock | colt | mac11 | frf1 | benelli | p90 | magnum | fstod | boot | knifefly

##### Items
> redflag | blueflag | vest | nvg | silencer | laser | medkit | helmet | ammo

### Commands (Rcon)
Command | Syntax | Description
--- | --- | ---
setscore | &#60;player&#62; &#60;value&#62; | Set a certain score to a player on the scoreboard of the game
setdeaths | &#60;player&#62; &#60;value&#62; | Set a certain deaths to a player on the scoreboard of the game
invisible | &#60;player&#62; | Turn (ON/OFF) the invisible mode of a player
playsound | &#60;player&#62; &#60;index&#62; | Play a sound that is on the index of client's configstrings
playsoundfile | &#60;player&#62; &#60;file&#62; | Play a sound that is on the pk3 files of client's game folder. Must specify the path to the file (sound(s)/.../file.wav)
giveweapon / gw | &#60;player&#62; &#60;weapon&#62; | Give a weapon to a player
removeweapon / rw | &#60;player&#62; &#60;weapon&#62; | Remove a weapon from a player
giveitem / gi | &#60;player&#62; &#60;item&#62; | Give an item to a player
removeitem / ri | &#60;player&#62; &#60;item&#62; | Remove an item from a player
giveclips | &#60;player&#62; &#60;value&#62; | Add clips to the current weapon of a player
givebullets | &#60;player&#62; &#60;value&#62; | Add bullets to the current weapon of a player
setclips | &#60;player&#62; &#60;value&#62; | Set clips to the current weapon of a player
setbullets | &#60;player&#62; &#60;value&#62; | Set bullets to the current weapon of a player
addhealth | &#60;player&#62; &#60;value&#62; | Add health to a player
sethealth | &#60;player&#62; &#60;value&#62; | Set health to a player
autohealth | &#60;player&#62; &#60;limit&#62; &#60;moving&#62; &#60;step&#62; &#60;timeout&#62; &#60;turnoffwhenfinish&#62; | Set auto health to an exclusive client
teleport / tp | &#60;player1&#62; &#60;player2&#62; or &#60;player&#62; &#60;x&#62; &#60;y&#62; &#60;z&#62; | Teleport a player to another one or teleport a player to the specified coordinates
resquestdownload | &#60;player&#62; &#60;file&#62; | Resquest a client the download of a pk3 file (NOTE: put the filename without extension)
location | &#60;player/all&#62; &#60;string&#62; &#60;index&#62; &#60;lock&#62; | Change location names of a player (NOTE: 'index' is the space where location will be saved and 'lock' if it should be static)
weaponoffset | &#60;weapon&#62; | Dump on weaponoff.txt all the data about a weapon
qvmreload | - | Apply the modifications of the weapons settings using the cvars (NOTE: a map restart or a map reload will do the same action)

### Commands (Client)
Command | Syntax | Description
--- | --- | ---

## INFO
Extra information:

### Build on Linux (Debian / Ubuntu)
#### Linux binaries
> apt-get install make gcc libsdl-dev

> make

#### Windows binaries
> apt-get install mingw-w64 binutils-mingw-w64 libc6-dev-i386

> make PLATFORM=mingw32 ARCH=x86 CC=i686-w64-mingw32-gcc LD=i686-w64-mingw32-ld WINDRES=i686-w64-mingw32-windres
