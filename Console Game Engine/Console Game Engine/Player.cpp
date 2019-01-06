#include "Player.hpp"
#include "GameEngine.h"

using namespace Engine;
using namespace Engine::Draw;


bool Player::MapLoad(string path, int x, int y) {
	return map.LoadMap(path, x, y);
}

void Player::Move(bool isForward)
{
	int i = isForward ? 1 : -1;
	Forward.Rotate(playerRot);
	Location += Forward * Vector2D(move * i,move * i);
	Forward.Rotate(-playerRot);
}

void Player::Rotate(double angle)
{
	double rad = CalcRad(angle);
	playerRot += rad;

	if (playerRot < 0)
	{
		playerRot += TWO_PI;
	}
	else if (playerRot >= TWO_PI)
	{
		playerRot -= TWO_PI;
	}

}

void Player::Draw(const int& width, const int& height, Aoi2DEngine* engine)
{
	MapX = width;
	MapY = height;
	viewDist = (MapX / 2) / tan(FOV / 2);
	this->engine = engine;

	for (int x = 0; x < MapX; x++)
	{
		viewDist = (MapX / 2) / tan(FOV / 2);
		double rayScreenPos = (-MapX / 2 + x);
		double rayViewDist = sqrt((rayScreenPos * rayScreenPos) + (viewDist * viewDist));
		double rayAngle = asin(rayScreenPos / rayViewDist);
		CastRay(playerRot + rayAngle, x);
	}
}

// 알아야할 자료 PI * 2 = TWO_PI
// PlayerRotate
// 몇번째 X인가
void Player::CastRay(double rotate, int kk)
{
	// Check the quadrant of the ray
	bool right = (rotate > TWO_PI * 0.75 || rotate < TWO_PI * 0.25);
	bool up = (rotate < 0 || rotate > PI);

	double HitDistance = 0.0;

	Vector2D HitLocation;
	Vector2D HitTile;

	double slope = sin(rotate) / cos(rotate);

	double DiffX = right ? 1 : -1;
	double DiffY = DiffX * slope;

	double RayX = right ? ceil(Location.x) : floor(Location.x);
	double RayY = Location.y + (RayX - Location.x) * slope;

	int side = -10;

	while (RayX >= 0 && RayX < MapX && RayY >= 0 && RayY < MapY)
	{
		Vector2D tileMap(floor(RayX + (right ? 0 : -1)), floor(RayY));

		if (map.GetTile(tileMap) > 0)
		{
			Vector2D dist(RayX - Location.x, RayY - Location.y);
			HitDistance = dist.x * dist.x + dist.y * dist.y;

			HitTile = std::move(tileMap);

			HitLocation = std::move(Vector2D(RayX, RayY));
			side = 0;
			break;
		}

		RayX += DiffX;
		RayY += DiffY;
	}

	slope = cos(rotate) / sin(rotate);
	DiffY = up ? -1 : 1;
	DiffX = DiffY * slope;
	RayY = up ? floor(Location.y) : ceil(Location.y);
	RayX = Location.x + (RayY - Location.y) * slope;

	while (RayX >= 0 && RayX < MapX && RayY >= 0 && RayY < MapY)
	{
		Vector2D tileMap(floor(RayX), floor(RayY + (up ? -1 : 0)));
		
		if (map.GetTile(tileMap) > 0)
		{
			Vector2D dist(RayX - Location.x, RayY - Location.y);

			double tileDist = (dist.x * dist.x) + (dist.y * dist.y);
			if (!HitDistance || tileDist < HitDistance)
			{
				HitDistance = tileDist;

				HitTile = std::move(tileMap);
				HitLocation = std::move(Vector2D(RayX, RayY));
				side = 10;
			}
			break;
		}
		RayX += DiffX;
		RayY += DiffY;
	}

	if (HitDistance)
	{
		HitDistance = sqrt(HitDistance);
		HitDistance *= cos(playerRot - rotate);
		double height = round(viewDist / HitDistance);
		int tile = map.GetTile(HitTile);
		DrawLine(kk, height > MapY ? MapY : height, tile + side);
	}
}
// 7 15
void Player::DrawLine(int x, double Height, int tile)
{
	auto render = engine->GetGraphic2D();
	for (int y = (MapY - Height) / 2; y < (MapY + Height) / 2; y++) {
		render->SetPixel(x, y, Color(tile > 10 ? ColorList::White : ColorList::WhiteWhite, tile > 10 ? ColorList::White : ColorList::WhiteWhite), ' ');
	}
	/*
	glBegin(GL_LINES);
	if (tile == 1) {
		glColor3b(255 + (Height / 10), 0 + (Height / 10), 0 + (Height / 10));
	}
	else if (tile == 2){
		glColor3b(0 + (Height / 10), 255 + (Height / 10), 255 + (Height / 10));
	}
	glVertex2f(((x - (MapX / 2.0)) / (MapX / 2)), -Height / MapY);
	glVertex2f(((x - (MapX / 2.0)) / (MapX / 2)), +Height / MapY);
	glEnd();*/
}