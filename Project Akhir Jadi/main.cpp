#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string akun[65][2]={"2731","2731"};
int pilih, jumlah = 4,stock,o;
char u;
string user, pass, hapus, pjm, edit, kembali;
string kode[20]{"APC","KAL","AJB","PKN"};
string kategori[20]{"Sains","Sains","Sains","Sosial"};
string judul[20]{"Algoritma dan Pemrograman C++","Kalkulus","Aljabar Linier dan Matriks","Pancasila"};
int stok[20]{8,10,2,3};

void awal();
void loginadm();
void loginusr();
void admin();
void edt();
void pengguna();
void entri();
void data();
void del();
void pinjam();
void kembalikan();
void tmbhuser();
void cari();
void listuser();


int main()
{
		awal();
}

//FUNGSI TAMPILAN AWAL LOGIN
void awal(){
	system ("cls");
	cout<<"============================================"<<endl;
	cout<<"||------------MENU PERPUSTAKAAN-----------||"<<endl;
	cout<<"============================================"<<endl;
	cout<<"||1.Login Admin                           ||"<<endl;
	cout<<"||2.Login User                            ||"<<endl;
    cout<<"||3.Keluar                                ||"<<endl;
	cout<<"============================================"<<endl;
	cout<<"Pilih: ";
	cin>>pilih;

    if(pilih == 1){
        loginadm();
    }else if(pilih == 2){
        loginusr();
    }else if(pilih == 3){
            cout<<"Terimakasih sudah berkunjung!"<<endl;
			exit(0);
    }else{
            cout<<"Pilihan yang Anda masukkan salah"<<endl;
            exit(0);
    }
	}
//FUNGSI LOGIN ADMIN
void loginadm(){
        loginadmin:
		cout<<"Username: ";
		cin>>user;
		cout<<"Password: ";
		cin>>pass;

		if(user=="admin" && pass=="123"){
			cout<<"Login Berhasil"<<endl;
			admin();
		}
		else{
			cout<<"Username atau Password salah"<<endl;
		}
		cout<<"Coba login kembali?(y/n): ";
		cin>>u;
        if(u=='y' || u== 'Y'){
            goto loginadmin;
        }
}
//FUNGSI LOGIN USER
void loginusr(){
    int j;
    bool sts = true;
        loginuser:
		cout<<"NIM anda: ";
		cin>>user;
		cout<<"Password: ";
		cin>>pass;

        for(j=0; j<65; j++){
        if(user == akun[j][0] && pass == akun[j][1]){
            cout<<"Login Berhasil"<<endl;
            sts = true;
			pengguna();
        }
        else{
			sts = false;
        }
		}
		if (sts==false) {

			cout<<"Username atau Password salah"<<endl;
		}
		cout<<"Coba login kembali?(y/n): ";
		cin>>u;
        if(u=='y' || u== 'Y'){
            goto loginuser;
        }else{
        }
}
//FUNGSI TAMBAH USER
void tmbhuser(){
    int jmlh;
    cout<<"Berapa User? : ";
    cin>>jmlh;
    cout<<"Ada Berapa user yang sudah ada ? :";
    cin>>o;
    jmlh=jmlh+o;
    for(o ;o<jmlh;o++){
        cin.ignore();
        cout<<"Masukkan NIM : ";
        getline(cin,akun[o][0]);
        cout<<"Masukkan Password : ";
        getline(cin,akun[o][1]);
        cout<<"Register Berhasil!"<<endl;
    }
}
//FUNGSI TAMPILAN ADMIN
void admin(){
	up:
		Sleep(1200);
		system ("cls");
		cout<<"============================================"<<endl;
		cout<<"||----------------MENU ADMIN--------------||"<<endl;
		cout<<"============================================"<<endl;
		cout<<"||1. Masukkan Buku Baru                   ||"<<endl;
		cout<<"||2. Edit Buku                            ||"<<endl;
		cout<<"||3. Hapus Buku                           ||"<<endl;
		cout<<"||4. Lihat Daftar Buku                    ||"<<endl;
		cout<<"||5. Kembali ke Menu Awal                 ||"<<endl;
		cout<<"||6. List User                            ||"<<endl;
		cout<<"||7. Tambah User Baru                     ||"<<endl;
		cout<<"||8. Keluar                               ||"<<endl;
		cout<<"============================================"<<endl;
		cout<<"Pilih: ";
		cin>>pilih;

        switch(pilih){
            case 1 :
                entri();
                break;
            case 2:
                edt();
                break;
            case 3:
                del();
                break;
            case 4:
                data();
                break;
            case 5:
                awal();
                break;
            case 6:
                listuser();
                break;
            case 7:
                tmbhuser();
                break;
            case 8:
                cout<<"Terimakash Telah Berkunjung!";
                exit(0);
                break;
            default:
                cout<<"Pilihan Anda Tidak Ada"<<endl;
                exit(0);
                break;
}
		cout<<"Kembali ke menu Admin?(y/n): ";
		cin>>u;
		if (u=='Y' || u == 'y'){
            goto up;
		}else{
            exit(0);
		}
	}
