//
//  _04_19_riff.cpp
//  cpp_test
//
//  Created by delims on 2022/4/19.
//

#include <stdio.h>
#include "../class.h"

struct chunk {
    unsigned int flag;
    unsigned int size;
    unsigned int data[0];
};

struct fmt_chunk {
    unsigned int id;
    unsigned int size;
    unsigned short audio_format;
    unsigned short num_channels;
    unsigned int sample_rate;
    unsigned int byte_rate;
    unsigned short block_align;
    unsigned short bits_per_sample;
};


void _04_19_riff() {
    
    const char *wav = "/Users/delims/Downloads/pcm/浪花一朵朵片段8k16bit单声道.wav";
    int fd = open(wav, O_RDONLY);
    if (fd < 0) {
        printf("%s\n",strerror(errno));
        return ;
    }
    printf("%d\n",fd);
    
    chunk ck;
    read(fd, &ck, sizeof(ck));
    
    printf("%s\n",(const char* )&ck.flag);
    printf("%d\n",ck.size);
    
    unsigned int format;
    read(fd, &format, sizeof(format));
    printf("%s\n",(const char* )&format);
//    printf("%d\n",ck_s1.size);

    fmt_chunk fmt;
    read(fd, &fmt, sizeof(fmt_chunk));
    
    printf("%s\n",(const char* )&fmt.id);
    printf("%d == %ld \n",fmt.size,sizeof(fmt_chunk));

    
    close(fd);
}
