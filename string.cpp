#include "string.h"

void strcrear (string &s){
    s = new char[1];
    s[0] = '\0';
}

void strDestruir (string &s){
    delete [] s;
    s = NULL;
}

int strlar (string s){
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}

void strcop (string &s1, string s2){
    int largo = strlar(s2)+1;
    delete [] s1;
    s1 = new char[largo];

    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan (string &s){
    string aux = new char[MAX];
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c", &c);
    while (c != '\n' && i < MAX){
        aux[i] = c;
        i++;
        scanf("%c",&c);
    }
    aux[i] = '\0';

    strcop(s, aux);
    delete [] aux;
}

void strcon (string &s1, string s2){
    int lar = strlar(s1)+strlar(s2)+1;
    string aux = new char[lar];
    int i = 0, j = 0;
    while (i < MAX-1 && s1[i] != '\0'){
        aux[i] = s1[i];
        i++;
    }
    while (i < MAX-1 && s2[j] != '\0'){
        aux[i] = s2[j];
        j++;
        i++;
    }
    aux[i] = '\0';
    strcop(s1,aux);
    delete [] aux;
}


void strswp (string &s1, string &s2){
    string aux1,aux2;
    int lar1 = strlar(s1);
    aux1 = new char[lar1];
    strcop(aux1,s1);
    int lar2 = strlar(s2);
    aux2 = new char[lar2];
    strcop(aux1,s1);
    strcop(aux2,s2);
    strcop(s1,aux2);
    strcop(s2,aux1);
}


void print (string s){
    int i=0;
    printf("\n %s", s);
    while(s[i] != '\0'){
        printf("%c",s[i]);
        i++;
    }
}

boolean strmen (string s1, string s2){
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0')){
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

boolean streq(string s1,string s2) {
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}
