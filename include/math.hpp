#pragma once

#include <cmath>
#include <cassert>
#include <cstdint>
#include <iostream>

namespace mpt
{
class Math;

template<class T, size_t D>
class Vector
{
public:
	Vector(T field, Vector<T, D - 1> inner) : m_field(field), m_inner(inner) {}
	explicit Vector(T value = {}) : Vector(value, Vector<T, D - 1>(value)) {}

	template<class... Ts, std::enable_if_t<sizeof...(Ts) == D - 1, bool>  = true>
	explicit Vector(T value, Ts... arguments) : Vector(value, Vector<T, D - 1>(arguments...)) {}

	template<class U>
	explicit Vector(U value) : Vector(static_cast<T>(value)) {}

	template<class U>
	explicit Vector(Vector<U, D> value) : Vector(value.template as<T>()) {}

	template<size_t I, std::enable_if_t<I < D, bool>  = true>
	T& at()
	{
		if constexpr (I == 0) return m_field;
		else return m_inner.template at<I - 1>();
	}

	template<size_t I, std::enable_if_t<I < D, bool>  = true>
	T at() const { return const_cast<Vector*>(this)->at<I>(); }

	T& x() { return at<0>(); }
	T& y() { return at<1>(); }
	T& z() { return at<2>(); }
	T& w() { return at<3>(); }

	T x() const { return at<0>(); }
	T y() const { return at<1>(); }
	T z() const { return at<2>(); }
	T w() const { return at<3>(); }

	template<typename U>
	Vector<U, D> as() const { return { static_cast<U>(m_field), m_inner.template as<U>() }; }

	bool operator==(Vector value) const { return m_field == value.m_field && m_inner == value.m_inner; }
	bool operator<(Vector value) const { return m_field < value.m_field && m_inner < value.m_inner; }
	bool operator<=(Vector value) const { return m_field <= value.m_field && m_inner <= value.m_inner; }

	bool operator!=(Vector value) const { return !operator==(value); }
	bool operator>(Vector value) const { return value.operator<(*this); }
	bool operator>=(Vector value) const { return value.operator<(*this); }

	Vector operator+(Vector value) const { return { m_field + value.m_field, m_inner + value.m_inner }; }
	Vector operator-(Vector value) const { return { m_field - value.m_field, m_inner - value.m_inner }; }
	Vector operator*(Vector value) const { return { m_field * value.m_field, m_inner * value.m_inner }; }
	Vector operator/(Vector value) const { return { m_field / value.m_field, m_inner / value.m_inner }; }

	Vector operator*(T value) const { return { m_field * value, m_inner * value }; }
	Vector operator/(T value) const { return { m_field / value, m_inner / value }; }

	Vector operator-() const { return { -m_field, -m_inner }; }
	Vector operator+() const { return *this; }

	Vector operator+=(Vector value) { return *this = *this + value; }
	Vector operator-=(Vector value) { return *this = *this - value; }
	Vector operator*=(Vector value) { return *this = *this * value; }
	Vector operator/=(Vector value) { return *this = *this / value; }

	Vector operator*=(T value) { return *this = *this * value; }
	Vector operator/=(T value) { return *this = *this / value; }

	friend std::ostream& operator<<(std::ostream& stream, Vector value) { return value.insert(stream << '(') << ')'; }

private:
	std::ostream& insert(std::ostream& stream) const { return m_inner.insert(stream << m_field << ", "); }

	T m_field;
	Vector<T, D - 1> m_inner;

	friend Vector<T, D + 1>;
	friend Math;
};

template<class T>
class Vector<T, 1>
{
public:
	explicit Vector(T value = {}) : m_field(value) {}

	template<size_t I, std::enable_if_t<I == 0, bool>  = true>
	T& at() { return m_field; }

	template<typename U>
	Vector<U, 1> as() const { return Vector<U, 1>(static_cast<U>(m_field)); }

	bool operator==(Vector value) const { return m_field == value.m_field; }
	bool operator<(Vector value) const { return m_field < value.m_field; }
	bool operator<=(Vector value) const { return m_field <= value.m_field; }

	Vector operator+(Vector value) const { return Vector(m_field + value.m_field); }
	Vector operator-(Vector value) const { return Vector(m_field - value.m_field); }
	Vector operator*(Vector value) const { return Vector(m_field * value.m_field); }
	Vector operator/(Vector value) const { return Vector(m_field / value.m_field); }

	Vector operator*(T value) const { return Vector(m_field * value); }
	Vector operator/(T value) const { return Vector(m_field / value); }

	Vector operator-() const { return { -m_field }; }

private:
	std::ostream& insert(std::ostream& stream) const { return stream << m_field; }

	T m_field;

	friend Vector<T, 2>;
	friend Math;
};

class Math
{
public:
	template<class T, size_t D>
	static T sum(Vector<T, D> value)
	{
		if constexpr (D == 1) return value.m_field;
		else return value.m_field + sum(value.m_inner);
	}

	template<class T, size_t D>
	static T product(Vector<T, D> value)
	{
		if constexpr (D == 1) return value.m_field;
		else return value.m_field * product(value.m_inner);
	}

	template<class T, size_t D>
	static T dot(Vector<T, D> value0, Vector<T, D> value1) { return sum(value0 * value1); }

	template<class T, size_t D>
	static T squared_magnitude(Vector<T, D> value) { return dot(value, value); }

	template<class T, size_t D>
	static float magnitude(Vector<T, D> value) { return std::sqrt(static_cast<float>(squared_magnitude(value))); }

	template<class T, size_t D>
	static Vector<float, D> normalize(Vector<T, D> value) { return value * (1.0f / magnitude(value)); }

	template<class T, size_t D>
	static Vector<T, D> min(Vector<T, D> value0, Vector<T, D> value1)
	{
		if constexpr (D == 1) return Vector<T, D>(std::min(value0.m_field, value1.m_field));
		else return { std::min(value0.m_field, value1.m_field), min(value0.m_inner, value1.m_inner) };
	}

	template<class T, size_t D>
	static Vector<T, D> max(Vector<T, D> value0, Vector<T, D> value1)
	{
		if constexpr (D == 1) return Vector<T, D>(std::max(value0.m_field, value1.m_field));
		else return { std::max(value0.m_field, value1.m_field), max(value0.m_inner, value1.m_inner) };
	}
};

using Float2 = Vector<float, 2>;
using Float3 = Vector<float, 3>;
using Float4 = Vector<float, 4>;
using Int2 = Vector<int32_t, 2>;
using Int3 = Vector<int32_t, 3>;
using Int4 = Vector<int32_t, 4>;
using UInt2 = Vector<uint32_t, 2>;
using UInt3 = Vector<uint32_t, 3>;
using UInt4 = Vector<uint32_t, 4>;
}
