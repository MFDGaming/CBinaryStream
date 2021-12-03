/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the GPL v2.0 license
 */

#ifndef BINARY_STREAM_H
#define BINARY_STREAM_H

#include <stdint.h>

typedef struct {
	char *buffer;
	int size;
	int offset;
} binary_stream_t;

char *get_bytes(int count, binary_stream_t *stream);

char *get_remaining_bytes(binary_stream_t *stream);

uint8_t get_unsigned_byte(binary_stream_t *stream);

int8_t get_byte(binary_stream_t *stream);

uint16_t get_unsigned_short_le(binary_stream_t *stream);

uint16_t get_unsigned_short_be(binary_stream_t *stream);

int16_t get_short_le(binary_stream_t *stream);

int16_t get_short_be(binary_stream_t *stream);

uint24_t get_unsigned_triad_le(binary_stream_t *stream);

uint24_t get_unsigned_triad_be(binary_stream_t *stream);

int24_t get_triad_le(binary_stream_t *stream);

int24_t get_triad_be(binary_stream_t *stream);

uint32_t get_unsigned_int_le(binary_stream_t *stream);

uint32_t get_unsigned_int_be(binary_stream_t *stream);

int32_t get_int_le(binary_stream_t *stream);

int32_t get_int_be(binary_stream_t *stream);

uint64_t get_unsigned_long_le(binary_stream_t *stream);

uint64_t get_unsigned_long_be(binary_stream_t *stream);

int64_t get_long_le(binary_stream_t *stream);

int64_t get_long_be(binary_stream_t *stream);

uint32_t get_var_int(binary_stream_t *stream);

int32_t get_signed_var_int(binary_stream_t *stream);

uint64_t get_var_long(binary_stream_t *stream);

int64_t get_signed_var_long(binary_stream_t *stream);

float get_float_le(binary_stream_t *stream);

float get_float_be(binary_stream_t *stream);

double get_double_le(binary_stream_t *stream);

double get_double_be(binary_stream_t *stream);

void put_bytes(char *data, int size, binary_stream_t *stream);

void put_unsigned_byte(uint8_t value, binary_stream_t *stream);

void put_byte(int8_t value, binary_stream_t *stream);

void put_unsigned_short_le(uint16_t value, binary_stream_t *stream);

void put_unsigned_short_be(uint16_t value, binary_stream_t *stream);

void put_short_le(int16_t value, binary_stream_t *stream);

void put_short_be(int16_t value, binary_stream_t *stream);

void put_unsigned_triad_le(uint24_t value, binary_stream_t *stream);

void put_unsigned_triad_be(uint24_t value, binary_stream_t *stream);

void put_triad_le(int24_t value, binary_stream_t *stream);

void put_triad_be(int24_t value, binary_stream_t *stream);

void put_unsigned_int_le(uint32_t value, binary_stream_t *stream);

void put_unsigned_int_be(uint32_t value, binary_stream_t *stream);

void put_int_le(int32_t value, binary_stream_t *stream);

void put_int_be(int32_t value, binary_stream_t *stream);

void put_unsigned_long_le(uint64_t value, binary_stream_t *stream);

void put_unsigned_long_be(uint64_t value, binary_stream_t *stream);

void put_long_le(int64_t value, binary_stream_t *stream);

void put_long_be(int64_t value, binary_stream_t *stream);

void put_var_int(uint32_t value, binary_stream_t *stream);

void put_signed_var_int(int32_t value, binary_stream_t *stream);

void put_var_long(uint64_t value, binary_stream_t *stream);

void put_signed_var_long(int64_t value, binary_stream_t *stream);

void put_float_le(float value, binary_stream_t *stream);

void put_float_be(float value, binary_stream_t *stream);

void put_double_le(double value, binary_stream_t *stream);

void put_double_be(double value, binary_stream_t *stream);

#endif
