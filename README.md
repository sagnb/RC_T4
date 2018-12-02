# RC_T4

    Em construção ...

    Ler de um arquivo um grafo não direcionado representando um mapa de ASs da Internet. O grafo deve conter no mínimo 13 ASs (AS1, AS2, ..., AS13). Deve haver caminhos entre todos os ASs, ou seja, escolhendo dois ASs quaisquer, como AS3 e AS9, dever have um caminho entre eles. Este caminho pode ser uma ligação direta (aresta) ou um caminho passando por outros nós (ASs) e arrestas. Não pode haver conexão direta do tipo todos com todos, ou seja, todos os ASs conectados diretamente a todos os demais ASs.

    Cada AS possui um número mínimo de saltos internos (roteadores) até qualquer saída do sistema. Exemplo: o AS1 possui R=2 e o AS7 possui R=7. Isto significa que o AS1 é, provavelmente, pequeno, enquanto que o AS7 é grande e agrega latência (devido ao número de roteadores/saltos) às comunicações que passam através do AS.

    Ler um segundo arquivo contendo pares host1/AS1 host2/AS2. Isto significa que o host1 está conectado ao AS1 e o host2 está conectado ao AS2. Exemplo:

        H1 AS2 H2 AS13

        H3 AS5 H4 AS1

        ...

        Hx AS4 Hy AS12

    Para cada par de hosts/ASs (linha do arquivo), o programa deverá encontrar e listar:

        (a) o menor caminho entre os hosts Hx e Hy;

        (b) o melhor caminho (menor custo considerando os custos das arrestas);

        (c) o melhor caminho em termos de latência (menor latência total), isto é, considerando o número de saltos/roteadores dentro dos nós (ASs).

    Coisas a observar:

        (i) Cada arresta possui um limite (ponto de saturação). Exemplo: 10 conexões host/host podem passar por ela num intervalo de tempo T.

        (ii) Cada arresta (conexão entre dois ASs quaisquer) possui um custo financeiro associado. Definir os custos de cada arresta de forma pseudo-aleatória.

    NOTA: é importante discutir em aula ou em horário/local a combinar. Não deixar para última hora.