AntiDeAMX()
{
 new a[][] =
 {
  "Unarmed (Fist)",
  "Brass K"
 };
 #pragma unused a
}

#include <a_samp>
#include <dc_cmd>
//#include <a_npc>
#include <markers-consts>
#include <markers-mapping>
#include <markers-cars>
#include <a_mysql>
#include <sscanf2>
#include <mxdate>
#include <Encrypt>

// Handle ����������� MySQL
new MySQL_Handle = -1; 

// ��������� �������� ������ ������
enum E_PLAYERS
{
	ORM:ORM_ID,
	
	ID,
	dbID,
	Name[MAX_PLAYER_NAME],
	email[100],
	phone[11],
	Password[33],
	Money,
	
	bool:IsLoggedIn,
	bool:IsRegistered,
	LoginAttempts,
	LoginTimer,
	Level,
	DateReg,
	HP,
	Armour,
	Admin,
	Frac,
	FracLVL,
	FracSkin,
	Wanted,
	Reg_IP,
	Skin,
	BanEnd,
	House,
	Car,
	CarKeys,
	Bank,
	Business,
	
};

// ��������� ��������
enum  
{
	DIALOG_LOGIN_INVALID,
	DIALOG_UNUSED,
	DIALOG_LOGIN,
	DIALOG_REGISTER
};

new Player[MAX_PLAYERS][E_PLAYERS]; // ������� ������ �������

// ��������� �������
new Threads[3] =
{
	CeateObject,
	SpawnCars, //?
	RemoveObject
}

new MySQL_RACE_CHECK[MAX_PLAYERS]; // ��� �������� ���������� ������������ ��� ���������� ��������


/*====================================================================*/
/* Forwards                                                           */
/*====================================================================*/
forward OnPlayerDataLoaded(playerid, race_check);
forward OnPlayerRegister(playerid);
forward _KickPlayerDelayed(playerid);
forward OnPlayerRegister(playerid);


/*====================================================================*/
/* SA-MP callbacks                                                    */
/*====================================================================*/

public OnGameModeInit()
{
	AntiDeAMX();

	// �������� ������� � ��������� ������
	Threads[CeateObject] = CreateThread("LoadMapping_GameStart");

	// ����������� ������ MySQL � HTML ����
	mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_HTML);
	// ��������� ���������� � MySQL
	MySQL_Handle = mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASSWORD);

	// �������� ������ �� ���������� ������
	EnableStuntBonusForAll(0);
	// ��������� ���� ��������� ��������� � ���
	//ManualVehicleEngineAndLights(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!! ����� ����������������
	// ������ ����������� ������ � ������
	DisableInteriorEnterExits();
	// ��������� ������ ������ � ����������
	AllowInteriorWeapons(0);
	// ������ ����������� ��������
	LimitPlayerMarkerRadius(50.0);

	print("Markers-RP: Loaded!");
	return 1;
}

public OnGameModeExit()
{
	// ������ ������
	//for (new i=0; i < sizeof(Threads); ++i)
	//{
		//DestroyThread(Threads[i]);
	//}
	
	// ������� ������ ������������� � MySQL
	for(new p=0; p < MAX_PLAYERS; ++p)
	{
		if(IsPlayerConnected(p) && Player[p][IsLoggedIn] && Player[p][ID] > 0)
		{
		// ���������� ������
		orm_save(Player[p][ORM_ID]); 
		}
	}
	// ������� MySQL
	mysql_close();
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerCameraPos(playerid,1678.2035,-1481.4669,110.1527);
	SetPlayerCameraLookAt(playerid,1614.6501,-1576.7792,88.1527);
	return 1;
}

