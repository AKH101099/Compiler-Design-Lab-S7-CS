#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int top=-1,i=0,j=1;
char stack[20];
void push(char x){
	stack[++top]=x;
}
int pop(){
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
int priority(char x){
	if(x=='(')
		return 0;
	else if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	return 0;
}
int main() {
	system("clear");
	char inp[20],out[20]="",*e,x,y,z,w;
	puts("ENter the string: ");
	scanf("%s",inp);
	e=inp;
	while(*e!='\0'){
		if(isalnum(*e)){
			out[i]=*e;i++;
		}
		else if(*e==')'){
			while((x=pop())!='('){
				out[i]=x;i++;
			}
		}
		else{
			while(priority(stack[top])>=priority(*e)){
				x=pop();
				out[i]=x;i++;
			}
			push(*e);
		}e++;
	}
	while(top!=-1){
		x=pop();
		out[i]=x;i++;	
	}
	puts(out);
	e=out;
	j=0;
	printf("\nopr\top1\top2\tres\n------------------------------\n");
	while(*e!='\0'){
		x=*e;
		y=*(e+1);
		z=*(e+2);
		w=*(e+3);
		if(z=='+' || z=='-' || z=='*' || z=='/'){
			printf("%c\t%c\t%c\tt%d\n",z,x,y,j);
			j++;e=e+3;
		}
		else if(y=='+' || y=='-' || y=='*' || y=='/'){
			printf("%c\tt%d\t%c\tt%d\n",y,j-1,x,j);
			j++;e=e+2;
		}
		else if(x=='+' || x=='-' || x=='*' || x=='/'){
			printf("%c\tt%d\tt%d\tt%d\n",x,j-2,j-1,j);
			j++;e=e+1;
		}
		else if(w=='+' || w=='-' || w=='*' || w=='/'){
			printf("%c\t%c\t%c\tt%d\n",*(e+4),x,y,j);
			j++;e=e+2;
			x=*e;
			y=*(e+1);
			z=*(e+2);
			w=*(e+3);
			printf("%c\t%c\t%c\tt%d\n",z,x,w,j);j++;
			printf("%c\tt%d\tt%d\tt%d\n",y,j-2,j-1,j);
			return 0;
		}
		else{
			printf("t%d\t%c\t%c\tt%d\n",j-1,x,y,j);
			j++;e=e+2;
		}
	}
}
