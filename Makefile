all:
	arduino-cli compile --fqbn arduino:avr:uno Transmitter

run:
	arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno Transmitter
