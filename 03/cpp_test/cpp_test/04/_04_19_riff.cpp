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
    
//    const char *wav = "/Users/delims/Documents/iPhone13/1641999079563.jpg";
    const char *wav = "/Users/delims/Documents/pcm/浪花一朵朵片段8k16bit单声道.wav";
    
    int fd = open(wav, O_RDONLY);
    if (fd < 0) {
        printf("%s\n",strerror(errno));
        return ;
    }
//    printf("%d\n",fd);
    chunk ck;
    read(fd, &ck, sizeof(ck));
    
    printf("id   = ");
    print_int_to_string(ck.flag);
    printf("size = ");
    print_u_int(ck.size);
    
    
    unsigned int format;
    printf("fmt  = ");

    read(fd, &format, sizeof(format));
    print_int_to_string(format);
    
    println();
//    printf("%d\n",ck_s1.size);

    fmt_chunk fmt;
    read(fd, &fmt, sizeof(fmt_chunk));
    
    printf("id   = ");
    print_int_to_string(fmt.id);
    printf("size = ");
    print_u_int(fmt.size);
    printf("%d == %ld \n",fmt.size,sizeof(fmt_chunk));
    printf("audio format: %d\n",fmt.audio_format);
    printf("num_channels: %d\n",fmt.num_channels);
    printf("sample_rate : %d\n",fmt.sample_rate);
    printf("byte_rate   : %d\n",fmt.byte_rate);
    printf("block_align : %d\n",fmt.block_align);//对齐
    printf("bits_per_sam: %d\n",fmt.bits_per_sample);

//    lseek(fd, fmt.size, SEEK_CUR);
    
    println();
    chunk fact_chunk;
    read(fd, &fact_chunk, sizeof(chunk));
    printf("id   = ");
    print_int_to_string(fact_chunk.flag);
    printf("size = ");
    print_u_int(fact_chunk.size);
    
    unsigned int fact_data;
    read(fd, &fact_data, sizeof(fact_data));
    printf("fact data = ");
    print_u_int(fact_data); //采样总数
    
    println();
    chunk data_chunk;
    read(fd, &data_chunk, sizeof(chunk));
    printf("id   = ");
    print_int_to_string(data_chunk.flag);
    printf("size = ");
    print_u_int(data_chunk.size);
    
    close(fd);
}
