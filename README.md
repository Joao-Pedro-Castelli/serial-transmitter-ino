# Setup

Instala o arduino-cli: https://arduino.github.io/arduino-cli/1.4/installation/

Execute os seguintes comandos:

`arduino-cli core update-indexl`
`arduino-cli core install arduino:avr`

Para compilar o projeto:

`arduino-cli compile --fqbn arduino:avr:uno Transmitter`

Finalmente, coloque o código no arduino

`arduino-cli upload -p /dev/[porta] --fqbn arduino:avr:uno Transmitter`

onde [porta] é o arquivo onde está conectado o arduino. Você pode
verificá-lo no campo "Port" com o comando

`arduino-cli board list`
