#ifndef SHAPES2D_SHAPE_META_INFO_H
#define SHAPES2D_SHAPE_META_INFO_H
#pragma once


#include <memory>
#include <string>

#include <shapes2d/misc.hpp>
#include <shapes2d/shape_ptr.hpp>
#include <shapes2d/export.h>


namespace shapes2d {
namespace shape {


class Factory;
using FactoryPtr = std::shared_ptr<Factory>;
using Identifier = std::string;

/**
 * @brief registry shape meta information.
 * Used for registry machinery, create new instance, etc
 */
struct SHAPES2D_MODEL_EXPORT MetaInfo {
    MetaInfo();
    Identifier id;
    std::type_index typeIndex;
    FactoryPtr factory;
};


/**
 * @brief abstract shape factory
 */
class SHAPES2D_MODEL_EXPORT Factory {
protected:
    virtual ShapePtr doCreate() = 0;
public:
    Factory() = default;
    S2D_DISABLE_COPY_AND_ASSIGN(Factory);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Factory);

    virtual ~Factory() {}

    ShapePtr create();
};


} // shape
} // ns shapes2d


#endif // SHAPES2D_SHAPE_META_INFO_H
