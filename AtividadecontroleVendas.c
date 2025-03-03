
//Antonio Cleison Alves Silva
//Adcionei alguns comentarios para não me perder.

#include <stdio.h>
#define TAMCli 5
#define TAMProd 5
#define TAMVend 100

typedef struct {
    int id;
    char nome[20];
    int quantidade;
    float valor;
}Produto;

typedef struct {
    int id;
    char nome[20];
}Cliente;

typedef struct {
    int idCliente;
    int idProduto;
    int quantProduto;
    float valorTotal;
}Venda;

//Cadastro de cliente
void cadastrarCliente (Cliente c[], int qtdCli) {
     printf("Cliente %d, Primeiro Nome: ",  qtdCli+1);
     scanf("%s", c[qtdCli].nome );
     c[qtdCli].id = qtdCli+1;
}
//Cadastro de Produtos
void cadastrarProduto (Produto p[], int  qtdProd) {
     printf("\nPrimeiro Nome do Produto %d: ", qtdProd+1);
     scanf("%s", p[qtdProd].nome );
     printf("Quantidade: ");
     scanf("%d", &p[qtdProd].quantidade);
     printf("Valor: ");
     scanf("%f", &p[qtdProd].valor);
     p[qtdProd].id = qtdProd+1;
}
//Consultar Cliente
void consultarCliente (Cliente c[],  int qtdCli) {
    for(int i=0; i < qtdCli; i++) {
        printf("\nId Cliente: %d.",  c[i].id);
        printf("\nPrimeiro Nome: %s.",  c[i].nome);
    }
    printf("\n\n");
}
void consultarProduto (Produto p[], int qtdProd) {
    for(int i=0; i < qtdProd; i++) {
        printf("\nId Produto: %d.",  p[i].id);
        printf("\nNome Produto: %s.", p[i].nome);
        printf("\nQuantidade: %d.", p[i].quantidade);
        printf("\nValor: %.2f.", p[i].valor);
        printf("\n----------------------------------");
    }
    printf("\n\n");
}

int realizarVendas(Cliente cli[], Produto prod[], Venda vend[], int qtdCli, int qtdProd, int qtdDeVendas) {
     int codCli, achouCli=0;
     printf("\nCodigo do Cliente: ");
     scanf("%d", &codCli);
     for (int c=0; c < qtdCli; c++) {
          if ( cli[c].id == codCli) {
               achouCli=1;
          }
     }
     int codProd, achouProd=0;
     printf("Codigo do Produto: ");
     scanf("%d", &codProd);
     int indiceProd;
     for (int i=0; i < qtdProd; i++) {
          if ( prod[i].id == codProd) {
               achouProd=1;
               indiceProd=i;
          }
     }
     if ( achouCli==1 && achouProd==1 ) {
        int quantProd;
        printf("Informe a quantidade desejada: ");
        scanf("%d", &quantProd);

        if ( quantProd > 0 ) {
             if ( quantProd <= prod[indiceProd].quantidade) {
                if ( qtdDeVendas < TAMVend) {
                    vend[qtdDeVendas].idCliente = codCli;
                    vend[qtdDeVendas].idProduto = codProd;
                    vend[qtdDeVendas].quantProduto = quantProd;
                    vend[qtdDeVendas].valorTotal = (quantProd * prod[indiceProd].valor);

                    prod[indiceProd].quantidade = prod[indiceProd].quantidade - quantProd;
                    printf("\n\nVenda Realizada com Sucesso!");

                    return 1;
                } else {
                   printf("\n\nNao ha mais espacos para mais vendas!");
                }
             } else {
                 printf("Esta quant. nao existe no estoque. Disponivel: %d", prod[indiceProd].quantidade);
             }
        } else {
           printf("Quant. ZERO!");
        }
     }
     return 0;
}
//Consultar vendas
void consultarVendas(Venda vend[], int qtdVendas) {
   printf("\n>>>> Vendas <<<< ");
   for (int i=0; i < qtdVendas; i++) {
        printf("\n%d. cliente=%d | produto=%d | quantProd=%d | valorTotal = %.2f |",(i+1),(vend[i].idCliente),vend[i].idProduto,vend[i].quantProduto,vend[i].valorTotal );
   }
}

