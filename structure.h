#pragma once

#include <memory>
#include <vector>
#include <string>
#include "olcPixelGameEngine.h"

typedef olc::vi2d vec2i;

class Item {
private:
	std::string name;
	std::shared_ptr<olc::Sprite> icon;
public:
	Item(std::string name,std::shared_ptr<olc::Sprite> icon) : name(name), icon(icon){}
	const std::string& getName() {return name;}
};

class ItemStack {
private:
	int count;
	std::shared_ptr<Item> item;
};

class AllItems {//singleton
private:
	AllItems() : blue(std::make_shared<Item>("blue", std::make_shared<olc::Sprite>("blue.png"))),
				 green(std::make_shared<Item>("green", std::make_shared<olc::Sprite>("green.png"))),
				 cyan(std::make_shared<Item>("cyan", std::make_shared<olc::Sprite>("cyan.png"))) {}
	static AllItems* aItems;
public:
	static AllItems* getAllItems(){
		if (aItems == nullptr) {
			aItems = new AllItems();
		}
		return aItems;
	};
	AllItems(const AllItems& i) = delete;//no copy constructor
	~AllItems(){delete aItems;}
	std::shared_ptr<Item> blue;
	std::shared_ptr<Item> green;
	std::shared_ptr<Item> cyan;
};

class ItemInput {
private:
	vec2i pos;
	ItemStack stack;
public:
	virtual bool insert(ItemStack);
};

class ItemOutput {
private:
	vec2i pos;
	ItemStack stack;
public:
	virtual ItemStack extract();
};

class Structure {
private:
	vec2i pos;
	std::shared_ptr<olc::Sprite> sprite;
public:
	Structure(std::shared_ptr<olc::Sprite> spr, vec2i pos) : sprite(spr), pos(pos) {}
	std::shared_ptr<olc::Sprite> getSprite() {return sprite;}
	vec2i& getPos() {return pos;}
};

class Mine : public Structure {

};
class Combiner : public Structure {

};

class World {
private:
	std::vector<std::shared_ptr<ItemInput>> openInputs;
	std::vector<std::shared_ptr<ItemOutput>> openOutputs;
	std::vector<std::shared_ptr<Structure>> structures;
public:
	void add(std::shared_ptr<Structure> str) {structures.push_back(str);}
	std::vector<std::shared_ptr<Structure>>& getStructures(){return structures;}
};
