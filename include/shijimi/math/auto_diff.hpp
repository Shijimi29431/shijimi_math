
/*!
 * @file
 * @brief Implementation of automatic differentiation with dual numbers.
 * @copyright shijimi29431 2021
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

// TODO: UPDATE
// TODO: Add Doxygen Comment
// Look https://github.com/ceres-solver/ceres-solver/blob/master/include/ceres/jet.h

#ifndef SHIJIMI_MATH_AUTO_DIFF_HPP
#define SHIJIMI_MATH_AUTA_DIFF_HPP

#pragma once

#include <nyaruga_util/config.hpp>

#ifdef NYARUGA_UTIL_HAS_EIGEN

#include <cmath>
#include <shijimi/math/concepts/field.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace shijimi { namespace math {

namespace detail {

template <size_t dim, field R = double>
constexpr auto make_init_value(int var_no) noexcept 
{
    Eigen::Matrix<R,dim,1> tmp = Eigen::Matrix<R,dim,1>::Zero();
    tmp(var_no - 1) = 1.;
    return tmp; 
}

} // namespace detail

template <size_t dim, field R = double>
struct var {
	using value_type = R;
    static constexpr size_t dimention = dim;
	using diff_value_type = Eigen::Matrix<R,dim,1>;
	value_type val;
	diff_value_type dval;
	constexpr var() noexcept = default;
	constexpr var(value_type val_, size_t var_no) noexcept : val(val_), dval(detail::make_init_value<dim,R>(var_no)) {}
	constexpr var(const value_type& val_,const diff_value_type& dval_) noexcept : val(val_), dval(dval_) {}
	friend constexpr auto operator<=>(const var&, const var&) noexcept = default;
};

template <field R, size_t dim>
constexpr auto operator + (const var<dim,R>& lhs, const var<dim,R>& rhs) noexcept
{
	return var<dim,R>(lhs.val + rhs.val, static_cast<var<dim,R>::diff_value_type>(lhs.dval + rhs.dval));
}

template <field R, size_t dim>
constexpr auto operator - (const var<dim,R>& lhs, const var<dim,R>& rhs) noexcept
{
	return var<dim,R>(lhs.val - rhs.val, static_cast<var<dim,R>::diff_value_type>(lhs.dval - rhs.dval));
}

template <field R, size_t dim>
constexpr auto operator * (const var<dim,R>& lhs, const var<dim,R>& rhs) noexcept
{
	return var<dim,R>(lhs.val * rhs.val, static_cast<var<dim,R>::diff_value_type>(rhs.val*lhs.dval + lhs.val*rhs.dval));
}

// rhs.val != 0
template <field R, size_t dim>
constexpr auto operator / (const var<dim,R>& lhs, const var<dim,R>& rhs)
{
	return var<dim,R>(lhs.val / rhs.val, static_cast<var<dim,R>::diff_value_type>((lhs.dval*rhs.val - lhs.val*rhs.dval)/std::pow(rhs.val,2)));
}

template <field R, size_t dim>
constexpr auto sin(const var<dim,R>& x) noexcept
{
	return var<dim,R>(std::sin(x.val), static_cast<var<dim,R>::diff_value_type>(std::cos(x.val)*x.dval));
}

template <field R, size_t dim>
constexpr auto cos(const var<dim,R>& x) noexcept
{
	return var<dim,R>(std::cos(x.val), static_cast<var<dim,R>::diff_value_type>(-x.dval*std::sin(x.val)));
}

template <field R, size_t dim>
constexpr auto exp(const var<dim,R>& x) noexcept
{
	return var<dim,R>(std::exp(x.val), static_cast<var<dim,R>::diff_value_type>(x.dval*std::exp(x.val)));
}

// x.val > 0
template <field R, size_t dim>
constexpr auto log(const var<dim,R>& x)
{
	return var<dim,R>(std::log(x.val), static_cast<var<dim,R>::diff_value_type>(x.dval/x.val));
}

// x.val != 0
template <field R, size_t dim>
constexpr auto pow(const var<dim,R>& x, float num)
{
	return var<dim,R>(std::pow(x.val,num), static_cast<var<dim,R>::diff_value_type>(x.dval*num*std::pow(x.val, num-1)));
}

} // namespace math
} // namespace shijimi

#endif // #ifdef NYARUGA_UTIL_HAS_EIGEN

#endif // SHIJIMI_MATH_AUTO_DIFF_HPP
