# Trabalhos de Laboratório de ICC 1

Trabalhos desenvolvidos em C por mim para a disciplina de Laboratório ICC 1 do curso de Ciências de Computação do ICMC/USP.

Link da disciplina no JupiterWeb:
[https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SCC0222](https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SCC0222)


## Como executar

Para executar os arquivos usando Linux, basta seguir os passos:

 **1. Instalar o gcc**
 
 O gcc é um conjunto de compiladores de linguagens de programação; dentre elas: C. Instale-o:
 

    $ sudo apt update
    $ sudo apt install build-essential

 **2. Compile (ou execute) os arquivos das pastas**
 
 Caso queira apenas executar o arquivo já compilado, abra uma das pastas e, no terminal:

    $ ./nomedoarquivo
   
Se quiser fazer alterações, será necessário compilar novamente:

    $ gcc -o nomedoarquivo nomedoarquivo.c
Após, apenas execute o novo arquivo gerado.