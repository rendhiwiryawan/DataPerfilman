#include "relasi.h"

void create_listR(listR &L)
{
    firstR(L) = NULL;
}

addressR getLastR (listR L)
{
    if (firstR(L) != NULL)
    {
        addressR P = firstR(L);
        while (nextR(P) != NULL)
        {
            P = nextR(P);
        }
        return P;
    }
    else
    {
        return NULL;
    }
}

void insert_firstR(listR &L, addressR P)
{
    nextR(P) = firstR(L);
    firstR(L) = P;
}

void insert_lastR(listR &L, addressR P)
{
    if (firstR(L) != NULL)
    {
        addressR Q = firstR(L);
        while (nextR(Q) != NULL)
        {
            Q = nextR(Q);
        }
        nextR(Q) = P;
    }
    else
    {
        insert_firstR(L, P);
    }
}

void insert_afterR(listR &L, addressR prec, addressR P)
{
    if (firstR(L) == NULL)
    {
        insert_firstR(L, P);
    }
    else if (nextR(getLastR(L)) == NULL)
    {
        insert_lastR(L, P);
    }
    else
    {
        nextR(P) = nextR(prec);
        nextR(prec) = P;
    }
}

void delete_firstR(listR &L, addressR &P)
{
    if (firstR(L) != NULL)
    {
        infoC(child(P)).rate--;
        P = firstR(L);
        firstR(L) = nextR(P);
        nextR(P) = NULL;
    }
}

void delete_lastR(listR &L, addressR &P)
{
    infoC(child(P)).rate--;
    addressR Q = firstR(L);
    P = nextR(Q);
    while (nextR(P) != NULL)
    {
        P = nextR(P);
        Q = nextR(Q);
    }
    nextR(Q) = NULL;
}

void delete_afterR(listR &L, addressR Prec, addressR &P)
{
    if (Prec != NULL)
    {
        infoC(child(P)).rate--;
        if (P == firstR(L))
        {
            delete_firstR(L, P);
        }
        else if (P == getLastR(L))
        {
            delete_lastR(L, P);
        }
        else
        {
            P = nextR(Prec);
            nextR(Prec) = nextR(P);
            nextR(P) = NULL;
        }
    }
}

addressR alokasiR(addressP P, addressC C)
{
    addressR Q = new elmlistR;
    parent(Q) = P;
    child(Q) = C;
    nextR(Q) = NULL;
    return Q;
}

addressR findElmR(listR L, addressP P, addressC C)
{
    addressR Q = firstR(L);
    while (Q != NULL)
    {
        if (parent(Q) == P && child(Q) == C)
        {
            return Q;
        }
        Q = nextR(Q);
    }
    return NULL;
}

void printPemainR(listR L, listP P, listC C)
{
    string namaFilm;
    cout<<endl;
    cout<<"Masukkan Nama Film : ";
    cin.ignore();
    getline(cin, namaFilm);
    cout<<endl;

    addressP Z = findElmNamaFilm(P, namaFilm);
    if (Z != NULL)
    {
        if (firstR(L) != NULL)
        {
            addressR R = firstR(L);
            system("cls");
            cout<<"=============================================================="<<endl;
            cout<<"== Berikut nama pemain pada film "<<namaFilm<<" :"<<endl;
            cout<<"=="<<endl;
            while (R != NULL)
            {
                if (namaFilm == infoP(parent(R)).namaFilm)
                {
                    addressC X = findElmChild(C, infoC(child(R)).idAktor);
                    if (X != NULL){
                        cout<<"== ID Pemain     : "<<infoC(child(R)).idAktor<<endl;
                        cout<<"== Nama Pemain   : "<<infoC(child(R)).namaAktor<<endl;
                        cout<<"== Jenis Kelamin : "<<infoC(child(R)).jenisKelamin<<endl;
                        cout<<"== "<<endl;
                    }
                }
                R = nextR(R);
            }
            cout<<"\t\t\t=============================================================="<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Tidak tersedia pemain dalam film "<<namaFilm<<".";
        }
    }
    else
    {
        system("cls");
        cout<<"========================================================"<<endl;
        cout<<"==-------MAAF, FILM YANG DIMINTA TIDAK TERSEDIA-------=="<<endl;
        cout<<"========================================================"<<endl;
        cout<<"==-----------------ENTER UNTUK KEMBALI----------------=="<<endl;
        cout<<"========================================================"<<endl;
    }
}

