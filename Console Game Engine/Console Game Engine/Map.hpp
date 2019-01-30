#pragma once
#include <string>
#include <fstream>
#include <iostream>
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
				read >> tile[x * my + mx];
			}
		}
		return true;
	}

	int GetTile(int x, int y) {
		if (0 <= x && x < this->x && 0 <= y && y < this->y) {
			return tile[this->x * y + x];
		}
		return 0;
	}
	int GetTile(Vector2D location) {
		if (0 <= location.x && location.x < this->x && 0 <= location.y && location.y < this->y) {
			return tile[x * int(location.y) + int(location.x)];
		}
		return 0;
	}

};