
/*!
 * @file
 * @brief Defines `shijimi::math::ring`.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_RING_HPP
#define SHIJIMI_MATH_RING_HPP

#pragma once

#include <shijimi/math/concepts/addable.hpp>
#include <shijimi/math/concepts/subtractable.hpp>
#include <shijimi/math/concepts/multipliable.hpp>

namespace shijimi { namespace math {

/**
 * @brief The concept dividable<T> is satisfied if and only if addable, subtractable, and multiplyable with type T.
 */
template <typename T>
concept ring = addable<T> && subtractable<T> &&
               multipliable<T>;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_RING_HPP
