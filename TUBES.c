#include <stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *f_data;
FILE *f_nabung;
FILE *f_aems;
FILE *f_aems2;
FILE *f_aems3;
FILE *f_bems;
FILE *f_bems2;

void main();
void User();
void Puse();
void Deposito();
void Idepo();
void Emas();
void searching();
void Jems();
void Dems();
void riwayat();
void riwayatb();
void Admin();
void Piladmin();
void Ldepo();
void Lemas();
void Jemas();
void fgs();
void cover();
void Exit();

int d,j,k,i,l,m,n,o,p,y,z,v;

int temp4,temp5;

struct {
	char uname[100],pass[100],nama[100],ttl[100],jenis[100],alamat[100],umur[100],telp[100];
} daftar,r;

struct {
	char nama[100],tgl[100];
	int c,k,total,uang;
} tabung,temp[100];

struct{
	char nama[100],tgl1[100];
	int hrg,harga,hasil,hasil2,brt,brt2;
} ems,temp1[100];

char uadmin[100],padmin[100];

char search[100],cari1[100],cari2[100];

char temp2[100],temp3[100];

void main(){
	system("cls");
	cover();
	printf("\t\t\t\t\t\t\t\t\t\t\t### MENU UTAMA ###\n \t\t\t\t\t  SELAMAT DATANG DI DASKOM SAVE\n");
	printf("\n1. User");
	printf("\n2. Admin");
	printf("\n3. Exit");
	printf("\nPilih :"); scanf("%d",&n);
	switch(n){
		case 1: User(); break;
		case 2: Admin(); break;
		case 3: Exit(); break;
	}
}

void User(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t##Menu Pilihan User##\n");
	printf("\n1. Registrasi");
	printf("\n2. Login");
	printf("\n3. Menu Utama");
	printf("\n\nPilih Menu :"); scanf("%d",&p); getchar();
	switch(p){
		case 1:
			system("cls");
			cover();
			printf("\n\t\t\t\t\t\t### MENU REGISTRASI ###\n");
			f_data =fopen("save.dat","ab");
			printf("\nUsername : ");gets(daftar.uname);
			printf("Password   : ");gets(daftar.pass);
			printf("\nRegistrasi Berhasil\n");
			printf("\n##### Isi Biodata #####\n");
			printf("Nama Lengkap          :"); gets(daftar.nama);
			printf("Tempat, Tanggal Lahir :"); gets(daftar.ttl);
			printf("Jenis Kelamin         :"); gets(daftar.jenis);
			printf("Alamat                :"); gets(daftar.alamat);
			printf("Umur                  :"); gets(daftar.umur);
			printf("Nomor Telepon         :"); gets(daftar.telp);
			printf("\n## Data Anda Sudah Disimpan ##\n");
			printf("\nSilahkan Login");
			fwrite(&daftar, sizeof(daftar), 1,f_data);
			fclose(f_data); getchar(); User(); break;
			
		case 2:
			system("cls");
			cover();
			f_data = fopen("save.dat","rb");
			printf("\t\t\t\t\t\t\t\t\t\t\t### Login Account ###\n"); 
			printf("\nUsername :");gets(cari1);
			printf("Password :");gets(cari2);
			while(fread(&daftar,sizeof(daftar),1,f_data)==1){
				if(strcmp(daftar.uname,cari1)==0 && strcmp(daftar.pass,cari2)==0){
					printf("\nSelamat Datang\n"); strcpy(r.nama,daftar.nama); system("pause"); Puse(); //
				}	
			} 
		fclose(f_data);
		printf("\nSilahkan Coba Lagi\n"); fclose(f_data); system("pause"); User();break; //
		
		case 3: main(); break;
	} 
}

void Puse(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### MENU TABUNGAN ###\n");
	printf("\nPilihan Tabungan Yang Ingin Diajukan");
	printf("\n1. Tabungan Deposito");
	printf("\n2. Tabungan Emas");
	printf("\n3. Intip Deposito");
	printf("\n4. Menu Utama ");
	printf("\nPilih Tabungan :"); scanf("%d",&m);
	switch(m){
		case 1: Deposito(); break;
		case 2: Emas(); break;
		case 3: Idepo(); break;
		case 4: main(); break;
	}
}

