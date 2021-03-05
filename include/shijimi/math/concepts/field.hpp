
/*!
 * @file
 * @brief Defines fields concept.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_FIELD_HPP
#define SHIJIMI_MATH_FIELD_HPP

#pragma once

#include <shijimi/math/concepts/addable.hpp>
#include <shijimi/math/concepts/subtractable.hpp>
#include <shijimi/math/concepts/multipliable.hpp>
#include <shijimi/math/concepts/dividable.hpp>

namespace shijimi { namespace math {

/**
 * @brief The concept dividable<T> is satisfied if and only if four arithmetic operations can be performed with type T.
 */
template <typename T>
concept field = addable<T> && subtractable<T> &&
                multipliable<T> && dividable<T>;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_FIELD_HPP