//Contador produtos
int contarProdutosComUmItem(Produto prod[], int qtdProd) {
   int quantProdUmItem=0;
   for (int i=0; i < qtdProd; i++) {
       if ( prod[i].quantidade == 1) {
           quantProdUmItem++;
       }
   }
   return quantProdUmItem;
}


//Implementei aqui espero que dê certo kk
//Alterar estoque !
void alterarEstoque(Produto prod[], int qtdProd){
    int idProd = 0, achouProd = 0;
    printf("Digite o codigo do produto:");
    scanf("%d", &idProd);
    int indiceDoProduto;
    for(int i = 0; i < qtdProd; i++){
        if(prod[i].id == idProd){
            achouProd = 1;
            indiceDoProduto = i;
        }
    }
        int qtdAlteraProd = 0;
    if (achouProd == 1){
        int op = 0;
        printf("1 - Adicionar, 2 - Remover: ");
        scanf("%d", &op);
            if(op == 1){
                printf("Quantidade Desejada adicionar: ");
                scanf("%d", &qtdAlteraProd);
                prod[indiceDoProduto].quantidade = qtdAlteraProd;
            }else if(op == 2){
                printf("Quantidade desejada remover: ");
                scanf("%d", &qtdAlteraProd);
                prod[indiceDoProduto].quantidade = qtdAlteraProd;
                         
            }else{
                    printf("Opcao invalida!");
            }
    }else{
        printf("Produto não encontrado: ");
    }
        
    }
    



// darDescontoNoProduto(){

// }

// exibirVendasPorCliente(){

// }

int main() {
    int opcao, sair=0; // sair inicialmente falso
    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda   vendas[TAMVend];

    //usadas como indices  nos vetores. Isto �, controla o armazenamentos
    int quantVendasRealizadas=0, quantClientes=0, quantProd=0;

    do {
        printf("\n\n>>>> Sistema de Vendas <<<< ");
        printf("\n\t1 - Cadastrar Clientes");
        printf("\n\t2 - Cadastrar Produtos");
        printf("\n\t3 - Consultar Clientes");
        printf("\n\t4 - Consultar Produtos");
        printf("\n\t5 - Vender");
        printf("\n\t6 - Consultar Vendas");
        printf("\n\t7 - Alterar Estoque");
        printf("\n\t10 - Sair\n\t>>>> ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            if (quantClientes < TAMCli) {
                cadastrarCliente(clientes, quantClientes);
                quantClientes++;
            } else {
                printf("\n\nNao ha mais espaco!!!");
            }
            break;
            
        case 2:
            if (quantProd < TAMProd) {
                cadastrarProduto(produtos, quantProd);
                quantProd++;
            } else {
                printf("\n\nNao ha mais espaco!!!");
            }
            break;

        case 3:
            if (quantClientes > 0) {
                consultarCliente(clientes, quantClientes);
            } else {
                printf("\n\nNao ha clientes!");
            }
            break;

        case 4:
            if (quantProd > 0) {
                consultarProduto(produtos, quantProd);
            } else {
                printf("\n\nNao ha produtos!");
            }
            break;
            
        case 5:
            printf("\n\t\tVendas ja realizadas: %d\n", quantVendasRealizadas);
            int vendaFoiRealizada = realizarVendas(clientes, produtos,
                                    vendas, quantClientes, quantProd, quantVendasRealizadas);
            if ( vendaFoiRealizada == 1 ) {

                quantVendasRealizadas++;

            } else {
                printf("\n\nVenda nao realizada... !");
            }
            break;

        case 6:
            if ( quantVendasRealizadas > 0) {
                consultarVendas(vendas, quantVendasRealizadas);
            } else {
                printf("\n\nNenhuma venda realizada... !");
            }
            break;

        case 7:
            if(quantProd > 0){
                alterarEstoque(produtos, quantProd);
            }else{
                printf("\n\nEstoque Zerado... !");
            }
            break;

        case 8:

            break;

        case 9:
            
            break;

        case 10:
            sair = 1;
            break;

        default: 
            printf("\n\nOpcao Invalida!");
            break;
        }

    } while ( sair != 1 );

    return 0;
}


