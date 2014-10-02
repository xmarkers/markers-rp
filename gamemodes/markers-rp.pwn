#include <a_samp>
#include <markers-consts>
#include <a_mysql>
#include <sscanf2>
#include <zcmd>
#include <Encrypt>

// Handle ����������� MySQL
new MySQL_Handle = -1; 

// ��������� �������� ������ ������
enum E_PLAYERS
{
	ORM:ORM_ID,
	
	ID,
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
	Heal,
	Reg_IP,

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
	// ����������� ������ MySQL � HTML ����
	mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_HTML);
	// ��������� ���������� � MySQL
	MySQL_Handle = mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASSWORD);

	print("markers-rp: Loaded!");
	return 1;
}

public OnGameModeExit()
{
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
	orm_addvar_string(ormid, Player[playerid][Name], MAX_PLAYER_NAME, "username");
	orm_addvar_string(ormid, Player[playerid][Password], 33, "password");
	orm_addvar_string(ormid, Player[playerid][email], 100, "email");
	orm_addvar_string(ormid, Player[playerid][phone], 11, "phone");
	orm_addvar_int(ormid, Player[playerid][Money], "money");
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
			SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			SpawnPlayer(playerid);
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
		PlayerInfo[playerid][pLevel] = 1;
		PlayerInfo[playerid][pHeal] = 90;
		// ������� ������� IP
		GetPlayerIp(playerid, PlayerInfo[playerid][Reg_IP], 15);
		// �������� �������
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

	// ����� �����
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, Player[playerid][Money]);

	//SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	//SpawnPlayer(playerid);
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
	new welcome_msg;
	format(welcome_msg, sizeof(welcome_msg), "~w~Welcome ~n~~b~   %s", Player[playerid][Name]);
	GameTextForPlayer(playerid, welcome_msg, 5000, 1);
}

public _KickPlayerDelayed(playerid)
{
	KickAndQuit(playerid);
	return 1;
}

CMD:gmx(playerid, params[])
{
	SendClientMessageToAll(COLOR_BLUE, "{FFFFFF}������ ���������� ������ � ������� ������...");
	GameTextForPlayer(playerid, "~r~RE~g~STARTING", 2000, 5);
	GameModeExit();
	return 1;
}

main(){}
