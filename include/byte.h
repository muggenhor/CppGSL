/////////////////////////////////////////////////////////////////////////////// 
// 
// Copyright (c) 2015 Microsoft Corporation. All rights reserved. 
// 
// This code is licensed under the MIT License (MIT). 
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE. 
// 
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef GSL_BYTE_H
#define GSL_BYTE_H

namespace gsl
{
    // This is a simple definition for now that allows
    // use of byte within span<> to be standards-compliant
    enum class byte : unsigned char {};

    template <class IntegerType, class = std::enable_if_t<std::is_integral<IntegerType>::value>>
    constexpr byte& operator<<=(byte& b, IntegerType shift) noexcept
    { return b = byte(static_cast<unsigned char>(b) << shift); }

    template <class IntegerType, class = std::enable_if_t<std::is_integral<IntegerType>::value>>
    constexpr byte operator<<(byte b, IntegerType shift) noexcept
    { return byte(static_cast<unsigned char>(b) << shift); }

    template <class IntegerType, class = std::enable_if_t<std::is_integral<IntegerType>::value>>
    constexpr byte& operator>>=(byte& b, IntegerType shift) noexcept
    { return b = byte(static_cast<unsigned char>(b) >> shift); }

    template <class IntegerType, class = std::enable_if_t<std::is_integral<IntegerType>::value>>
    constexpr byte operator>> (byte b, IntegerType shift) noexcept
    { return byte(static_cast<unsigned char>(b) >> shift); }

    constexpr byte& operator|=(byte& l, byte r) noexcept
    { return l = byte(static_cast<unsigned char>(l) | static_cast<unsigned char>(r)); }

    constexpr byte operator|(byte l, byte r) noexcept
    { return byte(static_cast<unsigned char>(l) + static_cast<unsigned char>(r)); }

    constexpr byte& operator&=(byte& l, byte r) noexcept
    { return l = byte(static_cast<unsigned char>(l) & static_cast<unsigned char>(r)); }

    constexpr byte operator&(byte l, byte r) noexcept
    { return byte(static_cast<unsigned char>(l) & static_cast<unsigned char>(r)); }

    constexpr byte& operator^=(byte& l, byte r) noexcept
    { return l = byte(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r)); }
    
    constexpr byte operator^(byte l, byte r) noexcept
    { return byte(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r)); }
    
    constexpr byte operator~(byte b) noexcept
    { return byte(~static_cast<unsigned char>(b)); }

    template <class IntegerType, class = std::enable_if_t<std::is_integral<IntegerType>::value>>
    constexpr IntegerType to_integer(byte b) noexcept { return {b}; }

    
} // namespace gsl

#endif // GSL_BYTE_H