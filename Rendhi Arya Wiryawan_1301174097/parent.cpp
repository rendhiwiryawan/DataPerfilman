#include <iostream>
#include "parent.h"

using namespace std;

addressP alokasiP(infotypeP data)
{
    addressP a = new elmlistP;
    infoP(a) = data;
    nextP(a) = null;
    return a;
}

addressP dealokasiP(listP l, addressP &a)
{
    delete a;
}

void create_listP(listP &l)
{
    firstP(l) = null;
}

void insert_firstP(listP &l, addressP a)
{
    if (firstP(l) != null)
    {
        addressP b = firstP(l);
        while (nextP(b) != firstP(l))
        {
            b = nextP(b);
        }
        nextP(a)=firstP(l);
        nextP(b)=a;
        firstP(l)=a;
    }
    else
    {
        firstP(l)=a;
        nextP(a)=firstP(l);
    }
}

void insert_lastP(listP &l, addressP a)
{
    if(firstP(l) != null)
    {
        addressP b = firstP(l);
        while (nextP(b) != firstP(l))
        {
            b = nextP(b);
        }
        nextP(a)=firstP(l);
        nextP(b)=a;
    }
    else
    {
        insert_firstP(l, a);
    }
}

void insert_afterP(listP &l, addressP Prec, addressP a)
{
    if (Prec != null)
    {
        if (nextP(firstP(l)) == firstP(l))
        {
            insert_firstP(l, a);
        }
        else if (nextP(Prec) == firstP(l))
        {
            insert_lastP(l, a);
        }
        else
        {
            nextP(a) = nextP(Prec);
            nextP(Prec) = a;
        }
    }
}

void delete_firstP(listP &l, addressP &a)
{
    if (nextP(firstP(l)) != firstP(l))
    {
        addressP b = firstP(l);
        while (nextP(b) != firstP(l))
        {
            b = nextP(b);
        }
        a = firstP(l);
        firstP(l)=nextP(a);
        nextP(b)=firstP(l);
        nextP(a)=null;
    }
    else
    {
        a = firstP(l);
        nextP(a)=null;
        firstP(l)=null;
    }
}

void delete_lastP(listP &l, addressP &a)
{
    if (nextP(firstP(l)) != firstP(l))
    {
        addressP b = firstP(l);
        a = nextP(b);
        while (nextP(a) != firstP(l))
        {
            b = a;
            a = nextP(a);
        }
        nextP(a)=null;
        nextP(b)=firstP(l);
    }
}


void delete_afterP(listP &l, addressP Prec, addressP &a)
{
    if (Prec != null)
    {
        if (nextP(firstP(l)) == firstP(l))
        {
            delete_firstP(l, a);
        }
        else if (nextP(a) == firstP(l))
        {
            delete_lastP(l, a);
        }
        else
        {
            a = nextP(Prec);
            nextP(Prec) = nextP(a);
            nextP(a) = null;
        }
    }
}

void print_infoP(listP l)
{
    if (firstP(l) != null)
    {
        system("cls");
        cout<<"================================================"<<endl;
        cout<<"== Berikut daftar Film-Film yang ada :        =="<<endl;
        cout<<"==--------------------------------------------=="<<endl;
        addressP a = firstP(l);
        do
        {
            cout<<"== Kode Film : "<<infoP(a).kodeFilm<<endl;
            cout<<"== Film      : "<<infoP(a).namaFilm<<endl;
            cout<<"== Durasi    : "<<infoP(a).durasi<<endl;
            cout<<"== Tahun     : "<<infoP(a).tahun<<endl;
            a = nextP(a);
            cout<<"==                                            "<<endl;
        }
        while (a != firstP(l));

        cout<<"================================================"<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"================================================"<<endl;
        cout<<"==           DATA FILM MASIH KOSONG           =="<<endl;
        cout<<"==   SILAHKAN MASUKKAN DATA TERLEBIH DAHULU   =="<<endl;
        cout<<"================================================"<<endl;
    }
}

addressP findElmKodeFilm(listP l, int x)
{
    if(firstP(l) != NULL)
    {
        addressP a = firstP(l);
        while ((nextP(a) != firstP(l)) && (infoP(a).kodeFilm != x))
        {
            a = nextP(a);
        }
        if(infoP(a).kodeFilm == x)
            return a;
        else
            return null;
    }
    else
    {
        cout<<"\t\t\tMAAF LIST MASIH KOSONG. "<<endl;
    }
}

addressP findElmNamaFilm(listP l, string y)
{
    if (firstP(l) != null)
    {
        addressP a = firstP(l);
        while((nextP(a) != firstP(l)) && (infoP(a).namaFilm != y))
        {
            a = nextP(a);
        }
        if (infoP(a).namaFilm == y)
            return a;
        else
            return null;
    }
}

