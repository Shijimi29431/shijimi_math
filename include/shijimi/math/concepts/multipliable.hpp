
/*!
 * @file
 * @brief Defines `shijimi::math::multipliable`.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_MULTIPLIABLE_HPP
#define SHIJIMI_MATH_MULTIPLIABLE_HPP

#pragma once

#include <type_traits>
#include <shijimi/math/config.hpp>

namespace shijimi { namespace math {

namespace detail {

template <class T, class U>
concept weak_multipliable =
requires (const std::remove_reference_t<T>& a,
          const std::remove_reference_t<U>& b)
{
  {a * b} -> std::common_with<T>;
  {b * a} -> std::common_with<T>;
  {a * b} -> std::common_with<U>;
  {b * a} -> std::common_with<U>;
};

} // namespace detail

/**
 * @brief The concept multipliable<T> is satisfied if and only if the types T can be multiplied together. 
 */
template <typename T>
concept multipliable = detail::weak_multipliable<T,T>;

/**
 * @brief The concept multipliable<T> is satisfied if and onlf if the types T and U can be multiplied together.
 */
template <class T, class U>
concept multipliable_with =
  multipliable<T> &&
  multipliable<U> &&
  std::common_reference_with<
    const std::remove_reference_t<T>&,
    const std::remove_reference_t<U>&> &&
  multipliable<
    std::common_reference_t<
      const std::remove_reference_t<T>&,
      const std::remove_reference_t<U>&>> &&
  detail::weak_multipliable<T, U>;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_MULTIPLIABLE_HPP
