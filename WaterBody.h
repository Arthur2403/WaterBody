#pragma once

using namespace std;

enum class TypesOfWaterBody {
	Sea,
	Ocean,
	Lake,
	Pond,
	River,
};

ostream& operator<<(ostream& out, TypesOfWaterBody);

map<string, TypesOfWaterBody> stringToWaterBodyMap{
	{ "Sea", TypesOfWaterBody::Sea },
	{ "Ocean", TypesOfWaterBody::Ocean },
	{ "Lake", TypesOfWaterBody::Lake },
	{ "Pond", TypesOfWaterBody::Pond },
	{ "River", TypesOfWaterBody::River },
};

class WaterBody {
private:
	double width;
	double length;
	double depth;
	TypesOfWaterBody type;
	string name;
public:

	explicit WaterBody(const double newWidth = 1, const double newLength = 1, const double newDepth = 1, const string& newType = "River", const string newName = "Latoritsa") {
		setWidth(newWidth);
		setLength(newLength);
		setDepth(newDepth);
		setName(newName);
		setType(newType);
	}

	double getWidth() const { return width; }
	void setWidth(const double newWidth) { if (newWidth > 0) { width = newWidth; } }
	double getLength() const { return length; }
	void setLength(const double newLength) { if (newLength > 0) { length = newLength; } }
	double getDepth() const { return depth; }
	void setDepth(const double newDepth) { if (newDepth > 0) { depth = newDepth; } }
	string getName() const { return name; }
	void setName(const string& newName) { if (newName.size() > 0) { name = newName; } }

	TypesOfWaterBody getType() const { return type; }
	void setType(const string& newType) { type = stringToTypesOfWaterBody(newType); }
	TypesOfWaterBody stringToTypesOfWaterBody(const string& newType);

	double getVolume() const { return width * length * depth; }
	double getArea() const { return width * length; }

	bool operator==(const WaterBody &anotherWaterBody) { return type == anotherWaterBody.type; }
	bool operator>(const WaterBody& anotherWaterBody) { return getArea() > anotherWaterBody.getArea(); }
	WaterBody& operator=(const WaterBody& anotherWaterBody);

	friend ostream& operator<<(ostream& out, WaterBody waterBody);
};