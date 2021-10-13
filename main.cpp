#include<iostream>
#include"DjikstraPlus.h"
using namespace std;

int main() {

	DjikstraPlus dj = DjikstraPlus();

	dj.getDataFromUser();

	dj.Djikstra();

	return 0;
}