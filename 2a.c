/*
Emirhan Aktürk
parent process "a", 1.child process "B" ve 2. child process c yazdırıyor
Ekran çıktısı:aBcaBcaBcaBcaBcaBcaBc 
şeklinde olan program
(Hüseyin Yılmaz'dan yardım aldım.)
*/
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<unistd.h>
int main()
{
    for(int i = 0; i < 3; ++i)
    {
        pid_t pid,pid2;
        pid = fork();
        if(pid<0)//fork negatif değer döndürürse başarısız olmuştur.
         {perror("Fork:"); exit(-1);}
       
        if (pid == 0) //child1, child2'yi oluşturur ve ekrana "B" basar
        { 
            pid2 = fork();
            if(pid<0)//fork negatif değer döndürürse başarısız olmuştur.
            {perror("Fork:"); exit(-1);}   
            if (pid2 == 0) //child2 ekrana "c" basar
            { 
                printf("c");
                fflush(stdout);//ekrana hemen yazması için
            }
            else 
            {
                printf("B");
                fflush(stdout);//ekrana hemen yazması için
                wait(NULL);
            }
            } 
            else //parent ekrana a basar ve childlerın bitmesini bekler
            { 
                printf("a");
                fflush(stdout);//ekrana hemen yazması için
                wait(NULL);
                }
    }
    return 0;
}

    

