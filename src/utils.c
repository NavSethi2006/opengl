#include "utils.h"

File file_read(const char *path) {
    File file_ = {.is_valid = false};

    FILE* fp = fopen(path, "rb");
    if(ferror(fp)) printf("ERROR reading file: %s. errno code: %d\n", path, errno);

    char* data = NULL;
    char* tmp;
    size_t used = 0;
    size_t size = 0;
    size_t n;

    while(true) {
        if(used + READ_CHUNK_SIZE + 1 > size) {
            size = used + READ_CHUNK_SIZE + 1;
            if(size <= used){
                free(data);
                printf("input file too large %s\n", path);
                exit(1);
            }

            tmp = realloc(data, size);
            if(!tmp) {
                free(data);
                printf("ERROR reading file: %s. errno code: %d\n", path, errno);
                exit(1);
            }
            data = tmp;
        }
        n = fread(data + used, 1, READ_CHUNK_SIZE, fp);
        if(n == 0)
            break;

        used += n;
    }

    if(ferror(fp)) {
        free(data);
        printf("ERROR reading file: %s. errno code: %d\n", path, errno);
        exit(1);
    }

    tmp = realloc(data, used+1);
    if(!tmp) {
        free(data);
        printf("ERROR reading file %s. errno code: %d\n", path, errno);
        exit(1);
    }

    data = tmp;
    data[used] = 0;

    file_.data = data;
    file_.len = used;
    file_.is_valid = true;

    return file_;
}

int file_write(void *buffer, size_t size, const char *path) {

}

