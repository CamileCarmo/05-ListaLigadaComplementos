#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
  int valor;
  NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
  menu();
}

void menu()
{
  int op = 0;
  while (op != 7) {
    //system("cls"); // somente no windows
    cout << "Menu Lista Ligada";
    cout << endl << endl;
    cout << "1 - Inicializar Lista \n";
    cout << "2 - Exibir quantidade de elementos \n";
    cout << "3 - Exibir elementos \n";
    cout << "4 - Buscar elemento \n";
    cout << "5 - Inserir elemento \n";
    cout << "6 - Excluir elemento \n";
    cout << "7 - Sair \n\n";

    cout << "Opcao: ";
    cin >> op;

    switch (op)
    {
    case 1: inicializar();
      break;
    case 2: exibirQuantidadeElementos();
      break;
    case 3: exibirElementos();
      break;
    case 4: buscarElemento();
      break;
    case 5: inserirElemento();
      break;
    case 6: excluirElemento();
      break;
    case 7:
      return;
    default:
      break;
    }

    //system("pause"); // somente no windows
  }
}

void inicializar()
{
  // se a lista já possuir elementos
// libera a memoria ocupada
  NO* aux = primeiro;
  while (aux != NULL) {
    NO* paraExcluir = aux;
    aux = aux->prox;
    free(paraExcluir);
  }

  primeiro = NULL;
  cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

  int nElementos = 0;
  NO* aux = primeiro;
  while (aux != NULL) {
    nElementos++;
    aux = aux->prox;
  }
  cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
  if (primeiro == NULL) {
    cout << "Lista vazia \n";
    return;
  }
  else {
    cout << "Elementos: \n";
    NO* aux = primeiro;
    while (aux != NULL) {
      cout << aux->valor << endl;
      aux = aux->prox;
    }
  }
}

void inserirElemento()
{
  //aloca um espaco de memoria 
  NO* novo = (NO*)malloc(sizeof(NO));
  if (novo == NULL) {
      return;
  }
  //digita um novo elemento
  cout << "Digite o elemento: ";
  cin >> novo->valor;
  novo->prox = NULL;
  
  //verifica se nao existe o valor digitado 
  if (primeiro == NULL) {
      primeiro = novo;
  }
  else {
      //inicia o valor da atual como o valor da primeira e retira o ultimo
      NO* atual = primeiro;
      NO* anterior = NULL;

      while (atual != NULL && atual->valor < novo->valor) {
          anterior = atual;
          atual = atual->prox;
      }

      if (atual != NULL && atual->valor == novo->valor) {
          cout << "Elemento duplicado, não inserido.\n";
          free(novo);
          return;
      }

      if (anterior == NULL) {
          novo->prox = primeiro;
          primeiro = novo;
      } else {
          novo->prox = anterior->prox;
          anterior->prox = novo;
      }
  }
}

void excluirElemento()
{
  if (primeiro == NULL) {
    cout << "Lista vazia \n";
    return;
  }

  int numero;
  cout << "Digite o elemento a ser excluído: ";
  cin >> numero;

  NO* atual = primeiro;
  NO* anterior = NULL;

  while (atual != NULL && atual->valor <= numero) {
    if (atual->valor == numero) {
        if (anterior == NULL) {
            // O elemento a ser excluído é o primeiro
            primeiro = atual->prox;
        } else {
            // Excluindo elemento no meio ou final
            anterior->prox = atual->prox;
        }
        free(atual);
        cout << "Elemento excluído.\n";
        return;
    }
    anterior = atual;
    atual = atual->prox;
  }

  cout << "Elemento não encontrado.\n";
}

void buscarElemento()
{
  if (primeiro == NULL) {
    cout << "Lista vazia \n";
    return;
  }

  int numero;
  cout << "Digite o elemento a ser buscado: ";
  cin >> numero;

  NO* aux = primeiro;
  while (aux != NULL && aux->valor <= numero) {
    if (aux->valor == numero) {
        cout << "Elemento encontrado: " << numero << endl;
        return;
    }
    aux = aux->prox;
  }

  cout << "Elemento não encontrado.\n";
}