addressP getLastP (listP l)
{
    if (firstP(l) != null)
    {
        addressP P = firstP(l);
        while (nextP(P) != firstP(l))
        {
            P = nextP(P);
        }
        return P;
    }
    else
        return null;
}

void menuCari(listP &l)
{
    system("cls");
    cout<<"=============================================="<<endl;
    cout<<"==              MENU CARI FILM              =="<<endl;
    cout<<"=============================================="<<endl;
    cout<<"== Silahkan Masukkan Kode Film : ";
    int x;
    cin>>x;
    cout<<"=============================================="<<endl;
    addressP cari = findElmKodeFilm(l, x);
    if (cari != null)
    {
        cout<<endl;
        cout<<"=============================================="<<endl;
        cout<<"==     BERIKUT DATA FILM YANG ANDA CARI     =="<<endl;
        cout<<"==------------------------------------------=="<<endl;
        cout<<"== Kode Film : "<<infoP(cari).kodeFilm<<endl;
        cout<<"== Nama      : "<<infoP(cari).namaFilm<<endl;
        cout<<"== Durasi    : "<<infoP(cari).durasi<<endl;
        cout<<"== Tahun     : "<<infoP(cari).tahun<<endl;
        cout<<"==------------------------------------------=="<<endl;
        cout<<"=============================================="<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Film Tidak di Temukan. "<<endl;
    }
};

void editParent(listP &l)
{

    int edit;
    char choose;

    cout<<"Masukkan Kode Film yang ingin di edit = ";
    cin>>edit;
    addressP temp = findElmKodeFilm(l, edit);

    if (temp == null)
    {
        system("cls");
        cout<<"=============================================="<<endl;
        cout<<"==--------Data film tidak ditemukan---------=="<<endl;
        cout<<"=============================================="<<endl;
    }
    else
    {
        system("cls");
        cout<<"=============================================="<<endl;
        cout<<"--------------Data film ditemukan-------------"<<endl;
        cout<<"=============================================="<<endl;
        cout<<"== Kode Film : "<<infoP(temp).kodeFilm<<endl;
        cout<<"== Nama Film : "<<infoP(temp).namaFilm<<endl;
        cout<<"== Durasi    : "<<infoP(temp).durasi<<endl;
        cout<<"== Tahun     : "<<infoP(temp).tahun<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;
        cout<<"Apakah anda yakin ingin mengedit data tersebut ? (Y/N) : ";
        cin>>choose;
        if(choose == 'y' || choose == 'Y')
        {
            Film a;
            cout<<endl;
            cout<<"============================================="<<endl;
            cout<<"==  SILAHKAN MASUKKAN DATA FILM YANG BARU  =="<<endl;
            cout<<"==-----------------------------------------=="<<endl;
            cout<<"== Kode Film Baru : ";
            cin>>a.kodeFilm;
            addressP P = findElmKodeFilm(l, a.kodeFilm);
            if (P == NULL)
            {
                if (temp == firstP(l))
                {
                    delete_firstP(l, temp);
                }
                else if (temp == getLastP(l))
                {
                    delete_lastP(l, temp);
                }
                else
                {
                    addressP Prec = firstP(l);
                    while (nextP(Prec) != temp)
                    {
                        Prec = nextP(Prec);
                    }
                    delete_afterP(l, Prec, temp);
                }

                cout<<"== Nama Baru   : ";
                cin.ignore();
                getline(cin,a.namaFilm);
                cout<<"== Durasi Baru : ";
                cin>>a.durasi;
                cout<<"== Tahun Baru  : ";
                cin>>a.tahun;

                P = alokasiP(a);
                if (a.kodeFilm < infoP(firstP(l)).kodeFilm)
                {
                    insert_firstP(l, P);
                }
                else if (a.kodeFilm > infoP(getLastP(l)).kodeFilm)
                {
                    insert_lastP(l, P);
                }
                else
                {
                    addressP Prec = firstP(l);
                    while (infoP(nextP(Prec)).kodeFilm < infoP(P).kodeFilm)
                    {
                        Prec = nextP(Prec);
                    }
                    insert_afterP(l, Prec,P);
                }
                cout<<"=============================================="<<endl;
                cout<<"==--------Data film berhasil di edit.-------=="<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"=============================================="<<endl;
                cout<<"==----------Maaf, Kode sudah tersedia-------=="<<endl;
                cout<<"=============================================="<<endl;
                getch();
            }
        }
        else
        {
            cout<<"=============================================="<<endl;
            cout<<"==----Data film tidak berhasil di edit.-----=="<<endl;
            cout<<"=============================================="<<endl;
        }

    }
}

