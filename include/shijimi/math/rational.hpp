
/*!
 * @file
 * @brief Defines `shijimi::math::rational`.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_RATIONAL_HPP
#define SHIJIMI_MATH_RATIONAL_HPP

#pragma once

#include <type_traits>
#include <shijimi/math/config.hpp>
#include <shijimi/math/external/tcb/rational.hpp>

namespace shijimi { namespace math {

/**
 * @brief rational
 */
template <typename T>
using rational = tcb::rational<T>;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_RATIONAL_HPP
