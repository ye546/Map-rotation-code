#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
//#include <algorithm>
#include <iostream>

void generate_maps(std::string all_maps_path, std::string old_rotation_path);
void save(std::vector<std::string> vec);

int main()
{
	srand(time(NULL));
	generate_maps("available_maps.txt", "old_rotation.txt");
	getchar();

	return 0;
}

void save(std::vector<std::string> vec) {
	std::ofstream file("rotation.txt", std::ofstream::app);

	if (file.is_open()) {
		file << "\n";
	}

	file << "gametype" << " " << "zom" << " " << "map" << " ";

	for (int i = 0; i < vec.size(); i++)
	{
		//take reference because othwerise
		//we check if it's equal to the value
		//whats on that index
		if (&vec[i] == &vec.back()) {
			file << vec[i];
		}else
			file << vec[i] << " " << "map" << " ";
	}
}

std::vector<std::string> load_maps(std::string filename)
{
	std::vector<std::string> _maps;
	std::ifstream file(filename);
	std::string tmp;

	while (std::getline(file, tmp))
		_maps.push_back(tmp);

	return _maps;
}

void generate_maps(std::string all_maps_path, std::string old_rotation_path)
{
	//filepath1 = all maps
	//filepath2 = old rotation

	//all available maps
	std::vector<std::string> _maps = load_maps(all_maps_path);

	//the old rotation
	std::vector<std::string> _old_maps = load_maps(old_rotation_path);


	//std::ofstream write_file("NewMaps.txt");

	//remove the old rotating maps from all maps
	for (int i = 0; i < _old_maps.size(); i++)
	{
		for (int j = 0; j < _maps.size(); j++)
		{
			if (_old_maps[i] == _maps[j]) 
			{
				_maps[j] = _maps.back();
				_maps.pop_back();
				//std::vector<std::string>::iterator position = std::find(_maps.begin(), _maps.end(), _maps[j]);
				//_maps.erase(position);
			}	
		}
	}

	
	
	std::vector<std::string> _new_rotation;

	std::string tmp;
	restart:
	for (int i = 0; i < 12; i++)
	{
		int length = _maps.size();
		int pos = (rand() % length);

		tmp = _maps[pos];

		_new_rotation.push_back(tmp);

		_maps[pos] = _maps.back();

		_maps.pop_back();

		//length--; // REMEMBER TO SRHINK THIS FUCKING VARIABLE
		//WHY? BECAUSE WHEN THE VECTOR RESIZES WE CAN'T FUCKING EXPECT 
		//THE SIZE TO BE THE SAME NOW CAN WE? AS ON LINE 73
		//HENCE THIS WAS CAUSING AN ANNOYING FUCKING CANCER BUG

		//printf("erased: %s\n", tmp.c_str());
	}
	printf("Chosen maps\n-------------\n");
	for (auto &i : _new_rotation)
		printf("%s\n", i.c_str());

	printf("\n");

	printf("Last Rotation\n-------------\n");
	for (auto &i : _old_maps)
		printf("%s\n", i.c_str());

	printf("\nwish to save? >");
	int x = 0; std::cin >> x;

	if (x == 1)
		save(_new_rotation);
	else {
		_new_rotation.clear();
		printf("\nrerolling\n");
		system("cls");
		goto restart;
	}
}
