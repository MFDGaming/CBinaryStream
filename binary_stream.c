/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the GPL v2.0 license
 */

#include "binary_stream.h"
#include <stdlib.h>
#include <string.h>

char *get_bytes(int count, binary_stream_t *stream) {
	char *result = malloc(count * sizeof(char));
	for (int i = 0; i < count; ++i) {
		result[i] = stream->buffer[stream->offset];
		++stream->offset;
	}
	return result;
}

char *get_remaining_bytes(binary_stream_t *stream) {
	return get_bytes(stream->size - stream->offset - 1, stream);
}

unsigned char get_unsigned_byte(binary_stream_t *stream) {
	unsigned char value = stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	return value;
}

char get_byte(binary_stream_t *stream) {
	unsigned char raw = get_unsigned_byte(stream);
	return *(char*)&raw;
}

unsigned short get_unsigned_short_le(binary_stream_t *stream) {
	unsigned short value = stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	return value;
}

unsigned short get_unsigned_short_be(binary_stream_t *stream) {
	unsigned short value = (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	value |= stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	return value;
}

short get_short_le(binary_stream_t *stream) {
	unsigned short raw = get_unsigned_short_le(stream);
	return *(short*)&raw;
}

short get_short_be(binary_stream_t *stream) {
	unsigned short raw = get_unsigned_short_be(stream);
	return *(short*)&raw;
}

unsigned int get_unsigned_triad_le(binary_stream_t *stream) {
	unsigned int value = stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 16;
	++stream->offset;
	return value;
}

unsigned int get_unsigned_triad_be(binary_stream_t *stream) {
	unsigned int value = (stream->buffer[stream->offset] & 0xff) << 16;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	value |= stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	return value;
}

unsigned int get_unsigned_int_le(binary_stream_t *stream) {
	unsigned int value = stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 16;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 24;
	++stream->offset;
	return value;
}

unsigned int get_unsigned_int_be(binary_stream_t *stream) {
	unsigned int value = (stream->buffer[stream->offset] & 0xff) << 24;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 16;
	++stream->offset;
	value |= (stream->buffer[stream->offset] & 0xff) << 8;
	++stream->offset;
	value |= stream->buffer[stream->offset] & 0xff;
	++stream->offset;
	return value;
}

int get_int_le(binary_stream_t *stream) {
	unsigned int raw = get_unsigned_int_le(stream);
	return *(int*)&raw;
}

int get_int_be(binary_stream_t *stream) {
	unsigned int raw = get_unsigned_int_be(stream);
	return *(int*)&raw;
}

unsigned long long get_unsigned_long_le(binary_stream_t *stream) {
	unsigned long long value = ((unsigned long long) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 8);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 16);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 24);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 32);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 40);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 48);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 56);
	++stream->offset;
	return value;
}

unsigned long long get_unsigned_long_be(binary_stream_t *stream) {
	unsigned long long value = ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 56);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 48);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 40);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 32);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 24);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 16);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff)) << ((unsigned long long) 8);
	++stream->offset;
	value |= ((unsigned long long) (stream->buffer[stream->offset] & 0xff));
	++stream->offset;
	return value;
}

long long get_long_le(binary_stream_t *stream) {
	unsigned long long raw = get_unsigned_long_le(stream);
	return *(long long*)&raw;
}

long long get_long_be(binary_stream_t *stream) {
	unsigned long long raw = get_unsigned_long_be(stream);
	return *(long long*)&raw;
}

unsigned int get_var_int(binary_stream_t *stream) {
	unsigned int value = 0;
	for (int i = 0; i < 35; i += 7) {
		unsigned char to_read = get_unsigned_byte(stream);
		value |= ((to_read & 0x7f) << i);
		if ((to_read & 0x80) == 0) {
			return value;
		}
	}
}

int get_signed_var_int(binary_stream_t *stream) {
	unsigned int raw = get_var_int(stream);
	return (raw >> 1) ^ (-1 * (raw & 1));
}

unsigned long long get_var_long(binary_stream_t *stream) {
	unsigned long long value = 0;
	for (int i = 0; i < 70; i += 7) {
		unsigned char to_read = get_unsigned_byte(stream);
		value |= (((unsigned long long) (to_read & 0x7f)) << ((unsigned long long) i));
		if ((to_read & 0x80) == 0) {
			return value;
		}
	}
}

long long get_signed_var_long(binary_stream_t *stream) {
	unsigned long long raw = get_var_long(stream);
	return ((long long) (raw >> 1)) ^ (-1 * ((long long) (raw & 1)));
}

