#include <cstdlib>
#include <iostream>

using namespace std;



int main()
{
    char conector_1;
    char conector_2;
    char conector_3;
    char conector_4;
    char conector_relacion;
    int p, q, r, s, t, u;
    bool valorV_1, valorV_2, valorV_3, valorV_4, res;
    cout << "El programa evaluara el valor de verdad de la siguiente proposicion: (p _ q _ r) _ (s _ t _ u)" << endl;
    cout << "Ingrese los conectores logicos que desea utilizar para conectar las proposiciones (Y para AND, O para OR)" << endl;

    do {
        cout << "1. p _ q :";
        cin >> conector_1;
        if (conector_1 != 'O' && conector_1 != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_1 != 'O' && conector_1 != 'Y');

    do {
        cout << "2. q _ r :";
        cin >> conector_2;
        if (conector_2 != 'O' && conector_2 != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_2 != 'O' && conector_2 != 'Y');

    do {
        cout << "3. (p " << conector_1 << " q " << conector_2 << " r) _ (s _ t _ u): ";
        cin >> conector_relacion;
        if (conector_relacion != 'O' && conector_relacion != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_relacion != 'O' && conector_relacion != 'Y');

    do {
        cout << "4. s _ t :";
        cin >> conector_3;
        if (conector_3 != 'O' && conector_3 != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_3 != 'O' && conector_3 != 'Y');

    do {
        cout << "5. t _ u :";
        cin >> conector_4;
        if (conector_4 != 'O' && conector_4 != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_4 != 'O' && conector_4 != 'Y');

    

    do {
        
        cin >> conector_relacion;
        if (conector_relacion != 'O' && conector_relacion != 'Y') {
            cout << "Por favor vuelva a ingresar el conector." << endl;
        }
    }
    while (conector_relacion != 'O' && conector_relacion != 'Y');
    cout<< endl;

    cout << "Proposicion compuesta total: "<< "(p " << conector_1 << " q " << conector_2 << " r ) " << conector_relacion << " (s " << conector_3 << " t " << conector_4 << " u)" <<endl <<endl;

    cout << "Ingrese los valores de verdad de cada una de las proposiciones." << endl;
    

    do {
        cout << "Ingrese p:";
        cin >> p;
        if ( (p != 0) && (p != 1) ){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ( (p != 0) && (p != 1) );
    do {
        cout << "Ingrese q:";
        cin >> q;
        if ((q != 0) && (q != 1)){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ((q != 1) && (q != 0));
    do {
        cout << "Ingrese r:";
        cin >> r;
        if ((r != 0) && (r !=1)){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ((r != 1) && (r != 0));
    do {
        cout << "Ingrese s:";
        cin >> s;
        if ((s != 0) && (s != 1)){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ((s != 1) && (s != 0));
    do {
        cout << "Ingrese t:";
        cin >> t;
        if ( (t != 0) && (t !=1) ){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ((t != 1) && (t != 0) );
    do {
        cout << "Ingrese u:";
        cin >> u;
        if ((u != 0) && (u !=1) ){
            cout << "Por favor reingrese el valor de verdad de la proposicion anterior. (0 - F, 1 - V)" << endl;
        }
    } while ((u != 1) && (u != 0) );

    if(conector_2 == 'Y' && conector_1 != 'Y') { 
        valorV_1 = (q && r);
        valorV_2 = (valorV_1 || p);
    }
    else { 
        switch (conector_1) {
            case 'O' : 
                valorV_1= (p || q);
                break;
            case 'Y' :
                valorV_1= (p && q);
                break;
           }
        valorV_2 = (valorV_1 || r);
    }

    if(conector_4 == 'Y' && conector_3 != 'Y') {
        valorV_3 = (t && u);  
        valorV_4 = (valorV_3 || s);
    }
    else { 
        switch (conector_3) {
            case 'O' : 
                valorV_3= (s || t);
                break;
            case 'Y' : 
                valorV_3= (s && t);
                break;
            }
            valorV_4 = (valorV_3 || u);
    }

    switch (conector_relacion) {
        case 'O':
            res = (valorV_2 || valorV_4);
            break;
        case 'Y':
            res = (valorV_2 && valorV_4);
            break;
    }

    cout << "Resultado final: " << endl;
    cout << "(" << p << " " << conector_1 << " " << q << " " << conector_2 << " " << r << ")" << " " << conector_relacion 
         << " "  << "(" << s << " " << conector_3 << " " << t << " " << conector_4 << " " << u << ")" << endl;
    cout << " \t" << valorV_2 << "\t" << conector_relacion << "\t" << valorV_4;

    cout << endl << endl << "El valor de verdad de la proposicion es";
    if (res == 0) {
        cout << " FALSO" << endl;
    }
    else {
        cout<< " VERDADERO" << endl;
    }
    return 0;
}