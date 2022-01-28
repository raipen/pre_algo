#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PAPER_SIZE 128

//func
void DivQuarter(int, int, int);
int ColorCheck(int, int, int, int, int);

//var
int PaperSize, PaperColor;
int PaperMatrix[MAX_PAPER_SIZE][MAX_PAPER_SIZE];
int WhiteBlueCount[2] = { 0,0 };

//main
int main(void)
{
	scanf_s("%d", &PaperSize);

	for (int i = 0; i < PaperSize; i++)
	{
		for (int j = 0; j < PaperSize; j++)
		{
			scanf_s("%d", &PaperColor);
			PaperMatrix[i][j] = PaperColor;
		}
	}

	if (ColorCheck(0, 0, 0, 0, PaperSize)) printf("%d\n%d", WhiteBlueCount[0], WhiteBlueCount[1]);
	else
	{
		DivQuarter(0, 0, PaperSize);
		printf("%d\n%d", WhiteBlueCount[0], WhiteBlueCount[1]);
	}
	
	return 0;
}

//func
void DivQuarter(int xAxis, int yAxis, int DivSize)
{
	DivSize /= 2;

	for (int i = 0; i < 4; i++)
	{
		if (ColorCheck(xAxis, yAxis, i / 2, i % 2, DivSize)) continue;
		else DivQuarter(xAxis + (i / 2) * DivSize, yAxis + (i % 2) * DivSize, DivSize);
	}
}
int ColorCheck(int xAxis, int yAxis, int xPos, int yPos, int DivSize)
{
	int m = PaperMatrix[xAxis + xPos * DivSize][yAxis + yPos * DivSize];

	for (int i = xAxis + xPos * DivSize; i < xAxis + xPos * DivSize + DivSize; i++)
	{
		for (int j = yAxis + yPos * DivSize; j < yAxis + yPos * DivSize + DivSize; j++)
		{
			if (PaperMatrix[i][j] == m) continue;
			else return 0;
		}
	}

	if (!m) WhiteBlueCount[0]++;
	else WhiteBlueCount[1]++;

	return 1;
}