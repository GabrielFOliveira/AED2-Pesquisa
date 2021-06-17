# AED2-Pesquisa

### Enunciado: 

O objetivo desta atividade prática é exercitar o uso de estrutura de dados para recuperar informações em memória principal. Você deverá implementar as estruturas de pesquisa estudadas em sala (Pesquisa Sequencial, Pesquisa Binária, Árvore de Pesquisa Binária, Árvore de Pesquisa Binária Balanceada, Tabelas Hash) para indexar e facilitar a recuperação de informações relacionado a Covid-19 no brasil, disponibilizado pelo governo federal no endereço: https://covid.saude.gov.br/ (Links para um site externo.)

Você terá a liberdade para definir quais consultas o seu sistema irá disponibilizar para os usuários. Para cada consulta você deverá mostrar o custo computacional (tempo e quantidade de comparações) em cada uma das estruturas implementadas.

A eficácia das informações recuperadas faz parte da avaliação da atividade, sendo assim, busque implementar consultas que possam auxiliar na análise da evolução e impacto da doença em nossa sociedade.

Ao final da atividade você deverá entregar o seu código hospedado no Github e documentado no próprio Github.


### 1 - Definição do problema: 

A partir do conjunto de dados levantado através do site do governo federal, foi feita a definição do tipo de pesquisa que seria disponibilizada para o usuário no sistema. 
Nesse sistema, é possível realizar pesquisas de quantidade de dados de covid referente ao município como um todo e de um dia específico referente ao município. Os dados abordam somente dados referentes ao estado de Minas Gerais.

### 2 - Estrutura base do trabalho: 

A estrutura de armazenamento de dados base do problema utilizada para realizar as pesquisas foi a Lista. Os dados dos municípios foram agrupados e colocados em uma lista para cada um. Para agrupar essas listas de dados dos município, foi utilizado um vetor de lista. Todas as pesquisas são baseadas nessa forma de armazenamento dos dados coletados do arquivo .csv que é lido pelo programa, interpretado e criada a TAD.

### 3 - Pesquisa Sequencial: 

A pesquisa sequencial foi feita de maneira simples, apenas recebendo como parâmetro o valor e pesquisando de forma sequencial no vetor de listas. Foi realizada uma separação entre as pesquisas para o município e para o dia, pois a pesquisa se dará por duas partes: a primeira onde o usuário pesquisará o município e a segunda o dia. Logo a função pesquisaSequencialMun(); receberá o município como parâmetro, enquanto a pesquisaSequencialDia(); receberá o dia.

### 4 - Pesquisa Binária: 

Para realizar a pesquisa binária, também foi dividido em pesquisa por município e por dia. O algoritmo de ordenação escolhido foi o Bubble Sort, devido a sua simplicidade de implementação. Foi verificada uma complexidade de xxx para este tipo de pesquisa.