void Deposito(){
	system("cls");
	f_nabung = fopen("simpanan.dat", "ab"); fflush(stdin);
	strcpy(tabung.nama,r.nama);
	cover();
	printf("\n\t\t\t\t\t\t### DEPOSITO ###\n");
	printf("\nTanggal "); gets(tabung.tgl);
	printf("\nJumlah Uang Deposit        :"); scanf("%d",&tabung.k); 
	printf("\nJangka Waktu(6/9/12) Bulan :"); scanf("%d",&tabung.c); getchar();
	
	if(tabung.c==6){
		printf("\nBunga yang Anda Dapat 4 persen \n");
		tabung.total = ((tabung.k*4)/100);
	}
	else if(tabung.c==9){
		printf("\nBunga yang Anda Dapat 5 persen\n");
		tabung.total = ((tabung.k*5)/100);
			 
	}
	else if(tabung.c==12){
		
		printf("\nBunga yang Anda Dapat 6 persen\n");
		tabung.total = ((tabung.k*6)/100);
	}
	else{
		printf("\nAnda Tidak Mendapat Bunga Karna Jangka Waktu Tidak Sesuai\n");
		tabung.total = 0;
	}
	
	tabung.uang = tabung.total + tabung.k;
	printf("\nJumlah Uang yang Akan Diterima : %d\n",tabung.uang);
	fwrite(&tabung, sizeof (tabung), 1,f_nabung);
	system("pause");
	fclose(f_nabung);  
	Idepo(); 
} 

void Idepo(){
	int h=0;
	
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### SERTIFIKAT ###\n");
	f_nabung = fopen("simpanan.dat", "rb");
	while(fread(&tabung,sizeof(tabung),1,f_nabung)==1){
		if(strcmp(r.nama,tabung.nama)==0){
			printf("\n#### Sertifikasi Deposito ####\n");
			printf("Nama Lengkap              : %s\n",tabung.nama); 
			printf("Tanggal Menabung          : %s\n",tabung.tgl); 
			printf("Deposit                   : %d\n",tabung.k);
			printf("Jangka Waktu              : %d\n",tabung.c );
			printf("Jumlah yang Akan Diterima : %d\n",tabung.uang);
			h = h + tabung.uang;
		}
	} 
	printf("\nTotal Deposito : %d\n\n",h);
	system("pause");
	fclose(f_nabung); Puse();
	
}

void Emas(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### TABUNGAN EMAS ###\n");
	printf("Jual atau Beli Emas\n");
	printf("1. Jual Emas\n");
	printf("2. Beli Emas\n");
	printf("3. Riwayat beli Emas\n");
	printf("4. Riwayat Jual Emas\n");
	printf("5. Kembali Ke-Menu Utama\n");
	printf("Pilih Menu :"); scanf("%d",&y);
	switch(y){
		case 1: Jems(); break;
		case 2: Dems(); break;
		case 3: riwayat(); break;
		case 4: riwayatb(); break;
		case 5: main(); break;
	}	
}

void Jems(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### JUAL EMAS ###\n");
	f_aems = fopen("list.dat","rb");
	while(fread(&ems,sizeof(ems),1,f_aems)==1){
		printf("\nHarga Jual Emas Pada Tanggal %s\n",ems.tgl1);
		printf("\nHarga Emas : %d\n",ems.harga);
		
	}fclose(f_aems); 
		
	f_aems3 = fopen("list3.dat","ab");
	strcpy(ems.nama,r.nama);
	
	printf("\nBerapa Gram Emas yang Ingin Dijual : "); scanf("%d(gram))",&ems.brt2);
	ems.hasil2 = ems.harga * ems.brt2;
	printf("\nEmas %d(gram) Berhasil Terjual dengan Harga %d\n",ems.brt2,ems.hasil2);
	fwrite(&ems,sizeof(ems),1,f_aems3);
	fclose(f_aems3); system("pause"); Emas();
	
	} 	

