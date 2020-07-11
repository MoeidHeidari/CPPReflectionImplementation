// Copyright 2020 moeidheidari
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ────────────────────────────────────────────────────────────────────────────────
#ifndef REF_STRING_VIEW_H_
#define REF_STRING_VIEW_H_
//
// ─── HEADER FILES INCLUDS ───────────────────────────────────────────────────────
//
#include "Reflection/Details/BasicInfo/Prerequisites.h"
#include <string>
#include <ostream>

namespace REF
{
    /*!
    \ref(ref) CharLikeObjects_descriptor class represents a bunch of information about some non-owing and constant char-like sequence objects in memory.
    */

    template <typename CharT, typename Traits = std::char_traits<CharT>>
    class CharLikeObjects_Descriptor
    {
    public:
        //
        // ─── USING DECLARATIVES BEGIN ───────────────────────────────────────────────────
        //
        using type_of_trait = Traits;
        using type_reference = CharT &;
        using type_const_reference = const CharT &;
        using type_const_ptr = const ChatT *;
        using type_const_ptr = const CharT *;
        using type_ptr = CharT *;
        using type_value = CharT;
        using type_size = std::size_t;
        using type_const_iterator = type_const_pointer;
        using type_iterator = type_const_iterator;
        using type_const_reverse_iterator = std::reverse_iterator<type_const_iterator>;
        using type_reverse_iterator = type_const_reverse_iterator;
        using type_deference = std::ptrdiff_t;
        REF_STATIC_CONSTEXPR type_size npos = type_size(-1);
        //
        // ─────────────────────────────────────────────────── USING DECLARATIVES END ─────
        //

        //
        // ─── CONSTRUCTOR DECLARATIONS START ──────────────────────────────
        //

        /*! 
        * \brief Default constructor. It constructs an empty CharLikeObjects_Descriptor instance. 
        */
        REF_CONSTEXPR CharLikeObjects_Descriptor() REF_NOEXCEPT;

        /*!
       \brief Copy constructor. It constructs a view of the same content as \p other. 
       */
        REF_CONSTEXPR CharLikeObjects_Descriptor(const CharLikeObjects_Descriptor &other) REF_NOEXCEPT;

        /*!
       \brief Constructs a descriptor of a non-terminating character string pointed by str argument as a pointer of type CharT.
       \p and the lenght is determined by Traits::lenght(str). 
       */
        REF_CONSTEXPR CharLikeObjects_Descriptor(const CharT *str) REF_NOEXCEPT;

        /*!
       \brief Constructs a descriptor of a terminating character string pointed by str argument as a pointer of the 
       \p first character of type CharT with lenght provided by {lenght}.
       */
        REF_CONSTEXPR CharLikeObjects_Descriptor(const CharT *str, type_size lenght) REF_NOEXCEPT;

        /*!
       \brief Constructs a descriptor the first str.size() characters pointed by str.data().
       */
        template <typename Allocator>
        CharLikeObjects_Descriptor(const std::basic_string<CharT, Traits, Allocator, > &str) REF_NOEXCEPT;

        //
        // ───────────────────────────────────────────────── CONSTRUCTOR DECLARATIONS END ─────
        //
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
        //
        // ─── BASIC CHART ARRAY OPERATIONS START ──────────────────────────────
        //
        REF_CXX14_CONSTEXPR void swap(CharLikeObjects_Descriptor* str) REF_NOEXCEPT;

