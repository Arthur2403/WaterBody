#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include "WaterBody.h"
#include "functions.h"


void addWaterBody(vector<WaterBody>& waterBodyVector, WaterBody& newWaterBody) {
	waterBodyVector.push_back(newWaterBody);
}


void deleteWaterBody(vector<WaterBody>& waterBodyVector, WaterBody& newWaterBody) {
	waterBodyVector.erase(remove(waterBodyVector.begin(), waterBodyVector.end(), newWaterBody), waterBodyVector.end());
}

void writeWaterBodyInTextFile(const string& fileName, vector<WaterBody>& waterBodyVector) {
	ofstream endFile(fileName, ios::app);
	endFile.open(fileName);
	if (!endFile.is_open()) {
		cerr << "Error: Could not open file for writing!" << endl;
		return;
	}
	for (WaterBody& waterBody : waterBodyVector) {
		endFile << "Name: " << waterBody.getName() << "Type: " << waterBody.getType() << "\nLength: " <<
			waterBody.getLength() << "\nWidth: " << waterBody.getWidth() << "\nDepth: " << waterBody.getDepth();
	}
	endFile.close();
}

WaterBody fillWaterBody() {
	string name;
	string type;
	double length;
	double width;
	double depth;
	cout << "Enter data about water body(Name, Type, length, width, depth)\n";
	getline(cin, name);
	cin >> type;
	cin >> length;
	cin >> width;
	cin >> depth;
	WaterBody waterBody(width, length, depth, type, name);
	return waterBody;
}

void menu() {
	vector<WaterBody> waterBodyVector;
	string choise;
	string stop;
	while (stop != "yes") {
		cout << "add - add water body\ndel - delete water body\nwr - write all water bodies in file";
		cin >> choise;
		if (choise == "add") {
			WaterBody waterBody = fillWaterBody();
			addWaterBody(waterBodyVector, waterBody);
		}
		else if(choise == "del") {
			WaterBody waterBody = fillWaterBody();
			deleteWaterBody(waterBodyVector, waterBody);
		}
		else if (choise == "wr") {
			string fileName;
			cout << "Enter name of file";
			cin >> fileName;
			writeWaterBodyInTextFile(fileName, waterBodyVector);
		}
		cout << "Would you like to end?(yes or no)\n";
		cin >> stop;
	}
}