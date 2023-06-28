/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the MIT license
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <cbinarystream/binary_stream.h>
#include <string.h>

#define CLOSEST_MULTIPLE(n, m)(n <= m ? m : ((n + m / 2) - ((n + m / 2) % m)))
#define BLOCK_SIZE 512

bool binary_stream_read(binary_stream_t *stream, size_t size, uint8_t **output)
{
    if ((stream->offset + size) <= stream->size) {
        *output = stream->buffer + stream->offset;
        stream->offset += size;
        return true;
    }
    return false;
}

void binary_stream_write(binary_stream_t *stream, uint8_t *buffer, size_t size)
{
    if (stream->buffer == NULL || stream->storage_size == 0) {
        stream->size = size;
        stream->storage_size = CLOSEST_MULTIPLE(size, BLOCK_SIZE);
        stream->buffer = (uint8_t *)malloc(stream->storage_size);
        memcpy(stream->buffer, buffer, size);
    } else {
        size_t old_size = stream->size;
        stream->size += size;
        if (stream->size > stream->storage_size) {
            stream->storage_size = CLOSEST_MULTIPLE(stream->size, BLOCK_SIZE);
            stream->buffer = (uint8_t *)realloc(stream->buffer, stream->storage_size);
        }
        memcpy(&stream->buffer[old_size], buffer, size);
    }
}

bool binary_stream_read_u8(binary_stream_t *stream, uint8_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 1, &out);
    if (no_error)
        *output = out[0];
    return no_error;
}

void binary_stream_write_u8(binary_stream_t *stream, uint8_t input)
{
    binary_stream_write(stream, &input, 1);
}

bool binary_stream_read_i8(binary_stream_t *stream, int8_t *output)
{
    return binary_stream_read_u8(stream, (uint8_t *) output);
}

void binary_stream_write_i8(binary_stream_t *stream, int8_t input)
{
    binary_stream_write_u8(stream, *((uint8_t *) &input));
}

bool binary_stream_read_u16le(binary_stream_t *stream, uint16_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 2, &out);
    if (no_error)
        *output = ((uint16_t) out[0]) | (((uint16_t) out[1]) << 8);
    return no_error;
}

void binary_stream_write_u16le(binary_stream_t *stream, uint16_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) (input & 0xff),
        (uint8_t) ((input >> 8) & 0xff)
    };
    binary_stream_write(stream, byte_array, 2);
}

bool binary_stream_read_i16le(binary_stream_t *stream, int16_t *output)
{
    return binary_stream_read_u16le(stream, (uint16_t *) output);
}

void binary_stream_write_i16le(binary_stream_t *stream, int16_t input)
{
    binary_stream_write_u16le(stream, *((uint16_t *) &input));
}

bool binary_stream_read_u16be(binary_stream_t *stream, uint16_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 2, &out);
    if (no_error)
        *output =  (((uint16_t) out[0]) << 8) | ((uint16_t) out[1]);
    return no_error;
}

void binary_stream_write_u16be(binary_stream_t *stream, uint16_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) (input & 0xff)
    };
    binary_stream_write(stream, byte_array, 2);
}

bool binary_stream_read_i16be(binary_stream_t *stream, int16_t *output)
{
    return binary_stream_read_u16be(stream, (uint16_t *) output);
}

void binary_stream_write_i16be(binary_stream_t *stream, int16_t input)
{
    binary_stream_write_u16be(stream, *((uint16_t *) &input));
}

bool binary_stream_read_u24le(binary_stream_t *stream, uint32_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 3, &out);
    if (no_error)
        *output = ((uint32_t) out[0]) | (((uint32_t) out[1]) << 8) | (((uint32_t) out[2]) << 16);
    return no_error;
}

void binary_stream_write_u24le(binary_stream_t *stream, uint32_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) (input & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) ((input >> 16) & 0xff)
    };
    binary_stream_write(stream, byte_array, 3);
}

