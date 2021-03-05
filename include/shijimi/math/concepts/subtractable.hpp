
/*!
 * @file
 * @brief Defines `shijimi::math::subtractable`.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_SUBTRACTABLE_HPP
#define SHIJIMI_MATH_SUBTRACTABLE_HPP

#pragma once

#include <type_traits>
#include <shijimi/math/config.hpp>

namespace shijimi { namespace math {

namespace detail {

template <class T, class U>
concept weak_subtractable = 
requires (const std::remove_reference_t<T>& a,
          const std::remove_reference_t<U>& b) 
{
  {a - b} -> std::common_with<T>;
  {b - a} -> std::common_with<T>;
  {a - b} -> std::common_with<U>;
  {b - a} -> std::common_with<U>;
};

} // namespace detail

/**
 * @brief The concept subtractble<T> is satisfied if and only if the types T can be subtracted together. 
 */
template <typename T>
concept subtractable = detail::weak_subtractable<T,T>;

/**
 * @brief The concept subtractable<T> is satisfied if and onlf if the types T and U can be subtracted together.
 */
template <class T, class U>
concept subtractable_with =
  subtractable<T> &&
  subtractable<U> &&
  std::common_reference_with<
    const std::remove_reference_t<T>&,
    const std::remove_reference_t<U>&> &&
  subtractable<
    std::common_reference_t<
      const std::remove_reference_t<T>&,
      const std::remove_reference_t<U>&>> &&
  detail::weak_subtractable<T, U>;

} // namespace math
} // namespace shijimi

#endif // SHIJIMI_MATH_SUBTRACTABLE_HPP
