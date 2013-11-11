WiiDevices Plugin for CryEngine SDK
=====================================
Wii devices Plugin for CryEngine 3.5.4 

Purpose of this plugin is to give the possibility to use Wii controlers inside CryEngine (Wiimote / motion plus, Nunchuk, Balance Board, Classic and Guitar Hero controler)

Lastest version can be found here : https://github.com/lefevren/Plugin_WiiDevices

This plugin is a part of a larger project : CryVR. For more information : https://github.com/lefevren/CryVR


Installation / Integration
==========================
Use the installer or extract the files to your CryEngine SDK Folder so that the Code and BinXX/Plugins directories match up.

The plugin manager will automatically load up the plugin when the game/editor is restarted or if you directly load it.

Install Wiiuse.dll inside both bin32 and bin64 directory to make it works.


Flownodes
=========

Wiimote Manager : Needed as the first active node. Initialize connection with bluetooth stack. 
Wiimote Balance Board / Classic / Guitar Hero / Controler nodes : For now, just one at a time. Use this to retrieve devices values inside your flowgraph.
Wiimote Battery Level : Retreive battery level of the connected device.
Wiimote IR : Activate / Deactivate / Get IR state.
Wiimote Rumble : Toogle Rumble for the given device.
Wiimote Motion Sensing : Activate or deactivate motion sensing for the connected device (off by default)
Wiimote Setup : Setup wiimote detection events.

Notes :
=================

Wiimote event detection can be really heavy. Wiimote generates event quickly. Detect all events could be FPS killer (something like 10% worst)
With good configuration you can get enough events to make it real time response without noticable fps drop down. Depends on system performance.