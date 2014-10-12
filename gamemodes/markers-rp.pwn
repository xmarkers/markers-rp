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

// Handle подключения MySQL
new MySQL_Handle = -1; 

// Структура хранения данных игрока
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

// Структура диалогов
enum  
{
	DIALOG_LOGIN_INVALID,
	DIALOG_UNUSED,
	DIALOG_LOGIN,
	DIALOG_REGISTER
};

new Player[MAX_PLAYERS][E_PLAYERS]; // Объявим массив игроков

// Структура потоков
new Threads[3] =
{
	CeateObject,
	SpawnCars, //?
	RemoveObject
}

new MySQL_RACE_CHECK[MAX_PLAYERS]; // Для проверки валидности пользователя при длительных запросах


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

	// Создадим объекты в отдельном потоке
	Threads[CeateObject] = CreateThread("LoadMapping_GameStart");

	// Логирование ошибок MySQL в HTML виде
	mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_HTML);
	// Установим соединение с MySQL
	MySQL_Handle = mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASSWORD);

	// Отключим бонусы за уникальные прыжки
	EnableStuntBonusForAll(0);
	// Запретить авто включение двигателя и фар
	//ManualVehicleEngineAndLights(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!! Потом раскоментировать
	// Запрет стандартных входов в здание
	DisableInteriorEnterExits();
	// Запрещаем носить оружие в интерьерах
	AllowInteriorWeapons(0);
	// Радиус отображения маркеров
	LimitPlayerMarkerRadius(50.0);

	print("Markers-RP: Loaded!");
	return 1;
}

