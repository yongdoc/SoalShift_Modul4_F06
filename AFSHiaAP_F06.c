#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <grp.h>
#include <pwd.h>

static const char *dirpath = "/home/yong/shift4";
int key=17;

//get attribute
static int xmp_getattr(const char *path, struct stat *stbuf)
{
  int res,i,j;
	char fpath[1000];
	char isi[1000];
	if(!(strcmp(".",path)==0||strcmp("..",path)==0)){
		strcpy(isi,path);
		char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath,"%s%s",dirpath,isi);
		res = lstat(fpath, stbuf);
		if (res == -1)
			return -errno;
	}
	return 0;
}

//read directory
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
  char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {
		int i,j;
		char isi[1000];
		if(!(strcmp(".",isi)==0||strcmp("..",isi)==0)){
			strcpy(isi,path);
			char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath, "%s%s",dirpath,isi);
	}
	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		char isi[100];
		int i,j;
		strcpy(isi,de->d_name);
		if(!(strcmp(".",isi)==0||strcmp("..",isi)==0)){
			struct stat st;
			int mode=st.st_mode&S_IRWXO;
			struct passwd *usrname;
			struct group *grpname;
			usrname = getpwuid(st.st_uid);
			grpname = getgrgid(st.st_gid);
			if(mode<4&&!((strcmp("chipset",usrname->pw_name)&&strcmp("ic_controller",usrname->pw_name))||strcmp("rusak",grpname->gr_name))){
				FILE *open = NULL;
				time_t t1=st.st_atime;
				struct tm *tinfo;
				char t[30],simpan[1000];
				char file[]="filemiris.txt";
				int i,j;
				if(!(strcmp(".",file)==0||strcmp("..",file)==0)){
					char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
					for(j=0;j<(int)strlen(file);j++){
						for(i=0;i<(int)strlen(temp);i++){
							if(temp[i]==file[j]){
								if(i-key>=0){
									file[j]=temp[i-key];
								}else {
									file[j]=temp[i+(int)strlen(temp)-key];
								}
								break;
							}
						}
					}
				}
				tinfo=localtime(&t1);
				strftime(t,30,"%H:%M:S %d-%m-%Y",tinfo);
				char input[1000];
				snprintf(input,(int)strlen(input),"%s. Accessed on : %s",de->d_name,t);
				snprintf(simpan,1000,"%s%s",dirpath,file);
				open=fopen(simpan,"a");
				if(open!=NULL){
					fputs(simpan,open);
					fclose(open);
				}
				remove(fpath);
			}else {
				char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
				for(j=0;j<(int)strlen(isi);j++){
					for(i=0;i<(int)strlen(temp);i++){
						if(temp[i]==isi[j]){
							if(i+key<=(int)strlen(temp)-1){
								isi[j]=temp[i+key];
							}else {
								isi[j]=temp[i-(int)strlen(temp)+key];
							}
							break;
						}
					}
				}
				memset(&st, 0, sizeof(st));
				st.st_ino = de->d_ino;
				st.st_mode = de->d_type << 12;
				// res = (filler(buf, de->d_name, &st, 0));
				res = (filler(buf, isi, &st, 0));
				if(res!=0) break;
			}
		}
	}

	closedir(dp);
	return 0;
}

//read
static int xmp_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
  char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {
		int i,j;
		char isi[1000];
		if(!(strcmp(".",isi)==0||strcmp("..",isi)==0)){
			strcpy(isi,path);
			char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath, "%s%s",dirpath,isi);
	}
	int res = 0;
  int fd = 0 ;
	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

//make node
static int xmp_mknod (const char *path, mode_t mode, dev_t rdev){
	char fpath[1000];
	int res,i,j;
	char isi[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}else {
		strcpy(isi,path);
		char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath,"%s%s",dirpath,isi);
	}
	if(strstr(fpath,"YOUTUBER")){
		strcat(fpath,".z1");
		res=mknod(fpath,640,rdev);
	}else {
		res=mknod(fpath,mode,rdev);
	}
	if(res==-1){
		return -errno;
	}
	return 0;
}


//make directory
static int xmp_mkdir (const char *path, mode_t mode){
	int res,i,j;
	char isi[1000],fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}else {
		strcpy(isi,path);
		char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath,"%s%s",dirpath,isi);
	}
	if(strstr(fpath,"YOUTUBER")){
		mode = 750;
	}
	res=mkdir(fpath,mode);
	if(res == -1)
			return -errno;
	return 0;
}

//change mode
static int xmp_chmod (const char *path, mode_t mode){
	int res,i,j;
	char isi[1000],fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}else {
		strcpy(isi,path);
		char temp[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
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
		sprintf(fpath,"%s%s",dirpath,isi);
	}
	int t=(int)strlen(fpath);
	if(!(isi[t-1]=='1'&&isi[t-2]=='z'&&isi[t-3]=='i'&&isi[t-4]=='.')){
		res = chmod(fpath, mode);
		if(res == -1)
			return -errno;
	}
	return 0;
}

static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.read		= xmp_read,
	.mkdir = xmp_mkdir,
	.mknod = xmp_mknod,
	.chmod = xmp_chmod,
};

int main(int argc, char *argv[])
{
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}