/*  Programma gestione dei dipendenti*/

#include <stdio.h>
#include <stdbool.h>


//*enum per tipo di dipendente
typedef enum  { dirigente, quadro, operaio, impiegato} ruolo_dip;

//* struttura del dipendente
typedef struct{
    int id;
    int age;
    float salary;
    int ruolo_dip; 
} dip;

int main(){
    int j = 0, i = 0, t = 0;
    int N;
    int id, age,ruolo_dip;
    float salary;
    float media = 0;

    dip dipendenti[6];   //*crea lista dipendenti
    
    //*inserisce in lista i dipendenti
    for(t = 0; t < 6; t++){
        //*controlla univocita' dell'id e lo inizializza
        bool univ = false;
        do{
            
            printf("Inserire id dipendente: ");
            scanf("%d", &id);
            for(i = 0; i < t; i++){
                if (dipendenti[i].id == id){
                    printf("Id non valido! deve essere univoco.\n");
                    univ = true;
                    break;
                }
            }
            if(univ != true){
                break;
            }
        } while(univ == true);
        dipendenti[t].id = id; 

        //*chiede age del dipendente
        printf("Inserire eta' del dipendente: ");
        scanf("%d", &age);
        dipendenti[t].age = age; 
        
        //*chiede stipendio del dipendente
        printf("Inserire stipendio del dipendente: ");
        scanf("%f", &salary);
        dipendenti[t].salary = salary;

        //*chiede tipo di dipendente
        printf("Inserire tipologia del dipendente: ");
        scanf("%d", &ruolo_dip);
        dipendenti[t].ruolo_dip = ruolo_dip;

        media += salary;
    }
    
    //*media degli stipendi
    media /= 6;

    //* calcolo media degli stipendi
    for(i = 0; i < 6; i++){
        if(dipendenti[i].salary < media){
            printf("%d %d ", dipendenti[i].id, dipendenti[i].age);
            switch(dipendenti[i].ruolo_dip){
                case dirigente:
                    printf("dirigente\n");
                    break; 
                case quadro:
                    printf("quadro\n");
                    break; 
                case operaio:
                    printf("operaio\n");
                    break; 
                case impiegato:
                    printf("impiegato\n");
                    break; 
            }
        }
    }
    return 0;
}