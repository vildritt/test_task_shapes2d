#ifndef SHAPES2D_SHAPE_META_INFO_H
#define SHAPES2D_SHAPE_META_INFO_H

#include <memory>
#include <string>

#include <shapes2d/misc.hpp>
#include <shapes2d/shape_ptr.hpp>


namespace shapes2d {
namespace shape {


class Factory;
using FactoryPtr = std::shared_ptr<Factory>;
using RegistryIdentifier = std::string;

/**
 * @brief registry shape meta information.
 * Used for registry machinery, create new instance, etc
 */
struct MetaInfo {
    RegistryIdentifier id;
    FactoryPtr factory;
};


/**
 * @brief abstract shape factory
 */
class Factory {
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