void insertParentSort (listP &l)
{
    if (firstP(l) != null)
    {
        int tambahP;
        addressP hasil;
        cout<<endl;
        cout<<"Masukkan Kode Film = ";
        cin>>tambahP;
        hasil = findElmKodeFilm(l, tambahP);

        if (hasil == null)
        {
            system("cls");
            Film a;
            cout<<"======================================="<<endl;
            cout<<"==      SILAHKAN ISI DATA UNTUK      =="<<endl;
            cout<<"==         MENAMBAHKAN FILM          =="<<endl;
            cout<<"======================================="<<endl;
            a.kodeFilm = tambahP;
            cout<<"== Kode Film : "<<a.kodeFilm<<endl;
            cout<<"== Nama Film : ";
            cin.ignore();
            getline(cin, a.namaFilm);
            cout<<"== Durasi Film : ";
            cin>>a.durasi;
            cout<<"== Tahun Film  : ";
            cin>>a.tahun;
            addressP P = alokasiP(a);
            cout<<"========================================"<<endl;
            cout<<"==-----film berhasil di tambahkan-----=="<<endl;
            cout<<"========================================"<<endl;

            if (a.kodeFilm < infoP(firstP(l)).kodeFilm)
            {
                insert_firstP(l, P);
            }
            else if (a.kodeFilm > infoP(getLastP(l)).kodeFilm)
            {
                insert_lastP(l, P);
            }
            else
            {
                addressP Prec = firstP(l);
                while (infoP(nextP(Prec)).kodeFilm < infoP(P).kodeFilm)
                {
                    Prec = nextP(Prec);
                }
                insert_afterP(l, Prec,P);
            }
        }
        else
        {
            cout<<endl;
            cout<<"Maaf, Kode Film sudah tersedia."<<endl;
            getch();
        }
    }
    else
    {
        system("cls");
        cout<<"======================================="<<endl;
        cout<<"==      SILAHKAN ISI DATA UNTUK      =="<<endl;
        cout<<"==         MENAMBAHKAN FILM          =="<<endl;
        cout<<"======================================="<<endl;
        Film b;
        cout<<"== Kode Film     : ";
        cin>>b.kodeFilm;
        cout<<"== Nama Film     : ";
        cin.ignore();
        getline(cin, b.namaFilm);
        cout<<"== Durasi Film   : ";
        cin>>b.durasi;
        cout<<"== Tahun Film    : ";
        cin>>b.tahun;
        cout<<"======================================="<<endl;
        addressP Q = alokasiP(b);
        insert_firstP(l, Q);
    }
}

void hapusFilm(listP &l)
{
    char choose;
    if (firstP(l) == NULL)
    {
        cout<<endl;
        cout<<"List Film masih kosong, silahkan input terlebih dahulu. "<<endl;
    }
    else
    {
        system("cls");
        int x;
        cout<<"=============================================="<<endl;
        cout<<"==              MENU HAPUS FILM             =="<<endl;
        cout<<"=============================================="<<endl;
        cout<<"== Silahkan Masukkan Kode Film = ";
        cin>>x;
        addressP a = findElmKodeFilm(l, x);

        if (a != null)
        {
            cout<<"=============================================="<<endl;
            cout<<"----------------Film di Temukan---------------"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"== Kode Film : "<<infoP(a).kodeFilm<<endl;
            cout<<"== Film      : "<<infoP(a).namaFilm<<endl;
            cout<<"== Durasi    : "<<infoP(a).durasi<<endl;
            cout<<"== Tahun     : "<<infoP(a).tahun<<endl;
            cout<<"=============================================="<<endl;
            cout<<endl;
            cout<<"Apakah anda yakin ingin menghapus data tersebut ? (Y/N) : ";
            cin>>choose;
            if(choose == 'y' || choose == 'Y')
            {
                cout<<endl;
                cout<<"=============================================="<<endl;
                cout<<"-----------Film berhasil di hapus.------------"<<endl;
                cout<<"=============================================="<<endl;

                addressP b = firstP(l);
                while (nextP(b)!=a)
                {
                    b = nextP(b);
                }

                if (a == firstP(l))
                {
                    delete_firstP(l,a);
                }
                else if (nextP(a) == firstP(l))
                {
                    delete_lastP(l, a);
                }
                else
                {
                    delete_afterP(l, b, a);
                }
            }
            else
            {
                cout<<"==============================================="<<endl;
                cout<<"==-------Film tidak berhasil di hapus.-------=="<<endl;
                cout<<"==============================================="<<endl;
            }

        }
        else
        {
            cout<<endl;
            cout<<"=============================================="<<endl;
            cout<<"==----------Film tidak di Temukan-----------=="<<endl;
            cout<<"=============================================="<<endl;
        }
    }
}
