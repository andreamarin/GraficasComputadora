#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::malloc;
using std::free;

typedef struct lst{
    int val;
    struct lst *apt;
}LISTA;

void imprimir(LISTA *inicio){
    LISTA *aux;
    aux = inicio;

    while(aux != NULL){
        cout << aux->val << "\n";
        aux = aux->apt;
    }
}

void agregar(LISTA *&inicio, int nuevo){
    LISTA *e;
    e = (LISTA*) malloc(sizeof(LISTA));
    e -> val = nuevo;

    if(inicio == NULL){ 
        e -> apt = NULL;
        inicio = e;
    }

    if(inicio -> val > nuevo){
        e -> apt = inicio;
        inicio = e;
    }else{
        LISTA *act , *ant;
        act = inicio -> apt;
        ant = inicio;
        int flag = 0;
        
        while (act != NULL &&  flag == 0){
            if (act -> val > nuevo){
                ant -> apt = e;
                e -> apt = act;
                flag = 1;
            }else{
                ant = act;
                act = act -> apt;
            }
        }

        if (flag == 0){
            ant -> apt = e;
            e->apt = NULL;
        } 
    } 
}

void eliminar(LISTA *&inicio, int valor){
    LISTA *aux, *ant;

    if (valor == inicio -> val){
        aux = inicio -> apt;
        free(inicio);
        inicio =  aux;
    }else{
        aux = inicio -> apt;
        ant = inicio;
        int flag = 0;

        while(aux != NULL && flag == 0){
            if(aux -> val == valor){
                ant -> apt = aux -> apt;
                free(aux);
                flag = 1;
            }else{
                ant = aux;
                aux = aux -> apt;
            }
        }
    }
}

int main(){
    LISTA *init;
    init = (LISTA*) malloc(sizeof(LISTA));

    init = NULL;

    int resp, valor;

    do{
        cout << "\n¿Qué quieres hacer?: \n 1. Agregar \n 2. Eliminar \n 3. Imprimir lista\n 4. Salir\n";
        cin >> resp;

        switch (resp){
            case 1:
                cout << "Dame valor a agregar: ";
                cin >> valor;
                agregar(init, valor);
                break;

            case 2:
                cout << "¿Qué valor quieres eliminar? ";
                cin >> valor;
                eliminar(init, valor);
                break;

            case 3:
                cout << "\nLista: \n";
                imprimir(init);
                break;

            case 4: 
                cout << "\nLista final: \n";
                imprimir (init);
                break;
            
            default:
                cout << "Opción no válida \n";
                break;
        }
    }while(resp != 4);

    return 0;
}