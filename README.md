# Tarefa: Controle de Servomotor por PWM

## Descrição do Projeto
Este projeto implementa o controle de um **servomotor** utilizando o **microcontrolador Raspberry Pi Pico W** e o módulo **PWM (Pulse Width Modulation)**. O sistema ajusta o ângulo do servomotor entre **0º e 180º** por meio da variação do **duty cycle** do sinal PWM.

A simulação é realizada no **Wokwi**, utilizando um **motor micro servo padrão** conectado à **GPIO 22** do **Raspberry Pi Pico W**.

O projeto também inclui um experimento com a ferramenta **BitDogLab**, utilizando um LED RGB na **GPIO 12**, para analisar o comportamento da iluminação do LED durante a operação do PWM.

---

## Requisitos
1. **Configuração do PWM na GPIO 22:**  
   - Frequência de **50 Hz** (período de **20 ms**).  
   
2. **Controle de Posições Específicas do Servo:**  
   - **180º:** Duty cycle de **2400 µs (2,4 ms)**, com espera de **5 segundos**.  
   - **90º:** Duty cycle de **1470 µs (1,47 ms)**, com espera de **5 segundos**.  
   - **0º:** Duty cycle de **500 µs (0,5 ms)**, com espera de **5 segundos**.  

3. **Movimentação Suave do Servo:**  
   - O servo deve oscilar continuamente entre **0º e 180º**.  
   - O ajuste do **duty cycle** deve ser feito em **incrementos de ±5 µs**, com um atraso de **10 ms** por passo.  

4. **Experimento com a Ferramenta BitDogLab:**  
   - Utilizar um **LED RGB na GPIO 12** para observar seu comportamento quando o PWM do servo está ativo.  

---

## Configuração do Hardware
### Componentes Simulados no Wokwi
- **Microcontrolador Raspberry Pi Pico W**  
- **Servomotor – Motor micro servo padrão**  
- **LED RGB – Conectado à GPIO 12**  

## Compilação e Execução

1. Clone o repositório do projeto.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico.
3. Compile o código usando o CMake:
4. Carregue o binário no Raspberry Pi Pico.

###  Testando no Simulador
Se quiser testar no **Wokwi**, abra o arquivo `diagram.json` e inicie a simulação.

## Experimento com BitDogLab
Durante a execução do código, o **LED RGB** conectado ao **GPIO 12** apresentou variações na intensidade da luz devido à modulação do sinal PWM. Ele foi variando a intensidade de acordo com o valor do dute cycle, tendo maior intensidade quando o dute cycle estava em 2400Us e menor quando estava em 500Us. Depois de entrar na função de rotina, ficou bem claro que a luminosidade do led estava variando de acordo com o dute cycle, ela foi diminuindo/aumentando quando o dute foi sendo incrementado/decrementado.

---

##  Link do video
 **Assista o video**:
https://youtu.be/loNZiQ3Vgks
 

---

##  Equipe de Desenvolvimento
| Nome | GitHub |
|------|--------|
| Guilherme Lopes | [@GuilhermeFRLopes](https://github.com/GuilhermeFRLopes) |


