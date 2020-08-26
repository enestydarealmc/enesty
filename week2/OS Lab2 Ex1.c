#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){		
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("INT_MAX:\nValue: %d\nSize: %ld\n\n\n",i,sizeof(i));
	printf("FLT_MAX:\nValue: %f\nSize: %ld\n\n\n",f,sizeof(f));
	printf("DLB_MAX:\nValue: %lf\nSize: %ld",d,sizeof(d));
	return 0;
}
