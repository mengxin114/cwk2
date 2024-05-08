#include "maze.h"

int main(int argc, char* argv[])
{
	load(argv[1]);
	while (!win)
	{
		scanf(" %c", &in);
		in = getInput(in);
		switch (in)
		{
		case '\0':
			printf("wrong input");
			break;
		case 'M':
			printMap();
			break;
		case 'Q':
			exit(0);
			break;
		default:
			move(in);
			break;
		}
	}
}





void load(char fileName[])
{
	char buf[LINE_MAX] = { 0 };
	FILE* f;
	f = fopen(fileName, "r");
	if (f == NULL)
	{
		printf("Error: cannot find file");
		exit(-1);
	}
	//read height and weight
	fgets(buf, LINE_MAX, f);
	width = strlen(buf);
	height += 1;
	while (fgets(buf, LINE_MAX, f) != NULL)
	{
		height += 1;
	}
	width -= 1;
	rewind(f);
	//create maze
	creatMaze();
	//load map
	
	for (int j = 0;j < height; j++)
	{
		fgets(buf, LINE_MAX, f);
		checkData(buf,j);
		for (int i = 0; i < width; i++) {
			map[j][i] = buf[i];
		}
	}
	printMap();
	//printf("%c", map[height - 1][width - 1]);
	//printf("%c", map[height - 2][width - 1]);
}

void printMap()
{
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (j == y & i == x)
				printf("X");
			else
				printf("%c", map[j][i]);
		}
		printf("\n");
	}
}

void creatMaze()
{
	printf("%d,%d\n", height, width);
	map = (char**)malloc(sizeof(char*) * height);
	for (int j = 0; j < height; j++) {
		map[j] = (char*)malloc(sizeof(char) * width);
	}


	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			map[j][i] = 'a';
		}
	}
}

void checkData(char buf[],int height)
{
	if (strlen(buf) - 1 != width)
	{
		printf("buf长度不对");
		exit(-3);
	}
	for (int i = 0; i < width; i++)
	{
		if (buf[i] == 'S')
		{
			y = height;
			x = i;
			count += 1;
		}
		else if (buf[i] == 'E')
		{
			count += 1;
		}
		else if (buf[i] == ' ' || buf[i] == '#')
		{

		}
		else if (count > 2)
		{
			printf("invalid char");
			exit(-3);
		}
		else
		{
			printf("invalid char");
			exit(-3);
		}
	}
}


char getInput(char input)
{
	input = toupper(input);
	char a[6] = { 'W', 'A', 'S', 'D', 'Q','M' };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (input == a[i])
		{
			return input;
		}
	}
	return '\0';
}

void move(char input)
{
	for (int i = 0; i < 4; i++) {
		if (direction[i].tag == input) {
			if (checkWrongway(direction[i].x, direction[i].y) == 1)
			{
				x = x + direction[i].x;
				y = y + direction[i].y;
			}
			else
			{
				printf("can not pass");
			}
		}
	}
	checkWin();
	//printf("%d,%d", y, x);
}

int checkWrongway(int dx, int dy)
{
	if (x + dx < 0 || x + dx > width)
	{
		return 0;
	}
	if (y + dy < 0 || y + dy > height)
	{
		return 0;
	}
	if (map[y + dy][x + dx] == '#')
	{
		return 0;
	}
	return 1;
}

void checkWin()
{
	if (map[y][x] == 'E')
	{
		printf("win");
		win = 1;
	}
	else
		win = 0;
}