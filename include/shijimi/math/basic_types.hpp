
/*!
 * @file
 * @brief Defines basic types such as N, R, C, Q, and Z.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_BASIC_TYPES_HPP
#define SHIJIMI_MATH_BASIC_TYPES_HPP

#pragma once

#include <complex>
#include <shijimi/math/rational.hpp>

namespace shijimi { namespace math {

/**
 * @brief Real number
 */
template <typename T = double>
using R = T;

/**
 * @brief Natural number
 */
template <typename T = unsigned int>
using N = T;

/**
 * @brief Integer
 */
template <typename T = int>
using Z = T;

/**
 * @brief Complex number
 */
template <typename T = std::complex<double>>
using C = T;

/**
 * @brief Rational number
 */
template <typename T = rational<int>>
using Q = T;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_BASIC_TYPES_HPP
