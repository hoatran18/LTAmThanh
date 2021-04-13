#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED
/*

Tran Thi Hoa - B18DCPT089 - 01 - 08
Nguyen Thi Quynh Anh - B18DCPT012 - 02 - 03
To Thi Thuong - B18DCPT232 - 02 - 36

*/
class Signal
{
private:
    int Fs;
    int so_mau;
    int[] tin_hieu;
    int vi_tri;
public :
    void cong_2_tin_hieu(int[] y, int n)
    {
        sigadd(x1,n1,x2,n2);
        n = min(min(n1), min(n2)) : max(max(n1), max(n2));
        y1 = zeros(1,length(n));
        y2=y1;
        y1(find(n>=min(n1))) && (n<= max(n1)) == 1) = x1 ;
        y2(find(n>=min(n2))) && (n<= max(n2)) == 1) = x2 ;
        y= y1+y2;

    }
    void nhan_2_tin_hieu(int[] y, int n)
    {
        sigmult(x1,n1,x2,n2);
        n = min(min(n1), min(n2)) : max(max(n1), max(n2));
        y1 = zeros(1,length(n));
        y2=y1;
        y1(find(n>=min(n1))) && (n<= max(n1)) == 1) = x1 ;
        y2(find(n>=min(n2))) && (n<= max(n2)) == 1) = x2 ;
        y= y1*y2;

    }
    void dich_tin_hieu(int[] y, int n)
    {
        sigshift(x,m,n0);
        n = m+n0;
        y=x;
    }
    void gap_tin_hieu(int[] y, int n)
    {
        sigfold(x,n);
        y=fliplr(x);
        n=-fliplr(n);

    }
};

#endif // SIGNAL_H_INCLUDED