bool binary_stream_read_i24le(binary_stream_t *stream, int32_t *output)
{
    int32_t value;
    bool no_error = binary_stream_read_u24le(stream, (uint32_t *) &value);
    if (no_error) {
        if (value > 0x7fffff) {
            value -= 0x1000000;
        }
        *output = value;
    }
    return no_error;
}

void binary_stream_write_i24le(binary_stream_t *stream, int32_t input)
{
    if (input < 0) {
        input += 0x1000000;
    }
    binary_stream_write_u24le(stream, *((uint32_t *) &input));
}

bool binary_stream_read_u24be(binary_stream_t *stream, uint32_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 3, &out);
    if (no_error)
        *output = (((uint32_t) out[0]) << 16) | (((uint32_t) out[1]) << 8) | ((uint32_t) out[2]);
    return no_error;
}

void binary_stream_write_u24be(binary_stream_t *stream, uint32_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) ((input >> 16) & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) (input & 0xff)
    };
    binary_stream_write(stream, byte_array, 3);
}

bool binary_stream_read_i24be(binary_stream_t *stream, int32_t *output)
{
    int32_t value;
    bool no_error = binary_stream_read_u24be(stream, (uint32_t *) &value);
    if (no_error) {
        if (value > 0x7fffff) {
            value -= 0x1000000;
        }
        *output = value;
    }
    return no_error;
}

void binary_stream_write_i24be(binary_stream_t *stream, int32_t input)
{
    if (input < 0) {
        input += 0x1000000;
    }
    binary_stream_write_u24be(stream, *((uint32_t *) &input));
}

bool binary_stream_read_u32le(binary_stream_t *stream, uint32_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 4, &out);
    if (no_error)
        *output = ((uint32_t) out[0]) | (((uint32_t) out[1]) << 8) | (((uint32_t) out[2]) << 16) | (((uint32_t) out[3]) << 24);
    return no_error;
}

void binary_stream_write_u32le(binary_stream_t *stream, uint32_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) (input & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) ((input >> 16) & 0xff),
        (uint8_t) ((input >> 24) & 0xff)
    };
    binary_stream_write(stream, byte_array, 4);
}

bool binary_stream_read_i32le(binary_stream_t *stream, int32_t *output)
{
    return binary_stream_read_u32le(stream, (uint32_t *) output);
}

void binary_stream_write_i32le(binary_stream_t *stream, int32_t input)
{
    binary_stream_write_u32le(stream, *((uint32_t *) &input));
}

bool binary_stream_read_u32be(binary_stream_t *stream, uint32_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 4, &out);
    if (no_error)
        *output = (((uint32_t) out[0]) << 24) | (((uint32_t) out[1]) << 16) | (((uint32_t) out[2]) << 8) | ((uint32_t) out[3]);
    return no_error;
}

void binary_stream_write_u32be(binary_stream_t *stream, uint32_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) ((input >> 24) & 0xff),
        (uint8_t) ((input >> 16) & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) (input & 0xff)
    };
    binary_stream_write(stream, byte_array, 4);
}

bool binary_stream_read_i32be(binary_stream_t *stream, int32_t *output)
{
    return binary_stream_read_u32be(stream, (uint32_t *) output);
}

void binary_stream_write_i32be(binary_stream_t *stream, int32_t input)
{
    binary_stream_write_u32be(stream, *((uint32_t *) &input));
}

bool binary_stream_read_u64le(binary_stream_t *stream, uint64_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 8, &out);
    if (no_error)
        *output = ((uint64_t) out[0]) | (((uint64_t) out[1]) << 8) | (((uint64_t) out[2]) << 16) | (((uint64_t) out[3]) << 24) | (((uint64_t) out[4]) << 32) | (((uint64_t) out[5]) << 40) | (((uint64_t) out[6]) << 48) | (((uint64_t) out[7]) << 56);
    return no_error;
}

