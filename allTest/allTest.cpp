// allTest.cpp : Defines the entry point for the console application.
//
#pragma warning (disable : 4996)

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;




struct MyStruct
{
	__int32 pole1;
	char pole2;
	double pole3;
};

MyStruct** losowanie(int N)
{
	MyStruct ** ptrptr;

	ptrptr = new MyStruct *[N];

	for (int i = 0; i < N; i++)
	{
		ptrptr[i] = new MyStruct[N];
		ptrptr[i]->pole1 = rand() % 1000001;
		ptrptr[i]->pole2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
		ptrptr[i]->pole3 = 8;
	}

	
 
	//MyStruct ***adrestablicy = &ptrptr;

	

	return  ptrptr;
}

void kasowanie( MyStruct** adrestablicy, int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[]adrestablicy[i];
	}
	
	delete[]adrestablicy;
}

void sortowanie( MyStruct** adrestablicy, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (adrestablicy[j]>adrestablicy[j + 1])
				swap(adrestablicy[j], adrestablicy[j + 1]);
		}
	}
}

int zliczanie( MyStruct ** adrestablicy, int N, char X)
{
	int licznik = 0;

	for (int i = 0; i < N; i++)
	{
		
		if (adrestablicy[i]->pole2 == X)
		{
			licznik += 1;
		}
	}

	return licznik;
}


int main()
{
	/*clock_t begin, end;
	double time_spent;
	begin = clock();*/

	int N;
	char X;
	FILE* fp = fopen(__argv[1], "r");
	if (fp == NULL)
		return -1;
	fscanf(fp, "%d %c", &N, &X);
	fclose(fp);


	/*MyStruct** x = losowanie(N);
	sortowanie(x, N);
	int znaki = zliczanie(x, N, X);
	kasowanie(x, N);*/

	cout << N << "   and  " << X;
	

	/*end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Czas wykonania: " << time_spent << endl;
	cout << "Liczba wyszukanych znaków " << znaki << endl;*/
	cin.get();
	return 0;

}