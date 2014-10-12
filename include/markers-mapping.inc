#pragma library markers-mapping
#include <streamer>

// Хранилище созданных объектов
enum s_OBJECTS
{
	FLASHER[4], // Мигалки на машинах ментов (лидеров)
   //.....
}
new OBJECTS[s_OBJECTS];

forward LoadMapping_GameStart(trhID=0); // Добавление объектов и пр.
forward RemoveBuldsForPlayer(playerid); // Удалить существующие объекты

public LoadMapping_GameStart(trhID=0)
{
   // Создадим надписи на зданиях
	new T_obj = CreateObject(10671, 1811.27, -1292.02, 14.95,   0.00, 0.00, 312.10);
	SetObjectMaterialText(T_obj, C_COLOR_CYAN "Телецен", 0, OBJECT_MATERIAL_SIZE_128x32, "Arial", 36, 1, -16776961, 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	T_Obj = CreateObject(10671, 1805.62, -1297.24, 14.95,   0.00, 0.00, 312.10);
	SetObjectMaterialText(T_obj, C_COLOR_CYAN "тр", 0, OBJECT_MATERIAL_SIZE_128x32, "Arial", 36, 1, -16776961, 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER );

   // Создадим мигалки
	OBJECTS[FLASHER][0] = CreateObject(19419,0.0,0.0,0.0,0.0,0.0,0.0);
	OBJECTS[FLASHER][1] = CreateObject(19419,0.0,0.0,0.0,0.0,0.0,0.0);
	OBJECTS[FLASHER][2] = CreateObject(19419,0.0,0.0,0.0,0.0,0.0,0.0);
	OBJECTS[FLASHER][3] = CreateObject(19419,0.0,0.0,0.0,0.0,0.0,0.0);


	// ....
	print("Mapping Loaded");
	DestroyThread(Threads[CeateObject]);
	return 1;
}

public RemoveBuldsForPlayer(playerid)
{
RemoveBuildingForPlayer(playerid, 3573, 1798.6484, -2057.9141, 14.9844, 0.25);
RemoveBuildingForPlayer(playerid, 1290, 1781.2031, -2000.4297, 18.8281, 0.25);
RemoveBuildingForPlayer(playerid, 700, 1792.7500, -1974.5547, 11.4453, 0.25);
RemoveBuildingForPlayer(playerid, 620, 1794.5938, -1980.7500, 9.6719, 0.25);
RemoveBuildingForPlayer(playerid, 620, 1808.8828, -1985.3359, 9.6719, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 1810.8281, -1971.3594, 13.7344, 0.25);
RemoveBuildingForPlayer(playerid, 700, 1812.3438, -1968.8047, 11.4453, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 1816.1094, -1971.3594, 13.7344, 0.25);
RemoveBuildingForPlayer(playerid, 700, 1810.6797, -1944.6406, 11.4453, 0.25);
RemoveBuildingForPlayer(playerid, 700, 1817.1797, -1944.6406, 11.4453, 0.25);
RemoveBuildingForPlayer(playerid, 5024, 1748.8438, -1883.0313, 14.1875, 0.25);
RemoveBuildingForPlayer(playerid, 6463, 389.7734, -2028.4688, 19.8047, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2028.5000, 32.2266, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2021.6406, 29.9297, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2017.4531, 24.0313, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2017.4297, 16.8516, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2021.6328, 10.9844, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2028.5156, 8.7813, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2035.3984, 10.9453, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2039.6406, 16.8438, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2039.6563, 24.1094, 0.25);
RemoveBuildingForPlayer(playerid, 3751, 389.8750, -2035.3828, 29.9531, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2039.6406, 16.8438, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2039.6563, 24.1094, 0.25);
RemoveBuildingForPlayer(playerid, 6298, 389.7734, -2028.4688, 19.8047, 0.25);
RemoveBuildingForPlayer(playerid, 6461, 389.7734, -2028.5000, 20.1094, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2028.5000, 32.2266, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2021.6406, 29.9297, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2017.4531, 24.0313, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2017.4297, 16.8516, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2021.6328, 10.9844, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2028.5156, 8.7813, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2035.3984, 10.9453, 0.25);
RemoveBuildingForPlayer(playerid, 3752, 389.8750, -2035.3828, 29.9531, 0.25);
RemoveBuildingForPlayer(playerid, 968, -1526.4375, 481.3828, 6.9063, 0.25);
RemoveBuildingForPlayer(playerid, 8229, 1142.0313, 1362.5000, 12.4844, 0.25);
RemoveBuildingForPlayer(playerid, 3368, 338.0078, 2587.7422, 15.4766, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 66.7969, 1207.1563, 18.9922, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 72.0859, 1206.8828, 18.9922, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 73.0938, 1228.0391, 19.0781, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 77.3594, 1206.8828, 18.9922, 0.25);
RemoveBuildingForPlayer(playerid, 3270, 338.0078, 2587.7422, 15.4766, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 78.2578, 1226.8516, 19.3672, 0.25);
RemoveBuildingForPlayer(playerid, 1413, 83.2813, 1225.2656, 19.8203, 0.25);
RemoveBuildingForPlayer(playerid, 1411, 347.1953, 1799.2656, 18.7578, 0.25);
RemoveBuildingForPlayer(playerid, 1411, 342.9375, 1796.2891, 18.7578, 0.25);
RemoveBuildingForPlayer(playerid, 16094, 191.1406, 1870.0391, 21.4766, 0.25);
RemoveBuildingForPlayer(playerid, 18555, -1813.8047, -1615.5625, 29.8516, 0.25);
RemoveBuildingForPlayer(playerid, 18560, -1874.3438, -1680.9531, 25.4375, 0.25);
RemoveBuildingForPlayer(playerid, 18247, -1874.3438, -1680.9531, 25.4375, 0.25);
RemoveBuildingForPlayer(playerid, 18254, -1813.8047, -1615.5625, 29.8516, 0.25);
RemoveBuildingForPlayer(playerid, 18608, -1818.4531, -1613.0391, 32.7891, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1968.7344, 1029.6641, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1967.4063, 1029.6563, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1968.7344, 1021.6875, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1967.4063, 1021.6875, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1968.7344, 1014.0000, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1967.4063, 1014.0000, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1968.7344, 1006.3438, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1967.4063, 1006.3438, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1941.0234, 1014.2266, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1939.6953, 1014.2188, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1941.0234, 1021.4141, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1939.6953, 1021.4141, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1941.8438, 1029.1328, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1940.5547, 1029.4766, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1942.1250, 1006.5703, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 1940.8828, 1006.1094, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2273.4609, 1596.4766, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2268.7188, 1596.4688, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2273.4609, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2268.7188, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2263.6563, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2258.2578, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2253.2344, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2263.6563, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2258.2578, 1596.4766, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2253.2344, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2254.1797, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2259.2188, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2264.6250, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2269.6719, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2274.4063, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2274.4063, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2269.6563, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2264.6094, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2259.1875, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2786, 2254.1563, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 1938.0469, 986.6250, 992.8828, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 1940.6875, 989.1719, 992.8828, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1940.8828, 1006.1094, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1942.1250, 1006.5703, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 1943.2188, 986.5234, 992.8828, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1939.6953, 1014.2188, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1941.0234, 1014.2266, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1939.6953, 1021.4141, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1941.0234, 1021.4141, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1957.4453, 987.6719, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1957.7188, 987.1953, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 1959.3984, 1010.1172, 992.5078, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1960.3672, 1015.6641, 992.4688, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1960.3672, 1020.1719, 992.4688, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1961.9609, 992.2031, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1962.4063, 991.8750, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1962.3438, 1015.6641, 992.4688, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1962.3438, 1020.1797, 992.4688, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1964.5703, 998.4531, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1965.1016, 998.3047, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 1963.7109, 1010.1172, 992.5078, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1014.0000, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1006.3438, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1006.3438, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1014.0000, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1021.6875, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1021.6875, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1940.5547, 1029.4766, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1941.8438, 1029.1328, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 1959.3984, 1025.6953, 992.5078, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 1963.7109, 1025.6953, 992.5078, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1967.4063, 1029.6563, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 1968.7344, 1029.6641, 992.3125, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1964.5469, 1037.2813, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1965.0938, 1037.3516, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1961.9219, 1043.3594, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1962.3984, 1043.6328, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1957.3203, 1047.9766, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 1957.6563, 1048.4141, 992.9844, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2217.0234, 1603.9297, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2217.5469, 1603.8984, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6328, 1588.0781, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6641, 1588.6016, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1589.1875, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2242.3672, 1589.1875, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6328, 1592.3828, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6641, 1592.9063, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1594.7578, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2242.3672, 1594.7578, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2230.3750, 1602.7500, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2241.3125, 1602.7500, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2220.6797, 1603.9297, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2221.2031, 1603.8984, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2243.1250, 1604.4375, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2232.1875, 1604.4375, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2239.4297, 1604.4531, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2228.4922, 1604.4531, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2241.3125, 1606.2734, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 2230.3750, 1606.2734, 1006.1563, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6328, 1614.2266, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6641, 1614.7500, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1614.5938, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2241.4453, 1614.5547, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6328, 1618.5625, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2218.6641, 1619.0859, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2230.5703, 1619.6563, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 1978, 2241.4453, 1619.6094, 1006.2266, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 2252.0313, 1584.4219, 1007.1094, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 2261.6328, 1584.4297, 1007.1094, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2264.6094, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2263.6563, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2258.2578, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2253.2344, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2259.1875, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2254.1563, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2258.2578, 1596.4766, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2263.6563, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2253.2344, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2254.1797, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2259.2188, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2264.6250, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1563, 1609.6016, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1875, 1610.1250, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1563, 1613.6484, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1875, 1614.1719, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1563, 1617.5469, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2255.1875, 1618.0703, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 2271.7266, 1584.4219, 1007.1094, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2268.7188, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2269.6563, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2268.7188, 1596.4688, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2269.6719, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2269.7734, 1606.6484, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2269.2500, 1606.6797, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2273.4609, 1589.7969, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2274.4063, 1589.7891, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2273.4609, 1596.4766, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2785, 2274.4063, 1596.4844, 1006.0156, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2273.2969, 1606.6797, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 2325, 2273.8203, 1606.6484, 1006.7656, 0.25);
RemoveBuildingForPlayer(playerid, 1895, 1117.2813, -1.6484, 1002.0781, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1125.1406, -3.4141, 1000.5781, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1127.0781, -1.6797, 1000.5781, 0.25);
RemoveBuildingForPlayer(playerid, 2188, 1125.1484, -0.0313, 1000.5781, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1135.0469, -3.0781, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1133.6875, -1.6250, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1135.0000, -0.1797, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1124.8203, 3.7969, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1125.8672, 3.7969, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1127.8828, 3.7969, 1000.5234, 0.25);
RemoveBuildingForPlayer(playerid, 2640, 1126.8828, 3.7969, 1000.5234, 0.25);

   //DestroyThread(Threads[RemoveObject]);
	return 1;
}