void binary_stream_write_u64le(binary_stream_t *stream, uint64_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) (input & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) ((input >> 16) & 0xff),
        (uint8_t) ((input >> 24) & 0xff),
        (uint8_t) ((input >> 32) & 0xff),
        (uint8_t) ((input >> 40) & 0xff),
        (uint8_t) ((input >> 48) & 0xff),
        (uint8_t) ((input >> 56) & 0xff)
    };
    binary_stream_write(stream, byte_array, 8);
}

bool binary_stream_read_i64le(binary_stream_t *stream, int64_t *output)
{
    return binary_stream_read_u64le(stream, (uint64_t *) output);
}

void binary_stream_write_i64le(binary_stream_t *stream, int64_t input)
{
    binary_stream_write_u64le(stream, *((uint64_t *) &input));
}

bool binary_stream_read_u64be(binary_stream_t *stream, uint64_t *output)
{
    uint8_t *out;
    bool no_error = binary_stream_read(stream, 8, &out);
    if (no_error)
        *output = (((uint64_t) out[0]) << 56) | (((uint64_t) out[1]) << 48) | (((uint64_t) out[2]) << 40) | (((uint64_t) out[3]) << 32) | (((uint64_t) out[4]) << 24) | (((uint64_t) out[5]) << 16) | (((uint64_t) out[6]) << 8) | ((uint64_t) out[7]);
    return no_error;
}

void binary_stream_write_u64be(binary_stream_t *stream, uint64_t input)
{
    uint8_t byte_array[] = {
        (uint8_t) ((input >> 56) & 0xff),
        (uint8_t) ((input >> 48) & 0xff),
        (uint8_t) ((input >> 40) & 0xff),
        (uint8_t) ((input >> 32) & 0xff),
        (uint8_t) ((input >> 24) & 0xff),
        (uint8_t) ((input >> 16) & 0xff),
        (uint8_t) ((input >> 8) & 0xff),
        (uint8_t) (input & 0xff)
    };
    binary_stream_write(stream, byte_array, 8);
}

bool binary_stream_read_i64be(binary_stream_t *stream, int64_t *output)
{
    return binary_stream_read_u64be(stream, (uint64_t *) output);
}

void binary_stream_write_i64be(binary_stream_t *stream, int64_t input)
{
    binary_stream_write_u64be(stream, *((uint64_t *) &input));
}

bool binary_stream_read_f32le(binary_stream_t *stream, float *output)
{
    return binary_stream_read_u32le(stream, (uint32_t *) output);
}

void binary_stream_write_f32le(binary_stream_t *stream, float input)
{
    binary_stream_write_u32le(stream, *((uint32_t *) &input));
}

bool binary_stream_read_f32be(binary_stream_t *stream, float *output)
{
    return binary_stream_read_u32be(stream, (uint32_t *) output);
}

void binary_stream_write_f32be(binary_stream_t *stream, float input)
{
    binary_stream_write_u32be(stream, *((uint32_t *) &input));
}

bool binary_stream_read_f64le(binary_stream_t *stream, double *output)
{
    return binary_stream_read_u64le(stream, (uint64_t *) output);
}

void binary_stream_write_f64le(binary_stream_t *stream, double input)
{
    binary_stream_write_u64le(stream, *((uint64_t *) &input));
}

bool binary_stream_read_f64be(binary_stream_t *stream, double *output)
{
    return binary_stream_read_u64be(stream, (uint64_t *) output);
}

void binary_stream_write_f64be(binary_stream_t *stream, double input)
{
    binary_stream_write_u64be(stream, *((uint64_t *) &input));
}

bool binary_stream_read_bool(binary_stream_t *stream, bool *output)
{
    return binary_stream_read_u8(stream, (uint8_t *) output);
}

void binary_stream_write_bool(binary_stream_t *stream, bool input)
{
    binary_stream_write_u8(stream, *((uint8_t *) &input));
}

