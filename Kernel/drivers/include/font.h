#ifndef FONT_H
#define FONT_H

#include <stdint.h>
#define DEFAULT_HEIGHT = 16
#define DEFAULT_WIDTH = 8


const char font[] = {
    0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '!' 
    0x00, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '"'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x36, 0x00, 0x7F, 0x00, 0x36, 0x00, 0x36, 0x00, 0x36, 0x00, 0x7F, 0x00, 0x36, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '#'  
    0x18, 0x00, 0x18, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x43, 0x00, 0x03, 0x00, 0x3E, 0x00, 0x60, 0x00, 0x60, 0x00, 0x61, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, // '$'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x00, 0x63, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x63, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '%'  
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x36, 0x00, 0x36, 0x00, 0x1C, 0x00, 0x6E, 0x00, 0x3B, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '&'  
    0x00, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '''  
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '('  
    0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ')'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x3C, 0x00, 0xFF, 0x00, 0x3C, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '*'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x7E, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '+'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ','  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '-'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '.'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '/'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x66, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '0'  
    0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x1E, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '1'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x03, 0x00, 0x63, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '2'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x60, 0x00, 0x60, 0x00, 0x3C, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '3'  
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x38, 0x00, 0x3C, 0x00, 0x36, 0x00, 0x33, 0x00, 0x7F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '4'  
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x3F, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '5'  
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x3F, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '6'  
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x63, 0x00, 0x60, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '7'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '8'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x7E, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x30, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '9'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ':'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ';'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '<'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '='  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '>'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x30, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '?'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x7B, 0x00, 0x7B, 0x00, 0x7B, 0x00, 0x3B, 0x00, 0x03, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '@'  
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x1C, 0x00, 0x36, 0x00, 0x63, 0x00, 0x63, 0x00, 0x7F, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'A'  
    0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3E, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'B'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x66, 0x00, 0x43, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x43, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'C'  
    0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x36, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x36, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'D'  
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x66, 0x00, 0x46, 0x00, 0x16, 0x00, 0x1E, 0x00, 0x16, 0x00, 0x06, 0x00, 0x46, 0x00, 0x66, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'E'  
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x66, 0x00, 0x46, 0x00, 0x16, 0x00, 0x1E, 0x00, 0x16, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'F'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x66, 0x00, 0x43, 0x00, 0x03, 0x00, 0x03, 0x00, 0x7B, 0x00, 0x63, 0x00, 0x63, 0x00, 0x66, 0x00, 0x5C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'G'  
    0x00, 0x00, 0x00, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x7F, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'H'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'I'  
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'J'  
    0x00, 0x00, 0x00, 0x00, 0x67, 0x00, 0x66, 0x00, 0x66, 0x00, 0x36, 0x00, 0x1E, 0x00, 0x1E, 0x00, 0x36, 0x00, 0x66, 0x00, 0x66, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'K'  
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x46, 0x00, 0x66, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'L'  
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xE7, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xDB, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'M'  
    0x00, 0x00, 0x00, 0x00, 0x63, 0x00, 0x67, 0x00, 0x6F, 0x00, 0x7F, 0x00, 0x7B, 0x00, 0x73, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'N'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'O'  
    0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3E, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'P'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x6B, 0x00, 0x7B, 0x00, 0x3E, 0x00, 0x30, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, // 'Q'  
    0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3E, 0x00, 0x36, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'R'  
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x06, 0x00, 0x1C, 0x00, 0x30, 0x00, 0x60, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'S'  
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xDB, 0x00, 0x99, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'T'  
    0x00, 0x00, 0x00, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'U'  
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'V'  
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xFF, 0x00, 0x66, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'W'  
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x66, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'X'  
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'Y'  
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xC3, 0x00, 0x61, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x83, 0x00, 0xC3, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'Z'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '['  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0x60, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '\'  
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ']'  
    0x08, 0x00, 0x1C, 0x00, 0x36, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '^'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, // '_'  
    0x0C, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '`'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x30, 0x00, 0x3E, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'a'  
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x1E, 0x00, 0x36, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'b'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'c'  
    0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3C, 0x00, 0x36, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'd'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x7F, 0x00, 0x03, 0x00, 0x03, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'e'  
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x36, 0x00, 0x26, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'f'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x3E, 0x00, 0x30, 0x00, 0x33, 0x00, 0x1E, 0x00, 0x00, 0x00, // 'g'  
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x36, 0x00, 0x6E, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'h'  
    0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'i'  
    0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x00, 0x00, // 'j'  
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x66, 0x00, 0x36, 0x00, 0x1E, 0x00, 0x1E, 0x00, 0x36, 0x00, 0x66, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'k'  
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'l'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x00, 0xFF, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'm'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'n'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'o'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x66, 0x00, 0x3E, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x00, 0x00, // 'p'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x3E, 0x00, 0x30, 0x00, 0x30, 0x00, 0x78, 0x00, 0x00, 0x00, // 'q'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x6E, 0x00, 0x66, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'r'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x63, 0x00, 0x06, 0x00, 0x1C, 0x00, 0x30, 0x00, 0x63, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 's'  
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x3F, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x6C, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 't'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'u'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'v'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xDB, 0x00, 0xDB, 0x00, 0xFF, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'w'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x00, 0x66, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x66, 0x00, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'x'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x63, 0x00, 0x7E, 0x00, 0x60, 0x00, 0x30, 0x00, 0x1F, 0x00, 0x00, 0x00, // 'y'  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x33, 0x00, 0x18, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x63, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 'z'  
    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0E, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '{'  
    0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '|'  
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x70, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '}'  


};


#endif // FONT_H_  