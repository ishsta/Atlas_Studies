#include <stdio.h>
#include <stdlib.h>

/* fopen, fclose */

int open_file_and_close(const char *filepath) {

    /* initialize pointer to NULL to clear garbage */
    FILE *file_stream = NULL;

    /* opening file in READ mode */
    file_stream = fopen(filepath, "r");

    /* check if pointer is NULL */
    if(file_stream == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", filepath);
        return -1;
    }

    fprintf(stderr, "Successfully opened file '%s'\n", filepath);

    /* close the file */
    fclose(file_stream);

    return 0;
}

int create_file_and_close(const char *filepath) {

    FILE *file_stream = NULL;

    /* opening in WRITE mode*/
    file_stream = fopen(filepath, "w");

    if(!file_stream) {
        fprintf(stderr, "Could not open/create file '%s'\n", filepath);
        return -1;
    }

    fprintf(stderr, "Successfully open/created file '%s'\n", filepath);
    fclose(file_stream);
    return 0;
}

int append_to_file_and_close(const char *filepath, const char *data) {

    FILE *file_stream = NULL;

    /* opening in APPEND mode*/
    file_stream = fopen(filepath, "a");

    if(!file_stream) {
        fprintf(stderr, "Could not open/create file '%s'\n", filepath);
        return -1;
    }
    
    fprintf(file_stream, "New data: '%s'\n", data);

    fprintf(stderr, "Successfully open/created file '%s'\n", filepath);
    fclose(file_stream);
    return 0;
}

/* fgets, fscanf */

int read_int_from_file(const char *filepath, int *out) {
    /* initialize pointer to NULL to clear garbage */
    FILE *file_stream = NULL;
    int items_scanned;

    /* opening file in READ mode */
    file_stream = fopen(filepath, "r");

    /* check if pointer is NULL */
    if(file_stream == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", filepath);
        return -1;
    }

    fprintf(stderr, "Successfully opened file '%s'\n", filepath);

    items_scanned = (file_stream, "really important data: %d", out);

    fprintf(stderr, "%d items scanned from file\n", items_scanned);

    /* close the file */
    fclose(file_stream);

    return 0;
}

/* fputs, fprintf */

/* fseek, ftell, rewind */

int jump_around_file(const char *filepath) {
    FILE *file_stream = NULL;
    long file_offset;
    
    file_stream = fopen(filepath, "r");

    if(!file_stream) {
        fprintf(stderr, "Could not open file '%s'\n", filepath);
        return -1;
    }

    fprintf(stderr, "Successfully opened file '%s'\n", filepath);

    file_offset = ftell(file_stream);
    fprintf(stderr, "Current file offset: %ld\n", file_offset);

    fseek(file_stream, 13, SEEK_CUR);

    file_offset = ftell(file_stream);
    fprintf(stderr, "Current file offset: %ld\n", file_offset);

    fseek(file_stream, -4, SEEK_END);

    file_offset = ftell(file_stream);
    fprintf(stderr, "Current file offset: %ld\n", file_offset);

    rewind(file_stream);

    file_offset = ftell(file_stream);
    fprintf(stderr, "Current file offset: %ld\n", file_offset);
}

int main(void) {

    int result;

    // result = open_file_and_close("testfile1.txt");
    // result
    fprintf(stderr, "open_file_and_close returned %d\n", result);
    return 0;

}