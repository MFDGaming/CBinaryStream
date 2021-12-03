/*
   Copyright Alexander Argentakis
   Repo: https://github.com/MFDGaming/CBinaryStream
   This file is licensed under the GPL v2.0 license
 */

#include "binary_stream.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    binary_stream_t stream;
    stream.buffer = malloc(0);
    stream.offset = 0;
    stream.size = 0;
    put_unsigned_byte(254, &stream);
    put_unsigned_short_le(65534, &stream);
    put_unsigned_short_be(65534, &stream);
    put_unsigned_triad_le(16777215, &stream);
    put_unsigned_triad_be(16777215, &stream);
    put_unsigned_int_le(4294967294, &stream);
    put_unsigned_int_be(4294967294, &stream);
    put_unsigned_long_le((unsigned long long)18446744073709551614, &stream);
    put_unsigned_long_be((unsigned long long)18446744073709551614, &stream);
    put_float_le(3.4, &stream);
    put_float_be(3.4, &stream);
    put_double_le(3.4, &stream);
    put_double_be(3.4, &stream);
    put_var_int(4294967294, &stream);
    put_signed_var_int(2147483646, &stream);
    put_var_long((unsigned long long)18446744073709551614, &stream);
    put_signed_var_long(9223372036854775806, &stream);
    put_byte(126, &stream);
    put_short_le(32766, &stream);
    put_short_be(32766, &stream);
    put_int_le(2147483646, &stream);
    put_int_be(2147483646, &stream);
    put_long_le(9223372036854775806, &stream);
    put_long_be(9223372036854775806, &stream);
    printf("%u\n", get_unsigned_byte(&stream));
    printf("%u\n", get_unsigned_short_le(&stream));
    printf("%u\n", get_unsigned_short_be(&stream));
    printf("%lu\n", get_unsigned_triad_le(&stream));
    printf("%lu\n", get_unsigned_triad_be(&stream));
    printf("%lu\n", get_unsigned_int_le(&stream));
    printf("%lu\n", get_unsigned_int_be(&stream));
    printf("%llu\n", get_unsigned_long_le(&stream));
    printf("%llu\n", get_unsigned_long_be(&stream));
    printf("%f\n", get_float_le(&stream));
    printf("%f\n", get_float_be(&stream));
    printf("%lf\n", get_double_le(&stream));
    printf("%lf\n", get_double_be(&stream));
    printf("%lu\n", get_var_int(&stream));
    printf("%ld\n", get_signed_var_int(&stream));
    printf("%llu\n", get_var_long(&stream));
    printf("%lld\n", get_signed_var_long(&stream));
    printf("%d\n", get_byte(&stream));
    printf("%d\n", get_short_le(&stream));
    printf("%d\n", get_short_be(&stream));
    printf("%ld\n", get_int_le(&stream));
    printf("%ld\n", get_int_be(&stream));
    printf("%lld\n", get_long_le(&stream));
    printf("%lld\n", get_long_be(&stream));
}
