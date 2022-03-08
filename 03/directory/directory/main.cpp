//
//  main.cpp
//  directory
//
//  Created by delims on 2022/3/8.
//

#include <iostream>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    printf("%s\n",argv[0]);
    
    char buffer[strlen(argv[0])];
    memcpy(buffer, argv[0], sizeof(buffer));
    size_t n = sizeof(buffer)-1;
    while (buffer[n] != '/') {
        n--;
    }
    buffer[n] = '\0';
    
    printf("%s\n",buffer);
    DIR *dir = opendir(buffer);
//    dirent *info = readdir(dir);


    dirent *info = NULL;
    while ((info = readdir(dir)) != NULL) {
//        printf("%d\n",info->d_ino);
        printf("%s  %d  %s \n",info->d_name,info->d_type,info->d_name);
//        printf("%d\n",telldir(dir));

//        sprintf("", const char *, ...)
        stat st;
//        S_ISDIR(<#m#>)
//        stat(const char *, struct stat *)
//        printf("%d\n",info->d_type);

    }
    
    return 0;
}
