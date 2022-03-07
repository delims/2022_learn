//
//  main.cpp
//  can_receive
//
//  Created by delims on 2022/3/6.
//

#include <iostream>
#include <vector>

#define CANID_altitude 0x01
#define CANID_longitude 0x02
#define CANID_latitude 0x03
#define CANID_speed 0x04

enum flag_t {
    flag_latitude   = 1 << 0,
    flag_longitude  = 1 << 1,
    flag_altitude   = 1 << 2,
    flag_speed      = 1 << 3,
    flag_all        = 0xf,
};

struct gnss_t {
    double latitude;
    double longitude;
    float altitude;
    float direction;
    float speed;
    short seq;
    unsigned char mode;
    unsigned char flags;
    
    struct mode_seq_t {
        unsigned char mode;
        unsigned char seq;
    };
    struct coordinate {
        mode_seq_t    mode_seq;
        short         integer;
        unsigned int  decimal;
        void operator=(const char* data) {
            memcpy(this, data, sizeof(*this));
        }
        coordinate(const char* data) {
            memcpy(this, data, sizeof(*this));
        }
        double value() {
            return integer + decimal * 0.00000001;
        }
        
    };
    struct direction_speed {
        mode_seq_t    mode_seq;
        short         direction;
        short         speed;
        unsigned char status;
        unsigned char reserve;
        direction_speed operator=(const char* data) {
            memcpy(this, data, sizeof(*this));
            return *this;
        }
        direction_speed(const char* data) {
            memcpy(this, data, sizeof(*this));
        }
    };
    struct altitude_t {
        mode_seq_t    mode_seq;
        short         integer;
        unsigned int  decimal;
        altitude_t(const char* data) {
            memcpy(this, data, sizeof(*this));
        }
    };
    bool complete() {return (mode & flag_all) == flag_all;}
    void clear() {flags = 0;}
    void update_latitude (const char* data) {
        coordinate lati = data;
        mode = lati.mode_seq.mode;
        latitude = lati.value();
        flags |= flag_latitude;
    }
    void update_longitude (const char* data) {
        coordinate lng = data;
        longitude = lng.value();
        mode = lng.mode_seq.mode;
        flags |= flag_longitude;
    }
    void update_speed (const char* data) {
        direction_speed ds = data;
        speed = ds.speed;
        direction = ds.direction;
        mode = ds.mode_seq.mode;
        flags |= flag_speed;
    }
    void update_altitude (const char* data) {
        altitude_t altitude = data;
        mode = altitude.mode_seq.mode;
        flags |= flag_altitude;
    }
};

struct gnss_receive_data {
#define seq_mask 0x7
    gnss_t receive_data[8];
    gnss_t current_gnss;
    void accept(const char *data,unsigned int canid) {
        unsigned int seq = *(data+1) & seq_mask;
        gnss_t &gnss = receive_data[seq];
        switch (canid) {
            case CANID_latitude:
                gnss.update_latitude(data);break;
            case CANID_longitude:
                gnss.update_longitude(data);break;
            case CANID_altitude:
                gnss.update_altitude(data);break;
            case CANID_speed:
                gnss.update_speed(data);break;
        }
        if (gnss.complete()) {
            memcpy(&current_gnss, &gnss, sizeof(gnss));
            gnss.clear();
        }
    }
    gnss_receive_data() {
        memset(this, 0, sizeof(*this));
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
