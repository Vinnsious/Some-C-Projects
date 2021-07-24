//Fé no pai que o C cai! ...now... i'm so hopeless...   
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct User {
    int role; //0 - Caixa || 1 - Gestor
    char password[255];
};

struct Item {
    int id;
    char name[255];
    float price;
    int total;
    int show; //0 || 1
};

struct Purchase {
    int itemId;
    float itemPrice;
    float total;
    int quantidade;
    char hour[255]; //HHMM
    char data[255];
    char name[255];
};

int chooseRole();
    struct User pickRole;
    printf("Entrar como (digite):\n1. Gestor\n2. Caixa\n");

int verifyId(int idProduct){
    int hasId = 0, i = 0;
    char stock[255];
    FILE *stockFile = fopen("estoque.txt", "r");
    while(fscanf(stockFile, "%s", stock) != EOF){
        if(i == 0 && atoi(stock) == idProduct) {
            hasId = 1;
            i++;
        }else if(i == 4){
            i = 0;
        }else{
            i++;
        }
    }
    return hasId;
}

void createItems(){
    FILE *createStockFile = fopen("estoque.txt", "a");
    struct Item itemCadastrado;
    printf("Insira o ID do produto:\n");
    scanf("%d", &itemCadastrado.id);
    if(!verifyId(itemCadastrado.id)){
        printf("Insira o nome do produto: ");
        scanf("%s", itemCadastrado.name);
        printf("Insira o preco do produto: ");
        scanf("%f", &itemCadastrado.price);
        printf("Insira a quantidade de produto: ");
        scanf("%d", &itemCadastrado.total);
        itemCadastrado.show = 1;
        fprintf(createStockFile, "%d %s %.2f %d %d\n", itemCadastrado.id, itemCadastrado.name, itemCadastrado.price, itemCadastrado.total, itemCadastrado.show);
    }else{
        printf("Essa identificacao de produto já existe\n");
    }

    fclose(createStockFile);
    return;
}

void listItems(){
    FILE *stockFile = fopen("estoque.txt", "r");
    char stock[255], id[255], name[255], price[255], total[255];
    int i = 0;
    while(fscanf(stockFile, "%s", stock) != EOF){
        if(i == 0){ 
            strcpy(id, stock);
            i++;
        }else if(i == 1){
            strcpy(name, stock);
            i++;
        }else if(i == 2){
            strcpy(price, stock);          
            i++;
        }else if(i == 3){
            strcpy(total, stock);               
            i++;
        }else if(i == 4){
            if(!(atoi(stock) == 0)){
                printf("%s %s %s %s\n", id, name, price, total);
            }
            i = 0;
        }
    }

    fclose(stockFile);
    return;
}

void editItems(){
    FILE *stockFile = fopen("estoque.txt", "r");
    struct Item itemEditado;
    printf("Informe o ID do produto: ");
    scanf("%d", &itemEditado.id);
    printf("Informe o novo nome: ");
    scanf("%s", itemEditado.name);
    printf("Informe o novo preco: ");
    scanf("%f", &itemEditado.price);
    printf("Informe a nova quantidade: ");
    scanf("%d", &itemEditado.total);
    FILE *temp = fopen("sartre.txt", "w");
    char stock[255];
    int i = 0, isProduct = 0;
    while(fscanf(stockFile, "%s", stock) != EOF){
        if(i == 0){
            int id = atoi(stock);
            if(id == itemEditado.id){
                fprintf(temp, "%d ", itemEditado.id);
                isProduct = 1;
            }else{
                fprintf(temp, "%s ", stock);
            }
            i++;
        }else if(i == 1 && isProduct == 1){
            fprintf(temp, "%s ", itemEditado.name);
            i++;
        }else if(i == 2 && isProduct == 1){
            fprintf(temp, "%.2f ", itemEditado.price);
            i++;
        }else if(i == 3 && isProduct == 1){
            fprintf(temp, "%d ", itemEditado.total);
            isProduct = 0;
            i++;
        }else if(i == 4){
            fprintf(temp, "%s\n", stock);
             i = 0;
        }else{
            fprintf(temp, "%s ", stock);
            i++;
        }
    }
    printf("\nProduto alterado com sucesso!\n");
    
    fclose(stockFile);
    fclose(temp);
    remove("estoque.txt");
    rename("sartre.txt", "estoque.txt");
}