void printFilmR (listR L,listP P, listC C)
{
    string namaAktor;
    cout<<endl;
    cout<<"\t\t\tMasukkan Nama Pemain = ";
    cin.ignore();
    getline(cin, namaAktor);
    cout<<endl;
    addressC Z = findElmNamaAktor(C, namaAktor);
    if (Z != NULL)
    {
        if (firstR(L) != NULL)
        {
            addressR R = firstR(L);
            system("cls");
            cout<<"================================================================"<<endl;
            cout<<"== Berikut film-film yang di bintangi oleh "<<namaAktor<<" :"<<endl;
            cout<<"==="<<endl;
            while (R != NULL)
            {
                if (namaAktor == infoC(child(R)).namaAktor)
                {
                    addressP X = findElmKodeFilm(P, infoP(parent(R)).kodeFilm);
                    if (X != NULL){
                        cout<<"== Kode Film : "<<infoP(parent(R)).kodeFilm<<endl;
                        cout<<"== Nama Film : "<<infoP(parent(R)).namaFilm<<endl;
                        cout<<"== Durasi    : "<<infoP(parent(R)).durasi<<endl;
                        cout<<"== Tahun     : "<<infoP(parent(R)).tahun<<endl;
                        cout<<"=="<<endl;
                    }
                }
                R = nextR(R);
            }
            cout<<"================================================================"<<endl;
        }
    }
    else
    {
        system("cls");
        cout<<"============================================================="<<endl;
        cout<<"==--------MAAF, PEMAIN YANG DIMINTA TIDAK TERSEDIA---------=="<<endl;
        cout<<"============================================================="<<endl;
        cout<<"==-------------------ENTER UNTUK KEMBALI-------------------=="<<endl;
        cout<<"============================================================="<<endl;
    }

}


void printSemua (listR L, listP P, listC C, string Film)
{
    if (firstR(L) != NULL)
    {
        addressP F = findElmNamaFilm(P, Film);
        addressR R = firstR(L);
        int n = 1;
        cout<<"== Film "<<Film<<" ("<<infoP(F).kodeFilm<<") dibintangi oleh : "<<endl;
        while (R != NULL)
        {
            if (infoP(parent(R)).namaFilm == Film)
            {
                addressC X = findElmChild(C, infoC(child(R)).idAktor);
                if (X != NULL){
                    cout<<"==   "<<n<<". "<<infoC(child(R)).namaAktor<<" ("<<infoC(child(R)).idAktor<<") "<<endl;
                    n = n+1;
                }
            }
            R = nextR(R);
        }
    }
}

void goPrint (listR M, listP K, listC L)
{
    if (firstR(M) != NULL)
    {
        addressP F = firstP(K);
        system("cls");
        cout<<"\t========================================================="<<endl;
        cout<<"== Berikut seluruh data pada relasi : "<<endl;
        cout<<"=="<<endl;
        do
        {
            printSemua(M, K, L, infoP(F).namaFilm);
            cout<<"=="<<endl;
            F = nextP(F);
        }
        while (F != firstP(K));
        cout<<"========================================================="<<endl;
    }
    else
    {
        cout<<"========================================================"<<endl;
        cout<<"==----BELUM TERSEDIA RELASI ANTARA FILM DAN PEMAIN----=="<<endl;
        cout<<"========================================================"<<endl;
        cout<<"==-----------------ENTER UNTUK KEMBALI----------------=="<<endl;
        cout<<"========================================================"<<endl;

    }
}

bool cekRelasi (listR &R, int x, int y)
{
    addressR P;
    P = firstR(R);
    while(P!=NULL)
    {
        if(infoP(parent(P)).kodeFilm == y && infoC(child(P)).idAktor==x)
        {
            return true;
        }
        else
        {
            P = nextR(P);
        }
    }
    if(P!=NULL)
    {
        return false;
    }
}

void tambahRelasi(listR &R, listP P, listC C)
{
    int kodeP, kodeC;

    print_infoP(P);
    cout<<"\t\t\tMasukkan kode Film = ";
    cin>>kodeP;
    addressP carikodeP = findElmKodeFilm(P, kodeP);
    if (carikodeP != NULL)
    {
        viewChild(C);
        cout<<"Masukkan ID Aktor = ";
        cin>>kodeC;
        addressC cariIdC = findElmChild(C, kodeC);
        if (cariIdC != NULL)
        {
            if(cekRelasi(R,kodeC,kodeP))
            {
                cout<<endl;
                cout<<"SUDAH PERNAH DIHUBUNGKAN.";
            }
            else
            {
                addressR newR = alokasiR(carikodeP, cariIdC);
                infoC(cariIdC).rate++;
                insert_lastR(R, newR);
                cout<<endl;
                system("cls");
                cout<<"==================================================================="<<endl;
                cout<<""<<infoP(carikodeP).namaFilm<<" dan "<<infoC(cariIdC).namaAktor<<" berhasil dihubungkan."<<endl;
                cout<<"==================================================================="<<endl;
                cout<<"==----------------------ENTER UNTUK KEMBALI----------------------=="<<endl;
                cout<<"==================================================================="<<endl;
            }
        } else {
            tambahRelasi(R, P, C);
        }
    }
    else
    {
        tambahRelasi(R, P, C);
    }
}

