/* Copyright 2020 Moeid Heidari

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */
// ────────────────────────────────────────────────────────────────────────────────
#ifndef REF_PREREQUISITES_H_
#define REF_PREREQUISITES_H_
 namespace REF
 {
     //
     // ─── POSSIBLE PLATFORMS ─────────────────────────────────────────────────────────
     //    
     #define REF_WINDOWS_PLATFORM   1
     #define REF_MAC_PLATFORM       2
     #define REF_LINUX_PLATFORM     3
     //
     // ─── POSSIBLE COMPILERS ─────────────────────────────────────────────────────────
     //
     #define REF_MSVC_COMPILER          1
     #define REF_CLANG_COMPILER         2
     #define REF_GNUC_COMPILER          3
     #define REF_APPLECLANG_COMPILER    4
     //
     // ─── ENDIAN POSSIBILITIES ───────────────────────────────────────────────────────
     //
     #define REF_LITTLE_ENDIAN  1
     #define REF_BIG_ENDIAN     2
     //
     // ─── ARCHITECTURE POSSIBILITIES ─────────────────────────────────────────────────
     //
     #define REF_32BIT_ARCHITECTURE     1
     #define REF_64BIT_ARCHITECTURE     2

//====================================================================================================================================
     //
     // ─── PLATFORM ───────────────────────────────────────────────────────────────────
     //
     #if    defined (__WIN32__) || defined (__WIN32)
     #      define REF_PLATFORM REF_WINDOWS_PLATFORM
     #elif  defined (__APPLE_CC__)
     #      define REF_PLATFORM REF_MAC_PLATFORM
     #else
     #      define REF_PLATFORM REF_LINUX_PLATFORM
     #endif
     //
     // ─── COMPILER ───────────────────────────────────────────────────────────────────
     //
     #if    defined(__clang__)
     
     #if    defined __aplle_build_version__
     #      define REF_COMPILER REF_APPLECLANG_COMPILER
     #else
     #      define REF_COMPILER REF_CLANG_COMPILER
     #endif
     #      define REF_COMPILER_VERSION (((__clang_major__)*100) + (__clang_minor__*10) + __clang_patchlevel__)
     #elif  defined(_MSC_VER)
     #      define RF_COMPILER REF_MSVC_COMPILER
     #      define REF_COMP_VER _MSC_VER
     #else
     #   error "No known compiler"
     #endif
     //
     // ─── ARCHITECTURE ───────────────────────────────────────────────────────────────
     //
     #if    defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) ||\
            defined(__ia64__) || defined(__s390__) || defined(__s390x__) || defined(_LP64) || defined(__LP64__)
     #      define REF_ARCH_TYPE REF_ARCH_64
     #else
     #      define REF_ARCH_TYPE REF_ARCH_32
     #endif
     #if    REF_COMPILER == REF_MSVC_COMPILER
     #      define REF_INLINE          inline
     #      define REF_FORCE_INLINE    __forceinline o
     #elif  REF_COMPILER == REF_GNUC_COMPILER
     #      define REF_INLINE          inline
     #      define REF_FORCE_INLINE   inline  __attribute__((always_inline))
     #elif  REF_COMPILER == REF_CLANG_COMPILER || REF_COMPILER == REF_APPLECLANG_COMPILER
     #      define REF_INLINE          inline
     #      define REF_FORCE_INLINE    inline  __attribute__((always_inline))
     #else
     #      define REF_INLINE         inline
     #      define REF_FORCE_INLINE   inline 
     #endif
     //
     // ─── MACROS TO ENABLE SOME USEFUL FEATURES IN C++11 WHICH THEY ARE NOT AVAILABLE IN ALL COMPILERS 
     //
      #endif
     #if    REF_COMPILER == REF_MSVC_COMPILER
     #      if !define(__cpp_constexpr) || (__cpp_1 < 201304)
     #      define REF_NO_CPP11_CONSTEXPR_AVAILABLE
     #      define REF_NO_CPP14_CONSTEXPR_AVAILABLE
     #      endif
     #      if !define(_MSVC_LANG) || (_MSVC_LANG < 201703L)
     #      define REF_NO_CPP17_CONSTEXPR_AVAILABLE
     #      endif
     #endif
     #if REF_COMPILER == REF_COMPILER_GNUC ||  REF_COMPILER == REF_COMPILER_CLANG || REF_COMPILER == REF_COMPILER_APPLECLANG
     #   if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
     #       define REF_NO_CPP14_CONSTEXPR_AVAILABLE
     #   endif
     #   if !defined(cpp_noexcept)
     #       define REF_NO_CPP11_CONSTEXPR_AVAILABLE
     #   endif
     #   if !defined(__cpp_noexcept_function_type) || (__cpp_noexcept_function_type < 201510)
     #       define REF_NO_CPP17_CONSTEXPR_AVAILABLE
     #   endif
     #endif
     #if defined(REF_NO_CXX11_CONSTEXPR)
     #   define REF_CONSTEXPR
     #   define REF_CONSTEXPR_OR_CONST const
     #else
     #   define REF_CONSTEXPR constexpr
     #   define REF_CONSTEXPR_OR_CONST constexpr
     #endif


     #if defined(REF_NO_CXX14_CONSTEXPR)
     #   define REF_CXX14_CONSTEXPR
     #else
     #   define REF_CXX14_CONSTEXPR constexpr
     #endif

     #ifdef REF_NO_CXX11_NOEXCEPT
     #   define REF_NOEXCEPT
     #   define REF_NOEXCEPT_OR_NOTHROW throw()
     #else
     #   define REF_NOEXCEPT noexcept
     #   define REF_NOEXCEPT_OR_NOTHROW noexcept
     #endif
     #define REF_STATIC_CONSTEXPR static REF_CONSTEXPR_OR_CONST
     #endif
}