//FUNGSI TAMBAH BUKU
void entri(){
    int j;
	cout<<"Berapa?: ";
	cin>>jumlah;
	cout<<"Ada berapa Buku :";
    cin>>j;
    jumlah=jumlah+j;
	for(j; j<jumlah; j++){
		cin.ignore();
		cout<<"Masukkan Kode Buku    : ";
		getline(cin, kode[j]);
		cout<<"Masukkan Kategori Buku: ";
		getline(cin, kategori[j]);
		cout<<"Masukkan Judul Buku   : ";
		getline(cin, judul[j]);
		cout<<"Masukkan Jumlah Stok  : ";
		cin>>stok[j];
		cout<<"---------------------------------------------------------"<<endl;
	}
}
//FUNGSI EDIT BUKU
void edt(){
    cin.ignore();
    cout<<"Masukkan kode buku : ";
    getline(cin,edit);

    cout<<"Masukkan stock buku : ";
    cin>>stock;

    for(int i=0;i<jumlah;i++){
		if(edit==kode[i]){
			for(int k=i;k<jumlah;k++ ){
				stok[i]=stock;
			}
		}
	}
	data();

}
//FUNGSI LIST USER
void listuser(){
    o=o-1;
    for(int i=0;i<=o;i++){
        cout<<"NIM : "<<akun[i][0]<<endl;
    }

}
//FUNGSI MENGHAPUS BUKU
void del(){
	cin.ignore();
	cout <<"Masukkan Kode Buku yang ingin di hapus: ";
	getline(cin,hapus);

	for(int i=0;i<jumlah;i++){
		if(hapus==kode[i]){
			for(int k=i;k<jumlah;k++ ){
				kode[k]=kode[k+1];
				kategori[k]=kategori[k+1];
				judul[k]=judul[k+1];
				stok[k]=stok[k+1];
			}
			jumlah-=1;
			break;
		}
	}
	data();
}
//FUNDSI TAMPILAN PENGGUNA
void pengguna(){
	do{
		Sleep(1200);
		system ("cls");
		cout<<"============================================"<<endl;
		cout<<"||------------------MENU------------------||"<<endl;
		cout<<"============================================"<<endl;
		cout<<"||1. Lihat Daftar Buku                    ||"<<endl;
		cout<<"||2. Pinjam Buku                          ||"<<endl;
		cout<<"||3. Kembalikan Buku                      ||"<<endl;
		cout<<"||4. Kembali ke Menu Awal                 ||"<<endl;
		cout<<"||5. Cari Buku                            ||"<<endl;
		cout<<"||6. Keluar                               ||"<<endl;
		cout<<"============================================"<<endl;
		cout<<"Pilih: ";
		cin>>pilih;

        switch(pilih){
        case 1:
            data();
            cout<<"Ingin Pinjam Buku?(y/n): ";
			cin>>u;
			if(u=='y' || u=='Y'){
				pinjam();
			}
			break;
        case 2:
            pinjam();
            break;
        case 3:
            kembalikan();
            break;
        case 4:
            awal();
            break;
        case 5:
            cari();
            break;
        case 6:
            cout<<"Terimakasih Sudah Berkunjung!";
            exit(0);
            break;
        default:
            cout<<"Pilihan Anda Tidak Ada"<<endl;
            exit(0);
            break;
        }

		cout<<"Kembali?(y/n): ";
		cin>>u;
	}
	while(u=='y' || u=='Y');

}
//FUNGSI PENCARIAN BUKU
void cari(){
    string car;
    bool sts = true;
    do{
    cout<<"Masukkan Kode/Nama Buku : ";
    cin>>car;
    for(int i =0;i<jumlah;i++){
        if(car == kode[i] || car == judul[i]){
        cout<<"Kode Buku	    : "<<kode[i]<<endl;
		cout<<"Kategori Buku       : "<<kategori[i]<<endl;
		cout<<"Judul Buku	    : "<<judul[i]<<endl;
		cout<<"Stok Buku	    : "<<stok[i]<<endl;
		sts = true;
		break;
		}else{
            sts = false;
		}
    }
    if(sts == false){
        cout<<"Tidak Ditemukan"<<endl;
    }
        cout<<"Ingin Cari Lagi (Y/N) : ";
        cin>>u;
    }
    while(u=='y' || u=='Y');
}
//FUNSGI KOLEKSI BUKU
void data(){
	cout<<"Koleksi buku yang kami punya: "<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i=0; i<jumlah; i++){
		if(judul[i]== "empty") break;
		cout<<i+1<<"\t Kode Buku	: "<<kode[i]<<endl;
		cout<<" \t Kategori Buku	: "<<kategori[i]<<endl;
		cout<<" \t Judul Buku	: "<<judul[i]<<endl;
		cout<<" \t Stok Buku	: "<<stok[i]<<endl;
		cout<<"---------------------------------------------------------"<<endl;
	}
}
//FUNGSI PEMINJAMAN BUKU
void pinjam(){
	cin.ignore();
 	cout<<"Masukkan Kode Buku yang ingin dipinjam: ";
	getline(cin,pjm);
 	for (int i=0;i<jumlah;i++){
  		if(pjm==kode[i]){
   				if(stok[i]>=1){
   					cout<<"Anda meminjam buku "<<judul[i]<<endl;
   					stok[i]-=1;
					cout<<"Sisa stok buku ini ada "<<stok[i]<<endl;
				}
				else if(stok[i]<=0){
   					cout<<"Maaf, stok buku tidak ada"<<endl;
				}
  		}
 	}
}
//FUNGSI PENGEMBALIAN BUKU
void kembalikan(){
	cin.ignore();
 	cout<<"Masukkan Kode Buku yang ingin dikembalikan: ";
 	getline(cin,kembali);
 	for(int i=0;i<jumlah;i++){
  		if(kembali==kode[i]){
   			cout<<"Anda telah mengembalikan buku "<<judul[i]<<endl;
   			stok[i]+=1;
  		}
 	}
}


