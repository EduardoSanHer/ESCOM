#include "ArBB.h"

typedef ArBB AVL;

/*
int Absoluto(int n){
     if(n>=0)
         return n;
     else
         return -n;
}
*/

int FactBal(ArBB a){ return AlturaAB(izquierdoB(a))-AlturaAB(derechoB(a));}

//Primera implementacion
/*
int EsAVL(ArBB a){
     return (esvacioB(a) || ((absoluto(FactBal(a))<=1)&&
                            (EsAVL(izquierdoB(a)))&&(EsAVL(derechoB(a)))));
}*/

//Segunda implementacion
int EsAVL(ArBB a){
    if(esvacioB(a))
        return 1;
    else
        return (Absoluto(AlturaAB(izquierdoB(a))-AlturaAB(derechoB(a)))<=1) && (EsAVL(izquierdoB(a))) && (EsAVL(derechoB(a)));
}

AVL RotaIzq(ArBB a){
     return consB(raiz(derechoB(a)),consB(raiz(a),izquierdoB(a),izquierdoB(derechoB(a))),derechoB(derechoB(a)));
}

AVL RotaDer(ArBB a){
     return consB(raiz(izquierdoB(a)),izquierdoB(izquierdoB(a)),consB(raiz(a),derechoB(izquierdoB(a)),derechoB(a)));
}
AVL RotaIzqDer(ArBB a){ return RotaIzq(consB(raiz(a),izquierdoB(a),RotaDer(derechoB(a))));}
AVL RotaDerIzq(ArBB a){ return RotaDer(consB(raiz(a),RotaIzq(izquierdoB(a)),derechoB(a)));}

AVL HazAVL(ArBB a){
    if(Absoluto(FactBal(a))>1)    // a no es AVL!!!
            if(EsAVL(izquierdoB(a)) && EsAVL(derechoB(a)))
                 if(FactBal(a)>1)
                      if(FactBal(izquierdoB(a))>0)
                           return RotaDer(a);
                      else
                           return RotaDerIzq(a);
                 else if(FactBal(derechoB(a))<0)
                            return RotaIzq(a);
                      else
                            return RotaIzqDer(a);
            else if(EsAVL(izquierdoB(a)))
                        return consB(raiz(a),izquierdoB(a),HazAVL(derechoB(a)));
                 else
                        return consB(raiz(a),HazAVL(izquierdoB(a)),derechoB(a));
    else if(EsAVL(izquierdoB(a)))
                        return consB(raiz(a),izquierdoB(a),HazAVL(derechoB(a)));
                 else
                        return consB(raiz(a),HazAVL(izquierdoB(a)),derechoB(a));
}

/*
//Tiene sus fallas
ArBB HazAVL(ArBB a){
    if(Absoluto(FactBal(a))>1){
        if(EsAVL(izquierdoB(a))&&EsAVL(derechoB(a))){
            if(FactBal(a)>1){
                if(FactBal(izquierdoB(a))>0)
                    return RotaDer(a);
                else
                    return RotaDerIzq(a);
            }
            else{
                if(FactBal(derechoB(a))<0)
                    return RotaIzq(a);
                else
                    return RotaIzqDer(a);
            }
        }
        else{
            if(EsAVL(izquierdoB(a)))
                return consB(raiz(a),izquierdoB(a),HazAVL(derechoB(a)));
            else
                return consB(raiz(a),HazAVL(izquierdoB(a)),derechoB(a));
        }
    }
    else{
        if(EsAVL(izquierdoB(a)))
            return consB(raiz(a),izquierdoB(a),HazAVL(derechoB(a)));
        else
            return consB(raiz(a),HazAVL(izquierdoB(a)),derechoB(a));
    }
}*/

AVL InsAVL(Elem e, AVL a){
    a=InsOrdAB(e,a);
    if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}

AVL EliminaAVL(Elem e, AVL a){
    a=Elimina(e,a);
    if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}