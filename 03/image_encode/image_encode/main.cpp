//
//  main.cpp
//  image_encode
//
//  Created by delims on 2022/3/8.
//

#include <iostream>
#include <cstdio>




void decode_image(const char* path)
{
    FILE* fd = fopen(path, "r");
    
    unsigned char buffer[1];
    int sum = 0;
    unsigned char last = '\0';
    while (feof(fd) == 0) {
        sum ++;
        size_t size = fread(buffer, 1, 1, fd);
        if (size == 0) return;
//        if (last == 0xff && buffer[0] != 0 &&  buffer[0] != 0xff) {
//            printf("%02x%02x \n",last,buffer[0] );
//        }
        printf("%02x ",buffer[0] );

        last = buffer[0];
        if (sum % 8 == 0) {
            printf(" ");
        }
        if (sum % 96 == 0) {
            printf("\n");
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s\n",argv[0]);
    if (argc == 1) return 0;
    decode_image(argv[1]);
    
    return 0;
}
