#include <stdio.h>
#include<pthread.h>
#include <stdlib.h>
//using namespace std;

int num;


void* factorial()
{
int fac=1;
for(int a=1;a<=num;a++)
{
fac=fac*a;
//cout<<"Factorial of Given Number is ="<<fac;
printf("Hello from thread is %d\n", fac);
}
}


int main(){
	pthread_t* t;
	printf("El factorial del numero: ");
	//cin>>num;
	scanf("%d", &num);
	pthread_create(&t,NULL,factorial,(void*)&num);

	  /*pthread_create(&thread_handles[thread], NULL,
	Pth_mat_vect, (void*) thread);*/

	return 0;
}