public OnGameModeExit()
{
	// Удалим потоки
	//for (new i=0; i < sizeof(Threads); ++i)
	//{
		//DestroyThread(Threads[i]);
	//}
	
	// Сбросим данные пользователей в MySQL
	for(new p=0; p < MAX_PLAYERS; ++p)
	{
		if(IsPlayerConnected(p) && Player[p][IsLoggedIn] && Player[p][ID] > 0)
		{
		// Сохранение данных
		orm_save(Player[p][ORM_ID]); 
		}
	}
	// Закроем MySQL
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
	MySQL_RACE_CHECK[playerid]++; // Установим проверочную переменную
	for(new E_PLAYERS:e; e < E_PLAYERS; ++e) 
		Player[playerid][e] = 0; // Сбросим параметры подключившегося пользователя

	GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);

	// Создаем новую структуру запроса
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
	if (!Player[playerid][IsLoggedIn])
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Ошибка", C_COLOR_WHITE "Вы должны быть зарегистрированы и должны войти в систему...", "", "");
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
	    case DIALOG_LOGIN: // Логинимся
	    {
		if(!response) return KickAndQuit(playerid); // Если отказался, кикнем
		if(strlen(inputtext) <= 5 || strlen(inputtext) >= 14) // Проверим длинну пароля
			return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Авторизация", C_COLOR_RED "Пароль должен быть не короче 6 символов и не длинней 16 символов!\n" C_COLOR_WHITE "Пожалуйста, введите пароль ещё раз!", "Войти", "Отмена");

		new hashed_pass[33];
		md5(inputtext, hashed_pass); // Получим md5 пароля
			
		if(strcmp(hashed_pass, Player[playerid][Password]) == 0)
		{
			// Пароль верный
			Player[playerid][IsLoggedIn] = true;
			//SetSpawnInfo(playerid, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			//SpawnPlayer(playerid);
			Welcome(playerid);
		}
		else
		{
                        // Сохраним, какая уже попытка ввода пароля
			Player[playerid][LoginAttempts]++;
			if(Player[playerid][LoginAttempts] >= 3)
			{
				// Эээ, брат, хватит брутить
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Авторизация", C_COLOR_RED "Вы исчерпали лимит попыток входа, ваш IP сохранен.", "", "");
				DelayedKick(playerid);
			}
			else
			    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Авторизация", C_COLOR_RED "Пароль не верен!\n" C_COLOR_WHITE "Введите ваш пароль:", "Вход", "Отмена");
		}
	    }
	    
	    case DIALOG_REGISTER:
	    {
		if(!response)
			return KickAndQuit(playerid);
		if(strlen(inputtext) <= 5 || strlen(inputtext) >= 14) // Проверим длинну пароля
			return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Регистрация", C_COLOR_RED "Пароль должен быть не короче 6 символов и не длинней 16 символов!\n" C_COLOR_WHITE "Пожалуйста, введите пароль ещё раз!", "Далее", "Отмена");

		md5(inputtext, Player[playerid][Password]); // Получим md5 пароля
		
		// Установим стартовые значения
		Player[playerid][Money] = 200;
		Player[playerid][Level] = 1;
		Player[playerid][HP] = 90;
		// Получим текущий IP
		GetPlayerIp(playerid, Player[playerid][Reg_IP], 15);
		// Сохраним профиль
		mysql_escape_string(Player[playerid][email], Player[playerid][email], MySQL, 128); // Обфускация
		mysql_escape_string(Player[playerid][phone], Player[playerid][phone], MySQL, 128); // Обфускация
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
	format(string, sizeof(string), "Вы успешно телепортировались. Координаты: X - %d Y - %d Z - %d",fX, fY, fZ);
	SendClientMessage(playerid,COLOR_WHITE,string);
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
	new welcome_cap[144];
	welcome_cap = "Добро пожаловать на сервер " SERVER_NAME "!";
	SendClientMessage(playerid, COLOR_YELLOW, welcome_cap);

	// Проверим результат 
	new welcome_text[400];
	
	switch(orm_errno(Player[playerid][ORM_ID]))
	{
		case ERROR_OK: // Есть регистрация
		{
			format(welcome_text, sizeof(welcome_text), C_COLOR_WHITE "%s\nВаш ник зарегистрирован\n\nЛогин: " C_COLOR_LIMEGREEN "%s\n" C_COLOR_WHITE "Введите пароль:", welcome_cap, Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, C_COLOR_CORNFLOWERBLUE "Авторизация", welcome_text, "Вход", "Отмена");
			Player[playerid][IsRegistered] = true;
		}
		case ERROR_NO_DATA: // Нет регистрации
		{
			format(welcome_text, sizeof(welcome_text), C_COLOR_WHITE "%s\nЧтобы начать игру вам необходиму пройти регистрацию\n\nУкажите пароль для Вашего аккаунта: " C_COLOR_LIMEGREEN "%s\n" C_COLOR_WHITE "\nОн будет запрашиваться каждый раз, когда вы заходите на сервер.\n\n" C_COLOR_LIMEGREEN "\tПримечания:\n\t- Пароль может состоять из руских и латинских символов\n\t- Пароль чуствителен к регистру\n\t- Длина пароля от 6-ти до 15-ти символов", welcome_cap, Player[playerid][Name]);
			ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, C_COLOR_CORNFLOWERBLUE "Регистрация", welcome_text, "Далее", "Отмена");
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
	SendClientMessage(playerid, COLOR_TOMATO, "Введите /q (/quit) чтобы выйти");	
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
        // Удалим объекты для игрока
	RemoveBuldsForPlayer(playerid);
	// Удалим объекты для игрока в отдельном потоке
	//Threads[RemoveObject] = CreateThread("RemoveBuldsForPlayer");


	// Дадим бабок
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
	SendClientMessageToAll(COLOR_BLUE, "{FFFFFF}Сервер возобновит работу в течение минуты...");
	GameTextForPlayer(playerid, "~r~RE:~g~STARTING", 2000, 5);
	GameModeExit();
	return 1;
}
ALTX:gmx("/restart", "/умри"); // !!!!! Удалить

CMD:veh(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new car_id, Color_1, Color_2;
	if (sscanf(params, "ddd", car_id, Color_1, Color_2))
		return SendClientMessage(playerid, COLOR_WHITE, "Используйте: /veh [carid] [цвет1] [цвет2]");
	if (car_id < 400 || car_id > 611) 
		return SendClientMessage(playerid, COLOR_GREY, "Номер машины может быть от 400 до 611!");
	if (Color_1 < 0 || Color_1 > 126 || Color_2 < 0 || Color_2 > 126)
		return SendClientMessage(playerid, COLOR_GREY, "Номер цвета может быть от 0 до 126.");

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
ALTX:veh("/makecar", "/дай_покататься"); // !!!!! Удалить

CMD:givegun(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new player, gunid, ammo;
	if (sscanf(params, "rdd", player, gunid, ammo))
		if (sscanf(params, "dd", gunid, ammo))
			return SendClientMessage(playerid, COLOR_WHITE, "Используйте: /givegun [ID оружия] [кол-во патронов]");
	if (player == INVALID_PLAYER_ID)
		return SendClientMessage(playerid, COLOR_GREY, "Игрока с таким ID не существует!");
	if (gunid < 1 && gunid > 54)
		return SendClientMessage(playerid, COLOR_GREY, "ID оружия может быть от 1 до 54.");
	if (ammo < 1 && ammo > 10000)
		return SendClientMessage(playerid, COLOR_GREY, "Кол-во патронов должно быть от 1 до 10000.");
	for (new i=0; i<sizeof(deleted_weapons); i++) {
		if (gunid == deleted_weapons[i]) return SendClientMessage(playerid, COLOR_GREY, "Это оружие запрещено на сервере!");
	}
	GivePlayerWeapon(playerid, gunid, ammo);
	return 1;
}
ALTX:givegun("/gm", "/дай_пострелять"); // !!!!! Удалить

CMD:time(playerid)
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new timeNow[20] = date(gettime(), "%dd.%mm.%yyyy %hh:%ii%ss");
	format(timeNow, sizeof(timeNow), "Текущее время - %s.", timeNow);
	SendClientMessage(playerid, COLOR_YELLOW, timeNow);
	print(timeNow);
	return 1;
}

CMD:kick(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new bastard, reason[50], msg2all[100], msg2btrd[100];
	if (sscanf(params, "rs", bastard, reason))
		return SendClientMessage(playerid, COLOR_GREY, "Используйте: /kick [ID игрока] {Причина}");
	if (sscanf(params, "r", bastard)) {
		reason = "[причина не указана]";
		return SendClientMessage(playerid, COLOR_GREY, "Используйте: /kick [ID игрока] {Причина}");
	}
	format(msg2all, sizeof(msg2all), "Администратор %s кикнул игрока %s. Причина: %s", Player[playerid][Name], Player[bastard][Name], reason);
	SendClientMessageToAll(COLOR_TOMATO, msg2all);
	format(msg2btrd, sizeof(msg2btrd), "Вас кикнул администратор %s. Причина: %s", Player[playerid][Name], reason);
	SendClientMessage(bastard, COLOR_TOMATO, msg2btrd);
	KickAndQuit(bastard);
	return 1;
}
ALTX:kick("/k", "/изыйди"); // !!!!! Удалить

CMD:ban(playerid, params[])
{
	if (!Player[playerid][IsLoggedIn]) return 1;
	new bastard, day, reason[50], msg2all[100], msg2btrd[100];
	if (sscanf(params, "rds", bastard, days, reason))
		return SendClientMessage(playerid, COLOR_GREY, "Используйте: /ban [ID] [Кол-во дней] [Причина]");
	new uTimeNow = gettime(), uTimeBanEnd = gettime() + days*24*60;
	Player[bastard][BanEnd] = uTimeBanEnd;
	new timeNow[20], timeBanEnd[20];
	timeBanEnd = date(uTimeBanEnd, "%dd.%mm.%yyyy %hh:%ii%ss");
	format(msg2all, sizeof(msg2all), "Администратор %s забанил игрока %s до %s. Причина: '%s'.", Player[playerid][Name], Player[bastard][Name], timeBanEnd, reason);
	SendClientMessageToAll(COLOR_TOMATO, msg2all);
	format(msg2all, sizeof(msg2all), "Администратор %s забанил Вас до %s. Причина: '%s'.", Player[playerid][Name], timeBanEnd, reason);
	SendClientMessage(bastard, COLOR_TOMATO, msg2btrd);
	KickAndQuit(bastard);
	return 1;
}
ALTX:ban("/b", "/порошок_не_входи"); // !!!!! Удалить

main(){}
