#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996) //ignore the deprecation

typedef std::vector<std::string> strVec;

void read(std::string fileName, strVec &rotation) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		printf("Error: Could not locate file.\n");
		return;
	}

	for (std::string tmp; std::getline(file, tmp);) {
		rotation.push_back(tmp);
	}
}

void write(strVec &new_rotation) {
	std::ofstream file("newrotation.txt", std::ofstream::app);
	time_t t;
	time(&t);
	std::string time = ctime(&t);

	file << "\n-----------------------\n";
	file << time << "\n";
	file << "gametype zom";

	for (int i = 0; i < new_rotation.size(); i++) {
		file << " map " << new_rotation[i];
	}
}

void randomize(strVec maps, strVec old_rot, strVec &new_rot) {
	srand(time(NULL));

	int length = maps.size();

	std::string tmp;

	while (new_rot.size() < 12) {
		
		/*
			I sometimes run out of vector subscription here, why?
		*/
		
		
		tmp = maps[rand() % length];

		for (int x = 0; x < old_rot.size(); x++) {
			if (tmp == old_rot[x]) {
				continue;
			}
		}

		new_rot.push_back(tmp);

		printf("pushed back\n");
		for (int j = 0; j < maps.size(); j++) {
			if (tmp == maps[j]) {
				maps[j] = maps.back();
				maps.pop_back();
			}
		}
	}
}


int main() {
	strVec maps, old_rotation, new_rotation;

	for (int i = 0; i < 1; i++) {
		std::string x;
		printf("enter name for the map file: >"); std::getline(std::cin, x);
		printf("\n");
		read(x, maps);
		printf("enter name for the old rotation file: >"); std::getline(std::cin, x);
		read(x, old_rotation);
	}

	randomize(maps, old_rotation, new_rotation);

	printf("old rotation\n------------\n");
	for (auto &i : old_rotation) {
		printf("%s\n", i.c_str());
	}
	printf("\n");
	printf("new rotation\n------------\n");
	for (auto &i : new_rotation) {
		printf("%s\n", i.c_str());
	}

	write(new_rotation);

	printf("%i\n", new_rotation.size());
	system("pause");
}
