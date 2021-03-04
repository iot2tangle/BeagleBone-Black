CC=gcc
CFLAGS= -lpaho-mqtt3c -lm -I. -DBBBW -DSHELLPRINT -DMQTT
DEPS = core/beaglebonebw/basics.h core/beaglebonebw/peripherals/gpio/simpleBBB_GPIO.c core/beaglebonebw/peripherals/gpio/gpio.c core/beaglebonebw/peripherals/i2c/simpleBBB_I2C.c core/beaglebonebw/sensors/internal/internal.h core/beaglebonebw/sensors/bme280/bme280.h core/beaglebonebw/sensors/acoustic/acoustic.h core/beaglebonebw/sensors/bh1750/bh1750.h core/beaglebonebw/sensors/mpu6050/mpu6050.hcore/beaglebonebw/protocols/mqtt/mqtt.h
OBJ = core/beaglebonebw/basics.o core/beaglebonebw/peripherals/gpio/simpleBBB_GPIO.o core/beaglebonebw/peripherals/gpio/gpio.o core/beaglebonebw/peripherals/i2c/simpleBBB_I2C.o core/beaglebonebw/sensors/internal/internal.o core/beaglebonebw/sensors/bme280/bme280.o core/beaglebonebw/sensors/acoustic/acoustic.o core/beaglebonebw/sensors/bh1750/bh1750.o core/beaglebonebw/sensors/mpu6050/mpu6050.o core/beaglebonebw/protocols/mqtt/mqtt.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BeagleboneB-MQTT: $(OBJ)
	@echo "\nCompiling..."
	$(CC) -o $@ $^ $(CFLAGS) 
	@echo "\nCompiled Finished, now you can run your code with: '$ ./BeagleboneBW-MQTT'\n"
	@$ find . -name "*.o" -type f -delete

help:
	@echo "\n'make' to compile"
	@echo "'make clean' to delete .o files\n"

.PHONY: clean
clean:
	@$ find . -name "*.o" -type f -delete
