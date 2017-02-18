# Titan Mod for UrT >= 4.2.023
TheK1ll3r and Pedrxd are proud to announce the new TitanMod completly rewritted. This software aspired to be the BEST urbanterror mod never writted before adding lot of new features for add better experiences to players and admins.

The usage of this software is **UNDER YOUR OWN RISK**.

## Features:
All features of this mod will be described below:
### Cvar
Cvar |  Value  | Description
--- | --- | ---
mod_infiniteStamina | On / Off | Disable stamina on the server
mod_infiniteWallJumps | On / Off | Allow infinite jums cross walls
mod_noFallDamage | On / Off | Dont get damage when fall from high distance
mod_colourNames | On / Off | Enable colour names on the scoreboard
mod_playerCount | &#60;value&#62; | If the int is positive, will be added to the real count of player, if is negative a random number beetween value to 1 will be added
mod_mapName | &#60;string&#62; | The specified name will be set to the mapname for UrT searcher, if nothing set will be the real one.
mod_hidecmds | &#60;value&#62; | Used for mute commands on chat starting with !, /, @, &. Where value 0 = off, 1 = pm player, 2 = full mute.

### Commands
Commands | Syntax | Description
--- | --- | ---
setscore |  &#60;player&#62;  &#60;score&#62; | Will set &#60;score&#62; to the scoreboard of the game
setdeaths |  &#60;player&#62;  &#60;deaths&#62; | Will set &#60;deaths&#62; to the scoreboard of the game
invisible | &#60;player&#62; | Switch between invisible or not to &#60;player&#62; 
playsound | &#60;player&#62; &#60;index&#62; | Will play a sound that is on the &#60;index&#62; of her configstring .
playsoundfile | &#60;player&#62; &#60;file&#62; | Will play a sound that is on the pk3 files of her computer on the path &#60;file&#62;

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
If you want the **dedicated server** take the file named 'Quake3-UrT-Ded.i386/x86_64'¹ and replaced it on the UrbanTerror folder, execute it as normal.

For **client version** take 'Quake3-UrT.i386/x86_64'¹ and replaced it on the UrbanTerror folder, execute it as normal.

 ¹ *i386 is for 32bits and x86_64 for 64bits*
