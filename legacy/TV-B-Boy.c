#include <stdio.h>
#include <gb/gb.h>
#include <gb/cgb.h>

//Title screen
#include "Tiles/K_tiles.h"
#include "Tiles/K_tiles.c"
#include "Map/K_map.c"

//Screen if isn't a GBC
#include "Tiles/Nocolor_tiles.c"
#include "Map/Nocolor_map.c"

extern UBYTE _cpu;
#define CGB_MODE 0x11

const UWORD k_color[] = {
    k_tilesCGBPal0c0, k_tilesCGBPal0c1, k_tilesCGBPal0c2, k_tilesCGBPal0c3 //Write colors
};

int main()
{ 
        /* ========== Title Screen ========== */
        set_bkg_palette(0, 1, &k_color[0]); //Write colors on the tiles
        set_bkg_data(0, 6, k_tiles); //Write tiles in the VRAM
        set_bkg_tiles(0, 0, 20, 18, k_map); //Put tiles on the map
        SHOW_BKG; //Show the background
        DISPLAY_ON; //Turn on the screen
        delay(1000); //Delay of 1 sec to show the title screen

        HIDE_BKG; //Clear the background
        DISPLAY_OFF; //Clear the screen

        if (_cpu == CGB_MODE) //Check if it's a GBC
        {
            printf("===== TV-B-Boy =====\n");
			printf("Welcome\n\n");
			printf("Press A to send IR\nsignals\n\n");
			printf("Press Select to go\nto the settings\n");
			printf("\n\n\n\n\n\n\n\n");
			printf("2018 - KeetKhat");
        }
        else //if isn't
        {
            set_bkg_data(0, 42, Nocolor_tiles);
            set_bkg_tiles(0, 0, 20, 18, Nocolor_map);
            SHOW_BKG;
            DISPLAY_ON;
        }
}