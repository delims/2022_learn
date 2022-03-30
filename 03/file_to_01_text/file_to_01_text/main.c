//
//  main.c
//  file_to_01_text
//
//  Created by delims on 2022/3/26.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s\n",argv[0]);

    if (argc < 1) {
        printf("no file found !\n");return 0;
    }
    const char *path = argv[0];
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        printf("can not open file !\n");return 0;
    }
    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    printf("file size:%lli\n",size);

    char output[512];
    strcpy(output, path);
    strcat(output, "_out.txt");

    
    int out = open(output, O_WRONLY | O_CREAT, S_IRWXU);
    if (out < 0) {
        printf("can not create file !\n");return 0;
    }
    
    char byte;
    char out_byte[9];
    memset(out_byte, ' ', sizeof(out_byte));
    while (lseek(fd, 0, SEEK_CUR) < size) {
        read(fd, &byte, 1);
        for (int i = 0; i < 8; i++)
            out_byte[i] = (byte & (1 << (7-i))) ? '1' : '0';
        
        write(out, out_byte, sizeof(out_byte));
    }
    
    

    printf("close file ret:%d %d\n",close(fd),close(out));

    return 0;
}
