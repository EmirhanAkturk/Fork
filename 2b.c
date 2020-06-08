/*
Emirhan Aktürk
parent process "a', 1.child process "B" ve 2. child process "c" yazdırıyor
Ekran çıktısı:ccccccccccccccccaaaaaaaaaaaaaaaaBBBBBBBBBBBBBBBB
şeklinde olan program
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    pid_t pid,pid2;
    for (int i = 0; i < 5; ++i)
      pid=fork();

    if(pid>0)//parent ise 2.child'ı oluştur
        pid2=fork();

    if(pid<0||pid2<0)//fork başarısızsa programdan çık
        {perror("fork:"); exit(1);}
   if(pid>0 && pid2>0)//parent ise ekrana "a" yazdırır
        {sleep(1);//2. child'ın bitmesini bekliyor
        printf("a");}
    if(pid==0)//1.child ise ekrana "B" yazdırır
        {sleep(2);//2. child ve parent'ın bitmesini bekliyor
        printf("B");}
    if(pid2==0)//2.child ise ekrana "c" yazdırır
        printf("c");
    return 0;
}
