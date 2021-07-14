#include "menu.h"

void openning()
{
    cout<<"========================================="<<endl;
    cout<<"==            DATA PERFILMAN           =="<<endl;
    cout<<"==                                     =="<<endl;
    cout<<"==                 BY                  =="<<endl;
    cout<<"==                                     =="<<endl;
    cout<<"==  Rendhi Arya Wiryawan (1301174097)  =="<<endl;
    cout<<"==              IF-42-GAB              =="<<endl;
    cout<<"==          Telkom University          =="<<endl;
    cout<<"==                                     =="<<endl;
    cout<<"========================================="<<endl;
    cout<<"==------------PRESS ANY KEY------------=="<<endl;
    cout<<"========================================="<<endl;
    cout<<endl;
}

void closing(){
    system("cls");
    cout<<"======================================="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"==           TERIMA KASIH            =="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"======================================="<<endl;


}

void menuUtama()
{
    listC L;
    listP K;
    listR M;

    create_listC(L);
    create_listP(K);
    create_listR(M);

    addressP P,Q,R,S;
    infotypeP a,b,c,d;

    a.kodeFilm = 11;
    a.namaFilm = "Captain Marvel";
    a.durasi = "124 menit";
    a.tahun = 2019;
    P = alokasiP(a);
    insert_lastP(K, P);

    b.kodeFilm = 111;
    b.namaFilm = "Avengers: Endgame";
    b.durasi = "181 menit";
    b.tahun = 2019;
    Q = alokasiP(b);
    insert_lastP(K, Q);

    c.kodeFilm = 22;
    c.namaFilm = "The Flash";
    c.durasi = "123 menit";
    c.tahun = 2017;
    R = alokasiP(c);
    insert_lastP(K, R);

    d.kodeFilm = 222;
    d.namaFilm = "Spider-Man: Homecoming";
    d.durasi = "133 menit";
    d.tahun = 2017;
    S = alokasiP(d);
    insert_afterP(K, Q, S);

    addressC A,B,C,D,E;
    infotypeC p,q,r,s,t;

    p.idAktor = 8;
    p.namaAktor = "Chris Hemsworth";
    p.jenisKelamin = 'L';
    A = alokasiC(p);
    insertChild(L, A);

    q.idAktor = 88;
    q.namaAktor = "Tom Holland";
    q.jenisKelamin = 'L';
    B = alokasiC(q);
    insertChild(L, B);

    r.idAktor = 888;
    r.namaAktor = "Chris Evans";
    r.jenisKelamin = 'L';
    C = alokasiC(r);
    insertChild(L, C);

    s.idAktor = 9;
    s.namaAktor = "Robert Downey Jr";
    s.jenisKelamin = 'L';
    D = alokasiC(s);
    insertChild(L, D);

    t.idAktor = 99;
    t.namaAktor = "Erza Miller";
    t.jenisKelamin = 'L';
    E = alokasiC(t);
    insertChild(L, E);

    int pil1;
    do
    {
        system("cls");
        cout<<"============================================"<<endl;
        cout<<"==               DAFTAR MENU              =="<<endl;
        cout<<"==      APLIKASI FILM DAN PEMAIN FILM     =="<<endl;
        cout<<"============================================"<<endl;
        cout<<"== 1. Menu Film                           =="<<endl;
        cout<<"== 2. Menu Pemain                         =="<<endl;
        cout<<"== 3. Menu Relasi                         =="<<endl;
        cout<<"==                                        =="<<endl;
        cout<<"== 0.Keluar                               =="<<endl;
        cout<<"============================================"<<endl;
        cout<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pil1;
        switch(pil1)
        {
        case 1 :
        {
            menuFilm(M, K, L);
            getch();
            break;
        }
        case 2 :
        {
            menuPemain(M, K, L);
            getch();
            break;
        }
        case 3 :
        {
            menuRelasi(M, K, L);
            break;
        }
        case 0 :
        {
            closing();
        }
        }
    }
    while (pil1 != 0);
}

