#pragma library markers-cars

// Время респавна машины
#define CAR_RESPAWN_MAFIA 1*60*60 // 1 час респан машин мафии
#define CAR_RESPAWN_MEDIA 2*60*60 // 2 часа респавн машин прессы
#define CAR_RESPAWN_MEDICINE 30*60 // 30 минут респавн машин больниц
#define CAR_RESPAWN_ARMY 30*60 // 30 минут,  респавн машин армии
#define CAR_RESPAWN_POLICE 1*60*60 // 1 час,  респавн машин полиции
#define CAR_RESPAWN_WORKERS 5*60 // 5 минут,  машины разных рабочих
#define CAR_RESPAWN_DEFAULT 30*60 // 30 минут,  респав по умолчанию

// Хранилище для заспавненых авто
enum s_cars
{
	// Банды
	F_BALLAS[7], // Банда "Баллас"
	F_GROVE[6], // Банда "Grove street"
	F_AZTECAS[7], // Банда "Varios Los Aztecas"
	F_VAGOS[6], // Банда "Los Santos Vagos"
	F_RIFA[9], // Бвнда "The RIFA"
	F_COSANOSTRA[8], // Банда "La Cosa Nostra"
	F_YAKUZA[10], // Банда "Yakuza"
	F_RUSSIAN[9], // Русская мафия

	// Пожарники (не фракция)
	FIRE_LS[4], // Пожарки ЛС
	FIRE_SF[5], // Пожарки СФ
	FIRE_LV[5], // Пожарки ЛВ

	// Медики
	F_MED_HEAD[1], // Министр здравохранения
	F_MED_LS[8], // Медики ЛС
	F_MED_LV[6], // Медики ЛВ
	F_MED_SF[8], // Медики СФ

	// Армия
	F_ARMY_HEAD[1], // Министерство обороны
	F_ARMY_LAND[14], // Сухопутные войска
	F_ARMY_WATER[15], // Военно моркской флот
	F_ARMY_AIR[12], // Военно воздушные силы
	F_ARMY_SUPPLY[3], // Машина снабжения

   // Полиция
   F_POLICE_HEAD[1], // Министр внутренних дел
	F_POLICE_FBI[10], // FBI
	F_POLICE_LS[16], // Полиция ЛС
	F_POLICE_LV[14], // Полиция ЛВ
	F_POLICE_SF[16], // Полиция СФ

	// Радио и ТВ
	F_MEDIA_HEAD[1], // Министр СМИ
	F_MEDIA_TV[9], // ТВ-Центр
	F_MEDIA_R_LS[6], // Радиоцентр ЛС
	F_MEDIA_R_SF[7], // Радиоцентр СФ
	F_MEDIA_R_LV[5], // Радиоцентр ЛВ

   // Президент и Мэрии
	F_GOV_AP[11], // Администрация президента
	F_GOV_LV[4], // Мэрия ЛВ
	F_GOV_LS[4], // Мэрия ЛС
	F_GOV_SF[4], // Мэрия СФ

   // Аренда машин
   RENT_BOAT[5], // Лодки
	RENT_VELO[76], // Магазин Вело/Мото !!!!Уточнить количество!!!
	RENT_LOWEND[76], // Магазин эконом класса !!!!Уточнить количество!!!
	RENT_MIDEND[76], // Магазин среднего класса !!!!Уточнить количество!!!
	RENT_HIEND[76], // Магазин премиум класса !!!!Уточнить количество!!!

	// Машины завода
	FACTORY_TRAIN[4], // Тягач
	FACTORY_TRAILER[4], // Прицеп
	FACTORY_WAGON[4], // Фургон

   // Машины доставщиков продуктов
	DELIVERY_GOODS_TRAIN[3], // Тягач, развозчик продуктов
	DELIVERY_GOODS_TRAILER[3], // Прицеп развозчика продуктов
	DELIVERY_GOODS_WAGON[3], // Грузовик развозчика продуктов

   // Машины доставщиков топлива
   DELIVERY_OIL_TRAIN[3], // Тягач, развозчик топлива
   DELIVERY_OIL_TRAILER[3], // Прицеп - цистерна развозчик топлива

	// Разные машины
	TRAINING[10], // Учебные машины
	MECHANIC[35], // Механики
	TRAIN[3], // Поезда
	BUS[52], // Автобусы
	TAXI[52], // Такси !!!!Уточнить количество!!!
	HOME[MAX_VEHICLES], // Домашние машины

}

new SpawningCars[s_cars][52];

forward AddSpawningCar_GameStart(); // Настройка спавна тачек

public AddSpawningCar_GameStart()
{
   /*==================== Машины фракций ================*/
	SpawningCar_Mafia(); // Заспавним тачки банд и мафий
	SpawningCar_Media(); // Заспавним тачки СМИ
	SpawningCar_Army(); // Заспавним тачки армии
	SpawningCar_Medicine(); // Заспавним тачки мадиков
	SpawningCar_Police(); // Заспавним тачки полиции и FBI
	SpawningCar_Goverment(); // Заспавним тачки правительства (АД + Мэрия)

   /*==================== Прочие =======================*/
	SpawningCar_Fire(); // Заспавним пожарные машины
	SpawningCar_Factory(); // Заспавним тачки завода
	SpawningCar_Mechanic(); // Заспавним машину автомеханика
	SpawningCar_Taxi(); // Заспавним такси
	SpawningCar_Bus(); // Заспавним автобусы
	SpawningCar_Delivery(); // Заспавним транспорт доставщиков продуктов/топлива

	/*===================== Поезда ======================*/
   // Brownstreak
	SpawningCars[TRAIN][0] = AddStaticVehicleEx(538,2285.0352,-1297.1613,25.5006,359.9906,132,132, CAR_RESPAWN_DEFAULT);  // Brownstreak
	SpawningCars[TRAIN][1] = AddStaticVehicleEx(538,2277.5952,-1465.9432,24.4232,349.3316,1,1, CAR_RESPAWN_DEFAULT);  // Brownstreak
	SpawningCars[TRAIN][2] = AddStaticVehicleEx(538,2229.0730,-1597.2704,18.4348,337.3030,252,252, CAR_RESPAWN_DEFAULT);  // Brownstreak

}

