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

-

## Permintaan 3

-

## Permintaan 4

-

## Permintaan 5

-