void deleteItems(){
    FILE *deleteStockFile = fopen("estoque.txt", "a");
    struct Item itemDeletado;
        FILE *stockFile = fopen("estoque.txt", "r");
    printf("Informe o ID do produto: ");
    scanf("%d", &itemDeletado.id);
    FILE *temp = fopen("sartre.txt", "w");
    char stock[255];
    int i = 0, isProduct = 0;
    while(fscanf(stockFile, "%s", stock) != EOF){
        if(i == 0){
            int id = atoi(stock);
            if(id == itemDeletado.id){
                fprintf(temp, "%d ", itemDeletado.id);
                isProduct = 1;
            }else{
                fprintf(temp, "%s ", stock);
            }
            i++;
        }else if(i == 4 && isProduct == 1){
            int show = 0;
            fprintf(temp, "%d\n", show);
            isProduct = 0;
            i = 0;
        }else if(i == 4){
            fprintf(temp, "%s\n", stock);
            i = 0;
        }else{
            fprintf(temp, "%s ", stock);
            i++;
        }
    }
    printf("\nProduto excluido com sucesso!\n");

    fclose(stockFile);
    fclose(temp);
    remove("estoque.txt");
    rename("sartre.txt", "estoque.txt");
    
}

int monthFunc(char *monthStr){
    int monthInt = 0;
    if(strcmp(monthStr, "Jan") == 0){
        monthInt = 1;
    }else if(strcmp(monthStr, "Feb") == 0){
        monthInt = 2;
    }else if(strcmp(monthStr, "Mar") == 0){
        monthInt = 3;
    }else if(strcmp(monthStr, "Apr") == 0){
        monthInt = 4;
    }else if(strcmp(monthStr, "May") == 0){
        monthInt = 5;
    }else if(strcmp(monthStr, "Jun") == 0){
        monthInt = 6;
    }else if(strcmp(monthStr, "Jul") == 0){
        monthInt = 7;
    }else if(strcmp(monthStr, "Aug") == 0){
        monthInt = 8;
    }else if(strcmp(monthStr, "Oct") == 0){
        monthInt = 9;
    }else if(strcmp(monthStr, "Sep") == 0){
        monthInt = 10;
    }else if(strcmp(monthStr, "Nov") == 0){
        monthInt = 11;
    }else if(strcmp(monthStr, "Dec") == 0){
        monthInt = 12;
    }
    return monthInt;
}

