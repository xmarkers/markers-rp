#include <a_samp>
#include <markers>
#include <a_mysql>
#include <sscanf2>
#include <zcmd>
#include <Encrypt>

new MySQL_Handle = -1; // Handle подключения MySQL

// Структура хранения данных игрока
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

// Структура диалогов
enum DIALOGS 
{
	Login,
	Register
};


new Player[MAX_PLAYERS][E_PLAYERS]; // Объявим массив игроков
new MySQL_RACE_CHECK[MAX_PLAYERS]; // Для проверки валидности пользователя при длительных запросах


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
        mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_HTML); // Логирование ошибок MySQL в HTML виде
        MySQL_Handle = mysql_connect(SQL_CONNECT_PROPS[Host], SQL_CONNECT_PROPS[Login], SQL_CONNECT_PROPS[DataBase], SQL_CONNECT_PROPS[Password]); // Установим соединение с MySQL
	
        return 1;
}

public OnGameModeExit()
{
        for(new p=0; p < MAX_PLAYERS; ++p) // Сбросим данные пользователей в MySQL
         {
           if(IsPlayerConnected(p) && Player[p][IsLoggedIn] && Player[p][ID] > 0)
            {
             orm_save(Player[p][ORM_ID]); // Сохранение данных
            }
         }
        mysql_close(); // Закроем MySQL
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
        MySQL_RACE_CHECK[playerid]++; // Установим проверочную переменную
        for(new E_PLAYERS:e; e < E_PLAYERS; ++e) 
           Player[playerid][e] = 0; // Сбросим параметры подключившегося пользователя
	GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);

        // Создаем новую структуру запроса
	new ORM:ormid = Player[playerid][ORM_ID] = orm_create("players", MySQL_Handle);
	orm_addvar_int(ormid, Player[playerid][ID], "id");
	orm_addvar_string(ormid, Player[playerid][Name], MAX_PLAYER_NAME, "username");
	orm_addvar_string(ormid, Player[playerid][Password], 33, "password");
        orm_addvar_string(ormid, Player[playerid][email], 100, "email");
        orm_addvar_string(ormid, Player[playerid][phone], 11, "phone");
	orm_addvar_int(ormid, Player[playerid][Money], "money");
	orm_setkey(ormid, "username");
        // Сделаем запрос в паралельном потоке
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
	    case DIALOGS[Login]: // Логинимся
	    {
	        if(!response) return Kick(playerid); // Если отказался, кикнем
		if(strlen(inputtext) <= 5 or strlen(inputtext) >= 14) // Проверим длинну пароля
			return ShowPlayerDialog(playerid, DIALOGS[Login], DIALOG_STYLE_PASSWORD, "Ошибка", COLORS_CHAT[Red] "Пароль должен быть не короче 6 символов и не длиньше 16!\n" COLORS_CHAT[White] "Пожалуйста, введите пароль ещё раз!", "Войти", "Отмена");

		new hashed_pass[33];
		md5(inputtext, hashed_pass); // Получим md5 пароля
			
		if(strcmp(hashed_pass, Player[playerid][Password]) == 0)
		{
			// Пароль верный
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
/* Функции мода                                                        */
/*=====================================================================*/

// Функция при начальной загрузке данных пользователя из базы
public OnPlayerDataLoaded(playerid, race_check)
{
	if(race_check != MySQL_RACE_CHECK[playerid]) // Проверка валидности пользователя на которого запрашивали данные
	    return Kick(playerid);
	    
	orm_setkey(Player[playerid][ORM_ID], "id");


        // Установим точку взгляда камеры
	SetPlayerCameraPos(playerid,1678.2035,-1481.4669,110.1527);
	SetPlayerCameraLookAt(playerid,1614.6501,-1576.7792,88.1527);

        // Поприветствуем игрока
	new welcome_cap = "Добро пожаловать на сервер " SERVER_NAME "!";
	SendClientMessage(playerid, COLORS[Yellow], welcome_cap);

	// Проверим результат 
	new welcome_text[256];
	
	switch(orm_errno(Player[playerid][ORM_ID]))
	{
		case ERROR_OK: // Есть регистрация
		{
			format(welcome_text, sizeof(welcome_text), COLORS_CHAT[White] welcome_cap "\nВаш ник зарегистрирован\n\nЛогин: " COLORS_CHAT[LimeGreen] "%s\n" COLORS_CHAT[White] "Введите пароль:", Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOGS[Login], DIALOG_STYLE_PASSWORD, COLORS_CHAT[CornflowerBlue] "Авторизация", welcome_text, "Войти", "Отмена");
			Player[playerid][IsRegistered] = true;
		}
		case ERROR_NO_DATA: // Нет регистрации
		{
			format(welcome_text, sizeof(welcome_text), COLORS_CHAT[White] welcome_cap "\nЧтобы начать игру вам необходиму пройти регистрацию\n\nВведите пароль для Вашего аккаунта: " COLORS_CHAT[LimeGreen] "%s\n" COLORS_CHAT[White] "\nОн будет запрашиваться каждый раз, когда вы заходите на сервер.\n\n" COLORS_CHAT[LimeGreen] "\tПримечания:\n\t- Пароль может состоять из руских и латинских символов\n\t- Пароль чуствителен к регистру\n\t- Длина пароля от 6-ти до 15-ти символов", Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOGS[Register], DIALOG_STYLE_PASSWORD, COLORS_CHAT[CornflowerBlue] "Регистрация", welcome_text, "Принять", "Отмена");
			Player[playerid][IsRegistered] = false;
		}
	}
	return 1;
}

KickAndQuit(playerid)
{
	SendClientMessage(playerid, 0xFF6347AA, "Введите /q (/quit) чтобы выйти");	
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
