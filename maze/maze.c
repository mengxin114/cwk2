#include "maze.h"

int main(int argc, char* argv[])
{
	load(argv[1]);
	while (!win)
	{
		in = getInput();
		switch (in)
		{
		case '\0':
			printf("wrong input");
			break;
		case 'M':
			break;
		case 'Q':
			break;
		default:
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
		checkData(buf);
		for (int i = 0; i < width; i++) {
			map[j][i] = buf[i];
		}
	}
	printMap();
	printf("%c", map[height - 1][width - 1]);
	printf("%c", map[height - 2][width - 1]);
}

void printMap()
{
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
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

void checkData(char buf[])
{
	if (strlen(buf) - 1 != width)
	{
		printf("buf长度不对");
		exit(-3);
	}
	for (int i = 0; i < width; i++)
	{
		if (buf[i] == 'S' || buf[i] == 'E')
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


char getInput()
{
	char input;
	input = scanf("%c", &input);
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