void menuFilm(listR &R, listP &P, listC &C)
{
    int pil2;

    system("cls");

    cout<<"======================================="<<endl;
    cout<<"==    SELAMAT DATANG DI MENU FILM    =="<<endl;
    cout<<"======================================="<<endl;
    cout<<"== 1. Tambah Film                    =="<<endl;
    cout<<"== 2. Lihat Daftar Film              =="<<endl;
    cout<<"== 3. Edit Data Film                 =="<<endl;
    cout<<"== 4. Cari Film                      =="<<endl;
    cout<<"== 5. Hapus Film                     =="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"== 0.Kembali                         =="<<endl;
    cout<<"======================================="<<endl;
    cout<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pil2;

    if (pil2 == 1)
    {
        insertParentSort(P);
        getch();
        menuFilm(R, P, C);
    }
    else if (pil2 == 2)
    {
        print_infoP(P);
        getch();
        menuFilm(R, P, C);
    }
    else if (pil2 == 3)
    {
        editParent(P);
        getch();
        menuFilm(R, P, C);
    }
    else if (pil2 == 4)
    {
        menuCari(P);
        getch();
        menuFilm(R, P, C);
    }
    else if (pil2 == 5)
    {
        deleteParentR(R, P , C);
        //hapusFilm(P);
        getch();
        menuFilm(R, P, C);
    }
}

void menuPemain(listR &R, listP &P, listC &C)
{
    int pil3;

    system("cls");

    cout<<"================================================"<<endl;
    cout<<"==     SELAMAT DATANG DI MENU PEMAIN FILM     =="<<endl;
    cout<<"================================================"<<endl;
    cout<<"== 1. Tambah Pemain                           =="<<endl;
    cout<<"== 2. Lihat Daftar Pemain                     =="<<endl;
    cout<<"== 3. Edit Data Pemain                        =="<<endl;
    cout<<"== 4. Cari Pemain                             =="<<endl;
    cout<<"== 5. Hapus Pemain                            =="<<endl;
    cout<<"==                                            =="<<endl;
    cout<<"== 0.Kembali                                  =="<<endl;
    cout<<"================================================"<<endl;
    cout<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pil3;

    if (pil3 == 1)
    {
        insertChildFirst(C);
        getch();
        menuPemain(R, P, C);
    }
    else if (pil3 == 2)
    {
        viewChild(C);
        getch();
        menuPemain(R, P, C);
    }
    else if (pil3 == 3)
    {
        menuEditChild(C);
        getch();
        menuPemain(R, P, C);
    }
    else if (pil3 == 4)
    {
        cariChild(C);
        getch();
        menuPemain(R, P, C);
    }
    else if (pil3 == 5)
    {
        //delteteChildR(R, P, C);
        //menuDeleteChild(C);
        getch();
        menuPemain(R, P, C);
    }
}

void menuRelasi(listR &R, listP &P, listC &C)
{
    int pil4;

    system("cls");

    cout<<"======================================="<<endl;
    cout<<"==   SELAMAT DATANG DI MENU RELASI   =="<<endl;
    cout<<"======================================="<<endl;
    cout<<"== 1. Tambah Relasi                  =="<<endl;
    cout<<"== 2. Lihat Data Film Tertentu       =="<<endl;
    cout<<"== 3. Lihat Data Pemain Tertentu     =="<<endl;
    cout<<"== 4. Data Aktor/Aktris Paling Top   =="<<endl;
    cout<<"== 5. Lihat Data Seluruhnya          =="<<endl;
    cout<<"== 6. Hapus relasi                   =="<<endl;
    cout<<"==                                   =="<<endl;
    cout<<"== 0. Kembali                        =="<<endl;
    cout<<"======================================="<<endl;
    cout<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pil4;

    if (pil4 == 1)
    {
        tambahRelasi(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
    else if (pil4 == 2)
    {
        printPemainR(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
    else if (pil4 == 3)
    {
        printFilmR(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
    else if (pil4 == 4)
    {
        pemainTop(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
    else if (pil4 == 5)
    {
        system("cls");
        goPrint(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
    else if (pil4 == 6)
    {
        deleteRelasi(R, P, C);
        getch();
        menuRelasi(R, P, C);
    }
}
