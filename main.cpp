/*

Tran Thi Hoa - B18DCPT089 - 01 - 08
Nguyen Thi Quynh Anh - B18DCPT012 - 02 - 03
To Thi Thuong - B18DCPT232 - 02 - 36

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include<mmsystem.h>
#include <fstream>
#include <windows.h>
#include <cmath>
using namespace std;


typedef struct header_file
{
    char chunk_id[4];
    int kich_thuoc;
    char format[4];
    char subchunk1_id[4];
    int somau1;
    short int audio_format;
    short int num_channels;
    int tanso;
    int byte_rate;
    char subchunk2_id[4];
    int somau2;
} header;

typedef struct header_file* header_p;

long double x[100], x1[100], x2[100];
int i, j, sizex, b ;

void printData(long double x[], int sizex)
{
    for (i = 0; i < sizex; i++)
    {
        if (i == 5) cout << "vect{" << x[i] << "}; ";
        else if (i == sizex - 1) cout << x[i] << "}";
        else cout << x[i] << "; ";
    }
    cout << endl;
}
void ReadData(string filename)
{
    i = 0;
    ifstream infile;
    infile.open(filename, ios::in);

    while (!infile.eof())
    {
        infile >> x[i];
        i++;
        if (i == 10) break;
    }
    sizex = i;

    cout << "\nDay tin hieu goc x(n) ={";
    printData(x, sizex);
    infile.close();
}

void tonghaitinhieu()
{

    ReadData("cachmang1.txt");
    for (i = 0; i < sizex; i++) x1[i] = x[i];
    ReadData("cachmang2.txt");
    for (i = 0; i < sizex; i++) x2[i] = x[i];
    for (i = 0; i < sizex; i++) x[i] = x1[i] + x2[i];
    cout << "Tong hai day tin hieu res(n)={";
    printData(x, sizex);

}
void nhanhaitinhieu()
{

    ReadData("cachmang1.txt");
    for (i = 0; i < sizex; i++) x1[i] = x[i];
    ReadData("cachmang2.txt");
    for (i = 0; i < sizex; i++) x2[i] = x[i];
    for (i = 0; i < sizex; i++) x[i] = x1[i] * x2[i];
    cout << "Tich hai day tin hieu res(n)={";
    printData(x, sizex);

}
void ung_dung()
{

    cout << " Doan nhac 1 : " << endl;
    PlaySound("cachmang1.wav", NULL, SND_SYNC);
    cout << " Doan nhac 2 : " << endl;
    PlaySound("cachmang2.wav", NULL, SND_SYNC);
    FILE * infile = fopen("cachmang1.wav","rb");
    FILE * infile2 = fopen("cachmang2.wav","rb");
    FILE * outfile = fopen("output.wav","wb");

    int BUFSIZE = 512;
    short int buff16[BUFSIZE];
    header_p meta = (header_p)malloc(sizeof(header));
    int nb, nb1, nb2;
    int count = 0;
    if (infile2)
    {
        fread(meta, 1, sizeof(header), infile);
        fwrite(meta,1, sizeof(*meta), outfile);
        cout << " Kich thuoc doan 1 :  "<<sizeof(*meta)<<" bytes" << endl;
        cout << " Tan so dau vao doan 1: "<< meta->tanso <<" Hz" << endl;
        cout << " So mau doan 1: " << meta->somau1 << " mau " << endl;

        while (!feof(infile2))
        {
            nb1 = fread(buff16,1,BUFSIZE,infile);
            nb2 = fread(buff16,1,BUFSIZE,infile2);
            nb = 0.5*(nb1 + nb2);

            count++;


            fwrite(buff16,1,nb,outfile);
        }

        cout << " So frames trong file dau ra :  " <<count << endl;
        cout << "DONE - De nghe doan am thanh da thay doi , vui long vao folder luu Project nay" << endl;
        PlaySound("output.wav", NULL, SND_SYNC);
    }

}
void nen()
{
    int check, ok, a;

    do
    {
        cout << "1. Doan 1" << endl;
        cout << "2. Doan 2" << endl;
        cout << "3. Quay lai" << endl;
        cout << "Chon mot doan nhac: ";
        cin >> check;
        if (check == 3) ok = 3;
        while (check > 0 && check < 3)
        {
            switch (check)
            {
            case 1:
            {
                cout << "Nhap he so nen: ";
                cin >> a;
                ReadData("cachmang1.txt");
                j = 0;
                for (int i = 5; i >= 0; i=i-a)
                {
                    if (i - a  >=0) x1[j] = x[i - a ];
                    else break;
                    j++;
                }
                for (int i = 5; i < sizex; i = i+a)
                {
                    x1[j] = x[i];
                    j++;
                }
                cout << "x(" << a << "n)= {";
                for (i = 0; i < j; i++)
                {
                    if (x1[i] == x[5]) cout << "vect{" << x1[i] << "}; ";
                    else if (i == j - 1) cout << x1[i] << "}";
                    else cout << x1[i] << "; ";
                }
                cout << endl;
            }
            break;
            case 2:
            {
                cout << "Nhap he so nen: ";
                cin >> a;
                ReadData("cachmang2.txt");
                j = 0;
                for (int i = 5; i >= 0; i = i - a )
                {
                    if (i - a  >= 0) x1[j] = x[i - a];
                    else break;
                    j++;
                }
                for (int i = 5; i < sizex; i = i + a )
                {
                    x1[j] = x[i];
                    j++;
                }
                cout << "x(" << a << "n)= {";
                for (i = 0; i < j; i++)
                {
                    if (x1[i] == x[5]) cout << "vect{" << x1[i] << "}; ";
                    else if (i == j - 1) cout << x1[i] << "}";
                    else cout << x1[i] << "; ";
                }
                cout << endl;
            }
            break;
            }
            check = 0;
            ok = 0;
        }
    }
    while (ok != 3);
}
int main()

{
    int choice, ok;
    do
    {
        cout << "========= CAC THAO TAC AM THANH =========" << endl;
        cout << "1. Cong hai tin hieu" << endl;
        cout << "2. Nhan hai tin hieu" << endl;
        cout << "3. Nen tin hieu " << endl;
        cout << "4. Ung dung tron am thanh" << endl;
        cout << "5. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";

        cin >> choice;
        if (choice == 5) ok = 5;
        while (choice > 0 && choice < 5)
        {
            switch (choice)
            {
            case 1:
                tonghaitinhieu();
                break;

            case 2:
            {
                nhanhaitinhieu();
                break;
            }
            case 3:
            {

                nen();
                break;
            }
            case 4 :
            {
                ung_dung();
                break;

            }

            }
            choice = 0;
            ok = 0;
        }
    }
    while (ok != 5);



}