void deleteRelasi(listR &L, listP P, listC C)
{
    if (firstR(L) != NULL)
    {
        goPrint(L, P, C);
        int x,y;
        cout<<"Masukkan kode Film  = ";
        cin>>x;
        cout<<"Masukkan kode Aktor = ";
        cin>>y;
        addressP F = findElmKodeFilm(P, x);

        addressC A = findElmChild(C, y);
//
//        if(A != NULL)
//            infoC(A).rate--;

        addressR R = findElmR(L, F, A);
        if (R != NULL)
        {
            if (R == firstR(L))
            {
                delete_firstR(L, R);
            }
            else if (R == getLastR(L))
            {
                delete_lastR(L, R);
            }
            else
            {
                addressR S = firstR(L);

                while (nextR(S) != R)
                {
                    S = nextR(S);
                }
                delete_afterR(L, S, R);
            }
            cout<<"========================================================="<<endl;
            cout<<"==---RELASI ANTARA FILM DAN PEMAIN BERHASIL DIHAPUS----=="<<endl;
            cout<<"========================================================="<<endl;
            cout<<"==-----------------ENTER UNTUK KEMBALI-----------------=="<<endl;
            cout<<"========================================================="<<endl;
        }
        else
        {
            cout<<"========================================================="<<endl;
            cout<<"==----BELUM TERSEDIA RELASI ANTARA FILM DAN PEMAIN-----=="<<endl;
            cout<<"========================================================="<<endl;
            cout<<"==-----------------ENTER UNTUK KEMBALI-----------------=="<<endl;
            cout<<"========================================================="<<endl;
        }
    }
    else
    {
        system("cls");
        cout<<"========================================================="<<endl;
        cout<<"==----BELUM TERSEDIA RELASI ANTARA FILM DAN PEMAIN-----=="<<endl;
        cout<<"========================================================="<<endl;
        cout<<"==-----------------ENTER UNTUK KEMBALI-----------------=="<<endl;
        cout<<"========================================================="<<endl;

    }
}

