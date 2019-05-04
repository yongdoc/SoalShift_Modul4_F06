# SoalShift_Modul4_F06
## Permintaan 1

Caesar chiper dengan menggunakan key=17 dan urutan karakter

```qE1~ YMUR2"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\8s;g<{3.u*W-0```

fungsi caesar chiper dituliskan pada get_attr, readdir, dan read.
```
if(!(strcmp(".",path)==0||strcmp("..",path)==0)){
	strcpy(isi,path);
	for(j=0;j<(int)strlen(isi);j++){
		for(i=0;i<(int)strlen(temp);i++){
			if(temp[i]==isi[j]){
				if(i-key>=0){
					isi[j]=temp[i-key];
				}else {
					isi[j]=temp[i+(int)strlen(temp)-key];
				}
				break;
			}
		}
	}
}
```
dengan terdapat array of char yang menyimpan urutan karakter.

## Permintaan 2
File File video yang terpisah harus tergabung dan dimasukkan ke dalam folder "Videos". lalu diminta untuk men-join file file "computer.mkv.001,computer.mkv.002" menjadi computer.mkv dan telah terjain di dalam root folder fuse. untuk mengantisipasi folder yang mengandung banyak file maka diminta untuk menggunakan 1thread/proses(fork) baru untuk menggabungkan file. lalu diminta saat melakukan unmount diminta untuk menghapus semua file pada folder "Videos" dan menghapus folder "Videos"

## Permintaan 3
Atta diminta untuk membuat aturan pada file system untuk menghapus "file bahaya" dari hacker LAPTOP_RUSAK yang menanamkan user "chipset" dan "ic_controller" serta group "rusak" yang tidak dapat dihapus.
jadi Atta menyimpan nama file,group ID,owner ID dan waktu terakhir diakses file system tersebut dalam file "filemiris.txt." yang akan menghapus file "bahaya" serta mencegah  serangan lanjutan dari LAPTOP_RUSAK.

## Permintaan 4
Diminta pada folder YOUTUBER untuk membuat permission folder yang akan otomatis menjadi 750. pada saat yang sama juga ketika membuat file permission akan otomatis menjadi 640 dan ditambah ekstensi file ".iz1". File dengan ekstensi ".iz1" tidak dapat diubah permissionnya dan memunculkan error bertuliskan "file ekstensi iz1 tidak boleh diubah permissionnya"

## Permintaan 5
Diminta saat mengedit suatu file dan melakukan save maka akan terbuat folder baru yaitu Backup, kemudian hasil disimpan dengan folder namafile_[timestamp].ekstensi. setelah dihapus dibuat lagi folder baru bernama RecycleBin. lalu menghapus semua file dan di zip dengan nama namafile_deleted_[timestamp].zip lalu ditempatkan di folder RecycleBin. dengan format [timestamp] adalah yyyy-MM-dd_HH:mm:ss

dengan catatan:
Semua nama file dan folder yang terdapat pada soal harus memenuhi syarat soal no. 1 (terenkripsi saat belum di-mount dan terdekripsi saat di-mount)
Tidak diperkenankan menggunakan system() dan exec*(), kecuali ada pengecualian di butir soal.
Untuk soal nomor 3 diharapkan secara manual membuat user dan group-nya. Pengecekan file dilakukan setiap membuka direktori.
Untuk soal nomor 4 dan 5 diperbolehkan menggunakan exec*().
Pengerjaan hanya dilakukan dalam 1 file program C dengan format nama AFSHiaAP_[Kelompok].c . 
File System AFSHiaAP mengarah ke folder /home/[user]/shift4.
