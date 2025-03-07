
//Antonio Cleison Alves Silva
//Adcionei alguns comentarios para não me perder.
//Este codigo eesta sendo versionado no git hub desde do dia 3/04

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

//###-Cadastro de cliente
void cadastrarCliente (Cliente cle[], int qtdCli) {
     printf("Cliente %d, Primeiro Nome: ",  qtdCli+1);
     scanf("%s", cle[qtdCli].nome );
     cle[qtdCli].id = qtdCli+1;
}

//###-Cadastro de Produtos
void cadastrarProduto (Produto p[], int  qtdProd) {
     printf("\nPrimeiro Nome do Produto %d: ", qtdProd+1);
        scanf("%s", p[qtdProd].nome );
     printf("Quantidade: ");
        scanf("%d", &p[qtdProd].quantidade);
     printf("Valor: ");
        scanf("%f", &p[qtdProd].valor);
     p[qtdProd].id = qtdProd+1;
}

//###-Consultar Cliente
void consultarCliente (Cliente c[],  int qtdCli) {
    for(int i=0; i < qtdCli; i++) {
        printf("\nId Cliente: %d.",  c[i].id);
        printf("\nPrimeiro Nome: %s.",  c[i].nome);
        printf("\n----------------------------------");
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

//###-Função de desconto
float darDescontoNoProduto(float valorTotal){
    if (valorTotal >= 100){
        int op;
        printf("Adicionar desconto de 5%%: Sim = 1, Nao = 2: ");
            scanf("%d", &op);

        switch(op){
           case 1:
                valorTotal *= 0.95; // Aplica 5% de desconto
                printf("Desconto feito, novo valor: %.2f\n", valorTotal);
                break;
            case 2:
                printf("Não aplicado desconto. Valor total: %.2f\n", valorTotal);
                break;
            default:
                printf("Opcao invalida nao aplicado desconto.\n");
                break;
        }
    }
    return valorTotal;

 }

//###-Consultar venda pelo cliente
 void exibirVendasPorCliente(Venda venda[], int qtdVendas){
    int codCli, vendasEncontradas = 0;
    printf("\nCodigo do Cliente: ");
    scanf("%d", &codCli);

        printf("\nVendas do Cliente ID %d:\n", codCli);
        for (int v = 0; v < qtdVendas; v++) {

            if ( venda[v].idCliente == codCli) {
                vendasEncontradas++;
                printf("Venda %d: Produto=%d | Quantidade=%d | Valor Total=%.2f\n",
                (vendasEncontradas), venda[v].idProduto, venda[v].quantProduto, venda[v].valorTotal); 
            }        
        }
        if(vendasEncontradas == 0){
            printf("Nao ha venda para este cliente ID: %d\n", codCli);
        }

 }

//###-Realizar a venda
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
             if (quantProd > 0 && quantProd <= prod[indiceProd].quantidade) {
                float valorTotal = quantProd * prod[indiceProd].valor;
                valorTotal = darDescontoNoProduto(valorTotal);

                if ( qtdDeVendas < TAMVend) {
                    vend[qtdDeVendas].idCliente = codCli;
                    vend[qtdDeVendas].idProduto = codProd;
                    vend[qtdDeVendas].quantProduto = quantProd;
                    vend[qtdDeVendas].valorTotal = valorTotal;

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
     //Verificação adicionada   
    }else if(achouCli == 0 || achouProd == 0){
        printf("\n\nCliente ou Produto nao encontrado\nVerifique os codigos");
    }
    return 0;
}

//###-Consultar vendas
void consultarVendas(Venda vend[], int qtdVendas) {
   printf("\n>>>> Vendas <<<< ");
   for (int i=0; i < qtdVendas; i++) {
        printf("\n%d. cliente=%d | produto=%d | quantProd=%d | valorTotal = %.2f |",(i+1),(vend[i].idCliente),vend[i].idProduto,vend[i].quantProduto,vend[i].valorTotal );
   }
}

//###-Contador produtos
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

//###-Alterar estoque !
void alterarEstoque(Produto prod[], int qtdProd){
    int idProd = 0, achouProd = 0;
    printf("Digite o codigo do produto: ");
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
        printf("Atual quantidade do produto: %d\n", prod[indiceDoProduto].quantidade);
        printf("Digite a nova quantidade: ");
        scanf("%d", &qtdAlteraProd);
        prod[indiceDoProduto].quantidade = qtdAlteraProd;   
        printf("Quantidade modificada para: %d\n", prod[indiceDoProduto].quantidade);
    } else {
        printf("Produto não encontrado: ");
    }
    
}

//##-Main (Cleison)
int main() {
    int opcao, sair=0; // sair inicialmente falso 
    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda   vendas[TAMVend];

//usadas como indices  nos vetores. Isto, controla o armazenamentos (Cle)
    int quantVendasRealizadas=0, quantClientes=0, quantProd=0;

    do {
        printf("\n\n>>>> Sistema de Vendas <<<< ");
        printf("\n\t1 - Cadastrar Clientes");
        printf("\n\t2 - Cadastrar Produtos");
        printf("\n\t3 - Consultar Clientes");
        printf("\n\t4 - Consultar Produtos");
        printf("\n\t5 - Vender");//(Cle)
        printf("\n\t6 - Consultar Vendas");
        printf("\n\t7 - Alterar Estoque");
        printf("\n\t8 - Consultar Venda por Cliente");
        printf("\n\t9 - Sair\n\t>>>> ");
        scanf("%d", &opcao);

        switch (opcao){
    //Cadastrar Clientes
        case 1:
            if (quantClientes < TAMCli) {
                cadastrarCliente(clientes, quantClientes);
                quantClientes++;
            } else {
                printf("\n\nNao ha mais espaco!!!");
            }
            break;
    //Cadastrar Produtos        
        case 2:
            if (quantProd < TAMProd) {
                cadastrarProduto(produtos, quantProd);
                quantProd++;
            } else {
                printf("\n\nNao ha mais espaco!!!");
            }
            break;
    //Consultar Clientes        
        case 3:
            if (quantClientes > 0) {
                consultarCliente(clientes, quantClientes);
            } else {
                printf("\n\nNao ha clientes!");
            }
            break;
    //Consultar Produtos        
        case 4:
            if (quantProd > 0) {
                consultarProduto(produtos, quantProd);
            } else {
                printf("\n\nNao ha produtos!");
            }
            break;
    //Vender        
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
    //Consultar Vendas
        case 6:
            if ( quantVendasRealizadas > 0) {
                consultarVendas(vendas, quantVendasRealizadas);
            } else {
                printf("\n\nNenhuma venda realizada... !");
            }
            break;
    //Alterar Estoque        
        case 7:
            if(quantProd > 0){
                alterarEstoque(produtos, quantProd);
            }else{//(Cleison)
                printf("\n\nEstoque Zerado... !");
            }
            break;
    //Consultar Venda por Cliente    
        case 8:
            if (quantClientes > 0 && quantVendasRealizadas > 0) {
                exibirVendasPorCliente(vendas, quantVendasRealizadas);
            } else {
                printf("\n\nNao ha clientes ou Nao ha vendas!");
            }
            break;
    //sair        
        case 9:
            sair = 1;
            break;

        default: 
            printf("\n\nOpcao Invalida!");
            break;
        }

    } while ( sair != 1 );

    return 0;
}

//Antonio Cleison