void deleteParentR (listR &R, listP &P, listC C){
    char choose;
    if (firstP(P) == NULL)
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
        addressP a = findElmKodeFilm(P, x);

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

                addressR r = firstR(R);
                while (r != NULL){
                    if (infoP(parent(r)).kodeFilm == x){
                        if (r == firstR(R)){
                            delete_firstR(R, r);
                        } else if (r == getLastR(R)){
                            delete_lastR(R, r);
                        } else {
                            addressR re = firstR(R);
                            while (nextR(re) != r){
                                re = nextR(re);
                            }
                            delete_afterR(R, re, r);
                        }
                    }
                    r = nextR(r);
                }

                if (a == firstP(P))
                {
                    delete_firstP(P,a);
                }
                else if (nextP(a) == firstP(P))
                {
                    delete_lastP(P, a);
                }
                else
                {
                    addressP b = firstP(P);
                    while (nextP(b)!=a)
                    {
                        b = nextP(b);
                    }
                    delete_afterP(P, b, a);
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

void delteteChildR(listR &R, listP P, listC &C){
aktor hapus;
    addressC temp;
    char choose;
    if (firstC(C) == NULL)
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
        cout<<"== Silahkan Masukkan ID Pemain = ";
        cin>>hapus.idAktor;
        temp = findElmChild(C, hapus.idAktor);

        if(temp == NULL)
        {
            cout<<endl;
            cout<<"=============================================="<<endl;
            cout<<"==----------Pemain tidak di Temukan---------=="<<endl;
            cout<<"=============================================="<<endl;
        }
        else
        {
            infoC(temp).rate--;
            cout<<"=============================================="<<endl;
            cout<<"---------------Pemain di Temukan--------------"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"== ID Pemain     : "<<infoC(temp).idAktor<<endl;
            cout<<"== Nama Pemain   : "<<infoC(temp).namaAktor<<endl;
            cout<<"== Jenis Kelamin : "<<infoC(temp).jenisKelamin<<endl;
            cout<<endl;
            cout<<" Apakah anda yakin ingin menghapus data tersebut ? (Y/N) : ";
            cin>>choose;
            if(choose == 'y' || choose == 'Y')
            {
                cout<<endl;
                cout<<"==============================================="<<endl;
                cout<<"=----------Pemain berhasil di hapus.-----------"<<endl;
                cout<<"==============================================="<<endl;

                addressR r = firstR(R);
                while (r != NULL){
                    if (infoC(child(r)).idAktor == hapus.idAktor){
                        if (r == firstR(R)){
                            delete_firstR(R, r);
                        } else if (r == getLastR(R)){
                            delete_lastR(R, r);
                        } else {
                            addressR prec = firstR(R);
                            while (nextR(prec) != r){
                                prec = nextR(prec);
                            }
                            delete_afterR(R, prec, r);
                        }
                    }
                    r = nextR(r);
                }

                deleteChild(C, temp);
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

void pemainTop(listR K, listP L, listC &C)
{
    system("cls");
    addressC topAkrtis;
    addressC topAktor;

    topAkrtis = NULL;
    topAktor = NULL;

    int x,y = 0;

    addressC P = firstC(C);
    while (P != NULL)
    {
        if (infoC(P).jenisKelamin == 'P')
        {
            if (topAkrtis == NULL || infoC(P).rate > x)
            {
                x = infoC(P).rate;
                topAkrtis = P;
            }
        }
        else if (infoC(P).jenisKelamin == 'L')
        {
            if (topAktor == NULL || infoC(P).rate > y)
            {
                y = infoC(P).rate;
                topAktor = P;
            }
        }
        P = nextC(P);
    }

    if(infoC(topAkrtis).rate == 0 && infoC(topAktor).rate == 0)
    {
        cout<<"============================================="<<endl;
        cout<<"== Top Aktris = Tidak ada Aktris Top.      =="<<endl;
        cout<<"==   a. ID Aktris   : -                    =="<<endl;
        cout<<"==   b. Gender      : -                    =="<<endl;
        cout<<"==   c. Popularitas : -                    =="<<endl;
        cout<<"============================================="<<endl;
        cout<<"== Top Aktor  = Tidak ada Aktor Top.       =="<<endl;
        cout<<"==   a. ID Aktris   : -                    =="<<endl;
        cout<<"==   b. Gender      : -                    =="<<endl;
        cout<<"==   c. Popularitas : -                    =="<<endl;
        cout<<"============================================="<<endl;
    }
    else if(infoC(topAkrtis).rate == 0)
    {
        cout<<"============================================="<<endl;
        cout<<"== Top Aktris = Tidak ada Aktris Top.      =="<<endl;
        cout<<"==   a. ID Aktris   : -                    =="<<endl;
        cout<<"==   b. Gender      : -                    =="<<endl;
        cout<<"==   c. Popularitas : -                    =="<<endl;
        cout<<"============================================="<<endl;
        cout<<"== Top Aktor  = "<<infoC(topAktor).namaAktor<<endl;
        cout<<"==   a. ID Aktor    : "<<infoC(topAktor).idAktor<<endl;
        cout<<"==   b. Gender      : "<<infoC(topAktor).jenisKelamin<<endl;
        cout<<"==   c. Popularitas : "<<infoC(topAktor).rate<<endl;
        cout<<"============================================="<<endl;
    }
    else if(infoC(topAktor).rate == 0)
    {
        cout<<"============================================="<<endl;
        cout<<"== Top Aktris = "<<infoC(topAkrtis).namaAktor<<endl;
        cout<<"==   a. ID Aktris   : "<<infoC(topAkrtis).idAktor<<endl;
        cout<<"==   b. Gender      : "<<infoC(topAkrtis).jenisKelamin<<endl;
        cout<<"==   c. Popularitas : "<<infoC(topAkrtis).rate<<endl;
        cout<<"== Top Aktor  = Tidak ada Aktor Top.       =="<<endl;
        cout<<"==   a. ID Aktris   : -                    =="<<endl;
        cout<<"==   b. Gender      : -                    =="<<endl;
        cout<<"==   c. Popularitas : -                    =="<<endl;
        cout<<"============================================="<<endl;
    }
    else
    {
        cout<<"============================================="<<endl;
        cout<<"== Top Aktris = "<<infoC(topAkrtis).namaAktor<<endl;
        cout<<"==   a. ID Aktris   : "<<infoC(topAkrtis).idAktor<<endl;
        cout<<"==   b. Gender      : "<<infoC(topAkrtis).jenisKelamin<<endl;
        cout<<"==   c. Popularitas : "<<infoC(topAkrtis).rate<<endl;
        cout<<"============================================="<<endl;
        cout<<"== Top Aktor  = "<<infoC(topAktor).namaAktor<<endl;
        cout<<"==   a. ID Aktor    : "<<infoC(topAktor).idAktor<<endl;
        cout<<"==   b. Gender      : "<<infoC(topAktor).jenisKelamin<<endl;
        cout<<"==   c. Popularitas : "<<infoC(topAktor).rate<<endl;
        cout<<"============================================="<<endl;
    }

}


