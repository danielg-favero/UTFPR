# Escolonadores de processos

## FCFS

Fila FIFO (First-in First-out)

### Exemplo

#### Processos

| Processo | Tempo de CPU | Prioridade |
|:--------:|:------------:|:----------:|
| P1       | 10           | 3          |
| P2       | 1            | 1          |
| P3       | 2            | 3          |
| P4       | 1            | 4          |
| P5       | 5            | 2          |

#### Diagrama de Gant

| Processo |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|----------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| P1       | - | - | - | - | - | - | - | - | - | - |   |   |   |   |   |   |   |   |   |
| P2       |   |   |   |   |   |   |   |   |   |   | - |   |   |   |   |   |   |   |   |
| P3       |   |   |   |   |   |   |   |   |   |   |   | - | - |   |   |   |   |   |   |
| P4       |   |   |   |   |   |   |   |   |   |   |   |   |   | - |   |   |   |   |   |
| P5       |   |   |   |   |   |   |   |   |   |   |   |   |   |   | - | - | - | - | - |

> Tempo Médio: (0 + 10 + 11 + 13 + 14) / 5 = 9,6 u.t

## SJF

Shortest Job First, executa o processo que toma menos tempo na CPU, porém, esse processo é apenas ideal, pois não é possível saber quanto tempo um processo irá tomar da CPU.

#### Processos

| Processo | Tempo de CPU | Prioridade |
|:--------:|:------------:|:----------:|
| P1       | 10           | 3          |
| P2       | 1            | 1          |
| P3       | 2            | 3          |
| P4       | 1            | 4          |
| P5       | 5            | 2          |

#### Diagrama de Gant

| Processo |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|----------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| P1 |   |   |   |   |   |   |   |   |   | - | - | - | - | - | - | - | - | - | - |
| P2 | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| P3 |   |   | - | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| P4 |   | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| P5 |   |   |   |   | - | - | - | - | - |   |   |   |   |   |   |   |   |   |   |

> Tempo médio: (0 + 1 + 2 + 4 + 9) / 5 = 3,2 u.t