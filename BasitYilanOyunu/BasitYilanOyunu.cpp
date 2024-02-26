#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int main() {
    cout << " *YILAN OYUNUNA HOSGELDINIZ*" << endl;
    cout << "Baslamak icin W,A,S,D tuslarini kullanin"<< endl;
    int satir = 1, sutun = 1;
    int s_yem = 1, d_yem = 1;
    int yem_sayaci = 0;
    int onceki_satir = satir, onceki_sutun = sutun;


    char tahta[12][12] = {
        {'-','-','-','-','-','-','-','-','-','-','-','-'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
        {'|','-','-','-','-','-','-','-','-','-','-','|'},
    };

    srand(time(NULL));
    char tus;
    while (true) {


        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                cout << tahta[i][j];
            }
            cout << endl;
        }
        cout << "Yon tusunu girin: ";
        cin >> tus;
        tahta[onceki_satir][onceki_sutun] = '-';
        switch (tus) {

        case 'w':
            if (satir > 0)
                satir--;
            break;
        case 's':
            if (satir < 11)
                satir++;
            break;
        case 'a':
            if (sutun > 0)
                sutun--;
            break;
        case 'd':
            if (sutun < 11)
                sutun++;
            break;
        case 'q':
            cout << "Oyun bitti!" << endl;
            return 0;
        default:
            cout << "Gecersiz tus! WASD tuslarini kullanin." << endl;
            break;
        }
        onceki_satir = satir;
        onceki_sutun = sutun;
        if (satir == s_yem && sutun == d_yem) {
            cout << "Yem yendi!" << endl;
            s_yem = rand() % 12;
            d_yem = rand() % 12;
            tahta[s_yem][d_yem] = '*';
            yem_sayaci++;
            if (yem_sayaci == 15) {
                cout << "Tebrikler oyunu kazandiniz!" << endl;
                return 0;
            }
        }

        tahta[satir][sutun] = '-';
        tahta[satir][sutun] = 'X';
        tahta[s_yem][d_yem] = '*';
        system("cls");
        cout << "W,A,S,D TUSLARINI KULLANINIZ!!" << endl;
        cout << "Oyunu bitirmek icin q tusuna basiniz!" << endl;
        cout << "Oyunu kazanmak icin 15 kere yemi yemeniz gerekli!" << endl;

        cout << "SAYAC: " << yem_sayaci << endl;
    }
    return 0;
}