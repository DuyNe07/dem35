#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int nguoiDanh(int N, int buoc_may_cu);
int ranDom(int buoc_cu);
int bangBuocDi(int N, int buoc_nguoi_cu);
bool kiemTraVaKetThuc(int N, int x);
void troChoiBatDau(int &N, int buoc_nguoi, int buoc_may);
int mayDanh(int N, int buoc_nguoi_cu);

// int mayDanh(int N, int &buoc_may, int buoc_nguoi_cu, )

int main()
{
    int N(0);
    int buoc_nguoi(0), buoc_may(0);
    troChoiBatDau(N, buoc_nguoi, buoc_may);
    system("pause");
    return 0;
}

void troChoiBatDau(int &N, int buoc_nguoi, int buoc_may)
{
    char a;
    cout << "Ban muon danh truoc nhap phim 1: ";
    cin >> a;
    if (a == '1')
    {
        buoc_nguoi = nguoiDanh(N, 0);
        N += buoc_nguoi;
    }
    do
    {
        buoc_may = mayDanh(N, buoc_nguoi);
        N += buoc_may;
        if (kiemTraVaKetThuc(N, 1) == true)
        {
            break;
        };
        buoc_nguoi = nguoiDanh(N, buoc_may);
        N += buoc_nguoi;
        if (kiemTraVaKetThuc(N, 0) == true)
        {
            break;
        };
    } while (true);

    cout << "Tro choi da ket thuc\nCam on ban da tham gia" << endl;
}

bool kiemTraVaKetThuc(int N, int x)
{
    if (N > 35)
    {
        cout << "Tro choi ket thuc !!!";
        if (x == 1)
        {
            cout << "Nguoi thang ~~~\nMay thua : (" << endl;
            return true;
        }
        else
        {
            cout << "Nguoi thua ~~~\nMay thang : )" << endl;
            return true;
        }
    }
    else
        return false;
}

int bangBuocDi(int N, int buoc_nguoi_cu)
{
    if (N == 0)
    {
        return ranDom(0);
    }
    switch (N)
    {
    case (34 || 21 || 8):
        if (buoc_nguoi_cu != 1)
        {
            return 1;
        }
        else
        {
            return ranDom(buoc_nguoi_cu);
            break;
        }
    case 33:
        if (buoc_nguoi_cu != 1)
        {
            return 1;
            break;
        }
        else
        {
            return 2;
            break;
        }
    case 26:
        if (buoc_nguoi_cu != 2)
        {
            return 2;
        }
        else
        {
            return ranDom(buoc_nguoi_cu);
            break;
        }
    case 20:
        if (buoc_nguoi_cu != 1)
        {
            return 1;
            break;
        }
        else
        {
            return 2;
            break;
        }
    case 7:
        if (buoc_nguoi_cu != 2)
        {
            return 2;
            break;
        }
        else
        {
            return 4;
            break;
        }
    }
    if (N == 32 || N == 19 || N == 6 || N == 3 || N == 29 || N == 16)
    {q
        if (buoc_nguoi_cu != 3)
        {
            return 3;
        }
        else
            return ranDom(buoc_nguoi_cu);
    }
    else if (N == 31 || N == 24 || N == 11)
    {
        if (buoc_nguoi_cu != 4)
        {
            return 4;
        }
        else
            return ranDom(buoc_nguoi_cu);
    }
    else if (N == 30 || N == 23 || N == 17 || N == 10 || N == 4)
    {
        if (buoc_nguoi_cu != 5)
        {
            return 5;
        }
        else
            return ranDom(buoc_nguoi_cu);
    }
    else if (N == 0 || N == 13)
    {
        if (buoc_nguoi_cu != 1)
        {
            return 1;
        }
        else
            return 2;
    }
    else if (N == 27 || N == 14)
    {
        if (buoc_nguoi_cu != 1)
        {
            return 1;
        }
        else
            return 4;
    }
    else if (N == 25 || N == 12)
    {
        if (buoc_nguoi_cu != 3)
        {
            return 3;
        }
        else
            return 5;
    }
    else /*if (N == (18 || 5))*/
    {
        if (buoc_nguoi_cu != 5)
        {
            return 5;
        }
        else
            return 4;
    }
}

int mayDanh(int N, int buoc_nguoi_cu)
{
    int buocdi = bangBuocDi(N, buoc_nguoi_cu);
    cout << "May chon buoc di la: " << buocdi << endl;
    cout << "Gia tri N luc nay la: " << N + buocdi << endl;
    return buocdi;
}

int ranDom(int buoc_cu)
{
    srand((unsigned int)time(NULL));
    int ketqua(0);
    do
    {
        ketqua = 1 + (int)(rand() * (5 - 1 + 1.0) / (1.0 + RAND_MAX));
    } while (ketqua == buoc_cu);
    return ketqua;
}

int nguoiDanh(int N, int buoc_may_cu)
{
    char buoc_nguoi;
    if (N == 0)
    {
        do
        {
            cout << "Moi ban danh truoc: ";
            cin >> buoc_nguoi;

        } while (buoc_nguoi < '0' || buoc_nguoi > '5');
    }
    else
    {
        do
        {
            cout << "Den luot cua ban: \nHay danh khac so " << buoc_may_cu << ": ";
            cin >> buoc_nguoi;
        } while (buoc_nguoi < '0' || buoc_nguoi > '5' || (int)(buoc_nguoi - '0') == buoc_may_cu);
    }
    cout << "Ban chon buoc di la: " << (int)(buoc_nguoi - '0') << endl;
    cout << "Gia tri N luc nay la: " << (N + (int)(buoc_nguoi - '0')) << endl;
    return (int)(buoc_nguoi - '0');
}


