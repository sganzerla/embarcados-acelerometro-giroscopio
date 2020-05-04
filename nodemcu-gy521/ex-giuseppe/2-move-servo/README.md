# 2-move-servo

## Objetivo

O programa tem o objetivo de fazer a leitura dos dados gerados pelo `GY521` conectado como `SLAVE` no protocolo `I2C` ao `NodeMCU` convertendo os dados dos eixos X e Y do acelerômetro para ângulos e movendo dois servos motores representando cada um dos eixos.

As conexões do `GY-521` com o `NodeMCU` devem ser as seguintes:

VCC -> 3v
GND -> G
SDA -> D2
SCL -> D1

Estando o sensor conectado corretamente a leitura na porta Serial será a seguinte:

```
Accelerometer: X = 3118 | Y = 883 | Z = 1510
Temperature: 17.89 C
Gyroscope: X = -112 | Y = 12 | Z = -161

Accelerometer: X = 3099 | Y = 893 | Z = 1510
Temperature: 17.89 C
Gyroscope: X = -113 | Y = 14 | Z = -151

```