public OnPlayerConnect(playerid)
{
	MySQL_RACE_CHECK[playerid]++; // ��������� ����������� ����������
	for(new E_PLAYERS:e; e < E_PLAYERS; ++e) 
		Player[playerid][e] = 0; // ������� ��������� ��������������� ������������

	GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);

	// ������� ����� ��������� �������
	new ORM:ormid = Player[playerid][ORM_ID] = orm_create("players", MySQL_Handle);
	orm_addvar_int(ormid, Player[playerid][ID], "id");
	mysql_escape_string(Player[playerid][Name], Player[playerid][Name], MySQL, 128);
	orm_addvar_string(ormid, Player[playerid][Name], MAX_PLAYER_NAME, "username");
	orm_addvar_string(ormid, Player[playerid][Password], 33, "password");
	orm_addvar_string(ormid, Player[playerid][email], 100, "email");
	orm_addvar_string(ormid, Player[playerid][phone], 11, "phone");
	orm_addvar_int(ormid, Player[playerid][Money], "money");
	orm_addvar_int(ormid, Player[playerid][BanEnd], "banend");
	orm_setkey(ormid, "username");
	// ������� ������ � ����������� ������
	orm_load(ormid, "OnPlayerDataLoaded", "dd", playerid, MySQL_RACE_CHECK[playerid]);

	//.....
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if (!Player[playerid][IsLoggedIn])
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "������", C_COLOR_WHITE "�� ������ ���� ���������������� � ������ ����� � �������...", "", "");
		KickAndQuit(playerid);
	}
	SetPlayerPos(playerid,1760.7921,-1900.1312,13.5636);
	SetPlayerFacingAngle(playerid,270.02);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid, 0);

	new welcome_msg[50];
	format(welcome_msg, sizeof(welcome_msg), "~w~Welcome ~n~~b~   %s", Player[playerid][Name]);
	GameTextForPlayer(playerid, welcome_msg, 5000, 1);

	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_LOGIN: // ���������
	    {
		if(!response) return KickAndQuit(playerid); // ���� ���������, ������
		if(strlen(inputtext) <= 5 || strlen(inputtext) >= 14) // �������� ������ ������
			return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "�����������", C_COLOR_RED "������ ������ ���� �� ������ 6 �������� � �� ������� 16 ��������!\n" C_COLOR_WHITE "����������, ������� ������ ��� ���!", "�����", "������");

		new hashed_pass[33];
		md5(inputtext, hashed_pass); // ������� md5 ������
			
		if(strcmp(hashed_pass, Player[playerid][Password]) == 0)
		{
			// ������ ������
			Player[playerid][IsLoggedIn] = true;
			//SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			//SpawnPlayer(playerid);
			Welcome(playerid);
		}
		else
		{
                        // ��������, ����� ��� ������� ����� ������
			Player[playerid][LoginAttempts]++;
			if(Player[playerid][LoginAttempts] >= 3)
			{
				// ���, ����, ������ �������
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "�����������", C_COLOR_RED "�� ��������� ����� ������� �����, ��� IP ��������.", "", "");
				DelayedKick(playerid);
			}
			else
			    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "�����������", C_COLOR_RED "������ �� �����!\n" C_COLOR_WHITE "������� ��� ������:", "����", "������");
		}
	    }
	    
	    case DIALOG_REGISTER:
	    {
		if(!response)
			return KickAndQuit(playerid);
		if(strlen(inputtext) <= 5 || strlen(inputtext) >= 14) // �������� ������ ������
			return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "�����������", C_COLOR_RED "������ ������ ���� �� ������ 6 �������� � �� ������� 16 ��������!\n" C_COLOR_WHITE "����������, ������� ������ ��� ���!", "�����", "������");

		md5(inputtext, Player[playerid][Password]); // ������� md5 ������
		
		// ��������� ��������� ��������
		Player[playerid][Money] = 200;
		Player[playerid][Level] = 1;
		Player[playerid][HP] = 90;
		// ������� ������� IP
		GetPlayerIp(playerid, Player[playerid][Reg_IP], 15);
		// �������� �������
		mysql_escape_string(Player[playerid][email], Player[playerid][email], MySQL, 128); // ����������
		mysql_escape_string(Player[playerid][phone], Player[playerid][phone], MySQL, 128); // ����������
		orm_save(Player[playerid][ORM_ID], "OnPlayerRegister", "d", playerid);

	    }
	    
	    default:
			return 0;
	}

	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}


public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	new string[256];
	SetPlayerPosFindZ(playerid, fX, fY, fZ+10);
	format(string, sizeof(string), "�� ������� �����������������. ����������: X - %d Y - %d Z - %d",fX, fY, fZ);
	SendClientMessage(playerid,COLOR_WHITE,string);
	return 1;
}

/*=====================================================================*/
/* ������� ����                                                        */
/*=====================================================================*/

