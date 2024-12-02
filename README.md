# atomArcade
Este projeto em linguagem C implementa um sistema simples para gerenciamento de estoque e vendas de uma loja de jogos. Ele utiliza conceitos fundamentais de programação, como estruturas, vetores, laços de repetição e funções, proporcionando uma interface interativa para facilitar a administração do negócio. A seguir, está uma visão geral do sistema:

Funcionalidades Principais:

Cadastro de Produtos:
Permite adicionar novos produtos ao estoque com informações como nome, plataforma, preço, quantidade e código único.
Realiza validações para evitar duplicação de códigos.

Consulta de Estoque:
Possibilita a busca por produtos cadastrados com base em critérios como nome, plataforma ou código.
Exibe as informações detalhadas do produto, como quantidade em estoque e preço.

Registro de Vendas:
Permite registrar vendas, descontando automaticamente a quantidade vendida do estoque.
Gera informações sobre a venda, incluindo o valor total.
Menu Interativo:

Interface de texto amigável com opções para navegar entre funcionalidades.
Utiliza comandos de limpeza de tela e pausa para melhorar a usabilidade.
Estrutura do Código:

Definição de Constantes:
maximoprodutos e maximoVendas definem os limites de armazenamento para produtos e vendas.

Estruturas de Dados:

Produto: Representa os produtos no estoque.
Venda: Registra os dados de cada venda realizada.

Funções Auxiliares:
clearConsole: Limpa o console de forma cross-platform.
pauseConsole: Pausa a execução para leitura de mensagens.

Produtos Pré-cadastrados:
O sistema inicializa com uma lista de 15 jogos populares para facilitar o teste.

Motivação:
Este projeto foi desenvolvido com o objetivo de aplicar e reforçar conhecimentos em programação estruturada e manipulação de dados. Ele simula a operação de um sistema básico de loja, ideal para estudos e experimentação.

Como Usar:
Compile o código utilizando um compilador C, como o gcc, e execute-o no terminal. O sistema guiará o usuário pelas opções do menu principal.
