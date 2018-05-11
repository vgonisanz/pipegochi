#include "Arduino.h"
#include <Wire.h>

/* Configuration */
const uint8_t INIT_ADDRESS = 1;
const uint8_t MAX_ADDRESS = 127;
const uint16_t SCAN_DELAY_IN_MS = 3000; /* 3s between loops */
const uint32_t UART_BAUDS = 9600;

/* Checkout Wire reference: https://www.arduino.cc/en/Reference/WireEndTransmission */
enum i2c_error
{
    i2c_success = 0,        /* Transmission ends ok */
    i2c_data_too_long,      /* Data too long to fit in transmit buffer */
    i2c_nack_on_address,    /* Received NACK on transmit of address */
    i2c_nack_on_data,       /* Received NACK on transmit of data */
    i2c_other_error         /* Other */
};

uint8_t check_error(uint8_t error, uint8_t address, uint8_t nDevicesFound)
{
    switch(error)
    {
        case i2c_success:
            Serial.print("I2C device found at address 0x");
            Serial.print(address, HEX);
            Serial.println("");
            nDevicesFound += 1;
            break;
        case i2c_data_too_long:
            Serial.print("I2C data tool long at address 0x");
            Serial.print(address, HEX);
            Serial.println("");
            break;
        case i2c_nack_on_address:   /* Avoid too much prints when device not found */
            //Serial.print("I2C NACK on address at address 0x");
            //Serial.print(address, DEC);
            //Serial.println("");
            break;
        case i2c_nack_on_data:
            Serial.print("I2C NACK on data at address 0x");
            Serial.print(address, HEX);
            Serial.println("");
            break;
        case i2c_other_error:
            Serial.print("Unknown error at address 0x");
            Serial.print(address, HEX);
            Serial.println("");
            break;
        default:
            Serial.print("Unregistered error");
            Serial.print(address, HEX);
            Serial.println("");
            break;
    }
    return nDevicesFound;
}

void scan()
{
    uint8_t address;    /* Scan 1 - 127 addresses */
    uint8_t error;      /* Error code given in scan */
    uint8_t nDevicesFound = 0;
    Serial.println("I2C scan...");
    for(address = INIT_ADDRESS; address < MAX_ADDRESS; address++ )
    {
        //Serial.print("Checking address: ");
        //Serial.print(address, HEX);
        //Serial.println("");
        Wire.beginTransmission(address);
        error = Wire.endTransmission(); /* Shall return info to check if exist i2c device at this address */
        nDevicesFound = check_error(error, address, nDevicesFound);
    }
    Serial.print("I2C devices found: ");
    Serial.print(nDevicesFound, DEC);
    Serial.println(".");
}

void scan_pause()
{
    Serial.print("Waiting ");
    Serial.print(SCAN_DELAY_IN_MS, DEC);
    Serial.println("ms for next scan.");
    Serial.println("");
    Serial.println("-------------------------------------------------");
    Serial.println("");
    delay(SCAN_DELAY_IN_MS);
}

void setup(void)
{
    Serial.begin(UART_BAUDS);
    Serial.println("Welcome to scan i2c sample...\n");
    Serial.println("Configuring Wire...\n");
    Wire.begin();
}

void loop(void)
{
    scan();
    scan_pause();
}
