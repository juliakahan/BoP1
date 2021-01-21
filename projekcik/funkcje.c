#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 10 //rozmiar planszy ze statkami
#define LOSE_MARK 9 //oznaczenie na pusty strzal
#define DOWN_MARK 8 //oznaczenie na zatopiona czesc statku

//rysuje mape ze statkami
void drawMap(int map[SIZE][SIZE])

{
    int i;
    printf("   ");
    for (i = 0; i < SIZE; i++)
    {
        printf("(%d)", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        int j;
        printf("(%d)", i);
        for (j = 0; j < SIZE; j++)
        {
            if (map[i][j] == 0)
            {
                printf("[ ]");
            }
            else if (map[i][j] == LOSE_MARK)
            {
                printf("[|]");
            }
            else if (map[i][j] == DOWN_MARK)
            {
                printf("[X]");
            }
            else
            {
                printf("[%d]", map[i][j]);
            }
        }
        printf("\n");
    }
}

//funckja dodajaca statek na plansze
void putShip(int map[SIZE][SIZE], int x, int y, int shipSize, int orientation)
{
    int i;
    for (i = 0; i < shipSize; i++)
    {
        if (orientation == 1)
        {
            map[x + i][y] = shipSize;
        }
        else if (orientation == 0)
        {
            map[x][y + i] = shipSize;
        }
    }
}

//funkcja sprawdzajaca czy mozna dodac dany statek na plansze
int canAddShip(int map[SIZE][SIZE], int x, int y, int shipSize, int orientation)
{
    if (x < 0 || y < 0 || orientation < 0 || orientation > 1 || x >= SIZE || y >= SIZE)
    {
        return 0;
    }

    int i = 0;
    if (orientation == 1) //sprawdzanie poziomo
    {
        for (i = 0; i < shipSize; i++)
        {
            if (x + i >= SIZE || map[x + i][y] != 0)
            {
                return 0;
            }
        }

        //sprawdzenie czy nie ma przylegajacych statkow
        int j;
        for (i = x - 1; i < x + shipSize + 1; i++)
        {
            for (j = y - 1; j < y + 2; j++)
            {
                if (i >= 0 && j >= 0 && i < SIZE && j < SIZE && map[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    else if (orientation == 0) //sprawdzanie pionowo
    {
        for (i = 0; i < shipSize; i++)
        {
            if (y + i >= SIZE || map[x][y + i] != 0)
            {
                return 0;
            }
        }

        //sprawdzenie czy nie ma przylegajacych statkow
        int j;
        for (i = x - 1; i < x + 2; i++)
        {
            for (j = y - 1; j < y + shipSize + 1; j++)
            {
                if (i >= 0 && j >= 0 && i < SIZE && j < SIZE && map[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

//menu dodawania stakow przez gracza na plansze
void addShips(int map[SIZE][SIZE])
{
    //rozmiary statkow do dodania
    int ships[7] = { 1, 1, 1, 2, 2, 3, 4 };

    int i;
    for (i = 0; i < 7; i++)
    {
        drawMap(map);
        printf("Podaj wspolrzedne na mapie oraz orientacje [0 - poziomo, 1 - pionowo] dla statku o rozmiarze: %d\n", ships[i]);
        printf("np. 5 4 1 - ustawia statek w pozycji 5 4 pionowo\n");
        int x, y, o;
       scanf("%d %d %d", &x, &y, &o);

        while (!canAddShip(map, x, y, ships[i], o)) //jesli statku nie da sie dodac to pytaj ponownie
        {
            printf("Wprowadzono niepoprawne wartosci, wprowadz ponownie..\n");
            scanf("%d %d %d", &x, &y, &o);

        }
        putShip(map, x, y, ships[i], o);
    }
}

int random_num(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

void computerAddShips(int map[SIZE][SIZE])
{
    int ships[7] = { 1, 1, 1, 2, 2, 3, 4 };
    int i;
    for (i = 0; i < 7; i++)
    {
        int x = random_num(0, SIZE - 1);
        int y = random_num(0, SIZE - 1);
        int o = random_num(0, 1);
        while (!canAddShip(map, x, y, ships[i], o))
        {
            x = random_num(0, SIZE - 1);
            y = random_num(0, SIZE - 1);
            o = random_num(0, 1);
        }
        putShip(map, x, y, ships[i], o);
    }
}

void readMapFromFile(int map[SIZE][SIZE], char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Brak pliku... Koniec programu\n");
        exit(-1);
    }

    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            fscanf(file, "%d", &map[i][j]);
            if (map[i][j] > 9 || map[i][j] < 0)
            {
                printf("Bledne dane w pliku! Koniec programu!\n");
                exit(-2);
            }
        }
    }
    while (getchar() != '\n') {}
    fclose(file);
}

int canShot(int map[SIZE][SIZE], int x, int y)
{
    return (x >= 0 && x < SIZE&& y >= 0 && y < SIZE&& map[x][y] != LOSE_MARK && map[x][y] != DOWN_MARK);
}

void showEnemyMap(int map[SIZE][SIZE])
{
    int i;
    printf("   ");
    for (i = 0; i < SIZE; i++)
    {
        printf("(%d)", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        int j;
        printf("(%d)", i);
        for (j = 0; j < SIZE; j++)
        {
            if (map[i][j] == LOSE_MARK)
            {
                printf("[|]");
            }
            else if (map[i][j] == DOWN_MARK)
            {
                printf("[X]");
            }
            else
            {
                printf("[ ]", map[i][j]);
            }
        }
        printf("\n");
    }
}

void playerMove(int enemyMap[SIZE][SIZE])
{
    showEnemyMap(enemyMap);
    printf("Podaj wspolrzedne do strzalu [x y]!");
    int x, y;
    scanf("%d %d", &x, &y);
    while (!canShot(enemyMap, x, y))
    {
        printf("Podano niewlasciwe wspolrzedne, podaj jeszcze raz..\n");
        scanf("%d %d", &x, &y);
    }
    int choice = enemyMap[x][y];
    system("clear"); //czyscimy plansze zeby wygodniej sie gralo
    if (choice == 0)
    {
        enemyMap[x][y] = LOSE_MARK;
        printf("Pudlo!!!\n");
    }
    else
    {
        enemyMap[x][y] = DOWN_MARK;
        printf("Trafiony: %d :)\n", choice);
    }
}

void computerMove(int map[SIZE][SIZE])
{
    int x, y;
    x = random_num(0, SIZE - 1);
    y = random_num(0, SIZE - 1);
    while (!canShot(map, x, y))
    {
        x = random_num(0, SIZE - 1);
        y = random_num(0, SIZE - 1);
    }

    int choice = map[x][y];
    map[x][y] = LOSE_MARK;
    if (choice == 0)
    {
        printf("[Komputer] Pudlo!!!\n");
        map[x][y] = LOSE_MARK;
    }
    else
    {
        map[x][y] = DOWN_MARK;
        printf("[Komputer] Trafiony :)\n");
    }
}

//sprawdza czy jest koniec gry, 0 - gra trwa, 1 - wygral gracz, -1 - wygral komputer
int ifWin(int playerMap[SIZE][SIZE], int enemyMap[SIZE][SIZE])
{
    int playerWin = 1;
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (enemyMap[i][j] > 0 && enemyMap[i][j] <= 4)
            {
                playerWin = 0;
                break;
            }
        }
    }

    if (playerWin)
    {
        return 1;
    }

    int enemyWin = 1;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (playerMap[i][j] > 0 && playerMap[i][j] <= 4)
            {
                enemyWin = 0;
                break;
            }
        }
    }

    if (enemyWin)
    {
        return -1;
    }

    return 0;
}

//petla rozgrywki
void gameLoop()
{
    int playerMap[SIZE][SIZE] = { 0 };
    int computerMap[SIZE][SIZE] = { 0 };
    srand(time(NULL));
    computerAddShips(computerMap);

        printf("Wprowadzanie statkow na plansze.\n");
        addShips(playerMap);


    int win = 0;
    while (!(win = ifWin(playerMap, computerMap)))
    {
        printf("Twoje statki:\n");
        drawMap(playerMap);
        printf("Twoj ruch..\n");
        playerMove(computerMap);
        printf("Komputer wykonuje ruch..\n");
        computerMove(playerMap);
    }

    if (win == 1)
    {
        printf("Wygrana!\n");
    }
    else
    {
        printf("Przegrana!\n");
    }
}

void start()
{
    printf("Nacisnij enter aby rozpoczac rozgrywke..\n");

    while (getchar() != '\n') {}
    gameLoop();
}

