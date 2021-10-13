#include "DjikstraPlus.h"


DjikstraPlus::DjikstraPlus(float r, float g, float b, float s, int n, int h, int nos) {
	red = r;
	green = g;
	blue = b;
	sum = s;
	number = n;
	howMuch = h;
	numberOfSheds = nos;
	text.resize(numberOfSheds);
}

void DjikstraPlus::getDataFromUser() {

	cout << "Prosze podac cene przejazdu po dorze czerownej, drodze zielonej, drodze niebieskiej" << endl;
	cin >> red >> green >> blue;

	cout << "Prosze podac liczbe odwiedzonych hangarow" << endl;
	cin >> numberOfSheds;

	text.resize(numberOfSheds );

	cout << "Prosze podac liste odwiedzonych hangarow" << endl;
	for (int i = 0; i < numberOfSheds; i++) {

		cin >> text[i];
	}
	UserInputValidation();
}

void DjikstraPlus::UserInputValidation() {

	if (red < 0 || green < 0 || blue < 0 || numberOfSheds < 2) {

		cout << "Bledne dane, prosze wprowadzi wszystkie dane jeszcze raz" << endl << endl;
		getDataFromUser();
	}

	for (int i = 0; i < numberOfSheds; i++) {

		if (text[i] != 'a' && text[i] != 'A' && text[i] != 'b' && text[i] != 'B' && text[i] != 'c' && text[i] != 'C' && text[i] != 'd' && text[i] != 'D') {

			cout <<endl<< "Bledne dane, prosze wprowadzi wszystkie dane jeszcze raz" << endl << endl;
			getDataFromUser();
		}
	}
}

void DjikstraPlus::getStartingPoint(int index, float* distance) {

	if (text[index] == 'a' || text[index] == 'A') {

		distance[1] = 0;
	}

	if (text[index] == 'b' || text[index] == 'B') {

		distance[2] = 0;
	}

	if (text[index] == 'c' || text[index] == 'C') {

		distance[8] = 0;
	}

	if (text[index] == 'd' || text[index] == 'D') {

		distance[14] = 0;
	}
}

float DjikstraPlus::getSum(int index, float* distance) {

	float sum = 0;

	if (text[index + 1] == 'a' || text[index + 1] == 'A') {

		sum = sum + distance[1];
	}

	if (text[index + 1] == 'b' || text[index + 1] == 'B') {

		sum = sum + distance[2];
	}

	if (text[index + 1] == 'c' || text[index + 1] == 'C') {

		sum = sum + distance[8];
	}

	if (text[index + 1] == 'd' || text[index + 1] == 'D') {

		sum = sum + distance[14];
	}

	return sum;
}

void  DjikstraPlus::Djikstra() {
	float graph[15][15] = { INFINITY,	blue,		INFINITY,	red,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							blue,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	green,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							red,		INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	INFINITY,	INFINITY,	red,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	green,		INFINITY,	green,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							INFINITY,	green,		INFINITY,	INFINITY,	green,		INFINITY,	red,		blue,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,
							INFINITY,	INFINITY,	blue,		INFINITY,	INFINITY,	red,		INFINITY,	INFINITY,	INFINITY,	blue,		green,		INFINITY,	INFINITY,	INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	green,		blue,		INFINITY,	INFINITY,	INFINITY,	green,		INFINITY,	green,		red,		INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	red,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	green,		INFINITY,	INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	blue,		green,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	green,		INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	red,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	green,		green,		INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	red,		INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	red,		INFINITY,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	blue,		INFINITY,	INFINITY,	red,		INFINITY,	red,
							INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	red,		INFINITY,	INFINITY,	red,		INFINITY
	};

	for (int i = 0; i < numberOfSheds - 1; i++) {

		float  distance[15] = { INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY,	INFINITY };
		float previous[15] = { -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 };
		bool QS[15] = { false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false };

		getStartingPoint(i, distance);

		howMuch = 0;

		//Petla wykonujaca sie tak dlugo az caly zbior QS nie bedzie = TRUE.
		while (howMuch < 15)
		{

			//Petla szukajaca wierzchloka grafu= FALSE z najmiejszym kosztem dojscia.
			minimal = INFINITY;
			for (int i = 0; i < 15; i++) {

				if (distance[i] < minimal && QS[i] == false) {

					minimal = distance[i];
					number = i;
				}
			}

			//Petla szukajaca bardziej oplacalnych sciezek do pobliskych wierzcholkow grafu od aktulanie uznanych za najlepsze.
			for (int i = 0; i < 15; i++) {

				if (graph[number][i] + distance[number] < distance[i]) {

					distance[i] = graph[number][i] + distance[number];
					previous[i] = number;
				}
			}

			//Po sprawdzeniu wierzcholka zmienia sie on na = TRUE w zbiorze QS
			QS[number] = true;

			//Petla sprawdzajaca czy caly zbior QS = TRUE.
			howMuch = 0;
			for (int i = 0; i < 15; i++) {

				if (QS[i] == true) {

					howMuch++;
				}
			}
		}

		//Sumowanie kosztow przejsc.
		sum = sum + getSum(i, distance);
	}
	cout << sum;
}

