#include<stdio.h>
#include<ctype.h>
void push(char x);
char pop();
int top=0;
char stack[10];
int main()
{
char exp[10];
int opx,opy,i;
printf("Enter the Postfix Expression: ");
scanf("%s",exp);
for(i=0;exp[i]!='\0';i++)
	{
	if(isalpha(exp[i])!=0)
		push(exp[i]);
	else
		{
		switch(exp[i])
			{
			case '*':
				opx=pop();
				printf("MOV B,%c\n",opx);
				opy=pop();
				printf("MOV A,%c\n",opy);
				printf("MUL A,B\n");
				push('A');
				break;
			case '-':
				opx=pop();
				printf("MOV B,%c\n",opx);
				opy=pop();
				printf("MOV A,%c\n",opy);
				printf("SUB A,B\n");
				push('A');
				break;
			case '+':
				opx=pop();
				printf("MOV B,%c\n",opx);
				opy=pop();
				printf("MOV A,%c\n",opy);
				printf("ADD A,B\n");
				push('A');
				break;
			case '/':
				opx=pop();
				printf("MOV B,%c\n",opx);
				opy=pop();
				printf("MOV A,%c\n",opy);
				printf("DIV A,B\n");
				push('A');
				break;
			case '=':
				opx=pop();
				opy=pop();
				printf("MOV %c,%c\n",opy,opx);
				break;
			}
	
		}
	}
    return 0;
}
void push (char x)
{
stack[top]=x;
top++;
}
char pop()
{
char y=stack[top-1];
top--;
return y;
}