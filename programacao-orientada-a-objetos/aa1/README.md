# DESCRIÇÃO DA ATIVIDADE

Um simulador de corrida de veículos irá controlar veículos através de seu centro de comandos. Os veículos estarão competindo no estilo corrida.

Cada veículo criado possuirá uma identificação única (que deverá ser um número inteiro, gerado automaticamente) e uma quantidade de **4 rodas** (cujos pneus estarão calibrados ou não de acordo com um sorteio). Além disso, os veículos terão uma quantidade inicial de combustível, **3,5 litros, o valor e se o IPVA (Imposto sobre a Propriedade de Veículos Automotores) do veículo está pago ou não**.

Os veículos podem ser abastecidos e consomem combustível à medida que se deslocam. Eles apenas se movimentam se há combustável suficiente para tal, se os pneus das rodas estiverem todos calibrados e se o IPVA estiver pago. Assume-se que para mover um *“bloco”* de espaço, **o veículo gaste 0,55 litros de combustível**. Portanto, um veículo automotivo *não* deve se movimentar se:

- não possuir a quantidade de combustível suficiente,
- se um ou mais pneus não estiverem calibrados
- se o IPVA não estiver pago.

*Os veículos devem ser desenhados em modo texto, e se movem sempre na horizontal da esquerda para direita de acordo com suas respectivas quantidades de “blocos” de espaço (unidade de movimento):*

- carro: de cinco em cinco *“blocos”* de espaço,

#### 1) Descreva o diagrama UML das classes do simulador (gerar o arquivo pdf do diagrama).

#### 2) Com base do diagrama UML elaborado acima, desenvolva um aplicativo Java com um menu interativo que permita ao usuário executar o simulador de corrida de veículos com no máximo 20 veículos:

1. **Incluir veículo**
    Gerar um id (inteiro) automático para o veículo e assumir que cada pneu está vazio ou não de acordo com um sorteio. Para os automotivos sortear se o IPVA estará pago ou não

2. **Remover um veículo**
   deve-se informar o id do veículo

3. **Abastecer veículo**
   deve-se informar o id do veículo e a quantidade de combustível em litros

4. **Movimentar veículo**

5. **Movimentar todos os veículos**

6. **Imprimir todos os dados de todos os veículos**

7. **Esvaziar um pneu específico**
    Solicitar o id do veículo e qual pneu será esvaziado (primeiro, segundo,...), caso não seja dada uma entrada correta, repetir a leitura.

8. **Calibrar pneu específico**

9. **Calibrar todos os pneus**

10. **Imprimir pista de corrida**
   imprime na ordem em que estão no array, os veículos com seus respectivos “blocos” de espaços percorridos.

   ```
       ____
    __/  |_\_
   |  _     _‘‘-.
   ’-(_)---(_)--’

                   ____
                __/  |_\_
               |  _     _‘‘-.
               ’-(_)---(_)--’
         
       ____
    __/  |_\_
   |  _     _‘‘-.
   ’-(_)---(_)--’

       ____
    __/  |_\_
   |  _     _‘‘-.
   ’-(_)---(_)--’
   ```

   ​

11. **Sair da aplicação**


#### 3) A atividade será avaliado em função da:

- Correção (o aplicativo cumpre com as exigências);
  
- Documentação (o aplicativo está devidamente comentado);
  
- Paradigma orientado a objetos (o aplicativo está seguindo os princípios da programação OO:
encapsulamento, associaçãao de classes, herançaa, polimorfismo?)

- Modularidade (o aplicativo está bem estruturado onde necessário, com métodos (funções) parametrizados);

- Robustez (o aplicativo não trava em tempo de execução).

#### 4) Detalhamento de itens a serem avaliados:

| Item                                                         | Atendeu |
| ------------------------------------------------------------ | ------- |
| Respeitar o princípio do encapsulamento de dados             |         |
| Usar modificadores de acesso adequados (private e public)    |         |
| Criar getters e setters que forem necessários                |         |
| Criar métodos construtores parametrizados                    |         |
| Fazer sobrecarga de pelo menos um método (qualquer um)       |         |
| Fazer uso da palavra reservada this                          |         |
| Ter pelo menos um atributo static                            |         |
| Criar relacionamento entre classes (Agregação ou Composição) |         |
| Não apresentar erro em tempo de execução                     |         |
| Apresentar o diagrama UML                                    |         |