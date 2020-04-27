# embarcados-acelerometro-giroscopio

## Conceitos

### Giroscópio

Sensores giroscópicos podem monitorar a orientação, direção, movimento angular e rotação. No smartphone, um sensor giroscópico geralmente executa funções de reconhecimento de gestos. Além disso, os giroscópios em smartphone ajudam a determinar a posição e orientação do aparelho.

### Acelerômetro

O acelerômetro é um sensor que mede aceleração, bem como a inclinação, ângulo de inclinação, rotação, vibração, colisão e gravidade. Quando utilizado em um smartphone, o acelerômetro pode mudar automaticamente o visor do celular na vertical ou horizontal, já que esse sensor pode verificar em que eixo vetor aceleração da gravidade atua.

## Modelos de Acelerômetros

### GY521 - [DataSheet](nodemcu-gy521/MPU-6000-Datasheet1.pdf)

Este sensor utiliza o MPU-6050 que é uma IMU (Inertial Measurement Unit), ela mede valores de aceleração em 3 eixos, X, Y e Z e velocidade angular também em X, Y e Z. Por isso esse sensor tem 6 graus de liberdade (6DOF). Os dados podem ser usados para sistemas de reconhecimento de gestos, navegação (GPS), jogos e diversas outras aplicações. Outro recurso adicional é o sensor de temperatura embutido no CI, que permite medições entre -40 e +85 ºC.

Essa placa utiliza o protocolo I2C para transmissão de dados.

Faixa de giroscópios +/- 250, 500, 1000 e 2000 graus/seg

Faixa de Aceleração +/- 2g, +/- 4g, +/- 8g e +/- 16g

Um exemplo de implementação com microntrolador [NodeMCU](nodemcu-gy521/README.md)

### ADXL345 -  [DataSheet](../embarcados-acelerometro-giroscopio/arduino-adxl345/ADXL345_SEN0032_datasheet_EN.pdf)

O ADXL345 é um acelerômetro de 3 eixos com alta resolução (13-bit) de medição de até ± 16 g,pequeno, fino e de baixo consumo de potência. Os dados digitais de saída são formatados como pares de 16 bits complementar e é acessível por meio de uma interface digital SPI (3 ou 4 fios) ou I2C.

O ADXL345 é bem adequado para medidas de aceleração estática de gravidade em aplicações de detecção de inclinação, bem como de aceleração dinâmica resultante do movimento ou choque. A sua alta resolução (4 mg / LSB) permite a medição de inclinação com variação de menos de 1,0 °. Ele ainda possui diversas funções especiais de leitura como:

- Detecção de Atividade ou inatividade para detectar a presença ou ausência de movimento e se a aceleração em qualquer eixo ultrapassa um nível definido pelo usuário.

- Detecção de toque detecta toques individuais e duplos.

- Detecção de queda livre detecta se o dispositivo está caindo.

Estas funções podem ser mapeadas a um dos dois pinos de saída de interrupção. Um sistema integrado de buffer FIFO (first in, first out) de 32 níveis pode ser usado para armazenar dados, minimizando a intervenção do processador. Modos de baixo consumo permitem o gerenciamento inteligente de energia com base em movimento com sensor de limite e medição de aceleração ativa com uma dissipação de energia extremamente baixa.

Essa placa utiliza o protocolo I2C ou SPI para transmissão de dados.

Um exemplo de implementação com microntrolador [Arduino](arduino-adxl345/README.md)

## Fonte

[Vida de Silício](https://www.vidadesilicio.com.br/modulo-gy-521-acelerometro-giroscopio) - Acessado em Maio 2020.

[Baú da Eletrônica](https://www.baudaeletronica.com.br/acelerometro-de-tres-eixos-adxl345-dfrobot.html) - Acessado em Maio 2020.

[Filipe Flop](https://www.filipeflop.com/blog/tutorial-acelerometro-mpu6050-arduino/) - Acessado em Maio 2020.