void Dems(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t ### BELI EMAS ###\n");
	f_aems = fopen("list.dat","rb");
	while(fread(&ems,sizeof(ems),1,f_aems)==1){
		printf("\nHarga Emas Pada Tanggal %s",ems.tgl1);
		printf("\nHarga Emas : %d",ems.hrg);		
	} fclose(f_aems); 
	
	f_aems2 = fopen("list2.dat","ab");
	strcpy(ems.nama,r.nama);
	
	printf("\nBerapa Gram Emas yang Ingin Dibeli : "); scanf("%d(gram))",&ems.brt);
	ems.hasil = ems.hrg * ems.brt;
	printf("\n### Sertifikasi Emas ###\n");	
	printf("\nAnda Berhasil Membeli Emas %d(gram) dengan Harga %d\n",ems.brt,ems.hasil);
	fwrite(&ems,sizeof(ems),1,f_aems2);
	
	fclose(f_aems2); system("pause"); Emas();	
}

void riwayat(){
	int u = 0;
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### RIWAYAT BELI EMAS ###\n");
	f_aems2 = fopen("list2.dat","rb");
	
	while(fread(&ems,sizeof(ems),1,f_aems2)==1){
		if(strcmp(ems.nama,r.nama)==0){
			printf("\nNama : %s",ems.nama);
			printf("\nTanggal : %s",ems.tgl1);
			printf("\nAnda Telah Membeli Emas %d(gram) Seharga %d\n",ems.brt,ems.hasil);	
			u = u + ems.brt;	
		}
	}
	printf("\nTotal Emas yang Dibeli : %d(gram)\n",u);
	system("pause"); fclose(f_aems2); Emas();
}

void riwayatb(){
	int v = 0;
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### RIWAYAT JUAL EMAS ###\n");
	f_aems3 = fopen("list3.dat","rb");
	
	while(fread(&ems,sizeof(ems),1,f_aems3)==1){
		if(strcmp(ems.nama,r.nama)==0){
			printf("\nNama    : %s",ems.nama);
			printf("\nTanggal : %s",ems.tgl1);
			printf("\nAnda Telah Menjual %d(gram) Emas Dengan Harga %d\n",ems.brt2,ems.hasil2);
			v = v + ems.brt2;
		}
	}
	printf("\nTotal Emas yang Dijual : %d(gram)\n",v);
	fclose(f_aems3); system("pause"); Emas();
}

void Admin(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### LOGIN ADMIN ###\n");
	printf("\nUsername :"); fflush(stdin); gets(uadmin);
	printf("Password  :"); gets(padmin);
	if(strcmp(uadmin,"admin")==0 && strcmp(padmin,"123")==0){
		printf("\nSelamat Datang\n");  system("pause"); Piladmin();
	} else printf("\nMaaf Coba Lagi\n"); system("pause"); main();
}

void Piladmin(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### MENU ADMIN ###\n");
	printf("===Pilihan Menu Admin===\n");
	printf("1. Input Harga Emas\n");
	printf("2. Melihat User yang Deposito\n");
	printf("3. Melihat User yang Menabung Emas\n");
	printf("4. Kembali Ke-Menu Utama\n");
	printf("\nPilih Menu :"); scanf("%d",&z);
	switch(z){
		case 1: Jemas(); break;
		case 2: Ldepo(); break;
		case 3: Lemas(); break;
		case 4:	main(); break;
	}
	
}
	
void Jemas(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### INPUT DATA EMAS ###\n");
	f_aems = fopen("list.dat", "wb");
	printf("\nTanggal "); fflush(stdin); gets(ems.tgl1);
	printf("\nHarga Emas per 1 Gram : "); scanf("%d",&ems.hrg);  
	printf("\nHarga Jual Emas per 1 Gram : "); scanf("%d",&ems.harga); getchar();
	printf("\nHarga Emas Sudah Tersimpan\n");
	fwrite(&ems,sizeof(ems),1,f_aems);
	
	fclose(f_aems);	
	system("pause"); Piladmin();
}

void Ldepo(){
	system("cls");
	printf("\t\t\t\t\t\t### DATA DEPOSITO ###\n");
	f_nabung = fopen("simpanan.dat", "rb");
	while(fread(&tabung,sizeof(tabung),1,f_nabung)==1){
		strcpy(temp[i].nama,tabung.nama);
		strcpy(temp[i].tgl,tabung.tgl);
		temp[i].k=tabung.k;
		temp[i].c=tabung.c;
		temp[i].uang=tabung.uang;
		i++;
		d=i;
	} fclose(f_nabung); fgs();
}

