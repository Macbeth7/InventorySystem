#include "Item.h"

Item::Item()
{

}

Item::Item(string name, int price)
{
	name_ = name;
	price_ = price;
}

void Item::PrintInfo() const
{
	std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
}

void Item::SetItem(string name, int price)
{
	name_ = name;
	price_ = price;
}
