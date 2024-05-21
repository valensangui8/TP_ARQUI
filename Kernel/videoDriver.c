#include <videoDriver.h>
#include <stdint.h>
#include <font.h>


//font
#define WIDTH_FONT 8
#define HEIGHT_FONT 16
#define TAB_SIZE 4

//screen
#define LAST_X 1024
#define LAST_Y 768
#define SCALE 1

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define YELLOW 0xFFFF00
#define ORANGE 0xFFA500

static uint32_t characterColor = 0xFFFFFF; // default color white
static uint32_t backgroundColor = 0x000000; // default color black

static uint16_t x = 0; // donde arranco en x
static uint16_t y = 0; // donde arranco en y
static uint64_t scale = 1; // escala de la letra



struct vbe_mode_info_structure {
	uint16_t attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
	uint8_t window_a;			// deprecated
	uint8_t window_b;			// deprecated
	uint16_t granularity;		// deprecated; used while calculating bank numbers
	uint16_t window_size;
	uint16_t segment_a;
	uint16_t segment_b;
	uint32_t win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
	uint16_t pitch;			// number of bytes per horizontal line
	uint16_t width;			// width in pixels
	uint16_t height;			// height in pixels
	uint8_t w_char;			// unused...
	uint8_t y_char;			// ...
	uint8_t planes;
	uint8_t bpp;			// bits per pixel in this mode
	uint8_t banks;			// deprecated; total number of banks in this mode
	uint8_t memory_model;
	uint8_t bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
	uint8_t image_pages;
	uint8_t reserved0;
 
	uint8_t red_mask;
	uint8_t red_position;
	uint8_t green_mask;
	uint8_t green_position;
	uint8_t blue_mask;
	uint8_t blue_position;
	uint8_t reserved_mask;
	uint8_t reserved_position;
	uint8_t direct_color_attributes;
 
	uint32_t framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
	uint32_t off_screen_mem_off;
	uint16_t off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen
	uint8_t reserved1[206];
} __attribute__ ((packed));

typedef struct vbe_mode_info_structure * VBEInfoPtr;

VBEInfoPtr VBE_mode_info = (VBEInfoPtr) 0x0000000000005C00;

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y) {
    uint8_t * framebuffer = (uint8_t *) VBE_mode_info->framebuffer;
    uint64_t offset = (x * ((VBE_mode_info->bpp)/8)) + (y * VBE_mode_info->pitch);
    framebuffer[offset]     =  (hexColor) & 0xFF;
    framebuffer[offset+1]   =  (hexColor >> 8) & 0xFF; 
    framebuffer[offset+2]   =  (hexColor >> 16) & 0xFF;
}

void drawSquare(uint32_t hexColor, uint64_t width, uint64_t height, int x, int y){
    for(uint64_t i = x; i < width; i++){
        for(uint64_t j = y; j < height; j++){
            putPixel(hexColor, i, j);
        }
    }
}

void drawChar(uint8_t character, int scale) {
    unsigned char * bitMapChar = font[character];
	//drawSquare(0x000000, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
    for (int i = 0; i < HEIGHT_FONT * scale; i++) {
        for (int j = 0; j < WIDTH_FONT * scale; j++) {
            int bit = (bitMapChar[i/scale] >> (j/scale)) & 1;
            if (bit) {
                putPixel(0xFFFFFF, x + j, y + i);
            }
        }
    }
	x += WIDTH_FONT * scale;
	
}

// void deleteChar(uint8_t character, int x, int y, int scale) {
//     for(int i = 0; i < + HEIGHT_FONT * scale; i++){
// 		for(int j = 0; j < WIDTH_FONT * scale; j++){
// 			putPixel(0x000000, x + j, y + i);
// 		}
// 	}
	
// }

void drawWord(char * word, int scale) {
    int i = 0;
    while (word[i] != 0) {
        drawChar(word[i], scale);
		i++;
    }
}

void clearScreen(){
	drawSquare(0x000000, VBE_mode_info->width, VBE_mode_info->height, 0, 0);
	x = 0;
	y = 0;
	drawWord("TP_ARQUI - GRUPO 12$", 1);
}

void drawLine(char letter){
	if(x + 8 * scale  >= VBE_mode_info->width){
		x = 10;
		y += 16 * scale;
	}
	if(y + 16 * scale >= VBE_mode_info->height){
		clearScreen();
	}
	drawChar(letter, scale);
	/updateCursor();
}

void initialize(){
	drawWord("TP_ARQUI - GRUPO 12$", 1);
	
	x += 8 * scale;
	
	//drawChar('|', scale);
	
	
	
}



//void updateCursor(){
	//drawChar('|', scale);
//}


void enter(){
	y += 16 * scale;
	x = 0;
	drawWord("TP_ARQUI - GRUPO 12$", 1);
	x += 8 * scale;

	return;
}


/*
void delete(){
	drawLine('\b');
	if(x + 8 * scale  >= VBE_mode_info->width){
		x = 10;
		y += 16 * scale;
	}
	if(y + 16 * scale >= VBE_mode_info->height){
		clearScreen();
	}
	drawChar(letter, x, y, scale);

	if(x == 21 + 8*scale){
		if(y== 0){
			drawChar('');
			return;
		}
		
	}
*/