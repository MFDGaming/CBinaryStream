/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the MIT license
 */

#include "binary_stream.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

int8_t *get_bytes(size_t count, binary_stream_t *stream)
{
	int8_t *result = (int8_t *) malloc(count);
	size_t i;
	for (i = 0; i < count; ++i) {
		result[i] = stream->buffer[stream->offset];
		++stream->offset;
	}
	return result;
}

int8_t *get_remaining_bytes(binary_stream_t *stream)
{
	return get_bytes(stream->size - stream->offset, stream);
}

uint8_t get_unsigned_byte(binary_stream_t *stream)
{
	uint8_t value = ((uint8_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	return value;
}

int8_t get_byte(binary_stream_t *stream)
{
	uint8_t raw = get_unsigned_byte(stream);
	return *(int8_t*)&raw;
}

bool get_bool(binary_stream_t *stream)
{
	return (get_unsigned_byte(stream) != 0) ? true : false;
}

uint16_t get_unsigned_short_le(binary_stream_t *stream)
{
	uint16_t value = ((uint16_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	value |= ((uint16_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	return value;
}

uint16_t get_unsigned_short_be(binary_stream_t *stream)
{
	uint16_t value = ((uint16_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	value |= ((uint16_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	return value;
}

int16_t get_short_le(binary_stream_t *stream)
{
	uint16_t raw = get_unsigned_short_le(stream);
	return *(int16_t*)&raw;
}

int16_t get_short_be(binary_stream_t *stream)
{
	uint16_t raw = get_unsigned_short_be(stream);
	return *(int16_t*)&raw;
}

uint32_t get_unsigned_triad_le(binary_stream_t *stream)
{
	uint32_t value = ((uint32_t) stream->buffer[stream->offset] & 0xff);
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 16;
	++stream->offset;
	return value;
}

uint32_t get_unsigned_triad_be(binary_stream_t *stream)
{
	uint32_t value = ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 16;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	value |= ((uint32_t) stream->buffer[stream->offset] & 0xff);
	++stream->offset;
	return value;
}

int32_t get_triad_le(binary_stream_t *stream)
{
	uint32_t raw = get_unsigned_triad_le(stream);
	return *(int32_t*)&raw;
}

int32_t get_triad_be(binary_stream_t *stream)
{
	uint32_t raw = get_unsigned_triad_be(stream);
	return *(int32_t*)&raw;
}

uint32_t get_unsigned_int_le(binary_stream_t *stream)
{
	uint32_t value = ((uint32_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 16;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 24;
	++stream->offset;
	return value;
}

uint32_t get_unsigned_int_be(binary_stream_t *stream)
{
	uint32_t value = ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 24;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 16;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff)) << 8;
	++stream->offset;
	value |= ((uint32_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	return value;
}

int32_t get_int_le(binary_stream_t *stream)
{
	uint32_t raw = get_unsigned_int_le(stream);
	return *(int32_t*)&raw;
}

int32_t get_int_be(binary_stream_t *stream)
{
	uint32_t raw = get_unsigned_int_be(stream);
	return *(int32_t*)&raw;
}

uint64_t get_unsigned_long_le(binary_stream_t *stream)
{
	uint64_t value = ((uint64_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 8);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 16);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 24);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 32);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 40);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 48);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 56);
	++stream->offset;
	return value;
}

uint64_t get_unsigned_long_be(binary_stream_t *stream)
{
	uint64_t value = ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 56);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 48);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 40);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 32);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 24);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 16);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff)) << ((uint64_t) 8);
	++stream->offset;
	value |= ((uint64_t) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	return value;
}

int64_t get_long_le(binary_stream_t *stream)
{
	uint64_t raw = get_unsigned_long_le(stream);
	return *(int64_t*)&raw;
}

int64_t get_long_be(binary_stream_t *stream)
{
	uint64_t raw = get_unsigned_long_be(stream);
	return *(int64_t*)&raw;
}

uint32_t get_var_int(binary_stream_t *stream)
{
	uint32_t value = 0;
	int i;
	for (i = 0; i < 35; i += 7) {
		uint8_t to_read = get_unsigned_byte(stream);
		value |= ((to_read & 0x7f) << i);
		if ((to_read & 0x80) == 0) {
			return value;
		}
	}
	return 0;
}

int32_t get_signed_var_int(binary_stream_t *stream)
{
	uint32_t raw = get_var_int(stream);
	return (raw >> 1) ^ (-1 * (raw & 1));
}

uint64_t get_var_long(binary_stream_t *stream)
{
	uint64_t value = 0;
	int i;
	for (i = 0; i < 70; i += 7) {
		uint8_t to_read = get_unsigned_byte(stream);
		value |= (((uint64_t) (to_read & 0x7f)) << ((uint64_t) i));
		if ((to_read & 0x80) == 0) {
			return value;
		}
	}
	return 0;
}

int64_t get_signed_var_long(binary_stream_t *stream)
{
	uint64_t raw = get_var_long(stream);
	return ((int64_t) (raw >> 1)) ^ (-1 * ((int64_t) (raw & 1)));
}

float get_float_le(binary_stream_t *stream)
{
	uint32_t i = get_unsigned_int_le(stream);
	float f;
	memcpy(&f, &i, sizeof(f));
	return f;
}

