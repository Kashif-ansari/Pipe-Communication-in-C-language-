#include <stdio.h>
#include <unistd.h>



int main(){
char pipe1writemessage[10];
char pipe2writemessage[10];
int p1[2],p2[2],returnstatus1,returnstatus2,pid, sum;
char readmessage[10];
int temp;
int num1;
returnstatus1 = pipe(p1);
if (returnstatus1 == -1){
printf("Unable to create pipe\n");
return 1;
}
returnstatus2 = pipe(p2);
if (returnstatus2 == -1){
printf("Unable to create pipe\n");
return 1;
}
printf("Enter the number : ");
scanf("%d\n",&num1);
pid = fork();
if (pid !=0){
close(p1[0]);
close(p2[1]);
printf("In parent: writeto pipe 1 - Message is %d\n",num1);
pipe1writemessage = char(num1);
write(p1[1],pipe1writemessage,sizeof(pipe1writemessage));
for (int i = 0; i < 3; i++){
read(p2[0],readmessage,sizeof(readmessage));
temp = int(readmessage);
sum += temp;}
printf("In Parent: Reading from pipe 2 - Messsage is %d\n",readmessage);
printf("Sum of numbers = %d", sum);
}
else{
close(p1[1]);
close(p2[0]);
read(p1[0],readmessage,sizeof(readmessage));
printf("In Child: reading from pipe 1 - Message is %s\n",readmessage);
num2 = int(readmessage);
for (int i = 0; i < 3; i++){
temp = num2 % 10;
num2 /= 10;
printf("In Child: writing to from pipe 2 - Messsage is %d\n",temp);
pipe2writemessage = char(temp);
write(p2[1],pipe2writemessage,sizeof(pipe2writemessage));
}

}
return 0; }