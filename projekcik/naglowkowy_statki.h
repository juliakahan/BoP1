#pragma once
#define SIZE 10
#define LOSE_MARK 9
#define DOWN_MARK 8

void drawMap(int mapa[SIZE][SIZE]);
void putShip(int map[SIZE][SIZE], int x, int y, int shipSize, int orientation);
int canAddShip(int map[SIZE][SIZE], int x, int y, int shipSize, int orientation);
void addShips(int map[SIZE][SIZE]);
int random_num(int min, int max);
void computerAddShips(int map[SIZE][SIZE]);
int canShot(int map[SIZE][SIZE], int x, int y);
void showEnemyMap(int map[SIZE][SIZE]);
void playerMove(int enemyMap[SIZE][SIZE]);
void computerMove(int map[SIZE][SIZE]);
int ifWin(int playerMap[SIZE][SIZE], int enemyMap[SIZE][SIZE]);
void gameLoop();
void start();

