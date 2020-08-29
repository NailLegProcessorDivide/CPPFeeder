#pragma once

#include <memory>

class Item {

};
class ItemStack {
	int count;
	std::shared_ptr<Item> item;
};

class ItemInput {
	virtual bool insert(ItemStack);
};

class ItemOutput {
	virtual ItemStack extract();
};



