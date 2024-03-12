#include<iostream>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

#define max 15
string nama[max], loop;
int posisi = 0;
void display(){
	system("cls"); 
	
	if(posisi > 0){
		cout << "Data Tersimpan" << endl;
		for(int i = 0; i < posisi; i++){
			cout << i+1 << ". " << nama[i] << endl;
		}	
	} else {
		cout << "<-- Data Kosong -->" << endl;
	}
	cout << endl;
}

void add(){
	do {
		display();
		if(posisi < max){
			cin.ignore();
			cout << "Tambah Data : ";
			getline(cin, nama[posisi]);
			posisi++;
			display();
			cout << "ulangi <y/t> : ";
			cin >> loop;
		} else {
			cout << "<-- memori penuh -->" << endl;
			cout << "isi t untuk kembali : ";
			cin >> loop;
		}
	} while(loop == "y");
}

void edit(){
	int y;
	do {
		display();
		cout << "ubah data ke : ";
		cin >> y;
		cin.ignore();
		cout << "ubah menjadi : ";
		getline(cin, nama[y-1]);
		display();
		cout << "ubah lagi <y/t> : ";
		cin >> loop;	
	} while(loop == "y");
}

void del(){
	int x;
	do {
		display();
		if(posisi > 0){
			cout << "Hapus Data Ke : ";
			cin >> x;
			for(int i = x; i < posisi; i++){
				nama[i-1] = nama[i];
			}
			posisi--;
			display();
			cout << "hapus lagi <y/t> : ";
			cin >> loop;
		} else {
			cout << "isi selain y : ";
			cin >> loop;
		}
	} while(loop == "y");
}

int main () {
    int pil,percobaan = 0;
    string nama,nim;
    cout<<"Selamat Datang di pendataan list merek TWS, Silakan Login terlebih dahulu!"<<endl;
    while (percobaan < 3){
    	cout<<"Masukkan Nama: ";
    	cin>>nama;
    	cout<<"Masukkan NIM: ";
    	cin>>nim;
    	if (nama == "AhmadNurHuda" && nim == "2309106108"){
    		cout<<"Login Berhasil!"<<endl;
    		cout<<"Mohon Tunggu dalam 5 Detik..."<<endl;
    		for (int i = 5; i > 0; --i) {
    			std::cout << "Countdown: " << i << " seconds remaining...\n";
    			std::this_thread::sleep_for(std::chrono::seconds(1));
    		}
    		std::cout << "Countdown Selesai!" << std::endl;
    		break;
    		
    	} else {
    		percobaan = percobaan + 1;
    		cout<<"Login Salah, Tersisa "<<3-percobaan<<" Lagi"<<endl;
    		
    	}//if (nama
    	
    }//while (percobaan < 3;){
    	
    if (percobaan == 3){
    	cout<<"Anda Sudah 3 kali salah login, program terpaksa berhenti"<<endl;
    	return 0;	
    }//if (percobaan == 3){
	do {
		system("cls");
		cout<<"Program Pendataan List Merek TWS"<<endl;
		cout << "[1] Tambah\n[2] Ubah\n[3] Hapus\n[4] Tampil\n[5] Keluar\nPilihan : "; 
		cin >> pil;
		switch(pil){
			case 1 :
				add();
				break;
			case 2 :
				edit();
				break;
			case 3 :
				del();
				break;
			case 4 :
				do {
					display();
					cout << "kembali <y/t> : ";
					cin >> loop;
				} while(loop != "y");
				break;
			case 5 :
				cout<<"Program Diakhirkan"<<endl;
				break;
			default :
				cout << "Pilih 1 - 4, Atau 5 Untuk keluar dari program!" << endl;
				break;
				
		}
	} while(pil != 5);
	cout << "Program Selesai !" << endl;
}