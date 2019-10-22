#include<stdio.h>
#include<ctype.h>
#include <string.h> 
#include<stdlib.h>
char stack[20];
int top = -1;
char out[20];
int i=0;
void push(char x){
    stack[++top] = x; 
    }
 
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
} 
int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main(){
    system("clear");
    char exp[20];
    char *e, x, y, z;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e)){
            out[i]=*e;
            i++;
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            while((x = pop()) != '('){
                out[i]=x;
                i++;
            }
        }
        else{
            while(priority(stack[top]) >= priority(*e)){
                x=pop();
                out[i]=x;
                i++;
                }
            push(*e);
        }
        e++;
    }
    while(top != -1){
        x=pop();
        out[i]=x;
        i++;
    }
    puts(out);
    e = out;
    int j=1;
    
    printf("op\top1\top2\tresult\n------------------------------\n");
    while(*e != '\0'){
        x=*(e+2);
        z=*(e+1);
        y=*e;
        if(x=='+' || x=='-' || x=='*' || x=='/'){
            printf("%c\t%c\t%c\tt%d\n",x,y,z,j);
            e=e+3;j++;
        }
        else if(y=='+' || y=='-' || y=='*' || y=='/'){
            printf("%c\tt%d\tt%d\tt%d\n",y,j-2,j-1,j);
            e=e+1;j++;
        }
        else{
            printf("%c\tt%d\t%c\tt%d\n",z,j-1,y,j);
            e=e+2;j++;
        }
    }

}