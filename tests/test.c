/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the MIT license
 */

#include <assert.h>
#include <cbinarystream/binary_stream.h>
#include <stdio.h>

int main () {
    uint8_t u8_value;
    bool bool_value;
    uint16_t u16le_value;
    uint16_t u16be_value;
    uint32_t u24le_value;
    uint32_t u24be_value;
    uint32_t u32le_value;
    uint32_t u32be_value;
    uint64_t u64le_value;
    uint64_t u64be_value;
    float f32le_value;
    float f32be_value;
    double f64le_value;
    double f64be_value;
    uint32_t varint32_value;
    int32_t zigzag32_value;
    uint64_t varint64_value;
    int64_t zigzag64_value;
    uint8_t i8_value;
    uint16_t i16le_value;
    uint16_t i16be_value;
    uint32_t i24le_value;
    uint32_t i24be_value;
    uint32_t i32le_value;
    uint32_t i32be_value;
    uint64_t i64le_value;
    uint64_t i64be_value;

    binary_stream_t stream;
    binary_stream_construct(&stream);

    binary_stream_write_u8(&stream, 254);
    binary_stream_write_bool(&stream, true);
    binary_stream_write_u16le(&stream, 65534);
    binary_stream_write_u16be(&stream, 65534);
    binary_stream_write_u24le(&stream, 16777215);
    binary_stream_write_u24be(&stream, 16777215);
    binary_stream_write_u32le(&stream, 4294967294);
    binary_stream_write_u32be(&stream, 4294967294);
    binary_stream_write_u64le(&stream, 18446744073709551614);
    binary_stream_write_u64be(&stream, 18446744073709551614);
    binary_stream_write_f32le(&stream, 3.4);
    binary_stream_write_f32be(&stream, 3.4);
    binary_stream_write_f64le(&stream, 3.4);
    binary_stream_write_f64be(&stream, 3.4);
    binary_stream_write_varint32(&stream, 4294967294);
    binary_stream_write_zigzag32(&stream, 2147483646);
    binary_stream_write_varint64(&stream, 18446744073709551614);
    binary_stream_write_zigzag64(&stream, 9223372036854775806);
    binary_stream_write_i8(&stream, 126);
    binary_stream_write_i16le(&stream, 32766);
    binary_stream_write_i16be(&stream, 32766);
    binary_stream_write_i24le(&stream, 8388606);
    binary_stream_write_i24be(&stream, 8388606);
    binary_stream_write_i32le(&stream, 2147483646);
    binary_stream_write_i32be(&stream, 2147483646);
    binary_stream_write_i64le(&stream, 9223372036854775806);
    binary_stream_write_i64be(&stream, 9223372036854775806);

    assert(binary_stream_read_u8(&stream, &u8_value));
    assert(binary_stream_read_bool(&stream, &bool_value));
    assert(binary_stream_read_u16le(&stream, &u16le_value));
    assert(binary_stream_read_u16be(&stream, &u16be_value));
    assert(binary_stream_read_u24le(&stream, &u24le_value));
    assert(binary_stream_read_u24be(&stream, &u24be_value));
    assert(binary_stream_read_u32le(&stream, &u32le_value));
    assert(binary_stream_read_u32be(&stream, &u32be_value));
    assert(binary_stream_read_u64le(&stream, &u64le_value));
    assert(binary_stream_read_u64be(&stream, &u64be_value));
    assert(binary_stream_read_f32le(&stream, &f32le_value));
    assert(binary_stream_read_f32be(&stream, &f32be_value));
    assert(binary_stream_read_f64le(&stream, &f64le_value));
    assert(binary_stream_read_f64be(&stream, &f64be_value));
    assert(binary_stream_read_varint32(&stream, &varint32_value));
    assert(binary_stream_read_zigzag32(&stream, &zigzag32_value));
    assert(binary_stream_read_varint64(&stream, &varint64_value));
    assert(binary_stream_read_zigzag64(&stream, &zigzag64_value));
    assert(binary_stream_read_i8(&stream, &i8_value));
    assert(binary_stream_read_i16le(&stream, &i16le_value));
    assert(binary_stream_read_i16be(&stream, &i16be_value));
    assert(binary_stream_read_i24le(&stream, &i24le_value));
    assert(binary_stream_read_i24be(&stream, &i24be_value));
    assert(binary_stream_read_i32le(&stream, &i32le_value));
    assert(binary_stream_read_i32be(&stream, &i32be_value));
    assert(binary_stream_read_i64le(&stream, &i64le_value));
    assert(binary_stream_read_i64be(&stream, &i64be_value));

    printf("%u\n", u8_value);
    printf("%u\n", bool_value);
    printf("%u\n", u16le_value);
    printf("%u\n", u16be_value);
    printf("%lu\n", u24le_value);
    printf("%lu\n", u24be_value);
    printf("%lu\n", u32le_value);
    printf("%lu\n", u32be_value);
    printf("%llu\n", u64le_value);
    printf("%llu\n", u64be_value);
    printf("%f\n", f32le_value);
    printf("%f\n", f32be_value);
    printf("%lf\n", f64le_value);
    printf("%lf\n", f64be_value);
    printf("%lu\n", varint32_value);
    printf("%ld\n", zigzag32_value);
    printf("%llu\n", varint64_value);
    printf("%lld\n", zigzag64_value);
    printf("%d\n", i8_value);
    printf("%d\n", i16le_value);
    printf("%d\n", i16be_value);
    printf("%ld\n", i24le_value);
    printf("%ld\n", i24be_value);
    printf("%ld\n", i32le_value);
    printf("%ld\n", i32be_value);
    printf("%lld\n", i64le_value);
    printf("%lld\n", i64be_value);

    binary_stream_deconstruct(&stream);
}