        /*!
       \brief Returns an iterator to the begining of the ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator begin() const REF_NOEXCEPT;

        /*!
       \brief Returns an iterator to the begining of the ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator cbegin() const REF_NOEXCEPT;

         /*!
       \brief Returns an iterator to the end of the ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator end() const REF_NOEXCEPT;

        /*!
       \brief Returns an iterator to the end of the ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator cend() const REF_NOEXCEPT;

        /*!
        \brief Returns an iterator to the begining of the reversed ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator rbegin() const REF_NOEXCEPT;

        /*!
       \brief Returns an iterator to the begining of the reversed ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator crbegin() const REF_NOEXCEPT;

         /*!
       \brief Returns an iterator to the end of the reversed ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator rend() const REF_NOEXCEPT;

        /*!
       \brief Returns an iterator to the end of the reversed ChatT type array
       \return type_const_iterator of the first character.
       */
        REF_CONSTEXPR type_const_iterator crend() const REF_NOEXCEPT;
        /*!
       \brief Returns an the number of elements in CharT array
       \return type_size of the  elements in the CharT array.
       */
        REF_CONSTEXPR type_size size() const REF_NOEXCEPT;
        /*!
       \brief Returns an the number of elements in CharT array
       \return type_size of the elements in the CharT array.
       */
        REF_CONSTEXPR type_size lenght() const REF_NOEXCEPT;
        /*!
       \brief Returns the maximum number of elements in CharT array
       \return type_size maximum number of elements in the CharT array.
       */
        REF_CONSTEXPR type_size max_size() const REF_NOEXCEPT;
        /*!
         * \brief it checks if the number of characters in CharT array is zero
         *
         * \return `true` the number of elements in CharT array is zero and 'false' otherwise
         */
        REF_CONSTEXPR bool isEmpty() const REF_NOEXCEPT;
        /*!
         * \brief it returns a reference to the first element of the CharT array
         *
         * \return `const_reference` a reference to the first element of the CharT Array 'Equivalent to operator[](0)'
         */
        REF_CONSTEXPR type_const_reference front() REF_NOEXCEPT;
        /*!
         * \brief it returns a reference to the last element of the CharT array
         *
         * \return `const_reference` a reference to the last element of the CharT Array 'operator[](size() - 1)'
         */
        REF_CONSTEXPR type_const_reference back() REF_NOEXCEPT;
        /*!
        \brief it returns a pointer to the data which this object contains. the pointer valid range is [data(): data()+size].
            and passing the \ref data() to a function which takes const CharT* my doesn't work because the buffer may not contain
            \p a null terminated character array.
        \return '' returns a value to the characters in the memory in range [data(): data()+size].
        */
       REF_CONSTEXPR type_ptr data() const REF_NOEXCEPT;

        /*!
         * \brief move the start point of the CharT array by n characters
         *  \p the behavior is undefined if 'n>size()'
         */
        REF_CONSTEXPR void remove_prefix(type_size n) const REF_NOEXCEPT;

        /*!
         * \brief Moves the end of the view back by n characters.
         *        The behavior is undefined if `n > size()`.
         */
        REF_CONSTEXPR void remove_suffix(type_size n) const REF_NOEXCEPT;

        /*!
         * \brief it creates a basic_string with the content of CharT view.
         *        The behavior is undefined if `n > size()`.
         */
        template<typename Allocator = std::allocator<CharT>>
        std::basic_string<CharT,Traits> to_string(const Allocator a = Allocator()) const;


        /*!
         * \brief The function compares the two views by calling `Traits::compare(data(), v.data(), length)`,
         *        where \p length is the small of `size()` and `v.size()`.
         *
         * \return negative value if this view is less than the other character sequence,
         *         zero if the both character sequences are equal,
         *         positive value if this view is greater than the other character sequence.
         */
        REF_CONSTEXPR_OR_CONST int compare(CharLikeObjects_Descriptor v) const REF_NOEXCEPT;

        /*!
         * \brief Equivalent to `compare(basic_string_view(c))`.
         *
         * \return negative value if this view is less than the other character sequence,
         *         zero if the both character sequences are equal,
         *         positive value if this view is greater than the other character sequence.
         */
        REF_CONSTEXPR_OR_CONST int compare(CharT* c) const REF_NOEXCEPT;
        //
        // ───────────────────────────────────────────────── BASIC CHART ARRAY OPERATIONS END ─────
        //
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────       
        //
        // ─── MEMBER VARIABLES DECLARATION START ──────────────────────────────
        //
        private:

        const type_value*   m_data;
        type_size           m_size;
        //
        // ───────────────────────────────────────────────── MEMBER VARIABLES DECLARATION END ─────
        //
// ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── 
        //
        // ─── OVERLOAED OPERATORS START────────────────────────
        //
            /*!
         * \brief it returns a const reference to the character located in the specific location provided between [location].
         *
         * \return Const reference to the requested character.
         */
        REF_CONSTEXPR type_const_reference operator [](type_size index)const REF_NOEXCEPT;
        //
        // ─── OVERLOAED OPERATORS START────────────────────────
        //
        /*!
         * \brief Creates a `basic_string` with a copy of the content of the current view.
         *
         * \return A basic_string containing a copy of the characters of the current view.
         */
        template<typename Allocator>
        explicit operator std::basic_string<CharT, Traits, Allocator>() const;
        }; // End of the class

} // namespace REF

#endif