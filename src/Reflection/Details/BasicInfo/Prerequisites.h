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
     #      define RET_COMPILER_VERSION (((__clang_major__)*100) + (__clang_minor__*10) + __clang_patchlevel__)
     #elif  defined(_MSC_VER)
     #      define RF_COMPILER REF_MSVC_COMPILER
     #      define REF_COMP_VER _MSC_VER
     #else
     #   error "No known compiler"
     #endif
     //
     // ─── ARCHITECTURE ───────────────────────────────────────────────────────────────
     //
     #if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) ||\
         defined(__ia64__) || defined(__s390__) || defined(__s390x__) || defined(_LP64) || defined(__LP64__)
     #   define REF_ARCH_TYPE RTTR_ARCH_64
     


         



         




         


         

         



         




 }

#endif