void totalPurchase(){
    FILE *purchaseFile = fopen("compras.txt", "a");
    struct Purchase compraItem; 
        
    printf("Digite o ID do produto: ");
    scanf("%d", &compraItem.itemId);
    if(verifyId(compraItem.itemId) == 1){

        printf("Digite a quantidade de itens: ");
        scanf("%d", &compraItem.quantidade);
        FILE *stockFile = fopen("estoque.txt", "r");
        char name[255], stock[255];
        int show, i = 0, isProduct = 0, id, total;
        float price;
        while(fscanf(stockFile, "%s", stock) != EOF){
            if(i == 0){ 
                int id = atoi(stock);
                if(id == compraItem.itemId){
                    isProduct = 1;
                }
                i++;
            }else if(i == 1 && isProduct == 1){
                strcpy(compraItem.name, stock);
                i++;
            }else if(i == 2 && isProduct == 1){
                char *aux;
                compraItem.itemPrice = strtod(stock, &aux);
                i++;
            }else if(i == 3 && isProduct == 1){
                total = atoi(stock);        
                i++;
            }else if(i == 4 && isProduct == 1){
                if(atoi(stock) == 1){
                    show = 1;
                }else{
                    show = 0;
                }
                i = 0;
                isProduct = 0;
            }else if(i == 4){
                i = 0;
            }else{
                i++;
            }
        }

        fclose(stockFile);
        if(!(compraItem.quantidade > total)){
            if(show == 1){
                time_t rawtime;
                struct tm * timeinfo;
                time (&rawtime);
                char *time = strtok(asctime(localtime(&rawtime)), " ");
                char hour[255];
                int i = 0, day, month, year;
                while( time != NULL ) {
                    if(i == 1){
                        month = monthFunc(time);
                    }else if(i == 2){
                        day = atoi(time);
                    }else if(i == 3){
                        strcpy(hour, time);
                    }else if(i == 4){
                        year = atoi(time);
                    }
                    i++;
                    time = strtok(NULL, " ");
                }
                
                compraItem.total = compraItem.quantidade * compraItem.itemPrice;
                
                fprintf(purchaseFile, "%d/%d/%d ", day, month, year);
                fprintf(purchaseFile, "%d ", compraItem.itemId);
                fprintf(purchaseFile, "%s ", compraItem.name);
                fprintf(purchaseFile, "%.2f ", compraItem.total);
                fprintf(purchaseFile, "%s\n", hour);
            }
            fclose(purchaseFile);
          
            FILE *stockFileEdit = fopen("estoque.txt", "r");
            struct Item itemEditado;
            FILE *temp = fopen("sartre.txt", "w");
            char stock[255];
            int i = 0, isProduct = 0;
            while(fscanf(stockFileEdit, "%s", stock) != EOF){
                if(i == 0){
                    int id = atoi(stock);
                    if(id == compraItem.itemId){
                        isProduct = 1;
                    }
                    fprintf(temp, "%s ", stock);
                    i++;
                }else if(i == 3 && isProduct == 1){
                    int total = atoi(stock) - compraItem.quantidade;
                    fprintf(temp, "%d ", total);
                    isProduct = 0;
                    i++;
                }else if(i == 4){
                    fprintf(temp, "%s\n", stock);
                    i = 0;
                }else{
                    fprintf(temp, "%s ", stock);
                    i++;
                }
            }
            fclose(stockFileEdit);
            fclose(temp);
            remove("estoque.txt");
            rename("sartre.txt", "estoque.txt");
        }else{
            printf("Nao ha itens suficientes no estoque");
        }
    }else{
        printf("ID inexistente\n");
    }
    return;
}

void listPurchase(){
    FILE *purchaseList = fopen("compras.txt", "r");
    char stock[255];
    int i = 0;
    char data[255];
    printf("Insira a data | Formato (dd/mm/aaaa):\n");
    scanf("%s", data);
    printf("\n");
    int hasStock = 0, isStock = 0;
    while(fscanf(purchaseList, "%s", stock) != EOF){
        if(i == 0){
            if(strcmp(stock, data) == 0){
                hasStock = 1;
                isStock = 1;
                printf("%s ", stock);
            }
            i++;
        }else if(i == 4 && isStock == 1){
            printf("%s\n", stock);
            i = 0;
            isStock = 0;    
        }else if(isStock == 1){
            printf("%s ", stock);
            i++;
        }else if(i == 4){
            i = 0;
        }else{
            i++;
        }   
    }
}

int main(){
    int cll = 0;
    while(j == 0)
    chooseRole();
    
    
    int close = 0;
    while(close == 0){
        printf("\n1. Cadastro de produto:\n");
        printf("2. Listar produto:\n");
        printf("3. Alterar informacoes de produto:\n");
        printf("4. Excluir produto:\n");
        printf("5. Cadastrar compra:\n");
        printf("6. Listar compras:\n");
        printf("7. Sair do programa:\n\n");
        
        int action;
        scanf("%d", &action);
        if(action == 1){ // Create Item
            createItems();
        }else if(action == 2){ // List Items
            listItems();
        }else if(action == 3){ // Edit Items
            editItems();
        }else if(action == 4){ // Delete Items
            deleteItems();
        }else if(action == 5){
            totalPurchase();
        }else if(action == 6){
            listPurchase();
        }else if(action == 7){
            break;
        }else{
            printf("\nComando inexistente\n");
        }
    }
    return 0;
}
