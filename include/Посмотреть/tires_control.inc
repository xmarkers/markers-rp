/********************************************************************************************************\
	* ������: Happy_Hardcore, Snoowker
	
	* ��������: Tires Control
	
	* ������: 0.1 (2012-04-01)
	
	* ����������: 
		������ Tires Control � ��� ��������� ������ � ���������� � ���������� ���������� ��� � ����������
	
	* �������:
		GetVehicleTireState(vehicleID, tireID) � ������� ��� ��������� ���������� � ��������� ������������ ����
			���������: vehicleID � ID ����������, tireID - ID ����.
			����������: 1 � ���� ����������, 0 � ���� �� ����������, -1 � ��������� ������.
		SetVehicleTireState(vehicleID, tireID, t_state) � ������� ��� ��������� ��������� ������������ ����
			���������: ���������: vehicleID � ID ����������, tireID - ID ����, t_state � (0 - ���������, 1 - ������������)
			����������: 1 � �-��� �����������, -1 � �-��� �� ����������� (������).
\********************************************************************************************************/
#include <a_samp>
GetVehicleTireState(vehicleid, tireid) {
	new panels, doors, lights, tires;
	GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
	switch(tireid) {
	    case 1: { // FRONT LEFT
			switch(tires) {
				case 0..7: return 0;
				default: return 1;
			}
		}
		case 2: { // BACK LEFT
			switch(tires) {
				case 0..3, 8..11: return 0;
				default: return 1;
			}
		}
		case 3: { // FRONT RIGHT
			switch(tires) {
				case 0, 1, 4, 5, 8, 9, 12, 13: return 0;
				default: return 1;
			}
		}
		case 4: { // BACK RIGHT
			switch(tires) {
				case 0, 2, 4, 6, 8, 10, 12, 14: return 0;
				default: return 1;
			}
		}
		default: return -1;
	}
	return -1;
}


SetVehicleTireState(vehicleID, tireID, t_state) {
	if(tireID <= 0 && tireID >= 5 || t_state < 0 && t_state >= 1) return -1; // ����������� ������� � ������ ��������� �������� ���������� �������
 	new tirest[4], panels, doors, lights;
	for(new s = 1; s <= sizeof(tirest); s ++) { tirest[s - 1] = GetVehicleTireState(vehicleID, s); } // ���� ���������� ������� ������� tirest ��������� ���
	tirest[tireID - 1] = t_state; // ���������� �������� ��������� ���� ���������
	UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, ((tirest[0] * involution(2, 3)) + (tirest[1] * involution(2, 2)) + (tirest[2] * involution(2, 1)) + (tirest[3] * involution(2, 0))));
	printf("%d", ((tirest[0] * involution(2, 3)) + (tirest[1] * involution(2, 2)) + (tirest[2] * involution(2, 1)) + (tirest[3] * involution(2, 0))));
	return 1;
}

involution(count, n_step) { // ���������� � �������
	if(n_step == 0) return 1;
	new res = count;
	for(new i; i < n_step-1; i++) res = res * count;
	return res;
}
