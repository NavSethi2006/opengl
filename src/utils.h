#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

#define READ_CHUNK_SIZE 2097152

typedef struct File {
    char *data;
    size_t len;
    bool is_valid;
}File;

File file_read(const char *path);
int file_write(void *buffer, size_t size, const char *path);
