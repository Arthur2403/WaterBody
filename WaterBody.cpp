#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "WaterBody.h"


TypesOfWaterBody WaterBody::stringToTypesOfWaterBody(const string& newType) {
	auto foo = stringToWaterBodyMap.find(newType);
	if (foo == stringToWaterBodyMap.end()) {
		cout << "Sorry there is not such type of water body";
		return TypesOfWaterBody::River;
	}
	return foo->second;
}

ostream& operator<<(ostream& out, WaterBody waterBody) {
	if (waterBody.type == TypesOfWaterBody::Sea) {
		out << "Your water body is sea, and it's volume is " << waterBody.getVolume() << "\n";
		return out;
	}
	else if (waterBody.type == TypesOfWaterBody::Ocean) {
		out << "Your water body is ocean, and it's volume is " << waterBody.getVolume() << "\n";
		return out;
	}
	else if (waterBody.type == TypesOfWaterBody::Pond) {
		out << "Your water body is pond, and it's volume is " << waterBody.getVolume() << "\n";
		return out;
	}
	else if (waterBody.type == TypesOfWaterBody::Lake) {
		out << "Your water body is lake, and it's volume is " << waterBody.getVolume() << "\n";
		return out;
	}
	else if (waterBody.type == TypesOfWaterBody::River) {
		out << "Your water body is river, and it's volume is " << waterBody.getVolume() << "\n";
		return out;
	}
	else {
		out << "Wrond type";
		return out;
	}
}


ostream& operator<<(ostream& out, TypesOfWaterBody typeOfWaterBody) {
	if (typeOfWaterBody == TypesOfWaterBody::Sea) {
		out << "sea";
		return out;
	}
	else if (typeOfWaterBody == TypesOfWaterBody::Ocean) {
		out << "ocean";
		return out;
	}
	else if (typeOfWaterBody == TypesOfWaterBody::Pond) {
		out << "pond";
		return out;
	}
	else if (typeOfWaterBody == TypesOfWaterBody::Lake) {
		out << "lake";
		return out;
	}
	else if (typeOfWaterBody == TypesOfWaterBody::River) {
		out << "river";
		return out;
	}
	else {
		out << "unkown";
		return out;
	}
}

WaterBody& WaterBody::operator=(const WaterBody& anotherWaterBody) {
	if (*this == anotherWaterBody) {
		return *this;
	}

	length = anotherWaterBody.length;
	width = anotherWaterBody.width;
	depth = anotherWaterBody.depth;
	type = anotherWaterBody.type;
	return *this;
}
