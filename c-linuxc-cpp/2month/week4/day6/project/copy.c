#include "head.h"

bool copydir(struct tpool *pool,char *src,char *dst,struct stat *info)
{
	if(access(dst,F_OK))
	{
		mkdir(dst,info->st_mode);
	}
	
	struct stat *fileinfo = (struct stat *)malloc(sizeof(struct stat));
	stat(dst,fileinfo);
	
	if(!S_ISDIR(fileinfo->st_mode))
	{
		printf("%s Not a directory!\n",dst);
		return false;
	}

	char src_path[50],dst_path[50],ori_path[50];
	
	bzero(ori_path,50);
	getcwd(ori_path,50); 
	
	chdir(src);           
	bzero(src_path,50);
	getcwd(src_path,50);
	
	chdir(ori_path);        
	chdir(dst);               
	bzero(dst_path,50);      
	getcwd(dst_path,50);
		
	DIR *dp = opendir(src_path);
	
	chdir(src_path);
	
	struct dirent *ep = NULL;
	
	while(1)
	{
		ep = readdir(dp);
		
		if(ep == NULL)
			break;
		
		if(strcmp(ep->d_name,".") == 0 ||
		   strcmp(ep->d_name,"..") == 0)
		   continue;
		   
		bzero(fileinfo,sizeof(struct stat));
		
		chdir(src_path);
		
		stat(ep->d_name,fileinfo);
		 
		if(S_ISREG(fileinfo->st_mode))
		{
			int *fd = calloc(2, sizeof(int));
				
			fd[0] = open(ep->d_name, O_RDONLY);
	
			chdir(dst_path);  
			fd[1] = open(ep->d_name, O_WRONLY|O_CREAT|O_TRUNC,fileinfo->st_mode);
						
			add_task(pool,mytask,(void *)fd); 	
		}
		
		if(S_ISDIR(fileinfo->st_mode))
		{
			chdir(dst_path);    
			mkdir(ep->d_name,fileinfo->st_mode);
			chdir(ep->d_name);
			
			char new_path[50];
			getcwd(new_path,50);
			
			chdir(src_path);
			copydir(pool,ep->d_name,new_path,fileinfo);
		}		
	}
}

void copyfile(int src,int dst)
{
	char buf[1024];
	int r_num;
	
	while(1)
	{
		r_num = read(src,buf,1024);
		
		if(r_num <= 0)
			break;
		
		write(dst,buf,r_num);
	}
	
	return;
}

void *mytask(void *arg)
{
	int *fd = (int *)arg;
	
	copyfile(fd[0],fd[1]);
}

int main(int argc,char *argv[]) // ./copy file1 file2   ||  ./copy dir1 dir2  || ./copy file dir/
{
	umask(0000);
	if(argc != 3)
	{
		printf("argc error!\n");
		exit(0);
	}
	
	struct tpool *pool = malloc(sizeof(struct tpool));
	
	init_pool(pool,20);
	
	struct stat *fileinfo = malloc(sizeof(struct stat));
	stat(argv[1],fileinfo);

	struct stat *dstfileinfo = malloc(sizeof(struct stat));
	stat(argv[2],dstfileinfo);
	
	if(S_ISREG(fileinfo->st_mode) && !S_ISDIR(dstfileinfo->st_mode))
	{
		
		int *fd = calloc(2, sizeof(int));
		
		fd[0] = open(argv[1],O_RDONLY);
		
		fd[1] = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,fileinfo->st_mode);	
		
		if(fd[0] == -1 || fd[1] == -1)
		{
			exit(0);		
		}
		
		add_task(pool,mytask,(void *)fd);
	}
	
	if(S_ISREG(fileinfo->st_mode) && S_ISDIR(dstfileinfo->st_mode))
	{
		int *fd = calloc(2, sizeof(int));
		
		fd[0] = open(argv[1],O_RDONLY);
		
		chdir(argv[2]);
		fd[1] = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,fileinfo->st_mode);
		
		if(fd[0] == -1 || fd[1] == -1)
		{
			exit(0);		
		}
		
		add_task(pool,mytask,(void *)fd);
	}
	
	if(S_ISDIR(fileinfo->st_mode))
	{
		copydir(pool,argv[1],argv[2],fileinfo);
	}
	
	destroy_pool(pool);
	
	return 0;
}