float get_float_le(binary_stream_t *stream) {
	unsigned int i = get_unsigned_int_le(stream);
	float f;
	memcpy(&f, &i, sizeof(f));
	return f;
}

float get_float_be(binary_stream_t *stream) {
	unsigned int i = get_unsigned_int_be(stream);
	float f;
	memcpy(&f, &i, sizeof(f));
	return f;
}

double get_double_le(binary_stream_t *stream) {
	unsigned long long l = get_unsigned_long_le(stream);
	double f;
	memcpy(&f, &l, sizeof(f));
	return f;
}

double get_double_be(binary_stream_t *stream) {
	unsigned long long l = get_unsigned_long_be(stream);
	double f;
	memcpy(&f, &l, sizeof(f));
	return f;
}

void put_bytes(char *data, int size, binary_stream_t *stream) {
	for (int i = 0; i < size; ++i) {
		stream->buffer = realloc(stream->buffer, (stream->size + 1) * sizeof(char));
		stream->buffer[stream->size] = data[i];
		++stream->size;
	}
}

void put_unsigned_byte(unsigned char value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 1) * sizeof(char));
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_byte(char value, binary_stream_t *stream) {
	put_unsigned_byte(value & 0xff, stream);
}

void put_unsigned_short_le(unsigned short value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 2) * sizeof(char));
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
}


void put_unsigned_short_be(unsigned short value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 2) * sizeof(char));
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_short_le(short value, binary_stream_t *stream) {
	put_unsigned_short_le(value & 0xffff, stream);
}

void put_short_be(short value, binary_stream_t *stream) {
	put_unsigned_short_be(value & 0xffff, stream);
}

void put_unsigned_triad_le(unsigned int value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 3) * sizeof(char));
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
}

void put_unsigned_triad_be(unsigned int value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 3) * sizeof(char));
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_unsigned_int_le(unsigned int value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 4) * sizeof(char));
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
}


void put_unsigned_int_be(unsigned int value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 4) * sizeof(char));
	stream->buffer[stream->size] = (value >> 24) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 16) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = (value >> 8) & 0xff;
	++stream->size;
	stream->buffer[stream->size] = value & 0xff;
	++stream->size;
}

void put_int_le(int value, binary_stream_t *stream) {
	put_unsigned_int_le(value & 0xffffffff, stream);
}

void put_int_be(int value, binary_stream_t *stream) {
	put_unsigned_int_be(value & 0xffffffff, stream);
}

void put_unsigned_long_le(unsigned long long value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 8) * sizeof(char));
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

void put_unsigned_long_be(unsigned long long value, binary_stream_t *stream) {
	stream->buffer = realloc(stream->buffer, (stream->size + 8) * sizeof(char));
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

void put_long_le(long long value, binary_stream_t *stream) {
	put_unsigned_long_le(value & 0xffffffffffffffff, stream);
}

void put_long_be(long long value, binary_stream_t *stream) {
	put_unsigned_long_be(value & 0xffffffffffffffff, stream);
}

void put_var_int(unsigned int value, binary_stream_t *stream) {
	value &= 0xffffffff;
	for (int i = 0; i < 5; ++i) {
		unsigned char to_write = value & 0x7f;
		value >>= 7;
		stream->buffer = realloc(stream->buffer, (stream->size + 1) * sizeof(char));
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

void put_signed_var_int(int value, binary_stream_t *stream) {
	put_var_int((value << 1) ^ (value >> 31), stream);
}

void put_var_long(unsigned long long value, binary_stream_t *stream) {
	value &= 0xffffffffffffffff;
	for (int i = 0; i < 10; ++i) {
		unsigned char to_write = value & 0x7f;
		value >>= 7;
		stream->buffer = realloc(stream->buffer, (stream->size + 1) * sizeof(char));
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

void put_signed_var_long(long long value, binary_stream_t *stream) {
	put_var_long((value << 1) ^ (value >> 63), stream);
}

void put_float_le(float value, binary_stream_t *stream) {
	unsigned int i;
	memcpy(&i, &value, sizeof(i));
	put_unsigned_int_le(i, stream);
}

void put_float_be(float value, binary_stream_t *stream) {
	unsigned int i;
	memcpy(&i, &value, sizeof(i));
	put_unsigned_int_be(i, stream);
}

void put_double_le(double value, binary_stream_t *stream) {
	unsigned long long l;
	memcpy(&l, &value, sizeof(l));
	put_unsigned_long_le(l, stream);
}

void put_double_be(double value, binary_stream_t *stream) {
	unsigned long long l;
	memcpy(&l, &value, sizeof(l));
	put_unsigned_long_be(l, stream);
}
