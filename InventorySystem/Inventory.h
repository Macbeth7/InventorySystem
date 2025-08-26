#pragma once
#include "Item.h"
#include <iostream>
#include <algorithm>

template <typename T>
class Inventory
{

public:
	Inventory(int capacuty = 10) {
		capacity_ = capacuty > 0 ? capacuty : 1;
		pItems_ = new T[capacity_];
	}

	Inventory(const Inventory<T>& other)
	{
		Assign(other);
	}

	~Inventory() {
		/* 해줘야 되는지 말아야 되는지 알수 없음.
		for (int i = 0; i < sizeof(pItems_) / sizeof(*pItems_); i++)
		{
			pItems_[i] = nullptr;
		}
		*/
		delete[] pItems_;
		pItems_ = nullptr;
	}

private:
	int capacity_ = 0;

	int size_ = 0;

	T* pItems_;

public:
	void AddItem(const T& item)
	{
		/*
		if (size_ < capacity_)
		{
			pItems_[size_] = item;
			size_++;
		}
		else {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
		}
		*/

		if (size_ >= capacity_) Resize(capacity_ * 2);

		pItems_[size_] = item;
		size_++;
	}

	void RemoveLastItem()
	{
		if (size_ > 0)
		{
			size_--;
		}
		else {
			std::cout << "인벤토리가 비어있습니다." << std::endl;
		}
	}

	int GetSize() const {
		return size_;
	};

	int GetCapacity_() const {
		return capacity_;
	};

	T* GetItemsPtr() const{
		return pItems_;
	}

	void PrintAll_Items() const
	{
		if (capacity_ <= 0 || size_ <= 0) {
			std::cout << "비어있음." << std::endl;
			return;
		}

		if (isItem())
		{
			for (int index = 0; index < size_; index++)
			{
				Item* _Item = dynamic_cast<Item*>(&pItems_[index]);
				_Item->PrintInfo();
			}
		}
	}

	void Assign(const Inventory<T>& other)
	{
		capacity_ = other.GetCapacity_();
		size_ = other.GetSize();

		//깊은복사
		T* new_pItems = new T[other.GetCapacity_()];
		for (int i = 0; i < other.GetSize(); i++)
		{
			new_pItems[i] = other.GetItemsPtr()[i];
		}

		delete[] pItems_;
		pItems_ = new_pItems;

		std::cout << "인벤토리 복사 완료" << std::endl;
	}

	void Resize(int newCapacity)
	{
		if (capacity_ == newCapacity)
		{
			return;
		}
		else if (capacity_ < newCapacity) {
			T* new_pItems = new T[newCapacity];

			//깊은 복사
			for (int i = 0; i < capacity_; i++)
			{
				new_pItems[i] = pItems_[i];
			}

			delete[] pItems_;
			pItems_ = new_pItems;

			capacity_ = newCapacity;
		}
		else {
			capacity_ = newCapacity;
			size_ = newCapacity; 
		}
	}

	void SortItems()
	{
		Item* check_casting = dynamic_cast<Item*>(&pItems_[0]);
		if (check_casting != nullptr)
		{
			sort(pItems_, pItems_ + size_, compareItemsByPrice);
		}
	}

	bool isItem() const {
		Item* check_casting = dynamic_cast<Item*>(&pItems_[0]);
		return check_casting != nullptr ? true : false;
	}

	static bool compareItemsByPrice(const T& a, const T& b)
	{
		return a.GetPrice() < b.GetPrice();
	}

private:
};

