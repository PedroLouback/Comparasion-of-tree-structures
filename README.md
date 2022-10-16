# Trabalho sobre Comparação das estruturas em árvore
[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)](https://github.com/TFIDF-Project)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)
<h1> Comparação de diferentes estruturas com diferentes tamanhos de entrada

## Conteúdos

<p align="center">
    <a href="#apresentação">Apresentação</a> •
    <a href="#inntrodução">Introdução</a> • 
    <a href="#estruturas-e-suas-implementações">Estruturas e suas implementações</a> • 
    <a href="#bibliotecas">Bibliotecas</a> •
    <a href="#compilação-e-execução">Compilação e Execução</a> •
    <a href="#referências">Referências</a> •
    <a href="#autor">Autor</a>
</p>

---

## Apresentação

Foi proposto pelo professor [Michel Pires da Silva](http://lattes.cnpq.br/1449902596670082) da matéria de `Arquitetura e Estruturas de Dados 2 do 4º Período do curso de Engenharia de Computação` um trabalho relacionado ao conteúdo passado em suas aulas teóricas que são `Estrutura de Dados Árvore`, onde foi introduzido uma comparação de tempo entre diversas implementações sob diferentes volumes de dados em três tipos de árvores sendo elas, <a href="#•-árvore-binária-de-pesquisa">Árvore Binária de Pesquisa</a>, <a href="#•-árvore-avl">Árvore AVL</a> e <a href="#•-árvore-redblack">Árvore RedBlack</a> e outras diferentes estruturas sendo __vectors__ e <a href="#maps">MAPs</a>. Portanto foi desenvolvido o seguinte desafio:

*Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:*

*1) - Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo.*

*2) - Qual o tempo necessário para montar a estrutura em memória.*

*3) - Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória?*

*4) - Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?*

*Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise.*

Com isso, foi desenvolvido um algoritmo baseado na proposta, onde foi possível obter as seguintes conclusões presentes em <a href="#conclusão">Conclusão</a>!

---

## Introdução

Para introduzir o problema proposto primeiramente foi necessário a criação dos cinco diferentes arquivos sendo quatro deles contendo os diferentes tamanhos de entrada do tipo _float_ e um contendo 10.000 entradas do tipo _float_ utilizado para consultas, sendo possível encontra-los na pasta *__src/files__* para verificação. A criação dos arquivos foi necessária apenas uma vez para manter o padrão de testes, após isso foi removido as funções de criações.

