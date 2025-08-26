#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	Item();

	Item(string name, int price);

	/*bool operator<(Item &ref) {
		return GetPrice() < ref.GetPrice();
	}*/

private:
	string name_ = "";

	int price_ = 0;

public:
	void PrintInfo() const;

	void SetItem(string name, int price);

	string GetName() const{
		return name_;
	}

	int GetPrice() const {
		return price_;
	}

private:
};

class Weapon : public Item 
{
public:

private:

public:

private:
};

class Potion : public Item
{
public:

private:

public:

private:
};
