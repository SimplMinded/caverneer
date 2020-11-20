#pragma once

#include <cstdint>

namespace caverneer {

int8_t min(int8_t lhs, int8_t rhs);
int16_t min(int16_t lhs, int16_t rhs);
int32_t min(int32_t lhs, int32_t rhs);
int64_t min(int64_t lhs, int64_t rhs);

uint8_t min(uint8_t lhs, uint8_t rhs);
uint16_t min(uint16_t lhs, uint16_t rhs);
uint32_t min(uint32_t lhs, uint32_t rhs);
uint64_t min(uint64_t lhs, uint64_t rhs);

float min(float lhs, float rhs);
double min(double lhs, double rhs);


int8_t max(int8_t lhs, int8_t rhs);
int16_t max(int16_t lhs, int16_t rhs);
int32_t max(int32_t lhs, int32_t rhs);
int64_t max(int64_t lhs, int64_t rhs);

uint8_t max(uint8_t lhs, uint8_t rhs);
uint16_t max(uint16_t lhs, uint16_t rhs);
uint32_t max(uint32_t lhs, uint32_t rhs);
uint64_t max(uint64_t lhs, uint64_t rhs);

float max(float lhs, float rhs);
double max(double lhs, double rhs);

} // namespace caverneer
