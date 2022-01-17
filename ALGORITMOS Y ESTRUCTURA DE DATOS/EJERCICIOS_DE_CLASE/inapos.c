#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Pila.h"

int EsMayuscula(Elem);
int EsMinuscula(Elem);
int EsDigito(Elem);
int EsOperando(Elem);
int EsParI(Elem);
int EsParD(Elem);
int EsOperador(Elem);
int Precedencia(Elem);
void inapos(Elem*);
Pila ProcParD(Pila);
Pila ProcOper(Pila, Elem);

int main(int argc, char *argv[]){
     inapos(argv[1]);
    
     return 0;
}

void inapos(Elem *c){
     int i=0;
     Pila ops=empty();

     while(c[i]){
        if(EsOperando(c[i]))
           ImpElem(c[i]);
        else if(EsParI(c[i]))
                ops=push(c[i],ops);
             else if(EsParD(c[i]))
                     ops=ProcParD(ops);
                  else if (EsOperador(c[i]))
                           ops=ProcOper(ops, c[i]);
         i++;
     }
     while(!isempty(ops)){
        ImpElem(top(ops));
        ops=pop(ops);
     }
 }
Pila ProcOper(Pila ops, Elem op){
    if(isempty(ops))
        ops=push(op,ops);
    else if(EsParI(top(ops)))
            ops=push(op,ops);
         else if(Precedencia(top(ops))<Precedencia(op))
                  ops=push(op,ops);
              else{
                   while((!isempty(ops))&&(Precedencia(top(ops))>=Precedencia(op))){
                        // if(!EsParI(top(ops)))
                         ImpElem(top(ops));
                         ops=pop(ops);
                   }
                   ops=push(op,ops);
                  }
    return ops;
}


int EsMayuscula(Elem c){ return ((c>='A')&&(c<='Z'));}
int EsMinuscula(Elem c){ return ((c>='a')&&(c<='z'));}
int EsDigito(Elem c){ return ((c>='0')&&(c<='9'));}
int EsOperando(Elem c){return (EsMayuscula(c)||EsMinuscula(c)||EsDigito(c));}
int EsParI(Elem c){return c=='(';};
int EsParD(Elem c){return c==')';};
int EsOperador(Elem c){return ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='^'));};
int Precedencia(Elem c){
    switch(c){
	   case '+': case '-': return 1;
	   case '*': case '/': return 2;
	   case '^': return 3;
	   case '(': return 0;
    }
}
Pila ProcParD(Pila ops){
   while(!EsParI(top(ops))){
       ImpElem(top(ops));
       ops=pop(ops);
   }
   ops=pop(ops);

   return ops;
}