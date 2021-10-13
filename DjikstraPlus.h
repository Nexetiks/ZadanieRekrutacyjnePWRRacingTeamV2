#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;
class DjikstraPlus
{
	float red, green, blue;

	float minimal = INFINITY, sum;

	int number, howMuch, numberOfSheds;

	vector<char> text;

public:
	DjikstraPlus(float = 5.0, float = 1.5, float = 0.1, float = 0, int = 0, int = 0, int = 2);

	/// <summary>
	/// Funkcja wczytujaca dane wejsciowe od uzytkownika.
	/// </summary>
	void getDataFromUser();

	// <summary>
	/// Obsluzenie przypadku w ktorym uzytkownik podal bledne dane.
	/// </summary>
	void UserInputValidation();

	/// <summary>
	/// Funkcja ustalajaca skad zaczyna poruszac sie robot.
	/// </summary>
	/// <param name="inex">Index elementu tablicy.</param>
	/// <param name="distance">Tablica z aktualnym kosztem dojscia najkrotsza droga do danego wierzcholka.</param>
	void getStartingPoint(int index, float* distance);

	/// <summary>
	/// Funkcja sumujaca koszt przejscia miedzy wszystkimi hangarami.
	/// </summary>
	/// <param name="index">Index elementu tablicy.</param>
	/// <param name="distance">Tablica z aktualnym kosztem dojscia najkrotsza droga do danego wierzcholka.</param>
	/// <returns></returns>
	float getSum(int index, float* distance);


	/// <summary>
	/// Algorytm dijkstry przerobiony o mozliwosc trasy zahaczaj¹ce o wybrane punkty.
	/// </summary>
	void  Djikstra();

};

