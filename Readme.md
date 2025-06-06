🚨 Monitor de Nível de Rio com Alerta de Segurança
📌 Descrição do Problema
Enchentes em áreas próximas a rios podem causar sérios danos materiais e colocar vidas humanas em risco. Uma das formas mais eficazes de prevenção é o monitoramento contínuo do nível da água para identificar situações de risco antes que se agravem.

Este projeto visa oferecer uma solução acessível e educativa para o monitoramento de rios usando um sensor de distância ultrassônico. O sistema alerta a população local automaticamente quando o nível da água atinge um patamar perigoso.

💡 Visão Geral da Solução
Componentes Utilizados:
Arduino UNO

Sensor Ultrassônico HC-SR04 (TRIG/ECHO)

Display LCD 16x2 com interface I2C

Buzzer (alarme sonoro)

Cabos e Protoboard

Funcionamento:
O sensor mede a distância entre ele e a superfície do rio.

Essa distância é convertida em um valor de nível de água (em cm), considerando uma simulação de até 8 metros de profundidade.

O nível é mostrado no display LCD.

Um buzzer é ativado quando o nível ultrapassa 700 cm (7 metros), indicando situação de perigo.

A mensagem de alerta também é enviada pela porta serial.

