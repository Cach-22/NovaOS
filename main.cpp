#include <3ds.h>
#include <cstdio>
#include <vector>
#include <string>

int main() {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL); // bottom screen for menu

    std::vector<std::string> menuItems = { "DEMO 1", "DEMO 2", "DEMO 3" };
    int selected = 0; // index of the highlighted item

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        // Navigate menu
        if (kDown & KEY_UP) {
            selected--;
            if (selected < 0) selected = menuItems.size() - 1; // wrap around
        }
        if (kDown & KEY_DOWN) {
            selected++;
            if (selected >= menuItems.size()) selected = 0; // wrap around
        }

        // Select menu item
        if (kDown & KEY_A) {
            printf("\nYou selected: %s\n", menuItems[selected].c_str());
        }

        // Exit
        if (kDown & KEY_START) break;

        // Clear screen and redraw menu
        consoleClear();
        printf("=== MNOS Demo Menu ===\n\n");
        for (int i = 0; i < menuItems.size(); i++) {
            if (i == selected)
                printf("> [%s]\n", menuItems[i].c_str());
            else
                printf("  [%s]\n", menuItems[i].c_str());
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
