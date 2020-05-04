# 0-can-i2c

## Objetivo

O programa tem o objetivo de percorrer todos os 128 endereços possíveis e identificar se há algum dispositivo `SLAVE` conectado no protocolo `I2C`.

As conexões do `GY-521` com o `NodeMCU` devem ser as seguintes:

VCC -> 3v
GND -> G
SDA -> D2
SCL -> D1

Estando o sensor conectado corretamente a leitura na porta Serial será a seguinte:

```
Scanning...
I2C device found at address 0x68  !
done
```
