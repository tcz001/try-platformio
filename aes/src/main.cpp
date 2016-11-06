#ifndef UNIT_TEST // disable program main loop while unit testing in progress

#include <Arduino.h>
#include "aes.h"

void setup() {
    delay(3000);
    Serial.begin(9600);
    Serial.println("Program started!");
}

void loop() {
    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    uint8_t in[64] = "Hello World";
    uint8_t *out;
    uint8_t *buffer;
    buffer = (unsigned uint8_t *)malloc(64 * sizeof(uint8_t));
    out = (unsigned uint8_t *)malloc(64 * sizeof(uint8_t));

    Serial.println("Encrypt...");
    aes::AES128_CBC_encrypt_buffer(buffer, in, 64, key, iv);
    Serial.println((char *)buffer);

    Serial.println("Decrypt...");
    aes::AES128_CBC_decrypt_buffer(out, buffer, 64, key, iv);
    Serial.println((char *)out);
    free(buffer);
    free(out);
    delay(5000);
}
#endif
