
/*!
 * @file
 * @brief Defines configuration macros used throughout the library.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef SHIJIMI_MATH_CONFIG_HPP
#define SHIJIMI_MATH_CONFIG_HPP

#pragma once

#include <boost/config.hpp>

// -------------------------
// User-adjustable macros
// -------------------------

//! If you have not EIGEN installed, comment out here.
#define SHIJIMI_MATH_HAS_EIGEN

// Uncomment if you don't want to assert.
// #define SHIJIMI_MATH_CONFIG_DISABLE_ASSERTIONS

#if defined(SHIJIMI_MATH_DOXYGEN_INVOKED) || \
   (defined(NDEBUG) && !defined(SHIJIMI_MATH_CONFIG_DISABLE_ASSERTIONS))

//! Disables assertions.
#   define SHIJIMI_MATH_CONFIG_DISABLE_ASSERTIONS

#endif

#endif // #ifndef SHIJIMI_MATH_CONFIG_HPP
