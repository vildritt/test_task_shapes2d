#ifndef SHAPES2D_MISC_H
#define SHAPES2D_MISC_H
#pragma once

#include <typeinfo>
#include <typeindex>


#define S2D_DISABLE_COPY_AND_ASSIGN(ClassName) \
  ClassName(const ClassName&) = delete;   \
  ClassName& operator=(const ClassName&) = delete

#define S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(ClassName) \
  ClassName(ClassName&&) = delete;   \
  ClassName& operator=(ClassName&&) = delete


namespace shapes2d {

template<typename T>
std::type_index typeIndex()
{
    return std::type_index(typeid(T));
}

}

#endif // SHAPES2D_MISC_H


