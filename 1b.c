 /* 
 Emirhan Aktürk
 
 parent process "a", child process "B" yazdırıyor
 Ekran çıktısı:BBBBBBBBBBBBBBBBaaaaaaaaaaaaaaaa
 şeklinde olan program 
 */
 #include <stdio.h> 
 #include <stdlib.h>
 #include <unistd.h> 
int main(){
   pid_t pid;
   for (int i = 0; i < 5; ++i)
      pid=fork();

   if(pid<0){//fork negatif değer döndürürse başarısız olmuştur
      perror("fork: "); exit(1);}
   if(pid>0) //parent childlerın bitmesini bekleyip ekrana "a" yazdırır
   {  sleep(1);//childların'ın bitmesini bekliyor
      printf("a");}
   else if(pid==0)//child ekrana "B" yazdırır
          printf("B");
   return 0;
}