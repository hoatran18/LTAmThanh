#ifndef TINHIEU_H_INCLUDED
#define TINHIEU_H_INCLUDED
/*

Tran Thi Hoa - B18DCPT089 - 01 - 08
Nguyen Thi Quynh Anh - B18DCPT012 - 02 - 03
To Thi Thuong - B18DCPT232 - 02- 36

*/

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

    void  printData(tinHieu.gia_tri[100], tinHieu.kich_thuoc);
    {
        for (i = 0; i < tinHieu.kich_thuoc; i++)
        {
            if (i == 3) cout << "vect{" << tinHieu.gia_tri[i] << "}; ";
            else if (i == tinHieu.kich_thuoc - 1) cout << tinHieu.gia_tri[i] << "}";
            else cout << tinHieu.gia_tri[i] << "; ";
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
            infile >> tinHieu.gia_tri[i];
            i++;
            if (i == 10) break;
        }
        tinHieu.kich_thuoc = i;

        cout << "\nDay tin hieu goc x(n) ={";
        printData(tinHieu.gia_tri, tinHieu.kich_thuoc);
        infile.close();
    }


    void dichthoigian(int b)
    {
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri1[i] = 0;
        if (b > 0)
        {
            cout << "Tin hieu bi tre" << endl;
            for ( i=0; i< tinHieu.kich_thuoc; i++)
            {
                if (i + b < tinHieu.kich_thuoc) tinHieu.gia_tri1[i + b ] = tinHieu.gia_tri[i];
            }
        }
        else
        {
            cout << "Tin hieu bi som" << endl;
            for (i = 0; i < tinHieu.kich_thuoc; i++)
                if (i + b >= 0) tinHieu.gia_tri1[i + b ] = tinHieu.gia_tri[i];
        }
        if (b > 0) cout << "\nx(n-" << b << ")={";
        else  cout << "\nx(n+" << b << ")={";
        printData(tinHieu.gia_tri1, tinHieu.kich_thuoc);
    }

    void daothoigian()
    {
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri1[i] = 0;
        i = 0;
        j = tinHieu.gia_tri - 1;
        while (j > 3)
        {
            tinHieu.gia_tri1[i] = tinHieu.gia_tri[j];
            i++;
            j--;
        }
        tinHieu.gia_tri1[i] = tinHieu.gia_tri[3];
        i++;
        j = 0;
        while (j < 3)
        {
            tinHieu.gia_tri1[i] = tinHieu.gia_tri[j];
            j++;
            i++;
        }
        cout << "x(-n)={";
        for (i = 0; i < tinHieu.kich_thuoc; i++)
        {
            if (i == tinHieu.kich_thuoc - 1- 3) cout << "vect{" << tinHieu.gia_tri1[i] << "}; ";
            else if (i == tinHieu.kich_thuoc- 1) cout << tinHieu.gia_tri1[i] << "}";
            else cout << tinHieu.gia_tri1[i] << "; ";
        }
        cout << endl;
    }

    void tonghaitinhieu()
    {

        ReadData("cachmang1.txt");
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri1[i] = tinHieu.gia_tri[i];
        ReadData("cachmang2.txt");
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri2[i] = tinHieu.gia_tri[i];;
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri[i] = tinHieu.gia_tri1[i] + tinHieu.gia_tri2[i];
        cout << "Tong hai day tin hieu res(n)={";
        printData(tinHieu.gia_tri, tinHieu.kich_thuoc);

    }
    void nhanhaitinhieu()
    {

        ReadData("cachmang1.txt");
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri1[i] = tinHieu.gia_tri[i];
        ReadData("cachmang2.txt");
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri2[i] = tinHieu.gia_tri[i];;
        for (i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri[i] = tinHieu.gia_tri1[i] * tinHieu.gia_tri2[i];
        cout << "Tich hai day tin hieu res(n)={";
        printData(tinHieu.gia_tri, tinHieu.kich_thuoc);

    }
    void nhanvoihangso(int b)
    {
        ReadData("cachmang1.txt");
        for (int i = 0; i < tinHieu.kich_thuoc; i++) tinHieu.gia_tri1[i] = tinHieu.gia_tri[i] * b;
        printData(tinHieu.gia_tri1, tinHieu.kich_thuoc);
    }
    void nentinhieu(int b)
    {


        ReadData("cahmang1.txt");
        j = 0;
        for (int i = 3; i >= 0; i=i-b)
        {
            if (i - b  >=0)   tinHieu.gia_tri1[j] = tinHieu.gia_tri[i-b];
            else break;
            j++;
        }
        for (int i = 3; i < tinHieu.kich_thuoc; i = i+b)
        {
            tinHieu.gia_tri1[j] = tinHieu.gia_tri[i];
            j++;
        }
        cout << "x(" << b << "n)= {";
        for (i = 0; i < j; i++)
        {
            if (tinHieu.gia_tri1[i] = tinHieu.gia_tri[3]) cout << "vect{" << tinHieu.gia_tri1[i] << "}; ";
            else if (i == j - 1) cout << tinHieu.gia_tri1[i] << "}";
            else cout << tinHieu.gia_tri1[i] << "; ";
        }
        cout << endl;
    }
    void tangtanso(int b)
    {

        ReadData("cachmang1.txt");
        i = 0;
        j = 0;
        while (i < tinHieu.kich_thuoc)
        {
           tinHieu.gia_tri1[j] = tinHieu.gia_tri[i];
            i++;
            j++;
            if (i!=tinHieu.kich_thuoc)
                for (int k = 1; k < b; k++)
                {
                    tinHieu.gia_tri1[j] = 0;
                    j++;
                }
        }
        cout << "x" << b << "(n)= {";
        for (i = 0; i < j; i++)
        {
            if (tinHieu.gia_tri1[i] = tinHieu.gia_tri[3]) cout << "vect{" << tinHieu.gia_tri1[i] << "}; ";
            else if (i == j - 1) cout << tinHieu.gia_tri1[i] << "}";
            else cout << tinHieu.gia_tri1[i] << "; ";
        }
        cout << endl;

    }
};


#endif // TINHIEU_H_INCLUDED
