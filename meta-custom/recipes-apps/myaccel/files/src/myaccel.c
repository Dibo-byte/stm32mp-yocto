#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

// MPU6050 I2C address and register definitions
#define MPU6050_ADDR         0x68
#define MPU6050_REG_ACCEL_X  0x3B
#define MPU6050_REG_ACCEL_Y  0x3D
#define MPU6050_REG_ACCEL_Z  0x3F

// Function to read 16-bit signed integer from MPU6050
int16_t read_mpu6050_data(int fd, uint8_t reg) {
    uint8_t buf[2];
    int16_t data;

    // Set register address to read
    if (write(fd, &reg, 1) != 1) {
        perror("Failed to write to the I2C bus");
        exit(1);
    }

    // Read data
    if (read(fd, buf, 2) != 2) {
        perror("Failed to read from the I2C bus");
        exit(1);
    }

    // Combine bytes into signed 16-bit integer
    data = (buf[0] << 8) | buf[1];
    return data;
}

int main() {
    const char *i2c_device = "/dev/i2c-1"; // I2C device file
    int fd;
    int16_t accel_x, accel_y, accel_z;

    // Open I2C device
    if ((fd = open(i2c_device, O_RDWR)) < 0) {
        perror("Failed to open the I2C device");
        exit(1);
    }

    // Set MPU6050 I2C address
    if (ioctl(fd, I2C_SLAVE, MPU6050_ADDR) < 0) {
        perror("Failed to acquire bus access and/or talk to the MPU6050");
        exit(1);
    }

    // Read accelerometer data
    accel_x = read_mpu6050_data(fd, MPU6050_REG_ACCEL_X);
    accel_y = read_mpu6050_data(fd, MPU6050_REG_ACCEL_Y);
    accel_z = read_mpu6050_data(fd, MPU6050_REG_ACCEL_Z);

    // Close I2C device
    close(fd);

    // Print accelerometer data
    printf("Accelerometer Data:\n");
    printf("X-axis: %d\n", accel_x);
    printf("Y-axis: %d\n", accel_y);
    printf("Z-axis: %d\n", accel_z);

    return 0;
}

