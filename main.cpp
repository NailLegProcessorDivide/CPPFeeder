#include <memory>

#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"
#include "structure.h"


class CPPFeeder : public olc::PixelGameEngine {
private:
	double scale;
	World world;
public:
	CPPFeeder()
	{
		sAppName = "CPPFeeder";
		scale = 32;
		std::shared_ptr<Structure> structure = std::make_shared<Structure>(std::make_shared<olc::Sprite>("white.png"), olc::vi2d(1, 1));
		world.add(structure);
	}

public:
	bool OnUserCreate() override
	{
		AllItems* ai = AllItems::getAllItems();
		printf("name blue: %s\n", ai->blue->getName().c_str());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		std::vector<std::shared_ptr<Structure>>& structures = world.getStructures();
		for(std::shared_ptr<Structure> structure : structures) {
			olc::vi2d& pos = structure->getPos();
			DrawSprite(pos*scale, structure->getSprite().get());
		}
		return true;
	}
};

int main()
{
	CPPFeeder demo;
	if (demo.Construct(1024, 768, 1, 1))
		demo.Start();

	return 0;
}