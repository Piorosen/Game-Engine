#pragma once
#include <string>
#include <fstream>

#include "Vector2D.hpp"

using namespace std;
class Map {
private:
	int x, y;
	int* tile;

	void ClearTile() {
		if (tile != nullptr) {
			delete[] tile;
		}
		tile = nullptr;
	}

	void AllocTile(int x, int y) {
		if (tile != nullptr) {
			ClearTile();
		}
		tile = new int[x * y];
		this->x = x;
		this->y = y;
	}

public:
	bool LoadMap(string path, int x, int y) {
		AllocTile(x, y);
		ifstream read(path);
		for (int my = 0; my < y; my++) {
			for (int mx = 0; mx < x; mx++) {
				read >> tile[y * my + mx];
			}
		}
		return true;
	}

	int GetTile(int x, int y) {
		return tile[this->y * y + x];
	}
	int GetTile(Vector2D location) {
		return tile[this->y * (int)location.y + (int)location.x];
	}

};