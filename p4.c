#include<stdio.h>
#include<stdlib.h>
void main(){
	int nState,nFinal,nInput,n,i,j,x,flag=0;
	system("clear");
	//States
	puts("Enter No of States:");
	scanf("%d",&nState);
	int state[nState];
	puts("Enter States:");
	for(i=0;i<nState;i++){
		scanf("%d",&state[i]);
	}
	
	//FInal States
	puts("Enter No of Final States:");
	scanf("%d",&nFinal);
	int final[nFinal];
	puts("Enter Final States:");
	for(i=0;i<nFinal;i++){
		scanf("%d",&final[i]);
	}
	
	//Inputs
	puts("Enter No of inputs:");
	scanf("%d",&nInput);
	int input[nInput];
	puts("Enter Inputs:");
	for(i=0;i<nInput;i++){
		scanf("%d",&input[i]);
	}
	
	//Delta Table
	puts("Enter Transition Table Elements:");
	int delta[nState][nInput];
	for(i=0;i<nState;i++){
		for(j=0;j<nInput;j++){
			printf("Enter the Transition of State %d on input %d is : ",i,j);
			scanf("%d",&delta[i][j]);
		}
	}
	
	//Initial State
	puts("Enter initial state");
	scanf("%d",&x);
	
	//Input String
	puts("Enter input String length");
	scanf("%d",&n);
	int inp[n];
	puts("Enter input Strings");
	for(i=0;i<n;i++){
		scanf("%d",&inp[i]);
	}
	i=0;
	while(i<n){
		x=delta[x][inp[i]];
		i+=1;
	}
	for(i=0;i<nFinal;i++){
		if(x==final[i]){
			flag=1;
			break;
		}
	}
	if(flag==1){
		puts("\n-------------\nInput String is Accepted\n-------------");
	}
	else{
		puts("\n-------------\nInput String is Not Accepted\n-------------");
	}
}