// ������� ��� ��������� �������� ������ ������������ �� ����
public OnPlayerDataLoaded(playerid, race_check)
{
	if(race_check != MySQL_RACE_CHECK[playerid]) // �������� ���������� ������������ �� �������� ����������� ������
		return Kick(playerid);
	orm_setkey(Player[playerid][ORM_ID], "id");

	// ��������� ����� ������� ������
	SetPlayerCameraPos(playerid,1678.2035,-1481.4669,110.1527);
	SetPlayerCameraLookAt(playerid,1614.6501,-1576.7792,88.1527);

	// �������������� ������
	new welcome_cap[144];
	welcome_cap = "����� ���������� �� ������ " SERVER_NAME "!";
	SendClientMessage(playerid, COLOR_YELLOW, welcome_cap);

	// �������� ��������� 
	new welcome_text[400];
	
	switch(orm_errno(Player[playerid][ORM_ID]))
	{
		case ERROR_OK: // ���� �����������
		{
			format(welcome_text, sizeof(welcome_text), C_COLOR_WHITE "%s\n��� ��� ���������������\n\n�����: " C_COLOR_LIMEGREEN "%s\n" C_COLOR_WHITE "������� ������:", welcome_cap, Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, C_COLOR_CORNFLOWERBLUE "�����������", welcome_text, "����", "������");
			Player[playerid][IsRegistered] = true;
		}
		case ERROR_NO_DATA: // ��� �����������
		{
			format(welcome_text, sizeof(welcome_text), C_COLOR_WHITE "%s\n����� ������ ���� ��� ���������� ������ �����������\n\n������� ������ ��� ������ ��������: " C_COLOR_LIMEGREEN "%s\n" C_COLOR_WHITE "\n�� ����� ������������� ������ ���, ����� �� �������� �� ������.\n\n" C_COLOR_LIMEGREEN "\t����������:\n\t- ������ ����� �������� �� ������ � ��������� ��������\n\t- ������ ����������� � ��������\n\t- ����� ������ �� 6-�� �� 15-�� ��������", welcome_cap, Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, C_COLOR_CORNFLOWERBLUE "�����������", welcome_text, "�����", "������");
			Player[playerid][IsRegistered] = false;
		}
	}
	return 1;
}

public OnPlayerRegister(playerid)
{
	//ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Registration", "Account successfully registered, you have been automatically logged in.", "Okay", "");
	Player[playerid][IsLoggedIn] = true;
	Player[playerid][IsRegistered] = true;

	Welcome(playerid);
	return 1;
}

KickAndQuit(playerid)
{
	SendClientMessage(playerid, COLOR_TOMATO, "������� /q (/quit) ����� �����");	
	Kick(playerid);
	return 1;
}

DelayedKick(playerid, time=500)
{
	SetTimerEx("_KickPlayerDelayed", time, false, "d", playerid);
	return 1;
}

Welcome(playerid)
{
        // ������ ������� ��� ������
	RemoveBuldsForPlayer(playerid);
	// ������ ������� ��� ������ � ��������� ������
	//Threads[RemoveObject] = CreateThread("RemoveBuldsForPlayer");


	// ����� �����
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, Player[playerid][Money]);

	//SetPlayerHealth(playerid, Player[playerid][HP]);
	SetPlayerHealth(playerid, 100);
	PreloadAnimLib(playerid,"BOMBER");
	PreloadAnimLib(playerid,"RAPPING");
	PreloadAnimLib(playerid,"SHOP");
	PreloadAnimLib(playerid,"BEACH");
	PreloadAnimLib(playerid,"SMOKING");
	PreloadAnimLib(playerid,"FOOD");
	PreloadAnimLib(playerid,"ON_LOOKERS");
	PreloadAnimLib(playerid,"DEALER");
	PreloadAnimLib(playerid,"CRACK");
	PreloadAnimLib(playerid,"CARRY");
	PreloadAnimLib(playerid,"COP_AMBIENT");
	PreloadAnimLib(playerid,"PARK");
	PreloadAnimLib(playerid,"INT_HOUSE");
	PreloadAnimLib(playerid,"FOOD");
	PreloadAnimLib(playerid,"CRIB");
	PreloadAnimLib(playerid,"ROB_BANK");
	PreloadAnimLib(playerid,"JST_BUISNESS");
	PreloadAnimLib(playerid,"PED");
	PreloadAnimLib(playerid,"OTB");
	ApplyAnimation(playerid, "BOMBER", "null",0.0,0,0,0,0,0);
	StopAudioStreamForPlayer(playerid);
	SetPlayerWantedLevel(playerid, Player[playerid][Wanted]);
	//SetPlayerSkills(playerid);

	SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	SpawnPlayer(playerid);

}

public _KickPlayerDelayed(playerid)
{
	KickAndQuit(playerid);
	return 1;
}

PreloadAnimLib(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
}

CMD:gmx(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	SendClientMessageToAll(COLOR_BLUE, "{FFFFFF}������ ���������� ������ � ������� ������...");
	GameTextForPlayer(playerid, "~r~RE:~g~STARTING", 2000, 5);
	GameModeExit();
	return 1;
}
ALTX:gmx("/restart", "/����"); // !!!!! �������

CMD:veh(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new car_id, Color_1, Color_2;
	if (sscanf(params, "ddd", car_id, Color_1, Color_2))
		return SendClientMessage(playerid, COLOR_WHITE, "�����������: /veh [carid] [����1] [����2]");
	if (car_id < 400 || car_id > 611) 
		return SendClientMessage(playerid, COLOR_GREY, "����� ������ ����� ���� �� 400 �� 611!");
	if (Color_1 < 0 || Color_1 > 126 || Color_2 < 0 || Color_2 > 126)
		return SendClientMessage(playerid, COLOR_GREY, "����� ����� ����� ���� �� 0 �� 126.");

	new Float:Xx,Float:Yy,Float:Zz;
	GetPlayerPos(playerid, Xx,Yy,Zz);
	CreateVehicle(car_id, Xx,Yy,Zz, 0.0, Color_1, Color_2, 60000);

//FP_PPVAC(playerid, createdvehicles[playerid], 0);
//CreatedCars[CreatedCar] = createdvehicles[playerid];
//SetVehicleParamsEx(createdvehicles[playerid],VEHICLE_PARAMS_ON,VEHICLE_PARAMS_ON,alarm,doors,bonnet,boot,objective);
//SpawnedCar ++;
//VehicleFuel[createdvehicles[playerid]] = 120;
//zavodis[createdvehicles[playerid]] = true;
//LinkVehicleToInterior(createdvehicles[playerid], intt);
//RepairVehicle(GetPlayerVehicleID(playerid));return true;
	return 1;

}
ALTX:veh("/makecar", "/���_����������"); // !!!!! �������

CMD:givegun(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new player, gunid, ammo;
	if (sscanf(params, "rdd", player, gunid, ammo))
		if (sscanf(params, "dd", gunid, ammo))
			return SendClientMessage(playerid, COLOR_WHITE, "�����������: /givegun [ID ������] [���-�� ��������]");
	if (player == INVALID_PLAYER_ID)
		return SendClientMessage(playerid, COLOR_GREY, "������ � ����� ID �� ����������!");
	if (gunid < 1 && gunid > 54)
		return SendClientMessage(playerid, COLOR_GREY, "ID ������ ����� ���� �� 1 �� 54.");
	if (ammo < 1 && ammo > 10000)
		return SendClientMessage(playerid, COLOR_GREY, "���-�� �������� ������ ���� �� 1 �� 10000.");
	for (new i=0; i<sizeof(deleted_weapons); i++) {
		if (gunid == deleted_weapons[i]) return SendClientMessage(playerid, COLOR_GREY, "��� ������ ��������� �� �������!");
	}
	GivePlayerWeapon(playerid, gunid, ammo);
	return 1;
}
ALTX:givegun("/gm", "/���_����������"); // !!!!! �������

CMD:time(playerid)
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new timeNow[20] = date(gettime(), "%dd.%mm.%yyyy %hh:%ii%ss");
	format(timeNow, sizeof(timeNow), "������� ����� - %s.", timeNow);
	SendClientMessage(playerid, COLOR_YELLOW, timeNow);
	print(timeNow);
	return 1;
}

CMD:kick(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new bastard, reason[50], msg2all[100], msg2btrd[100];
	if (sscanf(params, "rs", bastard, reason))
		return SendClientMessage(playerid, COLOR_GREY, "�����������: /kick [ID ������] {�������}");
	if (sscanf(params, "r", bastard)) {
		reason = "[������� �� �������]";
		return SendClientMessage(playerid, COLOR_GREY, "�����������: /kick [ID ������] {�������}");
	}
	format(msg2all, sizeof(msg2all), "������������� %s ������ ������ %s. �������: %s", Player[playerid][Name], Player[bastard][Name], reason);
	SendClientMessageToAll(COLOR_TOMATO, msg2all);
	format(msg2btrd, sizeof(msg2btrd), "��� ������ ������������� %s. �������: %s", Player[playerid][Name], reason);
	SendClientMessage(bastard, COLOR_TOMATO, msg2btrd);
	KickAndQuit(bastard);
	return 1;
}
ALTX:kick("/k", "/������"); // !!!!! �������

CMD:ban(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new bastard, day, reason[50], msg2all[100], msg2btrd[100];
	if (sscanf(params, "rds", bastard, days, reason))
		return SendClientMessage(playerid, COLOR_GREY, "�����������: /ban [ID] [���-�� ����] [�������]");
	new uTimeNow = gettime(), uTimeBanEnd = gettime() + days*24*60;
	Player[bastard][BanEnd] = uTimeBanEnd;
	new timeNow[20], timeBanEnd[20];
	timeBanEnd = date(uTimeBanEnd, "%dd.%mm.%yyyy %hh:%ii%ss");
	format(msg2all, sizeof(msg2all), "������������� %s ������� ������ %s �� %s. �������: '%s'.", Player[playerid][Name], Player[bastard][Name], timeBanEnd, reason);
	SendClientMessageToAll(COLOR_TOMATO, msg2all);
	format(msg2all, sizeof(msg2all), "������������� %s ������� ��� �� %s. �������: '%s'.", Player[playerid][Name], timeBanEnd, reason);
	SendClientMessage(bastard, COLOR_TOMATO, msg2btrd);
	KickAndQuit(bastard);
	return 1;
}
ALTX:ban("/b", "/�������_��_�����"); // !!!!! �������

main(){}
