/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the MIT license
 */

#ifndef MFDGAMING_BINARY_STREAM_H
#define MFDGAMING_BINARY_STREAM_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct binary_stream {
    uint8_t *buffer;
    size_t size;
    size_t storage_size;
    size_t offset;
} binary_stream_t;

bool binary_stream_read(binary_stream_t *stream, size_t size, uint8_t **output);

void binary_stream_write(binary_stream_t *stream, uint8_t *buffer, size_t size);

bool binary_stream_read_u8(binary_stream_t *stream, uint8_t *output);

void binary_stream_write_u8(binary_stream_t *stream, uint8_t input);

bool binary_stream_read_i8(binary_stream_t *stream, int8_t *output);

void binary_stream_write_i8(binary_stream_t *stream, int8_t input);

bool binary_stream_read_u16le(binary_stream_t *stream, uint16_t *output);

void binary_stream_write_u16le(binary_stream_t *stream, uint16_t input);

bool binary_stream_read_i16le(binary_stream_t *stream, int16_t *output);

void binary_stream_write_i16le(binary_stream_t *stream, int16_t input);

bool binary_stream_read_u16be(binary_stream_t *stream, uint16_t *output);

void binary_stream_write_u16be(binary_stream_t *stream, uint16_t input);

bool binary_stream_read_i16be(binary_stream_t *stream, int16_t *output);

void binary_stream_write_i16be(binary_stream_t *stream, int16_t input);

bool binary_stream_read_u24le(binary_stream_t *stream, uint32_t *output);

void binary_stream_write_u24le(binary_stream_t *stream, uint32_t input);

bool binary_stream_read_u24be(binary_stream_t *stream, uint32_t *output);

void binary_stream_write_u24be(binary_stream_t *stream, uint32_t input);

bool binary_stream_read_u32le(binary_stream_t *stream, uint32_t *output);

void binary_stream_write_u32le(binary_stream_t *stream, uint32_t input);

bool binary_stream_read_i32le(binary_stream_t *stream, int32_t *output);

void binary_stream_write_i32le(binary_stream_t *stream, int32_t input);

bool binary_stream_read_u32be(binary_stream_t *stream, uint32_t *output);

void binary_stream_write_u32be(binary_stream_t *stream, uint32_t input);

bool binary_stream_read_i32be(binary_stream_t *stream, int32_t *output);

void binary_stream_write_i32be(binary_stream_t *stream, int32_t input);

bool binary_stream_read_u64le(binary_stream_t *stream, uint64_t *output);

void binary_stream_write_u64le(binary_stream_t *stream, uint64_t input);

bool binary_stream_read_i64le(binary_stream_t *stream, int64_t *output);

void binary_stream_write_i64le(binary_stream_t *stream, int64_t input);

bool binary_stream_read_u64be(binary_stream_t *stream, uint64_t *output);

void binary_stream_write_u64be(binary_stream_t *stream, uint64_t input);

bool binary_stream_read_i64be(binary_stream_t *stream, int64_t *output);

void binary_stream_write_i64be(binary_stream_t *stream, int64_t input);

bool binary_stream_read_f32le(binary_stream_t *stream, float *output);

void binary_stream_write_f32le(binary_stream_t *stream, float input);

bool binary_stream_read_f32be(binary_stream_t *stream, float *output);

void binary_stream_write_f32be(binary_stream_t *stream, float input);

bool binary_stream_read_f64le(binary_stream_t *stream, double *output);

void binary_stream_write_f64le(binary_stream_t *stream, double input);

bool binary_stream_read_f64be(binary_stream_t *stream, double *output);

void binary_stream_write_f64be(binary_stream_t *stream, double input);

bool binary_stream_read_bool(binary_stream_t *stream, bool *output);

void binary_stream_write_bool(binary_stream_t *stream, bool input);

bool binary_stream_read_varint32(binary_stream_t *stream, uint32_t *output);
    
void binary_stream_write_varint32(binary_stream_t *stream, uint32_t input);

bool binary_stream_read_zigzag32(binary_stream_t *stream, int32_t *output);

void binary_stream_write_zigzag32(binary_stream_t *stream, int32_t input);

bool binary_stream_read_varint64(binary_stream_t *stream, uint64_t *output);
    
void binary_stream_write_varint64(binary_stream_t *stream, uint64_t input);

bool binary_stream_read_zigzag64(binary_stream_t *stream, int64_t *output);

void binary_stream_write_zigzag64(binary_stream_t *stream, int64_t input);

bool binary_stream_is_end_of_stream(binary_stream_t *stream);

void binary_stream_construct(binary_stream_t *stream);

void binary_stream_deconstruct(binary_stream_t *stream);

#ifdef __cplusplus
}
#endif

#endif