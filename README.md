# embarcados-acelerometro-giroscopio

## Créditos

Este tutorial é baseado na publicação do [how2electronics](https://how2electronics.com/interface-adxl345-accelerometer-with-arduino/)

### Visão geral

Com esse tutorial será possível capturar os dados gerados pelos sensores do acelerômetro `adxl345` e interagir com uma animação 3D utilizando o software Processing 3D IDE.

### Montagem do Circuito

![image](https://user-images.githubusercontent.com/22710963/80112333-5f8dd100-8557-11ea-8b88-a754d16ab305.png)

### Renderizando animação com o sensor

1 - Necessário instalar a [IDE Processing 3D](https://processing.org/download/)  

2 - Rodar o [programa Java](https://github.com/sganzerla/embarcados-giroscopio/blob/master/processing-3d/render-acelerometro.pde) dentro da IDE Processing 3D

3 - Alterar a porta Serial que está conectado o Arduino com o sensor, normalmente é encontrada no canto inferior direito da IDE do Arduino, ou VSCode. No Windows começam com `COM1, COM2` e no Linux `/dev/ttyUSB0`.

```
void setup() {
size(400, 300, P3D);
sp = new Serial(this, "/dev/ttyUSB0", 9600); //You have to rename your port in the "" and change the baud rate.
buff = new byte[128];
r = new float[3];
}
```

### Hardware necessário

```
- a) 1 Placa Arduino com cabo USB
- b) 1 Acelerômetro ADXL345
- c) 1 Protoboard
- d) 6 Cabos de conexão
```

#### a) Placa Arduino Uno

![image](https://user-images.githubusercontent.com/22710963/77551422-16cbf500-6e91-11ea-850d-7e3989c9f1f2.png)

#### b) Acelerômetro ADXL345

![image](https://user-images.githubusercontent.com/22710963/80141668-49483b00-8580-11ea-952f-ba84bd779e46.png)

#### c) Protoboard

![image](https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png)

#### d) Cabos de conexão

![image](https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png)

## Fonte

[how2electronics](https://how2electronics.com/interface-adxl345-accelerometer-with-arduino/) - Acessado em Maio 2020.
