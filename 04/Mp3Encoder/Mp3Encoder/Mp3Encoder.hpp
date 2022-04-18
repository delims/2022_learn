//
//  Mp3Encoder.hpp
//  Mp3Encoder
//
//  Created by delims on 2022/4/11.
//

#ifndef Mp3Encoder_hpp
#define Mp3Encoder_hpp

#include <stdio.h>
#include "lame.h"

class Mp3Encoder {
private:
    FILE* pcmFile;
    FILE* mp3File;
    lame_t lameClient;
public:
    int init(const char* pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate);
    void encode();
    void destory();
};


#endif /* Mp3Encoder_hpp */
