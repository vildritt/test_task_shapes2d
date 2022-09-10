#ifndef SHAPES2D_SHAPES_REGISTRY_H
#define SHAPES2D_SHAPES_REGISTRY_H
#pragma once


#include <memory>
#include <vector>
#include <string>

#include <shapes2d/misc.hpp>
#include <shapes2d/shape.hpp>
#include <shapes2d/export.h>


namespace shapes2d {
namespace shape {


class RegistryPrivate;
/**
 * @brief Registry of all available shapes
 */
class SHAPES2D_MODEL_EXPORT Registry {
public:
    S2D_DISABLE_COPY_AND_ASSIGN(Registry);
    S2D_DISABLE_MOVE_AND_MOVE_ASSIGN(Registry);

    /**
     * @brief global registry
     */
    static Registry& instance();

    /**
     * @brief register new shape
     */
    void registerShape(const MetaInfo* descriptor);

    /**
     * @brief get all registered shapes, order - registered order
     */
    const std::vector<const MetaInfo*>& allRegisteredShapes() const;

private:
    Registry();
    ~Registry();

    std::unique_ptr<RegistryPrivate> d_ptr;
};


} // shape
} // ns shapes2d


#endif // SHAPES2D_SHAPES_REGISTRY_H
