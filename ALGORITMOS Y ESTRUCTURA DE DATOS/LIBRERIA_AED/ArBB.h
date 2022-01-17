/*
Espec ArBB
    Incluye todo lo de ArBin;
    InsOrdAB: Elem, ArBB -> ArBB;

//Axioma: Elem e, ArBin a;
    [Ab1] esvacioB(InsOrd(e,a)) = Falso;
    [Ab2] raiz(InsOrd(e,a)) =
            Si esvacioB(a)  Return e;
            Sino return raiz(a);
    [Ab3] izquierdoB(InsOrd(e,a)) = 
            SI esvacioB(a)  return e;
            Sino si(esmenor(e,raiz(a))) = return InsOrd(e,izquierdoB(a));
            Sino return izquierdoB(a);
    [Ab4] derechoB(InsOrd(e,a)) = 
            SI esvacioB(a)  return vacioB();
            Sino si(esmayor(e,raiz(a))) = return InsOrdAB(e,derechoB(a));
            Sino return derechoB(a);
*/
#include"ArBin.h"

typedef ArBin ArBB;

ArBB InsOrdAB(Elem e, ArBB a){
    if(esvacioB(a))
        return consB(e,vacioB(),vacioB());
    else if(EsMenorIgual(e,raiz(a)))
            return consB(raiz(a),InsOrdAB(e,izquierdoB(a)), derechoB(a));
        else
            return consB(raiz(a),izquierdoB(a),InsOrdAB(e,derechoB(a)));
}

//Solo funciona si EstaEn(e,a)==Cierto
ArBB Elimina(Elem e, ArBB a){
    if(EsIgual(e,raiz(a)))
        if(EsHoja(a))
            return vacioB();
        else if (esvacioB(derechoB(a)))
                return izquierdoB(a);
             else if(esvacioB(izquierdoB(a)))
                        return derechoB(a);
                  else
                     return consB(ElemMasDerechoB(izquierdoB(a)),Elimina(ElemMasDerechoB (izquierdoB(a)),izquierdoB(a)),derechoB(a));
    else if(EsMenorIgual(e,raiz(a)))
              return consB(raiz(a),Elimina(e,izquierdoB(a)),derechoB(a));
         else
              return consB(raiz(a),izquierdoB(a),Elimina(e,derechoB(a)));
}

int EstaEn(Elem e, ArBB a){
    if(esvacioB(a))
        return a!=NULL;
    else{
        if(raiz(a)==e)
            return raiz(a)==e;
        else if(raiz(a)>e)
            EstaEn(e,izquierdoB(a));
        else
            EstaEn(e,derechoB(a));
    }
}

//Implementacion del profe
/*
int EstaEn(Elem e, DicBin a){
    if(esvacioB(a))
        return 0;
    else if(EsIgual(e,raiz(a)))
             return 1;
         else
             return EstaEn(e,izquierdoB(a))||EstaEn(e,derechoB(a));
}*/