Após a criação dos arquivos foi necessário a implementação dos diferentes tipos de `Estrutura de Dados Árvore` onde foram utilizadas através de repositórios feitos pelo professor [Michel Pires da Silva](http://lattes.cnpq.br/1449902596670082), sendo eles, [Árvore Binária de Pesquisa](https://github.com/mpiress/basic_tree), [Árvore AVL](https://github.com/mpiress/avl_tree) e [Árvore RedBlack](https://github.com/mpiress/RedBlack) onde na última estrutura foi necessária a implementação do método de _remoção_ onde foi encontrado o mesmo no livro do [1]Cormem em forma de pseudocódigo, sendo feita apenas algumas alterações no código principal para que fosse possível ser feita a implementação da _remoção_ sem nenhum problema. Sendo feita essas implementações foi necessário implementar a utilização de __*vectors*__ e estruturas do tipo __*MAPs*__ encontrando informações em [2] para uma implementação sem erros;

## Estruturas e suas implementações

### • Árvore Binária de Pesquisa

__*<u>O que é uma Árvore Binária de Pesquisa?</u>*__

Uma Árvore Binária de Pesquisa é organizada, como o nome sugere, em uma árvore binária como mostra a _Figura 1_. Sendo uma estrutura baseada em nós, onde todos os nós da subárvore esquerda possuem um valor númerico interior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz, sendo essa a forma padrão. Essa estrutura possue o objetivo de estruturar os dados de forma a permitir <a href="#busca-binária">Busca Binária</a>.
Esse tipo de estrutura suporta muitas operações de conjuntos dinâmicos, incluindo _<a href="#operação-de-busca">busca</a>, mínimo, máximo, antecessor, sucessor, <a href="#operação-de-inserção">inserção</a> e <a href="#operação-de-remoção">remoção</a>_, possibilitando seu uso como um dicionário e também como uma fila de prioridades. 

<p align="center">
<img src="imgs/abp.png" width="600px"/>
</p>
<p align="center">
<i>Figura 1: Árvores Binárias de Pesquisa. (<b>a</b>)Uma árvore binária de pesquisa com seis nós e altura 2. (<b>b</b>)Uma árvore de busca binária menos eficiente, com altura 4, contendo as mesmas chaves de (<b>a</b>).</i>
</p>

__*<u>Custos de uma Árvore Binária de Pesquisa?</u>*__

As operações básicas em um árvore binária de pesquisa demoram um tempo proporcional á altura da árvore. No caso de uma árvore binária completa com _n_ nós, tais operações são executados no tempo $O(log{}{n})$ do pior caso. Porém, se a árvore é uma cadeia linear de _n_ nós, as mesmas operações demoram o tempo $O(n)$ do pior caso. Segue uma tabela composta pela complexidade de tempo em __Notação big O__ dos algoritmos básicos que compõem a `Árvore Binária de Pesquisa`:

| Algoritmo         |  Caso Médio        | Pior Caso       |         
| ------------------| ------------------ | --------------- |
|  `Espaço`         | $O(n)$             | $O(n)$          |
|  `Busca`          | $O(log{n})$        | $O(n)$          |
|  `Inserção`       | $O(log{n})$        | $O(n)$          |
|  `Remoção`        | $O(log{n})$        | $O(n)$            

<i>Tabela 1: Complexidade de uma Árvore Binária de Pesquisa em notação big O.</i>

* Logo a árvore binária de busca é de pouca utilidade para ser aplicada em problemas de busca em geral, surgindo então o interesse em árvores balanceadas, cuja altura seja $O(log{}{n})$ no pior caso.

__*<u>Operação de Busca</u>*__

A operação de busca por um valor específico implementada no algoritmo através de uma função recursiva como é possível visualizar no pseudocódigo abaixo que foi usado como base para implementação:

```c
TreeSearch(x,k)
1 if x == NULL ou k == x.chave
2   return x
3 if k < x.chave
4   return TreeSearch(x.esquerda, k)
5 else return TreeSearch(x.direita, k)
```
<i>Explicação:</i> A busca começa examinando o nó raiz. Se a árvore está vazia, o valor procurado não pode existir na árvore. Caso contrário, se o valor é igual a raiz a busca foi bem sucedida. Se o valor é menor do que a raiz, a busca segue pela subárvore esquerda. Igualmente caso o valor é maior do que a raiz, a busca segue pela subárvore direita. Se tornando um processo recursivo até encontrar o valor requerido. Se o valor na for encontrado até a busca chegar na subárvore nula é concluido que o valor não está presente na árvore

__*<u>Operação de Inserção</u>*__

A operação de inserção é utilizado o procedimento presente na função ___insertTree()__ onde o mesmo toma um nó _z_ para o qual _z.chave = v_, _z.esquerda=NULL_ e _z.direita=NULL_, e modifica _T_ e alguns dos atributos de _z_ de modo tal que insere _z_ em uma posição adequada na árvore, sendo possível visualizar no pseudocódigo abaixo:

```c
insertTree(T,z)
1 y = NULL
2 x = T.raiz
3 while x != NULL
4   y = x
5   if z.chave < x.chave
6       x = x.esquerda
7   else x = x.direita
8 z.p = y
9 if y = NULL
10  T.raiz = z    //a árvore T era vazia
11 else if z.chave < y.chave
12  y.esquerda = z
13 else y.direita = z
```
<i>Explicação:</i> A fim de introduzir um nó novo na árvore, seu valor é primeiro comparado com o valor da raiz. Se seu valor for menor que a raiz, é comparado então com o valor do filho da esquerda da raiz. Se seu valor for maior, está comparado com o filho da direita da raiz. Este processo continua até que o nó novo esteja comparado com um nó da folha, e então adiciona-se o filho da direita ou esquerda, dependendo de seu valor. Segue abaixo na <i>Figura 2</i> um exemplo de inserção na Árvore Binária de Pesquisa:

<p align="center">
<img src="imgs/insertionTreeABP.png" width="400px"/>
</p>
<p align="center">
<i>Figura 2: Exemplo de uma inserção do valor 13 em uma árvore binária de pesquisa. Os nós sombreados emtommais claro indicamo
caminho simples da raiz até a posição emque o item é inserido. A linha tracejada indica a ligação que é acrescentada à árvore para inserir o item.</i>
</p>

__*<u>Operação de Remoção</u>*__

A exclusão de um nó na árvore binária de pesquisa é um processo mais complexo. Para excluir um nó de uma árvore binária de pesquisa, levando em consideração três casos distintos para a exclusão, sendo eles:

**Caso 1 - Remoção na folha:** A exclusão na folha é a mais simples, batando apenas removê-lo da árvore como no exemplo da figura abaixo:
<p align="left">
<img src="imgs/remove1.jpg" width="350px"/>
</p>
<i>Figura 3: Remoção do valor 40 presente em uma folha.</i>
<br><br>

**Caso 2 - Remoção de nó com um filho:** Ao excluir um nó que possui um filho, o filho vai subir para a posição do pai.
<p align="left">
<img src="imgs/remove2.jpg" width="500px"/>
</p>
<i>Figura 4: Remoção do valor 90 presente em um nó com um filho.</i>
<br><br>

**Caso 3 - Remoção de nó com dois filhos:** Neste caso, há duas opções para ser operado. A primeira é a possibilidade de substituir o valor do nó a ser retirado pelo valor sucessor (o nó mais á esquerda da subárvore direita) ou pelo valor antecessor (o nó mais á direita da subárvore esquerda), sendo feita então a remoção do nó sucessor ou antecessor.
<p align="left">
<img src="imgs/remove3.jpg" width="450px"/>
</p>
<i>Figura 5: Remoção do valor 30 presente em um nó com dois filho.</i>

A função __antecessor__ foi utilizada para que houvesse uma implementação sem erros onde a mesma é composta por:

```c
antecessor(T,x)
1 if x.direita != NULL
2 return antecessor(x.direita)
3 x = T
4 T = T.esquerda
5 free x
````

```c
RemoveTree(T,x)
1 y = T.raiz
2 if y == NULL
3   return
4 if x.chave < y.chave
5     RemoveTree(y.esquerda, x)
6 if x.chave > y.chave
7     RemoveTree(y.direita, x)
8 if y.direita == NULL{
9     aux = y
10     y = y.esquerda
11     free aux
12 }
13 if y.esquerda == NULL
14     antecessor(y.esquerda, y)
15 aux = y
16 y = y.direita
17 free aux
````

* *T* representa uma estrutura de árvore e *x* um nó

__*<u>Testes utilizando Árvore Binária de Pesquisa</u>*__

Após ser feita a implementação de todos os algoritmos básicos presentes em uma `Árvore Binária de Pesquisa` foi possível realizar os testes propostos em  <a href="#apresentação">Apresentação</a> obtendo então os seguintes resultados informados na tabela a seguir:

<p align="left">
<img src="imgs/tabelaABP.png" width="1100" height="115"/>
</p>
<i>Tabela 2: Tempos médios de comparações para pesquisa, remoção e motagem da estrutura de Árvore Binária de Pesquisa.</i>
<br><br>

Onde os mesmos são fornecidos pelo programa desenvolvido da seguinte forma após a sua compilação:

<p align="left">
<img src="imgs/saidaABP.png" width="300"/>
</p>
<i>Figura 6: Tempos encontrados após execução para diferentes processos implementados na Árvore Binária de Pesquisa.</i>
<br><br>

---

### • Árvore AVL

__*<u>O que é uma Árvore AVL?</u>*__

Uma árvore AVL é uma árvore de busca binária de altura balanceada, ou seja, uma árvore balanceada são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências identidas, Sendo necessária a reconstrução da árvore para seu estado ideal a cada operação sobre seus nós (inserção ou remoção). A sua diferença de alturas das subárvores á esquerda e á direita de _x_ é no máximo de uma unidade.

<p align="center">
<img src="imgs/AVLtree.JPG" width="500px"/>
</p>
<p align="center">
<i>Figura 7: Demonstração de uma Árvore AVL aproximadamente balanceada, uma árvore desbalanceada após remoções e a sua correção resultando em uma Árvore AVL completamente balanceada.</i>
</p>

__*<u>Complexidade de uma Árvore AVL</u>*__

Todas as operações básicas em uma `Árvore AVL` possuem complexidade $O(log{n})$ e ocupa espaço $O(n)$, sendo _n_ o número de nós da árvore, essa condição provém da sua característica de balanceamento.

| Algoritmo         |  Caso Médio        | Pior Caso       |         
| ------------------| ------------------ | --------------- |
|  `Espaço`         | $O(n)$             | $O(n)$          |
|  `Busca`          | $O(log{n})$        | $O(log{n})$     |
|  `Inserção`       | $O(log{n})$        | $O(log{n})$     |
|  `Remoção`        | $O(log{n})$        | $O(log{n})$             

<i>Tabela 3: Complexidade de uma Árvore AVL em notação big O.</i>

* Logo a árvore AVL é caracterizada por sua eficiência em buscas com chaves de probabilidades de ocorrências idênticas, reduzindo o número médio de comparações necessária para localizar qualquer elemento da árvore em 39 vezes menos.

__*<u>Operação de Busca</u>*__

A operação de busca por um valor específico implementada no algoritmo através de uma função recursiva como é possível visualizar no pseudocódigo abaixo que foi usado como base para implementação, sendo a mesma utilizada em <a href="#•-árvore-binária-de-pesquisa">Árvore Binária de Pesquisa</a>:

```c
TreeSearch(x,k)
1 if x == NULL ou k == x.chave
2   return x
3 if k < x.chave
4   return TreeSearch(x.esquerda, k)
5 else return TreeSearch(x.direita, k)
```
<i>Explicação:</i> A busca começa examinando o nó raiz. Se a árvore está vazia, o valor procurado não pode existir na árvore. Caso contrário, se o valor é igual a raiz a busca foi bem sucedida. Se o valor é menor do que a raiz, a busca segue pela subárvore esquerda. Igualmente caso o valor é maior do que a raiz, a busca segue pela subárvore direita. Se tornando um processo recursivo até encontrar o valor requerido. Se o valor na for encontrado até a busca chegar na subárvore nula é concluido que o valor não está presente na árvore

__*<u>Operação de Inserção</u>*__

A operação de inserção é utilizado o procedimento presente na função ___insertTreeAVL()__ onde é necessário uma busca pelo elemento inserido nesta mesma árvore. Após a busca o local correto para a inserção do nó  será em uma subárvore vazia de uma folha da árvore. Depois de inserido o nó, a altura do nó pai e de todos os nós acima deve ser atualizada. Em seguida o algoritmo de rotação simples ou dupla deve ser acionado para o primeiro nó pai desregulado

```c
insertTreeAVL(T,z)
1 if T == NULL
2   new(T)
3   T.item = z
4   T.peso = 0
5   T.esquerda = NULL
6   T.direita = NULL
7   else if z.chave = T.item.chave
8       insertTreeAVL(T.esquerda, z)
9       if (getPeso(T.esquerda) - getPeso(T.direita) = 2)
10          if z.chave < T.esquerda.item.chave
11              rotacaoSimplesDireita(T)
12          else
13              rotacaoDuplaEsquerdaDireita(T)
14      else if z.chave > T.item.chave
15          insertTreeAVL(T.direita, z)
16          if (getPeso(T.direita) - getPeso(T.esquerda) = 2)
17              if z.chave > T.direita.item.chave
18                  rotacaoSimplesEsquerda(T)
19              else
20                  rotacaoDuplaDireitaEsquerda(T)
21 T.peso = PesoMax(getPeso(T.esquerda),getPeso(T.direita))+1
```
A inserção demonstrada utilizou de quatro diferentes funções que foram criadas para auxiliar o balanceamento na inserção, sendo essas as 4 diferentes rotações possíveis de visualizar nos exemplos gráficos e respectivos pseudocódigos abaixo:

<p align="center">
<img src="imgs/rotacaosimples.png" width="550px"/>
</p>
<p align="center">
<i>Figura 8: Exemplo de uma rotação simples à direita.</i>
</p>

```c++
rotacaoSimplesDireita(t)
1 aux = t.left;
2 t.left = aux.right;
3 aux.right = t;
4 t.peso = PesoMax(getPeso(t.left), getPeso(t.right)) + 1;
5 aux.peso = PesoMax(getPeso(aux.left), t.peso) + 1;
6 t = aux;
```

```c++
rotacaoSimplesEsquerda(t)
1 aux = t.right;
2 t.right = aux.left;
3 aux.left = t;
4 t.peso = PesoMax(getPeso(t.esquerdo), getPeso(t.direito)) + 1;
5 aux.peso = PesoMax(getPeso(auxˆ .direito), t.peso) + 1;
6 raiz = aux;
```

<p align="center">
<img src="imgs/rotacaodupla.png" width="550px"/>
</p>
<p align="center">
<i>Figura 9: Exemplo de uma rotação dupla a esquerda/direita.</i>
</p>

```c++
rotacaoDuplaEsquerdaDireita(t)
1 rotacaoSimplesEsquerda(t.left);
2 rotacaoSimplesDireita(t);
```

```c++
rotacaoDuplaDireitaEsquerda(t)
1 rotacaoSimplesDireita(t.right);
2 rotacaoSimplesEsquerda(t);
```

* *t* representa uma estrutura de árvore e *z* um nó.

__*<u>Operação de Remoção</u>*__

O primeiro passo para remover uma chave na árvore AVL consiste em realizar uma busca binária a partir do nó raiz. Caso a busca encerre em uma subárvore vaiza, então a chave não está na árvore e a remoção não pode ser realizado. Caso a busca encerre em um nó a remoção poderá ser realizada obedecendo os seguintes casos

**Caso 1 - Remoção na folha:** A exclusão na folha é a mais simples, batando apenas removê-lo da árvore como no exemplo da figura abaixo:

**Caso 2 - Remoção de nó com um filho:** Ao excluir um nó que possui um filho, o filho vai subir para a posição do pai, bastando apontar o nó pai para a única subárvore e excluir o nó.

**Caso 3 - Remoção de nó com dois filhos:** Neste caso é necessário localizar o nó antecessor ou sucessor, que sempre será um nó folha ou possuirá apenas uma subárvore, copiar a chave do nó antecessor ou sucessor para o nó que deseja excluir e excluir o nó antecessor ou sucessor a partir da respectiva subárvore do nó que deseja excluir.


```c
RemoveTree(T,F,x)
1 y = T.raiz
2 if y == NULL
3   return
4 if x.chave < y.chave
5     RemoveTree(y.esquerda,T,x)
6 if x.chave > y.chave
7     RemoveTree(y.direita,T,x)
8 if y.direita == NULL{
9     aux = y
10     y = y.esquerda
11     free aux
12     rebalenceTree(f); //Função que verifica os pesos da árvore e balanceia novamente se necessário
13 }
14 if y.esquerda != NULL{
15     antecessor(y.esquerda, y)
16     rebalenceTree(T);
17     rebalenceTree(F);
18 }        
19 aux = y
20 y = y.direita
21 free aux
22 rebalenceTree(T);
23 rebalenceTree(F);
````

* *T* e *F* representam uma estrutura de árvore e *x* um nó.

<p align="center">
<img src="imgs/removeAVL.png" width="550px"/>
</p>
<p align="center">
<i>Figura 10: Exemplo de uma remoção balanceada na Árvore AVL.</i>
</p>

__*<u>Testes utilizando Árvore AVL</u>*__

Após ser feita a implementação de todos os algoritmos básicos presentes em uma `Árvore AVL` foi possível realizar os testes propostos em  <a href="#apresentação">Apresentação</a> obtendo então os seguintes resultados informados na tabela a seguir:

<p align="left">
<img src="imgs/tabelaAVL.png" width="1100" height="115"/>
</p>
<i>Tabela 4: Tempos médios de comparações para pesquisa, remoção e motagem da estrutura de Árvore AVL.</i>
<br><br>

Onde os mesmos são fornecidos pelo programa desenvolvido da seguinte forma após a sua compilação:

<p align="left">
<img src="imgs/saidaAVL.png" width="300"/>
</p>
<i>Figura 11: Tempos encontrados após execução do programa como saída para diferentes processos implementados na Árvore AVL.</i>
<br><br>

---

### • Árvore RedBlack

__*<u>O que é uma Árvore RedBlack?</u>*__

Uma árvore AVL é uma árvore de busca binária de altura balanceada, ou seja, uma árvore balanceada são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências identidas, Sendo necessária a reconstrução da árvore para seu estado ideal a cada operação sobre seus nós (inserção ou remoção). A sua diferença de alturas das subárvores á esquerda e á direita de _x_ é no máximo de uma unidade.

<p align="center">
<img src="imgs/AVLtree.JPG" width="500px"/>
</p>
<p align="center">
<i>Figura 7: Demonstração de uma Árvore AVL aproximadamente balanceada, uma árvore desbalanceada após remoções e a sua correção resultando em uma Árvore AVL completamente balanceada.</i>
</p>

__*<u>Complexidade de uma Árvore AVL</u>*__

Todas as operações básicas em uma `Árvore AVL` possuem complexidade $O(log{n})$ e ocupa espaço $O(n)$, sendo _n_ o número de nós da árvore, essa condição provém da sua característica de balanceamento.

| Algoritmo         |  Caso Médio        | Pior Caso       |         
| ------------------| ------------------ | --------------- |
|  `Espaço`         | $O(n)$             | $O(n)$          |
|  `Busca`          | $O(log{n})$        | $O(log{n})$     |
|  `Inserção`       | $O(log{n})$        | $O(log{n})$     |
|  `Remoção`        | $O(log{n})$        | $O(log{n})$             

<i>Tabela 3: Complexidade de uma Árvore AVL em notação big O.</i>

* Logo a árvore AVL é caracterizada por sua eficiência em buscas com chaves de probabilidades de ocorrências idênticas, reduzindo o número médio de comparações necessária para localizar qualquer elemento da árvore em 39 vezes menos.

__*<u>Operação de Busca</u>*__

A operação de busca por um valor específico implementada no algoritmo através de uma função recursiva como é possível visualizar no pseudocódigo abaixo que foi usado como base para implementação, sendo a mesma utilizada em <a href="#•-árvore-binária-de-pesquisa">Árvore Binária de Pesquisa</a>:

```c
TreeSearch(x,k)
1 if x == NULL ou k == x.chave
2   return x
3 if k < x.chave
4   return TreeSearch(x.esquerda, k)
5 else return TreeSearch(x.direita, k)
```
<i>Explicação:</i> A busca começa examinando o nó raiz. Se a árvore está vazia, o valor procurado não pode existir na árvore. Caso contrário, se o valor é igual a raiz a busca foi bem sucedida. Se o valor é menor do que a raiz, a busca segue pela subárvore esquerda. Igualmente caso o valor é maior do que a raiz, a busca segue pela subárvore direita. Se tornando um processo recursivo até encontrar o valor requerido. Se o valor na for encontrado até a busca chegar na subárvore nula é concluido que o valor não está presente na árvore

__*<u>Operação de Inserção</u>*__

A operação de inserção é utilizado o procedimento presente na função ___insertTreeAVL()__ onde é necessário uma busca pelo elemento inserido nesta mesma árvore. Após a busca o local correto para a inserção do nó  será em uma subárvore vazia de uma folha da árvore. Depois de inserido o nó, a altura do nó pai e de todos os nós acima deve ser atualizada. Em seguida o algoritmo de rotação simples ou dupla deve ser acionado para o primeiro nó pai desregulado

```c
insertTreeAVL(T,z)
1 if T == NULL
2   new(T)
3   T.item = z
4   T.peso = 0
5   T.esquerda = NULL
6   T.direita = NULL
7   else if z.chave = T.item.chave
8       insertTreeAVL(T.esquerda, z)
9       if (getPeso(T.esquerda) - getPeso(T.direita) = 2)
10          if z.chave < T.esquerda.item.chave
11              rotacaoSimplesDireita(T)
12          else
13              rotacaoDuplaEsquerdaDireita(T)
14      else if z.chave > T.item.chave
15          insertTreeAVL(T.direita, z)
16          if (getPeso(T.direita) - getPeso(T.esquerda) = 2)
17              if z.chave > T.direita.item.chave
18                  rotacaoSimplesEsquerda(T)
19              else
20                  rotacaoDuplaDireitaEsquerda(T)
21 T.peso = PesoMax(getPeso(T.esquerda),getPeso(T.direita))+1
```
A inserção demonstrada utilizou de quatro diferentes funções que foram criadas para auxiliar o balanceamento na inserção, sendo essas as 4 diferentes rotações possíveis de visualizar nos exemplos gráficos e respectivos pseudocódigos abaixo:

<p align="center">
<img src="imgs/rotacaosimples.png" width="550px"/>
</p>
<p align="center">
<i>Figura 8: Exemplo de uma rotação simples à direita.</i>
</p>

```c++
rotacaoSimplesDireita(t)
1 aux = t.left;
2 t.left = aux.right;
3 aux.right = t;
4 t.peso = PesoMax(getPeso(t.left), getPeso(t.right)) + 1;
5 aux.peso = PesoMax(getPeso(aux.left), t.peso) + 1;
6 t = aux;
```

```c++
rotacaoSimplesEsquerda(t)
1 aux = t.right;
2 t.right = aux.left;
3 aux.left = t;
4 t.peso = PesoMax(getPeso(t.esquerdo), getPeso(t.direito)) + 1;
5 aux.peso = PesoMax(getPeso(auxˆ .direito), t.peso) + 1;
6 raiz = aux;
```

<p align="center">
<img src="imgs/rotacaodupla.png" width="550px"/>
</p>
<p align="center">
<i>Figura 9: Exemplo de uma rotação dupla a esquerda/direita.</i>
</p>

```c++
rotacaoDuplaEsquerdaDireita(t)
1 rotacaoSimplesEsquerda(t.left);
2 rotacaoSimplesDireita(t);
```

```c++
rotacaoDuplaDireitaEsquerda(t)
1 rotacaoSimplesDireita(t.right);
2 rotacaoSimplesEsquerda(t);
```

* *t* representa uma estrutura de árvore e *z* um nó.

__*<u>Operação de Remoção</u>*__

O primeiro passo para remover uma chave na árvore AVL consiste em realizar uma busca binária a partir do nó raiz. Caso a busca encerre em uma subárvore vaiza, então a chave não está na árvore e a remoção não pode ser realizado. Caso a busca encerre em um nó a remoção poderá ser realizada obedecendo os seguintes casos

**Caso 1 - Remoção na folha:** A exclusão na folha é a mais simples, batando apenas removê-lo da árvore como no exemplo da figura abaixo:

**Caso 2 - Remoção de nó com um filho:** Ao excluir um nó que possui um filho, o filho vai subir para a posição do pai, bastando apontar o nó pai para a única subárvore e excluir o nó.

**Caso 3 - Remoção de nó com dois filhos:** Neste caso é necessário localizar o nó antecessor ou sucessor, que sempre será um nó folha ou possuirá apenas uma subárvore, copiar a chave do nó antecessor ou sucessor para o nó que deseja excluir e excluir o nó antecessor ou sucessor a partir da respectiva subárvore do nó que deseja excluir.


```c
RemoveTree(T,F,x)
1 y = T.raiz
2 if y == NULL
3   return
4 if x.chave < y.chave
5     RemoveTree(y.esquerda,T,x)
6 if x.chave > y.chave
7     RemoveTree(y.direita,T,x)
8 if y.direita == NULL{
9     aux = y
10     y = y.esquerda
11     free aux
12     rebalenceTree(f); //Função que verifica os pesos da árvore e balanceia novamente se necessário
13 }
14 if y.esquerda != NULL{
15     antecessor(y.esquerda, y)
16     rebalenceTree(T);
17     rebalenceTree(F);
18 }        
19 aux = y
20 y = y.direita
21 free aux
22 rebalenceTree(T);
23 rebalenceTree(F);
````

* *T* e *F* representam uma estrutura de árvore e *x* um nó.

<p align="center">
<img src="imgs/removeAVL.png" width="550px"/>
</p>
<p align="center">
<i>Figura 10: Exemplo de uma remoção balanceada na Árvore AVL.</i>
</p>

__*<u>Testes utilizando Árvore AVL</u>*__

Após ser feita a implementação de todos os algoritmos básicos presentes em uma `Árvore AVL` foi possível realizar os testes propostos em  <a href="#apresentação">Apresentação</a> obtendo então os seguintes resultados informados na tabela a seguir:

<p align="left">
<img src="imgs/tabelaAVL.png" width="1100" height="115"/>
</p>
<i>Tabela 4: Tempos médios de comparações para pesquisa, remoção e motagem da estrutura de Árvore AVL.</i>
<br><br>

Onde os mesmos são fornecidos pelo programa desenvolvido da seguinte forma após a sua compilação:

<p align="left">
<img src="imgs/saidaAVL.png" width="300"/>
</p>
<i>Figura 11: Tempos encontrados após execução do programa como saída para diferentes processos implementados na Árvore AVL.</i>
<br><br>





 
### • Contabilização da recorrência de cada palavra presente no arquivo
 
Primeiramente foi necessário ser feita a leitura de um arquivo do tipo _.txt_ contendo um texto sendo esse o alvo da compactação, onde no programa a função __ReadDocument()__ realiza esse trabalho recebendo como parâmetro uma `Lista Dinâmica` e uma estrutura de `Huffman` fazendo a leitura do arquivo _document.txt_ linha por linha, onde a cada linha lida é feita a tokenização de cada palavra e é feito o armazenamento dessas palavras em _vector tokens_ e com isso foi feita a remoção das vogais solitárias para que não houvesse interferência na normalização e codificação das palavras.
A recorrência foi feita checando as palavras de uma a uma, utilizando três estruturas de repetição do tipo `FOR` onde a primeira vai segurar uma palavra presente no _vector tokens_ , a segunda vai sempre começar a percorrer uma a frente para que não seja feita a verificação de duas mesmas palavras e a última estrutura vai percorrer o *vector verified_words*, um vector de strings onde a cada verificação das palavras é incrementada a palavra nesse vector,sendo feita a verificação de cada palavra do _vector tokens_ para que seja verificado se não vai haver uma segunda contabilização de determinada palavra, caso seja verificado que não foi realizado a verificação de cada palavra e que foi encontrado uma igual, será incrementado mais um na variável *repetition_count* para que no fim do segundo `FOR` seja feita a inserção da palavra e a sua quantidade de repetições na lista passada como parâmetro, fazendo no final a limpeza da variável *repetition_count* para que haja uma nova contabilização de uma outra palavra.
 
### • Normalização da contabilização
 
Para ser feita a normalização da contabilização primeiramente foi necessário encontrar o número máximo e o número mínimo de repetições para que fosse possível normalizar a contabilização entre 0 e 1 utilizando a fórmula $\frac{RP}{maxRP - minRP}$ , portanto foi encontrado o maior e o menor número de repetição percorrendo a lista e então armazenando-os nas variáveis *max_repetition* e *min_repetition* respectivamentes aplicando então a fórmula da normalização colocando o resultado na variável *normalization* como abaixo:
 
```c++
   normalization = (aux2->data.repetition_number / (max_repetition - min_repetition));
```
Feito isso, vai ser armazenado o valor encontrado adicionando-o no Item da lista *repetition_number* de cada palavra em que foi feita a normalização
 
### • Montagem da árvore de Huffman
 
Já possuindo um lista de palavras com suas determinadas repetições normalizadas de maneira ordenada, foi possibilitada a criação da `Árvore de Huffman` que inicialmente é composta em seu nó por uma variável do tipo _Item_ que vai ser as variáveis presentes no _Item_ da Lista Dinâmica e _ponteiros_ que apontam para os seguintes posições  left(esquerda), right(direita), _prox_(proximo) como possível a ver na representação abaixo:
 
<p align="center">
<img src="imgs/insertionTreeABP.png" width="170px"/>
<i>Imagem 1: Saída do programa onde é imprenso o ranking de relevância dos documentos</i>
</p>
 
Ou seja, a `Árvore de Huffman` se tratará de uma lista encadeada ordenada e será preenchida através da função __FillHuffman()__ que vai receber como parametro a lista de palavras com suas repetições e a estrutura de _Huffman_, onde vai preencher a estrutura de _Huffman_ com elementos presentes na lista de maneira ordenada definindo seus nós como **NULL**, a partir disso vai ser criada a `Árvore de Huffman` sendo feita pela função __HuffmanTree()__ que constitui de um nó e recebe como parâmetro a estrutura _Huffman_ preenchida, fazendo então de dois novos nó, sendo eles _**first**_ e _**second**_ que através de uma estrutura de repetição `WHILE`, que repete enquanto o tamanho da estrutura é maior que 1, vai retirando os dois primeiros elementos da estrutura (os dois menores elementos) colocando-os respectivamente nos nós criados e assim então criando um terceiro novo nó chamado **new_no** que vai receber como parte do seu _Item word_ um caracter qualquer e do seu *Item repetition_number* a soma da normalização dos dois nós removidos, inserindo os dois nós removidos como filho direito e esquerdo deste novo nó e após isso insere novamente na lista, como possível visualizar na representação abaixo:
 
<p align="center">
<img src="imgs/code4.png" width="550px"/>
</p>
 
(_OBS: A representação acima é referente a algumas palavras presentes no texto que está no arquivo *'documents.txt'* e também de possível visualização em <a href="#resultados">resultados</a>._)
 
Ao final desta função vai ser retornada o início da estrutura de _Huffman_ ou apenas um nó caso a estrutura possua um número ímpar de elementos.<br>
 
### • Codificação binária das palavras
 
Até o momento irá existir um nó chamado *tree* presente no algoritmo em que vai possuir toda a `Árvore de Huffman` e relacionada ao exemplo anterior vai estar como na representação a seguir:
 
<p align="center">
<img src="imgs/code5.png" width="550px"/>
</p>
 
(_OBS: A representação acima é referente a algumas palavras presentes no texto que está no arquivo *'documents.txt'* e também de possível visualização em <a href="#resultados">resultados</a>._)
 
 
A resolução para a codificação binária das palavras é encontrada na função __GenerateSequence()__ onde recebe como parâmetro toda a `Árvore de Huffman` construída na função anterior como parâmetro, uma nova `Lista Dinâmica` criada para armazenar as sequências booleanas com suas respectivas palavras e uma _string_ chamada *way*, se tratando de uma função recursiva, já vai ser introduzida com uma estrutura de decisão `IF` onde verifica se chegou em uma folha, ou seja, os filhos esquerdos e direitos daquele nó são **NULL** e caso se tratar de uma folha vai ser passada a palavra e a sequência booleana em forma de _string_ que foi obtida durante toda a recursão da função para a `Lista Dinâmica`, caso contrário, significa ainda que possui filhos então é feita duas cópias do caminho gerado até ali, uma cópia continuará para a esquerda e a outra para a direita. Na cópia da esquerda vai ser concatenado um 0 na variável *left_way* e na cópia da direita vai ser concatenada um 1 na variável *right_way* e por fim vai ser feita duas chamadas recursivas da função __GenerateSequence()__, uma para a esquerda com a *left_way* e outra para a direita com o *right_way* passados como parâmetros
 
### • Escrita da codificação binária em um arquivo binário
 
A última etapa do código consiste em pegar toda a codificação feita na etapa anterior e escrever essa codificação em formato _booleano_ correspondentes às palavras que são encontradas no arquivo de texto inicial, para a solução desse propósito foi criado a função __WriteBinaryFile()__ que recebe como parâmetro uma lista que contém as palavras com suas respectivas sequências booleanas e o _vector tokens_ criado no início do programa eu contém a tokenização do arquivo de texto a ser codificado. Diante disso, a função inicia com duas estruturas de repetição, sendo um `FOR` e um `WHILE` onde primeiramente o `FOR` irá percorrer o _vector tokens_ e o `WHILE` vai ser necessário para percorrer a lista que a cada posição percorrida vai ser feita a verificação utilizando a estrutura de decisão `IF` , verificando se cada posição do _vecotr tokens_ corresponde a posição da lista e caso seja correspondente vai ser introduzido um novo `FOR` para converter a sequência que está na lista em tipo _string_ para tipo _bool_ através de um _vector bool_ que vai armazenando a sequência em formato booleano para no fim escrever posição por posição do _vector bool_ no novo arquivo do tipo _.bin_, que ao fim vai ser feita a limpeza desse vector para que possa ser utilizado novamente em uma nova palavra encontrada na verificação de igualdade do texto.
 
---
 
## Resultados
 
• Após toda a lógica acima ter sido implementada no algoritmo foi possível a obtenção da compactação do arquivo *'document.txt'* como forma de teste onde o mesmo continha o seguinte texto:
 
_Caros amigos, a infinita diversidade da realidade única nos obriga à análise do demônio de Laplace. Por outro lado, a complexidade dos estudos efetuados cumpre um papel essencial na formulação da fundamentação metafísica das representações. Assim mesmo, a forma geral da proposição significativa deverá confirmar as consequências decorrentes do sistema de conhecimento geral._
 
_Neste sentido, o novo modelo estruturalista aqui preconizado auxilia a preparação e a composição das posturas dos filósofos divergentes com relação às atribuições conceituais. Baseando-se nos ensinamentos de Dewey, a canalização do Ser do Ente garante a contribuição de um grupo importante na determinação das novas teorias propostas. A prática cotidiana prova que a consolidação das estruturas psico-lógicas não sistematiza essa relação, de tal modo que a pulsão funciona funciona como significado da determinação do Ser enquanto Ser._
 
Onde a partir desse texto foi visualizado que o arquivo _'.txt'_ do mesmo continha um total de **_953 bytes_** e após a compactação realizada pelo algoritmo foi criado um novo arquivo _'.bin'_ chamado *'compact_text.bin'* encontrando um tamanho de **_761 bytes_** do mesmo, concluindo que a compactação foi feita com sucesso, tendo um total de **_191 bytes_** compactados.
 
• Ao ser compilado e executado o programa irá gerar a seguinte mensagem:
 
<p align="center">
<img src="imgs/code6.png" width="600px"/>
</p>
 
Diante disso um arquivo de texto chamado _'sequence.txt'_ irá ser criado no qual vai informar ao usuário todas as palavras presentes no texto com suas respectivas codificações booleanas, esse arquivo abre a possibilidade do usuário de consultar as codificações encontradas no arquivo binário.

---

## Bibliotecas

<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'iostream'</code></li>
    <li><code>#include 'stdio.h'</code></li>
    <li><code>#include 'stdbool.h'</code></li>
    <li><code>#include 'stdlib.h'</code></li>
    <li><code>#include 'vector'</code></li>
    <li><code>#include 'fstream'</code></li>
    <li><code>#include 'random'</code></li>
    <li><code>#include 'iomanip'</code></li>
    <li><code>#include 'string'</code></li>
    <li><code>#include 'sstream'</code></li>
    <li><code>#include 'algorithm'</code></li>
    <li><code>#include 'bits/stdc++.h'</code></li>
    <li><code>#include 'ctime'</code></li>
    <li><code>#include 'unordered_map'</code></li>
    <li><code>#include 'map'</code></li>
</ul>

---

## Referências

[1] CORMEM, Thomas H. et al. __Algoritmos__: Teoria e Prática. 3. ed. Cambridge, Massachussetts: MIT Press, [2009]. 1292 p. ISBN 9780262033848.

[2] THAPLIYAL, Rohit. __Map vs unordered_map in C++__. [S. l.]: GeeksforGeeks, 7 jul. 2022. Disponível em: https://www.geeksforgeeks.org/map-vs-unordered_map-c/. Acesso em: 15 out. 2022.

---

## Compilação e Execução

O programa feito de acordo com a proposta possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## Autor

Desenvolvido por [Pedro Henrique Louback Campos](https://github.com/PedroLouback)

Aluno do 4° periodo do curso de `Engenharia de Computação` no [CEFET-MG](https://www.cefetmg.br)
