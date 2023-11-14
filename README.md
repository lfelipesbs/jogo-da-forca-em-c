# Jogo da Forca em C
## Visão Geral
Este projeto é uma implementação do jogo da forca em linguagem C, onde o jogador tenta adivinhar uma palavra secreta letra por letra. Cada letra errada aproxima o jogador de um desfecho indesejado: a completa formação da forca.

## Estrutura do Projeto
O código está organizado em vários arquivos para facilitar a compreensão e o desenvolvimento:

    main.c: Arquivo que contém a função principal main, gerenciando o fluxo do jogo.
    forca.c: Arquivo com as funções que definem a lógica do jogo, como escolher a palavra secreta e verificar os chutes.
    termforca.h: Cabeçalho com definições e constantes para a interface do usuário.
    forca.h: Cabeçalho com a declaração das funções do jogo.
    palavras.txt: Arquivo de texto contendo uma lista de palavras para serem utilizadas como desafio no jogo.

## Compilação e Execução
### Pré-Requisitos

    Um compilador de C como o GCC ou Clang.
    Um editor de texto para editar os arquivos, se necessário.

### Compilando o Jogo

Para compilar o jogo, use o comando abaixo no terminal:

    gcc -o jogo_da_forca main.c forca.c -I.

### Executando o Jogo

Para iniciar o jogo, execute o seguinte comando no terminal:

    ./jogo_da_forca

## Como Jogar

Quando o jogo começa, uma palavra é escolhida aleatoriamente do palavras.txt. O jogador deve tentar adivinhar a palavra inserindo letras uma a uma. O jogo termina quando o jogador adivinha a palavra corretamente ou esgota o número permitido de tentativas incorretas.

## Adicionando Novas Palavras

Para adicionar novas palavras ao jogo, inclua cada nova palavra em uma nova linha no arquivo palavras.txt.

## Contribuições

Contribuições são encorajadas e podem ser feitas através de pull requests no repositório. Sugestões para novas funcionalidades, melhorias de código e correções de bugs são sempre bem-vindas.

## Licença

Este projeto é licenciado sob a GNU General Public License v3.0. Veja o arquivo LICENSE para mais detalhes.

## Contato

Se tiver alguma dúvida ou sugestão, por favor, entre em contato com o mantenedor do projeto através de luizfelipesbs15@gmail.com
