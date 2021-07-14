#include "child.h"

void create_listC(listC &L)
{
    firstC(L) = NULL;
    lastC(L) = NULL;
}

addressC alokasiC(infotypeC x)
{
    addressC P = new elmlistC;
    x.rate = 0;
    infoC(P) = x;
    nextC(P) = NULL;
    prevC(P) = NULL;
    return P;
}

void insertChild(listC &L, addressC P)
{
    if(firstC(L) != NULL && lastC(L) != NULL)
    {
        nextC(P) = firstC(L);
        prevC(firstC(L)) = P;
        firstC(L) = P;

    }
    else
    {
        firstC(L) = P;
        lastC(L) = P;
    }
}

//void insertlastChild(listC &L, addressC P){
//
//   if(firstC(L) != NULL and lastC(L) != NULL){
//       prevC(P) = lastC(L);
//        next(lastC(L)) = P;
//        lastC(L) = P;
//}
//    else{
//        insertChild(L, P);
//    }
//
//
//}

//void insertafterChild(listC &L, adrressC P, addressC Prec ){
//
//    if(firstC(L) != NULL and lastC(L) != NULL){
//        nextC(P) = nextC(Prec);
//        prevC(P) = Prec;
//        prevC(nextC(Prec)) = P;
//        nextC(Prec) = P;
//
//    }else if( firstC(L) == lastC(L)){
//        insertlastChild(L, P);
//    }else{
//       insertChildFirst()
//    }

//}

void viewChild(listC L)
{
    if(firstC(L) == NULL)
    {
        cout<<"================================================"<<endl;
        cout<<"==          DATA PEMAIN MASIH KOSONG          =="<<endl;
        cout<<"==   SILAHKAN MASUKKAN DATA TERLEBIH DAHULU   =="<<endl;
        cout<<"================================================"<<endl;
    }
    else
    {
        system("cls");
        cout<<"================================================"<<endl;
        cout<<"== Berikut daftar Pemain yang Tersedia :        "<<endl;
        cout<<"==                                              "<<endl;
        addressC P = firstC(L);
        while(P !=NULL)
        {
            cout<<"== ID Pemain     : "<<infoC(P).idAktor<<endl;
            cout<<"== Nama Pemain   : "<<infoC(P).namaAktor<<endl;
            cout<<"== Jenis Kelamin : "<<infoC(P).jenisKelamin<<endl;
            P = nextC(P);
            cout<<"== "<<endl;
        }
        cout<<"========================================================="<<endl;
    }
}


addressC findElmChild(listC L, int x)
{
    addressC P = firstC(L);
    while(P != NULL)
    {
        if(infoC(P).idAktor==x)
        {
            return P;
        }
        P = nextC(P);
    }
    return NULL;
}

addressC findElmNamaAktor(listC L, string y)
{
    addressC P = firstC(L);
    while(P != NULL)
    {
        if(infoC(P).namaAktor == y)
        {
            return P;
        }
        P = nextC(P);
    }
    return NULL;
}

void cariChild (listC L)
{
    system("cls");
    int cari;
    cout<<"============================================="<<endl;
    cout<<"==             MENU CARI PEMAIN            =="<<endl;
    cout<<"============================================="<<endl;
    cout<<"== Silahkan Masukkan ID Pemain : ";
    cin>>cari;
    addressC hasil = findElmChild(L, cari);
    if(hasil == NULL)
    {
        cout<<"Aktor tidak ditemukan. "<<endl;
    }
    else
    {
        cout<<"---------------------------------------------"<<endl;
        cout<<"== BERIKUT DATA AKTOR/ARTIS YANG ANDA CARI =="<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"ID Aktor      : "<<infoC(hasil).idAktor<<endl;
        cout<<"Nama Aktor    : "<<infoC(hasil).namaAktor<<endl;
        cout<<"Jenis Kelamin : "<<infoC(hasil).jenisKelamin<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"============================================="<<endl;
    }

}

void delete_firstC(listC &L, addressC &P)
{
    P = firstC(L);
    if (firstC(L) != lastC(L))
    {
        firstC(L) = nextC(P);
        prevC(P) = NULL;
        nextC(P) = NULL;
    }
    else
    {
        firstC(L) = NULL;
        lastC(L) = NULL;
    }
}

void delete_lastC(listC &L, addressC &P)
{
    P = lastC(L);
    lastC(L) = prevC(P);
    nextC(lastC(L)) = NULL;
    prevC(P) = NULL;
}

void delete_afterC(listC &L, addressC &P)
{
    addressC Q;
    addressC Prec = prevC(P);

    nextC(Prec) = nextC(P);
    prevC(nextC(P)) = Prec;
    nextC(P) = NULL;
    prevC(P) = NULL;
}


void deleteChild(listC &L, addressC P)
{
    if(P != NULL)
    {
        if(P == firstC(L))
        {
            delete_firstC(L, P);
        }
        else if( P == lastC(L))
        {
            delete_lastC(L, P);
        }
        else
        {
            delete_afterC(L, P);
        }
    }
    else
    {
        firstC(L) = NULL;
        lastC(L) = NULL;
    }
}

