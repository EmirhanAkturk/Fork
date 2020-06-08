/* 
 Emirhan Aktürk
 parent process "a", child process "B" yazdırıyor
 Ekran çıktısı:aBaBaBaBaBaBaBaB
 şeklinde olan program 
 (Bilal Özcan ve Mehmet Afif Arsay'dan yardım aldım)
 */
 #include <stdio.h> 
 #include <stdlib.h>
 #include <unistd.h> 
 #include <sys/wait.h>
int main()
{     pid_t pid;
      pid=fork();// process çoğaltma
      wait(NULL);//child processleri bekle
      pid=fork();// process çoğaltma
      wait(NULL);//child processleri bekle
      pid=fork();// process çoğaltma
      wait(NULL);//child processleri bekle
      pid=fork();//child process'i beklemeyeceği için ilk "a" yazdırır
      
      if(pid<0)//fork negatif değer döndürürse başarısız olmuştur.
         {perror("Fork:"); exit(-1);}
         
      if(pid > 0)//paret ise ekrana "a" yazdırır
      {
         printf("a");
         fflush(stdout);//ekrana hemen yazdırması için
      }
      else if(pid == 0)// child ise ekrana "B" yazdırır
         {
            printf("B");
            fflush(stdout);//ekrana hemen yazdırması için
         }
   return 0;
}