float get_float_be(binary_stream_t *stream)
{
	uint32_t i = get_unsigned_int_be(stream);
	float f;
	memcpy(&f, &i, sizeof(f));
	return f;
}

double get_double_le(binary_stream_t *stream)
{
	uint64_t l = get_unsigned_long_le(stream);
	double f;
	memcpy(&f, &l, sizeof(f));
	return f;
}

double get_double_be(binary_stream_t *stream)
{
	uint64_t l = get_unsigned_long_be(stream);
	double f;
	memcpy(&f, &l, sizeof(f));
	return f;
}

void put_bytes(int8_t *data, size_t size, binary_stream_t *stream)
{
	size_t i;
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + size);
	for (i = 0; i < size; ++i) {
		stream->buffer[stream->size] = data[i];
		++stream->size;
	}
}

void put_unsigned_byte(uint8_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 1);
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_byte(int8_t value, binary_stream_t *stream)
{
	put_unsigned_byte(value & 0xff, stream);
}

void put_bool(bool value, binary_stream_t *stream)
{
	put_unsigned_byte((value != false) ? 1 : 0, stream);
}

void put_unsigned_short_le(uint16_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 2);
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
}

void put_unsigned_short_be(uint16_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 2);
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_short_le(int16_t value, binary_stream_t *stream)
{
	put_unsigned_short_le(value & 0xffff, stream);
}

void put_short_be(int16_t value, binary_stream_t *stream)
{
	put_unsigned_short_be(value & 0xffff, stream);
}

void put_unsigned_triad_le(uint32_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 3);
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
}

void put_unsigned_triad_be(uint32_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 3);
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_triad_le(int32_t value, binary_stream_t *stream)
{
	put_unsigned_triad_le(value & 0xffffff, stream);
}

void put_triad_be(int32_t value, binary_stream_t *stream)
{
	put_unsigned_triad_be(value & 0xffffff, stream);
}

void put_unsigned_int_le(uint32_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 4);
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
}

void put_unsigned_int_be(uint32_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 4);
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_int_le(int32_t value, binary_stream_t *stream)
{
	put_unsigned_int_le(value & 0xffffffff, stream);
}

void put_int_be(int32_t value, binary_stream_t *stream)
{
	put_unsigned_int_be(value & 0xffffffff, stream);
}

void put_unsigned_long_le(uint64_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 8);
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 32) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 40) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 48) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 56) & 0xff;
	++stream->size;
}

void put_unsigned_long_be(uint64_t value, binary_stream_t *stream)
{
	stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 8);
	stream->buffer[stream->size] = (value >> 56) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 48) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 40) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 32) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_long_le(int64_t value, binary_stream_t *stream)
{
	put_unsigned_long_le(value & 0xffffffffffffffff, stream);
}

void put_long_be(int64_t value, binary_stream_t *stream)
{
	put_unsigned_long_be(value & 0xffffffffffffffff, stream);
}

void put_var_int(uint32_t value, binary_stream_t *stream)
{
	value &= 0xffffffff;
	int i;
	for (i = 0; i < 5; ++i) {
		uint8_t to_write = value & 0x7f;
		value >>= 7;
		stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 1);
		if (value != 0) {
			stream->buffer[stream->size] = (to_write | 0x80);
			++stream->size;
		} else {
			stream->buffer[stream->size] = to_write;
			++stream->size;
			break;
		}
	}
}

void put_signed_var_int(int32_t value, binary_stream_t *stream)
{
	put_var_int(value >= 0 ? (((uint32_t) value) << 1) : ((((uint32_t) (-1 - value)) << 1) | 0x01), stream);
}

void put_var_long(uint64_t value, binary_stream_t *stream)
{
	value &= 0xffffffffffffffff;
	int i;
	for (i = 0; i < 10; ++i) {
		uint8_t to_write = value & 0x7f;
		value >>= 7;
		stream->buffer = (int8_t *) realloc(stream->buffer, stream->size + 1);
		if (value != 0) {
			stream->buffer[stream->size] = (to_write | 0x80);
			++stream->size;
		} else {
			stream->buffer[stream->size] = to_write;
			++stream->size;
			break;
		}
	}
}

void put_signed_var_long(int64_t value, binary_stream_t *stream)
{
	put_var_long(value >= 0 ? (((uint64_t) value) << 1) : ((((uint64_t) (-1 - value)) << 1) | 0x01), stream);
}

void put_float_le(float value, binary_stream_t *stream)
{
	uint32_t i;
	memcpy(&i, &value, sizeof(i));
	put_unsigned_int_le(i, stream);
}

void put_float_be(float value, binary_stream_t *stream)
{
	uint32_t i;
	memcpy(&i, &value, sizeof(i));
	put_unsigned_int_be(i, stream);
}

void put_double_le(double value, binary_stream_t *stream)
{
	uint64_t l;
	memcpy(&l, &value, sizeof(l));
	put_unsigned_long_le(l, stream);
}

void put_double_be(double value, binary_stream_t *stream)
{
	uint64_t l;
	memcpy(&l, &value, sizeof(l));
	put_unsigned_long_be(l, stream);
}

#ifdef __cplusplus
}
#endif