SpawningCar_Media()
{
   /*===================== Управляющий СМИ ============*/
	// Sultan
	SpawningCars[F_MEDIA_HEAD][0] = AddStaticVehicleEx(560,1008.0260,1091.7413,10.6953,351.9361,183,183,CAR_RESPAWN_MEDIA); // Sultan

   /*======================= TV ==========================*/
	// Newsvan
	SpawningCars[F_MEDIA_TV][0] = AddStaticVehicleEx(582,1770.3916,-1303.4359,13.7547,3.4884,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][1] = AddStaticVehicleEx(582,1765.8862,-1305.9070,13.7248,0.7819,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][2] = AddStaticVehicleEx(582,1761.1223,-1308.1918,13.7143,0.1618,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][4] = AddStaticVehicleEx(582,1756.0848,-1309.8431,13.7012,358.8379,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][5] = AddStaticVehicleEx(582,1751.0397,-1311.4044,13.7056,359.6368,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][6] = AddStaticVehicleEx(582,1745.9377,-1312.2397,13.6964,359.9788,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_TV][7] = AddStaticVehicleEx(582,1740.6688,-1312.9230,13.7327,359.9171,1,106,CAR_RESPAWN_MEDIA); // Newsvan
	// SAN News Maverick
	SpawningCars[F_MEDIA_TV][3] = AddStaticVehicleEx(488,1823.30004883,-1298.50000000,132.00000000,270.00000000,1,106,CAR_RESPAWN_MEDIA); // SAN News Maverick

	/*====================== Радио ЛС ====================*/
	// Newsvan
	SpawningCars[F_MEDIA_R_LS][0] = AddStaticVehicleEx(582,1667.9680,-1715.0055,15.7050,90.2392,7,6,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LS][1] = AddStaticVehicleEx(582,1667.9772,-1709.9845,15.7055,89.5253,7,6,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LS][2] = AddStaticVehicleEx(582,1667.9673,-1704.9988,15.7044,90.0020,7,6,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LS][3] = AddStaticVehicleEx(582,1667.9652,-1699.9989,15.7132,90.0017,7,6,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LS][4] = AddStaticVehicleEx(582,1667.9689,-1695.0056,15.7138,90.0845,7,6,CAR_RESPAWN_MEDIA); // Newsvan
	// SAN News Maverick
	SpawningCars[F_MEDIA_R_LS][5] = AddStaticVehicleEx(488,1649.4056,-1682.0957,21.6255,180.0008,7,6,CAR_RESPAWN_MEDIA); // SAN News Maverick

	/*======================= Радио ЛВ ===================*/
	// Newsvan
	SpawningCars[F_MEDIA_R_LV][0] = AddStaticVehicleEx(582,2159.7920,2350.6123,10.7663,251.4557,65,3,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LV][1] = AddStaticVehicleEx(582,2153.4153,2352.4438,10.7321,250.0491,65,3,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LV][2] = AddStaticVehicleEx(582,2109.0955,2353.0737,10.7870,292.8784,65,3,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_LV][3] = AddStaticVehicleEx(582,2101.3379,2349.6143,10.7870,296.3011,65,3,CAR_RESPAWN_MEDIA); // Newsvan
   // SAN News Maverick
	SpawningCars[F_MEDIA_R_LV][4] = AddStaticVehicleEx(488,2094.0461,2415.0979,74.7854,89.9997,65,3,CAR_RESPAWN_MEDIA); // SAN News Maverick

   /*====================== Радио СФ ==================*/
	// Newsvan
	SpawningCars[F_MEDIA_R_SF][1] = AddStaticVehicleEx(582,-1787.1304,535.4861,35.2131,58.3202,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_SF][2] = AddStaticVehicleEx(582,-1784.2892,540.1542,35.2101,57.6954,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_SF][3] = AddStaticVehicleEx(582,-1781.4323,544.4192,35.2063,56.4205,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_SF][4] = AddStaticVehicleEx(582,-1778.5715,549.1130,35.1992,55.2886,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_SF][5] = AddStaticVehicleEx(582,-1772.5413,557.8875,35.1338,55.5064,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	SpawningCars[F_MEDIA_R_SF][6] = AddStaticVehicleEx(582,-1775.5465,553.6614,35.1418,55.7691,175,86,CAR_RESPAWN_MEDIA); // Newsvan
	// SAN News Maverick
	SpawningCars[F_MEDIA_R_SF][0] = AddStaticVehicleEx(488,-1827.2756,537.3652,35.2351,0.0020,175,86,CAR_RESPAWN_MEDIA); // SAN News Maverick
}

SpawningCar_Mafia()
{
	/*====================== Якудза ======================*/
   // Stretch
	SpawningCars[F_YAKUZA][0] = AddStaticVehicleEx(409,2611.8999023,1896.5000000,10.6999998,180.0000000,0,0,CAR_RESPAWN_MAFIA); // Stretch
	SpawningCars[F_YAKUZA][1] = AddStaticVehicleEx(409,2615.1999512,1896.5000000,10.6999998,179.9996338,0,0,CAR_RESPAWN_MAFIA); //Stretch
   // Sultan
	SpawningCars[F_YAKUZA][2] = AddStaticVehicleEx(560,2631.3999023,1890.5000000,10.6999998,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Sultan
	SpawningCars[F_YAKUZA][3] = AddStaticVehicleEx(560,2631.3999023,1887.1999512,10.6999998,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Sultan
   // Super GT
	SpawningCars[F_YAKUZA][4] = AddStaticVehicleEx(506,2631.1999512,1880.9000244,10.6000004,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Super GT
	// Stratum
	SpawningCars[F_YAKUZA][5] = AddStaticVehicleEx(561,2583.1000977,1897.8000488,10.6999998,179.9996338,0,0,CAR_RESPAWN_MAFIA); // Stratum
	SpawningCars[F_YAKUZA][6] = AddStaticVehicleEx(561,2576.6240,1897.6914,10.6388,180.5513,0,0,CAR_RESPAWN_MAFIA); // Stratum
   // FCR-900
	SpawningCars[F_YAKUZA][7] = AddStaticVehicleEx(521,2631.0618,1874.2289,10.3826,92.3708,0,0,CAR_RESPAWN_MAFIA); // FCR-900
	SpawningCars[F_YAKUZA][8] = AddStaticVehicleEx(521,2631.2268,1871.1301,10.3894,89.5842,0,0,CAR_RESPAWN_MAFIA); // FCR-900
	SpawningCars[F_YAKUZA][9] = AddStaticVehicleEx(521,2631.2654,1868.1542,10.3911,90.4278,0,0,CAR_RESPAWN_MAFIA); // FCR-900

	/*===================== Русская мафия ====================*/
   // Huntley
	SpawningCars[F_RUSSIAN][0] = AddStaticVehicleEx(579,981.5999756,1723.1999512,8.8000002,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Huntley
	SpawningCars[F_RUSSIAN][1] = AddStaticVehicleEx(579,981.7000122,1744.1999512,8.6999998,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Huntley
	// Rancher
	SpawningCars[F_RUSSIAN][2] = AddStaticVehicleEx(489,957.2000122,1708.4000244,9.0000000,0.0000000,0,0,CAR_RESPAWN_MAFIA); // Rancher
   // Cheetah
	SpawningCars[F_RUSSIAN][3] = AddStaticVehicleEx(415,982.2000122,1733.4000244,8.5000000,90.0000000,0,0,CAR_RESPAWN_MAFIA); // Cheetah
   // Stretch
	SpawningCars[F_RUSSIAN][4] = AddStaticVehicleEx(409,950.4000244,1720.1999512,8.6000004,179.9996338,0,0,CAR_RESPAWN_MAFIA); // Stretch
	SpawningCars[F_RUSSIAN][5] = AddStaticVehicleEx(409,950.4000244,1746.1999512,8.6000004,180.0000000,0,0,CAR_RESPAWN_MAFIA); // Stretch
	// Yosemite
	SpawningCars[F_RUSSIAN][6] = AddStaticVehicleEx(554,962.0593,1708.7124,8.7348,2.0423,0,0,CAR_RESPAWN_MAFIA); // Yosemite
	// Stafford
	SpawningCars[F_RUSSIAN][7] = AddStaticVehicleEx(580,982.5206,1738.9456,8.4460,90.7276,0,0,CAR_RESPAWN_MAFIA); // Stafford
	SpawningCars[F_RUSSIAN][8] = AddStaticVehicleEx(580,982.1812,1728.2660,8.4496,90.9072,0,0,CAR_RESPAWN_MAFIA); // Stafford

   /*===================== La Cosa Nostra ===================*/
	// Stretch
	SpawningCars[F_COSANOSTRA][0] = AddStaticVehicleEx(409,1484.4000244141,2839.6000976563,10.699999809265,180.9996338,0,0,CAR_RESPAWN_MAFIA); // Stretch
	SpawningCars[F_COSANOSTRA][1] = AddStaticVehicleEx(409,1489.5999755859,2839.6000976563,10.699999809265,180.9996338,0,0,CAR_RESPAWN_MAFIA); // Stretch
	// Feltzer
	SpawningCars[F_COSANOSTRA][2] = AddStaticVehicleEx(533,1474.8000488281,2838.3999023438,10.60000038147,180.9996338,0,0,CAR_RESPAWN_MAFIA); // Feltzer
	// Jester
	SpawningCars[F_COSANOSTRA][3] = AddStaticVehicleEx(559,1479.7407,2839.4087,10.4766,179.1468,0,0,CAR_RESPAWN_MAFIA); // Jester
	// Washington
	SpawningCars[F_COSANOSTRA][4] = AddStaticVehicleEx(421,1474.6999511719,2845.8000488281,10.800000190735,180.9996338,0,0,CAR_RESPAWN_MAFIA); // Washington
	SpawningCars[F_COSANOSTRA][5] = AddStaticVehicleEx(421,1479.5999755859,2845.8000488281,10.800000190735,180.9996338,0,0,CAR_RESPAWN_MAFIA); // Washington
	// Windsor
	SpawningCars[F_COSANOSTRA][6] = AddStaticVehicleEx(555,1470.2313,2838.6360,10.5050,179.3358,0,0,CAR_RESPAWN_MAFIA); // Windsor
   // Caddy
	SpawningCars[F_COSANOSTRA][7] = AddStaticVehicleEx(457,1470.2804,2845.8867,10.4456,179.5635,0,0,CAR_RESPAWN_MAFIA); // Caddy

	/*====================== Ацтеки =======================*/
	// Remington
	SpawningCars[F_AZTECAS][0] = AddStaticVehicleEx(534,2190.3999023,-1802.0999756,13.3999996,0.0000000,2,1,CAR_RESPAWN_MAFIA);// Remington
	SpawningCars[F_AZTECAS][1] = AddStaticVehicleEx(534,2190.3999023,-1790.8000488,13.3999996,0.0000000,2,1,CAR_RESPAWN_MAFIA); // Remington
	// Savanna
	SpawningCars[F_AZTECAS][2] = AddStaticVehicleEx(567,2174.3999023,-1810.3000488,13.3999996,270.0000000,2,1,CAR_RESPAWN_MAFIA); // Savanna
	SpawningCars[F_AZTECAS][3] = AddStaticVehicleEx(567,2166.5000000,-1810.3000488,13.3999996,270.0000000,2,1,CAR_RESPAWN_MAFIA); // Savanna
	// Broadway
	SpawningCars[F_AZTECAS][4] = AddStaticVehicleEx(575,2174.3999023,-1805.8000488,13.1000004,270.0000000,2,1,CAR_RESPAWN_MAFIA); // Broadway
	SpawningCars[F_AZTECAS][5] = AddStaticVehicleEx(575,2166.6999512,-1805.6999512,13.1000004,270.0000000,2,1,CAR_RESPAWN_MAFIA);// Broadway

   /*======================= Vagos =====================*/
   // Oceanic
	SpawningCars[F_VAGOS][0] = AddStaticVehicleEx(467,2745.3000488,-1184.3000488,69.3000031,0.0000000,6,1,CAR_RESPAWN_MAFIA); // Oceanic
	SpawningCars[F_VAGOS][1] = AddStaticVehicleEx(467,2760.5000000,-1175.5999756,69.3000031,90.0000000,6,1,CAR_RESPAWN_MAFIA); // Oceanic
	SpawningCars[F_VAGOS][2] = AddStaticVehicleEx(467,2753.3999023,-1175.5999756,69.3000031,90.0000000,6,1,CAR_RESPAWN_MAFIA); // Oceanic
	// Hermes
	SpawningCars[F_VAGOS][3] = AddStaticVehicleEx(474,2745.0000000,-1163.8000488,69.4000015,0.0000000,6,1,CAR_RESPAWN_MAFIA); // Hermes
	SpawningCars[F_VAGOS][4] = AddStaticVehicleEx(474,2745.0000000,-1154.8000488,69.5000000,0.0000000,6,1,CAR_RESPAWN_MAFIA); // Hermes
	SpawningCars[F_VAGOS][5] = AddStaticVehicleEx(474,2744.8447,-1144.7765,69.3419,1.3581,6,1,CAR_RESPAWN_MAFIA); // Hermes

	/*======================= RIFA ====================*/
	// Stallion
	SpawningCars[F_RIFA][0] = AddStaticVehicleEx(439,2773.8999023,-1926.3000488,13.3000002,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Stallion
	SpawningCars[F_RIFA][1] = AddStaticVehicleEx(439,2773.8000488,-1945.0000000,13.3000002,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Stallion
	SpawningCars[F_RIFA][2] = AddStaticVehicleEx(439,2764.8000488,-1944.9000244,13.3000002,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Stallion
	SpawningCars[F_RIFA][3] = AddStaticVehicleEx(439,2764.6000977,-1926.1999512,13.3000002,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Stallion
	// Tahoma
	SpawningCars[F_RIFA][4] = AddStaticVehicleEx(566,2764.6999512,-1935.4000244,13.1999998,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Tahoma
	SpawningCars[F_RIFA][5] = AddStaticVehicleEx(566,2773.8000488,-1935.5000000,13.1999998,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Tahoma
	// Feltzer
	SpawningCars[F_RIFA][5] = AddStaticVehicleEx(533,2776.1999512,-1914.4000244,12.3999996,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Feltzer
	SpawningCars[F_RIFA][7] = AddStaticVehicleEx(533,2762.8999023,-1914.5999756,12.3999996,0.0000000,162,1,CAR_RESPAWN_MAFIA); // Feltzer

   /*====================== Ballas ===================*/
	// Washington
	SpawningCars[F_BALLAS][0] = AddStaticVehicleEx(421,2020.2743,-1142.7402,24.8026,269.5850,233,88,CAR_RESPAWN_MAFIA); // Washington
	SpawningCars[F_BALLAS][1] = AddStaticVehicleEx(421,2028.1865,-1128.8131,24.5909,269.3274,233,88,CAR_RESPAWN_MAFIA); // Washington
	SpawningCars[F_BALLAS][5] = AddStaticVehicleEx(421,2038.2279,-1128.7406,24.2974,269.5583,233,88,CAR_RESPAWN_MAFIA); // Washington
	// Virgo
	SpawningCars[F_BALLAS][2] = AddStaticVehicleEx(491,2008.90002441,-1142.80004883,25.00000000,270.00000000,233,88,CAR_RESPAWN_MAFIA); // Virgo
	SpawningCars[F_BALLAS][3] = AddStaticVehicleEx(491,2018.50000000,-1128.80004883,24.89999962,270.00000000,233,88,CAR_RESPAWN_MAFIA); // Virgo
	SpawningCars[F_BALLAS][4] = AddStaticVehicleEx(491,2033.19995117,-1142.90002441,24.40999985,270.00000000,233,88,CAR_RESPAWN_MAFIA); // Virgo
	SpawningCars[F_BALLAS][6] = AddStaticVehicleEx(491,2049.0732,-1128.6858,23.8710,270.0690,233,88,CAR_RESPAWN_MAFIA); // Virgo

   /*====================== Grove street =============*/
   // Greenwood
	SpawningCars[F_GROVE][0] = AddStaticVehicleEx(492,2497.8928,-1679.3967,13.1442,0.2221,229,1,CAR_RESPAWN_MAFIA); // Greenwood
	SpawningCars[F_GROVE][1] = AddStaticVehicleEx(492,2493.3198,-1680.9476,13.0541,3.2488,229,1,CAR_RESPAWN_MAFIA); // Greenwood
	SpawningCars[F_GROVE][2] = AddStaticVehicleEx(492,2488.1006,-1680.6553,13.0593,355.2292,229,1,CAR_RESPAWN_MAFIA); // Greenwood
	// Glendale
	SpawningCars[F_GROVE][3] = AddStaticVehicleEx(466,2473.3557,-1674.4131,13.1264,268.2380,229,1,CAR_RESPAWN_MAFIA); // Glendale
	SpawningCars[F_GROVE][4] = AddStaticVehicleEx(466,2472.4026,-1670.5088,12.9852,270.2275,229,1,CAR_RESPAWN_MAFIA); // Glendale
	SpawningCars[F_GROVE][5] = AddStaticVehicleEx(466,2471.6062,-1666.5878,13.0712,269.6280,229,1,CAR_RESPAWN_MAFIA); // Glendale

}

SpawningCar_Factory()
{
   // Тягачи,  Linerunner
	SpawningCars[FACTORY_TRAIN][0] = AddStaticVehicleEx(403, -0.1539,-304.6792,6.0343,90.2252, 103, 103, 60); // Linerunner
	SpawningCars[FACTORY_TRAIN][1] = AddStaticVehicleEx(403, -0.1262,-311.7316,6.0223,90.2252, 103, 103, 60); // Linerunner
	SpawningCars[FACTORY_TRAIN][2] = AddStaticVehicleEx(403, -0.0990,-318.6402,6.0105,90.2252, 103, 103, 60); // Linerunner
	SpawningCars[FACTORY_TRAIN][3] = AddStaticVehicleEx(403, -0.0706,-325.8719,5.9981,90.2252, 103, 103, 60); // Linerunner

   // Прицепы для тягочей, Petrol Trailer
	SpawningCars[FACTORY_TRAILER][0] = AddStaticVehicleEx(584, -6.2845,-376.9568,6.5982,359.6887, 103, 103, 80); // Petrol Trailer
	SpawningCars[FACTORY_TRAILER][1] = AddStaticVehicleEx(584, -13.0054,-376.9966,6.5674,0.2270, 103, 103, 80); // Petrol Trailer
	SpawningCars[FACTORY_TRAILER][2] = AddStaticVehicleEx(584, -19.8373,-377.0236,6.5864,0.2283, 103, 103, 80); // Petrol Trailer
	SpawningCars[FACTORY_TRAILER][3] = AddStaticVehicleEx(584, -26.4430,-377.0499,6.5863,0.2283, 103, 103, 80); // Petrol Trailer

	// Фургоны, Boxville
	SpawningCars[FACTORY_WAGON][0] = AddStaticVehicleEx(498, -62.8731,-321.5614,5.5005,270.9580, 2, 154, 6); // Boxville
	SpawningCars[FACTORY_WAGON][2] = AddStaticVehicleEx(498, -62.9906,-314.2425,5.4976,270.9580, 2, 154, 6); // Boxville
	SpawningCars[FACTORY_WAGON][2] = AddStaticVehicleEx(498, -63.1243,-307.4265,5.4988,270.9580, 2, 154, 6); // Boxville
	SpawningCars[FACTORY_WAGON][3] = AddStaticVehicleEx(498, -63.0641,-300.9588,5.5005,270.9580, 2, 154, 6); // Boxville

}

SpawningCar_Army()
{
	/*=================== Министр обороны ==========================*/
   // Sultan
	SpawningCars[F_ARMY_HEAD][0]  = AddStaticVehicleEx(560,1010.8609,1100.5195,10.6962,332.2751,244,244,CAR_RESPAWN_ARMY); // Sultan

	/*================== Военно воздушные силы =====================*/
	// Patriot
	SpawningCars[F_ARMY_AIR][0]   = AddStaticVehicleEx(470,397.3047,2535.2148,16.5789,90.1078,43,0,CAR_RESPAWN_ARMY); // Patriot
	SpawningCars[F_ARMY_AIR][1]   = AddStaticVehicleEx(470,397.3361,2530.7119,16.5766,89.9389,43,0,CAR_RESPAWN_ARMY); // Patriot
	// Mesa
	SpawningCars[F_ARMY_AIR][2]   = AddStaticVehicleEx(500,392.7497,2546.5559,16.6748,180.0972,61,55,CAR_RESPAWN_ARMY); // Mesa
	SpawningCars[F_ARMY_AIR][3]   = AddStaticVehicleEx(500,388.5283,2546.3430,16.6713,179.6227,61,55,CAR_RESPAWN_ARMY); // Mesa
	// Helicopter: Cargobob
	SpawningCars[F_ARMY_AIR][4]   = AddStaticVehicleEx(548,347.7133,2542.3130,18.2415,180.3255,1,6,CAR_RESPAWN_ARMY); // Cargobob
   // Helicopter: Hunter
	SpawningCars[F_ARMY_AIR][5]   = AddStaticVehicleEx(425,365.5637,2548.9656,17.1384,182.6109,43,0,CAR_RESPAWN_ARMY); // Hunter
   // Air: Shamal
	SpawningCars[F_ARMY_AIR][6]   = AddStaticVehicleEx(519,404.7836,2463.3899,17.3967,8.6578,1,1,CAR_RESPAWN_ARMY); // Shamal
	SpawningCars[F_ARMY_AIR][7]   = AddStaticVehicleEx(519,394.0843,2445.4019,17.3710,357.4180,1,1,CAR_RESPAWN_ARMY); // Shamal
	SpawningCars[F_ARMY_AIR][8]   = AddStaticVehicleEx(519,414.5698,2445.6204,17.3747,359.9147,1,1,CAR_RESPAWN_ARMY); // Shamal
	// Helicopter: Maverick
	SpawningCars[F_ARMY_AIR][9]   = AddStaticVehicleEx(487,377.1948,2541.5298,16.6708,179.9936,61,55,CAR_RESPAWN_ARMY); // Maverick
   // Air: Hydra
	SpawningCars[F_ARMY_AIR][10]  = AddStaticVehicleEx(520,325.4445,2544.5112,17.5385,180.0015,0,0,CAR_RESPAWN_ARMY); // Hydra
	SpawningCars[F_ARMY_AIR][11]  = AddStaticVehicleEx(520,290.4938,2544.6924,17.5432,177.9054,0,0,CAR_RESPAWN_ARMY); // Hydra

	/*=============== Сухопутные войска ==========================*/
	// Barracks
	SpawningCars[F_ARMY_LAND][0]  = AddStaticVehicleEx(433,274.5160,1949.0681,18.0040,270.0539,43,0,CAR_RESPAWN_ARMY); // Barracks
	SpawningCars[F_ARMY_LAND][1]  = AddStaticVehicleEx(433,274.5683,1955.9941,18.0038,270.0000,43,0,CAR_RESPAWN_ARMY); // Barracks
	SpawningCars[F_ARMY_LAND][2]  = AddStaticVehicleEx(433,274.5868,1962.3256,18.1469,269.3572,43,0,CAR_RESPAWN_ARMY); // Barracks
	SpawningCars[F_ARMY_LAND][3]  = AddStaticVehicleEx(433,274.5809,1990.0187,18.1469,270.0000,43,0,CAR_RESPAWN_ARMY); // Barracks
	SpawningCars[F_ARMY_LAND][4]  = AddStaticVehicleEx(433,274.5736,1996.8099,18.1549,270.1160,43,0,CAR_RESPAWN_ARMY); // Barracks
   // Patriot
	SpawningCars[F_ARMY_LAND][5]  = AddStaticVehicleEx(470,277.0513,2015.7279,17.6740,270.0006,43,0,CAR_RESPAWN_ARMY); // Patriot
	SpawningCars[F_ARMY_LAND][6]  = AddStaticVehicleEx(470,277.0479,2021.0112,17.6693,270.0392,43,0,CAR_RESPAWN_ARMY); // Patriot
	SpawningCars[F_ARMY_LAND][7]  = AddStaticVehicleEx(470,277.0502,2026.4551,17.6640,270.0471,43,0,CAR_RESPAWN_ARMY); // Patriot
	SpawningCars[F_ARMY_LAND][8]  = AddStaticVehicleEx(470,277.0414,2032.0011,17.6176,270.4648,43,0,CAR_RESPAWN_ARMY); // Patriot
	// Mesa
	SpawningCars[F_ARMY_LAND][9]  = AddStaticVehicleEx(500,193.3515,1919.0298,17.7523,179.2473,174,174,CAR_RESPAWN_ARMY); // Mesa
	SpawningCars[F_ARMY_LAND][10] = AddStaticVehicleEx(500,202.7526,1919.1581,17.7538,180.7017,174,174,CAR_RESPAWN_ARMY); // Mesa
   // Huntley
	SpawningCars[F_ARMY_LAND][11] = AddStaticVehicleEx(579,211.4938,1918.2955,17.5796,179.3745,174,174,CAR_RESPAWN_ARMY); // Huntley
   // Admiral
	SpawningCars[F_ARMY_LAND][12] = AddStaticVehicleEx(445,220.6578,1917.9929,17.5153,180.1715,174,174,CAR_RESPAWN_ARMY); // Admiral
   // Bus
	SpawningCars[F_ARMY_LAND][13] = AddStaticVehicleEx(431,241.0248,1818.0791,17.7482,270.8608,174,174,CAR_RESPAWN_ARMY); // Bus

   /*================== Военно морской флот ================*/
	// Helicopter: Leviathan
	SpawningCars[F_ARMY_WATER][0] = AddStaticVehicleEx(417,-2227.5254,2324.8105,7.5872,180.0603,6,7,CAR_RESPAWN_ARMY); // Leviathan
	// Admiral
	SpawningCars[F_ARMY_WATER][1] = AddStaticVehicleEx(445,-2252.2585,2336.0925,4.6383,91.1596,108,123,CAR_RESPAWN_ARMY); // Admiral
	// Mesa
	SpawningCars[F_ARMY_WATER][2] = AddStaticVehicleEx(500,-2252.5540,2324.0581,4.9341,89.4805,108,123,CAR_RESPAWN_ARMY); // Mesa
	SpawningCars[F_ARMY_WATER][3] = AddStaticVehicleEx(500,-2252.6606,2317.9177,4.9441,90.2882,108,123,CAR_RESPAWN_ARMY); // Mesa
   // Patriot
	SpawningCars[F_ARMY_WATER][4] = AddStaticVehicleEx(470,-2252.2771,2311.9963,4.8326,90.1133,108,123,CAR_RESPAWN_ARMY); // Patriot
	SpawningCars[F_ARMY_WATER][5] = AddStaticVehicleEx(470,-2252.3040,2306.0776,4.8334,90.1192,108,123,CAR_RESPAWN_ARMY); // Patriot
	// Boat: Speeder
	SpawningCars[F_ARMY_WATER][6] = AddStaticVehicleEx(452,-2224.0969238,2398.6599121,0.0000000,46.0000000,119,1,CAR_RESPAWN_ARMY); // Speeder
   // Boat: Launch
	SpawningCars[F_ARMY_WATER][7] = AddStaticVehicleEx(595,-2235.8911133,2450.1140137,0.0000000,224.0000000,-1,-1,CAR_RESPAWN_ARMY); // Launch
	SpawningCars[F_ARMY_WATER][8] = AddStaticVehicleEx(595,-2241.6298828,2444.4040527,0.0000000,223.9947510,-1,-1,CAR_RESPAWN_ARMY); // Launch
	// Boat: Marquis
	SpawningCars[F_ARMY_WATER][9] = AddStaticVehicleEx(484,-2203.5810547,2419.4360352,0.0000000,44.7500000,-1,-1,CAR_RESPAWN_ARMY); // Marquis
	SpawningCars[F_ARMY_WATER][10] = AddStaticVehicleEx(484,-2211.3811035,2411.9609375,0.0000000,44.7473145,-1,-1,CAR_RESPAWN_ARMY); // Marquis
	// Boat: Tropic
	SpawningCars[F_ARMY_WATER][11] = AddStaticVehicleEx(454,-2254.6298828,2431.2470703,0.0000000,226.0000000,-1,-1,CAR_RESPAWN_ARMY); // Tropic
	// Boat: Coastguard
	SpawningCars[F_ARMY_WATER][12] = AddStaticVehicleEx(472,-2231.4509277,2393.7690430,0.0000000,44.0000000,-1,-1,CAR_RESPAWN_ARMY); // Coastguard
	SpawningCars[F_ARMY_WATER][13] = AddStaticVehicleEx(472,-2259.3540039,2421.6469727,0.0000000,225.9947510,-1,-1,CAR_RESPAWN_ARMY); // Coastguard

	/*================ Машины снабжения ====================*/
   // ВВС, Flatbed
	SpawningCars[F_ARMY_SUPPLY][0] = AddStaticVehicleEx(455,371.2784,2591.4421,16.8091,192.3828,84,31,CAR_RESPAWN_ARMY); // Flatbed
	// СВ, Flatbed
	SpawningCars[F_ARMY_SUPPLY][1] = AddStaticVehicleEx(455,280.20001221,1982.59997559,18.20000076,269.00000000,2,2,CAR_RESPAWN_ARMY); //Flatbed
	// ВМФ, Flatbed
	SpawningCars[F_ARMY_SUPPLY][1] = AddStaticVehicleEx(455,-2253.7468,2299.9255,5.3302,90.056,2,2,CAR_RESPAWN_ARMY); //Flatbed
}

SpawningCar_Fire()
{
   /*================= Пожарная часть ЛС =================*/
	// Firetruck LA
	SpawningCars[FIRE_LS][0] = AddStaticVehicle(544,1751.9188,-1455.6445,13.8662,260.5750,3,1); // Firetruck LA
   // Firetruck
	SpawningCars[FIRE_LS][1] = AddStaticVehicle(407,1743.9153,-1477.7180,13.5937,269.7896,3,1); // Firetruck
	SpawningCars[FIRE_LS][2] = AddStaticVehicle(407,1760.8300,-1484.3986,13.6650,356.1240,3,1); // Firetruck
	SpawningCars[FIRE_LS][3] = AddStaticVehicle(407,1765.3229,-1484.8879,13.4734,355.3812,3,1); // Firetruck

   /*================= Пожарная часть ЛВ ================*/
   // Firetruck LA
	SpawningCars[FIRE_LV][0] = AddStaticVehicle(544,1752.2098,2073.7402,10.9739,179.9793,3,1); // Firetruck LA
	SpawningCars[FIRE_LV][1] = AddStaticVehicle(544,1757.0265,2073.7439,10.9727,180.2391,3,1); // Firetruck LA
	// Firetruck
	SpawningCars[FIRE_LV][2] = AddStaticVehicle(407,1761.8457,2076.1489,10.9773,180.6374,3,1); // Firetruck
	SpawningCars[FIRE_LV][3] = AddStaticVehicle(407,1766.6324,2076.1436,10.9741,180.0033,3,1); // Firetruck
	SpawningCars[FIRE_LV][4] = AddStaticVehicle(407,1771.1188,2076.1755,11.1573,181.0065,3,1); // Firetruck

	/*================ Пожарная часть СФ ===============*/
	// Firetruck
	SpawningCars[FIRE_SF][0] = AddStaticVehicle(407,-2021.9474,75.3251,28.2667,269.4560,3,1); // Firetruck
	SpawningCars[FIRE_SF][1] = AddStaticVehicle(407,-2021.7711,81.8884,28.1666,270.0068,3,1); // Firetruck
	SpawningCars[FIRE_SF][2] = AddStaticVehicle(407,-2021.5376,85.6347,28.1727,272.9774,3,1); // Firetruck
	// Firetruck LA
	SpawningCars[FIRE_SF][3] = AddStaticVehicle(544,-2019.1667,90.5363,28.1425,269.6470,3,1); // Firetruck LA
	SpawningCars[FIRE_SF][4] = AddStaticVehicle(544,-2019.6837,94.4696,28.1080,273.1239,3,1); // Firetruck LA

}

SpawningCar_Taxi()
{
	/* TAXI[0] = AddStaticVehicleEx(420,-1977.1999512,171.6000061,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.3000488,175.6000061,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.3000488,179.8999939,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.4000244,184.3999939,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.3000488,189.1000061,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.4000244,194.1999969,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2676.6821,-54.9553,4.1147,0.2495,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2673.1711,-54.8319,4.1155,359.9188,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2670.0266,-54.8799,4.1140,0.1039,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2666.6143,-54.7650,4.1155,0.2619,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2663.2800,-55.0971,4.1138,359.2150,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2679.7874,-54.9202,4.1149,358.9979,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-1977.5000000,199.0000000,27.5000000,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,-2683.2722,-55.0508,4.1150,359.0473,6,1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(438,-2724.6999512,408.8999939,4.5999999,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie
	AddStaticVehicleEx(438,-2735.0000000,408.8999939,4.5999999,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie

	AddStaticVehicleEx(420,1062.9000244,-1737.3000488,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1740.5000000,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1749.1999512,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1752.1999512,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1746.4000244,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1743.4000244,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1766.8000488,13.1999998,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1760.9000244,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1763.9000244,13.1999998,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1758.0000000,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.8000488,-1769.6999512,13.1999998,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.6999512,-1755.1999512,13.3000002,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.6999512,-1772.8000488,13.1999998,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,1062.5999756,-1775.9000244,13.1999998,270.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi

	AddStaticVehicleEx(438,1438.9000244,-1699.1999512,13.6999998,180.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie
	AddStaticVehicleEx(438,1438.9000244,-1710.8000488,13.6999998,179.9996338,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie
	AddStaticVehicleEx(438,1438.9000244,-1685.6999512,13.6999998,180.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie

	AddStaticVehicleEx(420,2853.3000488,1348.5999756,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.3999023,1352.0000000,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.5000000,1358.4000244,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.3999023,1355.0999756,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.6000977,1361.5999756,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.6000977,1364.8000488,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(420,2853.6000977,1368.0000000,10.6999998,90.0000000,-1,-1,CAR_RESPAWN_WORKERS); //Taxi
	AddStaticVehicleEx(438,2374.8999023,2435.3000488,11.0000000,179.9996338,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie
	TAXI[1] = AddStaticVehicleEx(438,2374.8999023,2443.6000977,11.0000000,179.9996338,-1,-1,CAR_RESPAWN_WORKERS); //Cabbie */
}

SpawningCar_Medicine()
{
	/*====================== Министр здравохранения =====*/
   // Sultan
	SpawningCars[F_MED_HEAD][0] = AddStaticVehicleEx(560,1005.9003,1073.8079,10.6958,355.1549,17,17,CAR_RESPAWN_MEDICINE); // Sultan

	/*====================== Больница ЛС ================*/
	// Ambulance
	SpawningCars[F_MED_LS][0] = AddStaticVehicleEx(416,1195.7172,-1296.8813,13.4008,270.1106,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][1] = AddStaticVehicleEx(416,1195.9601,-1302.0042,13.4362,268.2237,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][2] = AddStaticVehicleEx(416,1195.8704,-1307.3459,13.4384,272.0492,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][4] = AddStaticVehicleEx(416,1195.7218,-1313.0815,13.4434,270.0023,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][5] = AddStaticVehicleEx(416,1195.7727,-1359.3448,13.3828,272.1497,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][6] = AddStaticVehicleEx(416,1195.9546,-1353.7596,13.4165,268.8787,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LS][7] = AddStaticVehicleEx(416,1195.7141,-1348.3986,13.4185,269.9338,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	// Helicopter: Maverick
	SpawningCars[F_MED_LS][3] = AddStaticVehicleEx(487,1194.1514,-1340.8085,13.5357,270.0017,1,3,CAR_RESPAWN_MEDICINE); // Maverick

   /*==================== Больница ЛВ =================*/
	// Ambulance
	SpawningCars[F_MED_LV][0] = AddStaticVehicleEx(416,1624.3859,1819.3165,11.0072,1.5376,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LV][1] = AddStaticVehicleEx(416,1612.7206,1840.5051,10.9143,358.2565,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LV][2] = AddStaticVehicleEx(416,1606.6171,1840.6438,11.0128,1.6390,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LV][3] = AddStaticVehicleEx(416,1599.6981,1841.1461,11.0062,358.5846,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_LV][5] = AddStaticVehicleEx(416,1593.7603,1840.7946,11.0022,2.1219,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	// Helicopter: Maverick
	SpawningCars[F_MED_LV][4] = AddStaticVehicleEx(487,1621.0460,1854.2583,10.9766,272.4377,1,3,CAR_RESPAWN_MEDICINE); // Maverick

   /*=================== Больница СФ ==================*/
   // Ambulance
	SpawningCars[F_MED_SF][1] = AddStaticVehicleEx(416,-2644.4622,590.1524,14.5152,180.0018,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][2] = AddStaticVehicleEx(416,-2678.5566,590.1783,14.6520,179.8927,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][3] = AddStaticVehicleEx(416,-2672.8425,590.2576,14.4801,178.5125,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][4] = AddStaticVehicleEx(416,-2667.1362,590.1206,14.6025,178.4187,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][5] = AddStaticVehicleEx(416,-2661.3840,590.1006,14.6419,178.8655,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][6] = AddStaticVehicleEx(416,-2655.9351,590.2794,14.4807,176.8300,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
	SpawningCars[F_MED_SF][7] = AddStaticVehicleEx(416,-2650.4019,590.2496,14.6020,178.0029,1,3,CAR_RESPAWN_MEDICINE); // Ambulance
   // Helicopter: Maverick
	SpawningCars[F_MED_SF][0] = AddStaticVehicleEx(487,-2591.5889,607.1993,14.6019,180.0001,1,3,CAR_RESPAWN_MEDICINE); // Maverick
}

SpawningCar_Police()
{
   /*============== Министр внутренних дел ==========*/
   // Sultan
	SpawningCars[F_POLICE_HEAD][0] = AddStaticVehicleEx(560,1006.8404,1082.8479,10.6962,352.9888,79,79,CAR_RESPAWN_POLICE); // Sultan

   /*================== FBI =========================*/
	// Enforcer
	SpawningCars[F_POLICE_FBI][0] = AddStaticVehicleEx(427,-2441.3005,523.5311,30.0553,179.9364,0,0,CAR_RESPAWN_POLICE); // Enforcer
	// FBI Rancher
	SpawningCars[F_POLICE_FBI][1] = AddStaticVehicleEx(490,-2425.7998,518.2865,29.8609,220.9706,0,0,CAR_RESPAWN_POLICE); // FBI Rancher
	SpawningCars[F_POLICE_FBI][2] = AddStaticVehicleEx(490,-2429.6963,515.4611,29.8795,215.7738,0,0,CAR_RESPAWN_POLICE); // FBI Rancher
	SpawningCars[F_POLICE_FBI][3] = AddStaticVehicleEx(490,-2422.3557,521.4836,29.8831,225.1303,0,0,CAR_RESPAWN_POLICE); // FBI Rancher
	SpawningCars[F_POLICE_FBI][4] = AddStaticVehicleEx(490,-2419.1292,524.8925,29.9017,230.1783,0,0,CAR_RESPAWN_POLICE); // FBI Rancher
	SpawningCars[F_POLICE_FBI][5] = AddStaticVehicleEx(490,-2416.4453,528.4032,29.9028,238.2431,0,0,CAR_RESPAWN_POLICE); // FBI Rancher
   // Admiral
	SpawningCars[F_POLICE_FBI][6] = AddStaticVehicleEx(445,-2415.0222,532.1198,29.7547,249.6213,0,0,CAR_RESPAWN_POLICE); // Admiral
   // Cheetah + FLASHER
	SpawningCars[F_POLICE_FBI][7] = AddStaticVehicleEx(415,-2414.0459,535.9401,29.7066,257.7313,0,0,CAR_RESPAWN_POLICE); // Cheetah
	// Burrito
	SpawningCars[F_POLICE_FBI][8] = AddStaticVehicleEx(482,-2413.7783,539.9514,30.0778,267.6446,0,0,CAR_RESPAWN_POLICE); // Burrito
	// Helicopter: Maverick
	SpawningCars[F_POLICE_FBI][9] = AddStaticVehicleEx(487,-2439.2722,523.6176,34.3661,180.0013,0,0,CAR_RESPAWN_POLICE); // Maverick

   /*============ Полиция ЛС =====================*/
	// Police Car (LSPD)
	SpawningCars[F_POLICE_LS][0] = AddStaticVehicleEx(596,1595.5294,-1710.4364,5.5554,359.9512,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][1] = AddStaticVehicleEx(596,1591.4102,-1710.4376,5.5512,359.9007,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][2] = AddStaticVehicleEx(596,1587.3835,-1710.4337,5.6186,0.0181,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][3] = AddStaticVehicleEx(596,1583.4680,-1710.4301,5.5567,359.9969,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][4] = AddStaticVehicleEx(596,1578.5658,-1710.4299,5.5568,359.9970,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][5] = AddStaticVehicleEx(596,1574.4985,-1710.4314,5.5677,359.9968,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][7] = AddStaticVehicleEx(596,1544.9449,-1684.5110,5.6010,90.0019,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][8] = AddStaticVehicleEx(596,1544.9449,-1680.4857,5.5985,90.0023,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][9] = AddStaticVehicleEx(596,1544.9290,-1675.8738,5.5502,89.9997,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][10] = AddStaticVehicleEx(596,1544.9286,-1672.1986,5.5487,90.1238,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	SpawningCars[F_POLICE_LS][11] = AddStaticVehicleEx(596,1544.9312,-1668.0057,5.6191,90.3254,125,1,CAR_RESPAWN_POLICE); // Police Car (LSPD)
	// FBI Truck
	SpawningCars[F_POLICE_LS][12] = AddStaticVehicleEx(528,1544.9625,-1659.0891,5.8918,90.1139,125,1,CAR_RESPAWN_POLICE); // FBI Truck
   // Enforcer
	SpawningCars[F_POLICE_LS][13] = AddStaticVehicleEx(427,1538.4792,-1645.9200,6.0634,180.0354,125,1,CAR_RESPAWN_POLICE); // Enforcer
	SpawningCars[F_POLICE_LS][14] = AddStaticVehicleEx(427,1534.7783,-1645.9224,6.0509,179.6709,125,1,CAR_RESPAWN_POLICE); // Enforcer
   // Helicopter: Police Maverick
	SpawningCars[F_POLICE_LS][15] = AddStaticVehicleEx(497,1551.4473,-1609.3640,13.5117,90.0019,125,1,CAR_RESPAWN_POLICE); // Police Maverick
   // Cheetah + FLASHER
	SpawningCars[F_POLICE_LS][6] = AddStaticVehicleEx(415,1570.2262,-1710.4408,5.6353,359.9994,1,1,CAR_RESPAWN_POLICE); // Cheetah

	/*================= Полиция ЛВ ================*/
   // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][0] = AddStaticVehicleEx(598,2272.5278,2430.7625,3.0029,0.0011,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][1] = AddStaticVehicleEx(598,2268.1873,2430.7576,3.0056,359.8773,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][2] = AddStaticVehicleEx(598,2263.6909,2430.7607,3.0042,359.9790,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][3] = AddStaticVehicleEx(598,2259.5288,2430.7576,3.0023,0.1146,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][4] = AddStaticVehicleEx(598,2239.5972,2437.4282,3.0449,269.9994,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][5] = AddStaticVehicleEx(598,2239.5930,2442.3853,3.0380,270.0208,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][6] = AddStaticVehicleEx(598,2239.5986,2447.0454,3.0465,269.9959,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	SpawningCars[F_POLICE_LV][7] = AddStaticVehicleEx(598,2239.5989,2452.0015,3.0463,269.9926,125,1,CAR_RESPAWN_POLICE); // Police Car (LVPD)
	// Police Ranger
	SpawningCars[F_POLICE_LV][10] = AddStaticVehicleEx(599,2239.5793,2466.3608,3.3981,269.9940,125,1,CAR_RESPAWN_POLICE); // Police Ranger
	// Enforcer
	SpawningCars[F_POLICE_LV][11] = AddStaticVehicleEx(427,2263.5732,2474.3376,3.4052,360.0000,125,1,CAR_RESPAWN_POLICE); // Enforcer
	SpawningCars[F_POLICE_LV][12] = AddStaticVehicleEx(427,2268.1692,2474.3049,3.4053,358.9745,125,1,CAR_RESPAWN_POLICE); // Enforcer
   // FBI Truck
	SpawningCars[F_POLICE_LV][13] = AddStaticVehicleEx(528,2272.5574,2474.8848,3.3187,357.6134,6,6,CAR_RESPAWN_POLICE); // FBI Truck
   // Cheetah + FLASHER
	SpawningCars[F_POLICE_LV][8] = AddStaticVehicleEx(415,2239.5964,2456.8318,2.9965,267.3014,1,1,CAR_RESPAWN_POLICE); // Cheetah

	/*=============== Полиция СФ ================*/
	// Police Car (SFPD)
	SpawningCars[F_POLICE_SF][1] = AddStaticVehicleEx(597,-1573.1211,742.8321,-5.5223,90.9742,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][2] = AddStaticVehicleEx(597,-1573.1511,738.7425,-5.4791,91.1489,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][3] = AddStaticVehicleEx(597,-1573.1152,734.8708,-5.4727,91.7343,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][4] = AddStaticVehicleEx(597,-1573.1600,730.4979,-5.5373,88.0672,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][5] = AddStaticVehicleEx(597,-1573.0562,726.3375,-5.5381,85.1793,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][6] = AddStaticVehicleEx(597,-1608.5082,693.3780,-5.4683,183.2357,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][7] = AddStaticVehicleEx(597,-1612.4927,693.3866,-5.4868,182.7922,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][8] = AddStaticVehicleEx(597,-1616.5481,693.4748,-5.4875,177.8815,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][9] = AddStaticVehicleEx(597,-1620.9077,693.3848,-5.4624,181.6400,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	SpawningCars[F_POLICE_SF][10] = AddStaticVehicleEx(597,-1624.9263,693.3171,-5.4729,177.6892,125,1,CAR_RESPAWN_POLICE); // Police Car (SFPD)
	// Enforcer
	SpawningCars[F_POLICE_SF][11] = AddStaticVehicleEx(427,-1638.6704,661.6256,-5.0797,271.1700,125,1,CAR_RESPAWN_POLICE); // Enforcer
	SpawningCars[F_POLICE_SF][12] = AddStaticVehicleEx(427,-1638.6851,657.9620,-5.0789,269.8145,125,1,CAR_RESPAWN_POLICE); // Enforcer
	// FBI Truck
	SpawningCars[F_POLICE_SF][14] = AddStaticVehicleEx(528,-1638.9502,678.1618,-5.1970,269.6913,0,0,CAR_RESPAWN_POLICE); // FBI Truck
	// Helicopter: Police Maverick
	SpawningCars[F_POLICE_SF][0] = AddStaticVehicleEx(497,-1679.8148,705.7831,30.7790,90.0109,125,1,CAR_RESPAWN_POLICE); // Police Maverick
	// Cheetah + FLASHER
	SpawningCars[F_POLICE_SF][13] = AddStaticVehicleEx(415,-1573.5740,722.3093,-5.5658,90.0000,1,1,CAR_RESPAWN_POLICE); // Cheetah

	/*================= Привяжим мигалки к Cheetah =======*/
	// FBI
	AttachObjectToVehicle(OBJECTS[FLASHER][0], SpawningCars[F_POLICE_FBI][7], 0,-0.3,0.6,0,0,0);
   // Полиция ЛС
	AttachObjectToVehicle(OBJECTS[FLASHER][1], SpawningCars[F_POLICE_LS][6], 0,-0.3,0.6,0,0,0);
   // Полиция ЛВ
	AttachObjectToVehicle(OBJECTS[FLASHER][2], SpawningCars[F_POLICE_LV][9], 0,-0.3,0.6,0,0,0);
	// Полиция СФ
	AttachObjectToVehicle(OBJECTS[FLASHER][3], SpawningCars[F_POLICE_SF][15], 0,-0.3,0.6,0,0,0);

}

SpawningCar_Mechanic()
{
	/*================ Машины автомехаников ========*/
   // Towtruck
	SpawningCars[MECHANIC][0] = AddStaticVehicleEx(525,1648.5869,-1136.0287,23.7816,359.3848,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][1] = AddStaticVehicleEx(525,1652.7318,-1135.8080,23.7921,0.1514,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][2] = AddStaticVehicleEx(525,1657.3997,-1136.3794,23.7783,358.7764,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][3] = AddStaticVehicleEx(525,1661.8904,-1136.1580,23.7807,359.1264,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][4] = AddStaticVehicleEx(525,1666.2986,-1136.1011,23.7770,358.3249,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][5] = AddStaticVehicleEx(525,1675.8644,-1129.4961,23.7868,89.9304,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][6] = AddStaticVehicleEx(525,1675.8175,-1124.7106,23.7832,90.2224,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][7] = AddStaticVehicleEx(525,1675.5989,-1120.5718,23.7847,89.6456,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][8] = AddStaticVehicleEx(525,1676.1625,-1115.6519,23.7887,88.7706,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][9] = AddStaticVehicleEx(525,1676.3378,-1111.5038,23.7876,89.0301,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][10] = AddStaticVehicleEx(525,1675.4113,-1106.6532,23.7808,88.8456,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][11] = AddStaticVehicleEx(525,1676.3295,-1102.3301,23.7855,88.2714,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][12] = AddStaticVehicleEx(525,1676.3480,-1097.9003,23.7824,92.8080,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][13] = AddStaticVehicleEx(525,1616.8829,-1119.3153,23.7873,270.1182,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][14] = AddStaticVehicleEx(525,1617.1809,-1123.4893,23.7812,268.9137,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][15] = AddStaticVehicleEx(525,1616.8478,-1128.2522,23.7853,269.0683,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][16] = AddStaticVehicleEx(525,1617.0802,-1132.7119,23.7833,267.2122,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][17] = AddStaticVehicleEx(525,1616.1351,-1136.8422,23.7873,270.7246,1,128,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][18] = AddStaticVehicleEx(525,2440.7332,1267.3026,10.7014,0.8438,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][19] = AddStaticVehicleEx(525,2445.8743,1267.1498,10.6927,0.1440,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][20] = AddStaticVehicleEx(525,2449.2449,1267.3167,10.6972,0.5731,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][21] = AddStaticVehicleEx(525,2452.6194,1267.3398,10.6947,0.3633,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][22] = AddStaticVehicleEx(525,2456.1182,1267.2740,10.7012,0.1325,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][23] = AddStaticVehicleEx(525,2455.2424,1273.8625,10.7006,89.5417,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][24] = AddStaticVehicleEx(525,2455.5251,1277.1400,10.7005,90.0661,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][25] = AddStaticVehicleEx(525,2455.2693,1280.4584,10.6874,90.8961,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][26] = AddStaticVehicleEx(525,2440.5002,1281.0157,10.7046,177.7981,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][27] = AddStaticVehicleEx(525,2445.3953,1281.3187,10.6838,181.3596,1,198,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][28] = AddStaticVehicleEx(525,-2148.5493,-105.9126,35.1983,358.3277,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][29] = AddStaticVehicleEx(525,-2141.7146,-106.4479,35.1997,357.7331,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][30] = AddStaticVehicleEx(525,-2135.0134,-106.1290,35.2019,357.9173,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][31] = AddStaticVehicleEx(525,-2128.1174,-105.8189,35.2020,358.5190,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][32] = AddStaticVehicleEx(525,-2123.2371,-105.9995,35.1993,357.1984,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][33] = AddStaticVehicleEx(525,-2118.0449,-106.5891,35.2010,359.3029,1,175,CAR_RESPAWN_WORKERS); // Towtruck
	SpawningCars[MECHANIC][34] = AddStaticVehicleEx(525,-2111.9231,-105.9967,35.2014,358.2345,1,175,CAR_RESPAWN_WORKERS); // Towtruck
}

SpawningCar_Bus()
{
	/*BUS[0] = AddStaticVehicleEx(431,-1974.1999512,104.8000031,27.8999996,90.0000000,6,108,108); //Bus SF
	BUS[1] = AddStaticVehicleEx(431,-1974.1999512,100.6999969,27.8999996,90.0000000,6,108,108); //Bus SF
	BUS[2] = AddStaticVehicleEx(431,-1974.3000488,96.5000000,27.8999996,90.0000000,6,108,108); //Bus SF
	BUS[3] = AddStaticVehicleEx(431,-1974.3000488,92.3000031,27.8999996,90.0000000,6,108,108); //Bus SF
	BUS[4] = AddStaticVehicleEx(431,-1974.4000244,87.6999969,27.8999996,90.0000000,6,108,108); //Bus SF

	BUS[5] = AddStaticVehicleEx(431,2808.6000977,1326.1999512,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[6] = AddStaticVehicleEx(431,2808.8000488,1337.4000244,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[7] = AddStaticVehicleEx(431,2808.8000488,1333.5999756,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[8] = AddStaticVehicleEx(431,2808.8999023,1345.1999512,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[9] = AddStaticVehicleEx(431,2808.8000488,1341.5000000,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[10] = AddStaticVehicleEx(431,2808.6999512,1329.8000488,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[11] = AddStaticVehicleEx(431,2808.6999512,1365.4000244,11.0000000,269.9998779,154,6,108); //Bus LV
	BUS[12] = AddStaticVehicleEx(431,2808.8000488,1361.4000244,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[13] = AddStaticVehicleEx(431,2808.8000488,1357.4000244,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[14] = AddStaticVehicleEx(431,2808.8000488,1353.4000244,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[15] = AddStaticVehicleEx(431,2808.8000488,1349.3000488,11.0000000,270.0000000,154,6,108); //Bus LV
	BUS[16] = AddStaticVehicleEx(431,2808.6000977,1369.3000488,11.0000000,270.0000000,154,6,108); //Bus LV
	//Хорошие
	BUS[36] = AddStaticVehicleEx(437,2794.8000488,1292.0999756,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[37] = AddStaticVehicleEx(437,2791.3000488,1292.0999756,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[38] = AddStaticVehicleEx(437,2787.6999512,1292.0999756,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[39] = AddStaticVehicleEx(437,2775.8999023,1291.8000488,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[40] = AddStaticVehicleEx(437,2783.8999023,1292.0000000,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[50] = AddStaticVehicleEx(437,2779.8999023,1291.9000244,11.0000000,180.0000000,194,198,198); //BIG LV
	BUS[51] = AddStaticVehicleEx(437,2771.8999023,1291.8000488,11.0000000,179.9996338,194,198,198); //BIG LV

	BUS[17] = AddStaticVehicleEx(431,1276.8000488,-1796.0000000,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[18] = AddStaticVehicleEx(431,1276.8000488,-1800.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[20] = AddStaticVehicleEx(431,1276.6999512,-1808.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[21] = AddStaticVehicleEx(431,1276.6999512,-1804.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[22] = AddStaticVehicleEx(431,1242.3000488,-1822.0999756,13.6999998,270.0000000,229,108,108); //Bus LS
	BUS[23] = AddStaticVehicleEx(431,1242.3000488,-1813.0000000,13.6999998,270.0000000,229,108,108); //Bus LS
	BUS[24] = AddStaticVehicleEx(431,1242.4000244,-1817.8000488,13.6999998,270.0000000,229,108,108); //Bus LS
	BUS[25] = AddStaticVehicleEx(431,1276.6999512,-1812.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[26] = AddStaticVehicleEx(431,1200.1999512,-1834.3000488,13.6000004,270.0000000,229,108,108); //Bus LS
	BUS[27] = AddStaticVehicleEx(431,1200.1999512,-1830.0999756,13.6999998,270.0000000,229,108,108); //Bus LS
	BUS[28] = AddStaticVehicleEx(431,1276.5999756,-1824.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[29] = AddStaticVehicleEx(431,1276.5999756,-1820.0999756,13.6000004,90.0000000,229,108,108); //Bus LS
	BUS[30] = AddStaticVehicleEx(431,1276.6999512,-1816.0000000,13.6000004,90.0000000,229,108,108); //Bus LS
	// Хорошие
	BUS[31] = AddStaticVehicleEx(437,1080.7462,-1755.0065,13.5251,269.8860,86,6,600); //BIG LS
	BUS[32] = AddStaticVehicleEx(437,1080.7383,-1760.0625,13.5133,269.5761,86,6,600); //BIG LS
	BUS[33] = AddStaticVehicleEx(437,1080.7360,-1765.2400,13.5013,269.8204,86,6,600); //BIG LS
	BUS[34] = AddStaticVehicleEx(437,1080.8528,-1770.4004,13.4901,269.5037,86,6,600); //BIG LS
	BUS[35] = AddStaticVehicleEx(437,1080.8030,-1775.6235,13.4782,270.0694,86,6,600); //BIG LS */
}

SpawningCar_Goverment()
{
	/* admcar[0] = AddStaticVehicleEx(409,894.70001221,-939.79998779,42.00000000,90.00000000,1,1,SPAWN_CARS); //Stretch
	admcar[1] = AddStaticVehicleEx(445,895.00000000,-935.40002441,42.09999847,90.00000000,0,0,SPAWN_CARS); //Admiral
	admcar[2] = AddStaticVehicleEx(579,971.4744,-924.7010,45.6957,2.6711,0,0,SPAWN_CARS); //Huntley
	admcar[3] = AddStaticVehicleEx(490,894.09997559,-926.50000000,42.40000153,90.25000000,0,0,SPAWN_CARS); //FBI Rancher
	admcar[4] = AddStaticVehicleEx(533,967.1082,-925.0595,45.4747,1.8892,0,0,SPAWN_CARS); //Feltzer
	admcar[5] = AddStaticVehicleEx(445,894.90002441,-931.29998779,42.09999847,90.00000000,0,0,SPAWN_CARS); //Admiral
	admcar[6] = AddStaticVehicleEx(579,975.8480,-924.3671,45.6920,3.0273,0,0,SPAWN_CARS); //Huntley
	admcar[7] = AddStaticVehicleEx(533,962.7848,-925.1851,45.4747,2.1384,0,0,SPAWN_CARS); //Feltzer //конец
	admcar[8] = AddStaticVehicleEx(473,-1364.8299561,-2974.2609863,0.0000000,266.0000000,-1,-1,SPAWN_CARS); //Dinghy
	admcar[9] = AddStaticVehicleEx(473,-1359.9820557,-2974.4819336,0.0000000,265.9954834,-1,-1,SPAWN_CARS); //Dinghy
	admcar[10] = AddStaticVehicleEx(487,917.0991,-934.1051,42.7657,92.4639,1,1,SPAWN_CARS); // Верт АП


	mlvcar[0] = AddStaticVehicleEx(400,2374.6809,2496.5730,10.8876,180.0157,0,0,SPAWN_CARS); //
	mlvcar[1] = AddStaticVehicleEx(400,2374.6899,2488.8584,10.9167,180.1313,0,0,SPAWN_CARS); //
	mlvcar[2] = AddStaticVehicleEx(400,2359.7598,2488.2683,10.9127,180.3083,0,0,SPAWN_CARS); //
	mlvcar[3] = AddStaticVehicleEx(400,2359.7673,2496.2031,10.9127,179.4308,0,0,SPAWN_CARS); //

	mlscar[0] = AddStaticVehicleEx(400,1403.3497,-1802.8577,13.6146,90.3161,0,0,SPAWN_CARS); //
	mlscar[1] = AddStaticVehicleEx(400,1403.4808,-1807.2294,13.6117,89.9991,0,0,SPAWN_CARS); //
	mlscar[2] = AddStaticVehicleEx(400,1403.2822,-1798.7563,13.6411,90.8311,0,0,SPAWN_CARS); //
	mlscar[3] = AddStaticVehicleEx(400,1403.1390,-1794.5258,13.6402,89.6049,0,0,SPAWN_CARS); //

	msfcar[0] = AddStaticVehicleEx(400,-2755.6921,395.2612,4.4060,0.5416,0,0,SPAWN_CARS); //
	msfcar[1] = AddStaticVehicleEx(400,-2755.6406,401.4774,4.4072,359.8892,0,0,SPAWN_CARS); //
	msfcar[2] = AddStaticVehicleEx(400,-2760.2234,395.1807,4.4367,0.6184,0,0,SPAWN_CARS); //
	msfcar[3] = AddStaticVehicleEx(400,-2760.2556,401.3667,4.4371,359.9085,0,0,SPAWN_CARS); // */
}

SpawningCar_Delivery()
{
   /*================== Развозчики продуктов ===============*/
	// Тягач, Linerunner
	SpawningCars[DELIVERY_GOODS_TRAIN][0] = AddStaticVehicleEx(403,2277.8137,-2319.4995,14.1980,224.6392,37,1,CAR_RESPAWN_WORKERS);  // Linerunner
	SpawningCars[DELIVERY_GOODS_TRAIN][1] = AddStaticVehicleEx(403,2274.2341,-2323.2112,14.1957,224.6973,30,1,CAR_RESPAWN_WORKERS);  // Linerunner
	SpawningCars[DELIVERY_GOODS_TRAIN][2] = AddStaticVehicleEx(403,2270.3445,-2327.0881,14.1533,225.1382,28,1,CAR_RESPAWN_WORKERS);  // Linerunner
	// Прицеп, Article Trailer
	SpawningCars[DELIVERY_GOODS_TRAILER][0] = AddStaticVehicleEx(435, 2261.0388, -2338.7712, 13.9277, 314.8093, 103, 103, 80); // Article Trailer
	SpawningCars[DELIVERY_GOODS_TRAILER][1] = AddStaticVehicleEx(435, 2264.7249, -2342.4802, 13.9277, 314.8093, 103, 103, 80); // Article Trailer
	SpawningCars[DELIVERY_GOODS_TRAILER][2] = AddStaticVehicleEx(435, 2268.1875, -2346.0420, 13.9277, 314.8093, 103, 103, 80); // Article Trailer

	// Грузовик, Yankee
	SpawningCars[DELIVERY_GOODS_WAGON][0] = AddStaticVehicleEx(456,2281.9121,-2350.5845,13.7613,42.8972,105,72,CAR_RESPAWN_WORKERS);  // Yankee
	SpawningCars[DELIVERY_GOODS_WAGON][1] = AddStaticVehicleEx(456,2291.2227,-2343.0730,13.7579,41.1841,91,63,CAR_RESPAWN_WORKERS);  // Yankee
	SpawningCars[DELIVERY_GOODS_WAGON][2] = AddStaticVehicleEx(456,2297.3428,-2336.6621,13.7605,43.1537,102,65,CAR_RESPAWN_WORKERS);  // Yankee

	/*================== Развозчики топлива =================*/
	// Тягач, Tanker
	SpawningCars[DELIVERY_OIL_TRAIN][0] = AddStaticVehicleEx(514,-71.5907,-1111.3419,1.6656,154.8273,23,2,CAR_RESPAWN_WORKERS);  // Tanker
	SpawningCars[DELIVERY_OIL_TRAIN][1] = AddStaticVehicleEx(514,-76.7364,-1108.9674,1.6662,158.4504,45,5,CAR_RESPAWN_WORKERS);  // Tanker
	SpawningCars[DELIVERY_OIL_TRAIN][2] = AddStaticVehicleEx(514,-66.2152,-1113.6133,1.7260,156.8898,28,1,CAR_RESPAWN_WORKERS);  // Tanker
	// Цистерна, Petrol Trailer
	SpawningCars[DELIVERY_OIL_TRAILER][0] = AddStaticVehicleEx(584, -41.8380, -1138.8506, 2.0000, 70.6454, 103, 103, 80); // Petrol Trailer
	SpawningCars[DELIVERY_OIL_TRAILER][1] = AddStaticVehicleEx(584, -44.3978, -1145.2072, 2.0000, 67.4599, 103, 103, 80); // Petrol Trailer
	SpawningCars[DELIVERY_OIL_TRAILER][2] = AddStaticVehicleEx(584, -47.1064, -1151.4474, 2.0000, 63.2933, 103, 103, 80); // Petrol Trailer

}