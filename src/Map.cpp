#include "Map.hpp"
#include "TextureManager.hpp"

Map::Map(int map_array[20][25])
{
    dirt = TextureManager::LoadTexture("../src/assets/dirt.png");
    grass = TextureManager::LoadTexture("../src/assets/grass.png");
    water = TextureManager::LoadTexture("../src/assets/water.png");

    LoadMap(map_array);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map()
{}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            type = map[row][column];
            dest.x = column * 32;
            dest.y = row * 32;

            switch (type)
            {
            case 0:
                TextureManager::Draw(water, src, dest);
                break;
            case 1:
                TextureManager::Draw(grass, src, dest);
                break;
            case 2:
                TextureManager::Draw(dirt, src, dest);
                break;
            default:
                break;
            }
        }
    }
}