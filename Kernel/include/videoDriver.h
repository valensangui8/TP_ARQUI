#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

#include <stdint.h>

/////////////////DRAW////////////////////

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);
void drawSquare(uint32_t hexColor, uint64_t width, uint64_t height, int x, int y);
void draw(uint32_t x, uint32_t y, uint32_t size, uint32_t color);
void drawRegisters(uint64_t value);
void drawChar(uint8_t character);
void drawError(char *word);
void drawWord(char * word);
void drawLine(char letter);
void updateCursor();
void drawWithColor(char * word, uint32_t hexColor);

/////////////////CLEAR////////////////////

void clearScreen();
void clear();

/////////////////INITIALIZE////////////////////

void start();
void initialize();

/////////////////ENTER////////////////////

void enter();
void commandEnter();

/////////////////SCALE////////////////////

int getScale();
void incScale();
void decScale();
void updateAfterCommand();

/////////////////DELETE///////////////////

void delete();

/////////////////CHECK///////////////////

void checkHeight(char * heightPassed, int indexCommand);

#endif