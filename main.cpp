#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"


class CPPFeeder : public olc::PixelGameEngine {

public:
	CPPFeeder()
	{
		sAppName = "CPPFeeder";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		printf("frame\n");
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		return true;
	}
};

int main()
{
	CPPFeeder demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}