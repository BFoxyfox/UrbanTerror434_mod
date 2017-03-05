# Titan Mod for UrT >= 4.2.023
TheK1ll3r and Pedrxd are proud to announce the new TitanMod completly rewritted. This software aspired to be the BEST urbanterror mod never writted before adding lot of new features for add better experiences to players and admins.

The usage of this software is **UNDER YOUR OWN RISK**.

## Features:
All features of this mod will be described below:
### Cvar
Cvar |  Value  | Description
--- | --- | ---
mod&#95;infiniteStamina | On / Off | Disable stamina on the server
mod&#95;infiniteWallJumps | On / Off | Allow infinite jums cross walls
mod&#95;noFallDamage | On / Off | Dont get damage when fall from high distance
mod&#95;colourNames | On / Off | Enable colour names on the scoreboard
mod&#95;playerCount | number | If the int is positive, will be added to the real count of player, if is negative a random number beetween value to 1 will be added
mod&#95;mapName | string | The specified name will be set to the mapname for UrT searcher, if nothing set will be the real one.
mod&#95;hidecmds | value | Used for mute commands on chat starting with !, /, @, &. Where value 0 = off, 1 = pm player, 2 = full mute.
mod&#95;infiniteAmmo | On / Off | When a player shot, no bullet will be spend .
mod&#95;allowTell | On / Off | Allow tell on the server
mod&#95;allowItemDrop | On / Off | Allow drop items on the server
mod&#95;allowWeapDrop | On / Off | Allow drop weapons on the server
mod&#95;allowFlagDrop | On / Off | Allow drop flag on the server
mod&#95;allowSuicide | On / Off | Allow /kill command on the server
mod&#95;allowRadio | On / Off | Allow the usage of radio on the server
mod&#95;allowChat | On / Off | Allow the usage of chat on the server
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
Is the mode of the weapon where should affect the modification.

##### Weapons
###### 4.2
>  knife | beretta | deagle | spas12 | mp5k | ump45 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | neveg | m4 | glock | colt | mac11 | boot | knifefly

###### 4.3
>  knife | beretta | deagle | spas12 | mp5k | ump45 | mp5k | ump45 | hk69 | lr | g36 | psg1 | he | flash | smoke | sr8 | ak103 | neveg | m4 | glock | colt | mac11 | frf1 | benelli | p90 | magnum | fstod | boot | knifefly

### Commands
Commands | Syntax | Description
--- | --- | ---
setscore |  &#60;player&#62;  &#60;score&#62; | Will set &#60;score&#62; to the scoreboard of the game
setdeaths |  &#60;player&#62;  &#60;deaths&#62; | Will set &#60;deaths&#62; to the scoreboard of the game
invisible | &#60;player&#62; | Switch between invisible or not to &#60;player&#62;
playsound | &#60;player&#62; &#60;index&#62; | Will play a sound that is on the &#60;index&#62; of her configstring .
playsoundfile | &#60;player&#62; &#60;file&#62; | Will play a sound that is on the pk3 files of her computer on the path &#60;file&#62;
giveweapon / gw | &#60;player&#62; &#60;weapon&#62; | Give a weapon to a player
removeweapon / rw | &#60;player&#62; &#60;weapon&#62; | Remove a weapon to a player
qvmreload | nothing | This command will apply the modifications on the weapons using the cvar, a map change or restart will do the same action.

## Build
First of all download dependences: For **Ubuntu**
```
sudo apt-get install make gcc libsdl-dev
```
And compile it:
```
make
```
You can use -jn where n is Number of Threads for speed up compilation.
Binary files are placed on the build folder.

## Installation
First of all, you should compile the mod .
### Windows
If you want the **dedicated server** take the file 'Quake3-UrT-Ded.exe' and replaced it on the UrbanTerror folder, execute it as normal.

For **client version** take 'Quake3-UrT.exe' and replaced it on the UrbanTerror folder, execute it as normal.

### Linux
If you want the **dedicated server** take the file named 'Quake3-UrT-Ded.i386/x86&#95;64'¹ and replaced it on the UrbanTerror folder, execute it as normal.

For **client version** take 'Quake3-UrT.i386/x86&#95;64'¹ and replaced it on the UrbanTerror folder, execute it as normal.

 ¹ *i386 is for 32bits and x86&#95;64 for 64bits*
