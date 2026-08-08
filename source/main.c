#include <stdio.h>
#include <3ds.h>

#define len(a) (sizeof(a) / sizeof((a)[0]))

int main(int argc, char* argv[])
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	struct KeyEntry {u32 mask; const char* name;};
	static const struct KeyEntry keys[] = {
		{KEY_A, "A"},
        {KEY_B, "B"},
        {KEY_SELECT, "Select"},
        {KEY_START, "Start"},
        {KEY_DRIGHT, "D-Pad Right"},
        {KEY_DLEFT, "D-Pad Left"},
        {KEY_DUP, "D-Pad Up"},
        {KEY_DDOWN, "D-Pad Down"},
        {KEY_R, "R"},
        {KEY_L, "L"},
        {KEY_X, "X"},
        {KEY_Y, "Y"},
        {KEY_ZL, "ZL"},
        {KEY_ZR, "ZR"},
        {KEY_TOUCH, "Touch"},
        {KEY_CSTICK_RIGHT, "C-Stick Right"},
        {KEY_CSTICK_LEFT, "C-Stick Left"},
        {KEY_CSTICK_UP, "C-Stick Up"},
        {KEY_CSTICK_DOWN, "C-Stick Down"},
        {KEY_CPAD_RIGHT, "Circle Pad Right"},
        {KEY_CPAD_LEFT, "Circle Pad Left"},
        {KEY_CPAD_UP, "Circle Pad Up"},
        {KEY_CPAD_DOWN, "Circle Pad Down"},
        {KEY_UP, "Up"},
        {KEY_DOWN, "Down"},
        {KEY_LEFT, "Left"},
        {KEY_RIGHT, "Right"}
	};

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (kDown & KEY_START) break;

		printf("\x1b[2J");
		printf("\x1b[1;1H");
		printf("Hello, world!\n");
		for (int i = 0; i < len(keys); i++){
			if (kHeld & keys[i].mask){
				printf("%s ", keys[i].name);
			}
		}

		gspWaitForVBlank();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
