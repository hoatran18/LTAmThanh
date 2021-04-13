/*

Tran Thi Hoa - B18DCPT089 - 01 - 08
Nguyen Thi Quynh Anh - B18DCPT012 - 02 - 03
To Thi Thuong - B18DCPT232 - 02 - 36

*/
#ifndef TINHIEU_H
#define TINHIEU_H
#include<string>

class tinHieu
{
private :
    int kich_thuoc;
    int Fs;
    int vi_tri;
    long double gia_tri[100];
    long double gia_tri1[100];
    long double gia_tri2[100];

public:
    tinHieu();
    ~tinHieu();

    void dichthoigian();
    void daothoigian();
    void tonghaitinhieu();
    void nhanhaitinhieu();
    void nhanvoihangso();
    void nentinhieu();
    void tangtanso();
};

#endif // TINHIEU_H
