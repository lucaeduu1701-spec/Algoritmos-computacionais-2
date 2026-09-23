[README.md](https://github.com/user-attachments/files/32561799/README.md)
# Algoritmos-computacionais-2# Desafio de Monitoramento de Temperatura

## 1. Identificação

**Nome do aluno:** Lucas Eduardo  
**Disciplina:** Programação de Computadores  
**Professora:** Profa. Karla Sartin  
**Título do projeto:** Sistema de Monitoramento de Temperatura

## 2. Objetivo

O programa tem como objetivo simular um sistema de monitoramento de temperatura. O usuário define um limite de temperatura e, em seguida, informa várias leituras. O sistema valida as entradas, identifica temperaturas acima do limite, controla ocorrências consecutivas e encerra automaticamente o monitoramento quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório com a quantidade de leituras válidas, maior temperatura, menor temperatura, média, quantidade de temperaturas acima do limite e percentual dessas ocorrências.

## 3. Funcionamento do programa

### Definição do limite de temperatura

Primeiro, o usuário informa o limite de temperatura. O programa aceita valores entre **-50 °C e 100 °C**. Caso seja informado um valor fora desse intervalo ou uma entrada que não seja numérica, o programa solicita novamente o limite.

### Realização das leituras

Depois de definir o limite, o usuário pode informar as temperaturas uma por uma. O valor **999** é utilizado para encerrar manualmente o monitoramento.

### Tratamento de valores inválidos

Valores não numéricos e temperaturas fora do intervalo de -50 °C a 100 °C são rejeitados. Eles não entram nos cálculos estatísticos e não alteram a contagem de temperaturas consecutivas.

### Identificação de temperaturas acima do limite

Sempre que uma leitura válida for maior que o limite definido pelo usuário, o programa apresenta um alerta e aumenta a quantidade de temperaturas acima do limite.

### Contagem de temperaturas consecutivas

O programa utiliza uma variável chamada `consecutivas`. Quando a temperatura está acima do limite, o contador aumenta em 1. Quando uma temperatura está dentro ou igual ao limite, o contador é zerado.

Quando o contador chega a **3**, o sistema encerra automaticamente o monitoramento.

### Condição de encerramento

O monitoramento termina em duas situações:

1. O usuário informa `999`, encerrando manualmente.
2. O sistema identifica três temperaturas consecutivas acima do limite, encerrando automaticamente.

## 4. Estruturas de repetição utilizadas

### do...while

O `do...while` é utilizado na definição do limite de temperatura. Essa estrutura foi escolhida porque o usuário precisa informar o limite pelo menos uma vez. Depois da entrada, o programa verifica se o valor é válido e, caso não seja, repete a solicitação.

### while

O `while` é utilizado no monitoramento das temperaturas. Ele mantém o programa executando enquanto houver novas leituras. O encerramento ocorre por meio das condições de saída (`break`), seja pela entrada `999` ou pela identificação de três temperaturas consecutivas acima do limite.

Também foi utilizado `while` para limpar entradas inválidas do teclado após uma tentativa de leitura não numérica.

## 5. Como executar

### Compilação

Em um terminal, dentro da pasta do projeto, execute:

```bash
gcc monitoramento.c -o monitoramento
```

### Execução no Linux/macOS

```bash
./monitoramento
```

### Execução no Windows

```bash
monitoramento.exe
```

## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

Foi informado um limite inválido e também foram inseridas temperaturas inválidas. O programa rejeitou os valores e solicitou novas entradas. As entradas inválidas não foram consideradas no relatório.

**Resultado:** teste aprovado.

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

Foi utilizado o limite de 30 °C e foram informadas temperaturas acima do limite intercaladas com temperaturas dentro do limite.

Exemplo de sequência:

`32, 28, 35, 29, 33, 27`

As temperaturas 32 °C, 35 °C e 33 °C ficaram acima do limite, mas não foram consecutivas. Sempre que uma temperatura ficou dentro do limite, o contador de consecutivas foi reiniciado.

**Resultado:** teste aprovado. O programa não encerrou automaticamente.

### Teste 3 — Três temperaturas consecutivas acima do limite

Foi utilizado o limite de 30 °C e foram informadas três temperaturas consecutivas acima do limite:

`31, 32, 33`

Na terceira ocorrência consecutiva, o programa encerrou automaticamente e apresentou o relatório final.

**Resultado:** teste aprovado.

As imagens dos três testes estão na pasta `evidencias/`.

## 7. Questão final de reflexão

### Por que você escolheu while, do...while ou uma combinação das duas estruturas? Em qual parte do algoritmo a diferença entre testar a condição antes ou depois da execução foi importante para sua solução?

Foi escolhida uma combinação de `do...while` e `while` porque cada estrutura se encaixa melhor em uma parte do algoritmo. O `do...while` foi utilizado para solicitar o limite de temperatura, pois essa entrada precisa acontecer pelo menos uma vez antes que sua validade seja verificada. Assim, a condição é testada depois da primeira execução.

Já o `while` foi utilizado no monitoramento das temperaturas, pois o programa precisa continuar recebendo leituras enquanto o monitoramento estiver ativo. Dentro desse laço, existem condições que podem encerrar o processo, como a entrada `999` ou a ocorrência de três temperaturas consecutivas acima do limite.

Dessa forma, a diferença entre testar a condição antes ou depois da execução foi importante principalmente na validação do limite: com `do...while`, a primeira tentativa de entrada é obrigatoriamente realizada antes da verificação.
