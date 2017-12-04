#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <windows.h>
#pragma warning(disable : 4996) //ignore the deprecated bs

void emptyArray(std::string arr[12]) {
	for (int i = 0; i < 12; i++)
		arr[i] = "";
}

int main() {
	srand(time(NULL));
	time_t t = time(0);
	struct tm* now = localtime(&t);
	int duplicates = 0;
	char xd, xd2;

	if(!CreateDirectoryA("C:/NewRotation", NULL)){
       goto next;
	}else{
        CreateDirectoryA("C:/NewRotation", NULL);
	}

    next:std::string bannedMaps[12];
	std::string newMaps[12];
	std::string fileName;

	for (int i = 0; i < 12; i++) {
		bannedMaps[i] = "";
		for (int j = 0; j < 12; j++) {
			newMaps[j] = "";
		}
	}

	try_again:std::cin >> fileName;
	std::ifstream readFile(fileName);

	if (readFile.is_open()) {
		for (int i = 0; i < 12; i++) {
			readFile >> bannedMaps[i];
		}
		readFile.close();
	}
	else {
		printf("No such file, try again.\n");
		goto try_again;
	}

	printf("Skipping these maps!\n------------\n");
	for (int i = 0; i < bannedMaps->length(); i++) {
		if(bannedMaps[i] == "")continue;
		std::cout << bannedMaps[i] << std::endl;
	}

	std::string maps[] = { "up01_4worlds", "up01_a51", "up01_annihilation", "up01_assault", "up01_asturzom", "up01_asylum", "up01_auferstehung", "up01_ayatown",
		"up01_bangbang", "up01_barrack44", "up01_battalion", "up01_bier", "up01_bodesteinv2", "up01_bromberg", "up01_brombergv2", "up01_bulton", "up01_bultonv2",
		"up01_canismajoris", "up01_cars", "up01_cbble", "up01_cbblev2", "up01_chamberofsecrets", "up01_chateauclassic", "up01_clavarlaespada", "up01_common",
		"up01_connected", "up01_corpse", "up01_corpsev2", "up01_dachau", "up01_daitek_green", "up01_defendthecentre", "up01_deimosv2", "up01_derm", "up01_desert_storm",
		"up01_dharmainitiative", "up01_disconight", "up01_doom", "up01_eternity", "up01_fall", "up01_footballarena", "up01_gallinero", "up01_glijbaan", "up01_govas", "up01_graveyard",
		"up01_greedisland", "up01_hipnosis", "up01_idk", "up01_infinite", "up01_infinitev2", "up01_keiseigyakuten", "up01_killhouse", "up01_kinodertoten", "up01_knockknockv3", "up01_koslin",
		"up01_kroptum", "up01_labyrinth", "up01_littlebigbox", "up01_loopbruggenland", "up01_madworld", "up01_metro", "up01_milkyway", "up01_milkywayv2", "up01_minecraft", "up01_mixed",
		"up01_mos_eisley", "up01_mos_eisleyv2", "up01_naout", "up01_neltu", "up01_nhl", "up01_nobsarea", "up01_noob", "up01_palace", "up01_pantarhei", "up01_phantomcemetery", "up01_ramken",
		"up01_ramkenv2", "up01_ratte", "up01_redemption", "up01_red_center", "up01_renson", "up01_rogue2", "up01_rose", "up01_royaljelly", "up01_rubicscube", "up01_shepardsangel", "up01_skinlesscadaver",
		"up01_slide", "up01_sunny", "up01_swift", "up01_tangoworld", "up01_thebridge", "up01_thecorridorv2", "up01_therig", "up01_therospark", "up01_thetower", "up01_timecrunchv2",
		"up01_timetodie", "up01_top", "up01_topv2", "up01_undertheearth", "up01_unmapacualquiera", "up01_uprisingv2", "up01_wide", "up01_winterfell", "up01_woods", "up01_yoshiv3",
		"up01_zombalk", "up01_zombiebunkerv3", "up01_zombiedoos", "up01_zombiefun", "up01_zombieground", "up01_zombiepark", "up01_zombieprison", "up01_zombietown", "up01_zombietrade",
		"up01_zombiezonev3", "up01_zombluev1", "up01_zombonus", "up01_zombox_v2", "up01_zomcure", "up01_zomcurev3", "up01_zomfadev2", "up01_zomix", "up01_zomly", "up01_zompink",
		"up01_zomtictac", "up01_zomturn", "up01_zone115" };

	int length = (sizeof(maps) / sizeof(maps[0]));
	std::string saveLocation = "C:/NewRotation/NewRotation.txt";
	std::fstream newMappack(saveLocation, std::fstream::app);
	newMappack << "\n\n\n";
	newMappack << "new rotation: " << (now->tm_year + 1900) << "/" << (now->tm_mon + 1) << "/" << now->tm_mday << " " << now->tm_hour << "-" << now->tm_min << "-" << now->tm_sec << "\n";
	newMappack << "gametype zom ";

	try_again2:for (int i = 0; i < 12; i++) {
		newMaps[i] = maps[(rand() % length)];
		if (newMaps[i] == bannedMaps[0] || newMaps[i] == bannedMaps[1] ||
			newMaps[i] == bannedMaps[2] || newMaps[i] == bannedMaps[3] ||
			newMaps[i] == bannedMaps[4] || newMaps[i] == bannedMaps[5] ||
			newMaps[i] == bannedMaps[6] || newMaps[i] == bannedMaps[7] ||
			newMaps[i] == bannedMaps[8] || newMaps[i] == bannedMaps[9] ||
			newMaps[i] == bannedMaps[10] || newMaps[i] == bannedMaps[11]) {
			emptyArray(newMaps);
			printf("\nDuplicate found, redoing the process!\n");
			duplicates++;
			goto try_again2;
		}
	}

	printf("\n------New Maps------ \t ------Old Maps------ \n");
	for (int i = 0; i < 12; i++) {
		std::cout << newMaps[i] << "<-->" << bannedMaps[i] << std::endl << std::endl;
	}

	printf("\npress 'k' to accept the maplist\nelse just press a random key\n"); std::cin >> xd;
	if (xd == 'k') {
		for (int i = 0; i < 12; i++) {
			newMappack << newMaps[i];
			newMappack << " map ";
		}
	}
	else {
        system("cls");
		goto try_again2;
	}
	printf("------------\n");
	printf("%i Duplicate(s) found!\n", duplicates);
	printf("Done!\n");
	getchar();
	return 0;
}
