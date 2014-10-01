#include <a_samp>
#include <markers>
#include <a_mysql>
#include <sscanf2>
#include <zcmd>
#include <Encrypt>

new MySQL_Handle = -1; // Handle ����������� MySQL

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
	LoginTimer
};

// ��������� ��������
enum DIALOGS 
{
	Login,
	Register
};


new Player[MAX_PLAYERS][E_PLAYERS]; // ������� ������ �������
new MySQL_RACE_CHECK[MAX_PLAYERS]; // ��� �������� ���������� ������������ ��� ���������� ��������


/*====================================================================*/
/* Forwards                                                           */
/*====================================================================*/
forward OnPlayerDataLoaded(playerid, race_check);
forward OnPlayerRegister(playerid);
forward _KickPlayerDelayed(playerid);


/*====================================================================*/
/* SA-MP callbacks                                                    */
/*====================================================================*/

public OnGameModeInit()
{
        mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_HTML); // ����������� ������ MySQL � HTML ����
        MySQL_Handle = mysql_connect(SQL_CONNECT_PROPS[Host], SQL_CONNECT_PROPS[Login], SQL_CONNECT_PROPS[DataBase], SQL_CONNECT_PROPS[Password]); // ��������� ���������� � MySQL
	
        return 1;
}

public OnGameModeExit()
{
        for(new p=0; p < MAX_PLAYERS; ++p) // ������� ������ ������������� � MySQL
         {
           if(IsPlayerConnected(p) && Player[p][IsLoggedIn] && Player[p][ID] > 0)
            {
             orm_save(Player[p][ORM_ID]); // ���������� ������
            }
         }
        mysql_close(); // ������� MySQL
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	//SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	//SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	//SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
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
	    case DIALOGS[Login]: // ���������
	    {
	        if(!response) return Kick(playerid); // ���� ���������, ������
		if(strlen(inputtext) <= 5 or strlen(inputtext) >= 14) // �������� ������ ������
			return ShowPlayerDialog(playerid, DIALOGS[Login], DIALOG_STYLE_PASSWORD, "������", COLORS_CHAT[Red] "������ ������ ���� �� ������ 6 �������� � �� ������� 16!\n" COLORS_CHAT[White] "����������, ������� ������ ��� ���!", "�����", "������");

		new hashed_pass[33];
		md5(inputtext, hashed_pass); // ������� md5 ������
			
		if(strcmp(hashed_pass, Player[playerid][Password]) == 0)
		{
			// ������ ������
			Player[playerid][IsLoggedIn] = true;
			SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			SpawnPlayer(playerid);
		}
		else
		{
		    Player[playerid][LoginAttempts]++;
		    if(Player[playerid][LoginAttempts] >= 3)
		    {
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Login", CHAT_RED "You have mistyped your password too often (3 times).", "Okay", "");
		        DelayedKick(playerid);
			}
			else
			    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login", CHAT_RED "Wrong password!\n" CHAT_WHITE "Please enter your password in the field below:", "Login", "Abort");
		}
	    }
	    
	    case DIALOG_REGISTER:
	    {
	        if(!response)
	            return Kick(playerid);
	            
            if(strlen(inputtext) <= 5)
				return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Registration",
					CHAT_RED "Your password must be longer than 5 characters!\n" CHAT_WHITE "Please enter your password in the field below:",
					"Register", "Abort");

			//WP_Hash(Player[playerid][Password], 129, inputtext);
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
	new welcome_cap = "����� ���������� �� ������ " SERVER_NAME "!";
	SendClientMessage(playerid, COLORS[Yellow], welcome_cap);

	// �������� ��������� 
	new welcome_text[256];
	
	switch(orm_errno(Player[playerid][ORM_ID]))
	{
		case ERROR_OK: // ���� �����������
		{
			format(welcome_text, sizeof(welcome_text), COLORS_CHAT[White] welcome_cap "\n��� ��� ���������������\n\n�����: " COLORS_CHAT[LimeGreen] "%s\n" COLORS_CHAT[White] "������� ������:", Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOGS[Login], DIALOG_STYLE_PASSWORD, COLORS_CHAT[CornflowerBlue] "�����������", welcome_text, "�����", "������");
			Player[playerid][IsRegistered] = true;
		}
		case ERROR_NO_DATA: // ��� �����������
		{
			format(welcome_text, sizeof(welcome_text), COLORS_CHAT[White] welcome_cap "\n����� ������ ���� ��� ���������� ������ �����������\n\n������� ������ ��� ������ ��������: " COLORS_CHAT[LimeGreen] "%s\n" COLORS_CHAT[White] "\n�� ����� ������������� ������ ���, ����� �� �������� �� ������.\n\n" COLORS_CHAT[LimeGreen] "\t����������:\n\t- ������ ����� �������� �� ������ � ��������� ��������\n\t- ������ ����������� � ��������\n\t- ����� ������ �� 6-�� �� 15-�� ��������", Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOGS[Register], DIALOG_STYLE_PASSWORD, COLORS_CHAT[CornflowerBlue] "�����������", welcome_text, "�������", "������");
			Player[playerid][IsRegistered] = false;
		}
	}
	return 1;
}

KickAndQuit(playerid)
{
	SendClientMessage(playerid, 0xFF6347AA, "������� /q (/quit) ����� �����");	
	Kick(playerid);
	return 1;
}

DelayedKick(playerid, time=500)
{
	SetTimerEx("_KickPlayerDelayed", time, false, "d", playerid);
	return 1;
}

public _KickPlayerDelayed(playerid)
{
	KickAndQuit(playerid);
	return 1;
}

main(){}
