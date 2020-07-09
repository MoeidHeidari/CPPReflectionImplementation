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

namespace RET
{
    /*!
    \ref(ref) CharLikeObjects_descriptor class represents a bunch of information about some non-owing and constant char-like sequence objects in memory.
    */

   template<typename CharT,typename Traits = std::char_traits<CharT>>
   class CharLikeObjects_Descriptor
   {
       public:
       using type_of_trait          = Traits;
       using type_reference         = CharT&;
       using type_const_ptr         =const ChatT*;
       using type_ptr               =CharT*;
       

   };

}

#endif