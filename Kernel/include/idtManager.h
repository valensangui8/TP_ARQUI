#ifndef IDTMANAGER_H
#define IDTMANAGER_H

#include <stdint.h>
#include <stddef.h>

uint64_t idtManager(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t rax);

#endif
