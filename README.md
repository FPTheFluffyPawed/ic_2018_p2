# 2º Projecto de Introdução à Computação 2018/2019

Diogo Henriques - 21802132
Miguel Costa - 21803360
Inácio Amerio - 21803493

## Descrição da Solução



## Manual de utilizador:
O Settlers Of Catan, ou Descobridores de Catan, é um jogo em que cada jogador encarna a pela de um descobridor, em busca de expandir o seu território e dominar o mapa. O seu objectivo principal é obter 6 pontos antes que o adversário.

Para compilar o jogo, o utilizador deve utilizar o comando make, isto deve-se a termos uma ficheiro makefile previamente preparado.

REGRAS:

 - No inicio do jogo, cada jogador tem de escolher onde criar a primeira aldeia, que vai ser designada pelo número '1'. Apenas pode haver uma aldeia(1)/cidade(2) por terreno, por isso se o jogador 1 (PL1) escolher a posição #1 o jogador 2 (PL0) não poderá escolher a posição #1.

 - Em cada jogada os jogadores vão rolar os dados, se a soma dos dois dados lançados for igual aos números dos terrenos adjacentes à aldeia (1) do jogador, o mesmo recebe uma carta com os recursos naturais produzidos por esse mesmo terreno adjacente. 
 
 - Quando o jogador quiser expandir o seu território, terá de formas novas aldeias (1), mas apenas o pode fazer em terrenos ligados directamente à sua aldeia (1). Se o jogador quiser transformar uma aldeia (1) numa cidade (2), os terrenos adjacentes vão produzir duas unidades de recurso natural em vez de uma.
Custos:
Aldeia: Brick (B)+ Lumber (L) + Grain (G) + Wool  (W)
Cidade: Grain (G) + Grain (G) + Iron (I) + >Iron (I) + Iron (I)

 - O jogador pode efectuar trocas com o banco. O rácio da troca será de 4 para 1, ou seja, o jogador terá de dar 4 unidades de 1 recurso em troca de 1 carta de outro recurso natural à sua escolha. O jogador terá ainda a possibilidade de trocar 10 cartas iguais por 1 ponto.


COMO JOGAR:
Sempre que é a vez do jogador, o mesmo tem obrigatoriamente de lançar os dados antes de fazer outra acção. Depois disso e de acordo com os seus recursos, o jogador pode:

 - Comprar uma aldeia(1)
 - Transformar uma aldeia(1) sua numa cidade(2)
 - Efectuar uma troca com o banco ao rácio de 4 para 1
 - Passar a vez ao outro jogador

## Conclusões e Matéria Aprendida
Com este trabalho relembra-mos novamente como usar melhor o C, aprendemos que fazer este projecto foi uma dor de cabeça, tivemos algumas dificuldades na parte da alocação de memória e de ir buscar variáveis ao ficheiro .ini, mas graças à discussão de ideias que tivemos com outros grupos da turma, achamos que tenhamos feito o trabalho que o professor pediu


## Referências
Discutimos alguns pontos do trabalho com outros colegas da turma:

 - Rodrigo Pinheiro
 - João Dias
 - João Cerqueira
 - Hugo Feliciano