void fgs(){
	int h=0;
	i=0;j=0;
	for(i=d-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if (strcmp(temp[j-1].nama,temp[j].nama)>0){
  				strcpy(temp2,temp[j-1].nama); 
  				strcpy(temp[j-1].nama,temp[j].nama);
  				strcpy(temp[j].nama,temp2);
  				
  				strcpy(temp2,temp[j-1].tgl); 
  				strcpy(temp[j-1].tgl,temp[j].tgl);
  				strcpy(temp[j].tgl,temp2);
  				
  				temp4=temp[j-1].k;
  				temp[j-1].k=temp[j].k;
  				temp[j].k=temp4;
  				
  				temp4=temp[j-1].c;
  				temp[j-1].c=temp[j].c;
  				temp[j].c=temp4;
  				
  				temp4=temp[j-1].k;
  				temp[j-1].uang=temp[j].uang;
  				temp[j].uang=temp4;
  			}
		}	
	}
	for(i=0;i<d;i++){
		printf("\n%d. Nama         : %s\n",i+1,temp[i].nama);
		printf("Tanggal         : %s\n",temp[i].tgl);
		printf("Jangka Waktu    : %d\n",temp[i].c);
		printf("Deposit         : %d\n",temp[i].k);
		printf("Deposit + Bunga : %d\n",temp[i].uang);
		h = h + temp[i].uang;
	}
	printf("\nTotal Uang : %d\n",h);
	system("pause"); Piladmin();
}	
	
void Lemas(){
	system("cls");
	printf("\t\t\t\t\t\t### DATA EMAS ###\n");
	f_aems2 = fopen("list2.dat", "rb");
	while(fread(&ems,sizeof(ems),1,f_aems2)==1){
		strcpy(temp1[i].nama,ems.nama);
		temp1[i].brt = ems.brt;
		i++;
		v=i;
	} fclose(f_aems2);
		
	i=0;j=0;
	for(i=v-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if (strcmp(temp1[j-1].nama,temp1[j].nama)>0){
  				strcpy(temp3,temp1[j-1].nama); 
  				strcpy(temp1[j-1].nama,temp1[j].nama);
  				strcpy(temp1[j].nama,temp3);
  				
  				temp5 = temp1[j-1].brt;
  				temp1[j-1].brt = temp1[j].brt;
  				temp1[j].brt = temp5;	
  			}
		}	
	}
	for(i=0;i<v;i++){
		printf("\n%d. Nama          : %s\n",i+1,temp1[i].nama);
		printf("Emas yang Dibeli : %d(gram)\n",temp1[i].brt);
	} searching();

}	

void searching(){
	int s=0;
	f_aems2 = fopen("list2.dat","rb");
	printf("\nNama yang Ingin Dicari :"); fflush(stdin); gets(search); 
	while(fread(&ems,sizeof(ems),1,f_aems2)==1){
		while ((i<=o-1) && (strcmp(ems.nama,search)!=0))
        i=i+1;
   	 	if (strcmp(ems.nama,search)==0){
        	printf("\nNama      : %s\n",search);
			printf("Berat Emas : %d(gram)\n",ems.brt);  
			s = s + ems.brt;  
    	}
	}
	printf("\nTotal Emas Nasabah : %d(gram)\n",s);
	system("pause"); fclose(f_aems2); Piladmin();

}	

void Exit(){
	system("cls");
	cover();
	printf("\n\t\t\t\t\t\t### SAMPAI JUMPA ###\n\n\n\t\t\t\t\t\t    TERIMA KASIH \n\n\n\n\n\n");	
	system("exit");
}

void cover(){
	system("cls");
	printf("\n  				DDDDDD    '''  SSSSS    AAA    VV       VV  EEEEEEE    ");
	printf("\n  				DD   DD   ''' SS      AA   AA   VV     VV   EE         ");
	printf("\n  				DD   DD   '''  SSS    AAaaaAA    VV   VV    EEEEEEE    ");
	printf("\n  				DD   DD         SSS   AA   AA     VV VV     EEEEEEE    ");
	printf("\n  				DD   DD           SS  AA   AA      VVV      EE         ");
	printf("\n  				DDDDDD        SSSSS   AA   AA       V       EEEEEEE    ");
	printf("\n\n\t\t         ================================================================");
}
