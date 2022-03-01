#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>

using namespace std;

#define MAX_PATH_LEN (256)

static void trave_dir(char* path , vector<string> &files) {
    DIR *d = nullptr;
    struct dirent *dp = nullptr; /* readdir函数的返回值就存放在这个结构体中 */
    struct stat st;
    char p[MAX_PATH_LEN] = {0};

    if(stat(path, &st) < 0 || !S_ISDIR(st.st_mode)) {
        printf("invalid path: %s\n", path);
        return;
    }

    if(!(d = opendir(path))) {
        printf("opendir[%s] error: %m\n", path);
        return;
    }

    while((dp = readdir(d)) != nullptr) {
        /* 把当前目录.，上一级目录..及隐藏文件都去掉，避免死循环遍历目录 */
        if((!strncmp(dp->d_name, ".", 1)) || (!strncmp(dp->d_name, "..", 2)))
            continue;

        snprintf(p, sizeof(p) - 1, "%s/%s", path, dp->d_name);
        stat(p, &st);
        string dir = path;
         
        if(!S_ISDIR(st.st_mode)) {
//            printf("%s\n", dp->d_name);
            
            files.push_back(dir + "" + dp->d_name);
        } else {
//            printf("%s/\n", dp->d_name);
//            trave_dir(p);
        }
    }
    closedir(d);

    return;
}

int main(int argc, char **argv)
{
    char *path = nullptr;

    if (argc != 2) {
        printf("Usage: %s [dir]\n", argv[0]);
        printf("use DEFAULT option: %s .\n", argv[0]);
        printf("-------------------------------------------\n");
        path = "./";
    } else {
        path = argv[1];
    }
    vector<string> files;
    trave_dir(path,files);
    for (int i = 0; i < files.size(); i ++) {
        printf("== %s \n",files[i].c_str());
    }

    return 0;
}
