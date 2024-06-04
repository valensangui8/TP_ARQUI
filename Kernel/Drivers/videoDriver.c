#include <videoDriver.h>
#include <stdint.h>
#include <font.h>
#include <naiveConsole.h>

//font
#define WIDTH_FONT 8
#define HEIGHT_FONT 16
#define TAB_SIZE 4
#define MAX_X 1008
#define MAX_Y 736
#define MIN_X 8
#define MIN_Y 8


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
static void uint64HexaToString(uint64_t valorHexa, char *hexaString);
static uint64_t binaryToHex(uint64_t binaryNum);
static void drawLine2(char letter);

static uint32_t characterColor = 0xFFFFFF; // default color white
static uint32_t colorVariable = 0;
static uint32_t backgroundColor = 0x000000; // default color black

static uint16_t x = 0; // donde arranco en x
static uint16_t y = 0; // donde arranco en y
static int scale; // escala de la letra
static int flag_enter = 1;
static int flag_bottom_enter = 0;
static int commands[10] = {0, 0, 0, 21, 0, 31, 23, 4, 0, 0};



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

/////////////////DRAW////////////////////

void drawSquare(uint32_t hexColor, uint64_t width, uint64_t height, int x, int y){
    for(uint64_t i = x; i-x < width; i++){
        for(uint64_t j = y; j-y < height; j++){
            putPixel(hexColor, i, j);
        }
    }
}

void draw(uint32_t x, uint32_t y, uint32_t size, uint32_t color){
	drawSquare(color, size, size, x, y);
}

void drawRegisters(uint64_t value){
    char buffer[256] = {0};
	value = binaryToHex(value);
    uint64HexaToString(value, buffer);
    drawWord(buffer);
    commandEnter();
}

static uint64_t binaryToHex(uint64_t binaryNum){
    return binaryNum;
}

static void uint64HexaToString(uint64_t valorHexa, char *hexaString) {
    int i;
    for (i = 15; i >= 0; i--) {
        uint64_t nibble = (valorHexa >> (i * 4)) & 0xF;
        hexaString[15 - i] = (nibble < 10) ? (char)('0' + nibble) : (char)('A' + (nibble - 10));
    }
    hexaString[16] = 'h';
    hexaString[17] = '\0'; // Terminar la cadena con el carácter nulo
}

void drawChar(uint8_t character) {
    unsigned char * bitMapChar = font[character];
	drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
    for (int i = 0; i < HEIGHT_FONT * scale; i++) {
        for (int j = 0; j < WIDTH_FONT * scale; j++) {
            int bit = (bitMapChar[i/scale] >> (j/scale)) & 1;
            if (bit) {
                putPixel(characterColor, x + j, y + i);
            }
        }
    }
	x += WIDTH_FONT * scale;

}


void drawError(char *word) {
	drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
	int i = 0;
	commandEnter();
	char * toDraw = "ERROR - command not found: ";
	drawWord(toDraw);
	drawWord(word);
	enter();
}

void drawWord(char * word) {
    int i = 0;
    while (word[i] != 0) {
		// if(y + 16 * scale >= VBE_mode_info->height){
		// 	if(flag_bottom_enter == 1){
		// 		y = 0;
		// 		flag_bottom_enter = 0;
		// 	}
		// 	clearScreen();
		// 	flag_enter = 1;
		// 	return;
		// }
        drawLine2(word[i]);
		i++;
    }
}

static void drawLine2(char letter){
	if(x + 8 * scale  >= VBE_mode_info->width){
		drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
		x = 0;
		y += 16 * scale;
		flag_enter = 0;
	}
	if(y + 16 * scale >= VBE_mode_info->height){
		y = 0;
		clear();
		flag_enter = 1;
		return;
	}
	drawChar(letter);
}


void drawLine(char letter){
	if(x + 8 * scale  >= VBE_mode_info->width){
		drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
		x = 0;
		y += 16 * scale;
		flag_enter = 0;
	}
	if(y + 16 * scale >= VBE_mode_info->height){
		y = 0;
		clearScreen();
		flag_enter = 1;
		return;
	}
	drawChar(letter);
	updateCursor();
}


void updateCursor(){
	drawSquare(characterColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
}


drawWithColor(char * word, uint32_t hexColor){
	characterColor = hexColor;
	drawWord(word);
	characterColor = WHITE;
}



/////////////////CLEAR////////////////////

void clearScreen(){
	drawSquare(backgroundColor, VBE_mode_info->width, VBE_mode_info->height, 0, 0);
	x = 0;
	y = 0;
	drawWord("TP_ARQUI - GRUPO 12$");
}


void clear(){
	drawSquare(backgroundColor, VBE_mode_info->width, VBE_mode_info->height, 0, 0);
	x = 0;
	y = 0;
	updateAfterCommand();
}

/////////////////INITIALIZE////////////////////

void start() {
	scale = 3;
	x = 435;
	y = 350;
	drawWord("voidOS");
	scale = 1;
	x -= 100;
	y += 50;
	drawWord("Loading...");
}

void initialize(){
	scale = 1;
	x = 0;
	y = 0;
	drawWord("TP_ARQUI - GRUPO 12$ ");
	updateCursor();
}

/////////////////ENTER////////////////////

void enter(){
	drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
	y += 16 * scale;
	x = 0;
	drawWord("TP_ARQUI - GRUPO 12$");
	flag_enter = 1;
	x += 8 * scale;
	updateCursor();
	
	return;
}


void commandEnter(){
	drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
	x = 0;
	y += HEIGHT_FONT * scale;
}


/////////////////SCALE////////////////////

int getScale(){
	return scale;
}

void incScale(){
	scale++;
	clear();
}

void decScale(){
	if(scale > 1){
		scale--;
		clear();
	}
}


void updateAfterCommand(){
	x -= WIDTH_FONT * scale;
	y -= HEIGHT_FONT * scale;
}





/////////////////DELETE////////////////////

void delete(){
	if(x <= 21 * 8 * scale && flag_enter == 1){
		return;
	}
	if(x < WIDTH_FONT * scale){
		drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y); // borro puntero linea de abajo
		x = VBE_mode_info->width - 2*(WIDTH_FONT * scale); // vuelvo a último lugar de la línea en X
		y -= HEIGHT_FONT * scale; // vuelvo un renglón para arriba
		drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y); // borro letra de linea arriba der
		updateCursor();
		return;
	}
	//drawSquare(0x000000, WIDTH_FONT * scale, HEIGHT_FONT * scale, x + WIDTH_FONT * scale, y);
	drawSquare(backgroundColor, WIDTH_FONT * scale, HEIGHT_FONT * scale, x, y);
	x -= WIDTH_FONT * scale;
	updateCursor();
	return;
}


/////////////////CHECK////////////////////


void checkHeight(char * HeightPassed, int command){
	if(y + commands[command]*16 * scale >= VBE_mode_info->height){
		*HeightPassed = 1;
	}
	else {
		*HeightPassed = 0;
	}
}

/////////////////IMAGE////////////////////
