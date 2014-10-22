#if defined _vehicledriver_included
	#endinput
#endif
#define _vehicledriver_included
#include <a_samp>
/* 
	GetVehicleDriver function by Zsolesszka aka Phento v1.1
	Bug fixed 2011.07.24
	Date 2011.07.23
*/
static
	VehicleDriverPlayerid[MAX_VEHICLES] = { INVALID_PLAYER_ID, ... };
	
//------------------------------------------------------------------------------
stock
	GetVehicleDriver(vehicleid) 
{
	if(vehicleid < 1 || vehicleid > sizeof(VehicleDriverPlayerid)) return INVALID_PLAYER_ID; // invalid array 
	if(VehicleDriverPlayerid[vehicleid - 1] != INVALID_PLAYER_ID  && IsPlayerInVehicle(VehicleDriverPlayerid[vehicleid - 1], vehicleid) && GetPlayerVehicleSeat(VehicleDriverPlayerid[vehicleid - 1]) == 0)
		return VehicleDriverPlayerid[vehicleid - 1]; // return playerid vehicledriver
	return VehicleDriverPlayerid[vehicleid - 1] = INVALID_PLAYER_ID;
}

//------------------------------------------------------------------------------
static 
	bool:GetVehicleDriver_VD = false;

//------------------------------------------------------------------------------

#if defined FILTERSCRIPT

public 
	OnFilterScriptInit()
{
	GetVehicleDriver_VD = (funcidx("OnPlayerStateChange_Veh_Driver") != -1);
	return CallLocalFunction("Veh_Driver_OnFilterScriptInit", "");
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Veh_Driver_OnFilterScriptInit
forward Veh_Driver_OnFilterScriptInit();
	
#else

public 
	OnGameModeInit()
{
	GetVehicleDriver_VD = (funcidx("OnPlayerStateChange_Veh_Driver") != -1);
	if(funcidx("VehicleDriver_OnGameModeInit") != -1)
	{
		return CallLocalFunction("VehicleDriver_OnGameModeInit", "");
	}
	return 1;
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit VehicleDriver_OnGameModeInit

forward VehicleDriver_OnGameModeInit();
	
#endif
		
//------------------------------------------------------------------------------
public 
	OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
		new
			vehicleid = GetPlayerVehicleID(playerid);
		if(vehicleid)
		{
			VehicleDriverPlayerid[vehicleid - 1] = playerid;
		}
	}
	if(GetVehicleDriver_VD)
		return CallLocalFunction("OnPlayerStateChange_Veh_Driver", "ddd", playerid, newstate, oldstate);
	return 1;
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange OnPlayerStateChange_Veh_Driver

forward OnPlayerStateChange_Veh_Driver(playerid, newstate, oldstate);
//------------------------------------------------------------------------------