bool binary_stream_read_varint32(binary_stream_t *stream, uint32_t *output)
{
    uint32_t value = 0;
    uint8_t i;
    uint8_t to_read;
    for (i = 0; i < 35; i += 7) {
        if (!binary_stream_read_u8(stream, &to_read)) {
            return false;
        }
        value |= ((uint32_t) (to_read & 0x7f)) << i;
        if ((to_read & 0x80) == 0) {
            *output = value;
            return true;
        }
    }
    return false;
}
    
void binary_stream_write_varint32(binary_stream_t *stream, uint32_t input)
{
    uint32_t value = input;
    uint8_t i;
    for (i = 0; i < 5; ++i) {
        uint8_t to_write = (uint8_t) (value & 0x7f);
        value >>= 7;
        if (value != 0) {
            binary_stream_write_u8(stream, to_write | 0x80);
        } else {
            binary_stream_write_u8(stream, to_write);
            break;
        }
    }
}

bool binary_stream_read_zigzag32(binary_stream_t *stream, int32_t *output)
{
    uint32_t raw;
    if (!binary_stream_read_varint32(stream, &raw)) {
        return false;
    }
    uint32_t temp = ((raw & 1) == 1) ? (~(raw >> 1)) : (raw >> 1);
    *output = *((int32_t *) &temp);
    return true;
}

void binary_stream_write_zigzag32(binary_stream_t *stream, int32_t input)
{
    uint32_t raw = (input >= 0) ? ((*((uint32_t *) &input)) << 1) : (((~(*((uint32_t *) &input))) << 1) | 1);
    binary_stream_write_varint32(stream, raw);
}

bool binary_stream_read_varint64(binary_stream_t *stream, uint64_t *output)
{
    uint64_t value = 0;
    uint8_t i;
    uint8_t to_read;
    for (i = 0; i < 70; i += 7) {
        if (!binary_stream_read_u8(stream, &to_read)) {
            return false;
        }
        value |= ((uint64_t) (to_read & 0x7f)) << i;
        if ((to_read & 0x80) == 0) {
            *output = value;
            return true;
        }
    }
    return false;
}
    
void binary_stream_write_varint64(binary_stream_t *stream, uint64_t input)
{
    uint64_t value = input;
    uint8_t i;
    for (i = 0; i < 10; ++i) {
        uint8_t to_write = (uint8_t) (value & 0x7f);
        value >>= 7;
        if (value != 0) {
            binary_stream_write_u8(stream, to_write | 0x80);
        } else {
            binary_stream_write_u8(stream, to_write);
            break;
        }
    }
}

bool binary_stream_read_zigzag64(binary_stream_t *stream, int64_t *output)
{
    uint64_t raw;
    if (!binary_stream_read_varint64(stream, &raw)) {
        return false;
    }
    uint64_t temp = ((raw & 1) == 1) ? (~(raw >> 1)) : (raw >> 1);
    *output = *((int64_t *) &temp);
    return true;
}

void binary_stream_write_zigzag64(binary_stream_t *stream, int64_t input)
{
    uint64_t raw = (input >= 0) ? ((*((uint64_t *) &input)) << 1) : (((~(*((uint64_t *) &input))) << 1) | 1);
    binary_stream_write_varint64(stream, raw);
}

bool binary_stream_is_end_of_stream(binary_stream_t *stream)
{
    return (stream->offset < stream->size);
}

void binary_stream_construct(binary_stream_t *stream)
{
    stream->buffer = NULL;
    stream->size = 0;
    stream->storage_size = 0;
    stream->offset = 0;
}

void binary_stream_deconstruct(binary_stream_t *stream)
{
    if (stream->buffer != NULL) {
        free(stream->buffer);
    }
    stream->size = 0;
    stream->storage_size = 0;
    stream->offset = 0;
}

#ifdef __cplusplus
}
#endif