void insertChildFirst(listC &L)
{
    int a;
    addressC anak;
    cout<<endl;
    cout<<"Masukkan ID Aktor : ";
    cin>>a;
    anak = findElmChild(L,a);

    if (anak != NULL)
    {
        cout<<endl;
        cout<<"Maaf, ID Aktor sudah tersedia."<<endl;
    }
    else
    {
        system("cls");
        aktor b;
        cout<<"======================================="<<endl;
        cout<<"==      SILAHKAN ISI DATA UNTUK      =="<<endl;
        cout<<"==        MENAMBAHKAN PEMAIN         =="<<endl;
        cout<<"======================================="<<endl;
        b.idAktor = a;
        cout<<"== ID Aktor      : "<<b.idAktor<<endl;
        cout<<"== Nama Aktor    : ";
        cin.ignore();
        getline(cin, b.namaAktor);
        cout<<"== Jenis Kelamin : ";
        cin>>b.jenisKelamin;
        addressC P = alokasiC(b);
        cout<<"========================================"<<endl;
        cout<<"==----pemain berhasil di tambahkan----=="<<endl;
        cout<<"========================================"<<endl;
        insertChild(L, P);
    }

}

void menuEditChild(listC &L)
{

    aktor change;
    int idBaru;
    string namaBaru;
    char jenisKelaminBaru;
    addressC temp;
    char choose;

    cout<<"=============================================="<<endl;
    cout<<"==             MENU EDIT PEMAIN             =="<<endl;
    cout<<"=============================================="<<endl;
    cout<<endl;
    cout<<"Masukkan ID Aktor yang ingin di edit = ";
    cin>>change.idAktor;
    temp = findElmChild(L, change.idAktor);
    if(temp == NULL)
    {
        system("cls");
        cout<<"=============================================="<<endl;
        cout<<"==--------Data pemain tidak ditemukan-------=="<<endl;
        cout<<"=============================================="<<endl;
    }
    else
    {
        system("cls");
        cout<<"=============================================="<<endl;
        cout<<"---------------Pemain di Temukan--------------"<<endl;
        cout<<"=============================================="<<endl;
        cout<<"== ID Pemain     : "<<infoC(temp).idAktor<<endl;
        cout<<"== Nama Pemain   : "<<infoC(temp).namaAktor<<endl;
        cout<<"== Jenis Kelamin : "<<infoC(temp).jenisKelamin<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;
        cout<<"Apakah anda yakin ingin mengedit data tersebut ? {Y/N) : ";
        cin>>choose;
        if((choose == 'Y') || (choose == 'y'))
        {
            cout<<endl;
            cout<<"=============================================="<<endl;
            cout<<"==  SILAHKAN MASUKKAN DATA PEMAIN YANG BARU =="<<endl;
            cout<<"=============================================="<<endl;
            cout<<"== ID Pemain Baru : ";
            cin>>idBaru;
            addressC temp2 = findElmChild(L, idBaru);

            if (temp2 == NULL)
            {
                infoC(temp).idAktor = idBaru;
                cout<<"== Nama Pemain Baru : ";
                cin>>namaBaru;
                infoC(temp).namaAktor = namaBaru;
                cout<<"== Jenis Kelamin Baru : ";
                cin>>jenisKelaminBaru;
                infoC(temp).jenisKelamin = jenisKelaminBaru;
                cout<<"=============================================="<<endl;
                cout<<"==-------Data pemain berhasil di edit.------=="<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;

            }
            else
            {
                cout<<"=============================================="<<endl;
                cout<<"==----------Maaf, ID sudah tersedia---------=="<<endl;
                cout<<"=============================================="<<endl;
                getch();
            }
        }
        else
        {
            system("cls");
            cout<<"=============================================="<<endl;
            cout<<"==----Data pemain tidak berhasil di edit.---=="<<endl;
            cout<<"=============================================="<<endl;
        }

    }
}

void menuDeleteChild(listC &L)
{
    aktor hapus;
    addressC temp;
    char choose;
    if (firstC(L) == NULL)
    {
        cout<<endl;
        cout<<" List pemain masih kosong, silahkan input terlebih dahulu. "<<endl;
    }
    else
    {
        system("cls");
        cout<<"=============================================="<<endl;
        cout<<"==             MENU HAPUS PEMAIN            =="<<endl;
        cout<<"=============================================="<<endl;
        cout<<"== Silahkan Masukkan ID Pemain : ";
        cin>>hapus.idAktor;
        temp = findElmChild(L, hapus.idAktor);

        if(temp == NULL)
        {
            cout<<endl;
            cout<<"=============================================="<<endl;
            cout<<"==----------Pemain tidak di Temukan---------=="<<endl;
            cout<<"=============================================="<<endl;
        }
        else
        {
            cout<<"=============================================="<<endl;
            cout<<"---------------Pemain di Temukan--------------"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"== ID Pemain     = "<<infoC(temp).idAktor<<endl;
            cout<<"== Nama Pemain   = "<<infoC(temp).namaAktor<<endl;
            cout<<"== Jenis Kelamin = "<<infoC(temp).jenisKelamin<<endl;
            cout<<endl;
            cout<<"Apakah anda yakin ingin menghapus data tersebut ? (Y/N) : ";
            cin>>choose;
            if(choose == 'y' || choose == 'Y')
            {
                cout<<endl;
                cout<<"==============================================="<<endl;
                cout<<"=----------Pemain berhasil di hapus.-----------"<<endl;
                cout<<"==============================================="<<endl;
                deleteChild(L, temp);
            }
            else
            {
                system("cls");
                cout<<"==============================================="<<endl;
                cout<<"==------Pemain tidak berhasil di hapus.------=="<<endl;
                cout<<"==============================================="<<endl;
            }
        }
    }
}
